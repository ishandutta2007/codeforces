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
#define ISPRIME_PRE_CALC_SIZE 1000000
char isPrime_prime_table[ISPRIME_PRE_CALC_SIZE];
template<class T> inline int isPrime(T n);
void isPrime32_init(void);
int isPrime32_sub(int b, unsigned n);
int isPrime32(unsigned n);
int isPrime64_sub(long long b, unsigned long long n);
int isPrime64(unsigned long long n);
#define FACTOR_PRE_CALC_SIZE 1000000
int factor_hasprime_table[FACTOR_PRE_CALC_SIZE];
template<class T, class R1, class R2> int Factor(T N, R1 fac[], R2 fs[], void *mem = wmem);
template<class T, class R1> int Factor(T N, R1 fac[], void *mem = wmem);
template<class T> int Factor(T N, void *mem = wmem);
unsigned Factor32_rho(unsigned n);
template<class R1, class R2> int Factor32(unsigned N, R1 fac[], R2 fs[], void *mem = wmem);
unsigned long long Factor64_rho(unsigned long long n);
template<class R1, class R2> int Factor64(unsigned long long N, R1 fac[], R2 fs[], void *mem = wmem);
void Factor32_init(void);
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
inline long long Isqrt_f_L(const long long n){
  long long r = sqrt(n);
  r =max_L(r-2, 0);
  while((pow2_L((r+1)))<= n ){
    r++;
  }
  return r;
}
int fs1;
int fn1[100];
int f1[100];
int fs2;
int fn2[100];
int f2[100];
int fs3;
int fn3[100];
int f3[100];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  {
    isPrime32_init();
  }
  {
    Factor32_init();
  }
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int A;
    rd(A);
    int B;
    rd(B);
    int K;
    rd(K);
    int g;
    int s;
    g =GCD_L(A, B);
    fs3 = Factor(g, f3, fn3);
    fs1 = Factor(A/g, f1, fn1);
    fs2 = Factor(B/g, f2, fn2);
    if(fs1 == fs2  &&  fs2 == 0 && K == 1){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    if(fs1 && fs2 && K == 1){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    int RZTsC2BF;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type FmcKpFmN;
    if(fs3==0){
      FmcKpFmN = 0;
    }
    else{
      FmcKpFmN = fn3[0];
      for(RZTsC2BF=(1);RZTsC2BF<(fs3);RZTsC2BF++){
        FmcKpFmN += fn3[RZTsC2BF];
      }
    }
    int t_ynMSdg;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type KrdatlYV;
    if(fs1==0){
      KrdatlYV = 0;
    }
    else{
      KrdatlYV = fn1[0];
      for(t_ynMSdg=(1);t_ynMSdg<(fs1);t_ynMSdg++){
        KrdatlYV += fn1[t_ynMSdg];
      }
    }
    int a2conNHc;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type hCmBdyQB;
    if(fs2==0){
      hCmBdyQB = 0;
    }
    else{
      hCmBdyQB = fn2[0];
      for(a2conNHc=(1);a2conNHc<(fs2);a2conNHc++){
        hCmBdyQB += fn2[a2conNHc];
      }
    }
    s = 2 *FmcKpFmN+KrdatlYV+hCmBdyQB;
    if(K > s){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    wt_L("YES");
    wt_L('\n');
  }
  return 0;
}
template<class T> inline int isPrime(T n){
  T i;
  if(n<=1){
    return 0;
  }
  if(n <= (1ULL<<32) - 1){
    return isPrime32(n);
  }
  if(n <= (1ULL<<63) - 1 + (1ULL<<63)){
    return isPrime64(n);
  }
  if(n<=3){
    return 1;
  }
  if(n%2==0){
    return 0;
  }
  for(i=3;i*i<=n;i+=2){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}
int isPrime32_sub(int b, unsigned n){
  unsigned i;
  unsigned t = 0;
  unsigned u = n-1;
  unsigned long long nw;
  unsigned long long nx;
  while(!(u&1)){
    t++;
    u >>= 1;
  }
  nw = 1;
  nx = b % n;
  while(u){
    if(u&1){
      nw = (nw * nx) % n;
    }
    nx = (nx * nx) % n;
    u >>= 1;
  }
  for(i=(0);i<(t);i++){
    nx = (nw * nw) % n;
    if(nx == 1 && nw != 1 && nw != n-1){
      return 0;
    }
    nw = nx;
  }
  if(nw == 1){
    return 1;
  }
  return 0;
}
int isPrime32(unsigned n){
  if(n < 100000){
    return isPrime_prime_table[n];
  }
  if(n % 2 == 0){
    return 0;
  }
  if(!isPrime32_sub(2,n)){
    return 0;
  }
  if(n<=1000000){
    if(!isPrime32_sub(3,n)){
      return 0;
    }
  }
  else{
    if(!isPrime32_sub(7,n)){
      return 0;
    }
    if(!isPrime32_sub(61,n)){
      return 0;
    }
  }
  return 1;
}
int isPrime64_sub(long long b, unsigned long long n){
  unsigned long long i;
  unsigned long long t = 0;
  unsigned long long u = n-1;
  __uint128_t nw;
  __uint128_t nx;
  while(!(u&1)){
    t++;
    u >>= 1;
  }
  nw = 1;
  nx = b % n;
  while(u){
    if(u&1){
      nw = (nw * nx) % n;
    }
    nx = (nx * nx) % n;
    u >>= 1;
  }
  for(i=(0);i<(t);i++){
    nx = (nw * nw) % n;
    if(nx == 1 && nw != 1 && nw != n-1){
      return 0;
    }
    nw = nx;
  }
  if(nw == 1){
    return 1;
  }
  return 0;
}
int isPrime64(unsigned long long n){
  if(n < 100000){
    return isPrime_prime_table[n];
  }
  if(n < (1ULL<<32)){
    return isPrime32(n);
  }
  if(n % 2 == 0){
    return 0;
  }
  if(!isPrime64_sub(2,n)){
    return 0;
  }
  if(n <= 21652684502221ULL){
    if(!isPrime64_sub(1215,n)){
      return 0;
    }
    if(!isPrime64_sub(34862,n)){
      return 0;
    }
    if(!isPrime64_sub(574237825,n)){
      return 0;
    }
  }
  else{
    if(!isPrime64_sub(325,n)){
      return 0;
    }
    if(!isPrime64_sub(9375,n)){
      return 0;
    }
    if(!isPrime64_sub(28178,n)){
      return 0;
    }
    if(!isPrime64_sub(450775,n)){
      return 0;
    }
    if(!isPrime64_sub(9780504,n)){
      return 0;
    }
    if(!isPrime64_sub(1795265022,n)){
      return 0;
    }
  }
  return 1;
}
void isPrime32_init(void){
  int i;
  int j;
  int k;
  k =Isqrt_f_L(ISPRIME_PRE_CALC_SIZE);
  for(i=(2);i<(ISPRIME_PRE_CALC_SIZE);i++){
    isPrime_prime_table[i] = 1;
  }
  for(i=(2);i<(k+1);i++){
    if(isPrime_prime_table[i]){
      for(j=(i*i);j<(ISPRIME_PRE_CALC_SIZE);j+=(i)){
        isPrime_prime_table[j] = 0;
      }
    }
  }
}
template<class T, class R1, class R2> int Factor(T N, R1 fac[], R2 fs[], void *mem/* = wmem*/){
  T i;
  int sz = 0;
  if(N <= 1){
    return sz;
  }
  if(N <= (1ULL<<32) - 1){
    return Factor32(N, fac, fs, mem);
  }
  if(N <= (1ULL<<63) - 1 + (1ULL<<63)){
    return Factor64(N, fac, fs, mem);
  }
  if(N%2==0){
    fac[sz] = 2;
    fs[sz] = 1;
    N /= 2;
    while(N%2==0){
      N /= 2;
      fs[sz]++;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      fs[sz] = 1;
      N /= i;
      while(N%i==0){
        N /= i;
        fs[sz]++;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    fs[sz] = 1;
    sz++;
  }
  return sz;
}
template<class T, class R1> int Factor(T N, R1 fac[], void *mem/* = wmem*/){
  int*fs;
  walloc1d(&fs,128,&mem);
  return Factor(N, fac, fs, mem);
}
template<class T> int Factor(T N, void *mem/* = wmem*/){
  T*fac;
  int*fs;
  walloc1d(&fac,128,&mem);
  walloc1d(&fs,128,&mem);
  return Factor(N, fac, fs, mem);
}
unsigned Factor32_rho(unsigned n){
  static Rand rnd;
  const int step = 16;
  int i;
  int s;
  int nx;
  int mx;
  unsigned long long x;
  unsigned long long y;
  unsigned long long memo;
  unsigned long long c;
  unsigned long long m;
  unsigned g;
  long long lm;
  lm =min_L(1ULL<<30, n - 1);
  for(;;){
    x = y = rnd.get(1LL, lm);
    c = rnd.get(1LL, lm);
    g = 1;
    for(nx=1;g==1;nx<<=1){
      x = y;
      for(i=(0);i<(nx);i++){
        y = (y * y + c) % n;
      }
      for(s=0;s<nx&&g==1;s+=step){
        m = 1;
        memo = y;
        mx =min_L(step, nx-s);
        for(i=(0);i<(mx);i++){
          y = (y * y + c) % n;
          if(x >= y){
            m = (m * (x - y)) % n;
          }
          else{
            m = (m * (y - x)) % n;
          }
        }
        g =GCD_L(n, m);
        if(g != 1){
          if(g != n){
            return g;
          }
          y = memo;
          for(;;){
            y = (y * y + c) % n;
            if(x >= y){
              m = x - y;
            }
            else{
              m = y - x;
            }
            g =GCD_L(n, m);
            if(g == n){
              break;
            }
            if(g != 1){
              return g;
            }
          }
        }
      }
    }
  }
  return 0;
}
template<class R1, class R2> int Factor32(unsigned N, R1 fac[], R2 fs[], void *mem/* = wmem*/){
  int res = 0;
  int sz = 0;
  int i;
  int k;
  unsigned*val;
  unsigned*valtmp;
  unsigned pf;
  unsigned n;
  if(N <= 1){
    return 0;
  }
  walloc1d(&val, 128, &mem);
  walloc1d(&valtmp, 128, &mem);
  while(N%2==0){
    val[res++] = 2;
    N /= 2;
  }
  while(N%3==0){
    val[res++] = 3;
    N /= 3;
  }
  while(N%5==0){
    val[res++] = 5;
    N /= 5;
  }
  if(N > 1){
    valtmp[sz++] = N;
  }
  while(sz){
    while(sz && isPrime32(valtmp[sz-1])){
      val[res] = valtmp[sz-1];
      res++;
      sz--;
    }
    if(sz==0){
      break;
    }
    n = valtmp[sz-1];
    if(n < FACTOR_PRE_CALC_SIZE){
      while(n > 1){
        val[res++] = factor_hasprime_table[n];
        n /= factor_hasprime_table[n];
      }
      sz--;
    }
    else{
      pf = Factor32_rho(n);
      valtmp[sz-1] = pf;
      valtmp[sz] = n / pf;
      sz++;
    }
  }
  sortA_L(res, val, mem);
  k = 0;
  for(i=(0);i<(res);i++){
    if(k && fac[k-1] == val[i]){
      fs[k-1]++;
      continue;
    }
    fac[k] = val[i];
    fs[k] = 1;
    k++;
  }
  res = k;
  return res;
}
unsigned long long Factor64_rho(unsigned long long n){
  static Rand rnd;
  const int step = 16;
  int i;
  int s;
  int nx;
  int mx;
  __uint128_t x;
  __uint128_t y;
  __uint128_t memo;
  __uint128_t c;
  __uint128_t m;
  unsigned long long g;
  long long lm;
  lm =min_L(1ULL<<30, n - 1);
  for(;;){
    x = y = rnd.get(1LL, lm);
    c = rnd.get(1LL, lm);
    g = 1;
    for(nx=1;g==1;nx<<=1){
      x = y;
      for(i=(0);i<(nx);i++){
        y = (y * y + c) % n;
      }
      for(s=0;s<nx&&g==1;s+=step){
        m = 1;
        memo = y;
        mx =min_L(step, nx-s);
        for(i=(0);i<(mx);i++){
          y = (y * y + c) % n;
          if(x >= y){
            m = (m * (x - y)) % n;
          }
          else{
            m = (m * (y - x)) % n;
          }
        }
        g =GCD_L(n, m);
        if(g != 1){
          if(g != n){
            return g;
          }
          y = memo;
          for(;;){
            y = (y * y + c) % n;
            if(x >= y){
              m = x - y;
            }
            else{
              m = y - x;
            }
            g =GCD_L(n, m);
            if(g == n){
              break;
            }
            if(g != 1){
              return g;
            }
          }
        }
      }
    }
  }
  return 0;
}
template<class R1, class R2> int Factor64(unsigned long long N, R1 fac[], R2 fs[], void *mem/* = wmem*/){
  int res = 0;
  int sz = 0;
  int i;
  int k;
  unsigned long long*val;
  unsigned long long*valtmp;
  unsigned long long pf;
  unsigned long long n;
  if(N <= 1){
    return 0;
  }
  walloc1d(&val, 128, &mem);
  walloc1d(&valtmp, 128, &mem);
  while(N%2==0){
    val[res++] = 2;
    N /= 2;
  }
  while(N%3==0){
    val[res++] = 3;
    N /= 3;
  }
  while(N%5==0){
    val[res++] = 5;
    N /= 5;
  }
  if(N > 1){
    valtmp[sz++] = N;
  }
  while(sz){
    while(sz && isPrime64(valtmp[sz-1])){
      val[res] = valtmp[sz-1];
      res++;
      sz--;
    }
    if(sz==0){
      break;
    }
    n = valtmp[sz-1];
    if(n < FACTOR_PRE_CALC_SIZE){
      while(n > 1){
        val[res++] = factor_hasprime_table[n];
        n /= factor_hasprime_table[n];
      }
      sz--;
    }
    else if(n < (1ULL<<32)){
      pf = Factor32_rho(n);
      valtmp[sz-1] = pf;
      valtmp[sz] = n / pf;
      sz++;
    }
    else{
      pf = Factor64_rho(n);
      valtmp[sz-1] = pf;
      valtmp[sz] = n / pf;
      sz++;
    }
  }
  sortA_L(res, val, mem);
  k = 0;
  for(i=(0);i<(res);i++){
    if(k && fac[k-1] == val[i]){
      fs[k-1]++;
      continue;
    }
    fac[k] = val[i];
    fs[k] = 1;
    k++;
  }
  res = k;
  return res;
}
void Factor32_init(void){
  int i;
  int j;
  int k;
  k =Isqrt_f_L(FACTOR_PRE_CALC_SIZE);
  for(i=(2);i<(FACTOR_PRE_CALC_SIZE);i++){
    factor_hasprime_table[i] = i;
  }
  for(i=(2);i<(k+1);i++){
    if(factor_hasprime_table[i]==i){
      for(j=(i*i);j<(FACTOR_PRE_CALC_SIZE);j+=(i)){
        factor_hasprime_table[j] = i;
      }
    }
  }
}
// cLay version 20210611-1 [beta]

// --- original code ---
// //no-unlocked
// int fs1, fn1[100]; int f1[100];
// int fs2, fn2[100]; int f2[100];
// int fs3, fn3[100]; int f3[100];
// {
//   REP(rd_int()){
//     int @A, @B, @K, g, s;
//     g = gcd(A,B);
//     fs3 = Factor(g, f3, fn3);
//     fs1 = Factor(A/g, f1, fn1);
//     fs2 = Factor(B/g, f2, fn2);
//     if(fs1 == fs2 == 0 && K == 1) wt("NO"), continue;
//     if(fs1 && fs2 && K == 1) wt("NO"), continue;
//     s = 2 * sum(fn3(fs3)) + sum(fn1(fs1)) + sum(fn2(fs2));
//     if(K > s) wt("NO"), continue;
//     wt("YES");
//   }
// }