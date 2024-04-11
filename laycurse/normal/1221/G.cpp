#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
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
inline void rd(int &x){
  int k;
  int m=0;
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
struct unionFind{
  int *d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
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
  int *es;
  int **edge;
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
  graph reduce(int tn, int ind[], int self_e = 0, int dep_e = 0, void **mem = &wmem){
    int i;
    int j;
    int k;
    int M = 0;
    int x;
    int y;
    graph g;
    void *tmem;
    pair<int,int> *A;
    for(i=(0);i<(N);i++){
      M += es[i];
    }
    tmem = ((char*)(*mem)) + sizeof(int**) * N + sizeof(int*) * N + sizeof(int) * M + 16 * (N+2);
    walloc1d(&A, M, &tmem);
    M = 0;
    for(i=(0);i<(N);i++){
      x = ind[i];
      if(x < 0){
        continue;
      }
      for(j=(0);j<(es[i]);j++){
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
      for(i=(0);i<(M);i++){
        if(k && A[k-1]==A[i]){
          continue;
        }
        A[k++] = A[i];
      }
      M = k;
    }
    g.N = tn;
    walloc1d(&g.es, tn, mem);
    walloc1d(&g.edge, tn, mem);
    for(i=(0);i<(tn);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      g.es[A[i].first]++;
    }
    for(i=(0);i<(tn);i++){
      walloc1d(&g.edge[i], g.es[i], mem);
    }
    for(i=(0);i<(tn);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i].first;
      k = A[i].second;
      g.edge[j][g.es[j]++] = k;
    }
    return g;
  }
  void articulationDFS(int n, int b, int &k, int od[], int lw[], int vs[], int &ress, int res[]){
    int i;
    int j;
    int a = 0;
    int c = 0;
    vs[n] = 1;
    lw[n] = od[n] = k++;
    for(i=(0);i<(es[n]);i++){
      j = edge[n][i];
      if(j==b){
        continue;
      }
      if(!vs[j]){
        c++;
        articulationDFS(j, n, k, od, lw, vs, ress, res);
        chmin(lw[n], lw[j]);
        if(b != -1 && od[n] <= lw[j]){
          a = 1;
        }
      }
      else{
        chmin(lw[n], od[j]);
      }
    }
    if(b == -1 && c >= 2){
      a = 1;
    }
    if(a){
      res[ress++] = n;
    }
  }
  int articulation(int res[], void *mem=wmem){
    int i;
    int k = 0;
    int ress = 0;
    int *od;
    int *lw;
    int *vs;
    walloc1d(&od, N, &mem);
    walloc1d(&lw, N, &mem);
    walloc1d(&vs, N, &mem);
    for(i=(0);i<(N);i++){
      vs[i] = 0;
    }
    for(i=(0);i<(N);i++){
      if(!vs[i]){
        articulationDFS(i, -1, k, od, lw, vs, ress, res);
      }
    }
    return ress;
  }
  long long countIndependenceSet(void *mem = wmem, int skip = 0){
    int i;
    int j;
    int k;
    int x;
    long long res;
    int *deg;
    int *ind;
    long long *pr;
    graph g;
    unionFind uf;
    void *tmem;
    if(N == 0){
      return 1;
    }
    if(N == 1){
      return 2;
    }
    walloc1d(&deg, N, &mem);
    walloc1d(&ind, N, &mem);
    walloc1d(&pr, N, &mem);
    if(!skip){
      k = 0;
      uf.walloc(N, &mem);
      uf.init(N);
      for(i=(0);i<(N);i++){
        for(j=(0);j<(es[i]);j++){
          k += uf(i,edge[i][j]);
        }
      }
      if(k < N-1){
        res = 1;
        for(i=(0);i<(N);i++){
          deg[i] = 0;
        }
        for(i=(0);i<(N);i++){
          deg[uf(i)]++;
        }
        for(x=(0);x<(N);x++){
          if(deg[x]){
            k = 0;
            for(i=(0);i<(N);i++){
              if(uf(i)!=x){
                ind[i] = -1;
                continue;
              }
              ind[i] = k++;
            }
            tmem = mem;
            g = reduce(k, ind, 1, 1, &mem);
            res *= g.countIndependenceSet(mem, 1);
            mem = tmem;
          }
        }
        return res;
      }
    }
    k = articulation(ind);
    for(i=(0);i<(N);i++){
      pr[i] = 0;
    }
    for(i=(0);i<(k);i++){
      pr[ind[i]] += (1LL<<40);
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        pr[i] += (1LL<<20) - es[edge[i][j]];
      }
    }
    {
      int cTE1_r3A;
      int RZTsC2BF = 0;
      long long FmcKpFmN;
      long long xr20shxY;
      int WYIGIcGE;
      for(cTE1_r3A=(0);cTE1_r3A<(((N)-1)+1);cTE1_r3A++){
        xr20shxY = pr[cTE1_r3A];
        if(RZTsC2BF==0 || FmcKpFmN<xr20shxY){
          FmcKpFmN = xr20shxY;
          RZTsC2BF = 1;
          WYIGIcGE = cTE1_r3A;
        }
      }
      x =WYIGIcGE;
    }
    res = 0;
    k = 0;
    for(i=(0);i<(N);i++){
      if(i == x){
        ind[i] = -1;
        continue;
      }
      ind[i] = k++;
    }
    tmem = mem;
    g = reduce(k, ind, 1, 1, &mem);
    res += g.countIndependenceSet(mem);
    mem = tmem;
    k = 0;
    for(i=(0);i<(N);i++){
      deg[i] = 0;
    }
    deg[x] = 1;
    for(j=(0);j<(es[x]);j++){
      deg[edge[x][j]] = 1;
    }
    for(i=(0);i<(N);i++){
      if(deg[i]){
        ind[i] = -1;
        continue;
      }
      ind[i] = k++;
    }
    g = reduce(k, ind, 1, 1, &mem);
    res += g.countIndependenceSet(mem);
    return res;
  }
  int bipartite(int res[] = NULL, void *mem = wmem){
    int i;
    int j;
    int k;
    int *st;
    int sts;
    if(res==NULL){
      walloc1d(&res, N, &mem);
    }
    walloc1d(&st, N, &mem);
    for(i=(0);i<(N);i++){
      res[i] = -1;
    }
    for(i=(0);i<(N);i++){
      if(res[i]==-1){
        res[i] = 0;
        sts = 0;
        st[sts++] = i;
        while(sts){
          i = st[--sts];
          for(j=(0);j<(es[i]);j++){
            k = edge[i][j];
            if(res[k]==-1){
              res[k] = 1 - res[i];
              st[sts++] = k;
            }
            if(res[i] + res[k] != 1){
              return 0;
            }
          }
        }
      }
    }
    return 1;
  }
}
;
int N;
int M;
int A[1000];
int B[1000];
int ind[40];
long long dp[8];
long long nx[8];
long long now[8];
int main(){
  int x;
  wmem = memarr;
  int i;
  int j;
  int k;
  unionFind uf;
  graph og;
  graph g;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
    }
  }
  og.setEdge(N,M,A,B);
  uf.malloc(N);
  uf.init(N);
  for(i=(0);i<(M);i++){
    uf(A[i],B[i]);
  }
  dp[0] = 1;
  for(x=(0);x<(N);x++){
    k = 0;
    for(i=(0);i<(N);i++){
      if(uf(i)!=x){
        ind[i] = -1;
      }
      else{
        ind[i] = k++;
      }
    }
    if(!k){
      continue;
    }
    if(k==1){
      for(i=(0);i<(8);i++){
        now[i] = 0;
      }
      now[0] = 2;
    }
    else{
      g = og.reduce(k, ind, 1, 1);
      now[0] = now[5] = 0;
      now[1] = now[4] = 1;
      now[2] = 2 * g.bipartite();
      now[3] = now[6] = g.countIndependenceSet() - 1 - now[2];
      {
        int KL2GvlyY;
        long long Q5VJL1cS;
        if(7==0){
          Q5VJL1cS = 0;
        }
        else{
          Q5VJL1cS = now[0];
          for(KL2GvlyY=(1);KL2GvlyY<(7);KL2GvlyY++){
            Q5VJL1cS += now[KL2GvlyY];
          }
        }
        now[7] = (1LL<<k) -Q5VJL1cS;
      }
    }
    for(i=(0);i<(8);i++){
      nx[i] = 0;
    }
    for(i=(0);i<(8);i++){
      for(j=(0);j<(8);j++){
        nx[i|j] += dp[i] * now[j];
      }
    }
    for(i=(0);i<(8);i++){
      dp[i] = nx[i];
    }
  }
  wt_L(dp[7]);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// //no-unlocked
