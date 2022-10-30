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

int N;
char C[16];
int A[16],B[16];

int dp[1<<16][121][2];

const int INF=1001001001001001001ll;
signed main(){
    cin>>N;
    rep(i,N){
        cin>>C[i]>>A[i]>>B[i];
    }

    fill_n(**dp,(1<<16)*121*2,INF);
    dp[0][0][0]=0;

    for(int i=0;i<(1<<N);i++){
        int baseA=0,baseB=0;
        int cntA=0,cntB=0;
        for(int j=0;j<N;j++){
            if(!(i>>j&1))continue;
            baseA+=A[j];baseB+=B[j];
            if(C[j]=='R')cntA++;else cntB++;
        }

        for(int k=0;k<N;k++){
            if(i>>k&1)continue;
            for(int j=0;j<=120;j++){
                int a,b,t,va=max(0ll,A[k]-cntA),vb=max(0ll,B[k]-cntB),vc;
                if(dp[i][j][0]!=INF){
                    a=0;b=dp[i][j][0]-baseB+j;t=baseA-dp[i][j][0];
                    vc=max(va-a,vb-b);
                    a+=vc;b+=vc;
                    if(a==va){
                        chmin(dp[i|(1<<k)][j+min(B[k],cntB)][0],dp[i][j][0]+vc);
                    }
                    else{
                        chmin(dp[i|(1<<k)][t+min(A[k],cntA)][1],dp[i][j][0]+vc);
                    }
                }
                if(dp[i][j][1]!=INF){
                    a=dp[i][j][1]-baseA+j;b=0;t=baseB-dp[i][j][1];
                    vc=max(va-a,vb-b);
                    a+=vc;b+=vc;
                    if(a==va){
                        chmin(dp[i|(1<<k)][t+min(B[k],cntB)][0],dp[i][j][1]+vc);
                    }
                    else{
                        chmin(dp[i|(1<<k)][j+min(A[k],cntA)][1],dp[i][j][1]+vc);
                    }
                }
            }
        }
    }

    int ans=INF;
    rep(i,120+1)rep(j,2)chmin(ans,dp[(1<<N)-1][i][j]);
    cout<<ans+N<<endl;
    return 0;
}