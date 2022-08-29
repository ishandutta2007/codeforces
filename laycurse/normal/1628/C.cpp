#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
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
int N;
int A[1000][1000];
int b[1000][1000];
int get(int i, int j){
  int ni, nj;
  int k = 0;
  {
    static int Nzj9Y0kE[4] = {-1, 0, 0, 1};
    static int bkxOPzPX[4] = {0, -1, 1, 0};
    int WKqLrJHZ;
    for(WKqLrJHZ=(0);WKqLrJHZ<(4);WKqLrJHZ++){
      ni = (i) + Nzj9Y0kE[WKqLrJHZ];
      nj = (j) + bkxOPzPX[WKqLrJHZ];
      if(0 <= ni  &&  ni < N && 0 <= nj  &&  nj < N){
        k ^= b[ni][nj];
      }
    }
  }
  return k;
}
int main(){
  int bs24PFPc;
  int R5MtCiij = rd_int();
  for(bs24PFPc=(0);bs24PFPc<(R5MtCiij);bs24PFPc++){
    int i;
    int res = 0;
    rd(N);
    {
      int ATMZloZo;
      int pyHJGNQc;
      for(ATMZloZo=(0);ATMZloZo<(N);ATMZloZo++){
        for(pyHJGNQc=(0);pyHJGNQc<(N);pyHJGNQc++){
          rd(A[ATMZloZo][pyHJGNQc]);
        }
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        b[i][j] = 0;
      }
    }
    for(i=(1);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        b[i][j] = 1 ^ get(i-1, j);
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        if(b[i][j]){
          res ^= A[i][j];
        }
      }
    }
    wt_L(res);
    wt_L('\n');
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
// cLay version 20220116-1 [+beta]

// --- original code ---
// //no-unlocked
// int N, A[1000][1000], b[1000][1000];
// int get(int i, int j){
//   int k = 0;
//   rep_dist(ni, nj, i, j) if(0 <= ni < N && 0 <= nj < N) k ^= b[ni][nj];
//   return k;
// }
// {
//   REP(rd_int()){
//     int res = 0;
//     rd(N,A(N,N));
//     rep(i,N) rep(j,N) b[i][j] = 0;
//     rep(i,1,N) rep(j,N) b[i][j] = 1 ^ get(i-1, j);
//     rep(i,N) rep(j,N) if(b[i][j]) res ^= A[i][j];
//     wt(res);
//   }
// }