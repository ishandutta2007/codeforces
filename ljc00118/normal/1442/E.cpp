#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 2e5 + 5, INF = 2000000;

vector <int> adj[N];
int col[N], f[N][2];
int T, n, ans, mid;

void dfs1(int u, int fa) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        dfs1(v, u);
    }
    f[u][0] = f[u][1] = 0;
    int mx[2] = {-INF, -INF};
    if (col[u] == 1) f[u][1] = -INF, mx[1] = INF;
    if (col[u] == 2) f[u][0] = -INF, mx[0] = INF;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        for (int c = 0; c <= 1; c++) {
            if (col[u] == 1 && c == 1) continue;
            if (col[u] == 2 && c == 0) continue;
            int now = INF;
            for (int j = 0; j <= 1; j++) {
                if (f[v][j] == -INF) continue;
                now = min(now, f[u][c] + f[v][j] + (c != j));
            }
            mx[c] = max(mx[c], now);
        }
        for (int c = 0; c <= 1; c++) {
            if (col[u] == 1 && c == 1) continue;
            if (col[u] == 2 && c == 0) continue;
            int now = INF;
            for (int j = 0; j <= 1; j++) {
                if (f[v][j] == -INF) continue;
                now = min(now, f[v][j] + (c != j));
            }
            f[u][c] = max(f[u][c], now);
        }
    }
    ans = max(ans, min(mx[0], mx[1]));
}

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(col[i]), adj[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            read(u); read(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans = 0;
        dfs1(1, 0);
        print((ans + 1) / 2 + 1, '\n');
    }
    return 0;
}