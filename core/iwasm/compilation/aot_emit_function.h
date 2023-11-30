/*
 * Copyright (C) 2019 Intel Corporation. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#ifndef _AOT_EMIT_FUNCTION_H_
#define _AOT_EMIT_FUNCTION_H_

#include "aot_compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

bool
aot_compile_op_call(AOTCompContext *comp_ctx, AOTFuncContext *func_ctx,
                    uint32 func_idx, bool tail_call, const uint8 *frame_ip);

bool
aot_compile_op_call_indirect(AOTCompContext *comp_ctx, AOTFuncContext *func_ctx,
                             uint32 type_idx, uint32 tbl_idx,
                             const uint8 *frame_ip);

bool
aot_compile_op_ref_null(AOTCompContext *comp_ctx, AOTFuncContext *func_ctx);

bool
aot_compile_op_ref_is_null(AOTCompContext *comp_ctx, AOTFuncContext *func_ctx);

bool
aot_compile_op_ref_func(AOTCompContext *comp_ctx, AOTFuncContext *func_ctx,
                        uint32 func_idx);

#if (WASM_ENABLE_DUMP_CALL_STACK != 0) || (WASM_ENABLE_PERF_PROFILING != 0)
bool
call_aot_alloc_frame_func(AOTCompContext *comp_ctx, AOTFuncContext *func_ctx,
                          LLVMValueRef func_idx);
bool
call_aot_free_frame_func(AOTCompContext *comp_ctx, AOTFuncContext *func_ctx);
#endif /* end of (WASM_ENABLE_DUMP_CALL_STACK != 0) \
                 || (WASM_ENABLE_PERF_PROFILING != 0) */

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif /* end of _AOT_EMIT_FUNCTION_H_ */
