// Copyright (C) 2022-2023 Intel Corporation
// SPDX-License-Identifier: MIT

#ifndef UR_CONFORMANCE_INCLUDE_CHECKS_H_INCLUDED
#define UR_CONFORMANCE_INCLUDE_CHECKS_H_INCLUDED

#include <gtest/gtest.h>
#include <ur_api.h>
#include <uur/utils.h>

inline std::ostream &operator<<(std::ostream &out, const ur_result_t &result) {
    switch (result) {
#define CASE(VALUE)                                                            \
    case VALUE:                                                                \
        out << #VALUE;                                                         \
        break;

        CASE(UR_RESULT_SUCCESS)
        CASE(UR_RESULT_ERROR_INVALID_KERNEL_NAME)
        CASE(UR_RESULT_ERROR_INVALID_OPERATION)
        CASE(UR_RESULT_ERROR_INVALID_KERNEL)
        CASE(UR_RESULT_ERROR_INVALID_QUEUE_PROPERTIES)
        CASE(UR_RESULT_ERROR_INVALID_VALUE)
        CASE(UR_RESULT_ERROR_INVALID_CONTEXT)
        CASE(UR_RESULT_ERROR_INVALID_PLATFORM)
        CASE(UR_RESULT_ERROR_INVALID_DEVICE)
        CASE(UR_RESULT_ERROR_INVALID_BINARY)
        CASE(UR_RESULT_ERROR_INVALID_QUEUE)
        CASE(UR_RESULT_ERROR_OUT_OF_HOST_MEMORY)
        CASE(UR_RESULT_ERROR_INVALID_PROGRAM)
        CASE(UR_RESULT_ERROR_INVALID_PROGRAM_EXECUTABLE)
        CASE(UR_RESULT_ERROR_INVALID_SAMPLER)
        CASE(UR_RESULT_ERROR_INVALID_BUFFER_SIZE)
        CASE(UR_RESULT_ERROR_INVALID_MEM_OBJECT)
        CASE(UR_RESULT_ERROR_OUT_OF_RESOURCES)
        CASE(UR_RESULT_ERROR_INVALID_EVENT)
        CASE(UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST)
        CASE(UR_RESULT_ERROR_MISALIGNED_SUB_BUFFER_OFFSET)
        CASE(UR_RESULT_ERROR_INVALID_WORK_GROUP_SIZE)
        CASE(UR_RESULT_ERROR_COMPILER_NOT_AVAILABLE)
        CASE(UR_RESULT_ERROR_PROFILING_INFO_NOT_AVAILABLE)
        CASE(UR_RESULT_ERROR_DEVICE_NOT_FOUND)
        CASE(UR_RESULT_ERROR_INVALID_WORK_ITEM_SIZE)
        CASE(UR_RESULT_ERROR_INVALID_WORK_DIMENSION)
        CASE(UR_RESULT_ERROR_INVALID_KERNEL_ARGS)
        CASE(UR_RESULT_ERROR_INVALID_IMAGE_SIZE)
        CASE(UR_RESULT_ERROR_INVALID_IMAGE_FORMAT_DESCRIPTOR)
        CASE(UR_RESULT_ERROR_IMAGE_FORMAT_NOT_SUPPORTED)
        CASE(UR_RESULT_ERROR_MEM_OBJECT_ALLOCATION_FAILURE)
        CASE(UR_RESULT_ERROR_UNINITIALIZED)
        CASE(UR_RESULT_ERROR_DEVICE_LOST)
        CASE(UR_RESULT_ERROR_OUT_OF_DEVICE_MEMORY)
        CASE(UR_RESULT_ERROR_PROGRAM_BUILD_FAILURE)
        CASE(UR_RESULT_ERROR_PROGRAM_LINK_FAILURE)
        CASE(UR_RESULT_ERROR_DEVICE_REQUIRES_RESET)
        CASE(UR_RESULT_ERROR_DEVICE_IN_LOW_POWER_STATE)
        CASE(UR_RESULT_ERROR_UNSUPPORTED_VERSION)
        CASE(UR_RESULT_ERROR_UNSUPPORTED_FEATURE)
        CASE(UR_RESULT_ERROR_INVALID_ARGUMENT)
        CASE(UR_RESULT_ERROR_INVALID_NULL_HANDLE)
        CASE(UR_RESULT_ERROR_HANDLE_OBJECT_IN_USE)
        CASE(UR_RESULT_ERROR_INVALID_NULL_POINTER)
        CASE(UR_RESULT_ERROR_INVALID_SIZE)
        CASE(UR_RESULT_ERROR_UNSUPPORTED_SIZE)
        CASE(UR_RESULT_ERROR_UNSUPPORTED_ALIGNMENT)
        CASE(UR_RESULT_ERROR_INVALID_SYNCHRONIZATION_OBJECT)
        CASE(UR_RESULT_ERROR_INVALID_ENUMERATION)
        CASE(UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION)
        CASE(UR_RESULT_ERROR_UNSUPPORTED_IMAGE_FORMAT)
        CASE(UR_RESULT_ERROR_INVALID_NATIVE_BINARY)
        CASE(UR_RESULT_ERROR_INVALID_GLOBAL_NAME)
        CASE(UR_RESULT_ERROR_INVALID_FUNCTION_NAME)
        CASE(UR_RESULT_ERROR_INVALID_GROUP_SIZE_DIMENSION)
        CASE(UR_RESULT_ERROR_INVALID_GLOBAL_WIDTH_DIMENSION)
        CASE(UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_INDEX)
        CASE(UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_SIZE)
        CASE(UR_RESULT_ERROR_INVALID_KERNEL_ATTRIBUTE_VALUE)
        CASE(UR_RESULT_ERROR_PROGRAM_UNLINKED)
        CASE(UR_RESULT_ERROR_OVERLAPPING_REGIONS)
        CASE(UR_RESULT_ERROR_INVALID_HOST_PTR)
        CASE(UR_RESULT_ERROR_INVALID_USM_SIZE)
        CASE(UR_RESULT_ERROR_OBJECT_ALLOCATION_FAILURE)
        CASE(UR_RESULT_ERROR_UNKNOWN)
        CASE(UR_RESULT_FORCE_UINT32)

#undef CASE
    default:
        out << "unknown ur_result_t: " << result;
        break;
    }
    return out;
}

