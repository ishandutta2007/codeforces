#include <bits/stdc++.h>

using namespace std;

const int N = 1005, LOG = 10;

int n, m, t, xmin, ymin, xmax, ymax;
int tab[N][N], pref[N][N], bestRect[N][N];
int pot[N];
int rmq[LOG + 1][LOG + 1][N][N];

int query(int xmin, int ymin, int xmax, int ymax) {
    if (xmax < xmin || ymax < ymin) {
        return 0;
    }
    int p1 = pot[xmax - xmin + 1];
    int p2 = pot[ymax - ymin + 1];
    return max(max(rmq[p1][p2][xmin][ymin],
                   rmq[p1][p2][xmax - (1 << p1) + 1][ymin]),
               max(rmq[p1][p2][xmin][ymax - (1 << p2) + 1],
                   rmq[p1][p2][xmax - (1 << p1) + 1][ymax - (1 << p2) + 1]));
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &tab[i][j]);
            tab[i][j] ^= 1;
            pref[i][j] = tab[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int low = 1;
            int high = min(n - i + 1, m - j + 1);
            int res = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (pref[i + mid - 1][j + mid - 1] - pref[i - 1][j + mid - 1] - pref[i + mid - 1][j - 1] + pref[i - 1][j - 1] == 0) {
                    res = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            bestRect[i][j] = res;
        }
    }

    pot[1] = 0;
    for (int i = 2; i <= max(n, m); i++) {
        pot[i] = pot[i / 2] + 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            rmq[0][0][i][j] = bestRect[i][j];
        }
    }

    for (int l = 1; l <= LOG; l++) {
        for (int i = 1; i + (1 << l) - 1 <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int p = (1 << (l - 1));
                rmq[l][0][i][j] = max(rmq[l - 1][0][i][j], rmq[l - 1][0][i + p][j]);
            }
        }
    }
    for (int l = 1; l <= LOG; l++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j + (1 << l) - 1 <= m; j++) {
                int p = (1 << (l - 1));
                rmq[0][l][i][j] = max(rmq[0][l - 1][i][j], rmq[0][l - 1][i][j + p]);
            }
        }
    }
    for (int l = 1; l <= LOG; l++) {
        for (int r = 1; r <= LOG; r++) {
            for (int i = 1; i + (1 << l) - 1 <= n; i++) {
                for (int j = 1; j + (1 << r) - 1 <= m; j++) {
                    int p1 = (1 << (l - 1));
                    int p2 = (1 << (r - 1));
                    rmq[l][r][i][j] = max(max(rmq[l - 1][r - 1][i][j],
                                              rmq[l - 1][r - 1][i + p1][j]),
                                          max(rmq[l - 1][r - 1][i][j + p2],
                                              rmq[l - 1][r - 1][i + p1][j + p2]));
                }
            }
        }
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);
        int low = 1;
        int high = min(xmax - xmin + 1, ymax - ymin + 1);
        int res = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (query(xmin, ymin, xmax - mid + 1, ymax - mid + 1) >= mid) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        printf("%d\n", res);
    }

    return 0;
}