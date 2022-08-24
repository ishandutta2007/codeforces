#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e5 + 10;
vector < int > g[maxN];
int ans = 0;
int h[maxN];
bool f[2];
void dfs(int root, int p) {
    int cnt_l = 0;
    for (int to : g[root]) {
        if (to == p) continue;
        h[to] = h[root] + 1;
        dfs(to, root);
        if (g[to].size() == 1) {
            cnt_l++;
            f[h[to] % 2] = true;
        }
    }
    if (cnt_l) ans -= (cnt_l - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    ans = n - 1;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() > 1) {
            root = i;
            break;
        }
    }
    assert(root != -1);
    dfs(root, -1);
    int mn = 1;
    if (f[0] && f[1]) mn = 3;
    cout << mn << " " << ans;
    return 0;
}