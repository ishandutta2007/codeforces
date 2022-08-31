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
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
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
inline void rd(long long &x){
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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int main(){
  int Nzj9Y0kE;
  wmem = memarr;
  int N;
  int M;
  int K;
  long long X[100000];
  int A[100000];
  int B[100000];
  int C[100000];
  int D[100000];
  long long H[100000];
  long long dw[100000];
  int sz[100000];
  int*p[100000];
  long long*dp[100000];
  int*ind[100000];
  long long res;
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int i, j;
    rd(N);
    rd(M);
    rd(K);
    {
      int om7Ebh6q;
      for(om7Ebh6q=(0);om7Ebh6q<(N);om7Ebh6q++){
        rd(X[om7Ebh6q]);
      }
    }
    {
      int YGwFZBGH;
      for(YGwFZBGH=(0);YGwFZBGH<(K);YGwFZBGH++){
        rd(A[YGwFZBGH]);A[YGwFZBGH] += (-1);
        rd(B[YGwFZBGH]);B[YGwFZBGH] += (-1);
        rd(C[YGwFZBGH]);C[YGwFZBGH] += (-1);
        rd(D[YGwFZBGH]);D[YGwFZBGH] += (-1);
        rd(H[YGwFZBGH]);
      }
    }
    for(i=(0);i<(N);i++){
      sz[i] = 0;
    }
    for(i=(0);i<(K);i++){
      sz[A[i]]++;
      sz[C[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&p[i], sz[i]);
      walloc1d(&dp[i], sz[i]);
      walloc1d(&ind[i], sz[i]);
    }
    for(i=(0);i<(N);i++){
      sz[i] = 0;
    }
    for(i=(0);i<(K);i++){
      arrInsert(sz[A[i]], sz[A[i]], p[A[i]], B[i], dp[A[i]], 4611686016279904256LL, ind[A[i]], i);
    }
    for(i=(0);i<(K);i++){
      arrInsert(sz[C[i]], sz[C[i]], p[C[i]], D[i], dp[C[i]], 4611686016279904256LL, ind[C[i]], K+i);
    }
    for(i=(0);i<(N);i++){
      int j;
      sortA_L(sz[i], p[i], dp[i], ind[i]);
      if(i==0){
        int j;
        for(j=(0);j<(sz[i]);j++){
          chmin(dp[i][j], p[i][j] * X[i]);
        }
      }
      for(j=(0);j<(sz[i]);j++){
        if(ind[i][j] >= K){
          chmin(dp[i][j], dw[ind[i][j]-K] - H[ind[i][j]-K]);
        }
      }
      for(j=(1);j<(sz[i]);j++){
        chmin(dp[i][j], dp[i][j-1] + (p[i][j] - p[i][j-1]) * X[i]);
      }
      for(j=(sz[i])-1;j>=(1);j--){
        chmin(dp[i][j-1], dp[i][j] + (p[i][j] - p[i][j-1]) * X[i]);
      }
      for(j=(0);j<(sz[i]);j++){
        if(ind[i][j] < K){
          dw[ind[i][j]] = dp[i][j];
        }
      }
    }
    res = 4611686016279904256LL;
    for(j=(0);j<(sz[N-1]);j++){
      chmin(res, dp[N-1][j] + X[N-1] * abs(M-1 - p[N-1][j]));
    }
    if(res < 4611686016279904256LL/2){
      wt_L(res);
      wt_L('\n');
    }
    else{
      wt_L("NO ESCAPE");
      wt_L('\n');
    }
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20211231-1

// --- original code ---
// //no-unlocked
// int N, M, K; ll X[1d5]; int A[], B[], C[], D[]; ll H[], dw[];
// int sz[], *p[]; ll *dp[]; int *ind[]; ll res;
// REP(rd_int()){
//   rd(N,M,K,X(N),(A--,B--,C--,D--,H)(K));
//   rep(i,N) sz[i] = 0;
//   rep(i,K) sz[@[A,C][i]]++;
//   rep(i,N) walloc1d(&@[p,dp,ind][i], sz[i]);
//   rep(i,N) sz[i] = 0;
//   rep(i,K) arrInsert(sz[A[i]], sz[A[i]], p[A[i]], B[i], dp[A[i]], ll_inf, ind[A[i]], i);
//   rep(i,K) arrInsert(sz[C[i]], sz[C[i]], p[C[i]], D[i], dp[C[i]], ll_inf, ind[C[i]], K+i);
//   rep(i,N){
//     sortA(sz[i], p[i], dp[i], ind[i]);
//     if(i==0) rep(j,sz[i]) dp[i][j] <?= p[i][j] * X[i];
//     rep(j,sz[i]) if(ind[i][j] >= K) dp[i][j] <?= dw[ind[i][j]-K] - H[ind[i][j]-K];
//     rep(j,1,sz[i]) dp[i][j] <?= dp[i][j-1] + (p[i][j] - p[i][j-1]) * X[i];
//     rrep(j,1,sz[i]) dp[i][j-1] <?= dp[i][j] + (p[i][j] - p[i][j-1]) * X[i];
//     rep(j,sz[i]) if(ind[i][j] < K) dw[ind[i][j]] = dp[i][j];
//   }
// 
//   res = ll_inf;
//   rep(j,sz[N-1]) res <?= dp[N-1][j] + X[N-1] * abs(M-1 - p[N-1][j]);
//   wt(if[res < ll_inf/2, res, "NO ESCAPE"]);
// }