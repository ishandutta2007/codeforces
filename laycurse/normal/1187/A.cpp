#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
int TT;
int N;
int S;
int T;
int main(){
  int Lj4PdHRW, both, res;
  rd(TT);
  for(Lj4PdHRW=0;Lj4PdHRW<TT;Lj4PdHRW++){
    rd(N);
    rd(S);
    rd(T);
    both = S + T - N;
    S -= both;
    T -= both;
    res =max_L(S, T)+ 1;
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190630-1

// --- original code ---
// //no-unlocked
// int TT, N, S, T;
// {
//   int both, res;
//   
//   rd(TT);
//   rep(TT){
//     rd(N,S,T);
//     both = S + T - N;
//     S -= both;
//     T -= both;
//     res = max(S,T) + 1;
//     wt(res);
//   }
// }