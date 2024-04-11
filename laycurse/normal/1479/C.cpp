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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N = 32;
int M;
int mat[32][32];
int main(){
  int i;
  int j;
  int k;
  int s;
  int L;
  rd(L);
  int R;
  rd(R);
  int h = R - L + 1;
  int r;
  mat[0][N-1] = L;
  mat[N-2][N-1] = 1;
  for(k=1;(1<<k)<=h;k++){
    for(i=(0);i<(k);i++){
      mat[i][k] = (1<<(k-1));
    }
    mat[k][N-1] = L;
  }
  r = h - (1<<(k-1));
  s = R - r;
  for(k=(0);k<(28);k++){
    if(r & (1<<k)){
      mat[k+1][N-2] = s - (1<<k);
      s += (1<<k);
    }
  }
  wt_L("YES");
  wt_L('\n');
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N);j++){
      if(mat[i][j] > 0){
        M++;
      }
    }
  }
  wt_L(N);
  wt_L(' ');
  wt_L(M);
  wt_L('\n');
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N);j++){
      if(mat[i][j] > 0){
        wt_L(i+1);
        wt_L(' ');
        wt_L(j+1);
        wt_L(' ');
        wt_L(mat[i][j]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 2]

// --- original code ---
// //no-unlocked
// int N = 32, M;
// int mat[32][32];
// 
// {
//   int i, j, k, s;
//   int @L, @R, h = R - L + 1, r;
// 
//   mat[0][N-1] = L;
//   mat[N-2][N-1] = 1;
//   for(k=1;(1<<k)<=h;k++){
//     rep(i,k) mat[i][k] = (1<<(k-1));
//     mat[k][N-1] = L;
//   }
//   r = h - (1<<(k-1));
//   s = R - r;
//   rep(k,28) if(r & (1<<k)){
//     mat[k+1][N-2] = s - (1<<k);
//     s += (1<<k);
//   }
// 
//   wt("YES");
//   rep(i,N) rep(j,N) if(mat[i][j] > 0) M++;
//   wt(N,M);
//   rep(i,N) rep(j,N) if(mat[i][j] > 0) wt(i+1,j+1,mat[i][j]);
// }