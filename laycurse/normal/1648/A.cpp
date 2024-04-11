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
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
template<class T> struct Arr1d{
  int n;
  int mem;
  T*d;
  T& operator[](int a){
    return d[a];
  }
  void sort(){
    reset();
    std::sort(d, d+n);
  }
  int set_cumulative_sum;
  int cumulative_sum_mem;
  T*cumulative_sum;
  void setSum(void){
    int i;
    set_cumulative_sum = 1;
    if(cumulative_sum_mem < n+1){
      delete[] cumulative_sum;
      cumulative_sum = new T[n+1];
      cumulative_sum_mem = n+1;
    }
    cumulative_sum[0] = 0;
    for(i=(0);i<(n);i++){
      cumulative_sum[i+1] = cumulative_sum[i] + d[i];
    }
  }
  template<class T1, class T2> T getSum(T1 i, T2 j){
    if(i > j){
      return 0;
    }
    if(set_cumulative_sum==0){
      setSum();
    }
    return cumulative_sum[min_L(j+1, n)] - cumulative_sum[max_L(0, i)];
  }
  void reset(){
    set_cumulative_sum = 0;
  }
  void constructor(){
    n = mem = 0;
    d = NULL;
    set_cumulative_sum = 0;
    cumulative_sum_mem = 0;
    cumulative_sum = NULL;
  }
  void destructor(){
    delete[] d;
    d = NULL;
    mem = n = 0;
    set_cumulative_sum = 0;
    cumulative_sum_mem = 0;
    delete[] cumulative_sum;
    cumulative_sum = NULL;
  }
  void constructor(int nn){
    constructor();
    malloc(nn);
  }
  void memory_expand(int nn){
    if(mem < nn){
      delete[] d;
      d = new T[nn];
      mem = nn;
    }
  }
  void malloc(int nn){
    reset();
    memory_expand(nn);
    n = nn;
  }
  void setN(int nn){
    reset();
    memory_expand(nn);
    n = nn;
  }
  void setN(int nn, T val){
    int i;
    reset();
    memory_expand(nn);
    n = nn;
    for(i=(0);i<(n);i++){
      d[i] = val;
    }
  }
  template<class S> void set(vector<S> &a){
    int i;
    int nn = a.size();
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  template<class S> void set_c(vector<S> a){
    int i;
    int nn = a.size();
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  template<class S> void set(int nn, S a[]){
    int i;
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  void free(){
    destructor();
  }
  Arr1d(){
    constructor();
  }
  Arr1d(int nn){
    constructor(nn);
  }
  ~Arr1d(){
    destructor();
  }
}
;
int X;
int Y;
int A[100000];
int sz;
vector<int> r[100000];
vector<int> c[100000];
Arr1d<long long> arr;
long long res = 0;
long long calc(vector<int> a){
  int i;
  int n = a.size();
  long long res = 0;
  arr.set(a);
  arr.sort();
  for(i=(0);i<(n);i++){
    res += (i * arr[i] - arr.getSum(0,i-1)) + (arr.getSum(i+1,n-1) - (n-1-i) * arr[i]);
  }
  return res;
}
int main(){
  int i;
  wmem = memarr;
  rd(X);
  rd(Y);
  {
    int WKqLrJHZ;
    for(WKqLrJHZ=(0);WKqLrJHZ<(X*Y);WKqLrJHZ++){
      rd(A[WKqLrJHZ]);
    }
  }
  sz =coordcomp_L(X*Y,A);
  for(i=(0);i<(X*Y);i++){
    r[A[i]].push_back(i/Y);
    c[A[i]].push_back(i%Y);
  }
  for(i=(0);i<(sz);i++){
    res += calc(r[i]);
  }
  for(i=(0);i<(sz);i++){
    res += calc(c[i]);
  }
  wt_L(res / 2);
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
// int X, Y, A[1d5];
// int sz;
// VI r[1d5], c[1d5];
// Arr1d<ll> arr;
// ll res = 0;
// 
// ll calc(VI a){
//   int n = a.size();
//   ll res = 0;
//   arr.set(a);
//   arr.sort();
//   rep(i,n) res += (i * arr[i] - arr.getSum(0,i-1)) + (arr.getSum(i+1,n-1) - (n-1-i) * arr[i]);
//   return res;
// }
// 
// {
//   rd(X,Y,A(X*Y));
//   sz = coordcomp(X*Y,A);
// 
//   rep(i,X*Y){
//     r[A[i]].push_back(i/Y);
//     c[A[i]].push_back(i%Y);
//   }
//   rep(i,sz) res += calc(r[i]);
//   rep(i,sz) res += calc(c[i]);
//   wt(res / 2);
// }