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

VI cycle;
VI path;
VVI to;

bool visited[200010];

bool dfs(int u, int p=-1) {
    if (visited[u]) {
        while(path.back() != u) {
            cycle.push_back(path.back());
            path.pop_back();
        }
        cycle.push_back(u);
        return true;
    }
    visited[u] = true;
    path.push_back(u);
    for(int v: to[u]) {
        if (v == p) continue;
        if (dfs(v, u)) return true;
    }
    path.pop_back();
    return false;
}

int dfs2(int u, int p) {
    int ret = 1;
    for(int v: to[u]) {
        if (v == p) continue;
        ret += dfs2(v, u);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        to = VVI(n);
        rep(i, n) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        cycle.clear();
        path.clear();
        rep(i, n) visited[i] = false;
        dfs(0);
        set<int> cset(all(cycle));
        VI cnt;
        ll csz = cycle.size();
        ll rest = n - csz;
        ll ans = csz * (csz - 1);
        for(int u: cset) {
            VI cnts;
            for(int v: to[u]) {
                if (cset.find(v) != cset.end()) continue;
                ll cnt = dfs2(v, u);
                ans += cnt * (cnt - 1) / 2;
                ans += cnt * (1 + (csz - 1) * 2);
                cnts.push_back(cnt);
            }
            ll t = 0;
            ll t2 = 0;
            for(ll cnt: cnts) {
                t += cnt;
                t2 += cnt * cnt;
            }
            ans += t * (rest - t);
            ans += (t * t - t2) / 2;
        }
        cout << ans << '\n';
    }
}