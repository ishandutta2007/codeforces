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

int dp[55];
int sum[55];

int N;
int A[55];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];
    reverse(A,A+N);
    rep(i,N)sum[i+1]=sum[i]+A[i];

    dp[0]=0;
    for(int i=0;i<N;i++){
        dp[i+1]=max(dp[i],A[i]+sum[i]-dp[i]);
    }

    cout<<sum[N]-dp[N]<<" "<<dp[N]<<endl;
    return 0;
}