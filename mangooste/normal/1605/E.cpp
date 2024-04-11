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

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i) a[i] -= x;
    }

    array<vector<ll>, 3> group;
    vector<ll> b(n);
    vector<int> cnt(n);
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        b[i] += a[i];
        for (int j = i + i + 1; j < n; j += i + 1) {
            b[j] -= b[i];
            cnt[j] -= cnt[i];
        }
        assert(-1 <= cnt[i] && cnt[i] <= 1);
        group[cnt[i] + 1].push_back(b[i]);
    }

    struct solver {
        vector<ll> values, pref;

        solver(const vector<ll> &a = {}) : values(a), pref(len(a) + 1) {
            sort(all(values));
            for (int i = 0; i < len(a); i++) {
                pref[i + 1] = pref[i] + values[i];
            }
        }

        ll query(int to_add) {
            int pos = lower_bound(all(values), -to_add) - values.begin();
            ll ret = -pref[pos] - 1ll * pos * to_add;
            ret += pref.back() - pref[pos] + 1ll * (len(values) - pos) * to_add;
            return ret;
        }
    };

    array<solver, 3> sol;
    for (int i : {0, 1, 2}) sol[i] = solver(group[i]);

    int q;
    cin >> q;
    while (q--) {
        int value;
        cin >> value;

        ll ans = 0;
        for (int i : {0, 1, 2}) {
            ans += sol[i].query(-(i - 1) * value);
        }
        cout << ans << '\n';
    }
}