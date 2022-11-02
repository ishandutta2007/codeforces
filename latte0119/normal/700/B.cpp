#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,K;
int lis[222222];

vint G[222222];

int par[20][222222],dep[222222],sz[222222];

void dfs(int v,int p,int d){
    par[0][v]=p;
    dep[v]=d;
    for(auto u:G[v]){
        if(p==u)continue;
        dfs(u,v,d+1);
        sz[v]+=sz[u];
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    rep(i,20)if((dep[u]-dep[v])>>i&1)u=par[i][u];
    if(u==v)return u;
    for(int i=19;i>=0;i--)if(par[i][u]!=par[i][v])u=par[i][u],v=par[i][v];
    return par[0][u];
}

pint findC(int v,int p){
    pint res(1001001001,-1);
    int m=0;
    for(auto u:G[v]){
        if(u==p)continue;
        res=min(res,findC(u,v));
        m=max(m,sz[u]);
    }
    m=max(m,2*K-sz[v]);
    res=min(res,pint(m,v));
    return res;
}
signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,2*K)scanf("%lld",&lis[i]),lis[i]--,sz[lis[i]]++;

    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    dfs(0,-1,0);
    rep(i,19){
        rep(j,N){
            if(par[i][j]==-1)par[i+1][j]=-1;
            else par[i+1][j]=par[i][par[i][j]];
        }
    }

    int c=findC(0,-1).se;
    int ans=0;
    rep(i,2*K){
        int v=lis[i];
        int p=lca(v,c);
        ans+=dep[v]+dep[c]-2*dep[p];
    }
    cout<<ans<<endl;
    return 0;
}