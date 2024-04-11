#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  return getchar();
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
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
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
}
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
inline void wt_L(char a){
  my_putchar(a);
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int main(){
  int EEPmwYOn;
  int N;
  rd(N);
  int K;
  rd(K);
  int ar[32];
  int d[32][32];
  int o[32][32];
  int cur = 0;
  int x;
  int i;
  int j;
  for(i=(0);i<(32);i++){
    ar[i] = (i ^ (i>>1));
  }
  for(i=(0);i<(32);i++){
    x = ar[i];
    ar[i] = 0;
    for(j=(0);j<(30);j++){
      if(((x) &(1<<(j)))){
        ar[i] |= (1<<(2*j));
      }
    }
  }
  for(i=(0);i<(32);i++){
    for(j=(0);j<(32);j++){
      d[i][j] = ar[i]*2 + ar[j];
    }
  }
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N-1);j++){
      o[i][j] = d[i][j] ^ d[i][j+1];
    }
  }
  {
    int Dc_3QP3Y;
    int myTeyldV;
    for(Dc_3QP3Y=(0);Dc_3QP3Y<(N);Dc_3QP3Y++){
      if(N-1==0){
        wt_L('\n');
      }
      else{
        for(myTeyldV=(0);myTeyldV<(N-1-1);myTeyldV++){
          wt_L(o[Dc_3QP3Y][myTeyldV]);
          wt_L(' ');
        }
        wt_L(o[Dc_3QP3Y][myTeyldV]);
        wt_L('\n');
      }
    }
  }
  for(i=(0);i<(N-1);i++){
    for(j=(0);j<(N);j++){
      o[i][j] = d[i][j] ^ d[i+1][j];
    }
  }
  {
    int Jq7Vmy8K;
    int a3zq_coq;
    for(Jq7Vmy8K=(0);Jq7Vmy8K<(N-1);Jq7Vmy8K++){
      if(N==0){
        wt_L('\n');
      }
      else{
        for(a3zq_coq=(0);a3zq_coq<(N-1);a3zq_coq++){
          wt_L(o[Jq7Vmy8K][a3zq_coq]);
          wt_L(' ');
        }
        wt_L(o[Jq7Vmy8K][a3zq_coq]);
        wt_L('\n');
      }
    }
  }
  int hUQRwZho = K;
  for(EEPmwYOn=(0);EEPmwYOn<(hUQRwZho);EEPmwYOn++){
    rd(x);
    for(i=(0);i<(N);i++){
      for(j=(0);j<(N);j++){
        if(d[i][j] == (cur^x)){
          wt_L(i+1);
          wt_L(' ');
          wt_L(j+1);
          wt_L('\n');
          goto Lbzl0EzV;
        }
      }
    }
    Lbzl0EzV:;
    cur ^= x;
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220312-1 [+beta]

// --- original code ---
// //interactive
// int @N, @K, ar[32], d[32][32], o[32][32], cur = 0, x, i, j;
// 
// rep(i,32) ar[i] = (i ^ (i>>1));
// rep(i,32){
//   x = ar[i]; ar[i] = 0;
//   rep(j,30) if(BIT_ith(x,j)) ar[i] |= (1<<(2*j));
// }
// rep(i,32) rep(j,32) d[i][j] = ar[i]*2 + ar[j];
// 
// rep(i,N) rep(j,N-1) o[i][j] = d[i][j] ^ d[i][j+1];
// wt(o(N,N-1));
// 
// rep(i,N-1) rep(j,N) o[i][j] = d[i][j] ^ d[i+1][j];
// wt(o(N-1,N));
// 
// REP(K){
//   rd(x);
//   rep(i,N) rep(j,N) if(d[i][j] == (cur^x)) wt(i+1,j+1), break_break;
//   cur ^= x;
// }