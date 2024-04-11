#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5, M = 22;

int f[M + 1][N], g[M + 1][N], pre[M + 1][N], s[M + 1][N], id[M + 1][N], a[N], pos[M + 1];
int n;

int main() {
    memset(f, 0x7f, sizeof(f));
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), a[i] += (1 << 19);
    int len = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
            id[0][++len] = i;
        }
    }
    pos[0] = len;
    f[0][0] = g[0][0] = (len != n);
    if (len != n) f[0][n - len] = 1, g[0][n - len] = 2;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 1) {
            id[0][++len] = i;
        }
    }
    for (int i = 1; i <= M; i++) {
        len = 0;
        for (int j = 1; j <= n; j++) {
            if (!((a[id[i - 1][j]] >> i) & 1)) {
                id[i][++len] = id[i - 1][j];
            }
        }
        pos[i] = len;
        for (int j = 1; j <= n; j++) {
            if ((a[id[i - 1][j]] >> i) & 1) {
                id[i][++len] = id[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= M; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = s[i][j - 1] + ((a[id[i][j]] >> (i + 1)) & 1);
        }
    }
    for (int i = 0; i <= M - 1; i++) {
        for (int j = 0; j <= n; j++) {
            if (f[i][j] == 0x7f7f7f7f) continue;
            {
                int cnt1 = s[i][n] - s[i][n - j], val = ((s[i][n] - s[i][n - j] != j) || (s[i][n - j] != 0));
                if (f[i][j] + val < f[i + 1][cnt1]) {
                    f[i + 1][cnt1] = f[i][j] + val;
                    g[i + 1][cnt1] = val;
                    pre[i + 1][cnt1] = j;
                }
            }
            {
                int cnt1 = s[i][n] - s[i][n - j], cnt0 = j - cnt1;
                if (f[i][j] + 1 < f[i + 1][cnt0 + n - pos[i + 1]]) {
                    f[i + 1][cnt0 + n - pos[i + 1]] = f[i][j] + 1;
                    g[i + 1][cnt0 + n - pos[i + 1]] = 2;
                    pre[i + 1][cnt0 + n - pos[i + 1]] = j;
                }
            }
        }
    }
    print(f[M][0] - 1, '\n');
    int now = 0;
    for (int i = M; i >= 0; i--) {
        if (g[i][now] == 1 && i != 19) print(1 << i, ' ');
        if (g[i][now] == 2) print(-(1 << i), ' ');
        now = pre[i][now];
    }
    putchar('\n');
    return 0;
}