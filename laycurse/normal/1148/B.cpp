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
inline void rd(long long &x){
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
int M;
int K;
long long TA;
long long TB;
long long A[200000];
long long B[200000];
int main(){
  int i, j, k;
  long long res=0, t;
  rd(N);
  rd(M);
  rd(TA);
  rd(TB);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=0;KL2GvlyY<M;KL2GvlyY++){
      rd(B[KL2GvlyY]);
    }
  }
  j = 0;
  for(k=0;k<K+1;k++){
    if(N <= k){
      res = -1;
      break;
    }
    t = A[k] + TA;
    while(j < M && B[j] < t){
      j++;
    }
    if(j + (K-k) >= M){
      res = -1;
      break;
    }
    chmax(res, B[j+(K-k)] + TB);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190601-1

// --- original code ---
// //no-unlocked
// int N, M, K;
// ll TA, TB;
// ll A[2d5], B[2d5];
// {
//   int i, j, k;
//   ll t;
//   ll res = 0;
//   rd(N,M,TA,TB,K,A(N),B(M));
// 
//   j = 0;
//   rep(k,K+1){
//     if(N <= k){
//       res = -1;
//       break;
//     }
// 
//     t = A[k] + TA;
//     while(j < M && B[j] < t) j++;
//     if(j + (K-k) >= M){
//       res = -1;
//       break;
//     }
// 
//     res >?= B[j+(K-k)] + TB;
//   }
// 
//   wt(res);
// }