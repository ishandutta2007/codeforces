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
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(A);
    rd(B);
    if(A==B){
      wt_L(0);
      wt_L('\n');
      continue;
    }
    if(A < B && (B-A)%2==1){
      wt_L(1);
      wt_L('\n');
      continue;
    }
    if(A > B && (A-B)%2==0){
      wt_L(1);
      wt_L('\n');
      continue;
    }
    wt_L(2);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// {
//   int A, B;
//   REP(rd_int()){
//     rd(A,B);
//     if(A==B) wt(0), continue;
//     if(A < B && (B-A)%2==1) wt(1), continue;
//     if(A > B && (A-B)%2==0) wt(1), continue;
//     wt(2);
//   }
// }