namespace uur {

struct Result {
    Result(ur_result_t result) noexcept : value(result) {}

    constexpr bool operator==(const Result &rhs) const noexcept {
        return value == rhs.value;
    }

    ur_result_t value;
};

inline std::ostream &operator<<(std::ostream &out, const Result &result) {
    out << result.value;
    return out;
}

} // namespace uur

#ifndef ASSERT_EQ_RESULT
#define ASSERT_EQ_RESULT(EXPECTED, ACTUAL)                                     \
    ASSERT_EQ(uur::Result(EXPECTED), uur::Result(ACTUAL))
#endif
#ifndef ASSERT_SUCCESS
#define ASSERT_SUCCESS(ACTUAL) ASSERT_EQ_RESULT(UR_RESULT_SUCCESS, ACTUAL)
#endif

#ifndef EXPECT_EQ_RESULT
#define EXPECT_EQ_RESULT(EXPECTED, ACTUAL)                                     \
    EXPECT_EQ(uur::Result(EXPECTED), uur::Result(ACTUAL))
#endif
#ifndef EXPECT_SUCCESS
#define EXPECT_SUCCESS(ACTUAL) EXPECT_EQ_RESULT(UR_RESULT_SUCCESS, ACTUAL)
#endif

inline std::ostream &operator<<(std::ostream &out,
                                const ur_device_info_t &info_type) {
    switch (info_type) {

#define CASE(VALUE)                                                            \
    case VALUE:                                                                \
        out << #VALUE;                                                         \
        break;

        CASE(UR_DEVICE_INFO_TYPE)
        CASE(UR_DEVICE_INFO_VENDOR_ID)
        CASE(UR_DEVICE_INFO_DEVICE_ID)
        CASE(UR_DEVICE_INFO_MAX_COMPUTE_UNITS)
        CASE(UR_DEVICE_INFO_MAX_WORK_ITEM_DIMENSIONS)
        CASE(UR_DEVICE_INFO_MAX_WORK_ITEM_SIZES)
        CASE(UR_DEVICE_INFO_MAX_WORK_GROUP_SIZE)
        CASE(UR_DEVICE_INFO_SINGLE_FP_CONFIG)
        CASE(UR_DEVICE_INFO_HALF_FP_CONFIG)
        CASE(UR_DEVICE_INFO_DOUBLE_FP_CONFIG)
        CASE(UR_DEVICE_INFO_QUEUE_PROPERTIES)
        CASE(UR_DEVICE_INFO_PREFERRED_VECTOR_WIDTH_CHAR)
        CASE(UR_DEVICE_INFO_PREFERRED_VECTOR_WIDTH_SHORT)
        CASE(UR_DEVICE_INFO_PREFERRED_VECTOR_WIDTH_LONG)
        CASE(UR_DEVICE_INFO_PREFERRED_VECTOR_WIDTH_FLOAT)
        CASE(UR_DEVICE_INFO_NATIVE_VECTOR_WIDTH_CHAR)
        CASE(UR_DEVICE_INFO_NATIVE_VECTOR_WIDTH_SHORT)
        CASE(UR_DEVICE_INFO_NATIVE_VECTOR_WIDTH_INT)
        CASE(UR_DEVICE_INFO_NATIVE_VECTOR_WIDTH_LONG)
        CASE(UR_DEVICE_INFO_NATIVE_VECTOR_WIDTH_FLOAT)
        CASE(UR_DEVICE_INFO_NATIVE_VECTOR_WIDTH_DOUBLE)
        CASE(UR_DEVICE_INFO_NATIVE_VECTOR_WIDTH_HALF)
        CASE(UR_DEVICE_INFO_MAX_CLOCK_FREQUENCY)
        CASE(UR_DEVICE_INFO_MEMORY_CLOCK_RATE)
        CASE(UR_DEVICE_INFO_ADDRESS_BITS)
        CASE(UR_DEVICE_INFO_MAX_MEM_ALLOC_SIZE)
        CASE(UR_DEVICE_INFO_IMAGE_SUPPORTED)
        CASE(UR_DEVICE_INFO_MAX_READ_IMAGE_ARGS)
        CASE(UR_DEVICE_INFO_MAX_WRITE_IMAGE_ARGS)
        CASE(UR_DEVICE_INFO_MAX_READ_WRITE_IMAGE_ARGS)
        CASE(UR_DEVICE_INFO_IMAGE2D_MAX_WIDTH)
        CASE(UR_DEVICE_INFO_IMAGE2D_MAX_HEIGHT)
        CASE(UR_DEVICE_INFO_IMAGE3D_MAX_WIDTH)
        CASE(UR_DEVICE_INFO_IMAGE3D_MAX_HEIGHT)
        CASE(UR_DEVICE_INFO_IMAGE3D_MAX_DEPTH)
        CASE(UR_DEVICE_INFO_IMAGE_MAX_BUFFER_SIZE)
        CASE(UR_DEVICE_INFO_IMAGE_MAX_ARRAY_SIZE)
        CASE(UR_DEVICE_INFO_MAX_SAMPLERS)
        CASE(UR_DEVICE_INFO_MAX_PARAMETER_SIZE)
        CASE(UR_DEVICE_INFO_MEM_BASE_ADDR_ALIGN)
        CASE(UR_DEVICE_INFO_GLOBAL_MEM_CACHE_TYPE)
        CASE(UR_DEVICE_INFO_GLOBAL_MEM_CACHELINE_SIZE)
        CASE(UR_DEVICE_INFO_GLOBAL_MEM_CACHE_SIZE)
        CASE(UR_DEVICE_INFO_GLOBAL_MEM_SIZE)
        CASE(UR_DEVICE_INFO_GLOBAL_MEM_FREE)
        CASE(UR_DEVICE_INFO_MAX_CONSTANT_BUFFER_SIZE)
        CASE(UR_DEVICE_INFO_MAX_CONSTANT_ARGS)
        CASE(UR_DEVICE_INFO_LOCAL_MEM_TYPE)
        CASE(UR_DEVICE_INFO_LOCAL_MEM_SIZE)
        CASE(UR_DEVICE_INFO_ERROR_CORRECTION_SUPPORT)
        CASE(UR_DEVICE_INFO_HOST_UNIFIED_MEMORY)
        CASE(UR_DEVICE_INFO_PROFILING_TIMER_RESOLUTION)
        CASE(UR_DEVICE_INFO_ENDIAN_LITTLE)
        CASE(UR_DEVICE_INFO_AVAILABLE)
        CASE(UR_DEVICE_INFO_COMPILER_AVAILABLE)
        CASE(UR_DEVICE_INFO_LINKER_AVAILABLE)
        CASE(UR_DEVICE_INFO_EXECUTION_CAPABILITIES)
        CASE(UR_DEVICE_INFO_QUEUE_ON_DEVICE_PROPERTIES)
        CASE(UR_DEVICE_INFO_QUEUE_ON_HOST_PROPERTIES)
        CASE(UR_DEVICE_INFO_BUILT_IN_KERNELS)
        CASE(UR_DEVICE_INFO_PLATFORM)
        CASE(UR_DEVICE_INFO_REFERENCE_COUNT)
        CASE(UR_DEVICE_INFO_IL_VERSION)
        CASE(UR_DEVICE_INFO_NAME)
        CASE(UR_DEVICE_INFO_VENDOR)
        CASE(UR_DEVICE_INFO_DRIVER_VERSION)
        CASE(UR_DEVICE_INFO_PROFILE)
        CASE(UR_DEVICE_INFO_VERSION)
        CASE(UR_DEVICE_INFO_BACKEND_RUNTIME_VERSION)
        CASE(UR_DEVICE_INFO_EXTENSIONS)
        CASE(UR_DEVICE_INFO_PRINTF_BUFFER_SIZE)
        CASE(UR_DEVICE_INFO_PREFERRED_INTEROP_USER_SYNC)
        CASE(UR_DEVICE_INFO_PARENT_DEVICE)
        CASE(UR_DEVICE_INFO_PARTITION_PROPERTIES)
        CASE(UR_DEVICE_INFO_PARTITION_MAX_SUB_DEVICES)
        CASE(UR_DEVICE_INFO_PARTITION_AFFINITY_DOMAIN)
        CASE(UR_DEVICE_INFO_PARTITION_TYPE)
        CASE(UR_DEVICE_INFO_MAX_NUM_SUB_GROUPS)
        CASE(UR_DEVICE_INFO_SUB_GROUP_INDEPENDENT_FORWARD_PROGRESS)
        CASE(UR_DEVICE_INFO_SUB_GROUP_SIZES_INTEL)
        CASE(UR_DEVICE_INFO_USM_HOST_SUPPORT)
        CASE(UR_DEVICE_INFO_USM_DEVICE_SUPPORT)
        CASE(UR_DEVICE_INFO_USM_SINGLE_SHARED_SUPPORT)
        CASE(UR_DEVICE_INFO_USM_CROSS_SHARED_SUPPORT)
        CASE(UR_DEVICE_INFO_USM_SYSTEM_SHARED_SUPPORT)
        CASE(UR_DEVICE_INFO_UUID)
        CASE(UR_DEVICE_INFO_PCI_ADDRESS)
        CASE(UR_DEVICE_INFO_GPU_EU_COUNT)
        CASE(UR_DEVICE_INFO_GPU_EU_SIMD_WIDTH)
        CASE(UR_DEVICE_INFO_GPU_EU_SLICES)
        CASE(UR_DEVICE_INFO_GPU_SUBSLICES_PER_SLICE)
        CASE(UR_DEVICE_INFO_MAX_MEMORY_BANDWIDTH)
        CASE(UR_DEVICE_INFO_IMAGE_SRGB)
        CASE(UR_DEVICE_INFO_ATOMIC_64)
        CASE(UR_DEVICE_INFO_ATOMIC_MEMORY_ORDER_CAPABILITIES)
        CASE(UR_DEVICE_INFO_BFLOAT16)
        CASE(UR_DEVICE_INFO_MAX_COMPUTE_QUEUE_INDICES)
        CASE(UR_DEVICE_INFO_FORCE_UINT32)
#undef CASE
    default:
        out << "unknown ur_device_info_t: " << info_type;
        break;
    }
    return out;
}

