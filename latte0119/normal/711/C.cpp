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

int N,M,K;
int C[100];
int P[100][100];

const int INF=1001001001001001001ll;
int dp[101][101][101];

signed main(){
    scanf("%lld%lld%lld",&N,&M,&K);
    rep(i,N)scanf("%lld",&C[i]),C[i]--;
    rep(i,N)rep(j,M)scanf("%lld",&P[i][j]);

    fill_n(**dp,101*101*101,INF);
    if(C[0]>=0)dp[1][1][C[0]]=0;
    else{
        rep(i,M)dp[1][1][i]=P[0][i];
    }

    int premin[111],sufmin[111];
    for(int i=1;i<N;i++){
        for(int j=0;j<=i;j++){
            fill_n(premin,111,INF);
            fill_n(sufmin,111,INF);
            for(int k=1;k<M;k++){
                premin[k]=min(premin[k-1],dp[i][j][k-1]);
            }
            for(int k=M-2;k>=0;k--){
                sufmin[k]=min(sufmin[k+1],dp[i][j][k+1]);
            }
            for(int k=0;k<M;k++){
                if(C[i]>=0){
                    if(C[i]==k){
                        chmin(dp[i+1][j][k],dp[i][j][k]);
                        chmin(dp[i+1][j+1][k],min(premin[k],sufmin[k]));
                    }
                }
                else{
                    chmin(dp[i+1][j][k],dp[i][j][k]+P[i][k]);
                    chmin(dp[i+1][j+1][k],min(premin[k],sufmin[k])+P[i][k]);
                }
            }
        }
    }

    int ans=INF;
    for(int i=0;i<M;i++)chmin(ans,dp[N][K][i]);
    if(ans==INF){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}