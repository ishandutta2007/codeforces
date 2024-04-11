#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define MD (1000000007U)
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
template<class T1, class T2, class T3> inline T1 Kth1_L(const T1 a, const T2 b, const T3 c){
  if(a <= b){
    if(b <= c){
      return b;
    }
    if(c <= a){
      return a;
    }
    return c;
  }
  if(a <= c){
    return a;
  }
  if(c <= b){
    return b;
  }
  return c;
}
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
inline void wt_L(Modint x){
  int i;
  i = (int)x;
  wt_L(i);
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
  T getSum(int i, int j){
    if(set_cumulative_sum==0){
      setSum();
    }
    return cumulative_sum[j+1] - cumulative_sum[i];
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
  void set(vector<T> &a){
    int i;
    int nn = a.size();
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  void set(int nn, T a[]){
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
int N;
int Q;
int X;
Arr1d<int> C;
Arr1d<int> B;
Modint dp[101][10001];
Modint s[10002];
Modint res[6000];
int main(){
  int BUotOFBp;
  wmem = memarr;
  int lm;
  int st = 0;
  rd(N);
  C.malloc(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(C[Lj4PdHRW]);
    }
  }
  B.malloc(N-1);
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N-1);e98WHCEY++){
      rd(B[e98WHCEY]);
    }
  }
  rd(Q);
  dp[0][0] = 1;
  for(X=(102)-1;X>=(-5000);X--){
    int k;
    lm = 0;
    for(k=(0);k<(N);k++){
      lm += X + B.getSum(0, k-1);
      if(lm > 10000+1){
        lm = 0;
      }
    }
    if(lm == 10000+1){
      continue;
    }
    lm = 0;
    for(k=(0);k<(st);k++){
      lm += X + B.getSum(0, k-1);
      if(lm > 10000+1){
        lm = 0;
      }
    }
    for(k=(st);k<(N);k++){
      int i;
      lm += X + B.getSum(0, k-1);
      if(lm > 10000+1){
        lm = 10000+1;
      }
      s[0] = 0;
      for(i=(0);i<(10000+1);i++){
        s[i+1] = s[i] + dp[k][i];
      }
      for(i=(0);i<(lm);i++){
        dp[k+1][i] = 0;
      }
      for(i=(lm);i<(10000+1);i++){
        dp[k+1][i] = s[i+1] - s[max_L(0, i-C[k])];
      }
      if(X <= -100 && lm <= 0){
        st = k + 1;
      }
    }
    int iMWUTgY_;
    cLtraits_try_make_signed<remove_reference<decltype((*((Modint*)NULL)))>::type>::type AlM5nNnR;
    if(10000+1==0){
      AlM5nNnR = 0;
    }
    else{
      AlM5nNnR = dp[N][0];
      for(iMWUTgY_=(1);iMWUTgY_<(10000+1);iMWUTgY_++){
        AlM5nNnR += dp[N][iMWUTgY_];
      }
    }
    res[X+5000] =AlM5nNnR;
  }
  int Q5rsz4fz = Q;
  for(BUotOFBp=(0);BUotOFBp<(Q5rsz4fz);BUotOFBp++){
    rd(X);
    X =Kth1_L(-5000, X, 101);
    wt_L(res[X+5000]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210619-1 [beta]

// --- original code ---
// //no-unlocked
// int N, Q, X;
// Arr1d<int> C, B;
// Modint dp[101][10001], s[10002];
// Modint res[6000];
// {
//   int lm, st = 0;
//   rd(N,C(N),B(N-1),Q);
//   // N = 100;
//   // C.setN(100); rep(i,N) C[i] = 90 + rand()%11;
//   // B.setN(100); rep(i,N) B[i] = 90 + rand()%11;
// 
//   dp[0][0] = 1;
//   rrep(X,-5000,102){
//     lm = 0;
//     rep(k,N){
//       lm += X + B.getSum(0, k-1);
//       if(lm > 1d4+1) lm = 0;
//     }
//     if(lm == 1d4+1) continue;
// 
//     lm = 0;
//     rep(k,st){
//       lm += X + B.getSum(0, k-1);
//       if(lm > 1d4+1) lm = 0;
//     }
//     rep(k,st,N){
//       lm += X + B.getSum(0, k-1);
//       if(lm > 1d4+1) lm = 1d4+1;
// 
//       s[0] = 0;
//       rep(i,1d4+1) s[i+1] = s[i] + dp[k][i];
//       rep(i,lm) dp[k+1][i] = 0;
//       rep(i,lm,1d4+1) dp[k+1][i] = s[i+1] - s[max(0,i-C[k])];
// 
//       if(X <= -100 && lm <= 0) st = k + 1;
//     }
//     res[X+5000] = sum(dp[N](1d4+1));
//     // if(X%50==0) wt(X,st);
//   }
//   REP(Q){
//     rd(X);
//     X = Kth1(-5000, X, 101);
//     wt(res[X+5000]);
//   }
// }