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
int dp[200000];
int main(){
  int i;
  long long x = 0;
  long long y = 0;
  long long res1;
  long long res2 = 0;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=0;i<(N);i++){
    x++;
    if(A[i] < 0){
      swap(x, y);
    }
    res2 += x;
  }
  res1 = (long long) N * (N+1) / 2 - res2;
  wt_L(res1);
  wt_L(' ');
  wt_L(res2);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int N, A[2d5];
// int dp[2d5];
// {
//   int i;
//   ll x = 0, y = 0;
//   ll res1, res2 = 0;
//   rd(N,A(N));
// 
//   rep(i,N){
//     x++;
//     if(A[i] < 0) swap(x, y);
//     res2 += x;
//   }
// 
//   res1 = (ll) N * (N+1) / 2 - res2;
//   wt(res1, res2);
// }