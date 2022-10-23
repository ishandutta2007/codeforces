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

const int md = 1e9 + 7;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 5e5 + 5;

map <ll, int> id;
vector <pii> vec[N];
vector <int> adj[N];
ll a[N];
int f[N * 2], siz[N * 2], st[N], pw[N];
int n, m, k, top, tot, ans;

int find(int x) {
    while (f[x] != x) x = f[x];
    return x;
}

int merge(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return 0;
    if (siz[u] > siz[v]) swap(u, v);
    st[++top] = u; f[u] = v; siz[v] += siz[u];
    return 1;
}

void pop() {
    int u = st[top--];
    siz[f[u]] -= siz[u]; f[u] = u;
}

int main() {
    read(n); read(m); read(k);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = add(pw[i - 1], pw[i - 1]);
    for (int i = 1; i <= n * 2; i++) f[i] = i, siz[i] = 1;
    int cnt = n * 2;
    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            if (a[u] == a[v]) {
                cnt -= merge(u, v + n);
                cnt -= merge(v, u + n);
            } else {
                if (!id.count(a[u] ^ a[v])) {
                    id[a[u] ^ a[v]] = ++tot;
                }
                vec[id[a[u] ^ a[v]]].emplace_back(u, v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (find(i) == find(i + n)) {
            print(0, '\n');
            return 0;
        }
    }
    ans = mul(pw[cnt / 2], ((1ll << k) - tot) % md);
    int pre = top;
    for (int i = 1; i <= tot; i++) {
        int ncnt = cnt;
        for (auto j : vec[i]) {
            ncnt -= merge(j.first, j.second);
            ncnt -= merge(j.first + n, j.second + n);
        }
        int cando = 1;
        for (auto j : vec[i]) {
            if (find(j.first) == find(j.first + n)) {
                cando = 0;
                break;
            }
        }
        if (cando) ans = add(ans, pw[ncnt / 2]);
        while (top > pre) pop();
    }
    print(ans, '\n');
    return 0;
}