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
struct unionFind{
  int*d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void malloc(const int n, const int fg){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
    if(fg){
      init(n);
    }
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void walloc(const int n, const int fg, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
    if(fg){
      init(n);
    }
  }
  inline void init(const int n){
    int i;
    N = n;
    for(i=(0);i<(n);i++){
      d[i] = -1;
    }
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    int t = a;
    int k;
    while(d[t]>=0){
      t=d[t];
    }
    while(d[a]>=0){
      k=d[a];
      d[a]=t;
      a=k;
    }
    return a;
  }
  inline int connect(int a, int b){
    if(d[a]>=0){
      a=get(a);
    }
    if(d[b]>=0){
      b=get(b);
    }
    if(a==b){
      return 0;
    }
    if(d[a] < d[b]){
      d[a] += d[b];
      d[b] = a;
    }
    else{
      d[b] += d[a];
      d[a] = b;
    }
    return 1;
  }
  inline int operator()(int a){
    return get(a);
  }
  inline int operator()(int a, int b){
    return connect(a,b);
  }
  inline int& operator[](const int a){
    return d[a];
  }
  inline int size(int a){
    a = get(a);
    return -d[a];
  }
  inline int sizeList(int res[]){
    int i;
    int sz=0;
    for(i=(0);i<(N);i++){
      if(d[i]<0){
        res[sz++] = -d[i];
      }
    }
    return sz;
  }
}
;
int K;
int A[500][500];
int m;
int x[1000];
int y[1000];
int c[1000];
int sz;
int arr[1000];
int solve(int sz, int arr[]){
  int i;
  int mx = 0;
  int r;
  int s;
  int*a;
  unionFind uf;
  if(sz==1){
    return arr[0];
  }
  uf.walloc(sz);
  walloc1d(&a, sz);
  for(i=(1);i<(sz);i++){
    chmax(mx, A[arr[0]][arr[i]]);
  }
  r = K++;
  c[r] = mx;
  uf.init(sz);
  for(i=(0);i<(sz);i++){
    int j;
    for(j=(i+1);j<(sz);j++){
      if(A[arr[i]][arr[j]] < mx){
        uf(i,j);
      }
    }
  }
  for(i=(0);i<(sz);i++){
    int j;
    s = 0;
    for(j=(0);j<(sz);j++){
      if(uf(j) == i){
        a[s++] = arr[j];
      }
    }
    if(!s){
      continue;
    }
    arrInsert(m, m, x, solve(s, a), y, r);
  }
  return r;
}
int main(){
  int i;
  wmem = memarr;
  rd(K);
  {
    int KrdatlYV;
    int ao_dF3pO;
    for(KrdatlYV=(0);KrdatlYV<(K);KrdatlYV++){
      for(ao_dF3pO=(0);ao_dF3pO<(K);ao_dF3pO++){
        rd(A[KrdatlYV][ao_dF3pO]);
      }
    }
  }
  for(i=(0);i<(K);i++){
    c[i] = A[i][i];
  }
  for(i=(0);i<(K);i++){
    arr[sz++] = i;
  }
  int r = solve(sz, arr);
  wt_L(K);
  wt_L('\n');
  {
    int ZIeRIny5;
    if(K==0){
      wt_L('\n');
    }
    else{
      for(ZIeRIny5=(0);ZIeRIny5<(K-1);ZIeRIny5++){
        wt_L(c[ZIeRIny5]);
        wt_L(' ');
      }
      wt_L(c[ZIeRIny5]);
      wt_L('\n');
    }
  }
  wt_L(r+1);
  wt_L('\n');
  for(i=(0);i<(m);i++){
    wt_L(x[i]+1);
    wt_L(' ');
    wt_L(y[i]+1);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int K, A[500][500];
// int m, x[1000], y[], c[];
// int sz, arr[1000];
// 
// int solve(int sz, int arr[]){
//   int mx = 0, r;
//   int s, *a;
//   unionFind uf;
//   if(sz==1) return arr[0];
// 
//   uf.walloc(sz);
//   walloc1d(&a, sz);
// 
//   rep(i,1,sz) mx >?= A[arr[0]][arr[i]];
//   r = K++;
//   c[r] = mx;
// 
//   uf.init(sz);
//   rep(i,sz) rep(j,i+1,sz) if(A[arr[i]][arr[j]] < mx) uf(i,j);
// 
//   rep(i,sz){
//     s = 0;
//     rep(j,sz) if(uf(j) == i) a[s++] = arr[j];
//     if(!s) continue;
//     arrInsert(m, m, x, solve(s, a), y, r);
//   }
// 
//   return r;
// }
// 
// {
//   rd(K,A(K,K));
//   rep(i,K) c[i] = A[i][i];
// 
//   rep(i,K) arr[sz++] = i;
//   int r = solve(sz, arr);
// 
//   wt(K);
//   wt(c(K));
//   wt(r+1);
//   rep(i,m) wt(x[i]+1, y[i]+1);
// }