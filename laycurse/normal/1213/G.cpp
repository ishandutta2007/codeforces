#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16]={0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for(i=0;i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=0;i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> > *arr;
  walloc1d(&arr, N, &mem);
  for(i=0;i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=0;i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
}
inline void rd(int &x){
  int k, m=0;
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
inline void wt_L(long long x){
  char f[20];
  int m=0, s=0;
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
struct unionFind{
  int M, N, *d;
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
    for(i=0;i<(n);i++){
      d[i] = -1;
    }
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    int k, t=a;
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
  inline int sizeList(int res[]){
    int i, sz=0;
    for(i=0;i<(N);i++){
      if(d[i]<0){
        res[sz++] = -d[i];
      }
    }
    return sz;
  }
}
;
char memarr[96000000];
int N;
int T;
int A[200000];
int B[200000];
int C[200000];
int Q[200000];
int ind[200000];
int sz[200000];
long long res[200000];
int main(){
  int i, j, k, m, t;
  long long tmp=0;
  unionFind uf;
  wmem = memarr;
  rd(N);
  rd(T);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N-1);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
      rd(C[Lj4PdHRW]);
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=0;KL2GvlyY<(T);KL2GvlyY++){
      rd(Q[KL2GvlyY]);
    }
  }
  sortA_L(N-1, C, A, B);
  for(i=0;i<(T);i++){
    ind[i] = i;
  }
  sortA_L(T, Q, ind);
  uf.walloc(N);
  uf.init(N);
  for(i=0;i<(N);i++){
    sz[i] = 1;
  }
  m = 0;
  for(t=0;t<(T);t++){
    while(m < N-1 && C[m] <= Q[t]){
      i = uf(A[m]);
      j = uf(B[m]);
      m++;
      if(i==j){
        continue;
      }
      uf(i,j);
      k = uf(i);
      tmp += (long long)sz[i] * sz[j];
      sz[k] = sz[i] + sz[j];
    }
    res[ind[t]] = tmp;
  }
  {
    int Q5VJL1cS;
    if(T==0){
      putchar('\n');
    }
    else{
      for(Q5VJL1cS=0;Q5VJL1cS<(T-1);Q5VJL1cS++){
        wt_L(res[Q5VJL1cS]);
        wt_L(' ');
      }
      wt_L(res[Q5VJL1cS]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int N, T, A[2d5], B[2d5], C[2d5], Q[2d5];
// int ind[2d5], sz[2d5];
// ll res[2d5];
// {
//   int i, j, k, m, t;
//   ll tmp = 0;
//   unionFind uf;
// 
//   rd(N,T,(A--,B--,C)(N-1),Q(T));
//   sortA(N-1, C, A, B);
//   rep(i,T) ind[i] = i;
//   sortA(T, Q, ind);
// 
//   uf.walloc(N);
//   uf.init(N);
// 
//   rep(i,N) sz[i] = 1;
//   m = 0;
//   rep(t,T){
//     while(m < N-1 && C[m] <= Q[t]){
//       i = uf(A[m]);
//       j = uf(B[m]);
//       m++;
//       if(i==j) continue;
//       uf(i,j);
//       k = uf(i);
// 
//       tmp += (ll)sz[i] * sz[j];
//       sz[k] = sz[i] + sz[j];
//     }
//     res[ind[t]] = tmp;
//   }
// 
//   wt(res(T));
// }