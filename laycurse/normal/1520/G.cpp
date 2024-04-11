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
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
struct dimcomp2{
  int B;
  dimcomp2(){
  }
  dimcomp2(int b){
    B = b;
  }
  dimcomp2(int a, int b){
    B = b;
  }
  inline void set(int b){
    B = b;
  }
  inline void set(int a, int b){
    B = b;
  }
  inline int mask(int a, int b){
    return a * B + b;
  }
  inline int operator()(int a, int b){
    return a * B + b;
  }
  inline void para(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
  inline void operator()(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
}
;
int X;
int Y;
int W;
int A[2000][2000];
int dd[4000000];
int q[4000000];
int qs;
int qe;
int main(){
  int s;
  int i;
  int j;
  int k;
  int ni;
  int nj;
  int nk;
  int d;
  long long res = 4611686016279904256LL;
  long long mn[2] = {4611686016279904256LL, 4611686016279904256LL};
  rd(X);
  rd(Y);
  rd(W);
  {
    int Lj4PdHRW;
    int KL2GvlyY;
    for(Lj4PdHRW=(0);Lj4PdHRW<(X);Lj4PdHRW++){
      for(KL2GvlyY=(0);KL2GvlyY<(Y);KL2GvlyY++){
        rd(A[Lj4PdHRW][KL2GvlyY]);
      }
    }
  }
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  dimcomp2 dm(X, Y);
  for(s=(0);s<(2);s++){
    for(i=(0);i<(X*Y);i++){
      dd[i] = -1;
    }
    if(s==0){
      k =0;
    }
    else{
      k =dm(X-1,Y-1);
    }
    dd[k] = 0;
    qs = qe = 0;
    q[qe++] = k;
    while(qs < qe){
      k = q[qs++];
      dm(k, i, j);
      if(A[i][j] > 0){
        chmin(mn[s], (long long)W*dd[k] + A[i][j]);
      }
      for(d=(0);d<(4);d++){
        auto hCmBdyQB = ((i + dx[d]));
        auto V9aVTaxx = (( j + dy[d]));
        ni=hCmBdyQB;
        nj=V9aVTaxx;
        if(ni < 0 || nj < 0 || ni >= X || nj >= Y || A[ni][nj] == -1){
          continue;
        }
        nk = dm(ni, nj);
        if(dd[nk] >= 0){
          continue;
        }
        dd[nk] = dd[k] + 1;
        q[qe++] = nk;
      }
    }
    if(s==1 && dd[0] >= 0){
      chmin(res, (long long)W*dd[0]);
    }
  }
  chmin(res, mn[0] + mn[1]);
  if(res==4611686016279904256LL){
    res = -1;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210502-1 [beta]

// --- original code ---
// //no-unlocked
// int X, Y, W;
// int A[2000][2000], dd[4d6];
// int q[4d6], qs, qe;
// {
//   int i, j, k, ni, nj, nk, d;
//   ll res = ll_inf, mn[2] = {ll_inf, ll_inf};
//   rd(X,Y,W,A(X,Y));
//   int dx[4] = {-1, 1, 0, 0};
//   int dy[4] = {0, 0, -1, 1};
//   dimcomp2 dm(X, Y);
//   rep(s,2){
//     rep(i,X*Y) dd[i] = -1;
//     k = if[s==0, 0, dm(X-1,Y-1)];
//     dd[k] = 0;
//     qs = qe = 0;
//     q[qe++] = k;
//     while(qs < qe){
//       k = q[qs++];
//       dm(k, i, j);
//       if(A[i][j] > 0) mn[s] <?= (ll)W*dd[k] + A[i][j];
//       rep(d,4){
//         (ni, nj) = (i + dx[d], j + dy[d]);
//         if(ni < 0 || nj < 0 || ni >= X || nj >= Y || A[ni][nj] == -1) continue;
//         nk = dm(ni, nj);
//         if(dd[nk] >= 0) continue;
//         dd[nk] = dd[k] + 1;
//         q[qe++] = nk;
//       }
//     }
//     if(s==1 && dd[0] >= 0) res <?= (ll)W*dd[0];
//   }
//   res <?= mn[0] + mn[1];
//   if(res==ll_inf) res = -1;
//   wt(res);
// }