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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int A[400000];
long long cost[20][20];
long long cbit[20][1100000];
long long dp[1100000];
int main(){
  int i;
  int j;
  int k;
  int c1;
  int c2;
  long long res;
  long long t1;
  long long t2;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  for(i=0;i<(20);i++){
    for(j=(i+1);j<(20);j++){
      c1 = c2 = 0;
      t1 = t2 = 0;
      for(k=0;k<(N);k++){
        if(A[k]==i){
          c1++;
          t1 += c2;
        }
        if(A[k]==j){
          c2++;
          t2 += c1;
        }
      }
      cost[i][j] = t1;
      cost[j][i] = t2;
    }
  }
  for(j=0;j<(20);j++){
    for(i=0;i<(20);i++){
      cbit[j][1<<i] = cost[i][j];
    }
    for(i=0;i<(1<<20);i++){
      k =(-(i) & (i));
      if(k != i){
        cbit[j][i] = cbit[j][i^k] + cbit[j][k];
      }
    }
  }
  for(i=(1);i<(1<<20);i++){
    dp[i] = 4611686016279904256LL;
  }
  for(i=0;i<(1<<20);i++){
    for(j=0;j<(20);j++){
      if(!(i & 1<<j)){
        chmin(dp[i|(1<<j)], dp[i] + cbit[j][i]);
      }
    }
  }
  wt_L(dp[(1<<20)-1]);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int N, A[4d5];
// ll cost[20][20];
// ll cbit[20][1100000];
// ll dp[1100000];
// {
//   int i, j, k, c1, c2;
//   ll res, t1, t2;
// 
//   rd(N,(A--)(N));
//   rep(i,20) rep(j,i+1,20){
//     c1 = c2 = 0;
//     t1 = t2 = 0;
//     rep(k,N){
//       if(A[k]==i) c1++, t1 += c2;
//       if(A[k]==j) c2++, t2 += c1;
//     }
//     cost[i][j] = t1;
//     cost[j][i] = t2;
//   }
// 
//   rep(j,20){
//     rep(i,20) cbit[j][1<<i] = cost[i][j];
//     rep(i,1<<20){
//       k = BIT_lowest(i);
//       if(k != i) cbit[j][i] = cbit[j][i^k] + cbit[j][k];
//     }
//   }
// 
//   rep(i,1,1<<20) dp[i] = ll_inf;
//   rep(i,1<<20) rep(j,20) if(!(i & 1<<j)){
//     dp[i|(1<<j)] <?= dp[i] + cbit[j][i];
//   }
// 
//   wt(dp[(1<<20)-1]);
// }