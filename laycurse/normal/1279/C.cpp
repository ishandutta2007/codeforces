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
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
int A[100000];
int B[100000];
int ind[100000];
int arr[100000];
int main(){
  int Lj4PdHRW;
  int mx;
  long long res;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(M);xr20shxY++){
        rd(B[xr20shxY]);B[xr20shxY] += (-1);
      }
    }
    for(i=(0);i<(N);i++){
      ind[A[i]] = i;
    }
    for(i=(0);i<(M);i++){
      arr[i] = ind[B[i]];
    }
    mx = -1;
    res = 0;
    for(i=(0);i<(M);i++){
      if(arr[i] <= mx){
        res++;
        continue;
      }
      mx = arr[i];
      res += 2*(mx-i) + 1;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// //no-unlocked
// int N, M, A[1d5], B[1d5];
// int ind[1d5], arr[1d5];
// {
//   int mx;
//   ll res;
//   REP(rd_int()){
//     rd(N,M,(A--)(N),(B--)(M));
//     rep(i,N) ind[A[i]] = i;
//     rep(i,M) arr[i] = ind[B[i]];
// 
//     mx = -1;
//     res = 0;
//     rep(i,M){
//       if(arr[i] <= mx) res++, continue;
//       mx = arr[i];
//       res += 2(mx-i) + 1;
//     }
//     wt(res);
//   }
// }