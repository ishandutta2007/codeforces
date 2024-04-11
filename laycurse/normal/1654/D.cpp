#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define MD (998244353U)
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
struct Modint{
  unsigned val;
  Modint(){
    val=0;
  }
  Modint(int a){
    val = ord(a);
  }
  Modint(unsigned a){
    val = ord(a);
  }
  Modint(long long a){
    val = ord(a);
  }
  Modint(unsigned long long a){
    val = ord(a);
  }
  inline unsigned ord(unsigned a){
    return a%MD;
  }
  inline unsigned ord(int a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned ord(unsigned long long a){
    return a%MD;
  }
  inline unsigned ord(long long a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned get(){
    return val;
  }
  inline Modint &operator++(){
    val++;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  inline Modint &operator--(){
    if(val == 0){
      val = MD - 1;
    }
    else{
      --val;
    }
    return *this;
  }
  inline Modint operator++(int a){
    Modint res(*this);
    val++;
    if(val >= MD){
      val -= MD;
    }
    return res;
  }
  inline Modint operator--(int a){
    Modint res(*this);
    if(val == 0){
      val = MD - 1;
    }
    else{
      --val;
    }
    return res;
  }
  inline Modint &operator+=(Modint a){
    val += a.val;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  inline Modint &operator-=(Modint a){
    if(val < a.val){
      val = val + MD - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  inline Modint &operator*=(Modint a){
    val = ((unsigned long long)val*a.val)%MD;
    return *this;
  }
  inline Modint &operator/=(Modint a){
    return *this *= a.inverse();
  }
  inline Modint operator+(Modint a){
    return Modint(*this)+=a;
  }
  inline Modint operator-(Modint a){
    return Modint(*this)-=a;
  }
  inline Modint operator*(Modint a){
    return Modint(*this)*=a;
  }
  inline Modint operator/(Modint a){
    return Modint(*this)/=a;
  }
  inline Modint operator+(int a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(int a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(int a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(int a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator+(long long a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(long long a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(long long a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(long long a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator-(void){
    Modint res;
    if(val){
      res.val=MD-val;
    }
    else{
      res.val=0;
    }
    return res;
  }
  inline operator bool(void){
    return val!=0;
  }
  inline operator int(void){
    return get();
  }
  inline operator long long(void){
    return get();
  }
  inline Modint inverse(){
    int a = val;
    int b = MD;
    int u = 1;
    int v = 0;
    int t;
    Modint res;
    while(b){
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if(u < 0){
      u += MD;
    }
    res.val = u;
    return res;
  }
  inline Modint pw(unsigned long long b){
    Modint a(*this);
    Modint res;
    res.val = 1;
    while(b){
      if(b&1){
        res *= a;
      }
      b >>= 1;
      a *= a;
    }
    return res;
  }
  inline bool operator==(int a){
    return ord(a)==val;
  }
  inline bool operator!=(int a){
    return ord(a)!=val;
  }
}
;
inline Modint operator+(int a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(int a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(int a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(int a, Modint b){
  return Modint(a)/=b;
}
inline Modint operator+(long long a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(long long a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(long long a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(long long a, Modint b){
  return Modint(a)/=b;
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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(Modint x){
  int i;
  i = (int)x;
  wt_L(i);
}
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
}
template<class T> inline T pow2_L(T a){
  return a*a;
}
template<class T, class S> inline T pow_L(T a, S b){
  T res = 1;
  res = 1;
  for(;;){
    if(b&1){
      res *= a;
    }
    b >>= 1;
    if(b==0){
      break;
    }
    a *= a;
  }
  return res;
}
inline double pow_L(double a, double b){
  return pow(a,b);
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
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
struct graph{
  int N;
  int*es;
  int**edge;
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
}
;
template<class T> struct wgraph{
  int N;
  int*es;
  int**edge;
  T**cost;
  graph g;
  void setEdge(int N__, int M, int A[], int B[], T C[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    walloc1d(&cost, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&cost[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]] = B[i];
      edge[B[i]][es[B[i]]] = A[i];
      cost[A[i]][es[A[i]]++] = C[i];
      cost[B[i]][es[B[i]]++] = C[i];
    }
    g.N = N;
    g.es = es;
    g.edge = edge;
  }
}
;
int N;
int A[200000+2];
int B[200000+2];
int X[200000+2];
int Y[200000+2];
int ind[200000+2];
wgraph<int> g;
int has[200000+2];
int mx[200000+2];
Modint w[200000+2];
void dfs(int n, int b){
  int i;
  int j;
  int k;
  int xx;
  int yy;
  int id;
  int fs;
  int f[40];
  int fn[40];
  for(i=(0);i<(g.es[n]);i++){
    k = g.edge[n][i];
    if(k==b){
      continue;
    }
    id = g.cost[n][i];
    if(A[id]==n){
      xx =X[id];
    }
    else{
      xx =Y[id];
    }
    if(A[id]==n){
      yy =Y[id];
    }
    else{
      yy =X[id];
    }
    fs = Factor(yy, f, fn);
    for(j=(0);j<(fs);j++){
      fn[j] *= -1;
    }
    fs += Factor(xx, f + fs, fn + fs);
    for(j=(0);j<(fs);j++){
      has[f[j]] += fn[j];
      chmax(mx[f[j]], has[f[j]]);
    }
    dfs(k, n);
    for(j=(0);j<(fs);j++){
      has[f[j]] -= fn[j];
    }
  }
}
void solve(int n, int b, Modint z){
  int i;
  int j;
  int k;
  int xx;
  int yy;
  int id;
  w[n] = z;
  for(i=(0);i<(g.es[n]);i++){
    k = g.edge[n][i];
    if(k==b){
      continue;
    }
    id = g.cost[n][i];
    if(A[id]==n){
      xx =X[id];
    }
    else{
      xx =Y[id];
    }
    if(A[id]==n){
      yy =Y[id];
    }
    else{
      yy =X[id];
    }
    solve(k, n, z / xx * yy);
  }
}
int main(){
  int pyHJGNQc;
  wmem = memarr;
  {
    isPrime32_init();
  }
  {
    Factor32_init();
  }
  int wbH8AaCb = rd_int();
  for(pyHJGNQc=(0);pyHJGNQc<(wbH8AaCb);pyHJGNQc++){
    int i;
    Modint tmp;
    rd(N);
    {
      int Dc_3QP3Y;
      for(Dc_3QP3Y=(0);Dc_3QP3Y<(N-1);Dc_3QP3Y++){
        rd(A[Dc_3QP3Y]);A[Dc_3QP3Y] += (-1);
        rd(B[Dc_3QP3Y]);B[Dc_3QP3Y] += (-1);
        rd(X[Dc_3QP3Y]);
        rd(Y[Dc_3QP3Y]);
      }
    }
    for(i=(0);i<(N-1);i++){
      ind[i] = i;
    }
    g.setEdge(N,N-1,A,B,ind);
    for(i=(0);i<(N+1);i++){
      has[i] = mx[i] = 0;
    }
    dfs(0, -1);
    tmp = 1;
    for(i=(0);i<(N+1);i++){
      if(mx[i]){
        tmp *=(pow_L(Modint(i),mx[i]));
      }
    }
    solve(0, -1, tmp);
    int ZcmRJqJU;
    cLtraits_try_make_signed<remove_reference<decltype((*((Modint*)NULL)))>::type>::type Jq7Vmy8K;
    if(N==0){
      Jq7Vmy8K = 0;
    }
    else{
      Jq7Vmy8K = w[0];
      for(ZcmRJqJU=(1);ZcmRJqJU<(N);ZcmRJqJU++){
        Jq7Vmy8K += w[ZcmRJqJU];
      }
    }
    wt_L(Jq7Vmy8K);
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
// cLay version 20220312-1

// --- original code ---
// //no-unlocked
// #define MD 998244353
// int N, A[2d5+2], B[], X[], Y[], ind[];
// wgraph<int> g;
// 
// int has[], mx[];
// Modint w[];
// 
// void dfs(int n, int b){
//   int i, j, k, xx, yy, id;
//   int fs, f[40], fn[40];
//   rep(i,g.es[n]){
//     k = g.edge[n][i]; if(k==b) continue;
//     id = g.cost[n][i];
//     xx = if[A[id]==n, X[id], Y[id]];
//     yy = if[A[id]==n, Y[id], X[id]];
//     fs = Factor(yy, f, fn);
//     rep(j,fs) fn[j] *= -1;
//     fs += Factor(xx, f + fs, fn + fs);
//     rep(j,fs){
//       has[f[j]] += fn[j];
//       mx[f[j]] >?= has[f[j]];
//     }
//     dfs(k, n);
//     rep(j,fs) has[f[j]] -= fn[j];
//   }
// }
// 
// void solve(int n, int b, Modint z){
//   int i, j, k, xx, yy, id;
//   w[n] = z;
//   rep(i,g.es[n]){
//     k = g.edge[n][i]; if(k==b) continue;
//     id = g.cost[n][i];
//     xx = if[A[id]==n, X[id], Y[id]];
//     yy = if[A[id]==n, Y[id], X[id]];
//     solve(k, n, z / xx * yy);
//   }
// }
// 
// {
//   REP(rd_int()){
//     Modint tmp;
//     rd(N,(A--,B--,X,Y)(N-1));
//     rep(i,N-1) ind[i] = i;
//     g.setEdge(N,N-1,A,B,ind);
//     rep(i,N+1) has[i] = mx[i] = 0;
//     dfs(0, -1);
//     tmp = 1;
//     rep(i,N+1) if(mx[i]) tmp *= Modint(i) ** mx[i];
//     solve(0, -1, tmp);
//     wt(sum(w(N)));
//   }
// }