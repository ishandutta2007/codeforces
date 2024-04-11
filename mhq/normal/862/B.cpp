#include <bits/stdc++.h>
using namespace std;
vector <int> g[100000 + 3];
long long ans1;
long long ans2;
bool used[100000 + 3];
int q[100000 + 3];
void dfs ( int v ) {
    used[v] = true;
    for ( int i = 0; i < g[v].size(); i++) {
        if ( !used[g[v][i]]) {
            if (q[v] == 1) {
                q[g[v][i]] = 2;
                dfs(g[v][i]);
            }
            else {
                q[g[v][i]] = 1;
                dfs(g[v][i]);
            }
        }
    }
}
int main() {
    int n, x, y;
    cin >> n;
    for ( int i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    q[1] = 1;
    dfs(1);
    for ( int i = 1; i <= n; i++) {
        if ( q[i] == 1) ans1++;
        else ans2++;
    }
    cout << ans1 * ans2 - ( n - 1);
    return 0;
}