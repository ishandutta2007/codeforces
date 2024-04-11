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

const int N = 5678, INF = 0x7f7f7f7f, MAXTIME = 100;

struct edge_t { int u, v, next, cap, flow, cost; };

vector <edge_t> G; queue <int> q;
int head[N], dis[N], fr[N], maxflow[N], used[N], x[N], y[N];
int n, m, k, c, d, tot = 1, s, t, ans1, ans2;

inline void addedge(int u, int v, int cap, int cost) {
    // fprintf(stderr, "addedge %d %d %d %d\n", u, v, cap, cost);
    G.resize(tot + 3);
    G[++tot] = (edge_t) {u, v, head[u], cap, 0, cost}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], 0, 0, -cost}, head[v] = tot;
}

bool spfa() {
    memset(dis, 0x7f, sizeof(dis));
    memset(used, 0, sizeof(used));
    dis[s] = 0; used[s] = 1; maxflow[s] = INF; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop(); used[u] = 0;
        for(register int i = head[u]; i; i = G[i].next) {
            int v = G[i].v;
            if(G[i].cap > G[i].flow && dis[v] > dis[u] + G[i].cost) {
                dis[v] = dis[u] + G[i].cost; fr[v] = i;
                maxflow[v] = min(maxflow[u], G[i].cap - G[i].flow);
                if(!used[v]) { used[v] = 1; q.push(v); }
            }
        }
    }
    return dis[t] != INF;
}

void solve() {
    int tmp = t;
    while(tmp != s) {
        int i = fr[tmp];
        G[i].flow += maxflow[t];
        G[i ^ 1].flow -= maxflow[t];
        tmp = G[i].u;
    }
    ans1 += maxflow[t];
    ans2 += maxflow[t] * dis[t];
}

void mcmf() { while(spfa()) solve(); }

inline int calc(int x, int y) { return x * n + y; }

int main() {
    G.resize(2);
    read(n); read(m); read(k); read(c); read(d);
    s = 0; t = (MAXTIME + 1) * n + 1;
    for(register int i = 1; i <= k; i++) {
        int a; read(a);
        addedge(s, calc(0, a), 1, 0);
    }
    for(register int i = 1; i <= m; i++) read(x[i]), read(y[i]);
    for(register int i = 0; i <= MAXTIME; i++) addedge(calc(i, 1), t, INF, i * c);
    for(register int i = 0; i < MAXTIME; i++) {
        for(register int j = 1; j <= n; j++) {
            addedge(calc(i, j), calc(i + 1, j), INF, 0);
        }
    }
    for(register int i = 1; i <= m; i++) {
        for(register int j = 0; j < MAXTIME; j++) {
            for(register int cnt = 1; cnt <= n; cnt++) {
                addedge(calc(j, x[i]), calc(j + 1, y[i]), 1, d * (cnt * 2 - 1));
                addedge(calc(j, y[i]), calc(j + 1, x[i]), 1, d * (cnt * 2 - 1));
            }
        }
    }
    mcmf(); print(ans2, '\n');
    return 0;
}