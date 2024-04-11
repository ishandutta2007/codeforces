/*input
5
6 3 2 5 0
1 2 10
2 3 3
2 4 1
1 5 1

*/
#include <bits/stdc++.h>
using namespace std;
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
#define ll long long
const int N = 300005;

int n;
vector<pair <int, ll> > a[N];
ll h[N], up[N], maxh[N];
ll ans = 0;

void dfs(int u, int p) {
    vector<ll> g;
    ll maxDown = 0;
    for (auto edge : a[u]) {
        int v = edge.fi;
        ll w = edge.se;
        if (v == p) continue;
        dfs(v, u);
        maxDown = max(maxDown, maxh[v] - w);
        g.push_back(maxh[v] - w);
    }
    sort(g.begin(), g.end(), greater <ll>());
    maxh[u] = maxDown + h[u];
    if (g.size() > 1) ans = max(ans, g[0] + g[1] + h[u]);
    ans = max(ans, maxh[u]);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    for (int i = 1; i < n; ++i) {
        int u, v; ll w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}