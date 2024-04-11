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
  int anUndirectedCycle(int res[] = NULL, void *mem = wmem){
    int i;
    int j;
    int k;
    int*arr;
    int*q;
    int qs;
    int qe;
    int*bk;
    if(res==NULL){
      walloc1d(&res, N+1, &wmem);
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        if(edge[i][j]==i){
          res[0] = res[1] = i;
          return 1;
        }
      }
    }
    walloc1d(&arr, N, &mem);
    walloc1d(&q, N, &mem);
    walloc1d(&bk, N, &mem);
    for(i=(0);i<(N);i++){
      arr[i] = -1;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(arr[k] == i){
          res[0] = i;
          res[1] = k;
          res[2] = i;
          return 2;
        }
        arr[k] = i;
      }
    }
    for(i=(0);i<(N);i++){
      arr[i] = bk[i] = -1;
    }
    qs = qe = 0;
    q[qe++] = 0;
    arr[0] = 0;
    while(qs < qe){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(arr[k]==-1){
          arr[k] = arr[i] + 1;
          bk[k] = i;
          q[qe++] = k;
          continue;
        }
        if(arr[k] == arr[i] - 1){
          continue;
        }
        qs = qe = 1;
        res[0] = i;
        q[0] = k;
        while(i!=k){
          if(arr[i] > arr[k]){
            res[qs++] = (i = bk[i]);
          }
          else{
            q[qe++] = (k = bk[k]);
          }
        }
        reverse(res, res+qs);
        for(i=(0);i<(qe);i++){
          res[qs++] = q[i];
        }
        return qs - 1;
      }
    }
    return -1;
  }
}
;
int N;
int M;
int A[200000];
int B[200000];
int ps;
int p[200000+1];
int incir[200000];
int sz[200000];
graph g;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  unionFind uf;
  uf.walloc(200000);
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    long long res;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
        rd(B[cTE1_r3A]);B[cTE1_r3A] += (-1);
      }
    }
    for(i=(0);i<(N);i++){
      incir[i] = sz[i] = 0;
    }
    g.setEdge(N,N,A,B);
    ps = g.anUndirectedCycle(p);
    for(i=(0);i<(ps);i++){
      incir[p[i]] = 1;
    }
    uf.init(N);
    for(i=(0);i<(N);i++){
      if(incir[A[i]] == 0 || incir[B[i]] == 0){
        uf(A[i], B[i]);
      }
    }
    for(i=(0);i<(N);i++){
      sz[uf(i)]++;
    }
    res = (long long) N * (N-1);
    for(i=(0);i<(N);i++){
      res -= (long long) sz[i] * (sz[i]-1) / 2;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20201205-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[2d5];
// int ps, p[2d5+1];
// int incir[2d5], sz[2d5];
// graph g;
// {
//   unionFind uf;
//   uf.walloc(2d5);
//   REP(rd_int()){
//     ll res;
//     rd(N,(A--,B--)(N));
//     rep(i,N) incir[i] = sz[i] = 0;
//     g.setEdge(N,N,A,B);
//     ps = g.anUndirectedCycle(p);
//     rep(i,ps) incir[p[i]] = 1;
//     uf.init(N);
//     rep(i,N) if(incir[A[i]] == 0 || incir[B[i]] == 0) uf(A[i], B[i]);
//     rep(i,N) sz[uf(i)]++;
//     res = (ll) N * (N-1);
//     rep(i,N) res -= (ll) sz[i] * (sz[i]-1) / 2;
//     wt(res);
//   }
// }