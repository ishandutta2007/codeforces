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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class T> void arrRot(int k, int N, T A[], T B[] = NULL, void *mem = wmem){
  int i;
  int fg = 0;
  (k = moddw_L(k,N));
  if(B==NULL){
    walloc1d(&B, N, &mem);
    fg = 1;
  }
  for(i=(k);i<(N);i++){
    B[i-k] = A[i];
  }
  for(i=(0);i<(k);i++){
    B[N-k+i] = A[i];
  }
  if(fg){
    for(i=(0);i<(N);i++){
      A[i] = B[i];
    }
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
template <class T> struct DijkstraHeap{
  int*hp;
  int*place;
  int size;
  char*visited;
  T*val;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place = (int*)std::malloc(N*sizeof(int));
    visited = (char*)std::malloc(N*sizeof(char));
    val = (T*)std::malloc(N*sizeof(T));
  }
  void free(){
    std::free(hp);
    std::free(place);
    std::free(visited);
    std::free(val);
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&visited, N, mem);
    walloc1d(&val, N, mem);
  }
  void init(int N){
    int i;
    size = 0;
    for(i=(0);i<(N);i++){
      place[i]=-1;
    }
    for(i=(0);i<(N);i++){
      visited[i]=0;
    }
  }
  void up(int n){
    int m;
    while(n){
      m=(n-1)/2;
      if(val[hp[m]]<=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void down(int n){
    int m;
    for(;;){
      m=2*n+1;
      if(m>=size){
        break;
      }
      if(m+1<size&&val[hp[m]]>val[hp[m+1]]){
        m++;
      }
      if(val[hp[m]]>=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void change(int n, T v){
    if(visited[n]||(place[n]>=0&&val[n]<=v)){
      return;
    }
    val[n]=v;
    if(place[n]==-1){
      place[n]=size;
      hp[size++]=n;
      up(place[n]);
    }
    else{
      up(place[n]);
    }
  }
  int pop(void){
    int res=hp[0];
    place[res]=-1;
    size--;
    if(size){
      hp[0]=hp[size];
      place[hp[0]]=0;
      down(0);
    }
    visited[res]=1;
    return res;
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
}
;
template<class T> struct wgraph{
  int N;
  int*es;
  int**edge;
  T**cost;
  graph g;
  void setEdge(int N__, int M, int A[], int B[], T C[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    walloc1d(&cost, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&cost[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]] = B[i];
      edge[B[i]][es[B[i]]] = A[i];
      cost[A[i]][es[A[i]]++] = C[i];
      cost[B[i]][es[B[i]]++] = C[i];
    }
    g.N = N;
    g.es = es;
    g.edge = edge;
  }
}
;
int N;
int M;
int A[200000];
int B[200000];
int C[200000];
int sm;
int mt[700][700];
int mm;
int aa[200000];
int bb[200000];
int cc[200000];
wgraph<int> g;
set<int> s;
set<int>::iterator it;
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int nx;
  long long res;
  long long r;
  long long tmp;
  unionFind uf;
  DijkstraHeap<int> hp;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
      rd(C[Lj4PdHRW]);
    }
  }
  sortA_L(M,C,A,B);
  for(i=(0);i<(M);i++){
    sm ^= C[i];
  }
  g.setEdge(N,M,A,B,C);
  r = (long long) N * (N-1) / 2 - M;
  if(r >= N){
    res = 0;
    hp.walloc(N);
    hp.init(N);
    hp.change(0,0);
    for(i=(1);i<(N);i++){
      s.insert(i);
    }
    while(hp.size){
      i = hp.pop();
      res += hp.val[i];
      sortA_L(g.es[i], g.edge[i], g.cost[i]);
      if(g.es[i] == 0){
        res = 0;
        break;
      }
      nx = g.edge[i][0];
      while(s.size() && *s.begin() < nx){
        hp.change(*s.begin(), 0);
        s.erase(s.begin());
      }
      for(j=(0);j<(g.es[i]);j++){
        k = g.edge[i][j];
        if(j==g.es[i]-1){
          nx =1073709056;
        }
        else{
          nx =g.edge[i][j+1];
        }
        for(;;){
          it = s.upper_bound(k);
          if(it == s.end() || *it >= nx){
            break;
          }
          hp.change(*it, 0);
          s.erase(it);
        }
        hp.change(k, g.cost[i][j]);
      }
    }
  }
  else{
    int iMWUTgY_;
    res = 4611686016279904256LL;
    mm = 0;
    for(i=(0);i<(M);i++){
      mt[A[i]][B[i]] = mt[B[i]][A[i]] = 1;
    }
    for(i=(0);i<(N);i++){
      for(j=(i+1);j<(N);j++){
        if(mt[i][j]==0){
          arrInsert(mm, mm, aa, i, bb, j);
        }
      }
    }
    cc[mm-1] = sm;
    uf.walloc(N);
    for(iMWUTgY_=(0);iMWUTgY_<(mm);iMWUTgY_++){
      tmp = 0;
      uf.init(N);
      k = 0;
      for(i=(0);i<(M);i++){
        while(k < mm && cc[k] < C[i]){
          if(uf(aa[k],bb[k])){
            tmp += cc[k];
          }
          k++;
        }
        if(uf(A[i],B[i])){
          tmp += C[i];
        }
      }
      chmin(res, tmp);
      arrRot(1, mm, aa);
      arrRot(1, mm, bb);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[], C[], sm;
// int mt[700][700];
// int mm, aa[], bb[], cc[];
// wgraph<int> g;
// set<int> s;
// set<int>::iterator it;
// {
//   int i, j, k, nx;
//   ll res, r, tmp;
//   unionFind uf;
//   DijkstraHeap<int> hp;
//   rd(N,M,(A--,B--,C)(M));
//   sortA(M,C,A,B);
//   rep(i,M) sm ^= C[i];
//   g.setEdge(N,M,A,B,C);
// 
//   r = (ll) N * (N-1) / 2 - M;
//   if(r >= N){
//     res = 0;
//     hp.walloc(N);
//     hp.init(N);
//     hp.change(0,0);
//     rep(i,1,N) s.insert(i);
//     while(hp.size){
//       i = hp.pop();
//       res += hp.val[i];
//       sortA(g.es[i], g.edge[i], g.cost[i]);
//       if(g.es[i] == 0) res = 0, break;
//       nx = g.edge[i][0];
//       while(s.size() && *s.begin() < nx){
//         hp.change(*s.begin(), 0);
//         s.erase(s.begin());
//       }
//       rep(j,g.es[i]){
//         k = g.edge[i][j];
//         nx = if[j==g.es[i]-1, int_inf, g.edge[i][j+1]];
//         for(;;){
//           it = s.upper_bound(k);
//           if(it == s.end() || *it >= nx) break;
//           hp.change(*it, 0);
//           s.erase(it);
//         }
//         hp.change(k, g.cost[i][j]);
//       }
//     }
//   } else {
//     res = ll_inf;
//     mm = 0;
//     rep(i,M) mt[A[i]][B[i]] = mt[B[i]][A[i]] = 1;
//     rep(i,N) rep(j,i+1,N) if(mt[i][j]==0) arrInsert(mm, mm, aa, i, bb, j);
//     cc[mm-1] = sm;
//     uf.walloc(N);
// 
//     rep(mm){
//       tmp = 0;
//       uf.init(N);
//       k = 0;
//       rep(i,M){
//         while(k < mm && cc[k] < C[i]){
//           if(uf(aa[k],bb[k])) tmp += cc[k];
//           k++;
//         }
//         if(uf(A[i],B[i])) tmp += C[i];
//       }
//       res <?= tmp;
//       arrRot(1, mm, aa);
//       arrRot(1, mm, bb);
//     }
//   }
//   wt(res);
// }