inline std::ostream &operator<<(std::ostream &out,
                                const ur_platform_info_t &info) {

    switch (info) {
#define CASE(VALUE)                                                            \
    case VALUE:                                                                \
        out << #VALUE;                                                         \
        break;
        CASE(UR_PLATFORM_INFO_NAME)
        CASE(UR_PLATFORM_INFO_VENDOR_NAME)
        CASE(UR_PLATFORM_INFO_VERSION)
        CASE(UR_PLATFORM_INFO_EXTENSIONS)
        CASE(UR_PLATFORM_INFO_PROFILE)
        CASE(UR_PLATFORM_INFO_FORCE_UINT32)
#undef CASE
    default:
        out << "unknown ur_platform_info_t: " << info;
        break;
    };
    return out;
}

inline std::ostream &operator<<(std::ostream &out,
                                const ur_context_info_t &info) {

    switch (info) {
#define CASE(VALUE)                                                            \
    case VALUE:                                                                \
        out << #VALUE;                                                         \
        break;

        CASE(UR_CONTEXT_INFO_NUM_DEVICES);
        CASE(UR_CONTEXT_INFO_DEVICES);
        CASE(UR_CONTEXT_INFO_USM_MEMCPY2D_SUPPORT);
        CASE(UR_CONTEXT_INFO_USM_FILL2D_SUPPORT);
        CASE(UR_CONTEXT_INFO_FORCE_UINT32);

#undef CASE
    default:
        out << "unkown ur_context_info_t: " << info;
        break;
    }
    return out;
}

