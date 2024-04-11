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
template<class T> inline T pow2_L(T a){
  return a*a;
}
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
template<class T, class S> T inline fDiv(T a, S b){
  T m;
  if(b < 0){
    a = -a;
    b = -b;
  }
  m = a % b;
  if(m == 0){
    return a / b;
  }
  if(m < 0){
    m += b;
  }
  return (a - m) / b;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T, class S> int subsetSumSD(int n, T a[], S res[], void *mem = wmem){
  int i;
  int k;
  int sz = 1;
  int bf;
  int x;
  int y;
  S*arr;
  walloc1d(&arr, 1, &mem);
  res[0] = 0;
  for(k=(0);k<(n);k++){
    bf = sz;
    sz = x = y = 0;
    for(i=(0);i<(bf);i++){
      arr[i] = res[i];
    }
    for(i=(0);i<(bf);i++){
      arr[bf+i] = res[i] + a[k];
    }
    while(x < bf && y < bf){
      if(arr[x] < arr[bf+y]){
        if(sz==0 || res[sz-1]!=arr[x]){
          res[sz++] = arr[x];
        }
        x++;
      }
      else{
        if(sz==0 || res[sz-1]!=arr[bf+y]){
          res[sz++] = arr[bf+y];
        }
        y++;
      }
    }
    while(x < bf){
      if(sz==0 || res[sz-1]!=arr[x]){
        res[sz++] = arr[x];
      }
      x++;
    }
    while(y < bf){
      if(sz==0 || res[sz-1]!=arr[bf+y]){
        res[sz++] = arr[bf+y];
      }
      y++;
    }
  }
  return sz;
}
template<class T, class S, class U> int subsetSumSD(int n, T a[], S res[], U lim, void *mem = wmem){
  int i;
  int k;
  int sz = 1;
  int bf;
  int x;
  int y;
  S*arr;
  walloc1d(&arr, 1, &mem);
  res[0] = 0;
  for(k=(0);k<(n);k++){
    bf = sz;
    sz = x = y = 0;
    for(i=(0);i<(bf);i++){
      arr[i] = res[i];
    }
    for(i=(0);i<(bf);i++){
      arr[bf+i] = res[i] + a[k];
    }
    while(x < bf && y < bf){
      if(arr[x] < arr[bf+y]){
        if(sz==0 || res[sz-1]!=arr[x]){
          res[sz++] = arr[x];
        }
        x++;
      }
      else{
        if(sz==0 || res[sz-1]!=arr[bf+y]){
          res[sz++] = arr[bf+y];
        }
        y++;
      }
    }
    while(x < bf){
      if(sz==0 || res[sz-1]!=arr[x]){
        res[sz++] = arr[x];
      }
      x++;
    }
    while(y < bf){
      if(sz==0 || res[sz-1]!=arr[bf+y]){
        res[sz++] = arr[bf+y];
      }
      y++;
    }
    while(sz && res[sz-1] > lim){
      sz--;
    }
  }
  return sz;
}
template<class T> T opt01SubsetSum_brute(int N, T A[], T t, T notfound = -1){
  T res;
  T tmp;
  int ok = 0;
  int mask;
  int i;
  for(mask=(0);mask<(1<<N);mask++){
    tmp = 0;
    for(i=(0);i<(N);i++){
      if(mask & (1<<i)){
        tmp += A[i];
      }
    }
    if(tmp <= t){
      if(!ok){
        ok = 1;
        res = tmp;
      }
      else if(res < tmp){
        res = tmp;
      }
    }
  }
  if(!ok){
    return notfound;
  }
  return res;
}
template<class T> T opt01SubsetSum_mim(int N, T A[], T t, T notfound = -1, void *mem = wmem){
  int i;
  int j;
  int n1;
  int n2;
  int s1;
  int s2;
  T*a;
  T*a1;
  T*a2;
  T res;
  T sm;
  T ad;
  walloc1d(&a, N, &mem);
  for(i=(0);i<(N);i++){
    a[i] = A[i];
  }
  ad = 0;
  for(i=(0);i<(N);i++){
    if(a[i] < 0){
      a[i] = -a[i];
      ad += a[i];
    }
  }
  t += ad;
  if(t < 0){
    return notfound;
  }
  sort(a, a+N);
  while(N && a[N-1] > t){
    N--;
  }
  if(N==0){
    if(t >= 0){
      return -ad;
    }
    return notfound;
  }
  sm = 0;
  for(i=(0);i<(N);i++){
    if(a[i] > 0){
      sm += a[i];
    }
    if(sm == t){
      return t - ad;
    }
  }
  if(sm < t){
    return sm - ad;
  }
  n1 = N / 2;
  n2 = N - n1;
  walloc1d(&a1, 1<<n1, &mem);
  walloc1d(&a2, 1<<n2, &mem);
  s1 = subsetSumSD(n1, a, a1, t, mem);
  s2 = subsetSumSD(n2, a+n1, a2, t, mem);
  res = 0;
  j = s2 - 1;
  for(i=(0);i<(s1);i++){
    while(j >= 0 && a1[i] + a2[j] > t){
      j--;
    }
    if(j < 0){
      break;
    }
    chmax(res, a1[i] + a2[j]);
  }
  return res - ad;
}
template<class T> T opt01SubsetSum_sdp(int N, T A[], T t, T notfound = -1, void *mem = wmem){
  int i;
  int k;
  T*a;
  T sm;
  T ad;
  T g;
  char*arr;
  walloc1d(&a, N, &mem);
  for(i=(0);i<(N);i++){
    a[i] = A[i];
  }
  ad = 0;
  for(i=(0);i<(N);i++){
    if(a[i] < 0){
      a[i] = -a[i];
      ad += a[i];
    }
  }
  t += ad;
  if(t < 0){
    return notfound;
  }
  sort(a, a+N);
  while(N && a[N-1] > t){
    N--;
  }
  if(N==0){
    if(t >= 0){
      return -ad;
    }
    return notfound;
  }
  walloc1d(&arr, t+1, &mem);
  while(N > 0 && a[N-1] > t){
    N--;
  }
  sm = 0;
  for(i=(0);i<(N);i++){
    sm += a[i];
    if(sm == t){
      return t - ad;
    }
  }
  if(sm < t){
    return sm - ad;
  }
  g = a[0];
  for(i=(1);i<(N);i++){
    g =GCD_L(g, a[i]);
  }
  if(g > 1){
    for(i=(0);i<(N);i++){
      a[i] /= g;
    }
    t = fDiv(t, g);
  }
  arr[0] = 1;
  for(i=(1);i<(t+1);i++){
    arr[i] = 0;
  }
  sm = 0;
  for(k=(0);k<(N);k++){
    sm =min_L(sm + a[k], t);
    for(i=(sm+1)-1;i>=(a[k]);i--){
      arr[i] |= arr[i-a[k]];
    }
  }
  for(i=(t+1)-1;i>=(0);i--){
    if(arr[i]){
      return i*g - ad;
    }
  }
  return notfound;
}
template<class T> T opt01SubsetSum(int N, T A[], T t, T notfound = -1, int mem_lim = sizeof(memarr)/2, void *mem = wmem){
  int i;
  T g;
  double x;
  double min_time;
  double time_brute;
  double time_mim;
  double time_sdp;
  double memo_brute;
  double memo_mim;
  double memo_sdp;
  min_time = 1e150;
  time_brute = pow(2.0, N) * N;
  memo_brute = 1;
  if(memo_brute > mem_lim){
    time_brute = 1e150;
  }
  chmin(min_time, time_brute);
  time_mim = 2 * pow(2.0, (N+1)/2);
  memo_mim = time_mim * sizeof(T);
  if(memo_mim > mem_lim){
    time_mim = 1e150;
  }
  chmin(min_time, time_mim);
  g = 0;
  for(i=(0);i<(N);i++){
    g =GCD_L(g, abs(A[i]));
  }
  x = t;
  for(i=(0);i<(N);i++){
    if(A[i] < 0){
      x -= A[i];
    }
  }
  time_sdp = (double) x * N;
  if(g > 1){
    time_sdp /= g;
  }
  memo_sdp = time_sdp * sizeof(T);
  if(memo_sdp > mem_lim){
    time_sdp = 1e150;
  }
  chmin(min_time, time_sdp);
  if(min_time == time_brute){
    return opt01SubsetSum_brute(N, A, t, notfound);
  }
  if(min_time == time_mim){
    return opt01SubsetSum_mim(N, A, t, notfound, mem);
  }
  if(min_time == time_sdp){
    return opt01SubsetSum_sdp(N, A, t, notfound, mem);
  }
  return notfound;
}
int main(){
  int Nzj9Y0kE;
  wmem = memarr;
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int i;
    int N;
    rd(N);
    int A[N];
    {
      int om7Ebh6q;
      for(om7Ebh6q=(0);om7Ebh6q<(N);om7Ebh6q++){
        rd(A[om7Ebh6q]);
      }
    }
    int B[N];
    {
      int YGwFZBGH;
      for(YGwFZBGH=(0);YGwFZBGH<(N);YGwFZBGH++){
        rd(B[YGwFZBGH]);
      }
    }
    int c[N];
    int sa;
    int sb;
    int x;
    int y;
    long long res = 0;
    int pyHJGNQc;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type wbH8AaCb;
    if(N==0){
      wbH8AaCb = 0;
    }
    else{
      wbH8AaCb = A[0];
      for(pyHJGNQc=(1);pyHJGNQc<(N);pyHJGNQc++){
        wbH8AaCb += A[pyHJGNQc];
      }
    }
    sa =wbH8AaCb;
    int Dc_3QP3Y;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type myTeyldV;
    if(N==0){
      myTeyldV = 0;
    }
    else{
      myTeyldV = B[0];
      for(Dc_3QP3Y=(1);Dc_3QP3Y<(N);Dc_3QP3Y++){
        myTeyldV += B[Dc_3QP3Y];
      }
    }
    sb =myTeyldV;
    for(i=(0);i<(N);i++){
      c[i] = A[i] - B[i];
    }
    x = opt01SubsetSum(N,c,(sa-sb)/2) + sb;
    y = sa+sb-x;
    for(i=(0);i<(N);i++){
      res += ((pow2_L(A[i]))) * (N - 2);
    }
    for(i=(0);i<(N);i++){
      res += ((pow2_L(B[i]))) * (N - 2);
    }
    res += x * x + y * y;
    wt_L(res);
    wt_L('\n');
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
// cLay version 20220116-1 [+beta]

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N, @A[N], @B[N], c[N], sa, sb, x, y;
//   ll res = 0;
//   sa = sum(A(N));
//   sb = sum(B(N));
//   rep(i,N) c[i] = A[i] - B[i];
//   x = opt01SubsetSum(N,c,(sa-sb)/2) + sb;
//   y = sa+sb-x;
//   rep(i,N) res += (A[i] ** 2) * (N - 2);
//   rep(i,N) res += (B[i] ** 2) * (N - 2);
//   res += x * x + y * y;
//   wt(res);
// }