#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;

int n, m;
char mat[maxn][maxn];
int r1, c1, r2, c2;
int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
bool vis[maxn][maxn];

bool good(int r, int c) { return r>=0 && r<n && c>=0 && c<m; }

void go(int r, int c) {
    vis[r][c] = 1;
    if (r == r2 && c == c2) {
        cout << "YES";
        exit(0);
    }
    for (int i=0; i<4; i++) {
        int nr = r+dr[i], nc = c+dc[i];
        if (good(nr, nc) && ((nr == r2 && nc == c2) || mat[nr][nc] == '.' && !vis[nr][nc]))
            go(nr, nc);
    }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> mat[i];
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    
    if (r1 == r2 && c1 == c2) {
        for (int i=0; i<4; i++) {
            int r = r1+dr[i], c = c1+dc[i];
            if (good(r, c) && mat[r][c] == '.') {
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
        return 0;
    }
        
    
    if (mat[r2][c2] == 'X') {
        go(r1, c1);
        cout << "NO";
        return 0;
    }
    
    for (int i=0; i<4; i++) {
        int r = r2+dr[i], c = c2+dc[i];
        if (good(r, c) && mat[r][c] != 'X') {
            mat[r][c] = 'X';
            memset(vis, 0, sizeof(vis));
            go(r1, c1);
            mat[r][c] = '.';
        }
    }
    cout << "NO";
}