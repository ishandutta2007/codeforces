#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[10485760];
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
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
  int shortestPath(const int s, const int t, int res[], void *mem=wmem){
    int i;
    int j;
    int k;
    int *q;
    int qs = 0;
    int qe = 0;
    int *b;
    walloc1d(&b, N, &mem);
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      b[i] = -1;
    }
    b[s] = -2;
    q[qe++] = s;
    while(qe > qs){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
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
}
;
int N;
int X[5000];
int Y[5000];
int M;
int A[5000];
int B[5000];
int V[5000];
graph g;
int ps[5000];
int p[5000][5000];
int res[5000][5000];
int resarr[5000];
int main(){
  int i, k;
  wmem = memarr;
  int mn;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N-1);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);X[Lj4PdHRW] += (-1);
      rd(Y[Lj4PdHRW]);Y[Lj4PdHRW] += (-1);
    }
  }
  rd(M);
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(M);e98WHCEY++){
      rd(A[e98WHCEY]);A[e98WHCEY] += (-1);
      rd(B[e98WHCEY]);B[e98WHCEY] += (-1);
      rd(V[e98WHCEY]);
    }
  }
  g.setEdge(N,N-1,X,Y);
  for(i=(0);i<(N-1);i++){
    res[X[i]][Y[i]] = res[Y[i]][X[i]] = 1;
  }
  for(k=(0);k<(M);k++){
    ps[k] = g.shortestPath(A[k], B[k], p[k]);
  }
  for(k=(0);k<(M);k++){
    for(i=(0);i<(ps[k]);i++){
      chmax(res[p[k][i+1]][p[k][i]], V[k]);
      chmax(res[p[k][i]][p[k][i+1]], V[k]);
    }
  }
  for(k=(0);k<(M);k++){
    mn = 1073709056;
    for(i=(0);i<(ps[k]);i++){
      chmin(mn, res[p[k][i+1]][p[k][i]]);
    }
    if(V[k] != mn){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
  }
  for(i=(0);i<(N-1);i++){
    resarr[i] = res[X[i]][Y[i]];
  }
  {
    int ZIeRIny5;
    if(N-1==0){
      wt_L('\n');
    }
    else{
      for(ZIeRIny5=(0);ZIeRIny5<(N-1-1);ZIeRIny5++){
        wt_L(resarr[ZIeRIny5]);
        wt_L(' ');
      }
      wt_L(resarr[ZIeRIny5]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// //working_memory=10MB
// int N, X[5000], Y[5000];
// int M, A[5000], B[5000], V[5000];
// 
// graph g;
// int ps[5000], p[5000][5000];
// int res[5000][5000], resarr[5000];
// {
//   int mn;
//   rd(N,(X--,Y--)(N-1),M,(A--,B--,V)(M));
//   g.setEdge(N,N-1,X,Y);
//   rep(i,N-1) res[X[i]][Y[i]] = res[Y[i]][X[i]] = 1;
// 
//   rep(k,M) ps[k] = g.shortestPath(A[k], B[k], p[k]);
//   rep(k,M) rep(i,ps[k]){
//     res[p[k][i+1]][p[k][i]] >?= V[k];
//     res[p[k][i]][p[k][i+1]] >?= V[k];
//   }
//   rep(k,M){
//     mn = int_inf;
//     rep(i,ps[k]) mn <?= res[p[k][i+1]][p[k][i]];
//     if(V[k] != mn) wt(-1), return 0;
//   }
// 
//   rep(i,N-1) resarr[i] = res[X[i]][Y[i]];
//   wt(resarr(N-1));
// }