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

inline void upd(int &x, int y) { x = max(x, y); }

const int N = 2005, INF = 1044266559;

int f[N][N], val[N][N][12];
int a[N], c[N], w[N * 2], maxn[N];
int n, m, ans;

int main() {
    memset(f, -0x3f, sizeof(f));
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) read(c[i]);
    for (int i = 1; i <= n + m; i++) read(w[i]);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 11; k++) {
                val[i][j][k] = val[i][j][k - 1] + w[i + k - 1] * (j >> (k - 1));
            }
        }
    }
    for (int i = 1; i <= m; i++) f[i][0] = 0;
    for (int _ = n; _ >= 1; _--) {
        for (int i = a[_], len = 0; i >= max(1, a[_] - 11); i--, len++) {
            for (int j = n; j >= 0; j--) {
                if (f[i][j] == -INF) continue;
                upd(f[a[_]][(j >> len) + 1], f[i][j] + val[i][j][len] - c[_]);
            }
        }
        for (int i = 1; i < a[_] - 11; i++) upd(f[a[_]][1], maxn[i] - c[_]);
        for (int i = 0; i <= n; i++) {
            if (f[a[_]][i] == -INF) continue;
            upd(maxn[a[_]], f[a[_]][i] + val[a[_]][i][11]);
        }
    }
    for (int i = 0; i <= n; i++) upd(ans, maxn[i]);
    print(ans, '\n');
    return 0;
}