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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
int main(){
  int i;
  int X;
  rd(X);
  int Y;
  rd(Y);
  int A[X][Y];
  int ad[X][Y];
  int res = 0;
  char tmp[500][502];
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(X);Lj4PdHRW++){
      rd(tmp[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(X);i++){
    int j;
    for(j=(0);j<(Y);j++){
      if(tmp[i][j]=='W'){
        A[i][j] =0;
      }
      else{
        A[i][j] =1;
      }
    }
  }
  for(i=(X)-1;i>=(0);i--){
    int j;
    for(j=(Y)-1;j>=(0);j--){
      ad[i][j] = 0;
      if(i+1 < X){
        ad[i][j] ^= ad[i+1][j];
      }
      if(j+1 < Y){
        ad[i][j] ^= ad[i][j+1];
      }
      if(i+1 < X && j+1 < Y){
        ad[i][j] ^= ad[i+1][j+1];
      }
      A[i][j] ^= ad[i][j];
      if(A[i][j]){
        res++;
        ad[i][j] ^= 1;
      }
    }
  }
  for(i=(0);i<(X-1);i++){
    int j;
    for(j=(0);j<(Y-1);j++){
      if(A[i][j] && A[X-1][j] && A[i][Y-1] && A[X-1][Y-1]){
        res--;
        goto tU__gIr_;
      }
    }
  }
  tU__gIr_:;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int @X, @Y, A[X][Y], ad[X][Y], res = 0;
// char tmp[500][502];
// rd(tmp(X));
// rep(i,X) rep(j,Y) A[i][j] = if[tmp[i][j]=='W', 0, 1];
// 
// rrep(i,X) rrep(j,Y){
//   ad[i][j] = 0;
//   if(i+1 < X) ad[i][j] ^= ad[i+1][j];
//   if(j+1 < Y) ad[i][j] ^= ad[i][j+1];
//   if(i+1 < X && j+1 < Y) ad[i][j] ^= ad[i+1][j+1];
//   A[i][j] ^= ad[i][j];
//   if(A[i][j]){
//     res++;
//     ad[i][j] ^= 1;
//   }
// }
// 
// rep(i,X-1) rep(j,Y-1) if(A[i][j] && A[X-1][j] && A[i][Y-1] && A[X-1][Y-1]) res--, break_break;
// wt(res);