// =================================
//   author: memset0
//   date: 2018.12.07 11:12:38
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}

template < class T >
inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
    print(x), putchar(c);
}

#define pb push_back

const int N = 2e5 + 10;
int n, u, v, root, fsize;
int c[N], siz[N], maxp[N], ans[N], bkt[1 << 20];
bool vis[N];
std::vector < int > G[N];

void get_root(int u, int father) {
    siz[u] = 1, maxp[u] = 0;
    for (auto v : G[u]) if (!vis[v] && v != father)
        get_root(v, u), siz[u] += siz[v], maxp[u] = std::max(maxp[u], siz[v]);
    maxp[u] = std::max(maxp[u], fsize - siz[u]);
    if (maxp[u] < maxp[root]) root = u;
}

void get(int u, int father, int s, int flag) {
    s ^= 1 << c[u], bkt[s] += flag;
    // printf("get %d %d %d\n", s, flag, bkt[s]);
    for (auto v : G[u]) if (!vis[v] && v != father)
        get(v, u, s, flag);
}

int calc(int u, int father, int s) {
    s ^= 1 << c[u]; int sum = bkt[s];
    for (int i = 0; i < 20; i++) sum += bkt[s ^ (1 << i)];
    for (auto v : G[u]) if (!vis[v] && v != father)
        sum += calc(v, u, s);
    ans[u] += sum;
    // printf("calc %d %d >> %d\n", u, s, sum);
    return sum;
}

void solve(int u) {
    // printf("==== solve %d ====\n", u);
    int sum = 0; vis[u] = 1, ++bkt[1 << c[u]];
    for (auto v : G[u]) if (!vis[v]) get(v, u, 1 << c[u], 1);
    for (auto v : G[u]) if (!vis[v]) {
        get(v, u, 1 << c[u], -1);
        // printf("--- %d ---\n", v);
        sum += calc(v, u, 0);
        get(v, u, 1 << c[u], 1);
        // printf("%d >> ", sum);
        // for (int i = 1; i <= n; i++) print(ans[i], " \n"[i == n]);
    }
    sum += bkt[0];
    for (int i = 0; i <= 19; i++) sum += bkt[(1 << i)];
    // printf("sum >> %d\n", sum);
    sum = (sum + 1) >> 1;
    ans[u] += sum, --bkt[1 << c[u]];
    for (auto v : G[u]) if (!vis[v]) get(v, u, 1 << c[u], -1);
    // for (int i = 1; i <= n; i++) print(ans[i], " \n"[i == n]);
    for (auto v : G[u]) if (!vis[v])
        root = 0, maxp[root] = fsize = siz[v], get_root(v, u), solve(root);
}

void main() {
    read(n);
    for (int i = 1; i < n; i++)
        read(u), read(v), G[u].pb(v), G[v].pb(u);
    for (int i = 1; i <= n; i++) {
        while (c[i] = getchar(), !islower(c[i]));
        c[i] -= 'a';
    }
    root = 0, maxp[root] = fsize = n, get_root(1, 0), solve(root);
    for (int i = 1; i <= n; i++) print(ans[i], " \n"[i == n]);
}

} signed main() { return ringo::main(), 0; }