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
int M;
int A[300000][8];
int mask[256];
inline int getmask(int a[], int x){
  int i;
  int res = 0;
  for(i=(0);i<(M);i++){
    if(a[i] >= x){
      res |= (1<<i);
    }
  }
  return res;
}
int main(){
  int i;
  int x;
  int ok;
  rd(N);
  rd(M);
  for(i=(0);i<(N);i++){
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(M);cTE1_r3A++){
        rd(A[i][cTE1_r3A]);
      }
    }
  }
  int xr20shxY;
  int WYIGIcGE;
  int t_ynMSdg;
  xr20shxY = 0;
  WYIGIcGE = 1000000000;
  while(xr20shxY < WYIGIcGE){
    if((xr20shxY + WYIGIcGE)%2==0){
      t_ynMSdg = (xr20shxY + WYIGIcGE) / 2;
    }
    else{
      t_ynMSdg = (xr20shxY + WYIGIcGE + 1) / 2;
    }
    ok = 0;
    for(i=(0);i<(1<<M);i++){
      mask[i] = 0;
    }
    for(i=(0);i<(N);i++){
      mask[getmask(A[i],t_ynMSdg)] = 1;
    }
    for(i=(0);i<(1<<M);i++){
      if(mask[i]){
        int j;
        for(j=(0);j<(1<<M);j++){
          if(mask[j]){
            if((i|j)==(1<<M)-1){
              ok = 1;
            }
          }
        }
      }
    }
    if(ok){
      xr20shxY = t_ynMSdg;
    }
    else{
      WYIGIcGE = t_ynMSdg - 1;
    }
  }
  x =WYIGIcGE;
  for(i=(0);i<(1<<M);i++){
    mask[i] = -1;
  }
  for(i=(0);i<(N);i++){
    mask[getmask(A[i],x)] = i;
  }
  for(i=(0);i<(1<<M);i++){
    int j;
    for(j=(0);j<(1<<M);j++){
      if(mask[i] >= 0 && mask[j] >= 0 && (i|j)==(1<<M)-1){
        wt_L(mask[i]+1);
        wt_L(' ');
        wt_L(mask[j]+1);
        wt_L('\n');
        return 0;
      }
    }
  }
  return 0;
}
// cLay varsion 20200112-1

// --- original code ---
// //no-unlocked
// int N, M, A[3d5][8];
// int mask[256];
// 
// inline int getmask(int a[], int x){
//   int res = 0;
//   rep(i,M) if(a[i] >= x) res |= (1<<i);
//   return res;
// }
// 
// {
//   int x, ok;
//   rd(N,M);
//   rep(i,N) rd(A[i](M));
//   x = bsearch_max[int,x,0,1d9][
//     ok = 0;
//     rep(i,1<<M) mask[i] = 0;
//     rep(i,N) mask[getmask(A[i],x)] = 1;
//     rep(i,1<<M) if(mask[i]) rep(j,1<<M) if(mask[j]) if((i|j)==(1<<M)-1) ok = 1;
//   ](ok);
// 
//   rep(i,1<<M) mask[i] = -1;
//   rep(i,N) mask[getmask(A[i],x)] = i;
//   rep(i,1<<M) rep(j,1<<M) if(mask[i] >= 0 && mask[j] >= 0 && (i|j)==(1<<M)-1) wt(mask[i]+1,mask[j]+1), return 0;
// }