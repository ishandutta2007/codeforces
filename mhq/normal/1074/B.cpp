#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1005;
vector < int > g[maxN];
int in_p[2][maxN];
int h[maxN];
void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) continue;
        h[to] = h[v] + 1;
        dfs(to, v);
    }
}
void solve() {
    int n;
    cin >> n;
    memset(in_p, 0, sizeof in_p);
    memset(h, 0, sizeof h);
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k1, k2;
    cin >> k1;
    vector < int > all;
    for (int i = 1; i <= k1; i++) {
        int x;
        cin >> x;
        all.push_back(x);
        in_p[0][x] = true;
    }
    cin >> k2;
    int any = -1;
    for (int i = 1; i <= k2; i++) {
        int y;
        cin >> y;
        any = y;
        in_p[1][y] = true;
    }
    cout << "B" << " " << any << endl;
    int ans;
    cin >> ans;
    if (in_p[0][ans]) {
        cout << "C" << " " << ans << endl;
        return ;
    }
    dfs(ans, -1);
    int mn = n + 10;
    int ind = -1;
    for (int v : all) {
        if (h[v] < mn) {
            mn = h[v];
            ind = v;
        }
    }
    cout << "A" << " " << ind << endl;
    int ans2;
    cin >> ans2;
    if (in_p[1][ans2]) {
        cout << "C" << " " << ind << endl;
    }
    else {
        cout << "C" << " " << -1 << endl;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(0));
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}