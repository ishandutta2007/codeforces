#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int n, m, s;
vector < int > g[maxN];
int clr[maxN];
bool used[maxN][2];
int out_deg[maxN];
pair < int, int > prv[maxN][2];
queue < pair < int, int > > q;
bool dfs(int v) {
    clr[v] = 1;
    bool ok = false;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (clr[to] == 1) {
            return true;
        }
        if (clr[to] == 0) ok |= dfs(to);
    }
    clr[v] = 2;
    return ok;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int x;
            cin >> x;
            g[i].push_back(x);
            out_deg[i]++;
        }
    }
    cin >> s;
    bool draw = false;
    draw = dfs(s);
    q.push(make_pair(s, 0));
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int v = t.first;
        int type = t.second;
        used[v][type] = true;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (used[to][type ^ 1]) continue;
            prv[to][type ^ 1] = make_pair(v, type);
            q.push(make_pair(to, type ^ 1));
        }
    }
    vector < int > ans;
    for (int i = 1; i <= n; i++) {
        if (used[i][1] && out_deg[i] == 0) {
            cout << "Win" << '\n';
            int v = i;
            int type = 1;
            while (make_pair(v, type) != make_pair(0, 0)) {
                ans.push_back(v);
                int ntype = prv[v][type].second;
                v = prv[v][type].first;
                type = ntype;
            }
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
            return 0;
        }
    }
    if (draw) cout << "Draw";
    else cout << "Lose";
    return 0;
}