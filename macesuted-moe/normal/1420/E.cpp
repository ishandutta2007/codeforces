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

#define maxn 85
#define maxS 4005

int rec[maxn], tail;
int a[maxn], f[maxn][maxn][maxS];

int main() {
    int n = read<int>();
    for (int i = 1; i <= n; i++)
        if (a[i] = read<int>()) rec[++tail] = i;
    memset(f, 0xcf, sizeof(f));
    f[0][0][0] = 0;
    for (register int i = 0, lim; i < n; i++)
        for (register int j = 0, lim = min(i, tail - 1); j <= lim; j++)
            for (register int k = 0; k < maxS; k++)
                if (~f[i][j][k])
                    for (register int l = i + 1; l <= n; l++)
                        f[l][j + 1][k + abs(l - rec[j + 1])] = max(f[l][j + 1][k + abs(l - rec[j + 1])], f[i][j][k] + (i - j) * (l - i - 1));
    int len = n * (n - 1) / 2;
    for (register int t = 0, ans = 0; t <= len; t++) {
        for (register int i = 1; i <= n; i++) ans = max(ans, f[i][tail][t] + (i - tail) * (n - i));
        printf("%d ", ans);
    }
    puts("");
    return 0;
}