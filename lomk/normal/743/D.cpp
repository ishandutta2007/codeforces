/*input
10
29 -2 39 1 98 98 82 56 5 -2
3 1
7 9
8 9
7 3
4 2
5 10
6 8
10 6
5 4
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
const int N = 200005;
const long long INF = 1e18;

int n;
long long value[N], sum[N], mx[N], ans = -INF;
vector <int> a[N];
bool isPossible = false;

void dfs(int u, int p) {
    sum[u] = value[u];
    mx[u] = -INF;
    int cntChild = 0;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (v == p) continue;
        cntChild++;
        dfs(v, u);
        sum[u] += sum[v];
        ans = max(ans, mx[u] + mx[v]);
        mx[u] = max(mx[u], mx[v]);
    }
    if (cntChild >= 2) isPossible = true;
    mx[u] = max(mx[u], sum[u]);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> value[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 1);
    if (!isPossible) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << ans << endl;
}