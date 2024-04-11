#include <bits/stdc++.h>
using namespace std;

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

const int maxn = 2e3 + 5;

double f[maxn][maxn];

int main() {
    int n, t;
    double p;
    scanf("%d%lf%d", &n, &p, &t);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= t; j++)
            f[i][j] = (1 - p) * f[i][j - 1] + p * (f[i - 1][j - 1] + 1);
    printf("%.6lf\n", f[n][t]);
    return 0;
}