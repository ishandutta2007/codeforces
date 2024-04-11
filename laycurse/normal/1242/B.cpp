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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> > *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
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
struct unionFind{
  int *d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void init(const int n){
    int i;
    N = n;
    for(i=(0);i<(n);i++){
      d[i] = -1;
    }
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    int t = a;
    int k;
    while(d[t]>=0){
      t=d[t];
    }
    while(d[a]>=0){
      k=d[a];
      d[a]=t;
      a=k;
    }
    return a;
  }
  inline int connect(int a, int b){
    if(d[a]>=0){
      a=get(a);
    }
    if(d[b]>=0){
      b=get(b);
    }
    if(a==b){
      return 0;
    }
    if(d[a] < d[b]){
      d[a] += d[b];
      d[b] = a;
    }
    else{
      d[b] += d[a];
      d[a] = b;
    }
    return 1;
  }
  inline int operator()(int a){
    return get(a);
  }
  inline int operator()(int a, int b){
    return connect(a,b);
  }
  inline int& operator[](const int a){
    return d[a];
  }
  inline int size(int a){
    a = get(a);
    return -d[a];
  }
  inline int sizeList(int res[]){
    int i;
    int sz=0;
    for(i=(0);i<(N);i++){
      if(d[i]<0){
        res[sz++] = -d[i];
      }
    }
    return sz;
  }
}
;
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
}
;
int N;
int M;
int A[100000];
int B[100000];
int nn;
int ind[100000];
int mat[1000][1000];
int cnt[1000];
int mm;
int a[500000];
int b[500000];
int c[500000];
graph g;
graph tn;
int main(){
  int a2conNHc;
  wmem = memarr;
  int i;
  int j;
  int k;
  int res = 0;
  unionFind uf;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
    }
  }
  g.setEdge(N,M,A,B);
  {
    int cTE1_r3A;
    int RZTsC2BF = 0;
    int FmcKpFmN;
    int xr20shxY;
    int WYIGIcGE;
    for(cTE1_r3A=(0);cTE1_r3A<(((N)-1)+1);cTE1_r3A++){
      xr20shxY = g.es[cTE1_r3A];
      if(RZTsC2BF==0 || FmcKpFmN>xr20shxY){
        FmcKpFmN = xr20shxY;
        RZTsC2BF = 1;
        WYIGIcGE = cTE1_r3A;
      }
    }
    k =WYIGIcGE;
  }
  if(g.es[k]==N-1){
    wt_L(N-1);
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N);i++){
    ind[i] = 0;
  }
  nn = 1;
  for(a2conNHc=(0);a2conNHc<(g.es[k]);a2conNHc++){
    auto &i = g.edge[k][a2conNHc];
    ind[i] = nn++;
  }
  for(i=(0);i<(nn);i++){
    for(j=(0);j<(nn);j++){
      mat[i][j] = 0;
    }
  }
  for(i=(0);i<(M);i++){
    j = ind[A[i]];
    k = ind[B[i]];
    mat[j][k]++;
    mat[k][j]++;
  }
  for(i=(0);i<(N);i++){
    cnt[ind[i]]++;
  }
  for(i=(0);i<(nn);i++){
    for(j=(i+1);j<(nn);j++){
      if(mat[i][j]==cnt[i]*cnt[j]){
        k =1;
      }
      else{
        k =0;
      }
      arrInsert(mm, mm, a, i, b, j, c, k);
    }
  }
  sortA_L(mm, c, a, b);
  uf.malloc(nn);
  uf.init(nn);
  for(i=(0);i<(mm);i++){
    if(uf(a[i],b[i])){
      res += c[i];
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// int N, M, A[1d5], B[1d5];
// int nn, ind[1d5];
// int mat[1000][1000], cnt[1000];
// int mm, a[5d5], b[5d5], c[5d5];
// graph g, tn;
// {
//   int i, j, k, res = 0;
//   unionFind uf;
//   rd(N,M,(A--,B--)(M));
//   g.setEdge(N,M,A,B);
//   k = argmin(g.es(N));
//   if(g.es[k]==N-1) wt(N-1), return 0;
// 
//   rep(i,N) ind[i] = 0;
//   nn = 1;
//   rep[g.edge[k]](i,g.es[k]) ind[i] = nn++;
// 
//   rep(i,nn) rep(j,nn) mat[i][j] = 0;
//   rep(i,M){
//     j = ind[A[i]];
//     k = ind[B[i]];
//     mat[j][k]++;
//     mat[k][j]++;
//   }
//   rep(i,N) cnt[ind[i]]++;
// 
//   rep(i,nn) rep(j,i+1,nn){
//     k = if[mat[i][j]==cnt[i]*cnt[j], 1, 0];
//     arrInsert(mm, mm, a, i, b, j, c, k);
//   }
//   sortA(mm, c, a, b);
// 
//   uf.malloc(nn);
//   uf.init(nn);
// 
//   rep(i,mm) if(uf(a[i],b[i])) res += c[i];
//   wt(res);
// }