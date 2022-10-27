#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10, mod = 1e9 + 7;
int add( int a, int b){
    return (a += b) >=  mod ?  a - mod : a;
}
int mul(int a, int b){
    return 1LL * a * b % mod;
}
 
struct fenwick{
    int bit[nax];
    int get(int idx){
        int res = 0;
        for(; idx > 0 ; idx -= idx & - idx)
            res +=  bit[idx];
        return res;
    }
    void update(int idx, int val){
        for(;idx < nax ; idx += idx & - idx)
            bit[idx] += val;
    }
    int get(int l, int r){
        if(l > r) return 0;
        return get(r) - get(l - 1);
    }
};
fenwick f;
int n, q, tin[nax], tout[nax], timer, up[nax][19];
vector<int> a[nax];
void dfs(int nod, int pa){
    tin[nod] = ++ timer;
    up[nod][0] = pa;
    for(int i = 1 ;i <= 18 ;i  ++)
        up[nod][i] = up[up[nod][i - 1]][i - 1];
    for(int i : a[nod]){
        if(i != pa)
            dfs(i, nod);
    }
    tout[nod] = ++ timer;
    return ;
}
bool ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v){
    if(ancestor(u, v)) return u;
    if(ancestor(v, u)) return v;
    for(int i = 18 ;i  >= 0 ; i --){
        if(!ancestor(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}
int v[nax], b[nax], dp[310];
bool mark[nax];
 
int main(){
    scanf("%d %d", &n , &q );
    for(int i = 1  ;i < n; i ++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);
    tout[0] = 1e9;
    while(q -- ){
        int k, root, m;
        scanf("%d %d %d", &k , &m , &root);
        for(int i = 1 ;i <= k ; i ++){
            scanf("%d", v + i);
            mark[v[i]] = true;
            f.update(tin[v[i]] , 1);
            f.update(tout[v[i]] + 1, -1);
            }
           // fprintf(stderr, "ALIVE\n");
        for(int i = 1 ; i <= k ;i ++){
            int lc = lca(root, v[i]);
            b[i] = f.get(tin[v[i]])  + f.get(tin[root]) - 2 * f.get(tin[lc]) + mark[lc] - 1;
        }
        for(int i = 1;  i <= k; i ++){
            mark[v[i]] = false;
            f.update(tin[v[i]], -1);
            f.update(tout[v[i]] + 1, 1);
        }
 
        sort(b + 1 , b + 1 + k);
        fill(dp, dp + m + 1, 0);
        dp[0] = 1;
        for(int i = 1 ; i <= k ;i ++){
            for(int j = min(i, m) ; j >= 0 ;j --){
                if(j <= b[i])dp[j] = 0;
                else dp[j] = add(dp[j - 1], mul(j - b[i], dp[j]));
                ///process in decreasing order
            }
        }
        int ans = 0;
        for(int i = 1 ; i <= m ;i ++)
            ans = add(ans, dp[i]);
        printf("%d\n", ans);
 
    }
 
}
/*
Good bye for a while laptop :P 
Good Luck in Manila -> tell myself!
*/