inline std::ostream &operator<<(std::ostream &out,
                                const ur_queue_info_t &info) {
    switch (info) {
#define CASE(VALUE)                                                            \
    case VALUE:                                                                \
        out << #VALUE;                                                         \
        break;

        CASE(UR_QUEUE_INFO_CONTEXT)
        CASE(UR_QUEUE_INFO_DEVICE)
        CASE(UR_QUEUE_INFO_DEVICE_DEFAULT)
        CASE(UR_QUEUE_INFO_FLAGS)
        CASE(UR_QUEUE_INFO_REFERENCE_COUNT)
        CASE(UR_QUEUE_INFO_SIZE)

#undef CASE
    default:
        out << "unkown ur_queue_info_t: " << info;
        break;
    }
    return out;
}

inline std::ostream &operator<<(std::ostream &out, const ur_mem_info_t &info) {
    switch (info) {

#define CASE(name)                                                             \
    case name:                                                                 \
        out << #name;                                                          \
        break;

        CASE(UR_MEM_INFO_SIZE)
        CASE(UR_MEM_INFO_CONTEXT)

#undef CASE
    default:
        out << "UNKOWN_UR_MEM_INFO_TYPE";
        break;
    }
    return out;
}

inline std::ostream &operator<<(std::ostream &out, const ur_mem_flag_t &flag) {
    switch (flag) {
#define CASE(name)                                                             \
    case name:                                                                 \
        out << #name;                                                          \
        break;

        CASE(UR_MEM_FLAG_READ_WRITE);
        CASE(UR_MEM_FLAG_WRITE_ONLY);
        CASE(UR_MEM_FLAG_READ_ONLY);
        CASE(UR_MEM_FLAG_USE_HOST_POINTER);
        CASE(UR_MEM_FLAG_ALLOC_HOST_POINTER);
        CASE(UR_MEM_FLAG_ALLOC_COPY_HOST_POINTER);

#undef CASE

    default:
        out << "UNKOWN_UR_MEM_FLAG_TYPE";
        break;
    }
    return out;
}

