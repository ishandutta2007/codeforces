#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[41943040];
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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
}
void sortF_L(int N, unsigned A[], void *mem = wmem){
  int i;
  int m;
  int bt;
  unsigned*arr;
  unsigned c;
  int*sz;
  if(N < 256){
    sort(A, A+N);
    return;
  }
  bt = sizeof(unsigned) * 8;
  walloc1d(&arr, N, &mem);
  walloc1d(&sz, N, &mem);
  for(m=0;m<bt;m+=8){
    for(i=(0);i<(257);i++){
      sz[i] = 0;
    }
    for(i=(0);i<(N);i++){
      sz[ 1+((A[i]>>m)&255u) ]++;
    }
    for(i=(1);i<(257);i++){
      sz[i] += sz[i-1];
    }
    for(i=(0);i<(N);i++){
      c = ((A[i]>>m)&255u);
      arr[sz[c]++] = A[i];
    }
    swap(A, arr);
  }
}
void sortF_L(int N, int A[], void *mem = wmem){
  int i;
  int x;
  int y;
  int z;
  int*arr;
  unsigned*send;
  if(N < 256){
    sort(A, A+N);
    return;
  }
  send = (unsigned*)A;
  sortF_L(N, send, mem);
  if(A[0] < 0 || A[N-1] >= 0){
    return;
  }
  x = 0;
  y = N;
  while(x < y){
    z = (x+y) / 2;
    if(A[z] < 0){
      y = z;
    }
    else{
      x = z+1;
    }
  }
  walloc1d(&arr, N, &mem);
  z = 0;
  for(i=(x);i<(N);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(x);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(N);i++){
    A[i] = arr[i];
  }
}
void sortF_L(int N, unsigned long long A[], void *mem = wmem){
  int i;
  int m;
  int bt;
  unsigned long long*arr;
  unsigned c;
  int*sz;
  if(N < 512){
    sort(A, A+N);
    return;
  }
  bt = sizeof(unsigned long long) * 8;
  walloc1d(&arr, N, &mem);
  walloc1d(&sz, N, &mem);
  for(m=0;m<bt;m+=8){
    for(i=(0);i<(257);i++){
      sz[i] = 0;
    }
    for(i=(0);i<(N);i++){
      sz[ 1+((A[i]>>m)&255u) ]++;
    }
    for(i=(1);i<(257);i++){
      sz[i] += sz[i-1];
    }
    for(i=(0);i<(N);i++){
      c = ((A[i]>>m)&255u);
      arr[sz[c]++] = A[i];
    }
    swap(A, arr);
  }
}
void sortF_L(int N, long long A[], void *mem = wmem){
  int i;
  int x;
  int y;
  int z;
  long long*arr;
  unsigned long long*send;
  if(N < 512){
    sort(A, A+N);
    return;
  }
  send = (unsigned long long*)A;
  sortF_L(N, send, mem);
  if(A[0] < 0 || A[N-1] >= 0){
    return;
  }
  x = 0;
  y = N;
  while(x < y){
    z = (x+y) / 2;
    if(A[z] < 0){
      y = z;
    }
    else{
      x = z+1;
    }
  }
  walloc1d(&arr, N, &mem);
  z = 0;
  for(i=(x);i<(N);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(x);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(N);i++){
    A[i] = arr[i];
  }
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
inline void rd(long long &x){
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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
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
struct unionFind{
  int*d;
  int N;
  int M;
  unionFind(){
  }
  unionFind(const char mode, const int n, void **mem = &wmem){
    if(mode == 'm'){
      malloc(n);
    }
    if(mode == 'w'){
      walloc(n, mem);
    }
  }
  unionFind(const char mode, const int n, const int fg, void **mem = &wmem){
    if(mode == 'm'){
      malloc(n, fg);
    }
    if(mode == 'w'){
      walloc(n, fg, mem);
    }
  }
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
  inline int comp(int res[], void *mem = wmem){
    int i;
    int sz=0;
    int*cnt;
    walloc1d(&cnt, N, &mem);
    for(i=(0);i<(N);i++){
      cnt[i] = 0;
    }
    for(i=(0);i<(N);i++){
      cnt[get(i)] = 1;
    }
    for(i=(0);i<(N);i++){
      if(cnt[i]){
        cnt[i] = sz++;
      }
    }
    for(i=(0);i<(N);i++){
      res[i] = cnt[get(i)];
    }
    return sz;
  }
}
;
template<class T> void Unique(int &N, T A[], int sorted=0){
  int i;
  int k;
  if(!sorted){
    sort(A, A+N);
  }
  k = 0;
  for(i=(0);i<(N);i++){
    if(k==0 || A[k-1]!=A[i]){
      A[k++] = A[i];
    }
  }
  N = k;
}
template<class T, class S> void Unique(int &N, T A[], S B[], int sorted=0, void *mem = wmem){
  int i;
  int k = 0;
  if(!sorted){
    sortA_L(N, A, B, mem);
  }
  for(i=(0);i<(N);i++){
    if(!k || A[k-1]!=A[i]){
      A[k] = A[i];
      B[k] = B[i];
      k++;
    }
    else{
      B[k-1] += B[i];
    }
  }
  N=k;
}
int N;
int M;
int U[300];
int V[300];
long long W[300];
long long P;
long long K;
long long A;
long long B;
long long C;
int Q[10000000];
int sz;
long long sh[200000];
long long val[200000];
unionFind uf;
int mm;
int aa[300];
int bb[300];
long long cc[300];
long long solve(long long x){
  int i;
  uf.init(N);
  long long res = 0;
  mm = 0;
  for(i=(0);i<(M);i++){
    arrInsert(mm, mm, aa, U[i], bb, V[i], cc, abs(x-W[i]));
  }
  sortA_L(M,cc,aa,bb);
  for(i=(0);i<(M);i++){
    if(uf(aa[i],bb[i])){
      res += cc[i];
    }
  }
  return res;
}
long long solve2(long long x){
  static int i;
  while(sh[i+1] < x){
    i++;
  }
  return val[i] + (val[i+1] - val[i]) / (sh[i+1] - sh[i]) * (x - sh[i]);
}
int main(){
  int i;
  wmem = memarr;
  long long res = 0;
  rd(N);
  rd(M);
  {
    int R5MtCiij;
    for(R5MtCiij=(0);R5MtCiij<(M);R5MtCiij++){
      rd(U[R5MtCiij]);U[R5MtCiij] += (-1);
      rd(V[R5MtCiij]);V[R5MtCiij] += (-1);
      rd(W[R5MtCiij]);
    }
  }
  rd(P);
  rd(K);
  rd(A);
  rd(B);
  rd(C);
  {
    int ATMZloZo;
    for(ATMZloZo=(0);ATMZloZo<(P);ATMZloZo++){
      rd(Q[ATMZloZo]);
    }
  }
  uf.walloc(N);
  for(i=(P);i<(K);i++){
    Q[i] = (Q[i-1] * A + B) % C;
  }
  sortF_L(K,Q);
  sh[sz++] =0;
  sh[sz++] =100000000;
  for(i=(0);i<(M);i++){
    sh[sz++] = W[i];
  }
  for(i=(0);i<(M);i++){
    int j;
    for(j=(i+1);j<(M);j++){
      sh[sz++] = (W[i] + W[j] +0) / 2;
      sh[sz++] = (W[i] + W[j] +1) / 2;
    }
  }
  Unique(sz, sh);
  for(i=(0);i<(sz);i++){
    val[i] = solve(sh[i]);
  }
  for(i=(0);i<(K);i++){
    res ^= solve2(Q[i]);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220116-1 [+beta]

// --- original code ---
// //no-unlocked
// //working_memory=40m
// int N, M, U[300], V[300]; ll W[300];
// ll P, K, A, B, C; int Q[1d7];
// 
// int sz; ll sh[2d5], val[2d5];
// 
// unionFind uf;
// int mm, aa[300], bb[300]; ll cc[300];
// 
// ll solve(ll x){
//   uf.init(N);
//   ll res = 0;
//   mm = 0;
//   rep(i,M) arrInsert(mm, mm, aa, U[i], bb, V[i], cc, abs(x-W[i]));
//   sortA(M,cc,aa,bb);
//   rep(i,M) if(uf(aa[i],bb[i])) res += cc[i];
//   return res;
// }
// 
// ll solve2(ll x){
//   static int i;
//   while(sh[i+1] < x) i++;
//   return val[i] + (val[i+1] - val[i]) / (sh[i+1] - sh[i]) * (x - sh[i]);
// }
// 
// {
//   ll res = 0;
//   rd(N,M,(U--,V--,W)(M),P,K,A,B,C,Q(P));
//   uf.walloc(N);
//   rep(i,P,K) Q[i] = (Q[i-1] * A + B) % C;
//   sortF(K,Q);
// 
//   sh[sz++] = @[0,1d8];
//   rep(i,M) sh[sz++] = W[i];
//   rep(i,M) rep(j,i+1,M) sh[sz++] = (W[i] + W[j] + @[0,1]) / 2;
//   Unique(sz, sh);
//   rep(i,sz) val[i] = solve(sh[i]);
//   rep(i,K) res ^= solve2(Q[i]);
//   wt(res);
// }