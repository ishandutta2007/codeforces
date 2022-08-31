#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
  return getchar();
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
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
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
}
;
int N;
int M;
int A[1000];
int B[1000];
int mx;
graph g;
int sz;
int arr[1000];
int ok[1000];
void dfs(int n){
  int Lj4PdHRW;
  for(Lj4PdHRW=(0);Lj4PdHRW<(g.es[n]);Lj4PdHRW++){
    auto&i = g.edge[n][Lj4PdHRW];
    arrInsert(M,M,A,n,B,i);
    dfs(i);
  }
}
int q(int sz, int arr[]){
  wt_L("?");
  wt_L(' ');
  wt_L(sz);
  wt_L(' ');
  {
    int e98WHCEY;
    if(sz==0){
      wt_L('\n');
    }
    else{
      for(e98WHCEY=(0);e98WHCEY<(sz-1);e98WHCEY++){
        wt_L(arr[e98WHCEY]+1);
        wt_L(' ');
      }
      wt_L(arr[e98WHCEY]+1);
      wt_L('\n');
    }
  }
  return rd_int();
}
int main(){
  int i;
  wmem = memarr;
  int m;
  rd(N);
  {
    int FmcKpFmN;
    for(FmcKpFmN=(0);FmcKpFmN<(N-1);FmcKpFmN++){
      rd(A[FmcKpFmN]);A[FmcKpFmN] += (-1);
      rd(B[FmcKpFmN]);B[FmcKpFmN] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    arr[i] = i;
  }
  mx = q(N, arr);
  g.setEdgeRootedTree(N, N-1, A, B);
  dfs(0);
  while(M > 1){
    for(i=(0);i<(N);i++){
      ok[i] = 0;
    }
    for(i=(0);i<(M/2);i++){
      ok[A[i]] = ok[B[i]] = 1;
    }
    sz = 0;
    for(i=(0);i<(N);i++){
      if(ok[i]){
        arr[sz++] = i;
      }
    }
    m = 0;
    if(q(sz, arr) == mx){
      for(i=(0);i<(M);i++){
        if(ok[A[i]] && ok[B[i]]){
          arrInsert(m, m, A, A[i], B, B[i]);
        }
      }
    }
    else{
      for(i=(0);i<(M);i++){
        if(!(ok[A[i]] && ok[B[i]])){
          arrInsert(m, m, A, A[i], B, B[i]);
        }
      }
    }
    M = m;
  }
  wt_L("!");
  wt_L(' ');
  wt_L(A[0]+1);
  wt_L(' ');
  wt_L(B[0]+1);
  wt_L('\n');
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //interactive
// int N, M, A[1000], B[], mx;
// graph g;
// int sz, arr[], ok[];
// 
// void dfs(int n){
//   rep[g.edge[n]](i,g.es[n]){
//     arrInsert(M,M,A,n,B,i);
//     dfs(i);
//   }
// }
// 
// int q(int sz, int arr[]){
//   wt("?",sz,arr(sz)+1);
//   return rd_int();
// }
// 
// {
//   int m;
//   rd(N,(A--,B--)(N-1));
// 
//   rep(i,N) arr[i] = i;
//   mx = q(N, arr);
// 
//   g.setEdgeRootedTree(N, N-1, A, B);
//   dfs(0);
// 
//   while(M > 1){
//     rep(i,N) ok[i] = 0;
//     rep(i,M/2) ok[A[i]] = ok[B[i]] = 1;
//     sz = 0;
//     rep(i,N) if(ok[i]) arr[sz++] = i;
//     m = 0;
//     if(q(sz, arr) == mx){
//       rep(i,M) if(ok[A[i]] && ok[B[i]]) arrInsert(m, m, A, A[i], B, B[i]);
//     } else {
//       rep(i,M) if(!(ok[A[i]] && ok[B[i]])) arrInsert(m, m, A, A[i], B, B[i]);
//     }
//     M = m;
//   }
//   wt("!", A[0]+1, B[0]+1);
// }