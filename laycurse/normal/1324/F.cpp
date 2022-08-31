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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
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
int U[200000];
int V[200000];
int A[200000];
graph g;
int dp1[200000];
int dp2[200000];
int dfs1(int n){
  int Lj4PdHRW;
  dp1[n] = A[n];
  for(Lj4PdHRW=(0);Lj4PdHRW<(g.es[n]);Lj4PdHRW++){
    auto &i = g.edge[n][Lj4PdHRW];
    dp1[n] +=max_L(0, dfs1(i));
  }
  return dp1[n];
}
void dfs2(int n, int b = -1){
  int FmcKpFmN;
  dp2[n] = dp1[n];
  if(b != -1){
    dp2[n] +=max_L(0, dp2[b] -max_L(0, dp1[n]));
  }
  for(FmcKpFmN=(0);FmcKpFmN<(g.es[n]);FmcKpFmN++){
    auto &i = g.edge[n][FmcKpFmN];
    dfs2(i,n);
  }
}
int main(){
  int i;
  wmem = memarr;
  rd(N);
  {
    int t_ynMSdg;
    for(t_ynMSdg=(0);t_ynMSdg<(N);t_ynMSdg++){
      rd(A[t_ynMSdg]);
    }
  }
  {
    int tU__gIr_;
    for(tU__gIr_=(0);tU__gIr_<(N-1);tU__gIr_++){
      rd(U[tU__gIr_]);U[tU__gIr_] += (-1);
      rd(V[tU__gIr_]);V[tU__gIr_] += (-1);
    }
  }
  g.setEdgeRootedTree(N,N-1,U,V);
  for(i=(0);i<(N);i++){
    A[i] = 2* A[i] - 1;
  }
  dfs1(0);
  dfs2(0);
  {
    int YREPHmFM;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(YREPHmFM=(0);YREPHmFM<(N-1);YREPHmFM++){
        wt_L(dp2[YREPHmFM]);
        wt_L(' ');
      }
      wt_L(dp2[YREPHmFM]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200308-1

// --- original code ---
// //no-unlocked
// int N, U[2d5], V[2d5], A[2d5];
// graph g;
// int dp1[2d5], dp2[2d5];
// 
// int dfs1(int n){
//   dp1[n] = A[n];
//   rep[g.edge[n]](i,g.es[n]) dp1[n] += max(0, dfs1(i));
//   return dp1[n];
// }
// 
// void dfs2(int n, int b = -1){
//   dp2[n] = dp1[n];
//   if(b != -1) dp2[n] += max(0, dp2[b] - max(0, dp1[n]));
//   rep[g.edge[n]](i,g.es[n]) dfs2(i,n);
// }
// 
// {
//   rd(N,A(N),(U--,V--)(N-1));
//   g.setEdgeRootedTree(N,N-1,U,V);
//   rep(i,N) A[i] = 2 A[i] - 1;
//   dfs1(0);
//   dfs2(0);
//   wt(dp2(N));
// }