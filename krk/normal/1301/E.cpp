#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;
const int Maxk = 252;
const int Maxd = 4;
const string cols = "GYRB";

int n, m, q;
char B[Maxn][Maxn];
int A[Maxd][Maxn][Maxn];
int sup[Maxk][Maxn][Maxn];

int Get(int B[][Maxn], int r1, int c1, int r2, int c2)
{
    return B[r2][c2] - B[r1 - 1][c2] - B[r2][c1 - 1] + B[r1 - 1][c1 - 1];
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", B[i] + 1);
        for (int j = 1; j <= m; j++) {
            int let = cols.find(B[i][j]);
            A[let][i][j] = 1;
        }
    }
    for (int d = 0; d < Maxd; d++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                A[d][i][j] += A[d][i - 1][j] + A[d][i][j - 1] - A[d][i - 1][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int lef = 1, rig = Maxk - 1;
            while (lef <= rig) {
                int d = lef + rig >> 1;
                if (d <= i && d <= j && i + d <= n && j + d <= m &&
                    Get(A[2], i - d + 1, j - d + 1, i, j) == d * d &&
                    Get(A[0], i - d + 1, j + 1, i, j + d) == d * d &&
                    Get(A[1], i + 1, j - d + 1, i + d, j) == d * d &&
                    Get(A[3], i + 1, j + 1, i + d, j + d) == d * d)
                    lef = d + 1;
                else rig = d - 1;
            }
            int d = lef - 1;
            if (d > 0) sup[d][i][j] = 1;
        }
    for (int d = Maxk - 1; d > 0; d--)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (sup[d][i][j]) sup[d - 1][i][j] += sup[d][i][j];
                sup[d][i][j] += sup[d][i - 1][j] + sup[d][i][j - 1] - sup[d][i - 1][j - 1];
            }
    while (q--) {
        int r1, c1, r2, c2; scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int lef = 1, rig = Maxk - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            int ur1 = r1 + mid - 1, uc1 = c1 + mid - 1;
            int ur2 = r2 - mid, uc2 = c2 - mid;
            if (ur1 <= ur2 && uc1 <= uc2 &&
                Get(sup[mid], ur1, uc1, ur2, uc2) > 0)
                lef = mid + 1;
            else rig = mid - 1;
        }
        printf("%d\n", 4 * (lef - 1) * (lef - 1));
    }
    return 0;
}