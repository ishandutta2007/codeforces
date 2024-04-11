#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
void*wmem;
char memarr[96000000];
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
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
int Prime_L(int N, int res[], void *mem=wmem){
  int i;
  int a;
  int b;
  int sz = 1;
  const int r = 23000;
  bool*isprime;
  int*sf;
  int ss = 1;
  walloc1d(&isprime, r, &mem);
  walloc1d(&sf, r, &mem);
  N /= 2;
  res[0] = 2;
  b =min_L(r, N);
  for(i=(1);i<(b);i++){
    isprime[i] = 1;
  }
  for(i=(1);i<(b);i++){
    if(isprime[i]){
      res[sz++] = 2*i+1;
      sf[ss] = 2*i*(i+1);
      if(sf[ss] < N){
        while(sf[ss] < r){
          isprime[sf[ss]] = 0;
          sf[ss] += res[ss];
        }
        ss++;
      }
    }
  }
  for(a=r; a<N; a+=r){
    b =min_L(a + r, N);
    isprime -= r;
    for(i=(a);i<(b);i++){
      isprime[i] = 1;
    }
    for(i=(1);i<(ss);i++){
      while(sf[i] < b){
        isprime[sf[i]] = 0;
        sf[i] += res[i];
      }
    }
    for(i=(a);i<(b);i++){
      if(isprime[i]){
        res[sz++] = 2*i+1;
      }
    }
  }
  return sz;
}
struct unionFind{
  int*d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void malloc(const int n, const int fg){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
    if(fg){
      init(n);
    }
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void walloc(const int n, const int fg, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
    if(fg){
      init(n);
    }
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
  inline int comp(int res[], void *mem = wmem){
    int i;
    int sz=0;
    int*cnt;
    walloc1d(&cnt, N, &mem);
    for(i=(0);i<(N);i++){
      cnt[i] = 0;
    }
    for(i=(0);i<(N);i++){
      cnt[get(i)] = 1;
    }
    for(i=(0);i<(N);i++){
      if(cnt[i]){
        cnt[i] = sz++;
      }
    }
    for(i=(0);i<(N);i++){
      res[i] = cnt[get(i)];
    }
    return sz;
  }
}
;
int N;
int Q;
int A[200000];
int S;
int T;
int ind[1000000+2];
unionFind uf;
int ps;
int p[1000000];
set<int> ss[1000000+2];
int main(){
  int YREPHmFM;
  wmem = memarr;
  int i;
  int j;
  int k;
  rd(N);
  rd(Q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(1000000+2);i++){
    ind[i] = -1;
  }
  for(i=(0);i<(N);i++){
    ind[A[i]] = i;
  }
  uf.walloc(1000000+2, 1);
  ps =Prime_L(1000000+1, p);
  for(i=(0);i<(ps);i++){
    k = -1;
    for(j=(p[i]);j<(1000000+2);j+=(p[i])){
      if(ind[j] >= 0){
        if(k >= 0){
          uf(k, j);
        }
        k = j;
      }
    }
  }
  for(i=(0);i<(ps);i++){
    k = -1;
    for(j=(p[i]);j<(1000000+2);j+=(p[i])){
      if(ind[j] >= 0){
        k = j;
        break;
      }
    }
    if(k == -1){
      continue;
    }
    k = uf(k);
    for(j=(p[i]);j<(1000000+2);j+=(p[i])){
      if(ind[j] >= 0){
        ss[k].insert(ind[j]);
      }
      if(ind[j-1] >= 0){
        ss[k].insert(ind[j-1]);
      }
    }
  }
  for(YREPHmFM=(0);YREPHmFM<(Q);YREPHmFM++){
    rd(S);S += (-1);
    rd(T);T += (-1);
    S = uf(A[S]);
    T = uf(A[T]);
    if(S==T){
      wt_L(0);
      wt_L('\n');
      continue;
    }
    if(ss[S].size() > ss[T].size()){
      swap(S,T);
    }
    for(int m : ss[S]){
      if(ss[T].count(m)){
        wt_L(1);
        wt_L('\n');
        goto jZyWAPpY;
      }
    }
    wt_L(2);
    wt_L('\n');
    jZyWAPpY:;
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N, Q, A[2d5], S, T;
// int ind[1d6+2];
// unionFind uf;
// int ps, p[1d6];
// set<int> ss[1d6+2];
// {
//   int i, j, k;
//   rd(N,Q,A(N));
//   rep(i,1d6+2) ind[i] = -1;
//   rep(i,N) ind[A[i]] = i;
//   uf.walloc(1d6+2, 1);
//   ps = Prime(1d6+1, p);
//   rep(i,ps){
//     k = -1;
//     rep(j,p[i],1d6+2,p[i]) if(ind[j] >= 0){
//       if(k >= 0) uf(k, j);
//       k = j;
//     }
//   }
//   rep(i,ps){
//     k = -1;
//     rep(j,p[i],1d6+2,p[i]) if(ind[j] >= 0) k = j, break;
//     if(k == -1) continue;
//     k = uf(k);
//     rep(j,p[i],1d6+2,p[i]){
//       if(ind[j] >= 0) ss[k].insert(ind[j]);
//       if(ind[j-1] >= 0) ss[k].insert(ind[j-1]);
//     }
//   }
//   rep(Q){
//     rd(S--, T--);
//     S = uf(A[S]);
//     T = uf(A[T]);
//     if(S==T) wt(0), continue;
//     if(ss[S].size() > ss[T].size()) swap(S,T);
//     for(int m : ss[S]) if(ss[T].count(m)) wt(1), break_continue;
//     wt(2);
//   }
// }