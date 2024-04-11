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
int main(){
  int Lj4PdHRW;
  int A;
  int B;
  int C;
  int res;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(A);
    rd(B);
    rd(C);
    res = 0;
    while(B >= 1 && C >= 2){
      res += 3;
      B -= 1;
      C -= 2;
    }
    while(A >= 1 && B >= 2){
      res += 3;
      A -= 1;
      B -= 2;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// {
//   int A, B, C, res;
//   REP(rd_int()){
//     rd(A,B,C);
//     res = 0;
//     while(B >= 1 && C >= 2) res += 3, B -= 1, C -= 2;
//     while(A >= 1 && B >= 2) res += 3, A -= 1, B -= 2;
//     wt(res);
//   }
// }