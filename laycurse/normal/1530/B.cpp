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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int X;
int Y;
char res[20][22];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, j;
    rd(X);
    rd(Y);
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        res[i][j] = '0';
      }
    }
    for(i=(0);i<(X);i++){
      res[i][Y] = '\0';
    }
    for(j=(0);j<(Y);j+=(2)){
      res[0][j] = res[X-1][j] = '1';
    }
    for(i=(2);i<(X-2);i+=(2)){
      res[i][0] = res[i][Y-1] = '1';
    }
    {
      int hCmBdyQB;
      for(hCmBdyQB=(0);hCmBdyQB<(X);hCmBdyQB++){
        wt_L(res[hCmBdyQB]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int X, Y;
// char res[20][22];
// {
//   REP(rd_int()){
//     rd(X,Y);
//     rep(i,X) rep(j,Y) res[i][j] = '0';
//     rep(i,X) res[i][Y] = '\0';
//     rep(j,0,Y,2) res[0][j] = res[X-1][j] = '1';
//     rep(i,2,X-2,2) res[i][0] = res[i][Y-1] = '1';
//     wtLn(res(X));
//   }
// }