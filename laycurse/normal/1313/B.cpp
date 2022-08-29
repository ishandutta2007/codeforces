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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
long long N;
long long X;
long long Y;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int res1;
    int res2;
    rd(N);
    rd(X);
    rd(Y);
    res1 = N - (N-X + N-Y - 1);
    res2 = X + Y - 1;
    chmax(res1, 1);
    chmin(res1, N);
    chmax(res2, 1);
    chmin(res2, N);
    wt_L(res1);
    wt_L(' ');
    wt_L(res2);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// ll N, X, Y;
// {
//   REP(rd_int()){
//     int res1, res2;
//     rd(N,X,Y);
//     res1 = N - (N-X + N-Y - 1);
//     res2 = X + Y - 1;
//     res1 >?= 1;
//     res1 <?= N;
//     res2 >?= 1;
//     res2 <?= N;
//     wt(res1,res2);
//   }
// }