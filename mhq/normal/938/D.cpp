#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxN = 2 * (int)1e5 + 10;
vector < pair < int, long long > > g[maxN];
long long dist[maxN];
priority_queue < pair < long long, int > > q;
int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        g[x].push_back(make_pair(y, 2 * w));
        g[y].push_back(make_pair(x, 2 * w));
    }
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        g[0].push_back(make_pair(i, a));
        //g[i].push_back(make_pair(0, a));
    }
    for (int i = 0; i <= n; i++) {
        dist[i] = -1;
    }
    dist[0] = 0;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        int v = t.second;
        long long we = -t.first;
        if (we > dist[v]) continue;
        //cout << v << '\n';
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i].first;
            if ((dist[to] == -1) || dist[to] > dist[v] + g[v][i].second) {
                dist[to] = dist[v] + g[v][i].second;
                q.push(make_pair(-dist[to], to));
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    return 0;
}