#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int C;
int A[200000];
int B[200000];
int dp[200000];
int tp[200000];
int main(){
  int i;
  rd(N);
  rd(C);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N-1);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N-1);e98WHCEY++){
      rd(B[e98WHCEY]);
    }
  }
  for(i=(0);i<(N);i++){
    dp[i] = tp[i] = 1073709056;
  }
  dp[0] = 0;
  for(i=(0);i<(N-1);i++){
    chmin(tp[i], dp[i] + C);
    chmin(dp[i], tp[i]);
    chmin(dp[i+1], dp[i] + A[i]);
    chmin(tp[i+1], tp[i] + B[i]);
  }
  for(i=(0);i<(N);i++){
    chmin(dp[i], tp[i]);
  }
  {
    int tU__gIr_;
    if(N==0){
      putchar('\n');
    }
    else{
      for(tU__gIr_=(0);tU__gIr_<(N-1);tU__gIr_++){
        wt_L(dp[tU__gIr_]);
        wt_L(' ');
      }
      wt_L(dp[tU__gIr_]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// int N, C, A[2d5], B[2d5];
// int dp[2d5], tp[2d5];
// {
//   rd(N,C,A(N-1),B(N-1));
//   rep(i,N) dp[i] = tp[i] = int_inf;
//   dp[0] = 0;
//   rep(i,N-1){
//     tp[i] <?= dp[i] + C;
//     dp[i] <?= tp[i];
//     dp[i+1] <?= dp[i] + A[i];
//     tp[i+1] <?= tp[i] + B[i];
//   }
//   rep(i,N) dp[i] <?= tp[i];
//   wt(dp(N));
// }