#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001001001001ll;

int N,B;
vint G[5555];
int C[5555],D[5555];

int dp[2][5000][5001];
int sz[5000];


int d[2][5001];
int t[2][5001];

void dfs(int v,int p){
    for(auto u:G[v]){
        if(u==p)continue;
        dfs(u,v);
    }
    rep(f,2){
        fill_n(*d,2*5001,INF);
        d[0][0]=0;
        d[0][1]=C[v];
        if(f){
            d[1][1]=C[v]-D[v];
        }
        sz[v]=1;
        for(auto u:G[v]){
            if(u==p)continue;
            rep(k,2)rep(i,sz[v]+sz[u]+1)t[k][i]=INF;
            rep(k,2){
                for(int i=0;i<=sz[v];i++){
                    for(int j=0;j<=sz[u];j++){
                        chmin(t[k][i+j],d[k][i]+dp[k][u][j]);
                    }
                }
            }
            sz[v]+=sz[u];
            rep(k,2)rep(i,sz[v]+1)chmin(d[k][i],t[k][i]);
        }

        rep(i,sz[v]+1)dp[f][v][i]=min(d[0][i],d[1][i]);
    }
}

signed main(){
    scanf("%lld%lld",&N,&B);
    rep(i,N){
        scanf("%lld%lld",&C[i],&D[i]);
        if(i){
            int x;scanf("%lld",&x);
            x--;
            G[x].pb(i);
        }
    }

    dfs(0,-1);


    int ans=0;
    rep(i,2)rep(j,N+1)if(dp[i][0][j]<=B)chmax(ans,j);
    cout<<ans<<endl;
    return 0;
}