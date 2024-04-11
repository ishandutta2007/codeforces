#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ull;
mt19937_64 rnd(std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count());
ull mods[3];
int n, m;
const int maxN = 2 * (int)1e5 + 10;
int p[maxN];
int dist[maxN];
int ways[maxN][3];
vector < int > byDist[maxN];
vector < int > g[maxN], gr[maxN];
int k;
bool f[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < 3; i++) {
        mods[i] = rnd() + 232;
    }
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        gr[y].push_back(x);
        g[x].push_back(y);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> p[i];
    }
    memset(dist, -1, sizeof dist);
    dist[p[k]] = 0;
    queue < int > q;
    q.push(p[k]);
    byDist[0].push_back(p[k]);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : gr[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] == -1) continue;
        f[i] = false;
        int cnt = 0;
        for (int p : g[i]) {
            if (dist[p] == dist[i] - 1) cnt++;
        }
        f[i] = (cnt > 1);
    }
    int mn = 0;
    int mx = 0;
    for (int i = 1; i + 1 <= k; i++) {
        if (dist[p[i]] != dist[p[i + 1]] + 1) {
            mn++;
            mx++;
        }
        else {
            if (f[p[i]]) mx++;
        }
    }
    cout << mn << " " << mx;
    return 0;
}