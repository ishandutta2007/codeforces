/*input
3 2
1 3
2 3

4 3
1 2
2 3
3 1
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

int n, m;
vector<vector<int> > a(N);
vector<vector<int> > b(N);
int vis[N];
int mnf[N], mnb[N];
vector<int> oa, ob;

// const int INF = numeric_limits<int>::max() / 2;
void dfs(int u) {
    vis[u] = 1;
    for (auto v : a[u]) {
        if (vis[v] == 0) dfs(v);
        else if (vis[v] == 1) throw 1;
    }
    oa.push_back(u);
    vis[u] = 2;
}

void dfs2(int u) {
    vis[u] = 1;
    for (auto v : b[u]) {
        if (vis[v] == 0) dfs2(v);
        else if (vis[v] == 1) throw 1;
    }
    vis[u] = 2;
    ob.push_back(u);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    loop(i, 1, m) {
        int u, v; cin >> u >> v;
        a[v].push_back(u);
        b[u].push_back(v);
    }
    try {
        loop(i, 1, n) if (!vis[i]) dfs(i);
        memset(vis, 0, sizeof(vis));
        loop(i, 1, n) if (!vis[i]) dfs2(i);
    } catch (...) {
        cout << -1 << endl;
        return 0;
    }
    reverse(oa.begin(), oa.end());
    reverse(ob.begin(), ob.end());
    // print(oa, ob);
    memset(mnf, 60, sizeof(mnf)); memset(mnb, 60, sizeof(mnb));
    for (auto u : oa) {
        mnb[u] = min(mnb[u], u);
        for (auto v : a[u]) mnb[v] = min(mnb[v], mnb[u]);
    }
    for (auto u : ob) {
        mnf[u] = min(mnf[u], u);
        for (auto v : b[u]) mnf[v] = min(mnf[v], mnf[u]);
    }
    int cnt = 0;
    string s;
    loop(i, 1, n) {
        if (mnf[i] >= i && mnb[i] >= i) {
            cnt++;
            s += "A";
        }
        else {
            s += "E";
        }
    }
    cout << cnt << endl;
    cout << s << endl;
}