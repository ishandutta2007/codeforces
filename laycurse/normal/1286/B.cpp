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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class S> void arrErase(int k, int &sz, S a[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
}
template<class S, class T> void arrErase(int k, int &sz, S a[], T b[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
}
template<class S, class T, class U> void arrErase(int k, int &sz, S a[], T b[], U c[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
  for(i=(k);i<(sz);i++){
    c[i] = c[i+1];
  }
}
template<class S> void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
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
template<class S, class T, class U> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
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
int P[2000];
int C[2000];
int r;
int m;
int a[2000];
int b[2000];
int sz[2000];
int val[2000];
graph g;
int A[2000];
int getsz(int n){
  int Lj4PdHRW;
  sz[n] = 1;
  for(Lj4PdHRW=(0);Lj4PdHRW<(g.es[n]);Lj4PdHRW++){
    auto &i = g.edge[n][Lj4PdHRW];
    sz[n] += getsz(i);
  }
  return sz[n];
}
void solve(int n, int val[]){
  int e98WHCEY;
  int i;
  int st = 0;
  int k = sz[n];
  A[n] = val[C[n]];
  arrErase(C[n], k, val);
  for(e98WHCEY=(0);e98WHCEY<(g.es[n]);e98WHCEY++){
    auto &i = g.edge[n][e98WHCEY];
    solve(i, val + st);
    st += sz[i];
  }
}
int main(){
  int i;
  wmem = memarr;
  rd(N);
  {
    int FmcKpFmN;
    for(FmcKpFmN=(0);FmcKpFmN<(N);FmcKpFmN++){
      rd(P[FmcKpFmN]);P[FmcKpFmN] += (-1);
      rd(C[FmcKpFmN]);
    }
  }
  for(i=(0);i<(N);i++){
    if(P[i]==-1){
      r = i;
      continue;
    }
    arrInsert(m,m,a,i,b,P[i]);
  }
  g.setEdgeRootedTree(N,m,a,b,r);
  getsz(r);
  for(i=(0);i<(N);i++){
    if(C[i] >= sz[i]){
      wt_L("NO");
      wt_L('\n');
      return 0;
    }
  }
  for(i=(0);i<(N);i++){
    val[i] = i+1;
  }
  solve(r, val);
  wt_L("YES");
  wt_L('\n');
  {
    int V9aVTaxx;
    if(N==0){
      putchar('\n');
    }
    else{
      for(V9aVTaxx=(0);V9aVTaxx<(N-1);V9aVTaxx++){
        wt_L(A[V9aVTaxx]);
        wt_L(' ');
      }
      wt_L(A[V9aVTaxx]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// int N, P[2000], C[2000];
// 
// int r, m, a[2000], b[2000];
// int sz[2000], val[2000];
// graph g;
// int A[2000];
// 
// int getsz(int n){
//   sz[n] = 1;
//   rep[g.edge[n]](i,g.es[n]) sz[n] += getsz(i);
//   return sz[n];
// }
// 
// void solve(int n, int val[]){
//   int i, st = 0, k = sz[n];
//   A[n] = val[C[n]];
//   arrErase(C[n], k, val);
//   rep[g.edge[n]](i,g.es[n]){
//     solve(i, val + st);
//     st += sz[i];
//   }
// }
// 
// {
//   rd(N,(P--,C)(N));
//   rep(i,N){
//     if(P[i]==-1) r = i, continue;
//     arrInsert(m,m,a,i,b,P[i]);
//   }
//   g.setEdgeRootedTree(N,m,a,b,r);
//   getsz(r);
//   rep(i,N) if(C[i] >= sz[i]) wt("NO"), return 0;
//   rep(i,N) val[i] = i+1;
//   solve(r, val);
//   wt("YES");
//   wt(A(N));
// }