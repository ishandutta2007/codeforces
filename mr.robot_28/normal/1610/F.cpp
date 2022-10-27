#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
#define sz(a) (int)a.size()
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 7;

const int N = 3e5 + 100;
int n, m, mm;


int u[N], v[N], w[N], ans[N];
int deg[N], parr[N][3], mark[N];
vector <int> g[N][3], E[N];
vector <pair <int, int> > g2[N];

void orient(int i, int cur){
    if(cur == u[i]){
        ans[i] = 1;
        deg[u[i]] -= w[i];
        deg[v[i]] += w[i];
    }
    else{
        ans[i] = 2;
        deg[u[i]] += w[i];
        deg[v[i]] -= w[i];
    }
}

void mergepath(int i, int weight){
    mm++;
    int cur = i;
    while(1){
        while(sz(g[cur][weight]) && mark[g[cur][weight].back()]){
            g[cur][weight].pop_back();
        }
        if(g[cur][weight].empty()){
            break;
        }
        int i1 = g[cur][weight].back();
        mark[i1]= 1;
        E[mm].push_back(i1);
        int other = u[i1] ^ v[i1] ^ cur;
        parr[other][weight] ^= 1;
        parr[cur][weight] ^= 1;
        cur = other;
    }
    if(E[mm].empty()){
        mm--;
        return;
    }
    g2[i].push_back({cur, mm});
    g2[cur].push_back({i, -mm});
}

void dfs(int cur){
    while(sz(g2[cur]) && mark[abs(g2[cur].back().y)]){
        g2[cur].pop_back();
    }
    if(g2[cur].empty()){
        return;
    }
    int other = g2[cur].back().x;
    int id = g2[cur].back().y;
    if(id < 0){
        id *= -1;
        reverse(E[id].begin(), E[id].end());
    }
    mark[id] = 1;
    for(auto i : E[id]){
        orient(i, cur);
        cur ^= v[i] ^ u[i];
    }
    dfs(other);

}
signed main(){
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
  //  cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> w[i];
        parr[u[i]][w[i]] ^= 1;
        parr[v[i]][w[i]] ^= 1;
        g[u[i]][w[i]].push_back(i);
        g[v[i]][w[i]].push_back(i);
    }
    int sum = 0;
    for(int i = 1;i <= n; i+=1){
        sum += parr[i][1];
    }
    for(int i = 1;i <= n; i++){
        for(int w1 = 1; w1 <= 2; w1++){
            if(parr[i][w1]){
                mergepath(i, w1);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int w1 = 1; w1 <= 2; w1++){
            mergepath(i, w1);
        }
    }
    for(int i = 0; i < m; i++){
        mark[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(sz(g2[i]) % 2 == 1){
            dfs(i);
        }
    }
    for(int i = 1; i <= n; i++){
        dfs(i);
    }
    cout << sum << "\n";
    for(int i = 0;i < m; i++){
        cout << ans[i];
    }
    return 0;
}