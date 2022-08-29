#pragma GCC optimize ("Ofast")
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
  graph reverse(void **mem = &wmem){
    int i;
    int j;
    int k;
    graph g;
    g.N = N;
    walloc1d(&g.es, N, mem);
    walloc1d(&g.edge, N, mem);
    for(i=(0);i<(N);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        g.es[edge[i][j]]++;
      }
    }
    for(i=(0);i<(N);i++){
      walloc1d(&g.edge[i], g.es[i], mem);
    }
    for(i=(0);i<(N);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        g.edge[k][g.es[k]++] = i;
      }
    }
    return g;
  }
  inline int sccDFS(int num[], int st, int mx){
    int i;
    int j;
    num[st]=-2;
    for(i=(0);i<(es[st]);i++){
      j=edge[st][i];
      if(num[j]==-1){
        mx=sccDFS(num,j,mx);
      }
    }
    num[st]=mx;
    return mx+1;
  }
  int scc(int res[], void *mem = wmem){
    int i;
    int j;
    int k;
    int ret=0;
    graph r;
    int*st;
    int st_size;
    int*num;
    int*nrv;
    r = reverse(&mem);
    walloc1d(&st, N, &mem);
    walloc1d(&num, N, &mem);
    walloc1d(&nrv, N, &mem);
    for(i=(0);i<(N);i++){
      res[i] = num[i] = -1;
    }
    k = 0;
    for(i=(0);i<(N);i++){
      if(num[i]==-1){
        k = sccDFS(num,i,k);
      }
    }
    for(i=(0);i<(N);i++){
      nrv[num[i]] = i;
    }
    for(k=N-1;k>=0;k--){
      i=nrv[k];
      if(res[i]>=0){
        continue;
      }
      res[i]=ret;
      st_size=0;
      st[st_size++]=i;
      while(st_size){
        i=st[--st_size];
        for(j=(0);j<(r.es[i]);j++){
          if(res[r.edge[i][j]]==-1){
            res[r.edge[i][j]]=ret;
            st[st_size++]=r.edge[i][j];
          }
        }
      }
      ret++;
    }
    return ret;
  }
}
;
template<class T> struct wgraph{
  int N;
  int*es;
  int**edge;
  T**cost;
  graph g;
  void setDirectEdge(int N__, int M, int A[], int B[], T C[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
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
      cost[A[i]][es[A[i]]++] = C[i];
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
long long C[200000];
wgraph<long long> g;
int sc[200000];
int vis[200000];
long long d[200000];
long long gc[200000];
long long gg[200000];
void dfs(int n, long long dd){
  int i;
  if(vis[n]){
    gc[n] =GCD_L(gc[n], abs(dd - d[n]));
    return;
  }
  vis[n] = 1;
  d[n] = dd;
  for(i=(0);i<(g.es[n]);i++){
    if(sc[n] == sc[g.edge[n][i]]){
      dfs(g.edge[n][i], dd + g.cost[n][i]);
    }
  }
}
int main(){
  int ao_dF3pO, i;
  wmem = memarr;
  rd(N);
  rd(M);
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(M);e98WHCEY++){
      rd(A[e98WHCEY]);A[e98WHCEY] += (-1);
      rd(B[e98WHCEY]);B[e98WHCEY] += (-1);
      rd(C[e98WHCEY]);
    }
  }
  g.setDirectEdge(N,M,A,B,C);
  g.g.scc(sc);
  for(i=(0);i<(N);i++){
    if(!vis[i]){
      dfs(i, 0);
    }
  }
  for(i=(0);i<(N);i++){
    gg[sc[i]] =GCD_L(gg[sc[i]], gc[i]);
  }
  int tU__gIr_ = rd_int();
  for(ao_dF3pO=(0);ao_dF3pO<(tU__gIr_);ao_dF3pO++){
    int V;
    rd(V);
    long long S;
    rd(S);
    long long T;
    rd(T);
    V = sc[V-1];
    S =GCD_L(S, T);
    if(S %GCD_L(gg[V], T)== 0){
      wt_L("YES");
      wt_L('\n');
      continue;
    }
    wt_L("NO");
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210502-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M; int A[2d5], B[2d5]; ll C[2d5];
// wgraph<ll> g;
// int sc[];
// int vis[]; ll d[], gc[], gg[];
// 
// void dfs(int n, ll dd){
//   if(vis[n]){
//     gc[n] = gcd(gc[n], abs(dd - d[n]));
//     return;
//   }
//   vis[n] = 1;
//   d[n] = dd;
//   rep(i,g.es[n]) if(sc[n] == sc[g.edge[n][i]]) dfs(g.edge[n][i], dd + g.cost[n][i]);
// }
// 
// {
//   rd(N,M,(A--,B--,C)(M));
//   g.setDirectEdge(N,M,A,B,C);
//   g.g.scc(sc);
//   rep(i,N) if(!vis[i]) dfs(i, 0);
//   rep(i,N) gg[sc[i]] = gcd(gg[sc[i]], gc[i]);
// 
//   REP(rd_int()){
//     int @V;
//     ll @S, @T;
//     V = sc[V-1];
//     S = gcd(S, T);
//     if(S % gcd(gg[V],T) == 0) wt("YES"), continue;
//     wt("NO");
//   }
// }