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
  int TopologicalSort(int res[], void *mem=wmem){
    int i;
    int j;
    int k;
    int rs;
    int *deg;
    int *q;
    int qs = 0;
    int qe = 0;
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
int N;
int M;
int A[5000];
int B[5000];
int d[5000];
int main(){
  wmem = memarr;
  int res;
  graph g;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
    }
  }
  g.setDirectEdge(N,M,A,B);
  res = g.TopologicalSort(d);
  if(res){
    int i;
    res = 1;
    for(i=0;i<(M);i++){
      d[i] = 1;
    }
  }
  else{
    int i;
    res = 2;
    for(i=0;i<(M);i++){
      if(A[i] < B[i]){
        d[i] =1;
      }
      else{
        d[i] =2;
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  {
    int KL2GvlyY;
    if(M==0){
      putchar('\n');
    }
    else{
      for(KL2GvlyY=0;KL2GvlyY<(M-1);KL2GvlyY++){
        wt_L(d[KL2GvlyY]);
        wt_L(' ');
      }
      wt_L(d[KL2GvlyY]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int N, M, A[5000], B[5000];
// int d[5000];
// {
//   int res;
//   graph g;
//   rd(N,M,(A--,B--)(M));
//   g.setDirectEdge(N,M,A,B);
//   res = g.TopologicalSort(d);
//   if(res){
//     res = 1;
//     rep(i,M) d[i] = 1;
//   } else {
//     res = 2;
//     rep(i,M) d[i] = if[A[i] < B[i], 1, 2];
//   }
//   wt(res);
//   wt(d(M));
// }