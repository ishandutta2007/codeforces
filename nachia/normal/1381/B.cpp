#include<bits/stdc++.h>
using namespace std;
using UL=unsigned int;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

const UL ZN=2000;

UL N;
UL A[2*ZN];
vector<UL> D;
bool dp[2*ZN+1][2*ZN+1];

void Loop(){
 D.clear();

 scanf("%u",&N);
 rep(i,2*N) scanf("%u",&A[i]);
 D.push_back(1);
 for(UL i=1; i<2*N; i++){
  if(A[i-D.back()] < A[i]) D.push_back(1);
  else ++D.back();
 }
 rep(i,D.size()+1) rep(j,2*N+1) dp[i][j]=false;
 dp[0][0]=true;
 rep(i,D.size()){
  rep(j,2*N+1){
   if(!dp[i][j]) continue;
   dp[i+1][j]=true;
   dp[i+1][j+D[i]]=true;
  }
 }
 if(dp[D.size()][N]) printf("YES\n");
 else printf("NO\n");
}

int main(){
 UL T; scanf("%u",&T);
 rep(t,T) Loop();
 return 0;
}