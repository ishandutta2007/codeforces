#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

# include <iostream>
# include <immintrin.h>
# include <array>

using namespace std;
int x[101010];
int n, w, q;
array<int, 4> foo(array<int, 4> kk) {
    auto k = _mm_set_epi32(kk[3], kk[2], kk[1], kk[0]);
    auto from = _mm_set1_epi32(-2e9);
    auto to = _mm_set1_epi32(-2e9);
    auto ans = _mm_set1_epi32(1);
    for (int i = 0; i < n; ++i) {
        auto val = _mm_set1_epi32(x[i]);
        from = _mm_max_epi32(from, val);
        to = _mm_min_epi32(to, val);
        auto c = _mm_cmpgt_epi32(from, _mm_add_epi32(to, k));
        ans = _mm_add_epi32(ans, c);
        from = _mm_add_epi32(from, c & _mm_sub_epi32(val, from));
        to = _mm_add_epi32(to, c & _mm_sub_epi32(val, to));
    }
    array<int, 4> res;
    _mm_store_si128((__m128i*) &res[0], ans);
    for (int i = 0; i < 4; ++i) { res[i] = -res[i]; }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w >> q;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    while (q > 0) {
        array<int, 4> k;
        for (int i = 0; i < 4; ++i) cin >> k[i];
        for (int i = 0; i < 4; ++i) k[i] = w - k[i];
        auto ans = foo(k);
        for (int i = 0; i < min(q, 4); ++i) {
            cout << ans[i] << '\n';
        }
        q -= 4;
    }
    
    return 0;
}