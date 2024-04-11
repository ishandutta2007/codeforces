#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
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
        VVI to(n);
        rep(i, n - 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        vector<char> alive(n, true);
        VI deg(n);
        rep(i, n) deg[i] = to[i].size();
        VI nxts;
        rep(i, n) if (deg[i] <= 1) {
            nxts.push_back(i);
        }
        VI added(n);
        rep(_, k) {
            VI vs = move(nxts);
            nxts.clear();
            for(int u: vs) {
                alive[u] = false;
                for(int v: to[u]) deg[v]--;
            }
            for(int u: vs) for(int v: to[u]) if (deg[v] <= 1 && !added[v]) {
                added[v] = true;
                nxts.push_back(v);
            }
        }
        int ans = 0;
        rep(i, n) ans += alive[i];
        cout << ans << '\n';
    }
}