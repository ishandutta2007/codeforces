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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int T;
int N;
int M;
int K;
int H[100];
int main(){
  int Lj4PdHRW, i;
  rd(T);
  for(Lj4PdHRW=0;Lj4PdHRW<(T);Lj4PdHRW++){
    rd(N);
    rd(M);
    rd(K);
    {
      int KL2GvlyY;
      for(KL2GvlyY=0;KL2GvlyY<(N);KL2GvlyY++){
        rd(H[KL2GvlyY]);
      }
    }
    for(i=0;i<(N-1);i++){
      M += H[i] -max_L(0, H[i+1]-K);
      if(M < 0){
        break;
      }
    }
    if(i==N-1){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int T, N, M, K, H[100];
// 
// {
//   int i;
// 
//   rd(T);
//   rep(T){
//     rd(N,M,K,H(N));
//     rep(i,N-1){
//       M += H[i] - max(0, H[i+1]-K);
//       if(M < 0) break;
//     }
//     wt(if[i==N-1,"YES","NO"]);
//   }
// }