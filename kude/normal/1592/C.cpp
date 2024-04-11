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
        int n, k;
        cin >> n >> k;
        VI a(n);
        rep(i, n) cin >> a[i];
        int x = 0;
        rep(i, n) x ^= a[i];
        VVI to(n);
        rep(i, n - 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        if (x == 0) {
            cout << "YES\n";
            continue;
        }
        if (k - 1 < 2) {
            cout << "NO\n";
            continue;
        }
        int cnt = 0;
        auto dfs = [&](auto&& self, int u, int p) -> int {
            int res = a[u];
            for(int v: to[u]) if (v != p) {
                res ^= self(self, v, u);
            }
            if (res == x) res = 0, cnt++;
            return res;
        };
        dfs(dfs, 0, -1);
        cout << (cnt >= 3 ? "YES" : "NO") << '\n';
    }
}