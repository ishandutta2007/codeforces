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
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=1000000007;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int N,K;
vint G[111];

int dp[111][21][21];
int tmp[21][21];


void dfs(int v,int p){
    dp[v][0][0]=1;
    dp[v][K][1]=1;

    for(auto u:G[v]){
        if(u==p)continue;
        dfs(u,v);

        memset(tmp,0,sizeof(tmp));
        for(int i=0;i<=K;i++){
            for(int j=0;j<=K;j++){
                for(int k=0;k<=K;k++){
                    for(int l=0;l<=K;l++){
                        int t=0;
                        if(i+l>K)chmax(t,l+1);
                        if(j+k>K)chmax(t,j);
                        if(t>K)continue;
                        int s=min(i,k+1);
                        add(tmp[s][t],dp[v][i][j]*dp[u][k][l]%mod);
                    }
                }
            }
        }
        rep(i,K+1)rep(j,K+1)dp[v][i][j]=tmp[i][j];
    }

}

signed main(){
    cin>>N>>K;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }
    dfs(0,-1);

    int ans=0;
    rep(i,K+1)add(ans,dp[0][i][0]);
    cout<<ans<<endl;
    return 0;
}