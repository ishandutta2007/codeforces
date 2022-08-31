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
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
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
int main(){
  int i;
  {
    rollingHashInit();
  }
  int N;
  rd(N);
  int LEN[10];
  int C[10][200000];
  for(i=(0);i<(N);i++){
    rd(LEN[i]);
    {
      int Q5VJL1cS;
      for(Q5VJL1cS=(0);Q5VJL1cS<(LEN[i]);Q5VJL1cS++){
        rd(C[i][Q5VJL1cS]);
      }
    }
  }
  int M;
  rd(M);
  int B[M][N];
  {
    int RZTsC2BF;
    int FmcKpFmN;
    for(RZTsC2BF=(0);RZTsC2BF<(M);RZTsC2BF++){
      for(FmcKpFmN=(0);FmcKpFmN<(N);FmcKpFmN++){
        rd(B[RZTsC2BF][FmcKpFmN]);B[RZTsC2BF][FmcKpFmN] += (-1);
      }
    }
  }
  set<unsigned long long> bhs;
  set<pair<long long,vector<int>>> q;
  vector<int> lis(N);
  int arr[N];
  long long gain;
  for(i=(0);i<(M);i++){
    bhs.insert(calcRollingHash(N,B[i]).hs);
  }
  gain = 0;
  for(i=(0);i<(N);i++){
    lis[i] = LEN[i]-1;
    gain += C[i][LEN[i]-1];
  }
  q.insert({-gain,lis});
  for(;;){
    gain = -q.begin()->first;
    lis = q.begin()->second;
    q.erase(q.begin());
    for(i=(0);i<(N);i++){
      arr[i] = lis[i];
    }
    if(!bhs.count(calcRollingHash(N,arr).hs)){
      break;
    }
    for(i=(0);i<(N);i++){
      if(lis[i]){
        lis[i]--;
        gain += C[i][lis[i]] - C[i][lis[i]+1];
        q.insert({-gain,lis});
        gain -= C[i][lis[i]] - C[i][lis[i]+1];
        lis[i]++;
      }
    }
  }
  {
    int iMWUTgY_;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(iMWUTgY_=(0);iMWUTgY_<(N-1);iMWUTgY_++){
        wt_L(lis[iMWUTgY_]+1);
        wt_L(' ');
      }
      wt_L(lis[iMWUTgY_]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210917-1

// --- original code ---
// //no-unlocked
// int @N, LEN[10], C[10][2d5];
// rep(i,N) rd(LEN[i], C[i](LEN[i]));
// int @M, @B[M][N]--; set<ull> bhs;
// set<pair<ll,VI>> q;
// VI lis(N); int arr[N]; ll gain;
// 
// rep(i,M) bhs.insert(calcRollingHash(N,B[i]).hs);
// 
// gain = 0;
// rep(i,N) lis[i] = LEN[i]-1, gain += C[i][LEN[i]-1];
// q.insert({-gain,lis});
// for(;;){
//   gain = -q.begin()->first;
//   lis = q.begin()->second;
//   q.erase(q.begin());
//   rep(i,N) arr[i] = lis[i];
//   if(!bhs.count(calcRollingHash(N,arr).hs)) break;
//   rep(i,N) if(lis[i]){
//     lis[i]--;
//     gain += C[i][lis[i]] - C[i][lis[i]+1];
//     q.insert({-gain,lis});
//     gain -= C[i][lis[i]] - C[i][lis[i]+1];
//     lis[i]++;
//   }
// }
// wt(lis(N)+1);