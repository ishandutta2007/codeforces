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
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
void*wmem;
char memarr[96000000];
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
template<class T> struct fenwick{
  int size;
  int memory;
  T*data;
  void malloc(int mem);
  void malloc(int mem, int fg);
  void walloc(int mem, void **workMemory = &wmem);
  void walloc(int mem, int fg, void **workMemory = &wmem);
  void free(void);
  void init(int N);
  void add(int k, T val);
  T get(int k);
  T range(int a, int b);
  int kth(T k);
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
struct HLD{
  int N;
  int*es;
  int**edge;
  int*group;
  int*groupind;
  int groupNum;
  int*groupSize;
  int**groupNode;
  int*groupUpNode;
  int*groupDepth;
  void init(graph g, void **mem = &wmem){
    init(g.N, g.es, g.edge, mem);
  }
  void init(int N__, int *es__, int **edge__, void **mem = &wmem){
    int i;
    int j;
    int k;
    int x;
    int y;
    int mx;
    int*q;
    int q_st;
    int q_ed;
    int*sz;
    char*vis;
    void*tmpmem;
    N = N__;
    es = es__;
    edge = edge__;
    walloc1d(&group, N, mem);
    walloc1d(&groupind, N, mem);
    tmpmem = *mem;
    walloc1d(&q, N, &tmpmem);
    walloc1d(&sz, N, &tmpmem);
    walloc1d(&vis, N, &tmpmem);
    for(i=(0);i<(N);i++){
      vis[i] = 0;
    }
    q_st = 0;
    q_ed = 1;
    q[0] = 0;
    vis[0] = 1;
    while(q_st < q_ed){
      i = q[q_st++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(!vis[k]){
          vis[k] = 1;
          q[q_ed++] = k;
        }
      }
    }
    for(i=(0);i<(N);i++){
      sz[i] = 0;
    }
    for(j=N-1;j>=0;j--){
      i = q[j];
      sz[i] = 1;
      for(k=(0);k<(es[i]);k++){
        sz[i] += sz[edge[i][k]];
      }
    }
    for(i=(0);i<(N);i++){
      group[i] = -1;
    }
    groupNum = 0;
    for(j=(0);j<(N);j++){
      i = q[j];
      if(group[i]>=0){
        continue;
      }
      group[i] = groupNum++;
      groupind[i] = 0;
      for(;;){
        mx = -1;
        for(k=(0);k<(es[i]);k++){
          if(group[edge[i][k]] != -1){
            continue;
          }
          if(mx==-1){
            mx = k;
          }
          else if(sz[edge[i][k]] > sz[edge[i][mx]]){
            mx = k;
          }
        }
        if(mx==-1){
          break;
        }
        group[edge[i][mx]] = group[i];
        groupind[edge[i][mx]] = groupind[i]+1;
        i = edge[i][mx];
      }
    }
    walloc1d(&groupSize, groupNum, mem);
    walloc1d(&groupUpNode, groupNum, mem);
    walloc1d(&groupDepth, groupNum, mem);
    for(i=(0);i<(groupNum);i++){
      groupSize[i] = 0;
    }
    for(i=(0);i<(N);i++){
      groupSize[group[i]]++;
    }
    walloc1d(&groupNode, groupNum, mem);
    for(i=(0);i<(groupNum);i++){
      walloc1d(&groupNode[i], groupSize[i], mem);
    }
    for(i=(0);i<(N);i++){
      groupNode[group[i]][groupind[i]] = i;
    }
    for(i=(0);i<(groupNum);i++){
      groupDepth[i] = -1;
    }
    groupUpNode[0] = -1;
    groupDepth[0] = 0;
    for(x=(0);x<(groupNum);x++){
      for(y=(0);y<(groupSize[x]);y++){
        i = groupNode[x][y];
        for(j=(0);j<(es[i]);j++){
          k = edge[i][j];
          if(x != group[k] && groupDepth[group[k]]==-1){
            groupUpNode[group[k]] = i;
            groupDepth[group[k]] = groupDepth[x] + 1;
          }
        }
      }
    }
  }
  int lca(int x, int y){
    int x1;
    int y1;
    int x2;
    int y2;
    x1 = group[x];
    x2 = groupind[x];
    y1 = group[y];
    y2 = groupind[y];
    while(groupDepth[x1] > groupDepth[y1]){
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    while(groupDepth[x1] < groupDepth[y1]){
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    while(x1 != y1){
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    if(x2 <= y2){
      return x;
    }
    return y;
  }
  int depth(int x){
    int x1;
    int x2;
    int res = 0;
    x1 = group[x];
    x2 = groupind[x];
    while(groupUpNode[x1] != -1){
      res += x2 + 1;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    return res + x2;
  }
  int dist(int x, int y){
    int x1;
    int y1;
    int x2;
    int y2;
    int res = 0;
    x1 = group[x];
    x2 = groupind[x];
    y1 = group[y];
    y2 = groupind[y];
    while(groupDepth[x1] > groupDepth[y1]){
      res += x2 + 1;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    while(groupDepth[x1] < groupDepth[y1]){
      res += y2 + 1;
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    while(x1 != y1){
      res += x2 + y2 + 2;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    if(x2 <= y2){
      return res + y2 - x2;
    }
    return res + x2 - y2;
  }
  int up(int x){
    int x1 = group[x];
    int x2 = groupind[x];
    if(x2==0){
      return groupUpNode[x1];
    }
    return groupNode[x1][x2-1];
  }
  int up(int x, int d){
    int x1 = group[x];
    int x2 = groupind[x];
    while(d > x2){
      if(groupUpNode[x1]==-1){
        return -1;
      }
      d -= x2 + 1;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    return groupNode[x1][x2-d];
  }
}
;
template<class T> struct HLD_fenwick{
  HLD*hld;
  fenwick<T>*fen;
  void init(HLD *hld__, void **mem = &wmem){
    int i;
    int j;
    hld = hld__;
    walloc1d(&fen, hld->groupNum, mem);
    for(i=(0);i<(hld->groupNum);i++){
      fen[i].walloc(hld->groupSize[i], mem);
      fen[i].init(hld->groupSize[i]);
    }
  }
  inline void add(int u, T val){
    int ug;
    int ui;
    ug = hld->group[u];
    ui = hld->groupind[u];
    fen[ug].add(ui, val);
  }
  inline T get(int u, int v){
    T res;
    int ug;
    int vg;
    int ui;
    int vi;
    ug = hld->group[u];
    vg = hld->group[v];
    res = 0;
    while(ug != vg){
      if(hld->groupDepth[ug] < hld->groupDepth[vg]){
        swap(u, v);
        swap(ug, vg);
      }
      res += fen[ug].get(hld->groupind[u]);
      u = hld->groupUpNode[ug];
      ug = hld->group[u];
    }
    ui = hld->groupind[u];
    vi = hld->groupind[v];
    res += fen[ug].range(min_L(ui, vi),max_L(ui, vi));
    return res;
  }
}
;
int N;
int K;
int A[400000+2];
int B[400000+2];
int mm;
int aa[400000+2];
int bb[400000+2];
int dup[400000+2];
graph g;
HLD hld;
HLD_fenwick<int> f;
char S[400000+2];
char res[400000+2];
int ress;
int arr[400000+2];
int sz;
int doit[400000+2];
void dfs(int n){
  if(n==-1){
    return;
  }
  dfs(A[n]);
  arr[sz++] = n;
  dfs(B[n]);
}
int getdep(int n){
  int k;
  int Lj4PdHRW;
  int KL2GvlyY;
  int Q5VJL1cS;
  Lj4PdHRW = 0;
  KL2GvlyY = N+1;
  while(Lj4PdHRW < KL2GvlyY){
    if((Lj4PdHRW + KL2GvlyY)%2==0){
      Q5VJL1cS = (Lj4PdHRW + KL2GvlyY) / 2;
    }
    else{
      Q5VJL1cS = (Lj4PdHRW + KL2GvlyY - 1) / 2;
    }
    k = hld.up(n,Q5VJL1cS);
    if(k==-1 || dup[k]){
      KL2GvlyY = Q5VJL1cS;
    }
    else{
      Lj4PdHRW = Q5VJL1cS + 1;
    }
  }
  return KL2GvlyY;
}
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int m;
  rd(N);
  rd(K);
  rd(S);
  {
    int RZTsC2BF;
    for(RZTsC2BF=(0);RZTsC2BF<(N);RZTsC2BF++){
      rd(A[RZTsC2BF]);A[RZTsC2BF] += (-1);
      rd(B[RZTsC2BF]);B[RZTsC2BF] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    if(A[i] >= 0){
      arrInsert(mm, mm, aa, i, bb, A[i]);
    }
  }
  for(i=(0);i<(N);i++){
    if(B[i] >= 0){
      arrInsert(mm, mm, aa, i, bb, B[i]);
    }
  }
  g.setEdge(N,mm,aa,bb);
  hld.init(g);
  f.init(&hld);
  dfs(0);
  for(i=(N-1)-1;i>=(0);i--){
    if(S[arr[i]] < S[arr[i+1]]){
      doit[i] = 1;
      continue;
    }
    if(S[arr[i]] == S[arr[i+1]]){
      doit[i] = doit[i+1];
      continue;
    }
  }
  for(i=(0);i<(N);i++){
    if(!dup[arr[i]]){
      if((doit[i] && f.get(0,arr[i])==0)){
        k = getdep(arr[i]);
        if(k <= K){
          int APIVbQlN;
          K -= k;
          j = arr[i];
          for(APIVbQlN=(0);APIVbQlN<(k);APIVbQlN++){
            dup[j] = 1;
            j = hld.up(j);
          }
        }
      }
      else{
        f.add(arr[i], 1);
      }
    }
  }
  for(i=(0);i<(N);i++){
    res[ress++] = S[arr[i]];
    if(dup[arr[i]]){
      res[ress++] = S[arr[i]];
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
template<class T> void fenwick<T>::malloc(int mem){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
}
template<class T> void fenwick<T>::malloc(int mem, int fg){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::walloc(int mem, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
}
template<class T> void fenwick<T>::walloc(int mem, int fg, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::free(void){
  memory = 0;
  free(data);
}
template<class T> void fenwick<T>::init(int N){
  size = N;
  memset(data,0,sizeof(T)*N);
}
template<class T> void fenwick<T>::add(int k, T val){
  while(k < size){
    data[k] += val;
    k |= k+1;
  }
}
template<class T> T fenwick<T>::get(int k){
  T res = 0;
  while(k>=0){
    res += data[k];
    k = (k&(k+1))-1;
  }
  return res;
}
template<class T> T fenwick<T>::range(int a, int b){
  if(a < 0){
    a = 0;
  }
  if(b >= size){
    b = size - 1;
  }
  if(b < a){
    return 0;
  }
  return get(b) - get(a-1);
}
template<class T> int fenwick<T>::kth(T k){
  int i=0;
  int j=size;
  int c;
  T v;
  while(i<j){
    c = (i+j)/2;
    v = get(c);
    if(v <= k){
      i=c+1;
    }
    else{
      j=c;
    }
  }
  return i==size?-1:i;
}
// cLay version 20211229-1

// --- original code ---
// //no-unlocked
// int N, K, A[4d5+2], B[];
// int mm, aa[], bb[], dup[];
// graph g;
// HLD hld;
// HLD_fenwick<int> f;
// char S[], res[]; int ress, arr[], sz, doit[];
// 
// void dfs(int n){
//   if(n==-1) return;
//   dfs(A[n]); arr[sz++] = n; dfs(B[n]);
// }
// 
// int getdep(int n){
//   int k;
//   return bsearch_min[int,x,0,N+1][
//     k = hld.up(n,x);
//   ](k==-1 || dup[k]);
// }
// 
// {
//   int i, j, k, m;
//   rd(N,K,S,(A--,B--)(N));
//   rep(i,N) if(A[i] >= 0) arrInsert(mm, mm, aa, i, bb, A[i]);
//   rep(i,N) if(B[i] >= 0) arrInsert(mm, mm, aa, i, bb, B[i]);
//   g.setEdge(N,mm,aa,bb);
//   hld.init(g);
//   f.init(&hld);
// 
//   dfs(0);
//   rrep(i,N-1){
//     if(S[arr[i]] < S[arr[i+1]]) doit[i] = 1, continue;
//     if(S[arr[i]] == S[arr[i+1]]) doit[i] = doit[i+1], continue;
//   }
// 
//   rep(i,N) if(!dup[arr[i]]){
//     if((doit[i] && f.get(0,arr[i])==0)){
//       k = getdep(arr[i]);
//       if(k <= K){
//         K -= k;
//         j = arr[i];
//         rep(k){
//           dup[j] = 1;
//           j = hld.up(j);
//         }
//       }
//     } else {
//       f.add(arr[i], 1);
//     }
//   }
// 
//   rep(i,N){
//     res[ress++] = S[arr[i]];
//     if(dup[arr[i]]) res[ress++] = S[arr[i]];
//   }
// 
//   wt(res);
// }