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
int A[200000];
int B[200000];
int use[200000];
int main(){
  int i;
  int r;
  int k;
  int m;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N-1);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  r = A[0];
  use[r] = 1;
  k = N-1;
  for(i=(0);i<(N-1);i++){
    while(use[k]){
      k--;
    }
    m = k;
    if(i+1 < N-1 && !use[A[i+1]]){
      m = A[i+1];
    }
    use[m] = 1;
    B[i] = m;
  }
  wt_L(A[0]+1);
  wt_L('\n');
  for(i=(0);i<(N-1);i++){
    wt_L(A[i]+1);
    wt_L(' ');
    wt_L(B[i]+1);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], B[2d5];
// int use[2d5];
// 
// {
//   int r, k, m;
//   rd(N,(A--)(N-1));
// 
//   r = A[0];
//   use[r] = 1;
//   k = N-1;
//   rep(i,N-1){
//     while(use[k]) k--;
//     m = k;
//     if(i+1 < N-1 && !use[A[i+1]]) m = A[i+1];
//     use[m] = 1;
//     B[i] = m;
//   }
// 
//   wt(A[0]+1);
//   rep(i,N-1) wt(A[i]+1, B[i]+1);
// }