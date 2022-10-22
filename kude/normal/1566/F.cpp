#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        VL a(n);
        rep(i, n) cin >> a[i];
        sort(all(a));
        struct S {
            ll l, r;
        };
        vector<S>  segs(m);
        for(auto& [l, r]: segs) {
            cin >> l >> r;
        }
        sort(all(segs), [&](const S& s, const S& t) { return s.l < t.l || (s.l == t.l && s.r > t.r); });
        vector<vector<S>> ds(n + 1);
        vector<S> st;
        for(auto [l, r]: segs) {
            auto it = lower_bound(all(a), l);
            if (it != a.end() && *it <= r) continue;
            while(!st.empty() && st.back().r >= r) st.pop_back();
            st.push_back({l, r});
        }
        rep(i, n) st.push_back({a[i], a[i]});
        sort(all(st), [&](const S& s, const S& t) { return s.l < t.l || (s.l == t.l && s.r > t.r); });
        int pl = 0, pr = 0;
        while(st[pr].r != a[0]) pr++;
        ll dp1 = a[0] - st[pl].r, dp2 = 2 * (a[0] - st[pl].r);
        pl = pr;
        // for(auto [l, r]: st) cout << l << ' ' << r << endl;
        for(int i = 0; i < n - 1; i++) {
            while(st[pr].r != a[i + 1]) pr++;
            // if (a[i] != st[pl].l) cout << i << endl;
            // assert(st[pl].l == a[i]);
            ll ndp1 = 1.1e18, ndp2 = 1.1e18;
            for(int j = pl; j < pr; j++) {
                // cout << j << "aa" << endl;
                ll d = min(
                    dp1 + 2 * (st[j].l - a[i]),
                    dp2 + (st[j].l - a[i])
                );
                // cout << j << "aa" << endl;
                // if (st[j].l - a[i] < 0) {
                //     auto [l, r] = st[j];
                //     cout << i << ' ' << a[i] << ' ' << l << ' ' << r << endl;
                // }
                // assert(st[j].l - a[i] >= 0);
                // assert(a[i + 1] - st[j + 1].r >= 0);
                chmin(ndp1, d + (a[i + 1] - st[j + 1].r));
                chmin(ndp2, d + 2 * (a[i + 1] - st[j + 1].r));
            }
            // cout << i << endl;
            dp1 = ndp1; dp2 = ndp2;
            // cout << dp1 << ' ' << dp2 << endl;
            pl = pr;
        }
        // cout << "aa" << endl;
        ll x = st.back().l - a.back();
        ll ans = min(dp1 + 2 * x, dp2 + x);
        cout << ans << '\n';

    }
}