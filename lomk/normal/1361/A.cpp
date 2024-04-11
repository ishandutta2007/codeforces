/*input
3 3
1 2
2 3
3 1
2 1 3

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
const int N = 5e5 + 5;

int n, m;
vector<vector<int> > a(N);
int need[N], lab[N];
bool mark[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    loop(i, 1, m) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    loop(i, 1, n) cin >> need[i];
    vector<pair<int, int> > order;
    loop(i, 1, n) order.push_back({need[i], i});
    sort(order.begin(), order.end());
    for (auto [val, u] : order) {
        mark[0] = true;
        for (auto v : a[u]) mark[lab[v]] = true;
        loop(i, 0, n) {
            if (mark[i] == false) {
                if (val != i) {
                    cout << -1 << endl;
                    return 0;
                }
                break;
            }
        }
        for (auto v : a[u]) mark[lab[v]] = false;
        lab[u] = val;
    }
    for (auto it : order) cout << it.se << sp;
    cout << endl;
}