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
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int X;
    int Y;
    int A;
    int B;
    rd(X);
    rd(Y);
    rd(A);
    rd(B);
    if((Y-X)%(A+B)){
      wt_L(-1);
      wt_L('\n');
    }
    else{
      wt_L((Y-X)/(A+B));
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200214-1

// --- original code ---
// //no-unlocked
// {
//   REP(rd_int()){
//     int X, Y, A, B;
//     rd(X,Y,A,B);
//     wt(if[(Y-X)%(A+B), -1, (Y-X)/(A+B)]);
//   }
// }