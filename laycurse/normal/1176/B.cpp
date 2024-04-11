#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
int T;
int N;
int A[100];
int main(){
  int Lj4PdHRW, c[3], i;
  rd(T);
  for(Lj4PdHRW=0;Lj4PdHRW<(T);Lj4PdHRW++){
    rd(N);
    {
      int KL2GvlyY;
      for(KL2GvlyY=0;KL2GvlyY<(N);KL2GvlyY++){
        rd(A[KL2GvlyY]);
      }
    }
    {
      int Q5VJL1cS;
      for(Q5VJL1cS=(0);Q5VJL1cS<((2) + 1);Q5VJL1cS++){
        c[Q5VJL1cS] = 0;
      }
    }
    {
      int e98WHCEY;
      for(e98WHCEY=(0);e98WHCEY<((N-1) + 1);e98WHCEY++){
        c[A[e98WHCEY]%3]++;
      }
    }
    i =min_L(c[1], c[2]);
    c[0] += i;
    {
      int RZTsC2BF;
      for(RZTsC2BF=(1);RZTsC2BF<((2) + 1);RZTsC2BF++){
        c[RZTsC2BF] -= i;
      }
    }
    {
      int FmcKpFmN;
      for(FmcKpFmN=(1);FmcKpFmN<((2) + 1);FmcKpFmN++){
        c[0] += c[FmcKpFmN] / 3;
      }
    }
    wt_L(c[0]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int T, N, A[100];
// {
//   int i, c[3];
//   
//   rd(T);
//   rep(T){
//     rd(N,A(N));
//     c[0..2] = 0;
//     c[A[0..N-1]%3]++;
// 
//     i = min(c[1], c[2]);
//     c[0] += i;
//     c[1..2] -= i;
//     c[0] += c[1..2] / 3;
// 
//     wt(c[0]);
//   }
// }