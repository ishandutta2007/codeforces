/*input

5
2 8 0 6 0
6
1 4
1 3
2 4
3 4
4 5
5 1

3
1 2 3
3
1 2
2 3
3 2
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
const int N = 1e5 + 5;
const int INF = 1e18;
const int mod = 1e9 + 7;

int n, m;
vector<vector<int> > a(N);
int cost[N];
pair<int, int> ans = {0, 1};

struct DirectedDfs {
    vector<int> num, low, in, S;
    int Time, numcc;

    DirectedDfs() : num(n + 5, -1), low(n + 5, 0), in(n + 5, 0), Time(0), numcc(0) {
        loop(i, 1, n) if (num[i] == -1) dfs(i);
    }

    void dfs(int u) {
        low[u] = num[u] = Time++;
        S.push_back(u);
        for (auto v : a[u]) {
            if (num[v] == -1) dfs(v);
            if (low[v] != INF) low[u] = min(low[u], low[v]);
        }
        if (low[u] == num[u]) {
            pair<int, int> best = {INF, 1};
            while (1) {
                int v = S.back(); S.pop_back(); num[v] = low[v] = INF;
                in[v] = numcc;
                if (cost[v] < best.fi) best = {cost[v], 1};
                else if (cost[v] == best.fi) best.se++;
                if (u == v) break;
            }
            numcc++;
            ans.fi += best.fi; ans.se = (ans.se * best.se) % mod;
        }
    };
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    loop(i, 1, n) {
        cin >> cost[i];
    }
    cin >> m;
    loop(i, 1, m) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
    }
    DirectedDfs tree;
    cout << ans.fi << sp << ans.se << endl;
}