#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 55;

int n, m;
int mat[MAXN][MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i=0; i<n; i++) {
        if (mat[i][0] == 1 || mat[i][m-1] == 1) {
            printf("2\n"); return 0;
        }
    }
    for (int i=0; i<m; i++) {
        if (mat[0][i] == 1 || mat[n-1][i] == 1) {
            printf("2\n"); return 0;
        }
    }
    printf("4\n");
    return 0;
}