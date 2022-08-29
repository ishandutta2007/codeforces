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
inline int BIT_ctz_L(const int x){
  return __builtin_ctz(x);
}
inline int BIT_ctz_L(const long long x){
  return __builtin_ctzll(x);
}
int N;
long long B[200000];
int val[200000];
int cnt[64];
int mxind;
long long res[200000];
long long ress;
int main(){
  int i;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(B[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    cnt[ val[i] =BIT_ctz_L(B[i])]++;
  }
  {
    int Q5VJL1cS;
    int e98WHCEY = 0;
    int cTE1_r3A;
    int RZTsC2BF;
    int FmcKpFmN;
    for(Q5VJL1cS=(0);Q5VJL1cS<(((64)-1)+1);Q5VJL1cS++){
      RZTsC2BF = cnt[Q5VJL1cS];
      if(e98WHCEY==0 || cTE1_r3A<RZTsC2BF){
        cTE1_r3A = RZTsC2BF;
        e98WHCEY = 1;
        FmcKpFmN = Q5VJL1cS;
      }
    }
    mxind =FmcKpFmN;
  }
  for(i=(0);i<(N);i++){
    if(val[i] != mxind){
      res[ress++] = B[i];
    }
  }
  wt_L(ress);
  wt_L('\n');
  {
    int xr20shxY;
    if(ress==0){
      putchar('\n');
    }
    else{
      for(xr20shxY=(0);xr20shxY<(ress-1);xr20shxY++){
        wt_L(res[xr20shxY]);
        wt_L(' ');
      }
      wt_L(res[xr20shxY]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// //no-unlocked
// int N;
// ll B[2d5];
// 
// int val[2d5], cnt[64], mxind;
// ll res[2d5], ress;
// {
//   rd(N,B(N));
//   rep(i,N) cnt[ val[i] = BIT_ctz(B[i]) ]++;
//   mxind = argmax(cnt(64));
//   rep(i,N) if(val[i] != mxind) res[ress++] = B[i];
//   wt(ress);
//   wt(res(ress));
// }