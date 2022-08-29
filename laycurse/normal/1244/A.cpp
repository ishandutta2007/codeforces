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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int A;
int B;
int C;
int D;
int K;
int main(){
  int Lj4PdHRW;
  int res1;
  int res2;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(A);
    rd(B);
    rd(C);
    rd(D);
    rd(K);
    res1 =divup_L(A,C);
    res2 =divup_L(B,D);
    if(res1+res2 > K){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    wt_L(res1);
    wt_L(' ');
    wt_L(res2);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int A,B,C,D,K;
// {
//   int res1, res2;
//   REP(rd_int()){
//     rd(A,B,C,D,K);
//     res1 = A /+ C;
//     res2 = B /+ D;
//     if(res1+res2 > K) wt(-1), continue;
//     wt(res1,res2);
//   }
// }