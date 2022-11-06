#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int per[4];

int n, m, l;
char board[N][N];
char instr[N];

int main() {
  
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf(" %s", &board[i][1]);
    }
    
    scanf("%s", &instr[1]);
    l = strlen(instr + 1);
    
    for (int i = 0; i < 4; i++) {
        per[i] = i;
    }
    
    int startx = -1, starty = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == 'S') {
                startx = i;
                starty = j;
                break;
            }
        }
    }
    
    for (int i = 1; i <= l; i++) {
        instr[i] -= '0';
    }
    
    int ans = 0;
    do {
        int x = startx;
        int y = starty;
        bool good = false;
        for (int i = 1; i <= l; i++) {
            int xx = x + dx[per[instr[i]]];
            int yy = y + dy[per[instr[i]]];
            if (xx < 1 || xx > n || yy < 1 || yy > m || board[xx][yy] == '#') {
                break;
            }
            x = xx;
            y = yy;
            if (board[x][y] == 'E') {
                good = true;
                break;
            }
        }
        if (good) {
            ans++;
        }
    } while (next_permutation(per, per + 4));
    
    printf("%d\n", ans);
    
    return 0;
}