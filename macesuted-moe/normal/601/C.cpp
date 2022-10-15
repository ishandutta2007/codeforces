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

#define maxn 105
#define maxm 1005

double f[maxn][maxn * maxm], pre[maxn * maxm];
int c[maxn];

int main() {
    int n = read<int>(), m = read<int>();
    double dou = 1.0 / (m - 1);
    for (register int i = 1; i <= n; i++) c[i] = read<int>();
    f[0][0] = pre[0] = 1;
    for (register int i = 1; i <= n; i++) {
        for (register int j = 1, lim = i * m; j <= lim; j++) {
            int scoreL = max(i - 1, j - m), scoreR = min(i * m - m, j - 1), self = j - c[i];
            i == 1 ? f[i][j] = dou * pre[scoreR] : f[i][j] = dou * (pre[scoreR] - pre[scoreL - 1]);
            if (scoreL <= self && self <= scoreR) f[i][j] -= dou * f[i - 1][self];
        }
        for (register int j = 1, lim = i * m; j <= lim; j++) pre[j] = pre[j - 1] + f[i][j];
    }
    int sum = 0;
    for (register int i = 1; i <= n; i++) sum += c[i];
    double answer = 0;
    for (register int i = n; i < sum; i++) answer += f[n][i];
    printf("%.16lf\n", answer * (m - 1) + 1);
    return 0;
}