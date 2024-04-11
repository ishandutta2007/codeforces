#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int n, m, k, s;
vector < int > clr[120];
vector < int > g[maxN];
int dist[maxN][105];
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        clr[x].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(dist, -1, sizeof dist);
    for (int i = 1; i <= k; i++) {
        queue < int > q;
        for (int j = 0; j < clr[i].size(); j++) {
            dist[clr[i][j]][i] = 0;
            q.push(clr[i][j]);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int j = 0; j < g[v].size(); j++) {
                int to = g[v][j];
                if (dist[to][i] == -1) {
                    dist[to][i] = dist[v][i] + 1;
                    q.push(to);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        vector < int > ans;
        for (int j = 1; j <= k; j++) {
            ans.push_back(dist[i][j]);
        }
        sort(ans.begin(), ans.end());
        long long sum = 0;
        for (int i = 0; i < s; i++) sum += ans[i];
        cout << sum << " ";
    }
    return 0;
}