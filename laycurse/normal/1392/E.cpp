#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
int Q;
long long A[26][26];
long long K;
long long pw[61];
int ress;
int resx[100];
int resy[100];
int main(){
  int hCmBdyQB;
  int i;
  int j;
  int k;
  int i1;
  int i2;
  int j1;
  int j2;
  pw[1] = 1;
  for(i=(2);i<(61);i++){
    pw[i] = 2 * pw[i-1];
  }
  scanf("%d",&N);
  for(i=(0);i<(N);i+=(2)){
    for(j=(0);j<(N);j++){
      A[i][j] = pw[i+j];
    }
  }
  for(i=(0);i<(N+1);i++){
    A[i][N] = pw[60];
  }
  for(i=(0);i<(N+1);i++){
    A[N][i] = pw[60];
  }
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N);j++){
      if(j==N-1){
        printf("%lld%c", A[i][j],'\n');
      }
      else{
        printf("%lld%c", A[i][j],' ');
      }
    }
  }
  fflush(stdout);
  scanf("%d",&Q);
  for(hCmBdyQB=(0);hCmBdyQB<(Q);hCmBdyQB++){
    scanf("%lld",&K);
    i = j = 0;
    ress = 0;
    arrInsert(ress, ress, resx, i, resy, j);
    while(i != N-1 || j != N-1){
      {
        auto jbtyPBGc = (i+1);
        auto ZIeRIny5 = ( j);
        i1 = jbtyPBGc;
        j1 = ZIeRIny5;
      }
      {
        auto iMWUTgY_ = (i);
        auto AlM5nNnR = ( j+1);
        i2 = iMWUTgY_;
        j2 = AlM5nNnR;
      }
      if(!A[i1][j1]){
        swap(i1,i2);
        swap(j1,j2);
      }
      if(A[i1][j1]&K){
        {
          auto XJIcIBrW = (i1);
          auto jPV_0s1p = (j1);
          i = XJIcIBrW;
          j = jPV_0s1p;
        }
      }
      else{
        {
          auto BUotOFBp = (i2);
          auto Q5rsz4fz = (j2);
          i = BUotOFBp;
          j = Q5rsz4fz;
        }
      }
      arrInsert(ress, ress, resx, i, resy, j);
    }
    for(i=(0);i<(ress);i++){
      printf("%d %d\n", resx[i]+1, resy[i]+1);
    }
    fflush(stdout);
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// int N, Q;
// ll A[26][26], K;
// ll pw[61];
// int ress, resx[100], resy[100];
// {
//   int i, j, k;
//   int i1, i2, j1, j2;
//   pw[1] = 1;
//   rep(i,2,61) pw[i] = 2 * pw[i-1];
//   scanf("%d",&N);
//   rep(i,0,N,2) rep(j,N) A[i][j] = pw[i+j];
//   rep(i,N+1) A[i][N] = pw[60];
//   rep(i,N+1) A[N][i] = pw[60];
//   rep(i,N) rep(j,N) printf("%lld%c", A[i][j], if[j==N-1,'\n',' ']);
//   fflush(stdout);
//   scanf("%d",&Q);
//   rep(Q){
//     scanf("%lld",&K);
//     i = j = 0;
//     ress = 0;
//     arrInsert(ress, ress, resx, i, resy, j);
//     while(i != N-1 || j != N-1){
//       (i1, j1) = (i+1, j);
//       (i2, j2) = (i, j+1);
//       if(!A[i1][j1]) swap(i1,i2), swap(j1,j2);
//       (i,j) = if[A[i1][j1]&K, (i1,j1), (i2,j2)];
//       arrInsert(ress, ress, resx, i, resy, j);
//     }
//     rep(i,ress) printf("%d %d\n", resx[i]+1, resy[i]+1);
//     fflush(stdout);
//   }
// }