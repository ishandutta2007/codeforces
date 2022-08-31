#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
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
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
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
}
;
int N;
int K;
int X[100000];
int Y[100000];
int A[100000];
int res[100000];
graph g;
int dw[100000][40];
int up[100000][40];
int tmp[40];
void dfs1(int n, int b){
  int i;
  int j;
  int k;
  dw[n][0] ^= A[n];
  for(i=(0);i<(g.es[n]);i++){
    j = g.edge[n][i];
    if(j == b){
      continue;
    }
    dfs1(j,n);
    for(k=(0);k<(2*K);k++){
      dw[n][(k+1)%(2*K)] ^= dw[j][k];
    }
  }
}
void dfs2(int n, int b){
  int i;
  int j;
  int k;
  if(b != -1){
    for(k=(0);k<(2*K);k++){
      up[n][(k+1)%(2*K)] ^= up[b][k];
    }
    for(k=(0);k<(2*K);k++){
      up[n][(k+1)%(2*K)] ^= dw[b][k] ^ dw[n][(moddw_L((k-1),(2*K)))];
    }
  }
  for(i=(0);i<(g.es[n]);i++){
    j = g.edge[n][i];
    if(j == b){
      continue;
    }
    dfs2(j,n);
  }
}
int main(){
  int i;
  wmem = memarr;
  rd(N);
  rd(K);
  {
    int KrdatlYV;
    for(KrdatlYV=(0);KrdatlYV<(N-1);KrdatlYV++){
      rd(X[KrdatlYV]);X[KrdatlYV] += (-1);
      rd(Y[KrdatlYV]);Y[KrdatlYV] += (-1);
    }
  }
  {
    int a2conNHc;
    for(a2conNHc=(0);a2conNHc<(N);a2conNHc++){
      rd(A[a2conNHc]);
    }
  }
  g.setEdge(N,N-1,X,Y);
  dfs1(0, -1);
  dfs2(0, -1);
  for(i=(0);i<(N);i++){
    int j;
    for(j=(K);j<(2*K);j++){
      res[i] ^= dw[i][j] ^ up[i][j];
    }
  }
  for(i=(0);i<(N);i++){
    if(res[i]){
      res[i] = 1;
    }
  }
  {
    int AlM5nNnR;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(AlM5nNnR=(0);AlM5nNnR<(N-1);AlM5nNnR++){
        wt_L(res[AlM5nNnR]);
        wt_L(' ');
      }
      wt_L(res[AlM5nNnR]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210328-1 [beta]

// --- original code ---
// //no-unlocked
// int N, K, X[1d5], Y[], A[], res[];
// graph g;
// int dw[1d5][40], up[1d5][40], tmp[40];
// 
// void dfs1(int n, int b){
//   int i, j, k;
//   dw[n][0] ^= A[n];
//   rep(i,g.es[n]){
//     j = g.edge[n][i];
//     if(j == b) continue;
//     dfs1(j,n);
//     rep(k,2*K) dw[n][(k+1)%(2*K)] ^= dw[j][k];
//   }
// }
// 
// void dfs2(int n, int b){
//   int i, j, k;
// 
//   if(b != -1){
//     rep(k,2*K) up[n][(k+1)%(2*K)] ^= up[b][k];
//     rep(k,2*K) up[n][(k+1)%(2*K)] ^= dw[b][k] ^ dw[n][(k-1)%%(2*K)];
//   }
//   rep(i,g.es[n]){
//     j = g.edge[n][i];
//     if(j == b) continue;
//     dfs2(j,n);
//   }
// }
// 
// {
//   rd(N,K,(X--,Y--)(N-1),A(N));
//   g.setEdge(N,N-1,X,Y);
//   dfs1(0, -1);
//   dfs2(0, -1);
//   rep(i,N) rep(j,K,2*K) res[i] ^= dw[i][j] ^ up[i][j];
//   rep(i,N) if(res[i]) res[i] = 1;
//   wt(res(N));
// }