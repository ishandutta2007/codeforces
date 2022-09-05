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

const int N = 2e5 + 5;

vector <int> adj[N];
int ans[N], p[N], t[N];
int T, n, rt, cando;

void dfs1(int u) {
    for (auto v : adj[u]) {
        if (p[v] < p[u]) {
            cando = 0;
            return;
        }
        ans[v] = p[v] - p[u]; dfs1(v);
    }
}

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) adj[i].clear(), ans[i] = 0;
        for (int i = 1; i <= n; i++) {
            int x; read(x);
            if (x == i) rt = i;
            else adj[x].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            int x; read(x);
            p[x] = i;
        }
        cando = 1; dfs1(rt);
        if (!cando) {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}