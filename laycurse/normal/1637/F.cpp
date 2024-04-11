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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
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
  template<class V> void Rerooting(V res[], void *mem = wmem);
}
;
int N;
int H[200000];
int U[200000];
int V[200000];
struct rval{
  long long cost;
  long long mx;
}
;
void RerootingId(rval &a){
  a = {0, 0};
}
rval RerootingMerge(rval a, rval b){
  return {a.cost+b.cost,max_L(a.mx, b.mx)};
}
rval RerootingEdge(rval a, int EFrom, int ETo){
  return a;
}
rval RerootingNode(rval a, int Nind){
  rval res = a;
  if(a.mx < H[Nind]){
    res.cost += H[Nind] - a.mx;
    res.mx = H[Nind];
  }
  return res;
}
graph g;
rval d[200000];
int main(){
  int i;
  wmem = memarr;
  long long res = 4611686016279904256LL;
  rd(N);
  {
    int bkxOPzPX;
    for(bkxOPzPX=(0);bkxOPzPX<(N);bkxOPzPX++){
      rd(H[bkxOPzPX]);
    }
  }
  {
    int om7Ebh6q;
    for(om7Ebh6q=(0);om7Ebh6q<(N-1);om7Ebh6q++){
      rd(U[om7Ebh6q]);U[om7Ebh6q] += (-1);
      rd(V[om7Ebh6q]);V[om7Ebh6q] += (-1);
    }
  }
  g.setEdge(N,N-1,U,V);
  g.Rerooting(d);
  for(i=(0);i<(N);i++){
    if(g.es[i] == 1){
      chmin(res, d[i].cost + d[i].mx);
    }
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
template<class V> void graph::Rerooting(V res[], void *mem /*= wmem*/){
  int i;
  int j;
  int k;
  int ui;
  int ii;
  int*upind;
  int*dwind;
  int*vis;
  int*q;
  int qs;
  int qe;
  V**val;
  V**pleft;
  V**pright;
  V tmp;
  walloc1d(&upind, N, &mem);
  walloc1d(&dwind, N, &mem);
  walloc1d(&vis, N, &mem);
  walloc1d(&q, N, &mem);
  walloc1d(&val, N, &mem);
  for(i=(0);i<(N);i++){
    walloc1d(&val[i], es[i], &mem);
  }
  walloc1d(&pleft, N, &mem);
  for(i=(0);i<(N);i++){
    walloc1d(&pleft[i], es[i]+1, &mem);
  }
  walloc1d(&pright, N, &mem);
  for(i=(0);i<(N);i++){
    walloc1d(&pright[i], es[i]+1, &mem);
  }
  upind[0] = -1;
  for(i=(0);i<(N);i++){
    vis[i] = 0;
  }
  qs = qe = 0;
  q[qe++] = 0;
  vis[0] = 1;
  while(qs < qe){
    i = q[qs++];
    for(j=(0);j<(es[i]);j++){
      k = edge[i][j];
      if(vis[k]){
        upind[i] = j;
        continue;
      }
      dwind[k] = j;
      vis[k] = 1;
      q[qe++] = k;
    }
  }
  for(ii=(N)-1;ii>=(0);ii--){
    i = q[ii];
    for(j=(0);j<(es[i]);j++){
      if(j != upind[i]){
        k = edge[i][j];
        ui = upind[k];
        tmp = RerootingMerge(pleft[k][ui], pright[k][es[k]-1-ui]);
        tmp = RerootingNode(tmp, k);
        val[i][j] = RerootingEdge(tmp, i, k);
      }
    }
    RerootingId(pleft[i][0]);
    RerootingId(pright[i][0]);
    for(j=(0);j<(es[i]);j++){
      if(j == upind[i]){
        break;
      }
      pleft[i][j+1] = RerootingMerge(pleft[i][j], val[i][j]);
    }
    for(j=(0);j<(es[i]);j++){
      if(es[i]-1-j == upind[i]){
        break;
      }
      pright[i][j+1] = RerootingMerge(pright[i][j], val[i][es[i]-1-j]);
    }
  }
  for(ii=(0);ii<(N);ii++){
    i = q[ii];
    j = upind[i];
    if(j != -1){
      k = edge[i][j];
      ui = dwind[i];
      tmp = RerootingMerge(pleft[k][ui], pright[k][es[k]-1-ui]);
      tmp = RerootingNode(tmp, k);
      val[i][j] = RerootingEdge(tmp, i, k);
      for(j=(upind[i]);j<(es[i]);j++){
        pleft[i][j+1] = RerootingMerge(pleft[i][j], val[i][j]);
      }
      for(j=(es[i]-upind[i]-1);j<(es[i]);j++){
        pright[i][j+1] = RerootingMerge(pright[i][j], val[i][es[i]-1-j]);
      }
    }
    res[i] = RerootingNode(pleft[i][es[i]], i);
  }
}
// cLay version 20220116-1 [+beta]

// --- original code ---
// //no-unlocked
// int N, H[2d5], U[], V[];
// 
// struct rval{ ll cost, mx; };
// 
// void RerootingId(rval &a){ a = {0, 0}; }
// rval RerootingMerge(rval a, rval b){ return {a.cost+b.cost, max(a.mx, b.mx)}; }
// rval RerootingEdge(rval a, int EFrom, int ETo){ return a; }
// rval RerootingNode(rval a, int Nind){
//   rval res = a;
//   if(a.mx < H[Nind]){
//     res.cost += H[Nind] - a.mx;
//     res.mx = H[Nind];
//   }
//   return res;
// }
// 
// graph g;
// rval d[2d5];
// {
//   ll res = ll_inf;
//   rd(N,H(N),(U--,V--)(N-1));
//   g.setEdge(N,N-1,U,V);
//   g.Rerooting(d);
//   rep(i,N) if(g.es[i] == 1){
//     res <?= d[i].cost + d[i].mx;
//   }
//   wt(res);
// }