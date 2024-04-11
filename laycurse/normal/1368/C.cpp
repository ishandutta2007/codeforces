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
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
int N;
int K;
int X[500000];
int Y[500000];
int main(){
  int i;
  rd(N);
  for(i=(0);i<(N);i++){
    arrInsert(K, K, X, 2*i, Y, -1);
  }
  for(i=(0);i<(N);i++){
    arrInsert(K, K, X, 2*i, Y, 1);
  }
  for(i=(-1);i<(2*N);i++){
    arrInsert(K, K, X, i, Y, 0);
  }
  if(N%2){
    arrInsert(K, K, X, -1, Y, 1);
    arrInsert(K, K, X, 2*N-1, Y, -1);
    for(i=(1);i<(N-1);i+=(2)){
      int j;
      for(j=(0);j<(3);j++){
        arrInsert(K, K, X, 2*i+j, Y, 2);
      }
    }
    for(i=(0);i<(N-1);i+=(2)){
      int j;
      for(j=(0);j<(3);j++){
        arrInsert(K, K, X, 2*i+j, Y, -2);
      }
    }
  }
  else{
    arrInsert(K, K, X, -1, Y, 1);
    arrInsert(K, K, X, 2*N-1, Y, 1);
    for(i=(1);i<(N-1);i+=(2)){
      int j;
      for(j=(0);j<(3);j++){
        arrInsert(K, K, X, 2*i+j, Y, 2);
      }
    }
    for(i=(0);i<(N-1);i+=(2)){
      int j;
      for(j=(0);j<(3);j++){
        arrInsert(K, K, X, 2*i+j, Y, -2);
      }
    }
  }
  wt_L(K);
  wt_L('\n');
  for(i=(0);i<(K);i++){
    wt_L(X[i]);
    wt_L(' ');
    wt_L(Y[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N;
// int K, X[5d5], Y[5d5];
// {
//   rd(N);
//   rep(i,N) arrInsert(K, K, X, 2i, Y, -1);
//   rep(i,N) arrInsert(K, K, X, 2i, Y, 1);
//   rep(i,-1,2N) arrInsert(K, K, X, i, Y, 0);
// 
//   if(N%2){
//     arrInsert(K, K, X, -1, Y, 1);
//     arrInsert(K, K, X, 2N-1, Y, -1);
//     rep(i,1,N-1,2) rep(j,3) arrInsert(K, K, X, 2i+j, Y, 2);
//     rep(i,0,N-1,2) rep(j,3) arrInsert(K, K, X, 2i+j, Y, -2);
//   } else {
//     arrInsert(K, K, X, -1, Y, 1);
//     arrInsert(K, K, X, 2N-1, Y, 1);
//     rep(i,1,N-1,2) rep(j,3) arrInsert(K, K, X, 2i+j, Y, 2);
//     rep(i,0,N-1,2) rep(j,3) arrInsert(K, K, X, 2i+j, Y, -2);
//   }
// 
//   wt(K);
//   rep(i,K) wt(X[i], Y[i]);
// 
//   // {
//   //   char buf[5][30] = {};
//   //   rep(i,5) rep(j,2N+1) buf[i][j] = '.';
//   //   rep(i,K) buf[Y[i]+2][X[i]+1] = '#';
//   //   wtLn(buf(5));
//   // }
// }