
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1000, K = 40;
int n, m, k, q, r1, c1, r2, c2;
int a[N][N], dist[K][N][N];
bool vis[N][N], visc[K];
vector<pair<int, int>> col[K];
int adj[K][K];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inbounds(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs(int c) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vis[i][j] = false;
        }
    }
    queue<pair<int, int>> Q;
    for(auto p : col[c]) {
        auto [i, j] = p;
        vis[i][j] = true;
        dist[c][i][j] = 0;
        Q.emplace(i, j);
    }
    while(!Q.empty()) {
        auto [i, j] = Q.front(); Q.pop();
        for(int k = 0; k < 4; k++) {
            if(inbounds(i + dx[k], j + dy[k]) && !vis[i + dx[k]][j + dy[k]]) {
                dist[c][i + dx[k]][j + dy[k]] = dist[c][i][j] + 1;
                vis[i + dx[k]][j + dy[k]] = true;
                Q.emplace(i + dx[k], j + dy[k]);
            }
        }
    }
}

void bfs2(int c) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vis[i][j] = false;
        }
    }
    for(int i = 0; i < k; i++) {
        visc[i] = false;
    }
    visc[c] = true;
    queue<pair<int, int>> Q;
    for(auto p : col[c]) {
        auto [i, j] = p;
        vis[i][j] = true;
        dist[c][i][j] = 0;
        Q.emplace(i, j);
    }
    while(!Q.empty()) {
        auto [i, j] = Q.front(); Q.pop();
        for(int k = 0; k < 4; k++) {
            if(inbounds(i + dx[k], j + dy[k]) && !vis[i + dx[k]][j + dy[k]]) {
                dist[c][i + dx[k]][j + dy[k]] = dist[c][i][j] + 1;
                vis[i + dx[k]][j + dy[k]] = true;
                Q.emplace(i + dx[k], j + dy[k]);
            }
        }
        int c2 = a[i][j];
        if(!visc[c2]) {
            visc[c2] = true;
            for(auto p : col[c2]) {
                auto [i2, j2] = p;
                if(!vis[i2][j2]) {
                    dist[c][i2][j2] = dist[c][i][j] + 1;
                    vis[i2][j2] = true;
                    Q.emplace(i2, j2);
                }
            }
        }
    }
    for(int c2 = 0; c2 < k; c2++) {
        int mn = INT_MAX;//, mx = -1;
        for(auto p : col[c2]) {
            auto [i, j] = p;
            mn = min(mn, dist[c][i][j]);
        }
        adj[c][c2] = mn;
    }
}

inline int manh(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
            col[a[i][j]].emplace_back(i, j);
        }
    }
    for(int i = 0; i < k; i++) {
        bfs2(i);
    }
    for(int i = 0; i < k; i++) {
        bfs(i);
    }
    cin >> q;
    while(q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        int best = manh(r1, c1, r2, c2);
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                best = min(best, (i == j ? 1 : 2) + dist[i][r1][c1] + dist[j][r2][c2] + adj[i][j]);
            }
        }
        cout << best << endl;
    }
}