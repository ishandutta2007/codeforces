#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
vector < pair < int, int > > g[maxN];
int n;
int f1[maxN], f10[maxN][2], f0[maxN];
ll ans = 0;
void dfs(int v, int p) {
    int cur10[2] = {0, 0};
    int cur0 = 0, cur1 = 0;
    for (auto t : g[v]) {
        int to = t.first;
        int clr = t.second;
        if (to == p) continue;
        dfs(to, v);
        if (clr == 1) {
            cur1 += f1[to];
            cur10[1] += f10[to][1] + f0[to];
            ans -= (1LL * f10[to][1] + f0[to]) * f1[to];
        }
        else {
            cur0 += f0[to];
            cur10[0] += f10[to][0] + f1[to];
            ans -= (1LL * f10[to][0] + f1[to]) * (f0[to]);
        }
    }
    f10[v][0] = cur10[0];
    f10[v][1] = cur10[1];
    f0[v] = cur0 + 1;
    f1[v] = cur1 + 1;
    ans += 1LL * f10[v][0]  * f0[v] + 1LL * f10[v][1] * f1[v] + 1LL * f0[v] * f1[v];
 //   cout << v << " " << ans << " ggg" << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    dfs(1, -1);
    ans -= n;
    cout << ans;
    return 0;
}