#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int T;
int N;
int A[150000];
int main(){
  int Lj4PdHRW, i, mn, res;
  rd(T);
  for(Lj4PdHRW=0;Lj4PdHRW<(T);Lj4PdHRW++){
    rd(N);
    {
      int KL2GvlyY;
      for(KL2GvlyY=0;KL2GvlyY<(N);KL2GvlyY++){
        rd(A[KL2GvlyY]);
      }
    }
    mn = 1073709056;
    res = 0;
    for(i=N-1;i>=0;i--){
      chmin(mn, A[i]);
      if(mn < A[i]){
        res++;
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int T, N, A[150000];
// {
//   int i, mn, res;
//   rd(T);
//   rep(T){
//     rd(N,A(N));
//     mn = int_inf;
//     res = 0;
//     for(i=N-1;i>=0;i--){
//       mn <?= A[i];
//       if(mn < A[i]) res++;
//     }
//     wt(res);
//   }
// }