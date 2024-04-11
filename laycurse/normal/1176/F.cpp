#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
inline void wt_L(long long x){
  char f[20];
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int K;
int C;
int D;
int d[3][200000];
int ds[3];
long long dp[10];
long long nx[10];
int main(){
  int Lj4PdHRW, i, j, k, x, y, z;
  long long mx, res, tmp;
  rd(N);
  for(i=(1);i<(10);i++){
    dp[i] = -4611686016279904256LL;
  }
  for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
    int KL2GvlyY;
    for(i=0;i<(10);i++){
      nx[i] = dp[i];
    }
    rd(K);
    for(i=0;i<(3);i++){
      ds[i] = 0;
    }
    for(KL2GvlyY=0;KL2GvlyY<(K);KL2GvlyY++){
      rd(C);C += (-1);
      rd(D);
      d[C][ds[C]++] = D;
    }
    for(i=0;i<(3);i++){
      sort(d[i], d[i]+ds[i]);
    }
    for(x=0;x<(4);x++){
      for(y=0;y<(3);y++){
        for(z=0;z<(2);z++){
          if(x+2*y+3*z > 3){
            continue;
          }
          if(x > ds[0] || y > ds[1] || z > ds[2]){
            continue;
          }
          tmp = mx = 0;
          k = x + y + z;
          for(i=0;i<(x);i++){
            tmp += d[0][ds[0]-1-i];
            chmax(mx, d[0][ds[0]-1-i]);
          }
          for(i=0;i<(y);i++){
            tmp += d[1][ds[1]-1-i];
            chmax(mx, d[1][ds[1]-1-i]);
          }
          for(i=0;i<(z);i++){
            tmp += d[2][ds[2]-1-i];
            chmax(mx, d[2][ds[2]-1-i]);
          }
          for(i=0;i<(10);i++){
            if(i+k>=10){
              chmax(nx[(i+k)%10], dp[i] +mx +tmp);
            }
            else{
              chmax(nx[(i+k)%10], dp[i] +tmp);
            }
          }
        }
      }
    }
    for(i=0;i<(10);i++){
      dp[i] = nx[i];
    }
  }
  {
    int Q5VJL1cS;
    long long e98WHCEY;
    if(10==0){
      e98WHCEY = 0;
    }
    else{
      e98WHCEY = dp[0];
      for(Q5VJL1cS=(1);Q5VJL1cS<(10);Q5VJL1cS++){
        e98WHCEY = max_L(e98WHCEY, dp[Q5VJL1cS]);
      }
    }
    res =e98WHCEY;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int N, K, C, D;
// 
// int d[3][2d5], ds[3];
// ll dp[10], nx[10];
// {
//   int i, j, k, x, y, z;
//   ll res, tmp, mx;
// 
//   rd(N);
//   rep(i,1,10) dp[i] = -ll_inf;
// 
//   rep(N){
//     rep(i,10) nx[i] = dp[i];
// 
//     rd(K);
//     rep(i,3) ds[i] = 0;
//     rep(K){
//       rd(C--,D);
//       d[C][ds[C]++] = D;
//     }
//     rep(i,3) sort(d[i], d[i]+ds[i]);
// 
//     rep(x,4) rep(y,3) rep(z,2){
//       if(x+2y+3z > 3) continue;
//       if(x > ds[0] || y > ds[1] || z > ds[2]) continue;
// 
//       tmp = mx = 0;
//       k = x + y + z;
//       rep(i,x) tmp += d[0][ds[0]-1-i], mx >?= d[0][ds[0]-1-i];
//       rep(i,y) tmp += d[1][ds[1]-1-i], mx >?= d[1][ds[1]-1-i];
//       rep(i,z) tmp += d[2][ds[2]-1-i], mx >?= d[2][ds[2]-1-i];
// 
//       rep(i,10) nx[(i+k)%10] >?= dp[i] + if[i+k>=10, mx + ] tmp;
//     }
// 
//     rep(i,10) dp[i] = nx[i];
//   }
// 
//   res = max(dp(10));
//   wt(res);
// }