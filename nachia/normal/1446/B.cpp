#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int dp[5001][5001];

int main(){
  int zA,zB; cin>>zA>>zB;
  string A,B; cin>>A>>B;
  rep(i,A.size()+1) rep(j,B.size()+1) dp[i][j]=0;

  int ans=0;
  rep(i,A.size()+1) rep(j,B.size()+1){
    int& tg=dp[i][j];
    if(i!=0 && j!=0) if(A[i-1]==B[j-1]) tg=max(tg,dp[i-1][j-1]+2);
    if(i!=0) tg=max(tg,dp[i-1][j]-1);
    if(j!=0) tg=max(tg,dp[i][j-1]-1);
    ans=max(ans,tg);
  }
  cout<<ans<<endl;
  return 0;
}