
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// (-1, -1) has to come in connected regions.
// label each (-1, -1) to point to an adjacent (-1, -1).
// for (r, c), it must be in a connected region containing the cell
// at position (r, c). Flood fill from each (r, c).

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define BLOCK 4

const int N = 1005;
int n;
int x[N][N], y[N][N], par[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dirch[5] = {'U', 'D', 'L', 'R', 'X'};

inline int oppdir(const int dir) {
    switch(dir) {
        case UP: return DOWN;
        case DOWN: return UP;
        case LEFT: return RIGHT;
        case RIGHT: return LEFT;
        default: return dir;
    }
}

bool inbounds(int r, int c) {
    return 1 <= r && r <= n && 1 <= c && c <= n;
}

void dfs(int i, int j) {
    for(int k = 0; k < 4; k++) {
        if(inbounds(i + dx[k], j + dy[k]) && 
                x[i + dx[k]][j + dy[k]] == x[i][j] &&
                y[i + dx[k]][j + dy[k]] == y[i][j] &&
                par[i + dx[k]][j + dy[k]] == -1) {
            par[i + dx[k]][j + dy[k]] = oppdir(k);
            dfs(i + dx[k], j + dy[k]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x[i][j] >> y[i][j];
            par[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(x[i][j] == -1) {
                for(int k = 0; k < 4; k++) {
                    if(inbounds(i + dx[k], j + dy[k]) &&
                            x[i + dx[k]][j + dy[k]] == -1) {
                        par[i][j] = k;
                        break;
                    }
                }
            }else if(x[i][j] == i && y[i][j] == j) {
                par[i][j] = BLOCK;
                dfs(i, j);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(par[i][j] == -1) {
                cout << "INVALID" << endl;
                return 0;
            }
        }
    }
    cout << "VALID" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << dirch[par[i][j]];
        }
        cout << endl;
    }
}