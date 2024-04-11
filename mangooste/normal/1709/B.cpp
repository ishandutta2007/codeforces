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
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<ll> pref(n);
    for (int i = 0; i < n - 1; i++) {
        pref[i + 1] = pref[i] + max(0, a[i] - a[i + 1]);
    }
    vector<ll> suf(n);
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + max(0, a[i + 1] - a[i]);
    }

    while (q--) {
        int from, to;
        cin >> from >> to;
        from--, to--;
        if (from <= to) {
            cout << pref[to] - pref[from] << '\n';
        } else {
            cout << suf[to] - suf[from] << '\n';
        }
    }
}