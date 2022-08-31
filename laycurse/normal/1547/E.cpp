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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
int A[300000];
int T[300000];
int res[300000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(K);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(K);xr20shxY++){
        rd(T[xr20shxY]);
      }
    }
    for(i=(0);i<(N);i++){
      res[i] = 1073709056;
    }
    for(i=(0);i<(K);i++){
      chmin(res[A[i]], T[i]);
    }
    for(i=(1);i<(N);i++){
      chmin(res[i], res[i-1] + 1);
    }
    for(i=(N)-1;i>=(1);i--){
      chmin(res[i-1], res[i] + 1);
    }
    {
      int jZyWAPpY;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(jZyWAPpY=(0);jZyWAPpY<(N-1);jZyWAPpY++){
          wt_L(res[jZyWAPpY]);
          wt_L(' ');
        }
        wt_L(res[jZyWAPpY]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210708-1

// --- original code ---
// //no-unlocked
// int N, K, A[3d5], T[], res[];
// {
//   REP(rd_int()){
//     rd(N,K,(A--)(K),T(K));
//     rep(i,N) res[i] = int_inf;
//     rep(i,K) res[A[i]] <?= T[i];
//     rep(i,1,N) res[i] <?= res[i-1] + 1;
//     rrep(i,1,N) res[i-1] <?= res[i] + 1;
//     wt(res(N));
//   }
// }