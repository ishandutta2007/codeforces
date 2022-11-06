#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, m, q, r1, c2, r2, c1;
char board[N][N];
int pionowe[N][N], poziome[N][N];

int main() {
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
    }
    
    for (int i = 0; i <= n + 1; i++) {
        board[i][0] = board[i][m + 1] = '#';
    }
    for (int i = 0; i <= m + 1; i++) {
        board[0][i] = board[n + 1][i] = '#';
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            poziome[i][j] = (board[i][j] == '.' && board[i][j - 1] == '.' ? 1 : 0);
            pionowe[i][j] = (board[i][j] == '.' && board[i - 1][j] == '.' ? 1 : 0);
            poziome[i][j] += poziome[i - 1][j] + poziome[i][j - 1] - poziome[i - 1][j - 1];
            pionowe[i][j] += pionowe[i - 1][j] + pionowe[i][j - 1] - pionowe[i - 1][j - 1];
        }
    }
    
    
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int wynikPoziome = c1 < c2 ? poziome[r2][c2] - poziome[r1 - 1][c2] - poziome[r2][c1] + poziome[r1 - 1][c1] : 0;
        int wynikPionowe = r1 < r2 ? pionowe[r2][c2] - pionowe[r2][c1 - 1] - pionowe[r1][c2] + pionowe[r1][c1 - 1] : 0;
        printf("%d\n", wynikPionowe + wynikPoziome);
    }
    
    return 0;
}