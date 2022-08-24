#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = 2 * (int)1e5 + 100;
vector < int > pr[maxN];
bool mark[maxN];
void init() {
    for (int i = 2; i < maxN; i++) {
        if (mark[i]) {
            continue;
        }
        mark[i] = true;
        for (int j = i; j < maxN; j += i) {
            mark[j] = true;
            pr[j].push_back(i);
        }
    }
}
int ans = 0;
int mx[maxN][7][2];
int a[maxN];
vector < int > g[maxN];
void dfs(int v, int p) {
    for (int i = 0; i < pr[a[v]].size(); i++) {
        mx[v][i][0] = 1;
    }
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        for (int i = 0; i < pr[a[v]].size(); i++) {
            int x = pr[a[v]][i];
            if (a[to] % x == 0) {
                int pos = find(pr[a[to]].begin(), pr[a[to]].end(), x) - pr[a[to]].begin();
                int upd_val = mx[to][pos][0] + 1;
                if (mx[v][i][0] < upd_val) {
                    mx[v][i][1] = mx[v][i][0];
                    mx[v][i][0] = upd_val;
                }
                else if (mx[v][i][1] < upd_val) {
                    mx[v][i][1] = upd_val;
                }
            }
        }
    }
    for (int i = 0; i < pr[a[v]].size(); i++) {
        ans = max(ans, mx[v][i][0]);
        ans = max(ans, mx[v][i][0] + mx[v][i][1] - 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    init();
    cin >> n;
    memset(mx, 0, sizeof mx);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1);
    cout << ans;
    return 0;
}