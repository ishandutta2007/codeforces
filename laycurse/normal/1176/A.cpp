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
int Q;
long long N;
int main(){
  int Lj4PdHRW, res;
  rd(Q);
  for(Lj4PdHRW=0;Lj4PdHRW<(Q);Lj4PdHRW++){
    rd(N);
    res = 0;
    while(N%5==0){
      res++;
      N = N/5*4;
    }
    while(N%3==0){
      res++;
      N = N/3*2;
    }
    while(N%2==0){
      res++;
      N /= 2;
    }
    if(N==1){
      wt_L(res);
      wt_L('\n');
    }
    else{
      wt_L(-1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int Q; ll N;
// {
//   int res;
//   rd(Q);
//   rep(Q){
//     rd(N);
//     res = 0;
//     while(N%5==0) res++, N = N/5*4;
//     while(N%3==0) res++, N = N/3*2;
//     while(N%2==0) res++, N /= 2;
//     wt( if[N==1, res, -1] );
//   }
// }