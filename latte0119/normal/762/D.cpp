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

const int INF=1001001001001001001;
int N;
int A[111111][3];

int dp[111111][5];

signed main(){

    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>N;
    rep(i,3)rep(j,N)cin>>A[j][i];

    fill_n(*dp,111111*5,-INF);
    dp[0][0]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                int s=0;
                for(int l=0;l<3;l++)if(min(j,k)<=l&&l<=max(j,k))s+=A[i][l];
                chmax(dp[i+1][k],dp[i][j]+s);
            }
        }
        int t=0;rep(j,3)t+=A[i][j];
        chmax(dp[i+1][3],dp[i][3]+t);
        chmax(dp[i+1][3],dp[i][0]+t);

        chmax(dp[i+1][4],dp[i][4]+t);
        chmax(dp[i+1][4],dp[i][2]+t);

        chmax(dp[i+1][2],dp[i][3]+t);
        chmax(dp[i+1][0],dp[i][4]+t);
    }
    cout<<dp[N][2]<<endl;
    return 0;
}