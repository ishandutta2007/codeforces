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

const int N = 1e5 + 5;

vector <int> adj[N];
ll f[N][2], a[N][2];
int T, n;

void dfs1(int u, int fa) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        dfs1(v, u);
        for (int j = 0; j <= 1; j++) {
            f[u][j] += max(f[v][0] + abs(a[u][j] - a[v][0]), f[v][1] + abs(a[u][j] - a[v][1]));
        }
    }
}

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) adj[i].clear(), f[i][0] = f[i][1] = 0;
        for (int i = 1; i <= n; i++) read(a[i][0]), read(a[i][1]);
        for (int i = 1; i < n; i++) {
            int u, v;
            read(u); read(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(1, 0);
        print(max(f[1][0], f[1][1]), '\n');
    }
    return 0;
}