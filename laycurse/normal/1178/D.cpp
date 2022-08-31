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
template<class T> inline int isPrime_L(T n){
  T i;
  if(n<=1){
    return 0;
  }
  if(n<=3){
    return 1;
  }
  if(n%2==0){
    return 0;
  }
  for(i=3;i*i<=n;i+=2){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}
int N;
int M;
int U[2000];
int V[2000];
void doit(int a, int b){
  U[M] = a+1;
  V[M++] = b+1;
}
int main(){
  int i, j, k;
  rd(N);
  for(i=0;i<N;i++){
    doit(i, (i+1)%N);
  }
  for(i=0;;i++){
    if(isPrime_L(M)){
      break;
    }
    doit(i, i+N/2);
  }
  wt_L(M);
  wt_L('\n');
  for(i=0;i<M;i++){
    wt_L(U[i]);
    wt_L(' ');
    wt_L(V[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190721-1

// --- original code ---
// //no-unlocked
// int N;
// 
// int M, U[2000], V[2000];
// 
// void doit(int a, int b){
//   U[M] = a+1;
//   V[M++] = b+1;
// }
// 
// {
//   int i, j, k;
//   rd(N);
// 
//   rep(i,N) doit(i, (i+1)%N);
// 
//   for(i=0;;i++){
//     if(isPrime(M)) break;
//     doit(i, i+N/2);
//   }
// 
//   wt(M);
//   rep(i,M) wt(U[i],V[i]);
// }