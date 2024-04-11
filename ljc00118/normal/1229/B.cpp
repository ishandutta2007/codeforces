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

const int N = 1e5 + 5, md = 1e9 + 7;

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

struct edge_t { int u, v, next; } G[N << 1];

ll d[N][50], cnt[N][50], w[N], ans;
int sum[N], head[N], top[N];
int n, tot;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void add(int u, ll x, ll y) {
    if(top[u] && d[u][top[u]] == x) cnt[u][top[u]] += y;
    else d[u][++top[u]] = x, cnt[u][top[u]] = y;
}

void dfs1(int u, int fa) {
    for(register int i = 1; i <= top[fa]; i++) add(u, gcd(d[fa][i], w[u]), cnt[fa][i]);
    add(u, w[u], 1);
    for(register int i = 1; i <= top[u]; i++) sum[u] = add(sum[u], mul(d[u][i] % md, cnt[u][i]));
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        dfs1(v, u);
    }
    ans = add(ans, sum[u]);
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(w[i]);
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        addedge(u, v);
    }
    dfs1(1, 0);
    print(ans, '\n');
    return 0;
}