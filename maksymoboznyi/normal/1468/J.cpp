#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lg2(x) __lg(x)
#define rem_dupl(x) sort(all(x)); x.erase(unique(all(x)), x.end())
using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<ll,ll> ii;
typedef array<ll,4> edge;
#define x first
#define y second

const int maxn = (int)2e5 + 5;

ll n, m, k;
vector<edge> E;
vector<ii> G[maxn];
bool vis[maxn];

int cnt, par[maxn];
ll maxw;

void dfs(int u){
    vis[u] = 1;
    cnt++;
    for(auto i:G[u]){
        int v = i.x;
        ll w = i.y;
        if(w > k)
            continue;
        maxw = max(maxw, w);
        if(vis[v]) continue;
        dfs(v);
    }
}

int rootfind(int u){
    if(u == par[u])
        return u;
    return par[u] = rootfind(par[u]);
}

bool join(int u, int v){
    u = rootfind(u);
    v = rootfind(v);
    if(u == v)
        return 0;
    par[v] = u;
    return 1;
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        G[i].clear();
        vis[i] = 0;
        par[i] = i;
    }
    E.resize(m);

    for(int i = 0; i < m; i++){
        cin >> E[i][1] >> E[i][2] >> E[i][0];
        G[E[i][1]].push_back({E[i][2], E[i][0]});
        G[E[i][2]].push_back({E[i][1], E[i][0]});
    }

    cnt = 0;
    maxw = -1;
    ll ans = LLONG_MAX;

    dfs(1);

    if(cnt == n)
        ans = min(ans, k - maxw);
    
    for(edge &e:E){
        if(e[0] >= k) e[0] -= k, e[3] = 1;
        else e[0] = 0, e[3] = 0;
    }

    sort(all(E));

    bool f = 0;
    ll mst = 0;
    for(edge e:E){
        if(join(e[1], e[2])){
            mst += e[0];
            if(e[3])
                f = 1;

        }
    }

    if(f) ans = min(ans, mst);
    else
    for(edge e:E)
        if(e[3] == 1)
            ans = min(ans, e[0]);


    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        solve();
    }
    
    return 0;
}