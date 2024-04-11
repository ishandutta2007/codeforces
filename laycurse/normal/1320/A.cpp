#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
int N;
int A[200000];
long long dp[700000];
int main(){
  int i;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    dp[A[i]-i+N+1] += A[i];
  }
  {
    int RZTsC2BF;
    long long FmcKpFmN;
    if(700000==0){
      FmcKpFmN = 0;
    }
    else{
      FmcKpFmN = dp[0];
      for(RZTsC2BF=(1);RZTsC2BF<(700000);RZTsC2BF++){
        FmcKpFmN = max_L(FmcKpFmN, dp[RZTsC2BF]);
      }
    }
    wt_L(FmcKpFmN);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200227-1

// --- original code ---
// //no-unlocked
// int N, A[2d5];
// ll dp[7d5];
// {
//   rd(N,A(N));
//   rep(i,N) dp[A[i]-i+N+1] += A[i];
//   wt(max(dp(7d5)));
// }