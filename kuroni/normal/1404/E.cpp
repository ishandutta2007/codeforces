#include <bits/stdc++.h>
using namespace std;

const int M = 205;

int m, n, cnt = 0;
int it = 0, le = 0, ri = 0, mat[M * M], chk[M * M];
string s[M];
vector<int> adj[M * M], hor[M][M], ver[M][M];

bool DFS(int u) {
    chk[u] = it + 1;
    for (int v : adj[u]) {
        if (mat[v] == 0) {
            mat[v] = u;
            return true;
        }
    }
    for (int v : adj[u]) {
        if (chk[mat[v]] <= it && DFS(mat[v])) {
            mat[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            cnt += (s[i][j] == '#');
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (s[i][j] == '#' && s[i][j + 1] == '#') {
                ++le;
                hor[i][j].push_back(le);
                hor[i][j + 1].push_back(le);
            }
        }
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '#' && s[i + 1][j] == '#') {
                ++ri;
                ver[i][j].push_back(ri);
                ver[i + 1][j].push_back(ri);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int u : hor[i][j]) {
                for (int v : ver[i][j]) {
                    adj[u].push_back(v);
                }
            }
        }
    }
    for (int i = 1; i <= le; i++) {
        it += DFS(i);
    }
    cout << cnt - (le + ri - it);
}