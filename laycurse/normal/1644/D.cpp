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
int N;
int M;
int K;
int Q;
int X[200000+1];
int Y[200000+1];
int cx[200000+1];
int cy[200000+1];
int ccx[200000+1];
int ccy[200000+1];
template<class T, class S> int arr2hist(int N, const T A[], S res[], int mn, int mx){
  int i;
  int d;
  d = mx - mn + 1;
  for(i=(0);i<(d);i++){
    res[i] = 0;
  }
  for(i=(0);i<(N);i++){
    res[A[i]-mn]++;
  }
  return d;
}
template<class T1, class T2> void DupDel(int &N, T1 A[], T2 B[], void *mem = wmem){
  int i;
  int k;
  pair<pair<T1,T2>,int>*arr;
  char*del;
  walloc1d(&arr,N,&mem);
  walloc1d(&del,N,&mem);
  for(i=(0);i<(N);i++){
    arr[i].first.first = A[i];
    arr[i].first.second = B[i];
    arr[i].second = i;
  }
  sort(arr,arr+N);
  for(i=(0);i<(N);i++){
    del[i] = 0;
  }
  for(i=(0);i<(N);i++){
    if(i && (arr[i-1].first == arr[i].first)){
      del[arr[i].second] = 1;
    }
  }
  k = N;
  N = 0;
  for(i=(0);i<(k);i++){
    if(del[i]==0){
      A[N] = A[i];
      B[N] = B[i];
      N++;
    }
  }
}
template<class T1, class T2> void DupDelL(int &N, T1 A[], T2 B[], void *mem = wmem){
  int i;
  int k;
  pair<pair<T1,T2>,int>*arr;
  char*del;
  walloc1d(&arr,N,&mem);
  walloc1d(&del,N,&mem);
  for(i=(0);i<(N);i++){
    arr[i].first.first = A[i];
    arr[i].first.second = B[i];
    arr[i].second = i;
  }
  sort(arr,arr+N);
  for(i=(0);i<(N);i++){
    del[i] = 0;
  }
  for(i=(0);i<(N);i++){
    if(i && (arr[i-1].first == arr[i].first)){
      del[arr[i-1].second] = 1;
    }
  }
  k = N;
  N = 0;
  for(i=(0);i<(k);i++){
    if(del[i]==0){
      A[N] = A[i];
      B[N] = B[i];
      N++;
    }
  }
}
int main(){
  int BRSo37Cn;
  wmem = memarr;
  int c6807iQa = rd_int();
  for(BRSo37Cn=(0);BRSo37Cn<(c6807iQa);BRSo37Cn++){
    int i;
    int res = 0;
    rd(N);
    rd(M);
    rd(K);
    rd(Q);
    {
      int Jq7Vmy8K;
      for(Jq7Vmy8K=(0);Jq7Vmy8K<(Q);Jq7Vmy8K++){
        rd(X[Jq7Vmy8K]);X[Jq7Vmy8K] += (-1);
        rd(Y[Jq7Vmy8K]);Y[Jq7Vmy8K] += (-1);
      }
    }
    N =min_L(N,coordcomp_L(Q,X)+1);
    M =min_L(M,coordcomp_L(Q,Y)+1);
    DupDelL(Q,X,Y);
    arr2hist(Q,X,cx,0,N-1);
    arr2hist(Q,Y,cy,0,M-1);
    arr2hist(N,cx,ccx,0,Q);
    arr2hist(M,cy,ccy,0,Q);
    for(i=(0);i<(Q);i++){
      ccx[cx[X[i]]]--;
      cx[X[i]]--;
      ccx[cx[X[i]]]++;
      ccy[cy[Y[i]]]--;
      cy[Y[i]]--;
      ccy[cy[Y[i]]]++;
      if(ccx[0]==0 || ccy[0]==0 || (cx[X[i]] && cy[Y[i]])){
        continue;
      }
      res++;
    }
    wt_L((pow_L(Modint(K),res)));
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
// #define MD 998244353
// int N, M, K, Q, X[2d5+1], Y[];
// int cx[], cy[], ccx[], ccy[];
// 
// template<class T, class S>
// int arr2hist(int N, const T A[], S res[], int mn, int mx){
//   int i, d;
//   d = mx - mn + 1;
//   rep(i,d) res[i] = 0;
//   rep(i,N) res[A[i]-mn]++;
//   return d;
// }
// 
// template<class T1, class T2>
// void DupDel(int &N, T1 A[], T2 B[], void *mem = wmem){
//   int i, k;
//   pair<pair<T1,T2>,int> *arr;
//   char *del;
//   walloc1d(&arr,N,&mem);
//   walloc1d(&del,N,&mem);
//   rep(i,N){
//     arr[i].first.first = A[i];
//     arr[i].first.second = B[i];
//     arr[i].second = i;
//   }
//   sort(arr,arr+N);
// 
//   rep(i,N) del[i] = 0;
//   rep(i,N) if(i && (arr[i-1].first == arr[i].first)) del[arr[i].second] = 1;
// 
//   k = N;
//   N = 0;
//   rep(i,k) if(del[i]==0){
//     A[N] = A[i];
//     B[N] = B[i];
//     N++;
//   }
// }
// 
// template<class T1, class T2>
// void DupDelL(int &N, T1 A[], T2 B[], void *mem = wmem){
//   int i, k;
//   pair<pair<T1,T2>,int> *arr;
//   char *del;
//   walloc1d(&arr,N,&mem);
//   walloc1d(&del,N,&mem);
//   rep(i,N){
//     arr[i].first.first = A[i];
//     arr[i].first.second = B[i];
//     arr[i].second = i;
//   }
//   sort(arr,arr+N);
// 
//   rep(i,N) del[i] = 0;
//   rep(i,N) if(i && (arr[i-1].first == arr[i].first)) del[arr[i-1].second] = 1;
// 
//   k = N;
//   N = 0;
//   rep(i,k) if(del[i]==0){
//     A[N] = A[i];
//     B[N] = B[i];
//     N++;
//   }
// }
// 
// {
//   REP(rd_int()){
//     int res = 0;
//     rd(N,M,K,Q,(X--,Y--)(Q));
//     N = min(N, coordcomp(Q,X)+1);
//     M = min(M, coordcomp(Q,Y)+1);
//     DupDelL(Q,X,Y);
//     arr2hist(Q,X,cx,0,N-1);
//     arr2hist(Q,Y,cy,0,M-1);
//     arr2hist(N,cx,ccx,0,Q);
//     arr2hist(M,cy,ccy,0,Q);
//     rep(i,Q){
//       ccx[cx[X[i]]]--; cx[X[i]]--; ccx[cx[X[i]]]++;
//       ccy[cy[Y[i]]]--; cy[Y[i]]--; ccy[cy[Y[i]]]++;
//       if(ccx[0]==0 || ccy[0]==0 || (cx[X[i]] && cy[Y[i]])) continue;
//       res++;
//     }
//     wt(Modint(K)**res);
//   }
// }