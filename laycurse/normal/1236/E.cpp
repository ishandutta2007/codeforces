#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int M;
int A[100000];
int arr[100000];
int dp[400000];
int lf[100000];
int rg[100000];
int main(){
  int i;
  int geta;
  int mx;
  long long res = 0;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  if(N==1){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  geta = M + 10;
  mx = geta + N + M + 10;
  for(i=(0);i<(M);i++){
    arr[i] = A[i] - i - 1 + geta;
  }
  for(i=(0);i<(mx);i++){
    dp[i] = 0;
  }
  for(i=(M)-1;i>=(0);i--){
    chmax(dp[arr[i]], dp[arr[i]-1] + 1);
  }
  for(i=(0);i<(N);i++){
    rg[i] =min_L(N-1, i + M + 1 - dp[i+geta]);
  }
  for(i=(0);i<(M);i++){
    arr[i] = A[i] + i + 1 + geta;
  }
  for(i=(0);i<(mx);i++){
    dp[i] = 0;
  }
  for(i=(M)-1;i>=(0);i--){
    chmax(dp[arr[i]], dp[arr[i]+1] + 1);
  }
  for(i=(0);i<(N);i++){
    lf[i] =max_L(0, i - M - 1 + dp[i+geta]);
  }
  for(i=(0);i<(N);i++){
    res += rg[i] - lf[i] + 1;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int N, M, A[1d5];
// int arr[1d5], dp[4d5];
// int lf[1d5], rg[1d5];
// {
//   int geta, mx;
//   ll res = 0;
//   rd(N,M,(A--)(M));
//   if(N==1) wt(0), return 0;
// 
//   geta = M + 10;
//   mx = geta + N + M + 10;
// 
//   rep(i,M) arr[i] = A[i] - i - 1 + geta;
//   rep(i,mx) dp[i] = 0;
//   rrep(i,M) dp[arr[i]] >?= dp[arr[i]-1] + 1;
//   rep(i,N) rg[i] = min(N-1, i + M + 1 - dp[i+geta]);
// 
//   rep(i,M) arr[i] = A[i] + i + 1 + geta;
//   rep(i,mx) dp[i] = 0;
//   rrep(i,M) dp[arr[i]] >?= dp[arr[i]+1] + 1;
//   rep(i,N) lf[i] = max(0, i - M - 1 + dp[i+geta]);
// 
//   rep(i,N) res += rg[i] - lf[i] + 1;
//   wt(res);
// }