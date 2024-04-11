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
inline void rd(long long &x){
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
inline void wt_L(long long x){
  char f[20];
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
int Q;
long long N;
long long M;
int main(){
  int Lj4PdHRW, d, i;
  long long res;
  rd(Q);
  for(Lj4PdHRW=0;Lj4PdHRW<(Q);Lj4PdHRW++){
    rd(N);
    rd(M);
    d = 0;
    for(i=0;i<(10);i++){
      d += (i*M) % 10;
    }
    N /= M;
    res = d * (N / 10);
    N %= 10;
    for(i=0;i<(N);i++){
      res += ((i+1)*M) % 10;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int Q;
// ll N, M;
// {
//   int i, d;
//   ll res;
//   rd(Q);
//   rep(Q){
//     rd(N,M);
//     d = 0;
//     rep(i,10) d += (i*M) % 10;
//     N /= M;
//     res = d * (N / 10);
//     N %= 10;
//     rep(i,N) res += ((i+1)*M) % 10;
//     wt(res);
//   }
// }