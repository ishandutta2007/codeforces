#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 300000 + 5;

vector<int> v[N];
int fa[N];
int ans[N];
int f[N];
void dfs(int x) {
    f[x] = 0;
    for (auto to : v[x]) {
        if (to == fa[x]) {
            continue;
        }
        fa[to] = x;
        dfs(to);
        f[x] ^= (f[to] + 1);
    }
}
int ban[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i += 1) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    if (f[1]) ans[1] = 1;
    else ans[1] = 2;
    ban[1] = 1;
    int as = f[1];
    for (int i = 2; i <= n; i += 1) {
        int p = i;
        while (!ban[p]) {
            ban[p] = 1;
            as ^= (f[p] + 1) ^ f[p] ^ 1;
            p = fa[p];
        }
        ans[i] = (as == 0 ? 2 : 1);
    }
    for (int i = 1; i <= n; i += 1) cout << ans[i];

}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--) {
        solve();
    }
}