#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int P = 998244353;
long long a[2], f[2000001][2][2];
int n, m, c[1000001];
char str[1000011];

inline void calc() {
    long long w[2];
    memset(w, 0, sizeof(w));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            w[i] += a[j] * f[1][j][i],
            w[i] %= P;
    memcpy(a, w, sizeof(a));
}

inline void update(int k) {
    memset(f[k], 0, sizeof(f[k]));
    for (int i = 0; i < 2; i++)
        for (int x = 0; x < 2; x++)
            if (f[k + k][i][x])
                for (int j = 0; j < 2; j++)
                    f[k][i][j] += f[k + k][i][x] * f[k + k + 1][x][j],
                    f[k][i][j] %= P;
}

inline void insert(int k, int Left, int Right, int x, int y) {
    if (Left == Right) {
        int L = max(y - 9, 0), R = min(y, 9);
        f[k][1][0] = 1;
        if (y >= 10 && y < 19)
            f[k][0][1] = R - L + 1;
        else
            f[k][0][1] = 0;
        f[k][0][0] = 0;
        f[k][1][1] = y % 10 + 1;
        return;
    }
    int i = (Left + Right) >> 1;
    if (x <= i)
        insert(k + k, Left, i, x, y);
    else
        insert(k + k + 1, i + 1, Right, x, y);
    update(k);
}

int main() {
    scanf("%d%d%s", &n, &m, str + 1);
    for (int i = 1; i <= n; i++)
        c[i] = str[i] - '0';
    for (int i = 1; i <= n; i++)
        insert(1, 1, n, i, c[i - 1] * 10 + c[i]);
    for (; m--; ) {
        int x, y;
        scanf("%d%d", &x, &y);
        c[x] = y;
        insert(1, 1, n, x, c[x - 1] * 10 + c[x]);
        if (x != n)
            insert(1, 1, n, x + 1, c[x] * 10 + c[x + 1]);
        a[0] = 0; a[1] = 1;
        calc();
        printf("%d\n", a[1]);
    }
}