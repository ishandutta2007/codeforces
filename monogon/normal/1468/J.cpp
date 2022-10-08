
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<tuple<ll, int, int>> edges;
    rep(i, 0, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(all(edges));
    vector<ll> costs;
    vector<int> dsu(n + 1, -1);
    function<int(int)> trace = [&](int x) {
        return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
    };
    auto join = [&](int x, int y) {
        if((x = trace(x)) == (y = trace(y))) return;
        if(dsu[x] > dsu[y]) swap(x, y);
        dsu[x] += dsu[y];
        dsu[y] = x;
    };
    rep(i, 0, m) {
        ll w;
        int u, v;
        tie(w, u, v) = edges[i];
        if(trace(u) != trace(v)) {
            join(u, v);
            costs.push_back(w);
        }
    }
    if(costs.back() < k) {
        ll ans = LLONG_MAX;
        rep(i, 0, m) {
            ans = min(ans, abs(k - get<0>(edges[i])));
        }
        cout << ans << '\n';
    }else {
        ll ans = 0;
        for(ll x : costs) {
            ans += max(0LL, x - k);
        }
        cout << ans << '\n';
    }
}

int main() {
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}