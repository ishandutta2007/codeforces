#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
template<class T> int Factor_L(T N, T fac[]){
  T i;
  int sz = 0;
  if(N%2==0){
    fac[sz] = 2;
    N /= 2;
    while(N%2==0){
      N /= 2;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      N /= i;
      while(N%i==0){
        N /= i;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    sz++;
  }
  return sz;
}
long long N;
int fs;
long long f[50];
int main(){
  rd(N);
  fs =Factor_L(N, f);
  if(fs==1){
    wt_L(f[0]);
    wt_L('\n');
  }
  else{
    wt_L(1);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// ll N;
// int fs; ll f[50];
// {
//   rd(N);
//   fs = Factor(N, f);
//   wt(if[fs==1, f[0], 1]);
// }