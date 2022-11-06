#include <bits/stdc++.h>

using namespace std;
const int N = 105;

char board[N][N];
int n, m;
int state[N][N];
void add(int x, int y, int w) {
    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j++) {
            state[i][j] += w;
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
    }
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        for(int j = m; j >= 1; j--) {
            if(board[i][j] == 'W' && state[i][j] != 1) {
                add(i, j, 1 - state[i][j]);
                ans++;
            } else if(board[i][j] == 'B' && state[i][j] != -1) {
                add(i, j, -1 - state[i][j]);
                ans++;
            }
           
        }
    }
    printf("%d\n", ans);
    return 0;
}