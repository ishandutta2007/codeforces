#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
struct graph{
  int N;
  int*es;
  int**edge;
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
  void getDist(int root, int res[], void *mem = wmem){
    int i;
    int j;
    int k;
    int*q;
    int s;
    int z;
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      res[i]=-1;
    }
    res[root]=0;
    s=0;
    z=1;
    q[0]=root;
    while(z){
      i=q[s++];
      z--;
      for(j=(0);j<(es[i]);j++){
        k=edge[i][j];
        if(res[k]>=0){
          continue;
        }
        res[k]=res[i]+1;
        q[s+z++]=k;
      }
    }
  }
  int getDist(int a, int b, void *mem = wmem){
    int i;
    int j;
    int k;
    int*q;
    int s;
    int z;
    int*d;
    if(a==b){
      return 0;
    }
    walloc1d(&d, N, &mem);
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      d[i] = -1;
    }
    d[a] = 0;
    s = 0;
    z = 1;
    q[0] = a;
    while(z){
      i = q[s++];
      z--;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(d[k] >= 0){
          continue;
        }
        d[k] = d[i] + 1;
        if(k==b){
          return d[k];
        }
        q[s+z++] = k;
      }
    }
    return -1;
  }
  int shortestPath(const int s, const int t, int res[], void *mem=wmem){
    int i;
    int j;
    int k;
    int*q;
    int qs = 0;
    int qe = 0;
    int*b;
    walloc1d(&b, N, &mem);
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      b[i] = -1;
    }
    b[s] = -2;
    q[qe++] = s;
    while(qe > qs){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(b[k]!=-1){
          continue;
        }
        b[k] = i;
        q[qe++] = k;
      }
      if(b[t]!=-1){
        break;
      }
    }
    if(b[t]==-1){
      return -1;
    }
    k = 0;
    res[k] = i = t;
    while(i != s){
      res[++k] = (i = b[i]);
    }
    std::reverse(res, res+k+1);
    return k;
  }
}
;
int main(){
  wmem = memarr;
  int N;
  rd(N);
  int M;
  rd(M);
  int Q;
  int A[300000];
  int B[300000];
  int i;
  int j;
  int k;
  int x;
  int y;
  unionFind uf;
  graph g;
  int ps;
  int p[N+1];
  int cnt[N] = {};
  int chk[N];
  int d[N];
  int s;
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
    }
  }
  uf.walloc(N,1);
  k = 0;
  for(i=(0);i<(M);i++){
    if(uf(A[i],B[i])){
      arrInsert(k,k,A,A[i],B,B[i]);
    }
  }
  g.setEdge(N,N-1,A,B);
  g.getDist(0,d);
  rd(Q);
  {
    int RZTsC2BF;
    for(RZTsC2BF=(0);RZTsC2BF<(Q);RZTsC2BF++){
      rd(A[RZTsC2BF]);A[RZTsC2BF] += (-1);
      rd(B[RZTsC2BF]);B[RZTsC2BF] += (-1);
    }
  }
  for(i=(0);i<(Q);i++){
    ps = g.shortestPath(A[i], B[i], p);
    for(j=(0);j<(ps);j++){
      auto tU__gIr_ = ((p[j]));
      auto a2conNHc = (( p[j+1]));
      x=tU__gIr_;
      y=a2conNHc;
      if(d[x] < d[y]){
        swap(x, y);
      }
      cnt[x] ^= 1;
    }
  }
  int hCmBdyQB;
  cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type V9aVTaxx;
  if(N==0){
    V9aVTaxx = 0;
  }
  else{
    V9aVTaxx = cnt[0];
    for(hCmBdyQB=(1);hCmBdyQB<(N);hCmBdyQB++){
      V9aVTaxx += cnt[hCmBdyQB];
    }
  }
  s =V9aVTaxx;
  if(s){
    for(i=(0);i<(N);i++){
      chk[i] = cnt[i];
    }
    for(i=(0);i<(N);i++){
      int AlM5nNnR;
      for(AlM5nNnR=(0);AlM5nNnR<(g.es[i]);AlM5nNnR++){
        auto&j = g.edge[i][AlM5nNnR];
        if(d[i] < d[j]){
          chk[i] ^= cnt[j];
        }
      }
    }
    int BUotOFBp;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type Q5rsz4fz;
    if(N==0){
      Q5rsz4fz = 0;
    }
    else{
      Q5rsz4fz = chk[0];
      for(BUotOFBp=(1);BUotOFBp<(N);BUotOFBp++){
        Q5rsz4fz += chk[BUotOFBp];
      }
    }
    s =Q5rsz4fz;
    wt_L("NO");
    wt_L('\n');
    wt_L(s/2);
    wt_L('\n');
    return 0;
  }
  wt_L("YES");
  wt_L('\n');
  for(i=(0);i<(Q);i++){
    ps = g.shortestPath(A[i], B[i], p);
    wt_L(ps+1);
    wt_L('\n');
    {
      int zT28qSmp;
      if(ps+1==0){
        wt_L('\n');
      }
      else{
        for(zT28qSmp=(0);zT28qSmp<(ps+1-1);zT28qSmp++){
          wt_L(p[zT28qSmp]+1);
          wt_L(' ');
        }
        wt_L(p[zT28qSmp]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int @N, @M, Q, A[3d5], B[];
// int i, j, k, x, y;
// unionFind uf;
// graph g;
// int ps, p[N+1], cnt[N] = {}, chk[N], d[N], s;
// 
// rd((A--,B--)(M));
// uf.walloc(N,1);
// k = 0;
// rep(i,M) if(uf(A[i],B[i])) arrInsert(k,k,A,A[i],B,B[i]);
// g.setEdge(N,N-1,A,B);
// g.getDist(0,d);
// 
// rd(Q,(A--,B--)(Q));
// rep(i,Q){
//   ps = g.shortestPath(A[i], B[i], p);
//   rep(j,ps){
//     (x, y) = (p[j], p[j+1]);
//     if(d[x] < d[y]) swap(x, y);
//     cnt[x] ^= 1;
//   }
// }
// s = sum(cnt(N));
// if(s){
//   rep(i,N) chk[i] = cnt[i];
//   rep(i,N) rep[g.edge[i]](j,g.es[i]) if(d[i] < d[j]) chk[i] ^= cnt[j];
//   s = sum(chk(N));
//   wt("NO");
//   wt(s/2);
//   return 0;
// }
// 
// wt("YES");
// rep(i,Q){
//   ps = g.shortestPath(A[i], B[i], p);
//   wt(ps+1);
//   wt(p(ps+1)+1);
// }