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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
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
inline int BIT_popcount_L(const int x){
  return __builtin_popcount(x);
}
inline int BIT_popcount_L(const long long x){
  return __builtin_popcountll(x);
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int P;
int K;
int A[100000];
int S[100000][7];
int val[100000];
int ind[100000];
long long dp[128];
long long nx[128];
int bt[128];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int m;
  rd(N);
  rd(P);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    {
      int RZTsC2BF;
      for(RZTsC2BF=(0);RZTsC2BF<(P);RZTsC2BF++){
        rd(S[i][RZTsC2BF]);
      }
    }
  }
  for(i=(0);i<(N);i++){
    val[i] = A[i];
    ind[i] = i;
  }
  rsortA_L(N, val, ind);
  for(i=(0);i<(1<<P);i++){
    bt[i] =BIT_popcount_L(i);
  }
  for(i=(1);i<(1<<P);i++){
    dp[i] = -4611686016279904256LL;
  }
  for(j=(0);j<(N);j++){
    k = ind[j];
    for(i=(0);i<(1<<P);i++){
      nx[i] = -4611686016279904256LL;
    }
    for(i=(0);i<(1<<P);i++){
      if(dp[i] >= 0){
        chmax(nx[i], dp[i]);
        if(j-bt[i] < K){
          chmax(nx[i], dp[i] + A[k]);
        }
        for(m=(0);m<(P);m++){
          if(!((i) &(1<<(m)))){
            chmax(nx[i^(1<<m)], dp[i] + S[k][m]);
          }
        }
      }
    }
    for(i=(0);i<(1<<P);i++){
      dp[i] = nx[i];
    }
  }
  wt_L(dp[(1<<P) - 1]);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200303-1 [beta]

// --- original code ---
// //no-unlocked
// int N, P, K;
// int A[1d5], S[1d5][7];
// int val[1d5], ind[1d5];
// ll dp[128], nx[128]; int bt[128];
// {
//   int i, j, k, m;
//   rd(N,P,K,A(N));
//   rep(i,N) rd(S[i](P));
//   rep(i,N) val[i] = A[i], ind[i] = i;
//   rsortA(N, val, ind);
// 
//   rep(i,1<<P) bt[i] = BIT_popcount(i);
// 
//   rep(i,1,1<<P) dp[i] = -ll_inf;
//   rep(j,N){
//     k = ind[j];
//     rep(i,1<<P) nx[i] = -ll_inf;
//     rep(i,1<<P) if(dp[i] >= 0){
//       nx[i] >?= dp[i];
//       if(j-bt[i] < K) nx[i] >?= dp[i] + A[k];
//       rep(m,P) if(!BIT_ith(i,m)) nx[i^(1<<m)] >?= dp[i] + S[k][m];
//     }
//     rep(i,1<<P) dp[i] = nx[i];
//   }
//   wt(dp[(1<<P) - 1]);
// }