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
inline void rd(long long &x){
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
template<class T> inline T pow2_L(T a){
  return a*a;
}
inline long long Isqrt_f_L(const long long n){
  long long r = sqrt(n);
  r =max_L(r-2, 0);
  while(pow2_L((r+1))<= n ){
    r++;
  }
  return r;
}
int N;
long long M[1000][1000];
long long res[1000];
int main(){
  int i;
  rd(N);
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      rd(M[i][j]);
    }
  }
  for(i=(0);i<(N);i++){
    res[i] =Isqrt_f_L(M[(i+1)%N][i] * M[i][(i+2)%N] / M[(i+1)%N][(i+2)%N]);
  }
  {
    int Lj4PdHRW;
    if(N==0){
      putchar('\n');
    }
    else{
      for(Lj4PdHRW=(0);Lj4PdHRW<(N-1);Lj4PdHRW++){
        wt_L(res[Lj4PdHRW]);
        wt_L(' ');
      }
      wt_L(res[Lj4PdHRW]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// //no-unlocked
// int N;
// ll M[1000][1000];
// ll res[1000];
// 
// {
//   rd(N);
//   rep(i,N) rep(j,N) rd(M[i][j]);
//   rep(i,N) res[i] = Isqrt(M[(i+1)%N][i] * M[i][(i+2)%N] / M[(i+1)%N][(i+2)%N]);
//   wt(res(N));
// }