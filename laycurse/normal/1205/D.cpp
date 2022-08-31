#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16]={0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
inline void rd(int &x){
  int k, m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(int x){
  char f[10];
  int m=0, s=0;
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template <class T> struct DijkstraHeap{
  T *val;
  char *visited;
  int *hp, *place, size;
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
    for(i=0;i<(N);i++){
      place[i]=-1;
    }
    for(i=0;i<(N);i++){
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
  int N, **edge, *es;
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=0;i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
  void setDirectEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    walloc1d(&edge[0], M, mem);
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      es[A[i]]++;
    }
    for(i=0;i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
    }
  }
  graph reverse(void **mem = &wmem){
    graph g;
    int i, j, k;
    g.N = N;
    walloc1d(&g.es, N, mem);
    walloc1d(&g.edge, N, mem);
    for(i=0;i<(N);i++){
      g.es[i] = 0;
    }
    for(i=0;i<(N);i++){
      for(j=0;j<(es[i]);j++){
        g.es[edge[i][j]]++;
      }
    }
    for(i=0;i<(N);i++){
      walloc1d(&g.edge[i], g.es[i]);
    }
    for(i=0;i<(N);i++){
      g.es[i] = 0;
    }
    for(i=0;i<(N);i++){
      for(j=0;j<(es[i]);j++){
        k = edge[i][j];
        g.edge[k][g.es[k]++] = i;
      }
    }
    return g;
  }
  graph reduce(int tn, int ind[], int self_e = 0, int dep_e = 0, void **mem = &wmem){
    graph g;
    int M=0, i, j, k, x, y;
    pair<int,int> *A;
    for(i=0;i<(N);i++){
      M += es[i];
    }
    A = (pair<int,int>*)((int*)((int**)(*mem) + tn) + tn + M);
    M = 0;
    for(i=0;i<(N);i++){
      x = ind[i];
      if(x < 0){
        continue;
      }
      for(j=0;j<(es[i]);j++){
        y = ind[edge[i][j]];
        if(y < 0){
          continue;
        }
        if(self_e==0 && x==y){
          continue;
        }
        A[M++] = make_pair(x, y);
      }
    }
    if(dep_e==0){
      sort(A, A+M);
      k = 0;
      for(i=0;i<(M);i++){
        if(k && A[k-1]==A[i]){
          continue;
        }
        A[k++] = A[i];
      }
      M = k;
    }
    g.N = tn;
    g.es = (int*)(*mem);
    g.edge = (int**)(g.es + tn);
    g.edge[0] = (int*)(g.edge + tn);
    for(i=0;i<(tn);i++){
      g.es[i] = 0;
    }
    for(i=0;i<(M);i++){
      g.es[A[i].first]++;
    }
    for(i=(1);i<(tn);i++){
      g.edge[i] = g.edge[i-1] + g.es[i-1];
    }
    *mem = g.edge[tn-1] + g.es[tn-1];
    for(i=0;i<(tn);i++){
      g.es[i] = 0;
    }
    for(i=0;i<(M);i++){
      j = A[i].first;
      k = A[i].second;
      g.edge[j][g.es[j]++] = k;
    }
    return g;
  }
  void getDist(int root, int res[], void *mem = wmem){
    int i, j, k, *q, s, z;
    walloc1d(&q, N, &mem);
    for(i=0;i<(N);i++){
      res[i]=-1;
    }
    res[root]=0;
    s=0;
    z=1;
    q[0]=root;
    while(z){
      i=q[s++];
      z--;
      for(j=0;j<(es[i]);j++){
        k=edge[i][j];
        if(res[k]>=0){
          continue;
        }
        res[k]=res[i]+1;
        q[s+z++]=k;
      }
    }
  }
  inline int sccDFS(int num[], int st, int mx){
    int i, j;
    num[st]=-2;
    for(i=0;i<(es[st]);i++){
      j=edge[st][i];
      if(num[j]==-1){
        mx=sccDFS(num,j,mx);
      }
    }
    num[st]=mx;
    return mx+1;
  }
  int scc(int res[], void *mem = wmem){
    graph r;
    int i, j, k, *nrv, *num, ret=0, *st, st_size;
    r = reverse(&mem);
    walloc1d(&st, N, &mem);
    walloc1d(&num, N, &mem);
    walloc1d(&nrv, N, &mem);
    for(i=0;i<(N);i++){
      res[i] = num[i] = -1;
    }
    k = 0;
    for(i=0;i<(N);i++){
      if(num[i]==-1){
        k = sccDFS(num,i,k);
      }
    }
    for(i=0;i<(N);i++){
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
        for(j=0;j<(r.es[i]);j++){
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
  inline void bccDFS(int v, int u, int *res, int *rt, int &rts, int *S, int &Ss, int *inS, int *num, int &tm){
    int i, k;
    num[v] = ++tm;
    S[Ss++] = v;
    inS[v] = 1;
    rt[rts++] = v;
    for(i=0;i<(es[v]);i++){
      int w=edge[v][i];
      if(!num[w]){
        bccDFS(w, v, res, rt, rts, S, Ss, inS, num, tm);
      }
      else if(u != w && inS[w]){
        while(num[rt[rts-1]] > num[w]){
          rts--;
        }
      }
    }
    if(v == rt[rts-1]){
      k = S[Ss-1];
      for(;;){
        int w=S[--Ss];
        inS[w] = 0;
        res[w] = k;
        if(v==w){
          break;
        }
      }
      rts--;
    }
  }
  int bcc(int res[], void *mem=wmem){
    int *S, Ss=0, i, *inS, k, *num, *rt, rts=0, tm=0;
    pair<int,int> *arr;
    walloc1d(&num, N, &mem);
    walloc1d(&rt, N, &mem);
    walloc1d(&S, N, &mem);
    walloc1d(&inS, N, &mem);
    memset(num, 0, sizeof(int)*N);
    memset(inS, 0, sizeof(int)*N);
    for(i=0;i<(N);i++){
      if(!num[i]){
        bccDFS(i, N, res, rt, rts, S, Ss, inS, num, tm);
      }
    }
    arr = (pair<int,int>*)mem;
    for(i=0;i<(N);i++){
      arr[i].first = res[i];
      arr[i].second = i;
    }
    sort(arr, arr+N);
    k = 0;
    for(i=0;i<(N);i++){
      if(i && arr[i].first != arr[i-1].first){
        k++;
      }
      res[arr[i].second] = k;
    }
    return k+1;
  }
  int shortestPath(const int s, const int t, int res[], void *mem=wmem){
    int *b, i, j, k, *q, qe=0, qs=0;
    walloc1d(&b, N, &mem);
    walloc1d(&q, N, &mem);
    for(i=0;i<(N);i++){
      b[i] = -1;
    }
    b[s] = -2;
    q[qe++] = s;
    while(qe > qs){
      i = q[qs++];
      for(j=0;j<(es[i]);j++){
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
  int TopologicalSort(int res[], void *mem=wmem){
    int *deg, i, j, k, *q, qe=0, qs=0, rs;
    walloc1d(&deg, N, &mem);
    walloc1d(&q, N, &mem);
    rs = 0;
    for(i=0;i<(N);i++){
      deg[i] = 0;
    }
    for(i=0;i<(N);i++){
      for(j=0;j<(es[i]);j++){
        deg[edge[i][j]]++;
      }
    }
    for(i=0;i<(N);i++){
      if(deg[i]==0){
        q[qe++] = i;
      }
    }
    while(qs < qe){
      i = q[qs++];
      res[rs++] = i;
      for(j=0;j<(es[i]);j++){
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
template<class T> struct wgraph{
  T **cost;
  graph g;
  int N, **edge, *es;
  void setEdge(int N__, int M, int A[], int B[], T C[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    walloc1d(&edge, N, mem);
    for(i=0;i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    walloc1d(&cost, N, mem);
    for(i=0;i<(N);i++){
      walloc1d(&cost[i], es[i], mem);
    }
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      edge[A[i]][es[A[i]]] = B[i];
      edge[B[i]][es[B[i]]] = A[i];
      cost[A[i]][es[A[i]]++] = C[i];
      cost[B[i]][es[B[i]]++] = C[i];
    }
    g.N = N;
    g.es = es;
    g.edge = edge;
  }
  void setDirectEdge(int N__, int M, int A[], int B[], T C[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      es[A[i]]++;
    }
    walloc1d(&edge, N, mem);
    for(i=0;i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    walloc1d(&cost, N, mem);
    for(i=0;i<(N);i++){
      walloc1d(&cost[i], es[i], mem);
    }
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      edge[A[i]][es[A[i]]] = B[i];
      cost[A[i]][es[A[i]]++] = C[i];
    }
    g.N = N;
    g.es = es;
    g.edge = edge;
  }
  template<class S> void getDist(int root, S res[], S unreachable = -1, void *mem = wmem){
    DijkstraHeap<S> hp;
    int i, j;
    hp.walloc(N, &mem);
    hp.init(N);
    hp.change(root,0);
    while(hp.size){
      i = hp.pop();
      for(j=0;j<(es[i]);j++){
        hp.change(edge[i][j], hp.val[i]+cost[i][j]);
      }
    }
    for(i=0;i<(N);i++){
      res[i] = (hp.visited[i] ? hp.val[i] : unreachable);
    }
  }
  template<class S> void getDistForest(int root, S res[], S unreachable = -1, void *mem = wmem){
    char *r;
    int i, j, k, *q, s, z;
    walloc1d(&q,N,&mem);
    walloc1d(&r,N,&mem);
    for(i=0;i<(N);i++){
      r[i]=0;
    }
    res[root]=0;
    r[root]=1;
    s=0;
    z=1;
    q[0]=root;
    while(z){
      i=q[s++];
      z--;
      for(j=0;j<(es[i]);j++){
        k=edge[i][j];
        if(r[k]){
          continue;
        }
        res[k]=res[i]+cost[i][j];
        r[k]=1;
        q[s+z++]=k;
      }
    }
    for(i=0;i<(N);i++){
      if(!r[i]){
        res[i]=unreachable;
      }
    }
  }
  template<class S> void BellmanFord(int root, S res[], S unreachable = -1, S minusInf = -2, int step = -1, void *mem = wmem){
    S *arr;
    int KL2GvlyY, i, *inf, j, k, *q, qe, qs, t;
    walloc1d(&q, N, &mem);
    walloc1d(&inf, N, &mem);
    walloc1d(&arr, N, &mem);
    for(i=0;i<(N);i++){
      inf[i] = 0;
    }
    for(i=0;i<(N);i++){
      res[i] = arr[i] = std::numeric_limits<S>::max();
    }
    res[root] = arr[root] = 0;
    t = step;
    if(t==-1){
      t = N;
    }
    for(KL2GvlyY=0;KL2GvlyY<(t);KL2GvlyY++){
      for(i=0;i<(N);i++){
        if(res[i] != std::numeric_limits<S>::max()){
          for(j=0;j<(es[i]);j++){
            chmin(arr[edge[i][j]], res[i] + cost[i][j]);
          }
        }
      }
      for(i=0;i<(N);i++){
        res[i] = arr[i];
      }
    }
    if(step != -1){
      for(i=0;i<(N);i++){
        if(res[i]==std::numeric_limits<S>::max()){
          res[i] = unreachable;
        }
      }
      return;
    }
    for(i=0;i<(N);i++){
      if(res[i] != std::numeric_limits<S>::max()){
        for(j=0;j<(es[i]);j++){
          k = edge[i][j];
          if(arr[k] > res[i] + cost[i][j]){
            inf[k] = 1;
          }
        }
      }
    }
    qs = qe = 0;
    for(i=0;i<(N);i++){
      if(inf[i]){
        q[qe++] = i;
      }
    }
    while(qs < qe){
      i = q[qs++];
      for(j=0;j<(es[i]);j++){
        k = edge[i][j];
        if(inf[k]==0){
          inf[k] = 1;
          q[qe++] = k;
        }
      }
    }
    for(i=0;i<(N);i++){
      if(res[i]==std::numeric_limits<S>::max()){
        res[i] = unreachable;
      }
    }
    for(i=0;i<(N);i++){
      if(inf[i]==1){
        res[i] = minusInf;
      }
    }
  }
  T MST_Prim_cost(void *mem = wmem){
    DijkstraHeap<T> hp;
    T res=0;
    int i, j;
    hp.walloc(N, &mem);
    hp.init(N);
    hp.change(0,0);
    while(hp.size){
      i = hp.pop();
      res += hp.val[i];
      for(j=0;j<(es[i]);j++){
        hp.change(edge[i][j], cost[i][j]);
      }
    }
    return res;
  }
  int MST_Prim_cost(T &res, void *mem = wmem){
    DijkstraHeap<T> hp;
    int cnt=0, i, j;
    res = 0;
    hp.walloc(N, &mem);
    hp.init(N);
    hp.change(0,0);
    while(hp.size){
      i = hp.pop();
      res += hp.val[i];
      cnt++;
      for(j=0;j<(es[i]);j++){
        hp.change(edge[i][j], cost[i][j]);
      }
    }
    if(cnt==N){
      return 1;
    }
    return 0;
  }
}
;
char memarr[96000000];
int N;
int A[1000];
int B[1000];
int C[1000];
wgraph<int> g;
int arr[1001];
int as;
int r;
int ok[1001];
int dp[1001];
int back[1001];
int dfs2(int n, int b){
  int i, j, k, res=1;
  for(i=0;i<(g.es[n]);i++){
    k = g.edge[n][i];
    if(k==b){
      continue;
    }
    res += dfs2(k, n);
  }
  return res;
}
int cnt;
void dfs(int n, int b, int d, int m, int dm){
  int i, j, k;
  for(i=0;i<(g.es[n]);i++){
    if(n==r && ok[i]==dm){
      continue;
    }
    k = g.edge[n][i];
    if(k==b){
      continue;
    }
    cnt++;
    g.cost[n][i] = m * (cnt - d);
    dfs(k, n, cnt, m, dm);
  }
}
int main(){
  int i, j, k, m, p;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N-1);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
    }
  }
  g.setEdge(N,N-1,A,B,C);
  for(r=0;r<(N);r++){
    as = 0;
    for(i=0;i<(g.es[r]);i++){
      arr[as++] = dfs2(g.edge[r][i], r);
    }
    for(i=0;i<(N+1);i++){
      dp[i] = 0;
    }
    dp[0] = 1;
    for(i=0;i<(as);i++){
      for(j=N;j>=arr[i];j--){
        if(!dp[j] && dp[j-arr[i]]){
          dp[j] = 1;
          back[j] = i;
        }
      }
    }
    for(p=0;p<(N+1);p++){
      if(dp[p] && (p+1) * (N-p) - 1 >= 2*N*N/9){
        break;
      }
    }
    if(p==N+1){
      continue;
    }
    k = p;
    while(k){
      ok[back[k]] = 1;
      k -= arr[back[k]];
    }
    cnt = 0;
    dfs(r, -1, 0, 1, 0);
    cnt = 0;
    dfs(r, -1, 0, p+1, 1);
    break;
  }
  for(i=0;i<(N);i++){
    for(j=0;j<(g.es[i]);j++){
      k = g.edge[i][j];
      r = g.cost[i][j];
      if(r > 0){
        wt_L(i+1);
        wt_L(' ');
        wt_L(k+1);
        wt_L(' ');
        wt_L(r);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20190818-1

// --- original code ---
// //no-unlocked
// int N, A[1000], B[1000], C[1000];
// wgraph<int> g;
// 
// int arr[1001], as;
// int r, ok[1001];
// int dp[1001], back[1001];
// 
// int dfs2(int n, int b){
//   int i, j, k, res = 1;
// 
//   rep(i,g.es[n]){
//     k = g.edge[n][i];
//     if(k==b) continue;
//     res += dfs2(k, n);
//   }
// 
//   return res;
// }
// 
// int cnt;
// void dfs(int n, int b, int d, int m, int dm){
//   int i, j, k;
// 
//   rep(i,g.es[n]){
//     if(n==r && ok[i]==dm) continue;
//     k = g.edge[n][i];
//     if(k==b) continue;
//     cnt++;
//     g.cost[n][i] = m * (cnt - d);
//     dfs(k, n, cnt, m, dm);
//   }
// }
// 
// {
//   int i, j, k, p, m;
//   rd(N,(A--,B--)(N-1));
// 
//   g.setEdge(N,N-1,A,B,C);
// 
//   rep(r,N){
//     as = 0;
//     rep(i,g.es[r]) arr[as++] = dfs2(g.edge[r][i], r);
// 
//     rep(i,N+1) dp[i] = 0;
//     dp[0] = 1;
//     rep(i,as) for(j=N;j>=arr[i];j--) if(!dp[j] && dp[j-arr[i]]){
//       dp[j] = 1;
//       back[j] = i;
//     }
// 
//     rep(p,N+1) if(dp[p] && (p+1) * (N-p) - 1 >= 2*N*N/9) break;
//     if(p==N+1) continue;
//     
//     k = p;
//     while(k){
//       ok[back[k]] = 1;
//       k -= arr[back[k]];
//     }
//     
//     cnt = 0;
//     dfs(r, -1, 0, 1, 0);
//     cnt = 0;
//     dfs(r, -1, 0, p+1, 1);
//     break;
//   }
// 
//   rep(i,N) rep(j,g.es[i]){
//     k = g.edge[i][j];
//     r = g.cost[i][j];
//     if(r > 0) wt(i+1, k+1, r);
//   }
// }