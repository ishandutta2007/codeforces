#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
  template<class S> void getDist(int root, S res[], S unreachable = -1, void *mem = wmem){
    int i;
    int j;
    DijkstraHeap<S> hp;
    hp.walloc(N, &mem);
    hp.init(N);
    hp.change(root,0);
    while(hp.size){
      i = hp.pop();
      for(j=(0);j<(es[i]);j++){
        hp.change(edge[i][j], hp.val[i]+cost[i][j]);
      }
    }
    for(i=(0);i<(N);i++){
      res[i] = (hp.visited[i] ? hp.val[i] : unreachable);
    }
  }
}
;
int N;
int M;
int K;
int X[1000];
int Y[1000];
int W[1000];
int A[1000];
int B[1000];
wgraph<int> g;
int dist[1000][1000];
int main(){
  int i, k;
  wmem = memarr;
  long long res = 4611686016279904256LL;
  rd(N);
  rd(M);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);X[Lj4PdHRW] += (-1);
      rd(Y[Lj4PdHRW]);Y[Lj4PdHRW] += (-1);
      rd(W[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(K);e98WHCEY++){
      rd(A[e98WHCEY]);A[e98WHCEY] += (-1);
      rd(B[e98WHCEY]);B[e98WHCEY] += (-1);
    }
  }
  g.setEdge(N,M,X,Y,W);
  for(i=(0);i<(N);i++){
    g.getDist(i, dist[i]);
  }
  for(k=(0);k<(M);k++){
    {
      int KrdatlYV;
      remove_reference<decltype(min_L(min_L(dist[A[KrdatlYV]][B[KrdatlYV]], dist[A[KrdatlYV]][X[k]]+dist[Y[k]][B[KrdatlYV]]), dist[A[KrdatlYV]][Y[k]]+dist[X[k]][B[KrdatlYV]]))>::type ao_dF3pO;
      int tU__gIr_ = 0;
      if((0) > ((K)-1)){
        ao_dF3pO = 0;
      }
      else{
        for(KrdatlYV = 0; KrdatlYV <= (K)-1; KrdatlYV++){
          if(tU__gIr_ == 0){
            ao_dF3pO =min_L(min_L(dist[A[KrdatlYV]][B[KrdatlYV]], dist[A[KrdatlYV]][X[k]]+dist[Y[k]][B[KrdatlYV]]), dist[A[KrdatlYV]][Y[k]]+dist[X[k]][B[KrdatlYV]]);
            tU__gIr_ = 1;
            continue;
          }
          ao_dF3pO +=min_L(min_L(dist[A[KrdatlYV]][B[KrdatlYV]], dist[A[KrdatlYV]][X[k]]+dist[Y[k]][B[KrdatlYV]]), dist[A[KrdatlYV]][Y[k]]+dist[X[k]][B[KrdatlYV]]);
        }
      }
      chmin(res, ao_dF3pO);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20201115-2

// --- original code ---
// //no-unlocked
// int N, M, K, X[1000], Y[1000], W[1000], A[1000], B[1000];
// wgraph<int> g;
// int dist[1000][1000];
// {
//   ll res = ll_inf;
//   rd(N,M,K,(X--,Y--,W)(M),(A--,B--)(K));
//   g.setEdge(N,M,X,Y,W);
//   rep(i,N) g.getDist(i, dist[i]);
//   rep(k,M) res <?= sum[i,0,K](min(dist[A[i]][B[i]], dist[A[i]][X[k]]+dist[Y[k]][B[i]], dist[A[i]][Y[k]]+dist[X[k]][B[i]]));
//   wt(res);
// }