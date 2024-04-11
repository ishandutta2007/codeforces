#include<bits/stdc++.h>
using namespace std;
//#define LOCAL
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL
using ll = long long ;
int const nax = 1e5 + 10, Log = 17;
vector<pair<int, int >> a[nax];
vector<pair<int , ll >> b[nax];
struct P{
    int nod;
    ll val;
    bool operator < (const P &x) const{
        return val > x.val;
    }
    P(int x, ll y) : nod(x), val(y) {}
};
struct Edge{
    int u, v;
    ll w;
    bool operator < (const Edge & x) const{
        return w < x.w;
    }
};
priority_queue<P> q;
ll d[nax];
int n, m, pa[nax], k, dep[nax], sz[nax], tin[nax], tout[nax];
int up[nax][Log + 1];
ll f[nax][Log + 1];
bool vis[nax];

int Find(int x){
    return pa[x] == x ? x : pa[x] = Find(pa[x]);
}

void multisourceDijsktar(){
    ll const inf = 1e17;
    for(int i = 1 ;i <= k ;i ++){
        q.push(P(i, 0));
    }
    for(int i = k + 1  ;i <=  n ; i++){
        d[i] = inf;
    }
    while(!q.empty()){
        auto top = q.top();
        q.pop();
        if(vis[top.nod]) continue;
        vis[top.nod] = true;
        for(auto i:a[top.nod]){
            if(top.val + i.second < d[i.first]){
                d[i.first] = top.val + i.second;
                q.push(P(i.first, d[i.first]));
            }
        }
    }
    return ;
}
void kruskal(vector<Edge> &e){
    sort(e.begin(), e.end());
    for(auto &it: e){
        int u = Find(it.u);
        int v = Find(it.v);
        if(u == v) continue;
        b[it.u].emplace_back(it.v, it.w);
        b[it.v].emplace_back(it.u, it.w);
        if(sz[u] > sz[v]){
            swap(u, v);
        }
        pa[u] = v;
        sz[v] += sz[u];
    }
}
int timer ;
void dfs(int nod, int pa, ll cost){
    up[nod][0] = pa;
    f[nod][0] = cost;
    tin[nod] = ++ timer;
    for(auto i : b[nod]){
        if(i.first == pa) continue;
        dep[i.first] = dep[nod] + 1;
        dfs(i.first, nod, i.second);
    }
    tout[nod] = ++ timer;
    return ;
}
bool ancestor(int u, int v){
    return tin[u] <= tin[v] &&  tout[u] >= tout[v];
}

int lca(int u, int v){
    if(ancestor(u, v)) return u;
    if(ancestor(v, u)) return v;
    for(int i =  Log; i >= 0 ; i --){
        if(!ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

ll jump(int u, int lc){
    ll res = 0;
    int dist = dep[u] - dep[lc];
    for(int i = Log; i >= 0 ;i --){
        if((dist >> i) & 1){
            res = max(res, f[u][i]);
            u = up[u][i];
        }
    }
    return res;
}

int main(){
    int T;
    scanf("%d %d %d %d", &n, &m, &k, &T);
    for(int i = 1 ;i <= m ; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u].emplace_back(v, w);
        a[v].emplace_back(u, w);
    }
    multisourceDijsktar();
    for(int i = 1 ;i <= n ; i++){
        pa[i] = i;
        sz[i] = 1;
    }
    vector<Edge> E;
    for(int i = 1; i <= n; i ++){
        for(auto it: a[i]){
            E.push_back({i, it.first, d[i] + d[it.first] + it.second});
        }
    }
    kruskal(E);
    dfs(1 , 0, 0);
    tout[0] = 1000000000 ;
    for(int i = 1 ;i <= Log ; i++){
        for(int j = 1; j <=  n; j ++){
            up[j][i] = up[up[j][i - 1]][i - 1];
            f[j][i] = max(f[j][i-1], f[up[j][i-1]][i-1]);
        }
    }
   /* eprintf("Tree\n");int ct  = 0;
    for(int i = 1 ;i <= n ;i ++){
        for(auto it: b[i]){
            ++ ct;
            eprintf("%d %lld\n", it.first, it.second);
        }
    }
    cerr << ct << endl;*/
    while(T --){
        int u, v;
        scanf("%d %d", &u , &v);
        int lc = lca(u, v);
        eprintf("LCA = %d\n", lc);
        printf("%lld\n", max(jump(u, lc), jump(v, lc)));
    }
}

/**
    Imagine that we take path from a to b
    for each edge E in that path
    (u, v, w)
    If u can't reach any central -> fail
    -> we could recharge fuel as C - d[u,x] where x is the nearest central
    C - d[u,x] - W >= d[v, y] where y is the nearest central to y
    C >= d[u, x] + w + d[v, y]
    Then, if we take any path, the answer is maximum weight of d[u, x] + w + d[v, y] in that path
    we can compute d[u], d[v] by Dijkstar and the rest is trivial
*/