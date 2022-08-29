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
long long N;
long long P;
long long W;
long long D;
int main(){
  long long x;
  long long y;
  long long z;
  rd(N);
  rd(P);
  rd(W);
  rd(D);
  for(y=(0);y<(100000);y++){
    x = (P - y * D) / W;
    z = N - x - y;
    if(x >= 0 && z >= 0 && x * W + y * D == P){
      wt_L(x);
      wt_L(' ');
      wt_L(y);
      wt_L(' ');
      wt_L(z);
      wt_L('\n');
      return 0;
    }
  }
  wt_L(-1);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// ll N, P, W, D;
// {
//   ll x, y, z;
//   rd(N,P,W,D);
//   rep(y,1d5){
//     x = (P - y * D) / W;
//     z = N - x - y;
//     if(x >= 0 && z >= 0 && x * W + y * D == P) wt(x,y,z), return 0;
//   }
//   wt(-1);
// }