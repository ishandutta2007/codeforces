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
int N;
int A[50000][5];
int chk(int i, int j){
  int k;
  int res = 0;
  for(k=(0);k<(5);k++){
    if(A[i][k] < A[j][k]){
      res++;
    }
  }
  return res;
}
int main(){
  int Q5VJL1cS;
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int i;
    int j;
    int k;
    rd(N);
    {
      int FmcKpFmN;
      int xr20shxY;
      for(FmcKpFmN=(0);FmcKpFmN<(N);FmcKpFmN++){
        for(xr20shxY=(0);xr20shxY<(5);xr20shxY++){
          rd(A[FmcKpFmN][xr20shxY]);
        }
      }
    }
    k = 0;
    for(i=(1);i<(N);i++){
      if(chk(i,k) >= 3){
        k = i;
      }
    }
    for(i=(0);i<(N);i++){
      if(i != k && chk(i,k) >= 3){
        wt_L(-1);
        wt_L('\n');
        goto cTE1_r3A;
      }
    }
    wt_L(k+1);
    wt_L('\n');
    cTE1_r3A:;
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[50000][5];
// 
// int chk(int i, int j){
//   int res = 0;
//   rep(k,5) if(A[i][k] < A[j][k]) res++;
//   return res;
// }
// 
// {
//   REP(rd_int()){
//     int i, j, k;
//     rd(N,A(N,5));
//     k = 0;
//     rep(i,1,N) if(chk(i,k) >= 3) k = i;
//     rep(i,N) if(i != k && chk(i,k) >= 3) wt(-1), break_continue;
//     wt(k+1);
//   }
// }