#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
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
template<class T> int weaklyLIS_length(int n, T a[], void *mem = wmem){
  int i;
  int k;
  int res;
  T*arr;
  if(n==0){
    return 0;
  }
  walloc1d(&arr, n, &mem);
  arr[0] = a[0];
  res = 1;
  int AlM5nNnR = n;
  for(i=(1);i<(AlM5nNnR);i++){
    k = upper_bound(arr, arr+res, a[i]) - arr;
    arr[k] = a[i];
    if(res==k){
      res++;
    }
  }
  return res;
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
int A[500000+2];
int B[500000+2];
int sz;
int arr[500000];
int main(){
  int i, k;
  wmem = memarr;
  int res = 0;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(K);e98WHCEY++){
      rd(B[e98WHCEY]);
    }
  }
  arrInsert(0, N, A, -1073709056);
  arrInsert(N, N, A, 1073709056);
  arrInsert(0, K, B, 0);
  arrInsert(K, K, B, N-1);
  for(i=(0);i<(N);i++){
    A[i] -= i;
  }
  for(k=(1);k<(K);k++){
    if(A[B[k-1]] > A[B[k]]){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
  }
  for(k=(1);k<(K);k++){
    sz = 0;
    for(i=(B[k-1]+1);i<(B[k]);i++){
      if(A[i] < A[B[k-1]] || A[i] > A[B[k]]){
        res++;
        continue;
      }
      arr[sz++] = A[i];
    }
    if(sz){
      res += sz - weaklyLIS_length(sz, arr);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20201102-1

// --- original code ---
// //no-unlocked
// int N, K, A[5d5+2], B[5d5+2];
// int sz, arr[5d5];
// {
//   int res = 0;
//   rd(N,K,A(N),B(K));
//   arrInsert(0, N, A, -int_inf);
//   arrInsert(N, N, A, int_inf);
//   arrInsert(0, K, B, 0);
//   arrInsert(K, K, B, N-1);
// 
//   rep(i,N) A[i] -= i;
//   rep(k,1,K) if(A[B[k-1]] > A[B[k]]) wt(-1), return 0;
//   rep(k,1,K){
//     sz = 0;
//     rep(i,B[k-1]+1,B[k]){
//       if(A[i] < A[B[k-1]] || A[i] > A[B[k]]) res++, continue;
//       arr[sz++] = A[i];
//     }
//     if(sz) res += sz - weaklyLIS_length(sz, arr);
//   }
//   wt(res);
// }