#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;

int n, m, hdir[MAXN], vdir[MAXN];
bool vis[MAXN][MAXN];

void dfs(int r, int c) {
    if (r<0 || r>=n || c<0 || c>=m) return;
    if (vis[r][c]) return;
    vis[r][c] = 1;
    dfs(r, c+hdir[r]);
    dfs(r+vdir[c], c);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        char c; cin >> c;
        if (c == '<') hdir[i] = -1;
        else hdir[i] = 1;
    }
    for (int i=0; i<m; i++) {
        char c; cin >> c;
        if (c == '^') vdir[i] = -1;
        else vdir[i] = 1;
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            memset(vis, 0, sizeof(vis));
            dfs(i, j);
            for (int i1=0; i1<n; i1++)
                for (int j1=0; j1<m; j1++)
                    if (!vis[i1][j1]) {
                        cout << "NO\n";
                        return 0;
                    }
        }
    cout << "YES\n";
    return 0;
}