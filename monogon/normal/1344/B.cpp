
#include <iostream>

using namespace std;

const int N = 1005;
int n, m;
string s[N];
int minrow[N], maxrow[N], mincol[N], maxcol[N];
bool emptyrow, emptycol, vis[N][N];

bool inbounds(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool dfs(int x, int y) {
    if(!inbounds(x, y) || s[x][y] == '.' || vis[x][y]) return false;
    vis[x][y] = true;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fill(minrow, minrow + N, N);
    fill(mincol, mincol + N, N);
    fill(maxrow, maxrow + N, -1);
    fill(maxrow, maxrow + N, -1);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '#') {
                minrow[i] = min(minrow[i], j);
                maxrow[i] = max(maxrow[i], j);
                mincol[j] = min(mincol[j], i);
                maxcol[j] = max(maxcol[j], i);
            }
        }
    }
    // each row is a segment
    for(int i = 0; i < n; i++) {
        if(minrow[i] > maxrow[i]) emptyrow = true;
        for(int j = minrow[i]; j <= maxrow[i]; j++) {
            if(s[i][j] == '.') {
                cout << "-1\n";
                return 0;
            }
        }
    }
    // each column is a segment
    for(int j = 0; j < m; j++) {
        if(mincol[j] > maxcol[j]) emptycol = true;
        for(int i = mincol[j]; i <= maxcol[j]; i++) {
            if(s[i][j] == '.') {
                cout << "-1\n";
                return 0;
            }
        }
    }
    if(emptyrow != emptycol) {
        cout << "-1\n";
        return 0;
    }
    // count number of connected components
    int comp = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            comp += dfs(i, j);
        }
    }
    cout << comp << '\n';
}