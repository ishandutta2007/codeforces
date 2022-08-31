#pragma GCC optimize ("Ofast")
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
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
int N;
int res[100][100];
int ress;
int arr[10000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        res[i][j] = 0;
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<((N-1)/2);j++){
        res[i][(moddw_L((i+j+1),N))] = 1;
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<((N-1)/2);j++){
        res[i][(moddw_L((i-j-1),N))] = -1;
      }
    }
    ress = 0;
    for(i=(0);i<(N);i++){
      int j;
      for(j=(i+1);j<(N);j++){
        arr[ress++] = res[i][j];
      }
    }
    {
      int ZIeRIny5;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(ZIeRIny5=(0);ZIeRIny5<(ress-1);ZIeRIny5++){
          wt_L(arr[ZIeRIny5]);
          wt_L(' ');
        }
        wt_L(arr[ZIeRIny5]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int N, res[100][100];
// int ress, arr[1d4];
// {
//   REP(rd_int()){
//     rd(N);
//     rep(i,N) rep(j,N) res[i][j] = 0;
//     rep(i,N) rep(j,(N-1)/2) res[i][(i+j+1)%%N] = 1;
//     rep(i,N) rep(j,(N-1)/2) res[i][(i-j-1)%%N] = -1;
//     ress = 0;
//     rep(i,N) rep(j,i+1,N) arr[ress++] = res[i][j];
//     wt(arr(ress));
//   }
// }