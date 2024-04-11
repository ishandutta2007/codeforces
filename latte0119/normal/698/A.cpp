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

int N;
int A[100];
int dp[111][3];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];
    fill_n(*dp,111*3,1001001001);
    dp[0][2]=0;

    rep(i,N){
        rep(j,3)chmin(dp[i+1][2],dp[i][j]+1);
        rep(j,2){
            if(A[i]>>j&1){
                rep(k,3)if(k!=j)chmin(dp[i+1][j],dp[i][k]);
            }
        }
    }

    int mi=1001001001;
    rep(i,3)chmin(mi,dp[N][i]);
    cout<<mi<<endl;
    return 0;
}