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
  int shortestUndirectedCycle_length(void *mem=wmem){
    int *arr, i, j, k, *q, qe, qs, r, res;
    for(i=0;i<(N);i++){
      for(j=0;j<(es[i]);j++){
        if(edge[i][j]==i){
          return 1;
        }
      }
    }
    walloc1d(&arr, N, &mem);
    for(i=0;i<(N);i++){
      arr[i] = -1;
    }
    for(i=0;i<(N);i++){
      for(j=0;j<(es[i]);j++){
        k = edge[i][j];
        if(arr[k]==i){
          return 2;
        }
        arr[k] = i;
      }
    }
    walloc1d(&q, N, &mem);
    res = 1073709056;
    for(r=0;r<(N);r++){
      for(i=0;i<(N);i++){
        arr[i] = -1;
      }
      arr[r] = 0;
      qs = qe = 0;
      q[qe++] = r;
      while(qs < qe){
        i = q[qs++];
        for(j=0;j<(es[i]);j++){
          k = edge[i][j];
          if(arr[k]==-1){
            arr[k] = arr[i] + 1;
            q[qe++] = k;
            continue;
          }
          if(arr[k]==arr[i]){
            chmin(res, 2* arr[i] + 1);
          }
          if(arr[k]==arr[i]+1){
            chmin(res, 2* arr[k]);
          }
        }
      }
    }
    if(res==1073709056){
      res = -1;
    }
    return res;
  }
}
;
char memarr[96000000];
#define MD 2520
int N;
int M;
int K[1000];
int A[10000];
int B[10000];
int Q;
int X;
int Y;
graph g;
int dp[1000][MD];
int vis[1000][MD];
int vn[1000];
int vns;
int main(){
  int Q5VJL1cS, i, j, k, res, x, y;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(K[Lj4PdHRW]);
    }
  }
  for(i=0;i<(N);i++){
    int KL2GvlyY;
    rd(k);
    for(KL2GvlyY=0;KL2GvlyY<(k);KL2GvlyY++){
      rd(j);j += (-1);
      A[M] = i;
      B[M++] = j;
    }
  }
  g.setDirectEdge(N,M,A,B);
  for(i=0;i<(N);i++){
    (K[i] = moddw_L(K[i],MD));
  }
  rd(Q);
  for(Q5VJL1cS=0;Q5VJL1cS<(Q);Q5VJL1cS++){
    rd(X);X += (-1);
    rd(Y);
    (Y = moddw_L(Y,MD));
    if(dp[X][Y]==0){
      x = X;
      y = Y;
      while(vis[x][y]==0){
        vis[x][y] = 1;
        y = (y + K[x]) % MD;
        x = g.edge[x][y%g.es[x]];
      }
      if(dp[x][y]==0){
        res = 0;
        vns++;
        while(vis[x][y]==1){
          vis[x][y] = 2;
          if(vn[x] != vns){
            vn[x] = vns;
            res++;
          }
          y = (y + K[x]) % MD;
          x = g.edge[x][y%g.es[x]];
        }
      }
      else{
        res = dp[x][y];
      }
      x = X;
      y = Y;
      while(dp[x][y]==0){
        dp[x][y] = res;
        y = (y + K[x]) % MD;
        x = g.edge[x][y%g.es[x]];
      }
    }
    wt_L(dp[X][Y]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// #define MD 2520
// int N, M, K[1000], A[10000], B[10000], Q, X, Y;
// graph g;
// 
// int dp[1000][MD];
// int vis[1000][MD];
// 
// int vn[1000], vns;
// 
// {
//   int i, j, k, x, y, res;
// 
//   rd(N,K(N));
//   rep(i,N){
//     rd(k);
//     rep(k){
//       rd(j--);
//       A[M] = i;
//       B[M++] = j;
//     }
//   }
//   g.setDirectEdge(N,M,A,B);
// 
//   rep(i,N) K[i] %%= MD;
// 
//   rd(Q);
//   rep(Q){
//     rd(X--,Y);
//     Y %%= MD;
// 
//     if(dp[X][Y]==0){
//       x = X;
//       y = Y;
//       while(vis[x][y]==0){
//         vis[x][y] = 1;
//         y = (y + K[x]) % MD;
//         x = g.edge[x][y%g.es[x]];
//       }
// 
//       if(dp[x][y]==0){
//         res = 0;
//         vns++;
//         while(vis[x][y]==1){
//           vis[x][y] = 2;
//           if(vn[x] != vns) vn[x] = vns, res++;
//           y = (y + K[x]) % MD;
//           x = g.edge[x][y%g.es[x]];
//         }
//       } else {
//         res = dp[x][y];
//       }
// 
//       x = X;
//       y = Y;
//       while(dp[x][y]==0){
//         dp[x][y] = res;
//         y = (y + K[x]) % MD;
//         x = g.edge[x][y%g.es[x]];
//       }
//     }
// 
//     wt(dp[X][Y]);
//   }
// }