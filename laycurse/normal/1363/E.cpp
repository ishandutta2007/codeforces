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
int A[200000];
int B[200000];
int C[200000];
int X[200000];
int Y[200000];
graph g;
long long res;
void solve(int n, int c, int &z, int &o){
  int Lj4PdHRW;
  int sz;
  int so;
  chmin(c, A[n]);
  for(Lj4PdHRW=(0);Lj4PdHRW<(g.es[n]);Lj4PdHRW++){
    auto &i = g.edge[n][Lj4PdHRW];
    sz = so = 0;
    solve(i,c,sz,so);
    z += sz;
    o += so;
  }
  if(B[n]==0 && C[n]==1){
    if(o){
      o--;
      res += c;
    }
    else{
      z++;
    }
  }
  if(B[n]==1 && C[n]==0){
    if(z){
      z--;
      res += c;
    }
    else{
      o++;
    }
  }
  while(z && o){
    z--;
    o--;
    res += c;
  }
}
int main(){
  wmem = memarr;
  int z = 0;
  int o = 0;
  rd(N);
  {
    int RZTsC2BF;
    for(RZTsC2BF=(0);RZTsC2BF<(N);RZTsC2BF++){
      rd(A[RZTsC2BF]);
      rd(B[RZTsC2BF]);
      rd(C[RZTsC2BF]);
    }
  }
  {
    int WYIGIcGE;
    for(WYIGIcGE=(0);WYIGIcGE<(N-1);WYIGIcGE++){
      rd(X[WYIGIcGE]);X[WYIGIcGE] += (-1);
      rd(Y[WYIGIcGE]);Y[WYIGIcGE] += (-1);
    }
  }
  int ao_dF3pO;
  int tU__gIr_;
  if(N==0){
    tU__gIr_ = 0;
  }
  else{
    tU__gIr_ = B[0];
    for(ao_dF3pO=(1);ao_dF3pO<(N);ao_dF3pO++){
      tU__gIr_ += B[ao_dF3pO];
    }
  }
  int V9aVTaxx;
  int APIVbQlN;
  if(N==0){
    APIVbQlN = 0;
  }
  else{
    APIVbQlN = C[0];
    for(V9aVTaxx=(1);V9aVTaxx<(N);V9aVTaxx++){
      APIVbQlN += C[V9aVTaxx];
    }
  }
  if(tU__gIr_!=APIVbQlN){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  g.setEdgeRootedTree(N,N-1,X,Y);
  solve(0, 1073709056, z, o);
  wt_L(2*res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], B[2d5], C[2d5], X[2d5], Y[2d5];
// graph g;
// ll res;
// 
// void solve(int n, int c, int &z, int &o){
//   int sz, so;
//   c <?= A[n];
//   rep[g.edge[n]](i,g.es[n]){
//     sz = so = 0;
//     solve(i,c,sz,so);
//     z += sz;
//     o += so;
//   }
//   if(B[n]==0 && C[n]==1){
//     if(o) o--, res += c;
//     else  z++;
//   }
//   if(B[n]==1 && C[n]==0){
//     if(z) z--, res += c;
//     else  o++;
//   }
//   while(z && o){
//     z--;
//     o--;
//     res += c;
//   }
// }
// 
// {
//   int z = 0, o = 0;
//   rd(N,(A,B,C)(N),(X--,Y--)(N-1));
//   if(sum(B(N)) != sum(C(N))) wt(-1), return 0;
//   g.setEdgeRootedTree(N,N-1,X,Y);
//   solve(0, int_inf, z, o);
//   wt(2*res);
// }