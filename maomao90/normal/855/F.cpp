#include <bits/stdc++.h>
using namespace std;

#include <nmmintrin.h>

#pragma GCC target("avx2")

const int N = 100000, INF = 1000000010;

int q;
int pos[N], neg[N];

int main() {
	scanf("%d", &q);
	for (int i = 0; i < N; i++) {
		pos[i] = INF;
		neg[i] = INF;
	}
	const __m128i MZERO = _mm_setzero_si128();
	const __m128i MINF = _mm_set1_epi32(INF);
	while (q--) {
		int t, l, r; scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			int k; scanf("%d", &k);
			if (k > 0) {
				__m128i ck = _mm_set1_epi32(k);
				int j = l;
				for (int i = l; i + 3 < r; i += 4) {
					j = i + 4;
					__m128i a = _mm_loadu_si128((__m128i*) &pos[i]);
					a = _mm_min_epi32(a, ck);
					_mm_storeu_si128((__m128i*) &pos[i], a);
				}
				for (int i = j; i < r; i++) {
					pos[i] = min(pos[i], k);
				}
			} else {
				k = -k;
				__m128i ck = _mm_set1_epi32(k);
				int j = l;
				for (int i = l; i + 3 < r; i += 4) {
					j = i + 4;
					__m128i a = _mm_loadu_si128((__m128i*) &neg[i]);
					a = _mm_min_epi32(a, ck);
					_mm_storeu_si128((__m128i*) &neg[i], a);
				}
				for (int i = j; i < r; i++) {
					neg[i] = min(neg[i], k);
				}
			}
		} else {
			long long ans = 0;
			__m128i msum = _mm_setzero_si128();
			int j = l;
			for (int i = l; i + 3 < r; i += 4) {
				j = i + 4;
				__m128i mpos = _mm_loadu_si128((__m128i*) &pos[i]),
						mneg = _mm_loadu_si128((__m128i*) &neg[i]);
				__m128i msk = _mm_cmplt_epi32(mpos, MINF);
				// elements < INF are valid
				msk = _mm_and_si128(msk, _mm_cmplt_epi32(mneg, MINF));
				__m128i mcomb = _mm_add_epi32(mpos, mneg);
				mcomb = _mm_blendv_epi8(MZERO, mcomb, msk);
				__m128i mfirst = _mm_cvtepi32_epi64(mcomb),
						msecond = _mm_cvtepi32_epi64(_mm_srli_si128(mcomb, 8));
				msum = _mm_add_epi64(msum, mfirst);
				msum = _mm_add_epi64(msum, msecond);
			}
			long long sumarr[2];
			_mm_storeu_si128((__m128i*) sumarr, msum);
			ans = sumarr[0] + sumarr[1];
			for (int i = j; i < r; i++) {
				if (pos[i] == INF || neg[i] == INF) continue;
				ans += pos[i] + neg[i];
			}
			printf("%lld\n", ans);
		}
	}
}