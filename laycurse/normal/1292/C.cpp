#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
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
}
;
template<class T> struct wgraph{
  int N;
  int *es;
  int **edge;
  T **cost;
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
int A[3000];
int B[3000];
int c[3000];
wgraph<int> g;
int sz[3000];
int up[3000];
int cnt[3000][3000];
int ind1[3000][3000];
int ind2[3000][3000];
long long dp[2][2][3000][3000];
int getsz(int n, int b){
  int i;
  int j;
  int v;
  up[n] = b;
  sz[n] = 1;
  for(i=(0);i<(g.es[n]);i++){
    j = g.edge[n][i];
    if(j==b){
      continue;
    }
    v = getsz(j, n);
    sz[n] += v;
    g.cost[n][i] = v;
  }
  if(up[n] >= 0){
    for(i=(0);i<(g.es[n]);i++){
      j = g.edge[n][i];
      if(j!=b){
        continue;
      }
      g.cost[n][i] = g.N - sz[n];
    }
  }
  return sz[n];
}
long long solve(int d1, int d2, int e1, int e2){
  int i;
  int j;
  int a0;
  int a1;
  int b0;
  int b1;
  long long res = 0;
  if(e1 > e2){
    swap(d1, d2);
    swap(e1, e2);
  }
  if(dp[d1][d2][e1][e2]){
    return dp[d1][d2][e1][e2];
  }
  a0 = A[e1];
  a1 = B[e1];
  if(d1){
    swap(a0, a1);
  }
  b0 = A[e2];
  b1 = B[e2];
  if(d2){
    swap(b0, b1);
  }
  for(i=(0);i<(g.es[a1]);i++){
    j = g.edge[a1][i];
    if(j==a0){
      continue;
    }
    chmax(res, solve(ind2[a1][j], d2, ind1[a1][j], e2));
  }
  for(i=(0);i<(g.es[b1]);i++){
    j = g.edge[b1][i];
    if(j==b0){
      continue;
    }
    chmax(res, solve(d1, ind2[b1][j], e1, ind1[b1][j]));
  }
  res += cnt[a0][a1] * cnt[b0][b1];
  return dp[d1][d2][e1][e2] = res;
}
int main(){
  wmem = memarr;
  long long res = 0;
  int i;
  int j;
  int k;
  int a0;
  int a1;
  int b0;
  int b1;
  int mx;
  int c0;
  int c1;
  int d0;
  int d1;
  rd(N);
  {
    int WYIGIcGE;
    for(WYIGIcGE=(0);WYIGIcGE<(N-1);WYIGIcGE++){
      rd(A[WYIGIcGE]);A[WYIGIcGE] += (-1);
      rd(B[WYIGIcGE]);B[WYIGIcGE] += (-1);
    }
  }
  g.setEdge(N,N-1,A,B,c);
  getsz(0, -1);
  for(i=(0);i<(N);i++){
    for(j=(0);j<(g.es[i]);j++){
      k = g.edge[i][j];
      cnt[i][k] = g.cost[i][j];
    }
  }
  for(i=(0);i<(N-1);i++){
    ind1[A[i]][B[i]] = ind1[B[i]][A[i]] = i;
    ind2[A[i]][B[i]] = 0;
    ind2[B[i]][A[i]] = 1;
  }
  for(k=(0);k<(N-1);k++){
    chmax(res, solve(0, 1, k, k));
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// int N, A[3000], B[3000], c[3000];
// 
// wgraph<int> g;
// int sz[3000], up[3000];
// int cnt[3000][3000], ind1[3000][3000], ind2[3000][3000];
// ll dp[2][2][3000][3000];
// 
// int getsz(int n, int b){
//   int i, j, v;
// 
//   up[n] = b;
//   sz[n] = 1;
// 
//   rep(i,g.es[n]){
//     j = g.edge[n][i];
//     if(j==b) continue;
//     v = getsz(j, n);
//     sz[n] += v;
//     g.cost[n][i] = v;
//   }
// 
//   if(up[n] >= 0){
//     rep(i,g.es[n]){
//       j = g.edge[n][i];
//       if(j!=b) continue;
//       g.cost[n][i] = g.N - sz[n];
//     }
//   }
// 
//   return sz[n];
// }
// 
// ll solve(int d1, int d2, int e1, int e2){
//   int i, j, a0, a1, b0, b1;
//   ll res = 0;
// 
//   if(e1 > e2){
//     swap(d1, d2);
//     swap(e1, e2);
//   }
// 
//   if(dp[d1][d2][e1][e2]) return dp[d1][d2][e1][e2];
// 
//   a0 = A[e1]; a1 = B[e1]; if(d1) swap(a0, a1);
//   b0 = A[e2]; b1 = B[e2]; if(d2) swap(b0, b1);
// 
//   rep(i,g.es[a1]){
//     j = g.edge[a1][i];
//     if(j==a0) continue;
//     res >?= solve(ind2[a1][j], d2, ind1[a1][j], e2);
//   }
//   rep(i,g.es[b1]){
//     j = g.edge[b1][i];
//     if(j==b0) continue;
//     res >?= solve(d1, ind2[b1][j], e1, ind1[b1][j]);
//   }
//   
//   res += cnt[a0][a1] * cnt[b0][b1];
// 
//   //wt(a0,a1,b0,b1,res);
//   return dp[d1][d2][e1][e2] = res;
// }
// 
// {
//   ll res = 0;
//   int i, j, k, a0, a1, b0, b1, mx;
//   int c0, c1, d0, d1;
//   rd(N,(A--,B--)(N-1));
//   g.setEdge(N,N-1,A,B,c);
//   getsz(0, -1);
//   rep(i,N) rep(j,g.es[i]){
//     k = g.edge[i][j];
//     cnt[i][k] = g.cost[i][j];
//   }
// 
//   rep(i,N-1){
//     ind1[A[i]][B[i]] = ind1[B[i]][A[i]] = i;
//     ind2[A[i]][B[i]] = 0;
//     ind2[B[i]][A[i]] = 1;
//   }
// 
//   rep(k,N-1) res >?= solve(0, 1, k, k);
//   wt(res);
// }