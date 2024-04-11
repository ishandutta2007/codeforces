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
int A[100];
int K;
int C[100];
int main(){
  int cur, i, sum;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  C[K++] = 0;
  for(i=1;i<N;i++){
    if(A[0] >= 2*A[i]){
      C[K++] = i;
    }
  }
  {
    int KL2GvlyY, Q5VJL1cS;
    if(N==0){
      Q5VJL1cS = 0;
    }
    else{
      Q5VJL1cS = A[0];
      for(KL2GvlyY=1;KL2GvlyY<N;KL2GvlyY++){
        Q5VJL1cS += A[KL2GvlyY];
      }
    }
    sum =Q5VJL1cS;
  }
  cur = 0;
  for(i=0;i<K;i++){
    cur += A[C[i]];
  }
  if(2*cur > sum){
    wt_L(K);
    wt_L('\n');
    {
      int e98WHCEY;
      if(K==0){
        putchar('\n');
      }
      else{
        for(e98WHCEY=0;e98WHCEY<K-1;e98WHCEY++){
          wt_L(C[e98WHCEY]+1);
          wt_L(' ');
        }
        wt_L(C[e98WHCEY]+1);
        wt_L('\n');
      }
    }
  }
  else{
    wt_L(0);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190721-1

// --- original code ---
// //no-unlocked
// int N, A[100];
// 
// int K, C[100];
// {
//   int i, sum, cur;
// 
//   rd(N,A(N));
//   
//   C[K++] = 0;
//   rep(i,1,N) if(A[0] >= 2A[i]) C[K++] = i;
// 
//   sum = sum(A(N));
//   cur = 0;
//   rep(i,K) cur += A[C[i]];
// 
//   if(2cur > sum){
//     wt(K);
//     wt(C(K)+1);
//   } else {
//     wt(0);
//   }
// }