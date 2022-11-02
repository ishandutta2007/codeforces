#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 505;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

string s[N];
int size[N * N];
int cnt[N * N];
int color[N][N];
int curAns;
int res;
int compSize;
int n;
int k;

bool valid(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n && s[x - 1][y - 1] == '.';
}    

void dfs(int x, int y, int col) {
    color[x][y] = col;
    compSize++;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (valid(nx, ny) && color[nx][ny] == -1)
            dfs(nx, ny, col);
    }    
}

void updateColor(int c, int delta) {
    if (c == -1)
        return;
    if (cnt[c] == 0)
        curAns += size[c];
    cnt[c] += delta;
    if (cnt[c] == 0)
        curAns -= size[c];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            color[i][j] = -1;
    int maxCol = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (valid(i, j) && color[i][j] == -1) {
                compSize = 0;
                dfs(i, j, maxCol);
                size[maxCol] = compSize;
                maxCol++;
            }
    for (int i = 1; i + k <= n + 1; i++) {
        for (int c = 0; c < maxCol; c++)
            cnt[c] = 0;
        curAns = 0;
        int extra = 0;
        for (int r = i - 1; r <= i + k; r++)
            for (int j = 0; j <= k + 1; j++) {
                int corner = 0;
                if (r == i - 1 || r == i + k)
                    corner++;
                if (j == 0 || j == k + 1)
                    corner++;
                if (corner == 2)
                    continue;
                updateColor(color[r][j], 1);
                if (corner == 0 && color[r][j] == -1)
                    extra++;    
            }
        res = max(res, curAns + extra);
        for (int j = 1; j + k <= n; j++) {
            for (int r = i; r <= i + k - 1; r++) {
                if (color[r][j] == -1)
                    extra--;
                if (color[r][j + k] == -1)
                    extra++;
                updateColor(color[r][j - 1], -1);
                updateColor(color[r][j + k + 1], 1);                            
            }
            updateColor(color[i - 1][j], -1);
            updateColor(color[i + k][j], -1);
            updateColor(color[i - 1][j + k], 1);
            updateColor(color[i + k][j + k], 1);
            res = max(res, curAns + extra);
        }
    }
    cout << res << endl;                        
    return 0;
}