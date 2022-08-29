#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
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
struct graph{
  int N;
  int*es;
  int**edge;
  void setEdgeRootedTree(int N__, int M, int A[], int B[], int root=0, int reorder=0, int cnv[] = NULL, void **mem = &wmem){
    int i;
    int j;
    int k;
    int*dist;
    int*q;
    int qs;
    int qe;
    int*ind;
    void*tmem;
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
  int preorder(int res[], int root = 0, void *mem=wmem){
    int i;
    int j;
    int k;
    int sts;
    int sz = 0;
    long long*st;
    char*vis;
    walloc1d(&vis, N, &mem);
    walloc1d(&st, N, &mem);
    sts = 0;
    st[sts++] = ((long long)root) << 32;
    for(i=(0);i<(N);i++){
      vis[i] = 0;
    }
    vis[root] = 1;
    while(sts){
      i = st[--sts] >> 32;
      j = st[sts] & 2147483647;
      if(j==0){
        res[sz++] = i;
      }
      while(j < es[i]){
        k = edge[i][j++];
        if(vis[k]){
          continue;
        }
        if(j < es[i]){
          st[sts++] = (((long long)i) << 32) + j;
        }
        vis[k] = 1;
        st[sts++] = ((long long)k) << 32;
        break;
      }
    }
    return sz;
  }
}
;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int N;
  int K;
  int A[100000];
  int X[100000];
  int Y[100000];
  int pre[100000];
  int w[100000];
  int sm;
  int ok;
  graph g;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int hCmBdyQB;
    rd(N);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N-1);xr20shxY++){
        rd(X[xr20shxY]);X[xr20shxY] += (-1);
        rd(Y[xr20shxY]);Y[xr20shxY] += (-1);
      }
    }
    g.setEdgeRootedTree(N,N-1,X,Y);
    int KrdatlYV;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type ao_dF3pO;
    if(N==0){
      ao_dF3pO = 0;
    }
    else{
      ao_dF3pO = A[0];
      for(KrdatlYV=(1);KrdatlYV<(N);KrdatlYV++){
        ao_dF3pO ^= A[KrdatlYV];
      }
    }
    sm =ao_dF3pO;
    ok = 0;
    g.preorder(pre);
    for(hCmBdyQB=(N)-1;hCmBdyQB>=(0);hCmBdyQB--){
      int YREPHmFM;
      auto&i = pre[hCmBdyQB];
      w[i] = A[i];
      for(YREPHmFM=(0);YREPHmFM<(g.es[i]);YREPHmFM++){
        auto&j = g.edge[i][YREPHmFM];
        w[i] ^= w[j];
      }
      if(w[i] == sm){
        ok++;
        w[i] = 0;
      }
    }
    if(sm==0 && ok){
      wt_L("YES");
      wt_L('\n');
      continue;
    }
    if(K >= 3 && ok >= 2){
      wt_L("YES");
      wt_L('\n');
      continue;
    }
    wt_L("NO");
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int N, K, A[1d5], X[], Y[], pre[], w[], sm, ok;
// graph g;
// REP(rd_int()){
//   rd(N,K,A(N),(X--,Y--)(N-1));
//   g.setEdgeRootedTree(N,N-1,X,Y);
//   sm = XOR(A(N));
//   ok = 0;
//   g.preorder(pre);
//   rrep[pre](i,N){
//     w[i] = A[i];
//     rep[g.edge[i]](j,g.es[i]) w[i] ^= w[j];
//     if(w[i] == sm) ok++, w[i] = 0;
//   }
//   if(sm==0 && ok) wt("YES"), continue;
//   if(K >= 3 && ok >= 2) wt("YES"), continue;
//   wt("NO");
// }