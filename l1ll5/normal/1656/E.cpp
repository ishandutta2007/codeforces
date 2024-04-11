#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 200000 + 5;
vector<int> v[N];
int deg[N];
int col[N];
void dfs(int x, int fa, int c) {
    col[x] = c;
    for (int to : v[x]) {
        if (to != fa) {
            dfs(to, x, c ^ 1);
        }
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i += 1) col[i] = deg[i] = 0, v[i].clear();
        for (int i = 0; i < n - 1; i += 1) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
            deg[x] += 1, deg[y] += 1;
        }
        dfs(1, 0, 0);
        for (int i = 1; i <= n; i += 1) {
            if (col[i]) cout << -deg[i] << ' ';
            else cout << deg[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}