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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int INF=INT_MAX/100;
int N;
vint G[5000];

int dp[5000][5000][2];
int sz[5000];

int tmp[5000];

void dfs(int v,int p){
    if(G[v].size()==1){
        sz[v]=1;
        dp[v][0][0]=dp[v][1][1]=0;
        return;
    }

    dp[v][0][0]=dp[v][0][1]=0;
    rep(hoge,G[v].size()){
        int to=G[v][hoge];
        if(to==p)continue;
        dfs(to,v);
        rep(c,2){
            fill_n(tmp,sz[v]+sz[to]+1,INF);
            for(int i=0;i<=sz[v];i++){
                rep(cc,2){
                    for(int j=0;j<=sz[to];j++){
                        chmin(tmp[i+j],dp[v][i][c]+dp[to][j][cc]+(c!=cc));
                    }
                }
            }
            for(int i=0;i<=sz[v]+sz[to];i++)dp[v][i][c]=tmp[i];
        }
        sz[v]+=sz[to];
    }
}

signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    if(N==2){
        puts("1");
        return 0;
    }
    fill_n(**dp,5000*5000*2,INF);
    rep(i,N){
        if(G[i].size()!=1){
            dfs(i,-1);
            printf("%lld\n",min(dp[i][sz[i]/2][0],dp[i][sz[i]/2][1]));
            return 0;
        }
    }
    return 0;
}