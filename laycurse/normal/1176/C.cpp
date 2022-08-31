#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
inline void rd(int &x){
  int k, m=0;
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
  char f[10];
  int m=0, s=0;
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
int A[500000];
int lst[6] = {4,8,15,16,23,42};
int cnv[45];
int dp[7];
int main(){
  int i, k, res;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=0;i<(6);i++){
    cnv[lst[i]] = i;
  }
  for(i=0;i<(N);i++){
    A[i] = cnv[A[i]];
  }
  dp[0] = N;
  for(i=0;i<(N);i++){
    k = A[i];
    dp[k+1] =min_L(dp[k+1]+1, dp[k]);
  }
  res = N - 6* dp[6];
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int N, A[5d5];
// 
// int lst[6] = {4,8,15,16,23,42};
// int cnv[45];
// int dp[7];
// {
//   int i, k, res;
//   
//   rd(N,A(N));
//   rep(i,6) cnv[lst[i]] = i;
//   rep(i,N) A[i] = cnv[A[i]];
// 
//   dp[0] = N;
//   rep(i,N){
//     k = A[i];
//     dp[k+1] = min(dp[k+1]+1, dp[k]);
//   }
// 
//   res = N - 6 dp[6];
//   wt(res);
// }