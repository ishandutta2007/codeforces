#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<ll,ll>;
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
        int n;
        cin >> n;
        VI x(n), y(n);
        rep(i, n) cin >> x[i] >> y[i];
        VVI to(n);
        rep(i, n - 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        auto dfs = [&](auto&& self, int u, int p=-1) -> P {
            ll r1 = 0, r2 = 0;
            for(int v: to[u]) if (v != p) {
                auto [t1, t2] = self(self, v, u);
                r1 += max(abs(x[u] - x[v]) + t1, abs(x[u] - y[v]) + t2);
                r2 += max(abs(y[u] - x[v]) + t1, abs(y[u] - y[v]) + t2);
            }
            return {r1, r2};
        };
        auto [r1, r2] = dfs(dfs, 0, -1);
        cout << max(r1, r2) << '\n';
    }
}