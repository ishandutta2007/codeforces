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
int A[100000];
int B[100000];
int cnv[100000];
int vis[100000];
int main(){
  int i;
  int res = 0;
  int ok = 0;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){
      rd(B[e98WHCEY]);B[e98WHCEY] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    cnv[A[i]] = i;
  }
  for(i=(0);i<(N);i++){
    B[i] = cnv[B[i]];
  }
  for(i=(0);i<(N);i++){
    if(ok != B[i]){
      res++;
    }
    vis[B[i]] = 1;
    while(ok < N && vis[ok]){
      ok++;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191108-1

// --- original code ---
// //no-unlocked
// int N, A[1d5], B[1d5];
// int cnv[1d5], vis[1d5];
// {
//   int res = 0, ok = 0;
//   rd(N,(A--)(N),(B--)(N));
//   rep(i,N) cnv[A[i]] = i;
//   rep(i,N) B[i] = cnv[B[i]];
// 
//   rep(i,N){
//     if(ok != B[i]) res++;
//     vis[B[i]] = 1;
//     while(ok < N && vis[ok]) ok++;
//   }
//   wt(res);
// }