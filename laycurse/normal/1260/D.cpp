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
void sortF_L(int N, unsigned A[], void *mem = wmem){
  int i;
  int m;
  int bt;
  unsigned *arr;
  unsigned c;
  int *sz;
  if(N < 256){
    sort(A, A+N);
    return;
  }
  bt = sizeof(unsigned) * 8;
  walloc1d(&arr, N, &mem);
  walloc1d(&sz, N, &mem);
  for(m=0;m<bt;m+=8){
    for(i=(0);i<(257);i++){
      sz[i] = 0;
    }
    for(i=(0);i<(N);i++){
      sz[ 1+((A[i]>>m)&255u) ]++;
    }
    for(i=(1);i<(257);i++){
      sz[i] += sz[i-1];
    }
    for(i=(0);i<(N);i++){
      c = ((A[i]>>m)&255u);
      arr[sz[c]++] = A[i];
    }
    swap(A, arr);
  }
}
void sortF_L(int N, int A[], void *mem = wmem){
  int i;
  int x;
  int y;
  int z;
  int *arr;
  unsigned *send;
  if(N < 256){
    sort(A, A+N);
    return;
  }
  send = (unsigned*)A;
  sortF_L(N, send, mem);
  if(A[0] < 0 || A[N-1] >= 0){
    return;
  }
  x = 0;
  y = N;
  while(x < y){
    z = (x+y) / 2;
    if(A[z] < 0){
      y = z;
    }
    else{
      x = z+1;
    }
  }
  walloc1d(&arr, N, &mem);
  z = 0;
  for(i=(x);i<(N);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(x);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(N);i++){
    A[i] = arr[i];
  }
}
void sortF_L(int N, unsigned long long A[], void *mem = wmem){
  int i;
  int m;
  int bt;
  unsigned long long *arr;
  unsigned c;
  int *sz;
  if(N < 512){
    sort(A, A+N);
    return;
  }
  bt = sizeof(unsigned long long) * 8;
  walloc1d(&arr, N, &mem);
  walloc1d(&sz, N, &mem);
  for(m=0;m<bt;m+=8){
    for(i=(0);i<(257);i++){
      sz[i] = 0;
    }
    for(i=(0);i<(N);i++){
      sz[ 1+((A[i]>>m)&255u) ]++;
    }
    for(i=(1);i<(257);i++){
      sz[i] += sz[i-1];
    }
    for(i=(0);i<(N);i++){
      c = ((A[i]>>m)&255u);
      arr[sz[c]++] = A[i];
    }
    swap(A, arr);
  }
}
void sortF_L(int N, long long A[], void *mem = wmem){
  int i;
  int x;
  int y;
  int z;
  long long *arr;
  unsigned long long *send;
  if(N < 512){
    sort(A, A+N);
    return;
  }
  send = (unsigned long long*)A;
  sortF_L(N, send, mem);
  if(A[0] < 0 || A[N-1] >= 0){
    return;
  }
  x = 0;
  y = N;
  while(x < y){
    z = (x+y) / 2;
    if(A[z] < 0){
      y = z;
    }
    else{
      x = z+1;
    }
  }
  walloc1d(&arr, N, &mem);
  z = 0;
  for(i=(x);i<(N);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(x);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(N);i++){
    A[i] = arr[i];
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int M;
int N;
int K;
int T;
int A[200000];
int L[200000];
int R[200000];
int D[200000];
int main(){
  wmem = memarr;
  int res;
  int agi;
  int p;
  int nx;
  int t;
  rd(M);
  rd(N);
  rd(K);
  rd(T);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(K);e98WHCEY++){
      rd(L[e98WHCEY]);
      rd(R[e98WHCEY]);
      rd(D[e98WHCEY]);
    }
  }
  sortF_L(M,A);
  sortA_L(K,L,R,D);
  int FmcKpFmN;
  int xr20shxY;
  int WYIGIcGE;
  FmcKpFmN = 0;
  xr20shxY = M;
  while(FmcKpFmN < xr20shxY){
    int i;
    if((FmcKpFmN + xr20shxY)%2==0){
      WYIGIcGE = (FmcKpFmN + xr20shxY) / 2;
    }
    else{
      WYIGIcGE = (FmcKpFmN + xr20shxY + 1) / 2;
    }
    agi = A[M-WYIGIcGE];
    t = p = 0;
    for(i=(0);i<(K);i++){
      if(D[i] > agi){
        t += (L[i] - 1) - p;
        p = L[i] - 1;
        nx = R[i];
        while(i+1 < K && nx >= L[i+1]){
          i++;
          if(D[i] > agi){
            chmax(nx, R[i]);
          }
        }
        t += 3 * (nx - p);
        p = nx;
      }
    }
    t += N + 1- p;
    if(t <= T){
      FmcKpFmN = WYIGIcGE;
    }
    else{
      xr20shxY = WYIGIcGE - 1;
    }
  }
  res =xr20shxY;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200214-1

// --- original code ---
// //no-unlocked
// int M, N, K, T, A[2d5];
// int L[2d5], R[2d5], D[2d5];
// {
//   int res, agi, p, nx, t;
//   rd(M,N,K,T,A(M),(L,R,D)(K));
//   sortF(M,A);
//   sortA(K,L,R,D);
// 
//   res = bsearch_max[int,x,0,M][
//     agi = A[M-x];
//     t = p = 0;
//     rep(i,K) if(D[i] > agi){
//       t += (L[i] - 1) - p;
//       p = L[i] - 1;
//       nx = R[i];
//       while(i+1 < K && nx >= L[i+1]){
//         i++;
//         if(D[i] > agi) nx >?= R[i];
//       }
//       t += 3 * (nx - p);
//       p = nx;
//     }
//     t += N + 1- p;
//   ](t <= T);
//   wt(res);
// }