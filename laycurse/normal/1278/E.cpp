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
int A[500000];
int B[500000];
graph g;
int sz;
int arr[1000000];
int res[500000][2];
void solve(int n){
  int i;
  int j;
  for(i=(0);i<(g.es[n]);i++){
    arr[sz++] = g.edge[n][i];
  }
  arr[sz++] = n;
  for(i=(g.es[n])-1;i>=(0);i--){
    solve(g.edge[n][i]);
  }
}
int main(){
  wmem = memarr;
  int i;
  int j;
  rd(N);
  {
    int cTE1_r3A;
    for(cTE1_r3A=(0);cTE1_r3A<(N-1);cTE1_r3A++){
      rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      rd(B[cTE1_r3A]);B[cTE1_r3A] += (-1);
    }
  }
  g.setEdgeRootedTree(N,N-1,A,B);
  arr[sz++] = 0;
  solve(0);
  for(i=(0);i<(sz);i++){
    j = arr[i];
    if(res[j][0]==0){
      res[j][0] = i+1;
      continue;
    }
    res[j][1] = i+1;
  }
  for(i=(0);i<(N);i++){
    wt_L(res[i][0]);
    wt_L(' ');
    wt_L(res[i][1]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191214-1

// --- original code ---
// //no-unlocked
// int N, A[5d5], B[5d5];
// graph g;
// 
// int sz, arr[1d6];
// int res[5d5][2];
// 
// void solve(int n){
//   int i, j;
//   rep(i,g.es[n]) arr[sz++] = g.edge[n][i];
//   arr[sz++] = n;
//   rrep(i,g.es[n]) solve(g.edge[n][i]);
// }
// 
// {
//   int i, j;
// 
//   rd(N,(A--,B--)(N-1));
//   g.setEdgeRootedTree(N,N-1,A,B);
// 
//   arr[sz++] = 0;
//   solve(0);
// 
//   rep(i,sz){
//     j = arr[i];
//     if(res[j][0]==0) res[j][0] = i+1, continue;
//     res[j][1] = i+1;
//   }
//   rep(i,N) wt(res[i][0], res[i][1]);
// }