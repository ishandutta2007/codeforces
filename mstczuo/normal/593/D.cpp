# include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll inf = 1000000000000000001LL;

const int maxn = 200000+10;

struct Edge {
    int u;
    int v;
    ll w;
} e[maxn];

vector<int> g[maxn];
vector<int> G[maxn];

ll add(ll a,ll b){
    ll ret = (b && a > inf / b) ? inf : a * b;
    return ret;
}

ll w[1<<18];

struct Array {
    ll a[1<<19];
    int M;
    void init(int n) {
        for(M = 1; M < n + 2; M = M << 1);
        for(int i = 1; i <= n; ++i) a[i+M] = w[i];
        for(int i = (M-1); i; --i) 
            a[i] = add(a[i<<1], a[i<<1|1]);
    }
    ll get(int l,int r) {
        ll ret = 1;
        for(int s = M+l-1, t = M+r+1; s^t^1; s=s>>1, t=t>>1) {
            if(~s&1) ret = add(ret, a[s^1]);
            if( t&1) ret = add(ret, a[t^1]);
        }
        return ret;
    }
    void set(int x) {
        a[M + x] = w[x];
        for(int i = (M + x) >> 1; i; i = i >> 1) {
            a[i] = add(a[i << 1], a[i << 1 | 1]);
        }
    }
} tree;

int dep[maxn], tp[maxn], sz[maxn], F[maxn], id[maxn];
int cnt = 0;

void DFS(int x,int fa) {
    dep[x] = dep[fa] + 1;
    sz[x] = 1;
    F[x] = fa;
    for(int i : g[x]) {
        int y = e[i].u + e[i].v - x;
        if(y == fa) continue;
        G[x].push_back(y);
        DFS(y, x);
        sz[x] += sz[y];
    }
}

void build(int x,int fa) {
    int k=0;
    id[x] = ++cnt;
    for(int y:G[x]) 
        if(!k||sz[y]>sz[k]) k=y;
    if(k) tp[k] = tp[x], build(k, x);
    for(int y:G[x]) if(y!=k) 
        tp[y]=y, build(y, x); 
}

ll query(int x,int y) {
    ll ret = 1;
    while(tp[x] != tp[y]) {
        if(dep[tp[x]] < dep[tp[y]]) swap(x, y);
        ret = add(ret, tree.get(id[tp[x]], id[x]));
        x = F[tp[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    ret = add(ret, tree.get(id[x]+1, id[y]));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i = 1; i < n; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        g[e[i].u].push_back(i);
        g[e[i].v].push_back(i);
    }
    DFS(1, 1);
    tp[1] = 1;
    build(1, 1);
    for(int i = 1; i < n; ++i) {
        if(dep[e[i].u] > dep[e[i].v])
            swap(e[i].u, e[i].v);
        w[id[e[i].v]] = e[i].w;
    }
    tree.init(n);
    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int u, v;
            ll val;
            cin >> u >> v >> val;
            cout << val / query(u, v) << endl;
        } else {
            int p; ll c;
            cin >> p >> c;
            int u = e[p].v;
            w[id[u]] = c;
            tree.set(id[u]);
        }
    }
    return 0;
}