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

int N;
vint G[200000];

int dist[200000];
int par[20][200000];
void dfs(int v,int p,int d){
    dist[v]=d;
    par[0][v]=p;
    for(auto u:G[v])dfs(u,v,d+1);
}

int lca(int u,int v){
    if(dist[u]<dist[v])swap(u,v);
    rep(i,20)if((dist[u]-dist[v])>>i&1)u=par[i][u];
    if(u==v)return u;
    for(int i=19;i>=0;i--)if(par[i][u]!=par[i][v])u=par[i][u],v=par[i][v];
    return par[0][u];
}

int get(int u,int v){
    return dist[u]+dist[v]-2*dist[lca(u,v)];
}

signed main(){
    scanf("%lld",&N);
    for(int i=1;i<N;i++){
        int p;
        scanf("%lld",&p);
        p--;
        G[p].pb(i);
    }
    dfs(0,-1,0);
    for(int i=0;i<19;i++){
        for(int j=0;j<N;j++){
            if(par[i][j]==-1)par[i+1][j]=-1;
            else par[i+1][j]=par[i][par[i][j]];
        }
    }

    int u=0,v=0;
    for(int i=1;i<N;i++){
        int a=get(u,v);
        int b=get(i,v);
        int c=get(u,i);
        if(a<b){
            u=i;
            printf("%lld ",b);
        }
        else if(a<c){
            v=i;
            printf("%lld ",c);
        }
        else{
            printf("%lld ",a);
        }
    }
    puts("");
    return 0;
}