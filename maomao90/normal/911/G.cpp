#include <bits/stdc++.h>
using namespace std;

#include <nmmintrin.h>
#include <immintrin.h>

#pragma GCC target("avx2")

int n, q;
char a[200005];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%hhi", &a[i]);
    }
    scanf("%d", &q);
    while (q--) {
        int l, r;
        char x, y; scanf("%d%d%hhi%hhi", &l, &r, &x, &y);
        int j = l;
        __m256i mx = _mm256_set1_epi8(x);
        __m256i my = _mm256_set1_epi8(y);
        for (int i = l; i + 31 <= r; i += 32) {
            j = i + 32;
            __m256i ma = _mm256_loadu_si256((__m256i*) &a[i]);
            __m256i msk = _mm256_cmpeq_epi8(ma, mx);
            ma = _mm256_blendv_epi8(ma, my, msk);
            _mm256_storeu_si256((__m256i*) &a[i], ma);
        }
        for (int i = j; i <= r; i++) {
            if (a[i] == x) {
                a[i] = y;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%hhi ", a[i]);
    }
    printf("\n");
    return 0;
}