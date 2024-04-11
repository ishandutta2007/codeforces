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
        int n;
        cin >> n;
        VVI to(n);
        rep(_, n - 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        int tot = 0;
        int lcnt = 0, bcnt = 0;
        for(int v: to[0]) {
            // if true, u not removed
            auto dfs = [&](auto&& self, int u, int p) -> bool {
                if (to[u].size() == 1) return true;
                int child_remained = 0;
                for(int v: to[u]) if (v != p) {
                    if (self(self, v, u)) {
                        child_remained++;
                    }
                }
                if (child_remained) tot += child_remained, bcnt++;
                return !child_remained;
            };
            if (dfs(dfs, v, 0)) lcnt++, tot++;
        }
        int ans = tot - bcnt;
        if (lcnt == 0) ans++;
        cout << ans << '\n';
        // cout << tot << ' ' << bcnt << ' ' << lcnt << endl;
    }
}