#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N,Q;
vint G[300000];

int sz[300000];
int par[20][300000];
int dep[300000];
int c[300000];

void predfs(int v,int p,int d){
    par[0][v]=p;
    dep[v]=d;
    sz[v]=1;
    for(auto u:G[v]){
        predfs(u,v,d+1);
        sz[v]+=sz[u];
    }
}

void dfs(int v){
    for(auto u:G[v])dfs(u);

    int w=-1;
    for(auto u:G[v]){
        if(sz[u]*2>sz[v]){
            w=u;
        }
    }
    if(w==-1){
        c[v]=v;
        return;
    }


    w=c[w];

    if((sz[v]-sz[w])*2<=sz[v]){
        c[v]=w;
        return;
    }

    for(int i=19;i>=0;i--){
        if(dep[w]-(1ll<<i)<=dep[v])continue;
        int ww=par[i][w];
        if((sz[v]-sz[ww])*2<=sz[v])continue;
        w=ww;
    }
    c[v]=par[0][w];
}

signed main(){
    scanf("%lld%lld",&N,&Q);
    for(int i=1;i<N;i++){
        int p;
        scanf("%lld",&p);
        p--;
        G[p].pb(i);
    }
    predfs(0,-1,0);
    rep(i,19){
        rep(j,N){
            if(par[i][j]==-1)par[i+1][j]=-1;
            else par[i+1][j]=par[i][par[i][j]];
        }
    }
    dfs(0);

    while(Q--){
        int v;
        scanf("%lld",&v);
        v--;
        printf("%lld\n",c[v]+1);
    }
    return 0;
}