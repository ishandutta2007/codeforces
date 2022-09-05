#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 1005;

double a[N][N], f[N], g[N], p[N], ans[N];
int used[N], vis[N];
int n;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; read(x);
            a[i][j] = (double)x / 100;
        }
    }
    for (int i = 1; i <= n; i++) f[i] = p[i] = 1;
    ans[n] = 0; vis[n] = 1;
    for (int i = 1; i <= n; i++) {
        int id = 0;
        for (int j = 1; j <= n; j++) {
            if (vis[j] && !used[j]) {
                if (!id || ans[j] < ans[id]) id = j;
            }
        }
        if (!id) break;
        used[id] = 1;
        if (id == 1) {
            printf("%.10lf\n", ans[1]);
            return 0;
        }
        for (int j = 1; j <= n; j++) {
            if (used[j] || a[j][id] < 1e-6) continue;
            double nowp = p[j] * a[j][id];
            p[j] *= (1 - a[j][id]);
            f[j] += ans[id] * nowp; g[j] += nowp;
            if (!vis[j]) vis[j] = 1, ans[j] = f[j] / g[j];
            else ans[j] = min(ans[j], f[j] / g[j]);
        }
    }
    return 0;
}