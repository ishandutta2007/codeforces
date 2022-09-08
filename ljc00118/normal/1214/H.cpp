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

const int N = 2e5 + 5;

vector <int> adj[N];
int ans[N], dep[N], maxdep[N], fa[N], id[N], rk[N];
int n, k, z1, z2, len;

void dfsk2(int u, int fa) {
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        dep[v] = dep[u] + 1; dfsk2(v, u);
    }
}

void dfs1(int u, int fa) {
    maxdep[u] = dep[u];
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        dep[v] = dep[u] + 1; ::fa[v] = u; dfs1(v, u);
        maxdep[u] = max(maxdep[u], maxdep[v]);
    }
}

multiset <int> t[N];
multiset <int> :: iterator it;
void dfs2(int u, int fa, int val) {
    if(val) t[u].insert(val);
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        t[u].insert(maxdep[v] - dep[u]);
    }
    if(t[u].size() >= 3) {
        // fprintf(stderr, "u = %d\n", u);
        it = t[u].end(); --it; --it;
        int tmp = *it; --it;
        if(tmp + *it + 1 >= k) {
            printf("No\n");
            exit(0);
        }
    }
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        t[u].erase(t[u].find(maxdep[v] - dep[u]));
        if(t[u].size()) dfs2(v, u, *--t[u].end() + 1);
        else dfs2(v, u, 1);
        t[u].insert(maxdep[v] - dep[u]);
    }
}

void dfs3(int u, int fa, int cur, int d) {
    ans[u] = cur; cur += d;
    if(cur == 0) cur = k;
    if(cur == k + 1) cur = 1;
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        dfs3(v, u, cur, d);
    }
}

int main() {
    read(n); read(k);
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(k == 2) {
        dfsk2(1, 0);
        printf("Yes\n");
        for(register int i = 1; i <= n; i++) print((dep[i] & 1) ? 1 : 2, i == n ? '\n' : ' ');
        return 0;
    }
    dfs1(1, 0); dfs2(1, 0, 0);
    for(register int i = 1; i <= n; i++) if(dep[i] == maxdep[1]) { z1 = i; break; }
    fa[z1] = dep[z1] = 0; dfs1(z1, 0);
    for(register int i = 1; i <= n; i++) if(dep[i] == maxdep[z1]) { z2 = i; break; }
    int tmp = z2, qwq = 0;
    while(tmp) {
        // fprintf(stderr, "tmp = %d\n", tmp);
        ++qwq; if(qwq == k + 1) qwq = 1;
        rk[tmp] = ++len; id[len] = tmp; ans[tmp] = qwq;
        tmp = fa[tmp];
    }
    for(register int _ = 1; _ <= len; _++) {
        int u = id[_];
        for(register int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            if(rk[v]) continue;
            dep[v] = 1; dfs1(v, u);
            if(rk[u] + maxdep[v] >= k) {
                int cur = ans[u] + 1;
                if(cur == k + 1) cur = 1;
                dfs3(v, u, cur, 1);
            } else {
                int cur = ans[u] - 1;
                if(cur == 0) cur = k;
                dfs3(v, u, cur, -1);
            }
        }
    }
    printf("Yes\n");
    for(register int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    return 0;
}