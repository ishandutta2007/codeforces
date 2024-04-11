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
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << pref[n - (x - y)] - pref[n - x] << '\n';
    }
}