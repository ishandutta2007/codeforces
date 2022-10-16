/*input
6
1 2
1 3
2 4
2 5
5 6
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#define LOCAL 1
#else
#define LOCAL 0
#endif
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define all(x) (x).begin(), (x).end()
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#define debug(x...) {if (!LOCAL) return; cout << "[" << #x << "] ="; print(x);}
void print() {cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {if (!LOCAL) return; cout << value << ' '; print(values...);}
const int N = 1e5 + 5;

int n;
vector<vector<pair<int, int> > > a(N);
int ans[N];
vector<vector<int> > lev(N);

void dfs(int u, int p, int d) {
    for (auto [v, id] : a[u]) {
        if (v == p) continue;
        lev[d].push_back(id);
        dfs(v, u, d + 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    loop(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        a[u].push_back({v, i - 1});
        a[v].push_back({u, i - 1});
    }
    memset(ans, -1, sizeof(ans));
    int peak = -1;
    loop(i, 1, n) {
        if (a[i].size() >= 3) {
            ans[a[i][0].se] = 0;
            ans[a[i][1].se] = 1;
            ans[a[i][2].se] = 2;
            peak = 2;
            break;
        }
    }
    loop(i, 0, n - 2) if (ans[i] == -1) ans[i] = ++peak;
    loop(i, 0, n - 2) cout << ans[i] << endl;
}