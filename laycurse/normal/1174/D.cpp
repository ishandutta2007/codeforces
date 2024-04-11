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
int N;
int X;
int ress;
int res[300000];
int b[20];
int bs;
int main(){
  int i, j, k;
  rd(N);
  rd(X);
  for(i=0;i<N;i++){
    if(X == (1<<i)){
      continue;
    }
    if(X & (1<<i)){
      X ^= (1<<i);
    }
    b[bs++] = i;
  }
  for(i=0;i<bs;i++){
    k = ress;
    res[ress++] = (1<<b[i]);
    for(j=0;j<k;j++){
      res[ress++] = res[j];
    }
  }
  wt_L(ress);
  wt_L('\n');
  {
    int Lj4PdHRW;
    if(ress==0){
      putchar('\n');
    }
    else{
      for(Lj4PdHRW=0;Lj4PdHRW<ress-1;Lj4PdHRW++){
        wt_L(res[Lj4PdHRW]);
        wt_L(' ');
      }
      wt_L(res[Lj4PdHRW]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190608-2

// --- original code ---
// //no-unlocked
// int N, X;
// 
// int ress, res[3d5];
// int b[20], bs;
// {
//   int i, j, k;
//   rd(N,X);
// 
//   rep(i,N){
//     if(X == (1<<i)) continue;
//     if(X & (1<<i)) X ^= (1<<i);
//     b[bs++] = i;
//   }
// 
//   rep(i,bs){
//     k = ress;
//     res[ress++] = (1<<b[i]);
//     rep(j,k) res[ress++] = res[j];
//   }
// 
//   wt(ress);
//   wt(res(ress));
// }