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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int Q;
int T;
int ind[50];
int res[300000];
int main(){
  int i, q;
  rd(N);
  rd(Q);
  for(i=(0);i<(50);i++){
    ind[i] = 1073709056;
  }
  for(i=(0);i<(N);i++){
    chmin(ind[rd_int()-1], i);
  }
  for(q=(0);q<(Q);q++){
    rd(T);T += (-1);
    res[q] = ind[T];
    for(i=(0);i<(50);i++){
      if(ind[i] < ind[T]){
        ind[i]++;
      }
    }
    ind[T] = 0;
  }
  {
    int WYIGIcGE;
    if(Q==0){
      wt_L('\n');
    }
    else{
      for(WYIGIcGE=(0);WYIGIcGE<(Q-1);WYIGIcGE++){
        wt_L(res[WYIGIcGE]+ 1);
        wt_L(' ');
      }
      wt_L(res[WYIGIcGE]+ 1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N, Q, T, ind[50];
// int res[3d5];
// {
//   rd(N,Q);
//   rep(i,50) ind[i] = int_inf;
//   rep(i,N) ind[rd_int()-1] <?= i;
//   rep(q,Q){
//     rd(T--);
//     res[q] = ind[T];
//     rep(i,50) if(ind[i] < ind[T]) ind[i]++;
//     ind[T] = 0;
//   }
//   wt(res(Q) + 1);
// }