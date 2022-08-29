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
  void setEdgeRootedTree(int N__, int M, int A[], int B[], int root=0, int reorder=0, int cnv[] = NULL, void **mem = &wmem){
    int i;
    int j;
    int k;
    int *dist;
    int *q;
    int qs;
    int qe;
    int *ind;
    void *tmem;
    N = N__;
    tmem = ((char*)(*mem)) + (sizeof(int) * N + 15) + (sizeof(int*) * N + 15) + (sizeof(int) * M + 15 * N);
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
      walloc1d(&edge[i], es[i], &tmem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
    walloc1d(&dist, N, &tmem);
    walloc1d(&q, N, &tmem);
    walloc1d(&ind, N, &tmem);
    if(cnv==NULL){
      walloc1d(&cnv, N, &tmem);
    }
    for(i=(0);i<(N);i++){
      dist[i] = -1;
    }
    dist[root] = 0;
    qs = qe = 0;
    q[qe++] = root;
    while(qs < qe){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(dist[k]==-1){
          dist[k] = dist[i] + 1;
          q[qe++] = k;
        }
      }
    }
    if(reorder == 0){
      for(i=(0);i<(N);i++){
        cnv[i] = i;
      }
      for(i=(0);i<(N);i++){
        ind[i] = i;
      }
    }
    else{
      for(i=(0);i<(N);i++){
        cnv[i] = q[i];
      }
      for(i=(0);i<(N);i++){
        ind[cnv[i]] = i;
      }
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      es[ind[j]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      j = ind[j];
      k = ind[k];
      edge[j][es[j]++] = k;
    }
  }
}
;
int N;
int K;
int U[200];
int V[200];
int A[200];
int AA[200];
int cnv[200];
graph g;
int dp[200][202];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int x;
  int y;
  int res;
  int tmp;
  int mx;
  rd(N);
  rd(K);K += (1);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(AA[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N-1);e98WHCEY++){
      rd(U[e98WHCEY]);U[e98WHCEY] += (-1);
      rd(V[e98WHCEY]);V[e98WHCEY] += (-1);
    }
  }
  g.setEdgeRootedTree(N,N-1,U,V,0,1,cnv);
  for(i=(0);i<(N);i++){
    A[i] = AA[cnv[i]];
  }
  for(i=(N)-1;i>=(0);i--){
    for(k=(K+1)-1;k>=(0);k--){
      int hCmBdyQB;
      dp[i][k] = 0;
      if(k < K){
        dp[i][k] = dp[i][k+1];
      }
      if(k == 0){
        chmax(dp[i][k], dp[i][K] + A[i]);
      }
      x =max_L(k-1, 0);
      y =max_L(x, K - x - 2);
      mx = tmp = 0;
      for(hCmBdyQB=(0);hCmBdyQB<(g.es[i]);hCmBdyQB++){
        auto &j = g.edge[i][hCmBdyQB];
        tmp += dp[j][y];
        chmax(mx, dp[j][x] - dp[j][y]);
      }
      chmax(dp[i][k], tmp + mx);
    }
  }
  wt_L(dp[0][0]);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// int N, K, U[200], V[200];
// int A[200], AA[200], cnv[200];
// 
// graph g;
// int dp[200][202];
// 
// {
//   int i, j, k, x, y, res, tmp, mx;
// 
//   rd(N,K++,AA(N),(U--,V--)(N-1));
//   g.setEdgeRootedTree(N,N-1,U,V,0,1,cnv);
//   rep(i,N) A[i] = AA[cnv[i]];
// 
//   rrep(i,N) rrep(k,K+1){
//     dp[i][k] = 0;
//     if(k < K) dp[i][k] = dp[i][k+1];
//     if(k == 0) dp[i][k] >?= dp[i][K] + A[i];
// 
//     x = max(k-1, 0);
//     y = max(x, K - x - 2);
//     mx = tmp = 0;
//     rep[g.edge[i]](j,g.es[i]){
//       tmp += dp[j][y];
//       mx >?= dp[j][x] - dp[j][y];
//     }
//     dp[i][k] >?= tmp + mx;
//   }
// 
//   wt(dp[0][0]);
// }