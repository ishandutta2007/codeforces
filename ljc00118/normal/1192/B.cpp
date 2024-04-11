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
 
const int N = 2e5 + 5, INF = 2e9;
 
multiset <ll> one[N], two[N];
vector <int> adj[N];
ll sum[N], lmx[N], rmx[N], mx[N], val[N], ans, lastans, w;
int fa[N], ch[N][2];
int n, q;
 
inline int isroot(int u) { return ch[fa[u]][0] != u && ch[fa[u]][1] != u; }
inline int get(int u) { return ch[fa[u]][1] == u; }
 
inline ll fir(multiset <ll> &t) { return t.size() > 0 ? *t.rbegin() : -INF; }
inline ll sec(multiset <ll> &t) { return t.size() > 1 ? *++t.rbegin() : -INF; }
 
void update(int u) {
    sum[u] = sum[ch[u][0]] + sum[ch[u][1]] + val[u];
    ll oth = max(0ll, fir(one[u]));
    ll up = max(oth, rmx[ch[u][0]]) + val[u];
    ll down = max(oth, lmx[ch[u][1]]) + val[u];
    lmx[u] = max(lmx[ch[u][0]], sum[ch[u][0]] + down);
    rmx[u] = max(rmx[ch[u][1]], sum[ch[u][1]] + up);
    mx[u] = max(lmx[ch[u][1]] + up, rmx[ch[u][0]] + down);
    mx[u] = max(mx[u], max(mx[ch[u][0]], mx[ch[u][1]]));
    mx[u] = max(mx[u], fir(two[u]));
    mx[u] = max(mx[u], oth + max(0ll, sec(one[u])) + val[u]);
}
 
void rotate(int u) {
    int old = fa[u], oldd = fa[old], k = get(u);
    if(!isroot(old)) { ch[oldd][get(old)] = u; } fa[u] = oldd;
    ch[old][k] = ch[u][k ^ 1]; fa[ch[u][k ^ 1]] = old;
    ch[u][k ^ 1] = old; fa[old] = u;
    update(old); update(u);
}
 
void ins(int u, int v) {
    one[u].insert(lmx[v]);
    two[u].insert(mx[v]);
}
 
void del(int u, int v) {
    one[u].erase(one[u].find(lmx[v]));
    two[u].erase(two[u].find(mx[v]));
}
 
void splay(int u) {
    for(; !isroot(u); rotate(u)) if(!isroot(fa[u])) rotate(get(u) == get(fa[u]) ? fa[u] : u);
}
 
void access(int u) {
    for(register int i = 0; u; i = u, u = fa[u]) {
        splay(u);
        if(i) del(u, i);
        if(ch[u][1]) ins(u, ch[u][1]);
        ch[u][1] = i;
        update(u);
    }
}
 
void dfs1(int u) {
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa[u]) continue;
        fa[v] = u; dfs1(v);
        ins(u, v);
    }
    update(u);
}
 
void change(int u, ll x) {
    access(u); splay(u);
    val[u] = x;
    update(u);
    ans = mx[u];
}
 
int main() {
    read(n); read(q); read(w);
    for(register int i = 1; i < n; i++) {
        int u, v; ll val;
        read(u); read(v); read(val);
        adj[u].push_back(i + n);
        adj[i + n].push_back(u);
        adj[v].push_back(i + n);
        adj[i + n].push_back(v);
        ::val[i + n] = val;
    }
    dfs1(1); ans = mx[1];
    while(q--) {
        int u; ll val;
        read(u); read(val);
        u = (u + lastans) % (n - 1) + 1;
        val = (val + lastans) % w;
        change(u + n, val);
        print(lastans = ans, '\n');
    }
    return 0;
}