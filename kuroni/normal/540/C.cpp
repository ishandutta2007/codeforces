#include <bits/stdc++.h>
using namespace std;

const int M = 505, N = 505, DX[4] = {1, 0, -1, 0}, DY[4] = {0, 1, 0, -1};

int n, m, x, y, u, v;
char s[M][N];
bool vis[M][N];

void DFS(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int cx = x + DX[i], cy = y + DY[i];
        if (cx >= 1 && cx <= m && cy >= 1 && cy <= n && !vis[cx][cy] && s[cx][cy] == '.') {
            DFS(cx, cy);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> (s[i] + 1);
    }
    cin >> x >> y >> u >> v;
    if (m == 1 && n == 1) {
        return cout << "NO", 0;
    }
    int cnt = s[u][v] == 'X'; s[u][v] = '.'; 
    DFS(x, y);
    if (!vis[u][v]) {
        return cout << "NO", 0;
    }
    for (int i = 0; i < 4; i++) {
        int cx = u + DX[i], cy = v + DY[i];
        if (cx >= 1 && cx <= m && cy >= 1 && cy <= n && vis[cx][cy]) {
            cnt++;
        }
    }
    cout << (cnt >= 2 ? "YES" : "NO");
}