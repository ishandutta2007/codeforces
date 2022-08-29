#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  return getchar();
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
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
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
}
inline void wt_L(char a){
  my_putchar(a);
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int M;
int K;
int P[1000][1000];
int res1;
int res2;
long long x;
long long v;
long long xx;
long long xv;
long long vv;
long long s[1000];
long long ss[3];
long long tmp;
int main(){
  int i;
  int j;
  int k;
  rd(M);
  rd(K);
  {
    int Lj4PdHRW;
    int KL2GvlyY;
    for(Lj4PdHRW=(0);Lj4PdHRW<(K);Lj4PdHRW++){
      for(KL2GvlyY=(0);KL2GvlyY<(M);KL2GvlyY++){
        rd(P[Lj4PdHRW][KL2GvlyY]);
      }
    }
  }
  for(i=(0);i<(K);i++){
    for(j=(0);j<(M);j++){
      s[i] += P[i][j];
    }
  }
  for(i=(1);i<(K);i++){
    for(j=(i+1);j<(K);j++){
      if(s[i]-s[i-1] == s[j]-s[j-1]){
        v = s[i] - s[i-1];
        goto ao_dF3pO;
      }
    }
  }
  ao_dF3pO:;
  for(i=(0);i<(K);i++){
    for(j=(i+1);j<(K);j++){
      if(s[i] - i*v == s[j] - j*v){
        x = s[i] - i*v;
        goto V9aVTaxx;
      }
    }
  }
  V9aVTaxx:;
  for(i=(0);i<(K);i++){
    if(s[i] != x + i*v){
      res1 = i;
    }
  }
  for(i=(0);i<(K);i++){
    if(res1 != i && res1 != i+1 && res1 != i+2){
      break;
    }
  }
  for(k=(0);k<(3);k++){
    for(j=(0);j<(M);j++){
      ss[k] += (long long)P[i+k][j] * P[i+k][j];
    }
  }
  vv = (ss[0] + ss[2] - 2*ss[1]) / 2;
  ss[0] -= i * i * vv;
  ss[1] -= (i+1) * (i+1) * vv;
  xv = (ss[1] - ss[0]) / 2;
  xx = ss[0] - 2 * i * xv;
  i = res1;
  k = x + i * v - s[i];
  for(j=(0);j<(M);j++){
    int m;
    P[i][j] += k;
    tmp = 0;
    for(m=(0);m<(M);m++){
      tmp += (long long)P[i][m] * P[i][m];
    }
    if(tmp == i*i*vv + 2*i*xv + xx){
      res2 = P[i][j];
    }
    P[i][j] -= k;
  }
  wt_L(res1);
  wt_L(' ');
  wt_L(res2);
  wt_L('\n');
  return 0;
}
// cLay version 20210708-1

// --- original code ---
// //no-unlocked
// //interactive
// int M, K, P[1000][1000];
// int res1, res2;
// ll x, v, xx, xv, vv, s[1000], ss[3], tmp;
// {
//   int i, j, k;
//   rd(M,K,P(K,M));
//   rep(i,K) rep(j,M) s[i] += P[i][j];
//   rep(i,1,K) rep(j,i+1,K) if(s[i]-s[i-1] == s[j]-s[j-1]) v = s[i] - s[i-1], break_break;
//   rep(i,K) rep(j,i+1,K) if(s[i] - i*v == s[j] - j*v) x = s[i] - i*v, break_break;
//   rep(i,K) if(s[i] != x + i*v) res1 = i;
// 
//   rep(i,K) if(res1 != i && res1 != i+1 && res1 != i+2) break;
//   rep(k,3) rep(j,M) ss[k] += (ll)P[i+k][j] * P[i+k][j];
// 
//   vv = (ss[0] + ss[2] - 2*ss[1]) / 2;
//   ss[0] -= i * i * vv;
//   ss[1] -= (i+1) * (i+1) * vv;
// 
//   xv = (ss[1] - ss[0]) / 2;
//   xx = ss[0] - 2 * i * xv;
// 
//   i = res1;
//   k = x + i * v - s[i];
//   rep(j,M){
//     P[i][j] += k;
//     tmp = 0;
//     rep(m,M) tmp += (ll)P[i][m] * P[i][m];
//     if(tmp == i*i*vv + 2*i*xv + xx) res2 = P[i][j];
//     P[i][j] -= k;
//   }
// 
//   wt(res1, res2);
// }