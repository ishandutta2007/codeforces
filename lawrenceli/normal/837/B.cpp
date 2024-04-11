#include <bits/stdc++.h>

using namespace std;

int n, m;
char mat[105][105];
char col[3] = {'B', 'G', 'R'};

int main() {
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s\n", mat[i]);

    do {
        bool good = true;
        if (n % 3 == 0) {
            for (int i = 0; i < n / 3; i++)
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] != col[0]) good = false;
                    if (mat[i + n / 3][j] != col[1]) good = false;
                    if (mat[i + 2 * n / 3][j] != col[2]) good = false;
                }
            if (good) {
                printf("YES\n");
                return 0;
            }
        }

        good = true;
        if (m % 3 == 0) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m / 3; j++) {
                    if (mat[i][j] != col[0]) good = false;
                    if (mat[i][j + m / 3] != col[1]) good = false;
                    if (mat[i][j + 2 * m / 3] != col[2]) good = false;
                }
            if (good) {
                printf("YES\n");
                return 0;
            }
        }
    } while (next_permutation(col, col + 3));

    printf("NO\n");
}