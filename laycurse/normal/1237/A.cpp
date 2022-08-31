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
int N;
int A[15000];
int main(){
  int i;
  int fg = 0;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    if(A[i] % 2 != 0){
      if(fg==0){
        A[i]++;
      }
      else{
        A[i]--;
      }
      fg ^= 1;
    }
  }
  for(i=(0);i<(N);i++){
    A[i] /= 2;
  }
  {
    int xr20shxY;
    for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
      wt_L(A[xr20shxY]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191108-1

// --- original code ---
// //no-unlocked
// int N, A[15000];
// {
//   int fg = 0;
//   rd(N,A(N));
//   rep(i,N) if(A[i] % 2 != 0){
//     if[fg==0, A[i]++, A[i]--];
//     fg ^= 1;
//   }
//   rep(i,N) A[i] /= 2;
//   wtLn(A(N));
// }