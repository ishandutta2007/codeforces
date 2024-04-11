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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int Q;
int N;
int A[400];
int main(){
  int Lj4PdHRW, i;
  rd(Q);
  for(Lj4PdHRW=0;Lj4PdHRW<(Q);Lj4PdHRW++){
    rd(N);
    {
      int KL2GvlyY;
      for(KL2GvlyY=0;KL2GvlyY<(4*N);KL2GvlyY++){
        rd(A[KL2GvlyY]);
      }
    }
    sort(A,A+4*N);
    for(i=0;i<(2*N);i++){
      if(A[2*i]!=A[2*i+1]){
        break;
      }
      A[i] = A[2*i];
    }
    if(i!=2*N){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    for(i=0;i<(N);i++){
      if(A[0]*A[2*N-1] != A[i]*A[2*N-1-i]){
        break;
      }
    }
    if(i==N){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int Q, N, A[400];
// {
//   int i;
//   
//   rd(Q);
//   rep(Q){
//     rd(N,A(4N));
//     sort(A,A+4N);
//     rep(i,2N){
//       if(A[2i]!=A[2i+1]) break;
//       A[i] = A[2i];
//     }
//     if(i!=2N){
//       wt("NO");
//       continue;
//     }
// 
//     rep(i,N) if(A[0]*A[2N-1] != A[i]*A[2N-1-i]) break;
//     wt(if[i==N,"YES","NO"]);
//   }
// }