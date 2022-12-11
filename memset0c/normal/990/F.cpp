// =================================
//   author: memset0
//   date: 2018.12.04 23:02:24
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
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

const int N = 2e5 + 10;
int n, m, u, v, fu, fv;
int s[N], f[N], flow[N];
int tot = 2, hed[N], nxt[N << 1], to[N << 1], val[N << 1], id[N << 1];

int find(int x) { return f[x] = f[x] == x ? x : find(f[x]); }

void dfs(int u, int father = 0) {
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v != father) {
            dfs(v, u);
            // printf("%d -> %d : %d %d\n", u, v, s[u], s[v]);
            flow[id[i]] = val[i] * s[v];
            s[u] += s[v], s[v] = 0;
        }
}


void main() {
    read(n);
    for (int i = 1; i <= n; i++)
        read(s[i]), f[i] = i;
    read(m);
    for (int i = 1; i <= m; i++) {
        read(u), read(v);
        fu = find(u), fv = find(v);
        if (fu == fv) continue;
        nxt[tot] = hed[u], to[tot] = v, id[tot] = i, val[tot] =  1, hed[u] = tot++;
        nxt[tot] = hed[v], to[tot] = u, id[tot] = i, val[tot] = -1, hed[v] = tot++;
        f[fu] = fv;
    }
    dfs(1);
    // for (int i = 1; i <= n; i++)
    //     print(s[i], " \n"[i == n]);
    if (s[1] == 0) {
        puts("Possible");
        for (int i = 1; i <= m; i++)
            print(flow[i], '\n');
    } else {
        puts("Impossible");
    }
}

} signed main() { return ringo::main(), 0; }