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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
int K[3];
int has1[200000];
int has2[200000];
int has3[200000];
int dp1[200001];
int dp2[200001];
int dp3[200001];
int main(){
  int KrdatlYV, a2conNHc, i, xr20shxY;
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(3);Lj4PdHRW++){
      rd(K[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    int cTE1_r3A;
    if(3==0){
      cTE1_r3A = 0;
    }
    else{
      cTE1_r3A = K[0];
      for(e98WHCEY=(1);e98WHCEY<(3);e98WHCEY++){
        cTE1_r3A += K[e98WHCEY];
      }
    }
    N =cTE1_r3A;
  }
  for(xr20shxY=(0);xr20shxY<(K[0]);xr20shxY++){
    has1[rd_int()-1] = 1;
  }
  for(KrdatlYV=(0);KrdatlYV<(K[1]);KrdatlYV++){
    has2[rd_int()-1] = 1;
  }
  for(a2conNHc=(0);a2conNHc<(K[2]);a2conNHc++){
    has3[rd_int()-1] = 1;
  }
  for(i=(0);i<(N);i++){
    dp1[i+1] = dp1[i] + 1 - has1[i];
    dp2[i+1] = dp2[i] + 1 - has2[i];
    dp3[i+1] = dp3[i] + 1 - has3[i];
    chmin(dp2[i+1], dp1[i+1]);
    chmin(dp3[i+1], dp2[i+1]);
  }
  wt_L(dp3[N]);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191123-1

// --- original code ---
// //no-unlocked
// int N, K[3];
// int has1[2d5], has2[2d5], has3[2d5];
// int dp1[200001], dp2[200001], dp3[200001];
// {
//   rd(K(3));
//   N = sum(K(3));
//   rep(K[0]) has1[rd_int()-1] = 1;
//   rep(K[1]) has2[rd_int()-1] = 1;
//   rep(K[2]) has3[rd_int()-1] = 1;
// 
//   rep(i,N){
//     dp1[i+1] = dp1[i] + 1 - has1[i];
//     dp2[i+1] = dp2[i] + 1 - has2[i];
//     dp3[i+1] = dp3[i] + 1 - has3[i];
//     dp2[i+1] <?= dp1[i+1];
//     dp3[i+1] <?= dp2[i+1];
//   }
//   wt(dp3[N]);
// }