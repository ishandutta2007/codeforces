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
int T;
int A;
int B;
int N;
int main(){
  int Lj4PdHRW;
  rd(T);
  for(Lj4PdHRW=0;Lj4PdHRW<(T);Lj4PdHRW++){
    rd(A);
    rd(B);
    rd(N);
    N %= 3;
    if(N==0){
      wt_L(A);
      wt_L('\n');
    }
    else if(N==1){
      wt_L(B);
      wt_L('\n');
    }
    else{
      wt_L(A^B);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int T, A, B, N;
// {
//   rd(T);
//   rep(T){
//     rd(A,B,N);
//     N %= 3;
//     wt( if[N==0, A, N==1, B, A^B] );
//   }
// }