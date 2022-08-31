#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = (int)1e4 + 10;
int pr[maxN];
int c[maxN];
int ans = 0;
vector < int > g[maxN];
void dfs(int a, int cl) {
    if (c[a] != cl) {
        ans++;
        cl = c[a];
    }
    for (int i = 0; i < g[a].size(); i++) {
        int to = g[a][i];
        dfs(to, cl);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> pr[i];
        g[pr[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}