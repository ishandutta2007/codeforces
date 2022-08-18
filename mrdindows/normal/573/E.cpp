#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <immintrin.h>
 
using namespace std;
 
#ifdef _MSC_VER
	#define ALIGN(x) __declspec(align(x))
#else
	#define ALIGN(x) __attribute__((aligned(x)))
#endif
 
static const int64_t INF = (1ll << 62);
static ALIGN(16) int32_t a[100000];
static ALIGN(16) int64_t dp[2][100008];
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	for(int i = 0; i <= n; ++i){
		dp[0][i] = dp[1][i] = -INF;
	}
	dp[0][0] = 0;
	for(int i = 0; i < n; ++i){
		const int cur = i & 1, next = 1 - cur;
		const int64_t *cur_row = &(dp[cur][0]);
		const int64_t ai = a[i];
		ALIGN(16) int64_t a_ai2[2] = { a[i] * 2, a[i] * 2 };
		const __m128i v_ai2 = _mm_load_si128((const __m128i *)a_ai2);
		int64_t *next_row = &(dp[next][0]);
		next_row[0] = cur_row[0];
		next_row[1] = max(cur_row[0] + ai * 1, cur_row[1]);
		next_row[2] = max(cur_row[1] + ai * 2, cur_row[2]);
		next_row[3] = max(cur_row[2] + ai * 3, cur_row[3]);
		const int last = i + 2;
		ALIGN(16) int64_t a_aij_init[2] = { ai * 4, ai * 5 };
		__m128i v_aij = _mm_load_si128((const __m128i *)a_aij_init);
		__m128i v_prev = _mm_load_si128((const __m128i *)(cur_row + 2));
		for(int j = 4; j < last; j += 4){
			const __m128i v_c01 = _mm_load_si128((const __m128i *)(cur_row + j));
			const __m128i v_c23 = _mm_load_si128((const __m128i *)(cur_row + j + 2));
			const __m128i v_m01 = v_aij;
			const __m128i v_m23 = _mm_add_epi64(v_aij, v_ai2);
			const __m128i v_p01 = _mm_alignr_epi8(v_c01, v_prev, 8);
			const __m128i v_p23 = _mm_alignr_epi8(v_c23, v_c01, 8);
			const __m128i v_d01 = _mm_add_epi64(v_m01, v_p01);
			const __m128i v_d23 = _mm_add_epi64(v_m23, v_p23);
			const __m128i v_k01 = _mm_cmpgt_epi64(v_c01, v_d01);
			const __m128i v_k23 = _mm_cmpgt_epi64(v_c23, v_d23);
			const __m128i v_r01 = _mm_blendv_epi8(v_d01, v_c01, v_k01);
			const __m128i v_r23 = _mm_blendv_epi8(v_d23, v_c23, v_k23);
			_mm_store_si128((__m128i *)(next_row + j),     v_r01);
			_mm_store_si128((__m128i *)(next_row + j + 2), v_r23);
			v_aij = _mm_add_epi64(v_m23, v_ai2);
			v_prev = v_c23;
		}
	}
	int64_t answer = 0;
	for(int i = 0; i <= n; ++i){
		answer = max(answer, dp[n & 1][i]);
	}
	cout << answer << endl;
	return 0;
}