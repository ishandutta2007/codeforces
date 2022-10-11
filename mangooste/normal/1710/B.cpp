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

void solve(int test_num) {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> p[i];
    }

    auto coords = x;
    sort(all(coords));
    coords.resize(unique(all(coords)) - coords.begin());
    const int k = len(coords);

    struct pref {
        int n;
        vector<ll> fl;
        vector<int> fi;

        pref(int n) : n(n), fl(n + 1), fi(n + 1) {}

        void add_on_segment(int from, int to, ll delta) {
            fl[from] += delta;
            fl[to] -= delta;
            fi[from]++;
            fi[to]--;
        }

        void init() {
            for (int i = 0; i < n; i++) {
                fl[i + 1] += fl[i];
                fi[i + 1] += fi[i];
            }
        }
    } f1(k), f2(k);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(all(coords), x[i]) - coords.begin();
        {
            int from = lower_bound(all(coords), x[i] - p[i]) - coords.begin();
            f1.add_on_segment(from, pos + 1, p[i] - x[i]);
        }
        {
            int to = upper_bound(all(coords), x[i] + p[i]) - coords.begin();
            f2.add_on_segment(pos + 1, to, p[i] + x[i]);
        }
    }
    f1.init();
    f2.init();

    vector<ll> tot(k);
    for (int i = 0; i < k; i++) {
        tot[i] = f1.fl[i] + 1ll * f1.fi[i] * coords[i];
        tot[i] += f2.fl[i] - 1ll * f2.fi[i] * coords[i];
    }
    
    vector<ll> pref_max(k + 1);
    pref_max[0] = -1e18;
    for (int i = 0; i < k; i++) {
        pref_max[i + 1] = pref_max[i];
        if (tot[i] > m) {
            pref_max[i + 1] = max(pref_max[i + 1], tot[i] - m - coords[i]);
        }
    }

    vector<ll> suf_max(k + 1);
    suf_max[k] = -1e18;
    for (int i = k - 1; i >= 0; i--) {
        suf_max[i] = suf_max[i + 1];
        if (tot[i] > m) {
            suf_max[i] = max(suf_max[i], tot[i] - m + coords[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(all(coords), x[i]) - coords.begin();
        bool ok = true;
        ok &= pref_max[pos + 1] + x[i] <= p[i];
        ok &= suf_max[pos] - x[i] <= p[i];
        cout << ok;
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}