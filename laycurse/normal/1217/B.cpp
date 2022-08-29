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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int T;
int N;
int X;
int D[100];
int H[100];
int main(){
  int Lj4PdHRW;
  int res;
  rd(T);
  for(Lj4PdHRW=0;Lj4PdHRW<(T);Lj4PdHRW++){
    int i;
    rd(N);
    rd(X);
    {
      int KL2GvlyY;
      for(KL2GvlyY=0;KL2GvlyY<(N);KL2GvlyY++){
        rd(D[KL2GvlyY]);
        rd(H[KL2GvlyY]);
      }
    }
    for(i=0;i<(N);i++){
      if(D[i] >= X){
        break;
      }
    }
    if(i<N){
      wt_L(1);
      wt_L('\n');
      continue;
    }
    res = 1073709056;
    for(i=0;i<(N);i++){
      if(D[i] > H[i]){
        int j;
        for(j=0;j<(N);j++){
          chmin(res,divup_L((X - D[j]),(D[i] - H[i])) + 1);
        }
      }
    }
    if(res==1073709056){
      res = -1;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int T, N, X, D[100], H[100];
// {
//   int res;
//   rd(T);
//   rep(T){
//     rd(N,X,(D,H)(N));
//     rep(i,N) if(D[i] >= X) break;
//     if(i<N) wt(1), continue;
// 
//     res = int_inf;
//     rep(i,N) if(D[i] > H[i]) rep(j,N){
//       res <?= (X - D[j]) /+ (D[i] - H[i]) + 1;
//     }
//     if(res==int_inf) res = -1;
//     wt(res);
//   }
// }