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
inline void rd(long long &x){
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
int M;
int A[100000];
int B[100000];
long long P[100000];
long long H[100000];
graph g;
long long good[100000];
long long bad[100000];
int doit(int n){
  int Lj4PdHRW;
  long long t;
  long long gn;
  long long bn;
  good[n] = 0;
  bad[n] = P[n];
  for(Lj4PdHRW=(0);Lj4PdHRW<(g.es[n]);Lj4PdHRW++){
    auto &i = g.edge[n][Lj4PdHRW];
    if(!doit(i)){
      return 0;
    }
    {
      auto e98WHCEY = (good[i]);
      auto cTE1_r3A = ( bad[i]);
      good[n] += e98WHCEY;
      bad[n] += cTE1_r3A;
    }
  }
  t = good[n] + bad[n];
  if((moddw_L(t,2))!=(moddw_L(H[n],2))){
    return 0;
  }
  gn = (t + H[n]) / 2;
  bn = (t - H[n]) / 2;
  if(gn < 0 || bn < 0){
    return 0;
  }
  if(gn < good[n]){
    return 0;
  }
  {
    auto RZTsC2BF = (gn);
    auto FmcKpFmN = ( bn);
    good[n] = RZTsC2BF;
    bad[n] = FmcKpFmN;
  }
  return 1;
}
int main(){
  int xr20shxY;
  wmem = memarr;
  int WYIGIcGE = rd_int();
  for(xr20shxY=(0);xr20shxY<(WYIGIcGE);xr20shxY++){
    int res;
    rd(N);
    rd(M);
    {
      int ao_dF3pO;
      for(ao_dF3pO=(0);ao_dF3pO<(N);ao_dF3pO++){
        rd(P[ao_dF3pO]);
      }
    }
    {
      int hCmBdyQB;
      for(hCmBdyQB=(0);hCmBdyQB<(N);hCmBdyQB++){
        rd(H[hCmBdyQB]);
      }
    }
    {
      int YREPHmFM;
      for(YREPHmFM=(0);YREPHmFM<(N-1);YREPHmFM++){
        rd(A[YREPHmFM]);A[YREPHmFM] += (-1);
        rd(B[YREPHmFM]);B[YREPHmFM] += (-1);
      }
    }
    g.setEdgeRootedTree(N,N-1,A,B);
    res = doit(0);
    if(res){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, A[1d5], B[1d5]; ll P[1d5], H[1d5];
// graph g;
// 
// ll good[1d5], bad[1d5];
// int doit(int n){
//   ll t, gn, bn;
//   good[n] = 0;
//   bad[n] = P[n];
//   rep[g.edge[n]](i,g.es[n]){
//     if(!doit(i)) return 0;
//     (good[n], bad[n]) += (good[i], bad[i]);
//   }
// 
//   t = good[n] + bad[n];
//   if(t%%2 != H[n]%%2) return 0;
//   gn = (t + H[n]) / 2;
//   bn = (t - H[n]) / 2;
//   if(gn < 0 || bn < 0) return 0;
//   if(gn < good[n]) return 0;
//   (good[n], bad[n]) = (gn, bn);
//   return 1;
// }
// 
// {
//   REP(rd_int()){
//     int res;
//     rd(N,M,P(N),H(N),(A--,B--)(N-1));
//     g.setEdgeRootedTree(N,N-1,A,B);
//     res = doit(0);
//     wt(if[res, "YES", "NO"]);
//   }
// }