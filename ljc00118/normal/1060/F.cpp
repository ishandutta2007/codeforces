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

const int N = 55;

vector <int> adj[N];
long double f[N][N], C[N][N], fac[N], tmp[N], g[N];
int siz[N];
int n;

void dfs1(int u, int fa) {
    siz[u] = 1; f[u][0] = 1;
    for (auto v : adj[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        for (int i = 0; i < siz[u] + siz[v]; i++) g[i] = 0;
        for (int i = 0; i <= siz[v]; i++) {
            long double now = 0;
            for (int j = 1; j <= siz[v]; j++) {
                if (j > i) now += f[v][j - 1] * 0.5;
                else now += f[v][i - 1];
            }
            for (int j = 0; j < siz[u]; j++) g[i + j] += now * f[u][j] * C[i + j][i] * C[siz[u] + siz[v] - 1 - i - j][siz[v] - i];
        }
        siz[u] += siz[v];
        for (int i = 0; i < siz[u]; i++) f[u][i] = g[i];
    }
}

int main() {
    read(n);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        dfs1(i, 0);
        printf("%.10lf\n", (double)(f[i][0] / fac[n - 1]));
    }
    return 0;
}