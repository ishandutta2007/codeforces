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
int A[100000];
int main(){
  int i, s=0;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=0;i<N;i++){
    if(A[i]%2){
      s++;
    }
  }
  if(0 < s  &&  s < N){
    sort(A, A+N);
  }
  {
    int KL2GvlyY;
    if(N==0){
      putchar('\n');
    }
    else{
      for(KL2GvlyY=0;KL2GvlyY<N-1;KL2GvlyY++){
        wt_L(A[KL2GvlyY]);
        wt_L(' ');
      }
      wt_L(A[KL2GvlyY]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190608-1

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// {
//   int i, s = 0;
//   rd(N,A(N));
//   rep(i,N) if(A[i]%2) s++;
//   if(0 < s < N) sort(A, A+N);
//   wt(A(N));
// }