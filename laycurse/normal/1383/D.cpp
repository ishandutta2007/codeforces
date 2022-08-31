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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int M;
int A[250][250];
int rm[250];
int cm[250];
int ind[100000];
int r[100000];
int c[100000];
int qs;
int qr[100000];
int qc[100000];
void doit(int rr, int cc, int v){
  int di;
  int dj;
  int i;
  int j;
  A[rr][cc] = v;
  for(di=(-2);di<(3);di++){
    for(dj=(-2);dj<(3);dj++){
      i = rr + di;
      j = cc + dj;
      if(i < 0 || i >= N || j < 0 || j >= M || A[i][j] != -1){
        continue;
      }
      if(i-1 >= 0 && j+1 < M && A[i-1][j] >= 0 && A[i][j+1] >= 0){
        A[i][j] = -2;
        arrInsert(qs, qs, qr, i, qc, j);
        continue;
      }
      if(i+1 < N && j-1 >= 0 && A[i+1][j] >= 0 && A[i][j-1] >= 0){
        A[i][j] = -2;
        arrInsert(qs, qs, qr, i, qc, j);
        continue;
      }
    }
  }
}
int main(){
  int i;
  int rr = 0;
  int cc = 0;
  rd(N);
  rd(M);
  {
    int cTE1_r3A;
    int RZTsC2BF;
    for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
      for(RZTsC2BF=(0);RZTsC2BF<(M);RZTsC2BF++){
        rd(A[cTE1_r3A][RZTsC2BF]);A[cTE1_r3A][RZTsC2BF] += (-1);
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(M);j++){
      chmax(rm[i], A[i][j]);
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(M);j++){
      chmax(cm[j], A[i][j]);
    }
  }
  for(i=(0);i<(N);i++){
    r[rm[i]] = 1;
  }
  for(i=(0);i<(M);i++){
    c[cm[i]] = 1;
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(M);j++){
      A[i][j] = -1;
    }
  }
  for(i=(N*M)-1;i>=(0);i--){
    if(r[i] && c[i]){
      doit(rr++, cc++, i);
      continue;
    }
    if(r[i]){
      doit(rr++, cc-1, i);
      continue;
    }
    if(c[i]){
      doit(rr-1, cc++, i);
      continue;
    }
    qs--;
    doit(qr[qs], qc[qs], i);
  }
  {
    int gEg5UqEA;
    int qSsg05KM;
    for(gEg5UqEA=(0);gEg5UqEA<(N);gEg5UqEA++){
      if(M==0){
        wt_L('\n');
      }
      else{
        for(qSsg05KM=(0);qSsg05KM<(M-1);qSsg05KM++){
          wt_L(A[gEg5UqEA][qSsg05KM]+1);
          wt_L(' ');
        }
        wt_L(A[gEg5UqEA][qSsg05KM]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, A[250][250];
// int rm[250], cm[250], ind[1d5];
// int r[1d5], c[1d5];
// int qs, qr[1d5], qc[1d5];
// 
// void doit(int rr, int cc, int v){
//   int di, dj, i, j;
//   A[rr][cc] = v;
//   rep(di,-2,3) rep(dj,-2,3){
//     i = rr + di;
//     j = cc + dj;
//     if(i < 0 || i >= N || j < 0 || j >= M || A[i][j] != -1) continue;
//     if(i-1 >= 0 && j+1 < M && A[i-1][j] >= 0 && A[i][j+1] >= 0){
//       A[i][j] = -2;
//       arrInsert(qs, qs, qr, i, qc, j);
//       continue;
//     }
//     if(i+1 < N && j-1 >= 0 && A[i+1][j] >= 0 && A[i][j-1] >= 0){
//       A[i][j] = -2;
//       arrInsert(qs, qs, qr, i, qc, j);
//       continue;
//     }
//   }
// }
// 
// {
//   int rr = 0, cc = 0;
//   rd(N,M,(A--)(N,M));
//   // N = 6;
//   // M = 12;
//   // rep(i,N*M) ind[i] = i;
//   // random_shuffle(ind, ind+N*M);
//   // rep(i,N) rep(j,M) A[i][j] = ind[i*M+j];
// 
//   rep(i,N) rep(j,M) rm[i] >?= A[i][j];
//   rep(i,N) rep(j,M) cm[j] >?= A[i][j];
//   rep(i,N) r[rm[i]] = 1;
//   rep(i,M) c[cm[i]] = 1;
// 
//   rep(i,N) rep(j,M) A[i][j] = -1;
// 
//   rrep(i,N*M){
//     if(r[i] && c[i]) doit(rr++, cc++, i), continue;
//     if(r[i]) doit(rr++, cc-1, i), continue;
//     if(c[i]) doit(rr-1, cc++, i), continue;
//     qs--; doit(qr[qs], qc[qs], i);
//   }
// 
//   wt(A(N,M)+1);
// }