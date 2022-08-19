#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<int,int> > my_edges;
vector<pair<int, pair<int,int> > > her_edges;

struct UF{
    int n;
    vector<int> par;
    UF(int n) : n(n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    void join(int a, int b){
        par[find(a)] = find(b);
    }
};

vector<vector<int> > tree_edges;
vector<vector<int> > who;

vector<int> par;
vector<int> par_who;

vector<int> depth;

const int MAXN = 1100000000; // bad
const int MAXJ = 19;

vector<vector<int> > jump;
vector<vector<int> > upd;
void init(int n){
    par.resize(n);
    par_who.resize(n);
    tree_edges.resize(n);
    who.resize(n);

    depth.resize(n);
    jump.resize(MAXJ, vector<int> (n));
    upd.resize(MAXJ, vector<int> (n, MAXN));
}

void dfs(int v, int p, int v_who, int d){
    par[v] = p;
    par_who[v] = v_who;

    depth[v] = d;
    for(int i = 0; i < tree_edges[v].size(); i++){
        int a = tree_edges[v][i];
        if(a == p) continue;
        dfs(a, v, who[v][i], d+1);
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    init(n);
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        my_edges.push_back({a,b});
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        her_edges.push_back({c, {a,b}});
    }

    UF uf(n);
    for(int i = 0; i < k; i++){
        pair<int,int> x = my_edges[i];
        uf.join(x.first, x.second);
        for(int q = 0; q < 2; q++){
            tree_edges[x.first].push_back(x.second);
            who[x.first].push_back(0);
            swap(x.first, x.second);
        }
    }
    vector<int> used(m, 0);
    for(int i = 0; i < m; i++){
        pair<int,int> x = her_edges[i].second;
        if(uf.find(x.first) == uf.find(x.second)) continue;
        used[i] = 1;
        uf.join(x.first, x.second);
        for(int q = 0; q < 2; q++){
            tree_edges[x.first].push_back(x.second);
            who[x.first].push_back(1);
            swap(x.first, x.second);
        }
    }
    dfs(0, -1, -1, 0);
    for(int i = 0; i < n; i++){
        jump[0][i] = par[i];
        if(jump[0][i] == -1) jump[0][i] = 0;
    }
    for(int j = 1; j < MAXJ; j++){
        for(int i = 0; i < n; i++){
            jump[j][i] = jump[j-1][jump[j-1][i]];
        }
    }
    for(int i = 0; i < m; i++){
        if(used[i]) continue;
        auto x = her_edges[i];
        int u = x.second.first;
        int v = x.second.second;
        
        int cost = x.first;
        if(depth[u] > depth[v]){
            swap(u,v);
        }
        for(int j = MAXJ - 1; j >= 0; j--){
            if(depth[v] >= depth[u] + (1<<j)){
                upd[j][v] = min(upd[j][v], cost);
                v = jump[j][v];
            }
        }
        for(int j = MAXJ - 1; j >= 0; j--){
            if(jump[j][v] != jump[j][u]){
                upd[j][v] = min(upd[j][v], cost);
                v = jump[j][v];
                upd[j][u] = min(upd[j][u], cost);
                u = jump[j][u];
            }
        }
        if(u != v){
            upd[0][v] = min(upd[0][v], cost);
            v = jump[0][v];
            upd[0][u] = min(upd[0][u], cost);
            u = jump[0][u];
        }
    }
    
    for(int j = MAXJ - 1; j > 0; j--){
        for(int i = 0; i < n; i++){
            upd[j-1][i] = min(upd[j-1][i], upd[j][i]);
            upd[j-1][jump[j-1][i]] = min(upd[j-1][jump[j-1][i]], upd[j][i]);
        }
    }
    
    LL ans = 0;
    int max_ans = 0;
    for(int i = 0; i < n; i++){
        if(i == 0) continue;
        if(par_who[i] == 0){
            max_ans = max(max_ans, upd[0][i]);
            ans += (LL)upd[0][i];
        }
    }
    if(max_ans == MAXN){
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}