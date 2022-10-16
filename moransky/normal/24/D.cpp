#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1005;
int n, m, x, y;
double f[N][N], a[N][N];
void inline gauss() {
    a[1][2] /= a[1][1], a[1][0] /= a[1][1], a[1][1] = 1;
    a[2][0] -= a[2][1] * a[1][0];
    for (int i = 3; i >= 1; i--) a[2][i] -= a[2][1] * a[1][i];
    for (int i = 2; i <= m; i++) {
        a[i][i + 1] /= a[i][i], a[i][0] /= a[i][i];
        a[i][i] = 1;
        a[i + 1][0] -= a[i + 1][i] * a[i][0];
        for (int j = i + 2; j >= i; j--) a[i + 1][j] -= a[i + 1][i] * a[i][j];
    }
    for (int i = m - 1; i; i--)
        a[i][0] -= a[i][i + 1] * a[i + 1][0];
}

int main() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    if(m == 1) { printf("%.3f\n", (double)(n - x) * 2); return 0; }
    for (int i = n - 1; i >= x; i--) {
        a[1][1] = 2.0 / 3, a[1][2] = -1.0 / 3, a[1][0] = f[i + 1][1] / 3.0 + 1;
        for (int j = 2; j < m; j++)
            a[j][j - 1] = a[j][j + 1] = -1.0 / 4, a[j][0] = f[i + 1][j] / 4.0 + 1, a[j][j] = 3.0 / 4;
        a[m][m - 1] = -1.0 / 3, a[m][m] = 2.0 / 3, a[m][0] = f[i + 1][m] / 3 + 1;
        gauss();
        for (int j = 1; j <= m; j++) f[i][j] = a[j][0];
    }
    printf("%.4lf\n", f[x][y]);
}