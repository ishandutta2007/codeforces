#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
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
int N;
int A[100000];
int solve(int N, int A[], int b){
  int i;
  int x;
  if(b==-1){
    return 0;
  }
  int Lj4PdHRW;
  int KL2GvlyY;
  int Q5VJL1cS;
  Lj4PdHRW = 0;
  KL2GvlyY = N;
  while(Lj4PdHRW < KL2GvlyY){
    if((Lj4PdHRW + KL2GvlyY)%2==0){
      Q5VJL1cS = (Lj4PdHRW + KL2GvlyY) / 2;
    }
    else{
      Q5VJL1cS = (Lj4PdHRW + KL2GvlyY - 1) / 2;
    }
    if(A[Q5VJL1cS] >= (1<<b)){
      KL2GvlyY = Q5VJL1cS;
    }
    else{
      Lj4PdHRW = Q5VJL1cS + 1;
    }
  }
  x =KL2GvlyY;
  for(i=(x);i<(N);i++){
    A[i] ^= (1<<b);
  }
  if(x==0 || x==N){
    return solve(N,A,b-1);
  }
  return (1<<b) +min_L(solve(x,A,b-1), solve(N-x,A+x,b-1));
}
int main(){
  wmem = memarr;
  int res;
  rd(N);
  {
    int WYIGIcGE;
    for(WYIGIcGE=(0);WYIGIcGE<(N);WYIGIcGE++){
      rd(A[WYIGIcGE]);
    }
  }
  sortF_L(N,A);
  res = solve(N, A, 29);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// 
// int solve(int N, int A[], int b){
//   int x;
//   if(b==-1) return 0;
// 
//   x = bsearch_min[int,x,0,N](A[x] >= (1<<b));
//   rep(i,x,N) A[i] ^= (1<<b);
//   if(x==0 || x==N) return solve(N,A,b-1);
//   return (1<<b) + min(solve(x,A,b-1), solve(N-x,A+x,b-1));
// }
// 
// {
//   int res;
//   rd(N,A(N));
//   sortF(N,A);
//   res = solve(N, A, 29);
//   wt(res);
// }