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
int P[300000];
int inv[300000];
int M;
int A[1500000];
int B[1500000];
void swap_sub(int a, int b){
  swap(P[a], P[b]);
  swap(inv[P[a]], inv[P[b]]);
  A[M] = a+1;
  B[M++] = b+1;
}
void swap_main(int a, int b){
  if(a > b){
    swap(a,b);
  }
  if(b-a >= N/2){
    swap_sub(a,b);
    return;
  }
  if( a >= N/2 && b >= N/2 ){
    swap_sub(0,a);
    swap_sub(0,b);
    swap_sub(0,a);
    return;
  }
  if( N-1-a >= N/2 && N-1-b >= N/2 ){
    swap_sub(N-1,a);
    swap_sub(N-1,b);
    swap_sub(N-1,a);
    return;
  }
  swap_sub(0, b);
  swap_sub(a, N-1);
  swap_sub(0, N-1);
  swap_sub(0, b);
  swap_sub(a, N-1);
}
int main(){
  int i, j, k;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(P[Lj4PdHRW]);
    }
  }
  for(i=0;i<N;i++){
    P[i]--;
  }
  for(i=0;i<N;i++){
    inv[P[i]] = i;
  }
  for(i=0;i<N;i++){
    if(P[i]!=i){
      swap_main(i, inv[i]);
    }
  }
  wt_L(M);
  wt_L('\n');
  for(i=0;i<M;i++){
    wt_L(A[i]);
    wt_L(' ');
    wt_L(B[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190601-1

// --- original code ---
// //no-unlocked
// int N, P[3d5];
// int inv[3d5];
// 
// int M, A[15d5], B[15d5];
// 
// void swap_sub(int a, int b){
//   swap(P[a], P[b]);
//   swap(inv[P[a]], inv[P[b]]);
//   A[M] = a+1;
//   B[M++] = b+1;
// }
// 
// void swap_main(int a, int b){
//   if(a > b) swap(a,b);
// 
//   if(b-a >= N/2){
//     swap_sub(a,b);
//     return;
//   }
// 
//   if( a >= N/2 && b >= N/2 ){
//     swap_sub(0,a);
//     swap_sub(0,b);
//     swap_sub(0,a);
//     return;
//   }
// 
//   if( N-1-a >= N/2 && N-1-b >= N/2 ){
//     swap_sub(N-1,a);
//     swap_sub(N-1,b);
//     swap_sub(N-1,a);
//     return;
//   }
// 
//   swap_sub(0, b);
//   swap_sub(a, N-1);
//   swap_sub(0, N-1);
//   swap_sub(0, b);
//   swap_sub(a, N-1);
// }
// 
// {
//   int i, j, k;
//   
//   rd(N,P(N));
//   rep(i,N) P[i]--;
//   rep(i,N) inv[P[i]] = i;
// 
//   rep(i,N) if(P[i]!=i){
//     swap_main(i, inv[i]);
//   }
// 
//   wt(M);
//   rep(i,M) wt(A[i],B[i]);
// }