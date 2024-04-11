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

const int N = 45;

vector <int> adj[N];
queue <int> q;
ll g[N], ans;
int vis[N], val[1 << 20];
int n, m, base, cnt, big, cnt2, flag = 1;

void dfs1(int u, ll now) {
    if(u == n + 1) {
        ++val[now & ((1 << base) - 1)];
        return;
    }
    dfs1(u + 1, now);
    if(((1ll << (u - 1)) & now) == 0) dfs1(u + 1, now | g[u]);
}

void dfs2(int u, ll now, ll c) {
    if(u == base + 1) {
        ans -= 2 * val[c ^ ((1 << base) - 1)];
        return;
    }
    dfs2(u + 1, now, c);
    if(((1 << (u - 1)) & now) == 0) dfs2(u + 1, now | g[u], c | (1 << (u - 1)));
}

void fwt(int *a) {
    for(register int mid = 1; mid < (1 << base); mid <<= 1) {
        for(register int i = 0; i < (1 << base); i += (mid << 1)) {
            for(register int j = 0; j < mid; j++) {
                a[i + j + mid] += a[i + j];
            }
        }
    }
}

int main() {
    read(n); read(m); base = n >> 1; ans = 1ll << n;
    if(!m) { print(0, '\n'); return 0; }
    for(register int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        g[u] |= 1ll << (v - 1);
        g[v] |= 1ll << (u - 1);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(register int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ++cnt; big = 1;
            vis[i] = 1; q.push(i);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(register int j = 0; j < (int)adj[u].size(); j++) {
                    int v = adj[u][j];
                    if(!vis[v]) {
                        vis[v] = 3 - vis[u]; ++big;
                        q.push(v);
                    } else if(vis[v] != 3 - vis[u]) flag = 0;
                }
            }
            if(big == 1) ++cnt2;
        }
    }
    ans -= 1ll << cnt; ans += 1ll << (cnt2 + 1);
    if(flag) ans += 1ll << cnt;
    dfs1(base + 1, 0); fwt(val); dfs2(1, 0, 0);
    print(ans, '\n');
    return 0;
}