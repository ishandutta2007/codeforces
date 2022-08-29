#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
template<class T> inline T GCD_L(T a,T b){
  T r;
  while(a){
    r=b;
    b=a;
    a=r%a;
  }
  return b;
}
int N;
int A[200000];
int main(){
  int i;
  int m;
  int g;
  long long res = 0;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int KL2GvlyY;
    int Q5VJL1cS;
    if(N==0){
      Q5VJL1cS = 0;
    }
    else{
      Q5VJL1cS = A[0];
      for(KL2GvlyY=(1);KL2GvlyY<(N);KL2GvlyY++){
        Q5VJL1cS = max_L(Q5VJL1cS, A[KL2GvlyY]);
      }
    }
    m =Q5VJL1cS;
  }
  for(i=(0);i<(N);i++){
    A[i] = m - A[i];
  }
  {
    int e98WHCEY;
    int cTE1_r3A;
    if(N==0){
      cTE1_r3A = 0;
    }
    else{
      cTE1_r3A = A[0];
      for(e98WHCEY=(1);e98WHCEY<(N);e98WHCEY++){
        cTE1_r3A = GCD_L(cTE1_r3A, A[e98WHCEY]);
      }
    }
    g =cTE1_r3A;
  }
  for(i=(0);i<(N);i++){
    res += A[i] / g;
  }
  wt_L(res);
  wt_L(' ');
  wt_L(g);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190925-1

// --- original code ---
// //no-unlocked
// int N, A[2d5];
// {
//   int m, g;
//   ll res = 0;
//   rd(N,A(N));
//   m = max(A(N));
//   rep(i,N) A[i] = m - A[i];
//   g = gcd(A(N));
//   rep(i,N) res += A[i] / g;
//   wt(res,g);
// }