#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
using namespace std;
typedef long long ll;
typedef double db;
const int N = 3e5 + 10;
int n, SG[N], num[N], ans[N], vis[N], fa[N];
vector<int> g[N];

void dfs(int u, int fa) {
    ::fa[u] = fa;
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        SG[u] ^= (SG[v] + 1);
    }
    return;
}

void solve() {
    cin >> n;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, 0);
    ans[1] = SG[1];
    for(int i = 1; i <= n; i++) num[i] = SG[i];
    vis[1] = 1;
    for(int i = 2; i <= n; i++) {
        ans[i] = ans[i - 1];
        if(vis[i]) continue;
        int a = i;
        for(int x = i; !vis[x]; x = fa[x]) a = x;
        ans[i] ^= num[fa[a]];
        for(int x = i; !vis[x]; x = fa[x]) {
            num[fa[x]] ^= (SG[x] + 1);
            ans[i] ^= num[fa[x]] ^ 1;
            vis[x] = 1;
        }
        ans[i] ^= num[i];
    }
    for(int i = 1; i <= n; i++) cout << "12"[ans[i] == 0];
    return;
}

int main() {
    solve();
    return 0;
}