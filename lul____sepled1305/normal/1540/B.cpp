#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int dp[500][500];
vector<int> d[500];
 
int add(int a, int b) {
    long long l = 0LL + a + b;
    l %= mod;
    return (int) l;
}
 
int mul(int a, int b) {
    long long l = (1LL*a*b)%mod;
    return (int) l;
}
 
int power(int b, int p) {
    if(p == 0)
        return 1;
    int g = power(b,p/2);
    g = mul(g,g);
    if(p%2) g = mul(g,b);
    return g;
}
 
int inv(int b) {
    return power(b,mod-2);
}
 
int n,l;
 
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
int depth[500];
 
void dfs(int v, int p, int dd)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
 
    depth[v] = dd;
    for (int u : d[v]) {
        if (u != p)
            dfs(u, v, dd+1);
    }
 
    tout[v] = ++timer;
}
 
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
 
void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root, 0);
}
 
int main() {
    int vvv = inv(2);
    for(int i=0;i<210;i++) {
        for(int j=0;j<210;j++) {
            if(i == 0)
                dp[i][j] = 1;
            else if(j == 0)
                dp[i][j] = 0;
            else {
                dp[i][j] = add(mul(vvv,dp[i-1][j]),mul(vvv,dp[i][j-1]));
            }
        }
    }
    cin>>n;
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    int ept = 0, sv = inv(n);
    for(int k=0;k<n;k++) {
        preprocess(k);
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                int r = lca(i,j);
                ept = add(ept,dp[depth[i]-depth[r]][depth[j]-depth[r]]);
            }
        }
    }
    cout<<mul(ept,sv);
    return 0;
}