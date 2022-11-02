#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 310;
const int ADD = 155;
const int M = 31;

bool was[N][N][M][8][5];
int t[N];
int levels;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int prevDir(int n) {
    n--;
    if (n < 0)
        n += 8;
    return n;
}

int nextDir(int n) {
    n++;
    if (n >= 8)
        n -= 8;
    return n;
}

void dfs(int x, int y, int level, int dir, int to_go) {
    if (was[x][y][level][dir][to_go])
        return;
    was[x][y][level][dir][to_go] = true;
    if (to_go == 0) {
        if (level == levels - 1)
            return;
        int d1 = prevDir(dir);
        int d2 = nextDir(dir);
        dfs(x + dx[d1], y + dy[d1], level + 1, d1, t[level + 1] - 1);
        dfs(x + dx[d2], y + dy[d2], level + 1, d2, t[level + 1] - 1);  
        return; 
    }
    dfs(x + dx[dir], y + dy[dir], level, dir, to_go - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> levels;
    for (int i = 0; i < levels; i++)
        cin >> t[i];
    dfs(ADD, ADD, 0, 0, t[0] - 1);
    int res = 0;
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++) {
            bool ok = false;
            for (int l = 0; l < M; l++)
                for (int d = 0; d < 8; d++)
                    for (int g = 0; g < 5; g++)
                        if (was[x][y][l][d][g])
                            ok = true; 
            if (ok)
                res++;
        }
    cout << res << endl;    
}