// int N, M, A[1000], B[1000], ind[40];
// ll dp[8], nx[8], now[8];
// {
//   int i, j, k;
//   unionFind uf;
//   graph og, g;
//   
//   rd(N,M,(A--,B--)(M));
//   og.setEdge(N,M,A,B);
// 
//   uf.malloc(N);
//   uf.init(N);
//   rep(i,M) uf(A[i],B[i]);
// 
//   dp[0] = 1;
//   rep(x,N){
//     k = 0;
//     rep(i,N){
//       if(uf(i)!=x) ind[i] = -1;
//       else         ind[i] = k++;
//     }
//     if(!k) continue;
// 
//     if(k==1){
//       rep(i,8) now[i] = 0;
//       now[0] = 2;
//     } else {
//       g = og.reduce(k, ind, 1, 1);
//       now[0] = now[5] = 0;
//       now[1] = now[4] = 1;
//       now[2] = 2 * g.bipartite();
//       now[3] = now[6] = g.countIndependenceSet() - 1 - now[2];
//       now[7] = (1LL<<k) - sum(now(7));
//     }
//     
//     rep(i,8) nx[i] = 0;
//     rep(i,8) rep(j,8) nx[i|j] += dp[i] * now[j];
//     rep(i,8) dp[i] = nx[i];
//   }
//   wt(dp[7]);
// }