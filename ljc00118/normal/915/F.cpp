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

const int N = 1e6 + 5;

struct ele {
    int val, id;
    bool operator < (const ele A) const { return val < A.val; }
} a[N];

vector <int> adj[N];
int fa[N], siz[N], vis[N];
int n; ll ans;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

ll solve() {
    memset(vis, 0, sizeof(vis));
    ll sum = 0;
    for(register int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
    for(register int i = 1; i <= n; i++) {
        int u = a[i].id; vis[u] = 1;
        for(register unsigned j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if(!vis[v]) continue;
            sum += 1ll * siz[find(u)] * siz[find(v)] * a[i].val;
            siz[find(u)] += siz[find(v)];
            fa[find(v)] = find(u);
        }
    }
    return sum;
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i].val), a[i].id = i;
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sort(a + 1, a + n + 1);
    ans = solve();
    reverse(a + 1, a + n + 1);
    cout << ans - solve() << endl;
    return 0;
}