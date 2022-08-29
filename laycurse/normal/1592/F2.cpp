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
template<class T, class S> struct maxflow{
  int node;
  int st;
  int ed;
  int*es;
  int*emem;
  int**edge;
  int**rev;
  int*level;
  int*qq;
  T**flow;
  T eps;
  void malloc(int N){
    int i;
    es = (int*)std::malloc(N*sizeof(int));
    emem = (int*)std::malloc(N*sizeof(int));
    level = (int*)std::malloc(N*sizeof(int));
    qq = (int*)std::malloc(N*sizeof(int));
    edge = (int**)std::malloc(N*sizeof(int*));
    rev = (int**)std::malloc(N*sizeof(int*));
    flow = (T**)std::malloc(N*sizeof(T*));
    for(i=(0);i<(N);i++){
      emem[i] = 0;
      edge[i] = rev[i] = NULL;
      flow[i] = NULL;
    }
  }
  void malloc(int N, int init_flag){
    int i;
    es = (int*)std::malloc(N*sizeof(int));
    emem = (int*)std::malloc(N*sizeof(int));
    level = (int*)std::malloc(N*sizeof(int));
    qq = (int*)std::malloc(N*sizeof(int));
    edge = (int**)std::malloc(N*sizeof(int*));
    rev = (int**)std::malloc(N*sizeof(int*));
    flow = (T**)std::malloc(N*sizeof(T*));
    for(i=(0);i<(N);i++){
      emem[i] = 0;
      edge[i] = rev[i] = NULL;
      flow[i] = NULL;
    }
    if(init_flag){
      init(N);
    }
  }
  void walloc(int N, void**mem = &wmem){
    int i;
    walloc1d(&es, N, mem);
    walloc1d(&emem, N, mem);
    walloc1d(&level, N, mem);
    walloc1d(&qq, N, mem);
    walloc1d(&edge, N, mem);
    walloc1d(&rev, N, mem);
    walloc1d(&flow, N, mem);
    (*mem) = (flow + N);
  }
  void walloc(int N, int init_flag, void**mem = &wmem){
    int i;
    walloc1d(&es, N, mem);
    walloc1d(&emem, N, mem);
    walloc1d(&level, N, mem);
    walloc1d(&qq, N, mem);
    walloc1d(&edge, N, mem);
    walloc1d(&rev, N, mem);
    walloc1d(&flow, N, mem);
    (*mem) = (flow + N);
    if(init_flag){
      init(N);
    }
  }
  void levelize(void){
    int i;
    int j;
    int k;
    int t;
    int q_st = 0;
    int q_ed = 1;
    for(i=(0);i<(node);i++){
      level[i] = -1;
    }
    level[st] = 0;
    qq[0] = st;
    while(q_st != q_ed){
      i = qq[q_st++];
      t = level[i] + 1;
      for(j=(0);j<(es[i]);j++){
        if(flow[i][j] > eps){
          k = edge[i][j];
          if(level[k]!=-1){
            continue;
          }
          level[k] = t;
          qq[q_ed++] = k;
          if(k==ed){
            return;
          }
        }
      }
    }
  }
  S pushflow(int i, S lim){
    int j;
    int k;
    int ji;
    S s;
    S t;
    S res = 0;
    if(i==ed){
      return lim;
    }
    for(j=(0);j<(es[i]);j++){
      if(flow[i][j] > eps){
        k = edge[i][j];
        if(level[k] != level[i]+1){
          continue;
        }
        s =min_L(lim, (S)flow[i][j]);
        t = pushflow(k, s);
        if(!t){
          continue;
        }
        res += t;
        lim -= t;
        ji = rev[i][j];
        flow[i][j] -= t;
        flow[k][ji] += t;
        if(!lim){
          break;
        }
      }
    }
    if(lim){
      level[i] = -1;
    }
    return res;
  }
  S solve(int st_, int ed_){
    S res = 0;
    st = st_;
    ed = ed_;
    for(;;){
      levelize();
      if(level[ed] == -1){
        break;
      }
      res += pushflow(st, numeric_limits<S>::max());
    }
    return res;
  }
  void init(int N){
    int i;
    node = N;
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    eps = (T)1e-9;
  }
  void memoryExpand(int i, int sz){
    if(sz <= emem[i]){
      return;
    }
    sz =max_L(sz,max_L(3, emem[i]*2));
    emem[i]=sz;
    edge[i] = (int*)realloc(edge[i], sz*sizeof(int));
    rev[i] = (int*)realloc(rev[i], sz*sizeof(int));
    flow[i] = (T*)realloc(flow[i], sz*sizeof(T));
  }
  void addEdge(int n1, int n2, T f1, T f2 = 0){
    int s1 = es[n1]++;
    int s2 = es[n2]++;
    if(s1 >= emem[n1]){
      memoryExpand(n1, es[n1]);
    }
    if(s2 >= emem[n2]){
      memoryExpand(n2, es[n2]);
    }
    edge[n1][s1]=n2;
    edge[n2][s2]=n1;
    flow[n1][s1]=f1;
    flow[n2][s2]=f2;
    rev[n1][s1]=s2;
    rev[n2][s2]=s1;
  }
  void addEdgeAdv(int n1, int n2, T f1, T f2 = 0){
    int s1 = es[n1]++;
    int s2 = es[n2]++;
    edge[n1][s1]=n2;
    edge[n2][s2]=n1;
    flow[n1][s1]=f1;
    flow[n2][s2]=f2;
    rev[n1][s1]=s2;
    rev[n2][s2]=s1;
  }
  void setGraph(int N, int M, int n1[], int n2[], T f1[], T f2[]){
    int i;
    node = N;
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[n1[i]]++;
      es[n2[i]]++;
    }
    for(i=(0);i<(N);i++){
      memoryExpand(i, es[i]);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      addEdgeAdv(n1[i], n2[i], f1[i], f2[i]);
    }
    eps = (T)1e-9;
  }
  void setGraph_w(int N, int M, int n1[], int n2[], T f1[], T f2[], void **mem = wmem){
    int i;
    int j;
    int k;
    node = N;
    for(i=(0);i<(N);i++){
      es[i] = emem[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[n1[i]]++;
      es[n2[i]]++;
    }
    edge[0] = (int*)(*mem);
    int Wv3_QJ0O = N;
    for(i=(1);i<(Wv3_QJ0O);i++){
      edge[i] = edge[i-1] + es[i-1];
    }
    rev[0] = edge[N-1] + es[N-1];
    int eNrGll8F = N;
    for(i=(1);i<(eNrGll8F);i++){
      rev[i] = rev[i-1] + es[i-1];
    }
    flow[0] = (T*)(rev[N-1] + es[N-1]);
    int bz47bCAl = N;
    for(i=(1);i<(bz47bCAl);i++){
      flow[i] = flow[i-1] + es[i-1];
    }
    *mem = (void*)(flow[N-1] + es[N-1]);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      addEdgeAdv(n1[i], n2[i], f1[i], f2[i]);
    }
    eps = (T)1e-9;
  }
}
;
int main(){
  int i;
  wmem = memarr;
  int X;
  rd(X);
  int Y;
  rd(Y);
  int A[X][Y];
  int ad[X][Y];
  int res = 0;
  char tmp[500][502];
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(X);Lj4PdHRW++){
      rd(tmp[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(X);i++){
    int j;
    for(j=(0);j<(Y);j++){
      if(tmp[i][j]=='W'){
        A[i][j] =0;
      }
      else{
        A[i][j] =1;
      }
    }
  }
  for(i=(X)-1;i>=(0);i--){
    int j;
    for(j=(Y)-1;j>=(0);j--){
      ad[i][j] = 0;
      if(i+1 < X){
        ad[i][j] ^= ad[i+1][j];
      }
      if(j+1 < Y){
        ad[i][j] ^= ad[i][j+1];
      }
      if(i+1 < X && j+1 < Y){
        ad[i][j] ^= ad[i+1][j+1];
      }
      A[i][j] ^= ad[i][j];
      if(A[i][j]){
        res++;
        ad[i][j] ^= 1;
      }
    }
  }
  int node;
  int st;
  int ed;
  int flow;
  maxflow<int,int> f;
  node = (X-1) + (Y-1);
  st = node++;
  ed = node++;
  f.walloc(node);
  f.init(node);
  for(i=(0);i<(X-1);i++){
    if(A[i][Y-1]){
      f.addEdge(st, i, 1);
    }
  }
  for(i=(0);i<(Y-1);i++){
    if(A[X-1][i]){
      f.addEdge((X-1)+i, ed, 1);
    }
  }
  for(i=(0);i<(X-1);i++){
    int j;
    for(j=(0);j<(Y-1);j++){
      if(A[i][j]){
        f.addEdge(i,(X-1)+j,1);
      }
    }
  }
  flow = f.solve(st,ed) + A[X-1][Y-1];
  wt_L(res - flow/2*2);
  wt_L('\n');
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int @X, @Y, A[X][Y], ad[X][Y], res = 0;
// char tmp[500][502];
// rd(tmp(X));
// rep(i,X) rep(j,Y) A[i][j] = if[tmp[i][j]=='W', 0, 1];
// 
// rrep(i,X) rrep(j,Y){
//   ad[i][j] = 0;
//   if(i+1 < X) ad[i][j] ^= ad[i+1][j];
//   if(j+1 < Y) ad[i][j] ^= ad[i][j+1];
//   if(i+1 < X && j+1 < Y) ad[i][j] ^= ad[i+1][j+1];
//   A[i][j] ^= ad[i][j];
//   if(A[i][j]){
//     res++;
//     ad[i][j] ^= 1;
//   }
// }
// 
// int node, st, ed, flow;
// maxflow<int,int> f;
// node = (X-1) + (Y-1);
// st = node++;
// ed = node++;
// f.walloc(node);
// f.init(node);
// 
// rep(i,X-1) if(A[i][Y-1]) f.addEdge(st, i, 1);
// rep(i,Y-1) if(A[X-1][i]) f.addEdge((X-1)+i, ed, 1);
// rep(i,X-1) rep(j,Y-1) if(A[i][j]) f.addEdge(i,(X-1)+j,1);
// flow = f.solve(st,ed) + A[X-1][Y-1];
// 
// wt(res - flow/2*2);