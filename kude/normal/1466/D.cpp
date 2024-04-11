#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
        VL w(n);
        rep(i, n) cin >> w[i];
        VVI to(n);
        rep(_, n - 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        priority_queue<ll> q;
        auto dfs = [&](auto self, int u, int p=-1) -> void {
            if (u == 0) {
                bool first = true;
                for(int v: to[u]) {
                    if (first) first = false;
                    else q.push(w[u]);
                    self(self, v, u);
                }
                return;
            }
            for(int v: to[u]) {
                if (v == p) continue;
                q.push(w[u]);
                self(self, v, u);
            }
        };
        dfs(dfs, 0);
        ll ans = 0;
        rep(i, n) ans += w[i];
        rep(i, n - 1) {
            cout << ans;
            if (i + 1 == n - 1) cout << '\n';
            else {
                cout << ' ';
                ans += q.top(); q.pop();
            }
        }   
    }
}