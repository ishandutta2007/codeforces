#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 5e5 + 5;

struct edge_t { int u, v, next, val; } G[N << 1];

ll f[N][2];
int head[N];
int T, n, k, tot;

inline void addedge(int u, int v, int val) {
    G[++tot] = (edge_t) {u, v, head[u], val}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], val}, head[v] = tot;
}

vector <ll> t[N];
void dfs1(int u, int fa) {
    t[u].clear();
    ll sum = 0, s = 0;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        dfs1(v, u);
        sum += f[v][0];
        if(f[v][1] + G[i].val > f[v][0]) t[u].push_back(f[v][1] + G[i].val - f[v][0]);
    }
    sort(t[u].begin(), t[u].end()); reverse(t[u].begin(), t[u].end());
    for(register int i = 0; i < min(k, (int)t[u].size()); i++) s += t[u][i];
    if((int)t[u].size() >= k) {
        f[u][0] = s + sum; f[u][1] = s + sum - t[u][k - 1];
    } else {
        f[u][0] = f[u][1] = s + sum;
    }
}

int main() {
    read(T);
    while(T--) {
        read(n); read(k); tot = 0;
        for(register int i = 1; i <= n; i++) head[i] = 0;
        for(register int i = 1; i < n; i++) {
            int u, v, val;
            read(u); read(v); read(val);
            addedge(u, v, val);
        }
        dfs1(1, 0);
        print(f[1][0], '\n');
    }
    return 0;
}