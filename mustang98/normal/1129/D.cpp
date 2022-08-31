#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse4,sse3,avx,avx2")
#include <iostream>
#include <immintrin.h>
using namespace std;

using ll = long long;
int a[101001];
int b[101010];
int dp[101010];
int p1[101010];
int p2[101010];
int ans = 0;
int n, k;
#define mod 998244353
void add(int* __restrict a, int* __restrict dp, int n) {
    int sum = 0;
    while (n % 8) {
        a[0]++;
        sum -= a[0] == 0 ? dp[0] : 0;
        sum += sum < 0 ? mod : 0;
        ++a;
        ++dp;
        --n;
    }
    n /= 8;
    __m256i x7 = _mm256_set1_epi32(0);
    __m256i x0 = _mm256_set1_epi32(0);
    __m256i x3 = _mm256_set1_epi32(1);
    __m256i x4 = _mm256_set1_epi32(mod);
    while (n--) {
        __m256i x1 = _mm256_loadu_si256((__m256i*)a);
        x1 = _mm256_add_epi32(x1, x3);
        _mm256_storeu_si256((__m256i*)a, x1);
        __m256i x2 = _mm256_loadu_si256((__m256i*)dp);
        x7 = _mm256_sub_epi32(x7, _mm256_and_si256(x2, _mm256_cmpeq_epi32(x1, x0)));
        x7 = _mm256_add_epi32(x7, _mm256_and_si256(x4, _mm256_cmpgt_epi32(x0, x7)));
        a += 8;
        dp += 8;
    }
    int res[8];
    _mm256_storeu_si256((__m256i*)res, x7);
    for (int i = 0; i < 8; ++i) {
        sum += res[i]; if (sum >= mod) sum -= mod;
    }
    ans += sum; if (ans >= mod) ans -= mod;
}
void sub(int* __restrict a, int* __restrict dp, int n) {
    int sum = 0;
    while (n % 8) {
        sum -= a[0] == 0 ? dp[0] : 0;
        sum += sum < 0 ? mod : 0;
        a[0]--;
        ++a;
        ++dp;
        --n;
    }
    n /= 8;
    __m256i x7 = _mm256_set1_epi32(0);
    __m256i x0 = _mm256_set1_epi32(0);
    __m256i x3 = _mm256_set1_epi32(1);
    __m256i x4 = _mm256_set1_epi32(mod);
    while (n--) {
        __m256i x1 = _mm256_loadu_si256((__m256i*)a);
        __m256i x2 = _mm256_loadu_si256((__m256i*)dp);
        x7 = _mm256_sub_epi32(x7, _mm256_and_si256(x2, _mm256_cmpeq_epi32(x1, x0)));
        x7 = _mm256_add_epi32(x7, _mm256_and_si256(x4, _mm256_cmpgt_epi32(x0, x7)));
        x1 = _mm256_sub_epi32(x1, x3);
        _mm256_storeu_si256((__m256i*)a, x1);
        a += 8;
        dp += 8;
    }
    int res[8];
    _mm256_storeu_si256((__m256i*)res, x7);
    for (int i = 0; i < 8; ++i) {
        sum += res[i]; if (sum >= mod) sum -= mod;
    }
    ans -= sum; ans += ans < 0 ? mod : 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        b[i] = -k - 1;
        cin >> a[i];
        --a[i];
        p1[i] = p2[i] = -1;
    }
    dp[0] = 1;
    ans = 1;
    for (int i = 0; i < n; ++i) {
        if (i) ans = (ans + ans) % mod;
        int x = a[i];
        sub(b + p2[x] + 1, dp + p2[x] + 1, p1[x] - p2[x]);
        add(b + p1[x] + 1, dp + p1[x] + 1, i - p1[x]);
        dp[i + 1] = ans;
        p2[x] = p1[x];
        p1[x] = i;
    }
    cout << ans << endl;
    return 0;
}