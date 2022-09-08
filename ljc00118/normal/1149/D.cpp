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

const int N = 75, M = 205;

struct edge_t { int u, v, next, val; } G[M << 1];

queue <pii> q;
ll dis[1 << 17][N], ans[N];
bool used[1 << 17][N];
int head[N], f[N], cnt[N], pre[N];
int n, m, a, b, tot;

inline void addedge(int u, int v, int val) {
    G[++tot] = (edge_t) {u, v, head[u], val}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], val}, head[v] = tot;
}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    memset(dis, 0x7f, sizeof(dis)); memset(ans, 0x7f, sizeof(ans));
    read(n); read(m); read(a); read(b);
    for(register int i = 1; i <= n; i++) f[i] = i;
    for(register int i = 1; i <= m; i++) {
        int u, v, val;
        read(u); read(v); read(val);
        if(val == a) f[find(u)] = find(v);
        addedge(u, v, val);
    }
    for(register int i = 1; i <= n; i++) ++cnt[find(i)];
    tot = 0;
    for(register int i = 1; i <= n; i++) if(find(i) == i && cnt[i] >= 4) pre[i] = ++tot;
    if(pre[find(1)]) dis[1 << (pre[find(1)] - 1)][1] = 0, used[1 << (pre[find(1)] - 1)][1] = 1, q.push(make_pair(1 << (pre[find(1)] - 1), 1));
    else dis[0][1] = 0, used[0][1] = 1, q.push(make_pair(0, 1));
    while(!q.empty()) {
        pii t = q.front(); q.pop();
        int zt = t.first, u = t.second;
        used[zt][u] = 0;
        for(register int i = head[u]; i; i = G[i].next) {
            int v = G[i].v;
            if(G[i].val == a) {
                if(dis[zt][v] > dis[zt][u] + a) {
                    dis[zt][v] = dis[zt][u] + a;
                    if(!used[zt][v]) {
                        used[zt][v] = 1;
                        q.push(make_pair(zt, v));
                    }
                }
            }
            if(G[i].val == b) {
                if(find(u) == find(v)) continue;
                if(pre[find(v)] && ((1 << (pre[find(v)] - 1)) & zt)) continue;
                int go = zt;
                if(pre[find(v)]) go ^= 1 << (pre[find(v)] - 1);
                if(dis[go][v] > dis[zt][u] + b) {
                    dis[go][v] = dis[zt][u] + b;
                    if(!used[go][v]) {
                        used[go][v] = 1;
                        q.push(make_pair(go, v));
                    }
                }
            }
        }
    }
    for(register int i = 0; i < (1 << tot); i++) {
        for(register int j = 1; j <= n; j++) {
            ans[j] = min(ans[j], dis[i][j]);
        }
    }
    for(register int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    return 0;
}