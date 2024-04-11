#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
int N;
int M;
int Q;
int A[1000000];
int B[1000000];
int C[1000000];
int X[1000000];
int Y[1000000];
int L[1000000];
long long dist[600][600];
long long q[600][600];
long long mn[600][600];
int main(){
  int i, k, x;
  int res = 0;
  long long mx;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
      rd(C[Lj4PdHRW]);
    }
  }
  rd(Q);
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(Q);e98WHCEY++){
      rd(X[e98WHCEY]);X[e98WHCEY] += (-1);
      rd(Y[e98WHCEY]);Y[e98WHCEY] += (-1);
      rd(L[e98WHCEY]);
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      dist[i][j] = 4611686016279904256LL;
    }
  }
  for(i=(0);i<(N);i++){
    dist[i][i] = 0;
  }
  for(i=(0);i<(M);i++){
    chmin(dist[A[i]][B[i]], C[i]);
  }
  for(i=(0);i<(M);i++){
    chmin(dist[B[i]][A[i]], C[i]);
  }
  for(k=(0);k<(N);k++){
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      q[i][j] = -1;
    }
  }
  for(i=(0);i<(Q);i++){
    chmax(q[X[i]][Y[i]], L[i]);
  }
  for(i=(0);i<(Q);i++){
    chmax(q[Y[i]][X[i]], L[i]);
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      mn[i][j] = -4611686016279904256LL;
    }
  }
  for(x=(0);x<(N);x++){
    int z;
    for(z=(0);z<(N);z++){
      int y;
      mx = -1;
      for(i=(0);i<(N);i++){
        chmax(mx, q[x][i] - dist[z][i]);
      }
      for(y=(0);y<(N);y++){
        chmax(mn[y][z], mx - dist[x][y]);
      }
    }
  }
  for(i=(0);i<(M);i++){
    if(mn[A[i]][B[i]] >= C[i]){
      res++;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210321-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M, Q, A[1d6], B[], C[], X[], Y[], L[];
// ll dist[600][600];
// ll q[][], mn[][];
// {
//   int res = 0;
//   ll mx;
//   rd(N,M,(A--,B--,C)(M));
//   rd(Q,(X--,Y--,L)(Q));
//   rep(i,N) rep(j,N) dist[i][j] = ll_inf;
//   rep(i,N) dist[i][i] = 0;
//   rep(i,M) dist[A[i]][B[i]] <?= C[i];
//   rep(i,M) dist[B[i]][A[i]] <?= C[i];
//   rep(k,N) rep(i,N) rep(j,N) dist[i][j] <?= dist[i][k] + dist[k][j];
// 
//   rep(i,N) rep(j,N) q[i][j] = -1;
//   rep(i,Q) q[X[i]][Y[i]] >?= L[i];
//   rep(i,Q) q[Y[i]][X[i]] >?= L[i];
// 
//   rep(i,N) rep(j,N) mn[i][j] = -ll_inf;
// 
//   rep(x,N){
//     rep(z,N){
//       mx = -1;
//       rep(i,N) mx >?= q[x][i] - dist[z][i];
//       rep(y,N) mn[y][z] >?= mx - dist[x][y];
//     }
//   }
//   rep(i,M) if(mn[A[i]][B[i]] >= C[i]) res++;
//   wt(res);
// }