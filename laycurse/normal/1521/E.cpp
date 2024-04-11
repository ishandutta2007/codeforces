#pragma GCC optimize ("Ofast")
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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int M;
int K;
int A[200000];
int sz;
int arr[200000];
int ind[200000];
int n;
int res[1000][1000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(M);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(K);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(K);i++){
      ind[i] = i+1;
    }
    sortA_L(K, A, ind);
    sz = n = 0;
    for(i=(0);i<(K);i++){
      int ao_dF3pO;
      for(ao_dF3pO=(0);ao_dF3pO<(A[i]);ao_dF3pO++){
        arr[sz++] = ind[i];
      }
    }
    while( ((divup_L(n,2))) * n + (n/2) * ((divup_L(n,2))) < M ){
      n++;
    }
    while( ((divup_L(n,2))) * n < A[K-1] ){
      n++;
    }
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(n);j++){
        res[i][j] = 0;
      }
    }
    for(i=(0);i<(n);i+=(2)){
      int j;
      for(j=(1);j<(n);j+=(2)){
        if(sz > 0){
          res[i][j] = arr[--sz];
        }
      }
    }
    for(i=(0);i<(n);i+=(2)){
      int j;
      for(j=(0);j<(n);j+=(2)){
        if(sz > 0){
          res[i][j] = arr[--sz];
        }
      }
    }
    for(i=(1);i<(n);i+=(2)){
      int j;
      for(j=(0);j<(n);j+=(2)){
        if(sz > 0){
          res[i][j] = arr[--sz];
        }
      }
    }
    wt_L(n);
    wt_L('\n');
    {
      int szDqbNYU;
      int ytthggxT;
      for(szDqbNYU=(0);szDqbNYU<(n);szDqbNYU++){
        if(n==0){
          wt_L('\n');
        }
        else{
          for(ytthggxT=(0);ytthggxT<(n-1);ytthggxT++){
            wt_L(res[szDqbNYU][ytthggxT]);
            wt_L(' ');
          }
          wt_L(res[szDqbNYU][ytthggxT]);
          wt_L('\n');
        }
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int M, K, A[2d5];
// int sz, arr[], ind[];
// int n, res[1000][1000];
// {
//   REP(rd_int()){
//     rd(M,K,A(K));
// 
//     rep(i,K) ind[i] = i+1;
//     sortA(K, A, ind);
// 
//     sz = n = 0;
//     rep(i,K) rep(A[i]) arr[sz++] = ind[i];
// 
//     while( (n/+2) * n + (n/2) * (n/+2) < M ) n++;
//     while( (n/+2) * n < A[K-1] ) n++;
// 
//     rep(i,n) rep(j,n) res[i][j] = 0;
//     rep(i,0,n,2) rep(j,1,n,2) if(sz > 0) res[i][j] = arr[--sz];
//     rep(i,0,n,2) rep(j,0,n,2) if(sz > 0) res[i][j] = arr[--sz];
//     rep(i,1,n,2) rep(j,0,n,2) if(sz > 0) res[i][j] = arr[--sz];
// 
//     wt(n);
//     wt(res(n,n));
//   }
// }