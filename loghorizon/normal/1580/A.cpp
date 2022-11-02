// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 405;

int n, m;

int g[N][N], s[2][N][N], d[N][N], r[N][N];
 
void inline clear() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[1][i][j] = s[0][i][j] = 0, r[i][j] = d[i][j] = 0;
}

int inline get(int i, int j, int k) {
    return d[j - 1][k] - d[i][k];
}

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                scanf("%1d", &g[i][j]), s[g[i][j]][i][j]++;
                if (!g[i][j]) d[i][j]++;
                d[i][j] += d[i - 1][j];
                if (!g[i][j]) r[i][j]++;
                r[i][j] += r[i][j - 1];
                for (int k = 0; k < 2; k++)
                    s[k][i][j] += s[k][i - 1][j] + s[k][i][j - 1] - s[k][i - 1][j - 1];
            }
        int ans = 2e9;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 4; j <= n; j++) {
                int v = 2e9;
                for (int x = 1; x <= m; x++) {
                    if (x - 3 >= 1) {
                        chkMin(v, s[1][i][x - 3] - s[1][j - 1][x - 3] + get(i, j, x - 3) - r[j][x - 3] - r[i][x - 3]);
                        chkMin(ans, v + s[1][j - 1][x - 1] - s[1][i][x - 1] + get(i, j, x) + r[j][x - 1] + r[i][x - 1]);
                    }
                }
            }
        }
        printf("%d\n", ans);
        clear();
    }
    return 0;
}