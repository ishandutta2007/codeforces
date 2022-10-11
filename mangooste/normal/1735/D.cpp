#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
    #define dprint(...)
#endif // LOCAL

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    constexpr int N = 30;
    vector<ll> p3(N, 1);
    for (int i = 1; i < N; i++) p3[i] = p3[i - 1] * 3;
    auto get_bit = [&](ll mask, int bit) {
        return mask / p3[bit] % 3;
    };

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &mask : a) {
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            mask += p3[i] * x;
        }
    }

    set<ll> st;
    for (auto mask : a) st.insert(mask);

    ll ans = 0;
    for (int c = 0; c < n; c++) {
        int pairs = 0;
        for (int i = 0; i < n; i++) {
            if (i == c) continue;
            ll another = 0;
            for (int bit = 0; bit < k; bit++) {
                int my = get_bit(a[c], bit);
                int his = get_bit(a[i], bit);
                if (my == his) {
                    another += p3[bit] * my;
                } else {
                    another += p3[bit] * (1 ^ 2 ^ my ^ his);
                }
            }
            
            if (another == a[c] || another == a[i]) continue;
            if (!st.count(another)) continue;
            pairs++;
        }
        pairs /= 2;
        ans += 1ll * pairs * (pairs - 1) / 2;
    }
    cout << ans << '\n';
}