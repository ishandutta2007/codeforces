/*input
2
1 2
1 2
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 2e5 + 5;

int n;
vector<vector<pair<int, int> > > g(N);
pair<int, int> f[N];
int match[N], match2[N];
int vis[N], nxt[N];
set<int> active;

vector<int> genPerfect() {
    vector<int> ret(n);
    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;
    loop(i, 1, n) {
        for (auto it : g[i]) pq.push(it);
        while (!pq.empty() && pq.top().fi < i) pq.pop();
        ret[pq.top().se - 1] = i;
        pq.pop();
    }
    return ret;
}

void foundCycle(int root) {
    cout << "NO" << endl;
    vector<int> ans1(n + 1), ans2(n + 1);
    loop(i, 1, n) ans1[i] = match[i];
    int u = root;
    while (true) {
        match[u] = ans1[nxt[u]];
        u = nxt[u];
        if (u == root) break;
    }
    loop(i, 1, n) ans2[i] = match[i];
    loop(i, 1, n) cout << ans1[i] << sp;
    cout << endl;
    loop(i, 1, n) cout << ans2[i] << sp;
    cout << endl;
    exit(0);
}

void dfs(int u) {
    vector<int> done;
    vis[u] = 1;
    while (true) {
        auto it = active.lower_bound(f[u].fi);
        if (it != active.end() && *it == match[u]) {
            done.push_back(*it);
            it++;
        }
        if (it == active.end() || *it > f[u].se) break;
        int v = *it; done.push_back(v);
        assert(vis[match2[v]] != 2);
        nxt[u] = match2[v];
        if (vis[match2[v]] == 1) {
            foundCycle(match2[v]);
            exit(0);
        }
        dfs(match2[v]);
    }
    vis[u] = 2;
    for (auto it : done) if (active.find(it) != active.end()) active.erase(it);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    loop(i, 1, n) {
        int l, r; cin >> l >> r;
        g[l].push_back({r, i});
        f[i] = {l, r};
    }
    auto rec1 = genPerfect();
    loop(i, 0, n - 1) {
        match[i + 1] = rec1[i];
        match2[rec1[i]] = i + 1;
    }
    loop(i, 1, n) active.insert(i);
    loop(i, 1, n) {
        if (vis[i] == 0)
            dfs(i);
    }
    cout << "YES" << endl;
    for (auto it : rec1) cout << it << sp;
    cout << endl;
}