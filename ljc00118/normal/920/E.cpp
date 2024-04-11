#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
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

const int N = 2e5 + 5;

struct edge_t {
    int u, v, next;
} G[N << 1];

vector <int> adj[N], res;
queue <int> q;
int in[N], vis[N], head[N], used[N], val[N], visit[N];
int n, m, minn, tot, ans, qaq;

inline void addedge(int u, int v) {
    // fprintf(stderr, "addedge %d %d\n", u, v);
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++in[u]; ++in[v];
    }
    minn = 1;
    for(register int i = 2; i <= n; i++) if(in[i] < in[minn]) minn = i;
    vis[minn] = 1;
    for(register unsigned i = 0; i < adj[minn].size(); i++) {
        int v = adj[minn][i];
        vis[v] = 1;
    }
    for(register int i = 1; i <= n; i++) {
        if(vis[i]) {
            val[i] = 1;
            for(register int j = 1; j <= n; j++) visit[j] = 0;
            for(register unsigned j = 0; j < adj[i].size(); j++) {
                int v = adj[i][j];
                visit[v] = 1;
            }
            for(register int v = 1; v <= n; v++) {
                if(visit[v]) continue;
                if(!vis[v]) addedge(i, n + 1);
                else addedge(i, v);
            }
        } else val[n + 1]++;
    }
    for(register int i = 1; i <= n + 1; i++) {
        if(vis[i] && !used[i]) {
            int big = val[i];
            ++ans;
            used[i] = 1;
            q.push(i);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(register int i = head[u]; i; i = G[i].next) {
                    int v = G[i].v;
                    if(!used[v]) {
                        used[v] = 1;
                        big += val[v];
                        q.push(v);
                    }
                }
            }
            res.push_back(big);
        }
    }
    print(ans, '\n');
    sort(res.begin(), res.end());
    for(register int i = 0; i < ans; i++) print(res[i], ' ');
    putchar('\n');
    return 0;
}