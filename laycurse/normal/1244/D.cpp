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
int A[100000];
int B[100000];
int C[3][100000];
int resi[100000];
int deg[100000];
int cnv[100000];
int main(){
  int i;
  wmem = memarr;
  long long res = 4611686016279904256LL;
  long long tmp;
  int ind[3] = {0,1,2};
  graph g;
  rd(N);
  for(i=(0);i<(3);i++){
    {
      int Lj4PdHRW;
      for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
        rd(C[i][Lj4PdHRW]);
      }
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=(0);KL2GvlyY<(N-1);KL2GvlyY++){
      rd(A[KL2GvlyY]);A[KL2GvlyY] += (-1);
      rd(B[KL2GvlyY]);B[KL2GvlyY] += (-1);
    }
  }
  for(i=(0);i<(N-1);i++){
    deg[A[i]]++;
    deg[B[i]]++;
  }
  for(i=(0);i<(N);i++){
    if(deg[i] >= 3){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
  }
  for(i=(0);i<(N);i++){
    if(deg[i] == 1){
      break;
    }
  }
  g.setEdgeRootedTree(N,N-1,A,B,i,1,cnv);
  do{
    tmp = 0;
    for(i=(0);i<(N);i++){
      tmp += C[ind[i%3]][cnv[i]];
    }
    if(tmp < res){
      res = tmp;
      for(i=(0);i<(N);i++){
        resi[cnv[i]] = ind[i%3] + 1;
      }
    }
  }
  while(next_permutation(ind,ind+3));
  wt_L(res);
  wt_L('\n');
  {
    int Q5VJL1cS;
    if(N==0){
      putchar('\n');
    }
    else{
      for(Q5VJL1cS=(0);Q5VJL1cS<(N-1);Q5VJL1cS++){
        wt_L(resi[Q5VJL1cS]);
        wt_L(' ');
      }
      wt_L(resi[Q5VJL1cS]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int N, A[1d5], B[1d5], C[3][1d5];
// int resi[1d5], deg[1d5], cnv[1d5];
// {
//   ll res = ll_inf, tmp;
//   int ind[3] = {0,1,2};
//   graph g;
//   rd(N);
//   rep(i,3) rd(C[i](N));
//   rd((A--,B--)(N-1));
//   rep(i,N-1) deg[A[i]]++, deg[B[i]]++;
// 
//   rep(i,N) if(deg[i] >= 3) wt(-1), return 0;
//   rep(i,N) if(deg[i] == 1) break;
//   g.setEdgeRootedTree(N,N-1,A,B,i,1,cnv);
//   do{
//     tmp = 0;
//     rep(i,N) tmp += C[ind[i%3]][cnv[i]];
//     if(tmp < res){
//       res = tmp;
//       rep(i,N) resi[cnv[i]] = ind[i%3] + 1;
//     }
//   }while(next_permutation(ind,ind+3));
// 
//   wt(res);
//   wt(resi(N));
// }