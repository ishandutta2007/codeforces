#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
ll pot(ll x, ll p){
    if (p==0) return 1;
    if (p==2) return (x*x)%mod;
    if (p%2==0) return pot(pot(x, p/2), 2);
    return (x*pot(x, p-1))%mod;
}
ll inv(ll x){
    return pot(x, mod-2);
}
vector<int> g[202020];
ll v[202020];
ll dp[202020];

void dfs1(int x, int p){
    dp[x]=1;
    for (int nx:g[x]){
        if (nx!=p){
            dfs1(nx, x);
            dp[x]*=dp[nx];
            dp[x]%=mod;
        }
    }
    dp[x]++;
    dp[x]%=mod;
}
void dfs2(int x, int p, ll pv){
    v[x]=(((dp[x]+mod-1)%mod)*pv)%mod;
    vector<ll> lt;
    lt.push_back(pv);
    for (int nx:g[x]){
        if (nx!=p){
            lt.push_back((lt.back()*dp[nx])%mod);
        }
    }
    vector<ll> rt;
    rt.push_back(1);
    for (int i=g[x].size()-1;i>=0;i--){
        if (g[x][i]!=p){
            rt.push_back((rt.back()*dp[g[x][i]])%mod);
        }
    }
    int li=0;
    int ri=rt.size()-2;
    for (int nx:g[x]){
        if (nx!=p){
            dfs2(nx, x, (lt[li]*rt[ri]+1)%mod);
            li++;
            ri--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=2;i<=n;i++){
        int a;
        cin>>a;
        g[a].push_back(i);
        g[i].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0, 1);
    for (int i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
}