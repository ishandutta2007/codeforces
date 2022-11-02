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

int dp[333333][3];


int Q;
int N;

int A[333333],B[333333];

void solve(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld%lld",&A[i],&B[i]);
    
    rep(i,N+1)rep(j,3)dp[i][j]=1001001001001001001ll;
    
    rep(i,3)dp[1][i]=i*B[0];
    for(int i=1;i<N;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(A[i-1]+j==A[i]+k)continue;
                chmin(dp[i+1][k],dp[i][j]+k*B[i]);
            }
        }
    }
    cout<<min({dp[N][0],dp[N][1],dp[N][2]})<<endl;
}

signed main(){
    scanf("%lld",&Q);
    while(Q--){
        solve();
    }
    return 0;
}