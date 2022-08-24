#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e6 + 10;
vector < int > g[maxN];
vector < int > gr[maxN];
bool in_ans[maxN];
bool in_rec[maxN];
int n, m;
vector < int > all;
vector < int > ans;
void solve() {
    while (!all.empty()) {
        int v = all.back();
        if (!in_rec[v]) all.pop_back();
        else break;
    }
    if (all.empty()) return;
    int v = all.back();
    in_rec[v] = false;
    all.pop_back();
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (in_rec[to]) {
            in_rec[to] = false;
        }
    }
    solve();
    bool ok = true;
    for (int i = 0; i < gr[v].size(); i++) {
        int to = gr[v][i];
        if (in_ans[to]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        in_ans[v] = true;
        ans.push_back(v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        gr[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        in_rec[i] = true;
        all.push_back(i);
    }
    solve();
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}