#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int N = 500 + 10, oo = 0x3f3f3f3f;
int t, k, n;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int cnt[N][N][4], id[N][N], idtot = 0;
int dis[N * N], vis[N * N];
vector<pii> g[N * N];
void add(int x, int y, int opt) {
    cnt[x][y][opt]++;
    cnt[k + 2 - x][k + 2 - y][opt ^ 1]++;
    return;
}
void bfs(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= idtot; i++) dis[i] = oo, vis[i] = 0;
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto [v, w] : g[u]) {
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.emplace(dis[v], v);
            }
        }
    }
    return;
}
void solve() {
    for(int i = 1; i <= idtot; i++) g[i].clear();
    idtot = 0;
    cin >> n >> k;
    for(int i = 1; i <= k + 1; i++) for(int j = 1; j <= k + 1; j++) for(int o = 0; o < 4; o++) cnt[i][j][o] = 0;
    for(int i = 1; i <= k + 1; i++) for(int j = 1; j <= k + 1; j++) id[i][j] = ++idtot;
    for(int i = 1; i <= n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if(abs(r1 - r2) == 1) {
            if(r1 > r2) swap(r1, r2), swap(c1, c2);
            add(r2, c1, 0), add(r2, c1 + 1, 1);
        } else {
            if(c1 > c2) swap(r1, r2), swap(c1, c2);
            add(r1, c2, 2), add(r1 + 1, c2, 3);
        }
    }
    for(int x = 1; x <= k + 1; x++) {
        for(int y = 1; y <= k + 1; y++) {
            for(int o = 0; o < 4; o++) {
                int nx = x + dx[o], ny = y + dy[o];
                if(nx < 1 || nx > k + 1 || ny < 1 || ny > k + 1) continue;
                g[id[x][y]].emplace_back(id[nx][ny], cnt[x][y][o]);
            }
        }
    }
    bfs(id[k / 2 + 1][k / 2 + 1]);
    int ans = oo;
    for(int i = 1; i <= k + 1; i++) {
        for(int j = 1; j <= k + 1; j++) {
            if(i == 1 || i == k + 1 || j == 1 || j == k + 1) {
                ans = min(ans, dis[id[i][j]]);
            }
        }
    }
    cout << n - ans << endl;
    return;
}
int main() {
    cin >> t;
    for(; t--; solve());
    return 0;
}