inline std::ostream &operator<<(std::ostream &out,
                                const ur_usm_alloc_info_t &info) {
    switch (info) {
#define CASE(name)                                                             \
    case name:                                                                 \
        out << #name;                                                          \
        break;

        CASE(UR_USM_ALLOC_INFO_TYPE);
        CASE(UR_USM_ALLOC_INFO_BASE_PTR);
        CASE(UR_USM_ALLOC_INFO_SIZE);
        CASE(UR_USM_ALLOC_INFO_DEVICE);
        CASE(UR_USM_ALLOC_INFO_POOL);

#undef CASE

    default:
        out << "UNKNOWN_UR_MEM_ALLOC_INFO_TYPE";
        break;
    }
    return out;
}

inline std::ostream &operator<<(std::ostream &out,
                                const ur_event_info_t &info) {
    switch (info) {
#define CASE(name)                                                             \
    case name:                                                                 \
        out << #name;                                                          \
        break;

        CASE(UR_EVENT_INFO_COMMAND_QUEUE);
        CASE(UR_EVENT_INFO_CONTEXT);
        CASE(UR_EVENT_INFO_COMMAND_TYPE);
        CASE(UR_EVENT_INFO_COMMAND_EXECUTION_STATUS);
        CASE(UR_EVENT_INFO_REFERENCE_COUNT);

#undef CASE

    default:
        out << "UNKNOWN_UR_EVENT_INFO_TYPE";
        break;
    }
    return out;
}

inline std::ostream &operator<<(std::ostream &out,
                                const ur_profiling_info_t &info) {
    switch (info) {
#define CASE(name)                                                             \
    case name:                                                                 \
        out << #name;                                                          \
        break;

        CASE(UR_PROFILING_INFO_COMMAND_QUEUED);
        CASE(UR_PROFILING_INFO_COMMAND_SUBMIT);
        CASE(UR_PROFILING_INFO_COMMAND_START);
        CASE(UR_PROFILING_INFO_COMMAND_END);

#undef CASE

    default:
        out << "UNKNOWN_UR_PROFILING_INFO_TYPE";
        break;
    }
    return out;
}

inline std::ostream &operator<<(std::ostream &out,
                                const ur_device_handle_t &device) {
    out << uur::GetDeviceName(device);
    return out;
}

#endif // UR_CONFORMANCE_INCLUDE_CHECKS_H_INCLUDED
