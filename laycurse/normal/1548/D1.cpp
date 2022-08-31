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
struct Rand{
  unsigned x;
  unsigned y;
  unsigned z;
  unsigned w;
  Rand(void){
    x=123456789;
    y=362436069;
    z=521288629;
    w=(unsigned)time(NULL);
  }
  Rand(unsigned seed){
    x=123456789;
    y=362436069;
    z=521288629;
    w=seed;
  }
  inline unsigned get(void){
    unsigned t;
    t = (x^(x<<11));
    x=y;
    y=z;
    z=w;
    w = (w^(w>>19))^(t^(t>>8));
    return w;
  }
  inline double getUni(void){
    return get()/4294967296.0;
  }
  inline int get(int a){
    return (int)(a*getUni());
  }
  inline int get(int a, int b){
    return a+(int)((b-a+1)*getUni());
  }
  inline long long get(long long a){
    return(long long)(a*getUni());
  }
  inline long long get(long long a, long long b){
    return a+(long long)((b-a+1)*getUni());
  }
  inline double get(double a, double b){
    return a+(b-a)*getUni();
  }
  inline int getExp(int a){
    return(int)(exp(getUni()*log(a+1.0))-1.0);
  }
  inline int getExp(int a, int b){
    return a+(int)(exp(getUni()*log((b-a+1)+1.0))-1.0);
  }
}
;
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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> struct Comb{
  int mem_fact;
  T*factri;
  T*ifactri;
  int mem_dfact;
  T*dfactri;
  int mem_pw2;
  int mem_pw3;
  int mem_pw10;
  int mem_rep1;
  T*pw2c;
  T*pw3c;
  T*pw10c;
  T*rep1c;
  int mem_ipw2;
  int mem_ipw3;
  int mem_ipw10;
  T*ipw2c;
  T*ipw3c;
  T*ipw10c;
  Comb(){
    mem_fact = 0;
    mem_dfact = 0;
    mem_pw2 = mem_pw3 = mem_pw10 = mem_rep1 = 0;
    mem_ipw2 = mem_ipw3 = mem_ipw10 = 0;
  }
  inline void expand_fact(int k){
    int i;
    if(k <= mem_fact){
      return;
    }
    chmax(k, 2 * mem_fact);
    if(mem_fact == 0){
      factri = (T*)malloc(k * sizeof(T));
      ifactri = (T*)malloc(k * sizeof(T));
      factri[0] = 1;
      for(i=(1);i<(k);i++){
        factri[i] = i * factri[i-1];
      }
      ifactri[k-1] = 1 / factri[k-1];
      for(i=(k-1)-1;i>=(0);i--){
        ifactri[i] = (i+1) * ifactri[i+1];
      }
    }
    else{
      factri = (T*)realloc(factri, k * sizeof(T));
      ifactri = (T*)realloc(ifactri, k * sizeof(T));
      for(i=(mem_fact);i<(k);i++){
        factri[i] = i * factri[i-1];
      }
      ifactri[k-1] = 1 / factri[k-1];
      for(i=(k-1)-1;i>=(mem_fact);i--){
        ifactri[i] = (i+1) * ifactri[i+1];
      }
    }
    mem_fact = k;
  }
  inline T fac(int k){
    if(mem_fact < k+1){
      expand_fact(k+1);
    }
    return factri[k];
  }
  inline T ifac(int k){
    if(mem_fact < k+1){
      expand_fact(k+1);
    }
    return ifactri[k];
  }
  inline T C(int a, int b){
    if(b < 0 || b > a){
      return 0;
    }
    if(mem_fact < a+1){
      expand_fact(a+1);
    }
    return factri[a] * ifactri[b] * ifactri[a-b];
  }
  inline T P(int a, int b){
    if(b < 0 || b > a){
      return 0;
    }
    if(mem_fact < a+1){
      expand_fact(a+1);
    }
    return factri[a] * ifactri[a-b];
  }
  inline T H(int a, int b){
    if(a==0 && b==0){
      return 1;
    }
    if(a <= 0 || b < 0){
      return 0;
    }
    if(mem_fact < a+b){
      expand_fact(a+b);
    }
    return C(a+b-1, b);
  }
  inline T Multinomial(int sz, int a[]){
    int i;
    int s = 0;
    T res;
    for(i=(0);i<(sz);i++){
      s += a[i];
    }
    if(mem_fact < s+1){
      expand_fact(s+1);
    }
    res = factri[s];
    for(i=(0);i<(sz);i++){
      res *= ifactri[a[i]];
    }
    return res;
  }
  inline T Multinomial(int a){
    return 1;
  }
  inline T Multinomial(int a, int b){
    if(mem_fact < a+b+1){
      expand_fact(a+b+1);
    }
    return factri[a+b] * ifactri[a] * ifactri[b];
  }
  inline T Multinomial(int a, int b, int c){
    if(mem_fact < a+b+c+1){
      expand_fact(a+b+c+1);
    }
    return factri[a+b+c] * ifactri[a] * ifactri[b] * ifactri[c];
  }
  inline T Multinomial(int a, int b, int c, int d){
    if(mem_fact < a+b+c+d+1){
      expand_fact(a+b+c+d+1);
    }
    return factri[a+b+c+d] * ifactri[a] * ifactri[b] * ifactri[c] * ifactri[d];
  }
  inline T Catalan(int n){
    if(n < 0){
      return 0;
    }
    if(mem_fact < 2*n+1){
      expand_fact(2*n+1);
    }
    return factri[2*n] * ifactri[n] * ifactri[n+1];
  }
  inline T Catalan(int n, int m, int k){
    if(k <= 0){
      return C(n+m, n);
    }
    if(n < k || m < k){
      return 0;
    }
    return C(n+m, m) - C(n+m, k-1);
  }
  inline T Catalan_s(long long n, long long m, long long k){
    if(k <= 0){
      return C_s(n+m, n);
    }
    if(n < k || m < k){
      return 0;
    }
    return C_s(n+m, m) - C_s(n+m, k-1);
  }
  inline T C_s(long long a, long long b){
    long long i;
    T res;
    if(b < 0 || b > a){
      return 0;
    }
    if(b > a - b){
      b = a - b;
    }
    res = 1;
    for(i=(0);i<(b);i++){
      res *= a - i;
      res /= i + 1;
    }
    return res;
  }
  inline T P_s(long long a, long long b){
    long long i;
    T res;
    if(b < 0 || b > a){
      return 0;
    }
    res = 1;
    for(i=(0);i<(b);i++){
      res *= a - i;
    }
    return res;
  }
  inline T H_s(long long a, long long b){
    if(a==0 && b==0){
      return 1;
    }
    if(a <= 0 || b < 0){
      return 0;
    }
    return C_s(a+b-1, b);
  }
  inline T per_s(long long n, long long k){
    T d;
    int m;
    if(n < 0 || k < 0){
      return 0;
    }
    if(n == k  &&  k == 0){
      return 1;
    }
    if(n == 0 || k == 0){
      return 0;
    }
    if(k==1){
      return 1;
    }
    if(k==2){
      d = n / 2;
      return d;
    }
    if(k==3){
      d = (n-1) / 6;
      m = (n-1) % 6;
      if(m==0){
        return 3 * d * d + d;
      }
      if(m==1){
        return 3 * d * d + 2 * d;
      }
      if(m==2){
        return 3 * d * d + 3 * d + 1;
      }
      if(m==3){
        return 3 * d * d + 4 * d + 1;
      }
      if(m==4){
        return 3 * d * d + 5 * d + 2;
      }
      if(m==5){
        return 3 * d * d + 6 * d + 3;
      }
    }
    assert(0 && "per_s should be k <= 3");
    return -1;
  }
  inline void expand_dfact(int k){
    int i;
    if(k <= mem_dfact){
      return;
    }
    chmax(k, 3);
    chmax(k, 2 * mem_dfact);
    if(mem_dfact==0){
      dfactri = (T*)malloc(k * sizeof(T));
      dfactri[0] = dfactri[1] = 1;
      for(i=(2);i<(k);i++){
        dfactri[i] = i * dfactri[i-2];
      }
    }
    else{
      dfactri = (T*)realloc(dfactri, k * sizeof(T));
      for(i=(mem_dfact);i<(k);i++){
        dfactri[i] = i * dfactri[i-2];
      }
    }
    mem_dfact = k;
  }
  inline void expand_pw2(int k){
    int i;
    if(k <= mem_pw2){
      return;
    }
    chmax(k, 2 * mem_pw2);
    if(mem_pw2==0){
      pw2c = (T*)malloc(k * sizeof(T));
      pw2c[0] = 1;
      for(i=(1);i<(k);i++){
        pw2c[i] = 2 * pw2c[i-1];
      }
    }
    else{
      pw2c = (T*)realloc(pw2c, k * sizeof(T));
      for(i=(mem_pw2);i<(k);i++){
        pw2c[i] = 2 * pw2c[i-1];
      }
    }
    mem_pw2 = k;
  }
  inline void expand_ipw2(int k){
    int i;
    if(k <= mem_ipw2){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * mem_ipw2);
    if(mem_ipw2==0){
      ipw2c = (T*)malloc(k * sizeof(T));
      ipw2c[0] = 1;
      ipw2c[1] = ipw2c[0] / 2;
      for(i=(1);i<(k);i++){
        ipw2c[i] = ipw2c[1] * ipw2c[i-1];
      }
    }
    else{
      ipw2c = (T*)realloc(ipw2c, k * sizeof(T));
      for(i=(mem_ipw2);i<(k);i++){
        ipw2c[i] = ipw2c[1] * ipw2c[i-1];
      }
    }
    mem_ipw2 = k;
  }
  inline void expand_pw3(int k){
    int i;
    if(k <= mem_pw3){
      return;
    }
    chmax(k, 2 * mem_pw3);
    if(mem_pw3==0){
      pw3c = (T*)malloc(k * sizeof(T));
      pw3c[0] = 1;
      for(i=(1);i<(k);i++){
        pw3c[i] = 3 * pw3c[i-1];
      }
    }
    else{
      pw3c = (T*)realloc(pw3c, k * sizeof(T));
      for(i=(mem_pw3);i<(k);i++){
        pw3c[i] = 3 * pw3c[i-1];
      }
    }
    mem_pw3 = k;
  }
  inline void expand_ipw3(int k){
    int i;
    if(k <= mem_ipw3){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * mem_ipw3);
    if(mem_ipw3==0){
      ipw3c = (T*)malloc(k * sizeof(T));
      ipw3c[0] = 1;
      ipw3c[1] = ipw3c[0] / 3;
      for(i=(1);i<(k);i++){
        ipw3c[i] = ipw3c[1] * ipw3c[i-1];
      }
    }
    else{
      ipw3c = (T*)realloc(ipw3c, k * sizeof(T));
      for(i=(mem_ipw3);i<(k);i++){
        ipw3c[i] = ipw3c[1] * ipw3c[i-1];
      }
    }
    mem_ipw3 = k;
  }
  inline void expand_pw10(int k){
    int i;
    if(k <= mem_pw10){
      return;
    }
    chmax(k, 2 * mem_pw10);
    if(mem_pw10==0){
      pw10c = (T*)malloc(k * sizeof(T));
      pw10c[0] = 1;
      for(i=(1);i<(k);i++){
        pw10c[i] = 10 * pw10c[i-1];
      }
    }
    else{
      pw10c = (T*)realloc(pw10c, k * sizeof(T));
      for(i=(mem_pw10);i<(k);i++){
        pw10c[i] = 10 * pw10c[i-1];
      }
    }
    mem_pw10 = k;
  }
  inline void expand_ipw10(int k){
    int i;
    if(k <= mem_ipw10){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * mem_ipw10);
    if(mem_ipw10==0){
      ipw10c = (T*)malloc(k * sizeof(T));
      ipw10c[0] = 1;
      ipw10c[1] = ipw10c[0] / 10;
      for(i=(1);i<(k);i++){
        ipw10c[i] = ipw10c[1] * ipw10c[i-1];
      }
    }
    else{
      ipw10c = (T*)realloc(ipw10c, k * sizeof(T));
      for(i=(mem_ipw10);i<(k);i++){
        ipw10c[i] = ipw10c[1] * ipw10c[i-1];
      }
    }
    mem_ipw10 = k;
  }
  inline void expand_rep1(int k){
    int i;
    if(k <= mem_rep1){
      return;
    }
    chmax(k, 2 * mem_rep1);
    if(mem_rep1==0){
      rep1c = (T*)malloc(k * sizeof(T));
      rep1c[0] = 0;
      for(i=(1);i<(k);i++){
        rep1c[i] = 10 * rep1c[i-1] + 1;
      }
    }
    else{
      rep1c = (T*)realloc(rep1c, k * sizeof(T));
      for(i=(mem_rep1);i<(k);i++){
        rep1c[i] = 10 * rep1c[i-1] + 1;
      }
    }
    mem_rep1 = k;
  }
  inline T dfac(int k){
    if(k >= 0){
      if(mem_dfact < k+1){
        expand_dfact(k+1);
      }
      return dfactri[k];
    }
    if(k==-1){
      return 1;
    }
    k = - k - 2;
    if(k % 4 == 1){
      return 1 / (-dfac(k));
    }
    return 1 / dfac(k);
  }
  inline T pw2(int k){
    if(k >= 0){
      if(mem_pw2 < k+1){
        expand_pw2(k+1);
      }
      return pw2c[k];
    }
    else{
      k = -k;
      if(mem_ipw2 < k+1){
        expand_ipw2(k+1);
      }
      return ipw2c[k];
    }
  }
  inline T pw3(int k){
    if(k >= 0){
      if(mem_pw3 < k+1){
        expand_pw3(k+1);
      }
      return pw3c[k];
    }
    else{
      k = -k;
      if(mem_ipw3 < k+1){
        expand_ipw3(k+1);
      }
      return ipw3c[k];
    }
  }
  inline T pw10(int k){
    if(k >= 0){
      if(mem_pw10 < k+1){
        expand_pw10(k+1);
      }
      return pw10c[k];
    }
    else{
      k = -k;
      if(mem_ipw10 < k+1){
        expand_ipw10(k+1);
      }
      return ipw10c[k];
    }
  }
  inline T repunit(int k){
    if(mem_rep1 < k+1){
      expand_rep1(k+1);
    }
    return rep1c[k];
  }
}
;
#define ROLLING_HASH_MOD (2305843009213693951ULL)
#define ROLLING_HASH_PRIMITIVE_ROOT (3)
#define ROLLING_HASH_MAX_MEMORY (2000000)
int ROLLING_HASH_MEM;
unsigned long long ROLLING_HASH_BASE;
unsigned long long ROLLING_HASH_IBASE;
unsigned long long*ROLLING_HASH_PW = NULL;
unsigned long long*ROLLING_HASH_IPW = NULL;
inline unsigned long long rollingHash61_mul(unsigned long long a, unsigned long long b){
  __uint128_t r = (__uint128_t) a * b;
  a = (r >> 61) + (r & ROLLING_HASH_MOD);
  if(a >= ROLLING_HASH_MOD){
    a -= ROLLING_HASH_MOD;
  }
  return a;
}
inline unsigned long long rollingHash61_pow(unsigned long long a, unsigned long long b){
  unsigned long long r = 1;
  for(;;){
    if(b&1){
      r = rollingHash61_mul(r, a);
    }
    if(b==0){
      break;
    }
    b >>= 1;
    a = rollingHash61_mul(a, a);
  }
  return r;
}
void rollingHashInit(){
  int i;
  Rand rnd;
  unsigned long long x;
  for(i=(0);i<(20);i++){
    rnd.get(2);
  }
  do{
    x = rnd.get(1.0, (double)(ROLLING_HASH_MOD-2));
  }
  while(GCD_L(x, ROLLING_HASH_MOD-1)!= 1);
  ROLLING_HASH_BASE = rollingHash61_pow(ROLLING_HASH_PRIMITIVE_ROOT, x);
  ROLLING_HASH_IBASE = rollingHash61_pow(ROLLING_HASH_BASE, ROLLING_HASH_MOD - 2);
}
void rollingHash_expand(int k){
  int i;
  if(ROLLING_HASH_MEM >= k){
    return;
  }
  ROLLING_HASH_MEM =max_L(2 * ROLLING_HASH_MEM, k);
  assert(ROLLING_HASH_MEM <= 2 * ROLLING_HASH_MAX_MEMORY);
  ROLLING_HASH_PW = (unsigned long long*) realloc(ROLLING_HASH_PW, ROLLING_HASH_MEM * sizeof(unsigned long long));
  ROLLING_HASH_IPW = (unsigned long long*) realloc(ROLLING_HASH_IPW, ROLLING_HASH_MEM * sizeof(unsigned long long));
  ROLLING_HASH_PW[0] = 1;
  for(i=(1);i<(ROLLING_HASH_MEM);i++){
    ROLLING_HASH_PW[i] = rollingHash61_mul(ROLLING_HASH_PW[i-1], ROLLING_HASH_BASE);
  }
  ROLLING_HASH_IPW[0] = 1;
  for(i=(1);i<(ROLLING_HASH_MEM);i++){
    ROLLING_HASH_IPW[i] = rollingHash61_mul(ROLLING_HASH_IPW[i-1], ROLLING_HASH_IBASE);
  }
}
struct rollingHash{
  long long len;
  unsigned long long hs;
  template<class T> void set(int N, T A[]){
    int i;
    long long tmp;
    hs = 0;
    len = N;
    rollingHash_expand(N);
    for(i=(0);i<(N);i++){
      tmp = A[i] % ((long long)ROLLING_HASH_MOD);
      if(tmp < 0){
        tmp += ROLLING_HASH_MOD;
      }
      hs += rollingHash61_mul(tmp, ROLLING_HASH_PW[i]);
      if(hs >= ROLLING_HASH_MOD){
        hs -= ROLLING_HASH_MOD;
      }
    }
  }
  template<class S, class T> void change(long long ind, S bef, T aft){
    long long tmp1;
    long long tmp2;
    tmp1 = bef % ((long long)ROLLING_HASH_MOD);
    tmp2 = aft % ((long long)ROLLING_HASH_MOD);
    tmp1 = tmp2 - tmp1;
    if(tmp1 < 0){
      tmp1 += ROLLING_HASH_MOD;
    }
    if(tmp1 < 0){
      tmp1 += ROLLING_HASH_MOD;
    }
    if(tmp1 >= ROLLING_HASH_MOD){
      tmp1 -= ROLLING_HASH_MOD;
    }
    if(ind+1 <= ROLLING_HASH_MAX_MEMORY || ind+1 >= ROLLING_HASH_MEM){
      rollingHash_expand(ind+1);
      hs += rollingHash61_mul(tmp1, ROLLING_HASH_PW[ind]);
    }
    else{
      hs += rollingHash61_mul(tmp1, rollingHash61_pow(ROLLING_HASH_BASE, ind));
    }
    if(hs >= ROLLING_HASH_MOD){
      hs -= ROLLING_HASH_MOD;
    }
  }
  void push_front(rollingHash a){
    if(a.len + 1 <= ROLLING_HASH_MAX_MEMORY || a.len + 1 >= ROLLING_HASH_MEM){
      rollingHash_expand(a.len + 1);
      hs = rollingHash61_mul(hs, ROLLING_HASH_PW[a.len]);
    }
    else{
      hs = rollingHash61_mul(hs, rollingHash61_pow(ROLLING_HASH_BASE, a.len));
    }
    hs += a.hs;
    if(hs >= ROLLING_HASH_MOD){
      hs -= ROLLING_HASH_MOD;
    }
    len += a.len;
  }
  void push_back(rollingHash a){
    if(len + 1 <= ROLLING_HASH_MAX_MEMORY || len + 1 >= ROLLING_HASH_MEM){
      rollingHash_expand(len + 1);
      hs += rollingHash61_mul(a.hs, ROLLING_HASH_PW[len]);
    }
    else{
      hs += rollingHash61_mul(a.hs, rollingHash61_pow(ROLLING_HASH_BASE, len));
    }
    if(hs >= ROLLING_HASH_MOD){
      hs -= ROLLING_HASH_MOD;
    }
    len += a.len;
  }
  void pop_front(rollingHash a){
    if(hs >= a.hs){
      hs -= a.hs;
    }
    else{
      hs = hs + ROLLING_HASH_MOD - a.hs;
    }
    if(a.len + 1 <= ROLLING_HASH_MAX_MEMORY || a.len + 1 >= ROLLING_HASH_MEM){
      rollingHash_expand(a.len + 1);
      hs = rollingHash61_mul(hs, ROLLING_HASH_IPW[a.len]);
    }
    else{
      hs = rollingHash61_mul(hs, rollingHash61_pow(ROLLING_HASH_IBASE, a.len));
    }
    len -= a.len;
  }
  void pop_back(rollingHash a){
    unsigned long long tmp;
    if(len + 1 <= ROLLING_HASH_MAX_MEMORY || len + 1 >= ROLLING_HASH_MEM){
      rollingHash_expand(len + 1);
      tmp = rollingHash61_mul(a.hs, ROLLING_HASH_PW[len]);
    }
    else{
      tmp = rollingHash61_mul(a.hs, rollingHash61_pow(ROLLING_HASH_BASE, len));
    }
    if(hs >= tmp){
      hs -= tmp;
    }
    else{
      hs = hs + ROLLING_HASH_MOD - tmp;
    }
    len -= a.len;
  }
  bool operator==(const rollingHash a){
    return len == a.len && hs == a.hs;
  }
  bool operator!=(const rollingHash a){
    return len != a.len || hs != a.hs;
  }
}
;
template<class T> rollingHash calcRollingHash(int N, T A[]){
  rollingHash res;
  res.set(N, A);
  return res;
}
struct rollingHashSubarrays{
  unsigned long long*hs;
  int mem;
  int len;
  void set(){
    hs = NULL;
    mem = len = 0;
  }
  void free(){
    if(mem){
      delete[] hs;
    }
  }
  void expand(int k){
    if(mem >= k){
      return;
    }
    free();
    mem =max_L(2*mem, k);
    hs = new unsigned long long[mem];
  }
  template<class T> void set(int N, T A[]){
    int i;
    long long tmp;
    if(N <= 0){
      return;
    }
    rollingHash_expand(N);
    expand(N);
    len = N;
    tmp = A[0] % ((long long)ROLLING_HASH_MOD);
    if(tmp < 0){
      tmp += ROLLING_HASH_MOD;
    }
    hs[0] = tmp;
    for(i=(1);i<(N);i++){
      tmp = A[i] % ((long long)ROLLING_HASH_MOD);
      if(tmp < 0){
        tmp += ROLLING_HASH_MOD;
      }
      hs[i] = hs[i-1] + rollingHash61_mul(tmp, ROLLING_HASH_PW[i]);
      if(hs[i] >= ROLLING_HASH_MOD){
        hs[i] -= ROLLING_HASH_MOD;
      }
    }
  }
  rollingHash get_len(int s, int len){
    unsigned long long x;
    rollingHash res;
    res.len = len;
    rollingHash_expand(s+1);
    if(s == 0){
      res.hs = hs[len-1];
    }
    else{
      if(hs[s+len-1] >= hs[s-1]){
        res.hs = hs[s+len-1] - hs[s-1];
      }
      else{
        res.hs = hs[s+len-1] + ROLLING_HASH_MOD - hs[s-1];
      }
      res.hs = rollingHash61_mul(res.hs, ROLLING_HASH_IPW[s]);
    }
    return res;
  }
  rollingHash get(int a, int b){
    return get_len(a, b - a + 1);
  }
  rollingHashSubarrays(){
    set();
  }
  ~rollingHashSubarrays(){
    free();
  }
}
;
int N;
int X[6000];
int Y[6000];
int c[6000][6000];
unsigned long long hs[6000];
int ind[6000];
int s[6000];
int sz;
Comb<long long> comb;
int main(){
  wmem = memarr;
  {
    rollingHashInit();
  }
  int i;
  int j;
  int k;
  int sz;
  long long res = 0;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);
      rd(Y[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    for(j=(i+1);j<(N);j++){
      c[i][j] = c[j][i] = (GCD_L(abs(X[i]-X[j]), abs(Y[i]-Y[j]))/ 2) % 2;
    }
  }
  for(i=(0);i<(N);i++){
    hs[i] = calcRollingHash(N, c[i]).hs;
  }
  for(i=(0);i<(N);i++){
    ind[i] = i;
  }
  sortA_L(N, hs, ind);
  sz = 0;
  for(i=(0);i<(N);i++){
    if(sz == 0 || hs[i] != hs[sz-1]){
      arrInsert(sz, sz, hs, hs[i], ind, ind[i]);
    }
    s[sz-1]++;
  }
  for(i=(0);i<(sz);i++){
    res += comb.C_s(s[i], 3);
  }
  for(i=(0);i<(sz);i++){
    if(s[i]){
      for(j=(i+1);j<(sz);j++){
        if(s[j]){
          if(c[ind[i]][ind[j]]){
            res += comb.C_s(s[i],2) * comb.C_s(s[j],1);
            res += comb.C_s(s[i],1) * comb.C_s(s[j],2);
          }
        }
      }
    }
  }
  for(i=(0);i<(sz);i++){
    if(s[i]){
      for(j=(i+1);j<(sz);j++){
        if(s[j]){
          for(k=(j+1);k<(sz);k++){
            if(s[k]){
              if((c[ind[i]][ind[j]] + c[ind[j]][ind[k]] + c[ind[k]][ind[i]]) % 2 == 0){
                res += (long long) s[i] * s[j] * s[k];
              }
            }
          }
        }
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N, X[6000], Y[];
// int c[6000][6000];
// ull hs[6000]; int ind[6000], s[6000], sz;
// Comb<ll> comb;
// {
//   int i, j, k, sz;
//   ll res = 0;
//   rd(N,(X,Y)(N));
//   rep(i,N) rep(j,i+1,N) c[i][j] = c[j][i] = (gcd(abs(X[i]-X[j]), abs(Y[i]-Y[j])) / 2) % 2;
//   rep(i,N) hs[i] = calcRollingHash(N, c[i]).hs;
//   rep(i,N) ind[i] = i;
//   sortA(N, hs, ind);
//   sz = 0;
//   rep(i,N){
//     if(sz == 0 || hs[i] != hs[sz-1]) arrInsert(sz, sz, hs, hs[i], ind, ind[i]);
//     s[sz-1]++;
//   }
//   rep(i,sz) res += comb.C_s(s[i], 3);
//   rep(i,sz) if(s[i]) rep(j,i+1,sz) if(s[j]) if(c[ind[i]][ind[j]]){
//     res += comb.C_s(s[i],2) * comb.C_s(s[j],1);
//     res += comb.C_s(s[i],1) * comb.C_s(s[j],2);
//   }
//   rep(i,sz) if(s[i]) rep(j,i+1,sz) if(s[j]) rep(k,j+1,sz) if(s[k]){
//     if((c[ind[i]][ind[j]] + c[ind[j]][ind[k]] + c[ind[k]][ind[i]]) % 2 == 0){
//       res += (ll) s[i] * s[j] * s[k];
//     }
//   }
//   wt(res);
// }