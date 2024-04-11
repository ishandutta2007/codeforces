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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
template<class T, class U> void reduceFraction(T&a, U&b){
  T g=GCD_L(a,b);
  a/=g;
  b/=g;
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
template<class T> int coordcomp_L(int n1, T arr1[], int n2, T arr2[], int res1[] = NULL, int res2[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int>*r;
  walloc1d(&r, n1+n2, &mem);
  for(i=(0);i<(n1);i++){
    r[i].first = arr1[i];
    r[i].second = i;
  }
  for(i=(0);i<(n2);i++){
    r[n1+i].first = arr2[i];
    r[n1+i].second = n1+i;
  }
  sort(r, r+n1+n2);
  for(i=(0);i<(n1+n2);i++){
    if(i && r[i].first != r[i-1].first){
      k++;
    }
    if(r[i].second < n1){
      if(res1!=NULL){
        res1[r[i].second] = k;
      }
      else{
        arr1[r[i].second] = k;
      }
    }
    else{
      if(res2!=NULL){
        res2[r[i].second-n1] = k;
      }
      else{
        arr2[r[i].second-n1] = k;
      }
    }
  }
  return k+1;
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
long long A[200000];
long long B[200000];
long long C[200000];
long long D[200000];
__int128_t xx[200000];
__int128_t yy[200000];
int sz;
int x[200000];
int y[200000];
int ind[200000];
int vis[400000];
wgraph<int> g;
int ress;
int res1[400000];
int res2[400000];
int d[400000];
int dfs(int n, int pre, int dd){
  int i;
  int cur = -1;
  int tmp;
  vis[n] = 1;
  d[n] = dd;
  for(i=(0);i<(g.es[n]);i++){
    if(vis[g.edge[n][i]]){
      tmp = -1;
      if(d[n] < d[g.edge[n][i]]){
        tmp = g.cost[n][i];
      }
    }
    else{
      tmp = dfs(g.edge[n][i], g.cost[n][i], dd+1);
    }
    if(tmp == -1){
      continue;
    }
    if(cur==-1){
      cur = tmp;
    }
    else{
      arrInsert(ress, ress, res1, cur, res2, tmp);
      cur = -1;
    }
  }
  if(cur >= 0 && pre >= 0){
    arrInsert(ress, ress, res1, cur, res2, pre);
    cur = pre = -1;
  }
  return pre;
}
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int m;
  rd(N);
  {
    int Q5VJL1cS;
    for(Q5VJL1cS=(0);Q5VJL1cS<(N);Q5VJL1cS++){
      rd(A[Q5VJL1cS]);
      rd(B[Q5VJL1cS]);
      rd(C[Q5VJL1cS]);
      rd(D[Q5VJL1cS]);
    }
  }
  for(i=(0);i<(N);i++){
    __int128_t a;
    __int128_t b;
    a = (A[i] + B[i]) * D[i];
    b = B[i] * C[i];
    reduceFraction(a,b);
    xx[i] = a * 4000000000000000000LL + b;
    a = A[i] * D[i];
    b = B[i] * (C[i] + D[i]);
    reduceFraction(a,b);
    yy[i] = a * 4000000000000000000LL + b;
  }
  sz =coordcomp_L(N, xx, N, yy, x, y);
  for(i=(0);i<(N);i++){
    ind[i] = i;
  }
  g.setEdge(sz, N, x, y, ind);
  for(i=(0);i<(sz);i++){
    if(!vis[i]){
      dfs(i, -1, 0);
    }
  }
  wt_L(ress);
  wt_L('\n');
  for(i=(0);i<(ress);i++){
    wt_L(res1[i]+1);
    wt_L(' ');
    wt_L(res2[i]+1);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N; ll A[2d5], B[], C[], D[];
// __int128_t xx[], yy[];
// int sz, x[], y[], ind[], vis[4d5];
// wgraph<int> g;
// int ress, res1[], res2[], d[];
// 
// int dfs(int n, int pre, int dd){
//   int cur = -1, tmp;
//   vis[n] = 1;
//   d[n] = dd;
// 
//   rep(i,g.es[n]){
//     if(vis[g.edge[n][i]]){
//       tmp = -1;
//       if(d[n] < d[g.edge[n][i]]) tmp = g.cost[n][i];
//     } else {
//       tmp = dfs(g.edge[n][i], g.cost[n][i], dd+1);
//     }
//     if(tmp == -1) continue;
// 
//     if(cur==-1){
//       cur = tmp;
//     } else {
//       arrInsert(ress, ress, res1, cur, res2, tmp);
//       cur = -1;
//     }
//   }
//   if(cur >= 0 && pre >= 0){
//     arrInsert(ress, ress, res1, cur, res2, pre);
//     cur = pre = -1;
//   }
//   return pre;
// }
// 
// {
//   int i, j, k, m;
//   rd(N,(A,B,C,D)(N));
//   rep(i,N){
//     __int128_t a, b;
//     a = (A[i] + B[i]) * D[i];
//     b = B[i] * C[i];
//     reduceFraction(a,b);
//     xx[i] = a * 4d18 + b;
// 
//     a = A[i] * D[i];
//     b = B[i] * (C[i] + D[i]);
//     reduceFraction(a,b);
//     yy[i] = a * 4d18 + b;
//   }
//   sz = coordcomp(N, xx, N, yy, x, y);
//   rep(i,N) ind[i] = i;
//   g.setEdge(sz, N, x, y, ind);
//   rep(i,sz) if(!vis[i]) dfs(i, -1, 0);
//   wt(ress);
//   rep(i,ress) wt(res1[i]+1, res2[i]+1);
// }