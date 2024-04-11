#include<bits/stdc++.h>
using namespace std;
int const nax = 510, L = 10, inf = 1e9;
int n, m, lg[nax];
int a[nax][nax];
int p[nax][nax][4];
char s[nax][nax];


#define eprintf(...) fprintf(stderr, __VA_ARGS__)
char c[] = {'R', 'G', 'Y', 'B'};

inline bool in_x_range (int v) {
    return v >= 1 && v <= n;
}

inline bool in_y_range (int v) {
    return v >= 1 && v <= m;
}



struct sparse_table_2d {
    int sp[L][L][nax][nax];

    sparse_table_2d () {
        for (int i = 2 ; i < nax ; ++ i)
            lg[i] = lg[i >> 1] + 1;
    }

    void build () {

        for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            sp[0][0][i][j] = ::a[i][j];
        }

        for (int x = 1 ; x < L ; ++ x) {
            for (int i = 1 ; i + (1 << x) <= n + 1 ; ++ i)
            for (int j = 1 ; j <= m ; ++ j) {
                sp[x][0][i][j] = max(sp[x - 1][0][i][j], sp[x - 1][0][i + (1 << (x - 1))][j]);
            }
        }

        for (int x = 0 ; x < L ; ++ x)
        for (int y = 1 ; y < L ; ++ y) {
            for (int i = 1 ; i + (1 << x) <= n + 1; ++ i)
            for (int j = 1 ; j + (1 << y) <= m + 1; ++ j) {
                sp[x][y][i][j] = max(sp[x][y - 1][i][j], sp[x][y - 1][i][j + (1 << (y - 1))]);
            }
        }

    }

    int get_max (int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) return -inf;
        if (!in_x_range(x1) || !in_x_range(x2)) return - inf;
        if (!in_y_range(y1) || !in_y_range(y2)) return - inf;

        int a = lg[x2 - x1 + 1];
        int b = lg[y2 - y1 + 1];

        int m1 = max(sp[a][b][x1][y1], sp[a][b][x1][y2 - (1 << b) + 1]);
        int m2 = max(sp[a][b][x2 - (1 << a) + 1][y1], sp[a][b][x2 - (1 << a) + 1][y2 - (1 << b) + 1]);

        return max(m1, m2);

    }
};

int get_sum (int x1, int y1, int x2, int y2, int k) {
    return p[x2][y2][k] - p[x1 - 1][y2][k] - p[x2][y1 - 1][k] + p[x1 - 1][y1 - 1][k];
}

sparse_table_2d table;

int query () {
    int r1, r2, c1, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    int l = 1, r = min(r2 - r1 + 1, c2 - c1 + 1), ans = 0;


    while (l <= r) {
        int mid = l + r >> 1;
        int res = table.get_max(r1 + mid - 1, c1 + mid - 1, r2 - mid, c2 - mid);

        if (res >= mid) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }


    return 4 * ans * ans;
}

bool ok (int x, int y, int range) {
    int res = get_sum(x - range + 1, y - range + 1, x, y, 0);
    if (res != range * range) return false;

    res = get_sum(x - range + 1, y + 1,  x, y + range, 1);

    if (res != range * range) return false;


    res = get_sum(x + 1, y - range + 1, x + range, y, 2);

    if (res != range * range) return false;

    res = get_sum(x + 1, y + 1, x + range, y + range, 3);

    if (res != range * range) return false;

    return true;
}

int main () {
    int q ;
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%s", s[i] + 1);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= m ; ++ j) {
            for (int k = 0 ; k < 4 ; ++ k) {
                p[i][j][k] = p[i - 1][j][k] + p[i][j - 1][k] - p[i - 1][j - 1][k] + (s[i][j] == c[k]);
            }
        }
    }


    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= m ; ++ j) {
        if (s[i][j] == 'R' && s[i][j + 1] == 'G' && s[i + 1][j] == 'Y' && s[i + 1][j + 1] == 'B') {
            int l = 1 , r = min( { i, n - i + 1, j, m - j + 1}), ans = 1;

            while (l <= r) {
                int mid = l + r >> 1;
                if (ok(i, j, mid)) {
                    ans = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }

            a[i][j] = ans;

        }
    }

   /* for (int i = 1 ; i <= n;  ++ i , puts(""))
        for (int j = 1 ; j <= m ; ++ j)
            printf("%d ", a[i][j]);

*/

    table.build();

  //  eprintf("%d\n", table.sp[0][1][3][3]);
  //  eprintf("huh 3 3 3 5 %d\n", table.get_max(3, 3, 3, 5));


    for (; q -- ; ) {
        printf("%d\n", query());
    }
}
/*
    Good Luck
        -Lucina
*/