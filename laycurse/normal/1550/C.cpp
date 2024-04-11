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
int A[200000];
int sz;
int isok(int a, int b){
  int i;
  for(i=(a);i<(b+1);i++){
    int j;
    for(j=(i+1);j<(b+1);j++){
      int k;
      for(k=(j+1);k<(b+1);k++){
        if(A[i] <= A[j]  &&  A[j] <= A[k]){
          return 0;
        }
        if(A[i] >= A[j]  &&  A[j] >= A[k]){
          return 0;
        }
      }
    }
  }
  return 1;
}
int main(){
  int FmcKpFmN;
  int xr20shxY = rd_int();
  for(FmcKpFmN=(0);FmcKpFmN<(xr20shxY);FmcKpFmN++){
    int i;
    int res = 0;
    rd(N);
    {
      int KrdatlYV;
      for(KrdatlYV=(0);KrdatlYV<(N);KrdatlYV++){
        rd(A[KrdatlYV]);
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(i);j<(N);j++){
        if(!isok(i,j)){
          break;
        }
        res++;
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210708-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], sz;
// int isok(int a, int b){
//   rep(i,a,b+1) rep(j,i+1,b+1) rep(k,j+1,b+1){
//     if(A[i] <= A[j] <= A[k]) return 0;
//     if(A[i] >= A[j] >= A[k]) return 0;
//   }
//   return 1;
// }
// {
//   REP(rd_int()){
//     int res = 0;
//     rd(N,A(N));
//     rep(i,N) rep(j,i,N){
//       if(!isok(i,j)) break;
//       res++;
//     }
//     wt(res);
//   }
// }