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

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() { *this = hash_map_t(mod); }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 1005;

struct edge_t { int u, v, next; } G[N << 1];

struct ele {
    int u, v, val;
    ele () {}
    ele (int a, int b, int c) : u(a), v(b), val(c) {}
};

vector <ele> ans;
int g[N][N];
int deg[N], head[N], vis[N];
int n, tot, rt;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

void dfs1(int u, int fa) {
    vis[u] = 1;
    if(deg[u] == 2) {
        int v = -1;
        for(register int i = 1; i <= n; i++) {
            if(g[u][i] && i != fa) {
                v = i;
                break;
            }
        }
        if(g[u][fa] != g[u][v]) {
            printf("NO\n");
            exit(0);
        }
        g[fa][v] = g[v][fa] = g[u][v];
        g[u][fa] = g[fa][u] = 0;
        g[u][v] = g[v][u] = 0;
        dfs1(v, fa);
    } else {
        for(register int i = 1; i <= n; i++) {
            if(g[u][i] && i != fa && !vis[i]) {
                dfs1(i, u);
            }
        }
    }
}

int dfs2(int u, int fa) {
    if(deg[u] == 1) return u;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        return dfs2(v, u);
    }
}

int main() {
    read(n);
    for(register int i = 1; i < n; i++) {
        int u, v, val;
        read(u); read(v); read(val); val >>= 1;
        g[u][v] = g[v][u] = val; ++deg[u]; ++deg[v];
    }
    for(register int i = 1; i <= n; i++) if(deg[i] == 1) { rt = i; break; }
    dfs1(rt, 0);
    memset(deg, 0, sizeof(deg));
    for(register int i = 1; i <= n; i++) {
        for(register int j = i + 1; j <= n; j++) {
            if(g[i][j]) {
                addedge(i, j);
                ++deg[i]; ++deg[j];
            }
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = i + 1; j <= n; j++) {
            if(g[i][j]) {
                int x = 0, y = 0, _x = 0, _y = 0;
                if(deg[i] == 1) x = y = i;
                else {
                    for(register int t = head[i]; t; t = G[t].next) {
                        int v = G[t].v;
                        if(v == j) continue;
                        int point_t = dfs2(v, i);
                        if(!x) x = point_t;
                        else { y = point_t; break; }
                    }
                }
                if(deg[j] == 1) _x = _y = j;
                else {
                    for(register int t = head[j]; t; t = G[t].next) {
                        int v = G[t].v;
                        if(v == i) continue;
                        int point_t = dfs2(v, j);
                        if(!_x) _x = point_t;
                        else { _y = point_t; break; }
                    }
                }
                ans.push_back(ele(x, _x, g[i][j]));
                ans.push_back(ele(y, _y, g[i][j]));
                if(x != y) ans.push_back(ele(x, y, -g[i][j]));
                if(_x != _y) ans.push_back(ele(_x, _y, -g[i][j]));
            }
        }
    }
    printf("YES\n");
    cout << ans.size() << endl;
    for(register unsigned i = 0; i < ans.size(); i++) {
        print(ans[i].u, ' ');
        print(ans[i].v, ' ');
        print(ans[i].val, '\n');
    }
    return 0;
}