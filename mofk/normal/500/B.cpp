#include <bits/stdc++.h>

using namespace std;

int n;
int p[305];
int a[305][305];
int vis[305];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        for (int j = 1; j <= n; ++j) a[i][j] = s[j-1] - '0';
    }
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        vector <int> pos, val;
        queue <int> q;
        vis[i] = 1;
        q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            pos.push_back(u);
            val.push_back(p[u]);
            for (int v = 1; v <= n; ++v) if (a[u][v] && !vis[v])
                vis[v] = 1, q.push(v);
        }
        sort(pos.begin(), pos.end());
        sort(val.begin(), val.end());
        for (int j = 0; j < pos.size(); ++j) p[pos[j]] = val[j];
    }
    for (int i = 1; i <= n; ++i) cout << p[i] << ' ';
    return 0;
}