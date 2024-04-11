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
template<class T1, class T2> void sortA_index_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    b[i] = i;
  }
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class T> int coordcomp_L(int n, T arr[], int res[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int>*r;
  walloc1d(&r, n, &mem);
  for(i=(0);i<(n);i++){
    r[i].first = arr[i];
    r[i].second = i;
  }
  sort(r, r+n);
  if(res != NULL){
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      res[r[i].second] = k;
    }
  }
  else{
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      arr[r[i].second] = k;
    }
  }
  return k+1;
}
struct dimcomp2{
  int B;
  dimcomp2(){
  }
  dimcomp2(int b){
    B = b;
  }
  dimcomp2(int a, int b){
    B = b;
  }
  inline void set(int b){
    B = b;
  }
  inline void set(int a, int b){
    B = b;
  }
  inline int mask(int a, int b){
    return a * B + b;
  }
  inline int operator()(int a, int b){
    return a * B + b;
  }
  inline void para(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
  inline void operator()(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
}
;
int N;
int M;
int A[100000][5];
int tmp[500000];
int W[100000];
int iind[100000];
int sz;
vector<int> ind[500000];
int ta[500000];
int ts;
dimcomp2 dm;
bitset<100001> cur;
bitset<100001> al;
bitset<100001> ss[1000];
int main(){
  int i;
  wmem = memarr;
  int f;
  long long res = 4611686016279904256LL;
  rd(N);
  rd(M);
  for(i=(0);i<(N);i++){
    {
      int WKqLrJHZ;
      for(WKqLrJHZ=(0);WKqLrJHZ<(M);WKqLrJHZ++){
        rd(A[i][WKqLrJHZ]);
      }
    }
    rd(W[i]);
  }
  sortA_index_L(N,W,iind);
  dm.set(N,M);
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(M);j++){
      tmp[dm(i,j)] = A[i][j];
    }
  }
  sz =coordcomp_L(N*M,tmp);
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(M);j++){
      A[i][j] = tmp[dm(iind[i],j)];
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(M);j++){
      ind[A[i][j]].push_back(i);
    }
  }
  for(i=(0);i<(sz);i++){
    ta[i] = -1;
    if(ind[i].size() > 500){
      ta[i] = ts++;
      for(int k : ind[i]){
        ss[ta[i]].set(k);
      }
    }
  }
  al.set();
  for(i=(0);i<(N);i++){
    int ZcmRJqJU;
    cur.reset();
    for(ZcmRJqJU=(0);ZcmRJqJU<(M);ZcmRJqJU++){
      auto&j = A[i][ZcmRJqJU];
      if(ta[j]==-1){
        for(int k : ind[j]){
          cur.set(k);
        }
      }
      else{
        cur |= ss[ta[j]];
      }
    }
    cur ^= al;
    f = cur._Find_first();
    if(f < N){
      chmin(res, W[i] + W[f]);
    }
  }
  if(res==4611686016279904256LL){
    res = -1;
  }
  wt_L(res);
  wt_L('\n');
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
// cLay version 20220116-1 [+beta]

// --- original code ---
// //no-unlocked
// int N, M, A[1d5][5], tmp[5d5], W[1d5], iind[1d5];
// int sz;
// VI ind[5d5]; int ta[5d5], ts;
// dimcomp2 dm;
// 
// bitset<100001> cur, al, ss[1000];
// 
// {
//   int f;
//   ll res = ll_inf;
//   rd(N,M);
//   rep(i,N) rd(A[i](M), W[i]);
//   sortA_index(N,W,iind);
// 
//   dm.set(N,M);
//   rep(i,N) rep(j,M) tmp[dm(i,j)] = A[i][j];
//   sz = coordcomp(N*M,tmp);
//   rep(i,N) rep(j,M) A[i][j] = tmp[dm(iind[i],j)];
// 
//   // rep(i,N) wt(A[i](M),":",W[i]);
// 
//   rep(i,N) rep(j,M) ind[A[i][j]].push_back(i);
//   rep(i,sz){
//     ta[i] = -1;
//     if(ind[i].size() > 500){
//       ta[i] = ts++;
//       for(int k : ind[i]) ss[ta[i]].set(k);
//     }
//   }
// 
//   al.set();
//   rep(i,N){
//     cur.reset();
//     rep[A[i]](j,M){
//       if(ta[j]==-1){
//         for(int k : ind[j]) cur.set(k);
//       } else {
//         cur |= ss[ta[j]];
//       }
//     }
//     cur ^= al;
//     f = cur._Find_first();
//     if(f < N) res <?= W[i] + W[f];
//   }
//   if(res==ll_inf) res = -1;
//   wt(res);
// }