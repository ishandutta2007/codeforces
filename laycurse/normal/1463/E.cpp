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
}
;
struct graph{
  int N;
  int*es;
  int**edge;
  void setDirectEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    walloc1d(&edge[0], M, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
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
  int TopologicalSort(int res[], void *mem=wmem){
    int i;
    int j;
    int k;
    int rs;
    int*deg;
    int*q;
    int qs = 0;
    int qe = 0;
    walloc1d(&deg, N, &mem);
    walloc1d(&q, N, &mem);
    rs = 0;
    for(i=(0);i<(N);i++){
      deg[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        deg[edge[i][j]]++;
      }
    }
    for(i=(0);i<(N);i++){
      if(deg[i]==0){
        q[qe++] = i;
      }
    }
    while(qs < qe){
      i = q[qs++];
      res[rs++] = i;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        deg[k]--;
        if(deg[k]==0){
          q[qe++] = k;
        }
      }
    }
    if(rs==N){
      return 1;
    }
    return 0;
  }
}
;
int N;
int K;
int P[300000];
int X[300000];
int Y[300000];
int m;
int a[600000];
int b[600000];
int dist[300000+1];
int f[300000];
int gr[300000];
int tp[300000];
vector<int> gi[300000];
graph g;
int ress;
int res[300000];
int main(){
  int Hjfu7Vx7, i;
  wmem = memarr;
  unionFind uf;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(P[Lj4PdHRW]);P[Lj4PdHRW] += (-1);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(K);e98WHCEY++){
      rd(X[e98WHCEY]);X[e98WHCEY] += (-1);
      rd(Y[e98WHCEY]);Y[e98WHCEY] += (-1);
    }
  }
  uf.walloc(N, 1);
  for(i=(0);i<(K);i++){
    if(uf(X[i],Y[i]) == 0){
      wt_L("0");
      wt_L('\n');
      return 0;
    }
  }
  for(i=(0);i<(N);i++){
    f[i] = 1;
  }
  for(i=(0);i<(K);i++){
    f[Y[i]] = 0;
  }
  for(i=(0);i<(N);i++){
    gr[i] = -1;
  }
  for(i=(0);i<(N);i++){
    if(f[i]){
      gr[uf(i)] = i;
    }
  }
  for(i=(0);i<(K);i++){
    arrInsert(m, m, a, X[i], b, Y[i]);
  }
  for(i=(0);i<(N);i++){
    if(f[i]){
      arrInsert(m, m, a, N, b, i);
    }
  }
  g.setDirectEdge(N+1, m, a, b);
  g.getDist(N, dist);
  m = 0;
  for(i=(0);i<(N);i++){
    if(P[i] != -1){
      arrInsert(m, m, a, P[i], b, i);
    }
  }
  for(i=(0);i<(m);i++){
    if(uf(a[i])==uf(b[i]) && dist[a[i]] > dist[b[i]]){
      wt_L("0");
      wt_L('\n');
      return 0;
    }
  }
  m = 0;
  for(i=(0);i<(N);i++){
    if(P[i] != -1 && uf(P[i]) != uf(i)){
      arrInsert(m, m, a, uf(P[i]), b, uf(i));
    }
  }
  g.setDirectEdge(N, m, a, b);
  if(!g.TopologicalSort(tp)){
    wt_L("0");
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N);i++){
    gi[uf(i)].push_back(i);
  }
  for(i=(0);i<(N);i++){
    gi[uf(i)][dist[i]-1] = i;
  }
  for(Hjfu7Vx7=(0);Hjfu7Vx7<(N);Hjfu7Vx7++){
    int j;
    auto &i = tp[Hjfu7Vx7];
    for(j=(0);j<(gi[i].size());j++){
      res[ress++] = gi[i][j];
    }
  }
  {
    int ytthggxT;
    if(ress==0){
      wt_L('\n');
    }
    else{
      for(ytthggxT=(0);ytthggxT<(ress-1);ytthggxT++){
        wt_L(res[ytthggxT]+ 1);
        wt_L(' ');
      }
      wt_L(res[ytthggxT]+ 1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20201206-1

// --- original code ---
// //no-unlocked
// int N, K, P[3d5], X[3d5], Y[3d5];
// int m, a[6d5], b[6d5];
// int dist[3d5+1], f[3d5], gr[3d5], tp[3d5];
// VI gi[3d5];
// graph g;
// int ress, res[3d5];
// {
//   unionFind uf;
//   rd(N,K,(P--)(N),(X--,Y--)(K));
//   uf.walloc(N, 1);
//   rep(i,K) if(uf(X[i],Y[i]) == 0) wt("0"), return 0;
// 
//   rep(i,N) f[i] = 1;
//   rep(i,K) f[Y[i]] = 0;
//   rep(i,N) gr[i] = -1;
//   rep(i,N) if(f[i]) gr[uf(i)] = i;
// 
//   rep(i,K) arrInsert(m, m, a, X[i], b, Y[i]);
//   rep(i,N) if(f[i]) arrInsert(m, m, a, N, b, i);
//   g.setDirectEdge(N+1, m, a, b);
//   g.getDist(N, dist);
// 
//   m = 0;
//   rep(i,N) if(P[i] != -1) arrInsert(m, m, a, P[i], b, i);
//   rep(i,m) if(uf(a[i])==uf(b[i]) && dist[a[i]] > dist[b[i]]) wt("0"), return 0;
// 
//   m = 0;
//   rep(i,N) if(P[i] != -1 && uf(P[i]) != uf(i)) arrInsert(m, m, a, uf(P[i]), b, uf(i));
//   g.setDirectEdge(N, m, a, b);
//   if(!g.TopologicalSort(tp)) wt("0"), return 0;
// 
//   rep(i,N) gi[uf(i)].push_back(i);
//   rep(i,N) gi[uf(i)][dist[i]-1] = i;
// 
//   rep[tp](i,N) rep(j,gi[i].size()) res[ress++] = gi[i][j];
//   wt(res(ress) + 1);
// }