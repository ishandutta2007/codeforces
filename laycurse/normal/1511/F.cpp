#pragma GCC optimize ("Ofast")
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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
template<class T> struct Matrix{
  int r;
  int c;
  int mem;
  T*dat;
  Matrix(){
    r=c=mem = 0;
  }
  Matrix(const int rr, const int cc){
    if(rr == 0 || cc == 0){
      r = c = 0;
    }
    else{
      r = rr;
      c = cc;
    }
    mem = r * c;
    if(mem > 0){
      dat = new T[mem];
    }
  }
  Matrix(const Matrix<T> &a){
    int i;
    r = a.r;
    c = a.c;
    mem = r * c;
    dat = new T[mem];
    for(i=(0);i<(mem);i++){
      dat[i] = a.dat[i];
    }
  }
  ~Matrix(){
    if(mem){
      delete [] dat;
    }
  }
  void changeSize(const int rr, const int cc){
    if(rr==0 || cc==0){
      r = c = 0;
    }
    else{
      r = rr;
      c = cc;
    }
    if(mem < r*c){
      if(mem){
        delete [] dat;
      }
      mem = r*c;
      dat = new T[mem];
    }
  }
  Matrix<T>& operator=(const Matrix<T> &a){
    int i;
    int j;
    r = a.r;
    c = a.c;
    j = r * c;
    changeSize(r,c);
    for(i=(0);i<(j);i++){
      dat[i] = a.dat[i];
    }
    return *this;
  }
  Matrix<T>& operator=(const int a){
    int i;
    int j;
    j = r * c;
    for(i=(0);i<(j);i++){
      dat[i] = 0;
    }
    j =min_L(r, c);
    for(i=(0);i<(j);i++){
      dat[i*c+i] = a;
    }
    return *this;
  }
  Matrix<T>& operator+=(const Matrix<T> &a){
    int i;
    int j;
    if(r==0 || r!=a.r || c!=a.c){
      changeSize(0,0);
      return *this;
    }
    j = r*c;
    for(i=(0);i<(j);i++){
      dat[i] += a.dat[i];
    }
    return *this;
  }
  Matrix<T> operator+(const Matrix<T> &a){
    return Matrix<T>(*this) += a;
  }
  Matrix<T>& operator-=(const Matrix<T> &a){
    int i;
    int j;
    if(r==0 || r!=a.r || c!=a.c){
      changeSize(0,0);
      return *this;
    }
    j = r*c;
    for(i=(0);i<(j);i++){
      dat[i] -= a.dat[i];
    }
    return *this;
  }
  Matrix<T> operator-(const Matrix<T> &a){
    return Matrix<T>(*this) -= a;
  }
  Matrix<T>& operator*=(const Matrix<T> &a){
    int i;
    int j;
    int k;
    int x;
    T*m;
    if(r==0 || c!=a.r){
      changeSize(0,0);
      return *this;
    }
    m = (T*)wmem;
    x = r * a.c;
    for(i=(0);i<(x);i++){
      m[i] = 0;
    }
    for(i=(0);i<(r);i++){
      for(k=(0);k<(c);k++){
        for(j=(0);j<(a.c);j++){
          m[i*a.c+j] += dat[i*c+k] * a.dat[k*a.c+j];
        }
      }
    }
    changeSize(r, a.c);
    for(i=(0);i<(x);i++){
      dat[i] = m[i];
    }
    return *this;
  }
  Matrix<T> operator*(const Matrix<T> &a){
    return Matrix<T>(*this) *= a;
  }
  Matrix<T>& operator*=(const int a){
    int i;
    int j;
    j = r * c;
    for(i=(0);i<(j);i++){
      dat[i] *= a;
    }
    return *this;
  }
  Matrix<T>& operator*=(const long long a){
    int i;
    int j;
    j = r * c;
    for(i=(0);i<(j);i++){
      dat[i] *= a;
    }
    return *this;
  }
  Matrix<T>& operator*=(const double a){
    int i;
    int j;
    j = r * c;
    for(i=(0);i<(j);i++){
      dat[i] *= a;
    }
    return *this;
  }
  inline T* operator[](const int a){
    return dat+a*c;
  }
}
;
template<class T> Matrix<T> operator*(const int a, const Matrix<T> &b){
  return Matrix<T>(b)*=a;
}
template<class T> Matrix<T> operator*(const Matrix<T> &b, const int a){
  return Matrix<T>(b)*=a;
}
template<class T> Matrix<T> operator*(const long long a, const Matrix<T> &b){
  return Matrix<T>(b)*=a;
}
template<class T> Matrix<T> operator*(const Matrix<T> &b, const long long a){
  return Matrix<T>(b)*=a;
}
template<class T> Matrix<T> operator*(const double a, const Matrix<T> &b){
  return Matrix<T>(b)*=a;
}
template<class T> Matrix<T> operator*(const Matrix<T> &b, const double a){
  return Matrix<T>(b)*=a;
}
template<class T, class S> inline Matrix<T> pow_L(Matrix<T> a, S b){
  int i;
  int j;
  Matrix<T> res;
  res.changeSize(a.r, a.c);
  res = 1;
  while(b){
    if(b&1){
      res *= a;
    }
    b >>= 1;
    a *= a;
  }
  return res;
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
template<class S, class T> inline int arrcmp(int As, S A[], int Bs, T B[]){
  int i;
  for(i=0;;i++){
    if(i==As && As==Bs){
      break;
    }
    if(i==As){
      return -1;
    }
    if(i==Bs){
      return 1;
    }
    if(A[i] < B[i]){
      return -1;
    }
    if(A[i] > B[i]){
      return 1;
    }
  }
  return 0;
}
int N;
int M;
char S[8][7];
int len[8];
Matrix<Modint> mt;
int node1;
int n1[100];
int s1[100];
int edge1[26][100][100];
int node2;
int x[1000];
int y[1000];
int edge2[1000][1000];
char aa[7];
int getNode1(int a, int b){
  int i;
  for(i=(0);i<(node1);i++){
    if(n1[i]==a && s1[i]==b){
      return i;
    }
  }
  auto Q5VJL1cS = ((a));
  auto e98WHCEY = (( b));
  n1[node1]=Q5VJL1cS;
  s1[node1]=e98WHCEY;
  return node1++;
}
int getNode2(int a, int b){
  int i;
  for(i=(0);i<(node2);i++){
    if(x[i]==a && y[i]==b){
      return i;
    }
  }
  auto FmcKpFmN = ((a));
  auto xr20shxY = (( b));
  x[node2]=FmcKpFmN;
  y[node2]=xr20shxY;
  return node2++;
}
int main(){
  int n;
  wmem = memarr;
  int i;
  int j;
  int k;
  rd(N);
  rd(M);
  {
    int WYIGIcGE;
    for(WYIGIcGE=(0);WYIGIcGE<(N);WYIGIcGE++){
      len[WYIGIcGE] = rd(S[WYIGIcGE]);
    }
  }
  getNode1(0, 0);
  for(n=(0);n<(node1);n++){
    for(i=(0);i<(s1[n]);i++){
      aa[i] = S[n1[n]][i];
    }
    for(k=('a');k<('z'+1);k++){
      aa[s1[n]] = k;
      for(i=(0);i<(N);i++){
        if(arrcmp(s1[n]+1, S[i], s1[n]+1, aa) == 0){
          break;
        }
      }
      if(i < N){
        j = getNode1(i, s1[n]+1);
        edge1[k-'a'][n][j]++;
      }
      for(i=(0);i<(N);i++){
        if(arrcmp(len[i], S[i], s1[n]+1, aa) == 0){
          break;
        }
      }
      if(i < N){
        edge1[k-'a'][n][0]++;
      }
    }
  }
  getNode2(0, 0);
  for(n=(0);n<(node2);n++){
    for(k=(0);k<(26);k++){
      int m1;
      for(m1=(0);m1<(node1);m1++){
        int m2;
        for(m2=(0);m2<(node1);m2++){
          if(edge1[k][x[n]][m1] && edge1[k][y[n]][m2]){
            i = getNode2(m1, m2);
            edge2[n][i] += edge1[k][x[n]][m1] * edge1[k][y[n]][m2];
          }
        }
      }
    }
  }
  mt.changeSize(node2, node2);
  for(i=(0);i<(node2);i++){
    for(j=(0);j<(node2);j++){
      mt[i][j] = edge2[i][j];
    }
  }
  (mt = pow_L(mt,M));
  wt_L(mt[0][0]);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// #define MD 998244353
// int N, M;
// char S[8][7]; int len[8];
// Matrix<Modint> mt;
// int node1, n1[100], s1[], edge1[26][100][100];
// int node2, x[1000], y[], edge2[1000][1000];
// char aa[7];
// 
// int getNode1(int a, int b){
//   rep(i,node1) if(n1[i]==a && s1[i]==b) return i;
//   (n1[node1], s1[node1]) = (a, b);
//   return node1++;
// }
// 
// int getNode2(int a, int b){
//   rep(i,node2) if(x[i]==a && y[i]==b) return i;
//   (x[node2], y[node2]) = (a, b);
//   return node2++;
// }
// 
// {
//   int i, j, k;
//   rd(N,M,S@len(N));
//   getNode1(0, 0);
//   rep(n,node1){
//     rep(i,s1[n]) aa[i] = S[n1[n]][i];
//     rep(k,'a','z'+1){
//       aa[s1[n]] = k;
//       rep(i,N) if(arrcmp(s1[n]+1, S[i], s1[n]+1, aa) == 0) break;
//       if(i < N){
//         j = getNode1(i, s1[n]+1);
//         edge1[k-'a'][n][j]++;
//       }
//       rep(i,N) if(arrcmp(len[i], S[i], s1[n]+1, aa) == 0) break;
//       if(i < N) edge1[k-'a'][n][0]++;
//     }
//   }
// 
//   getNode2(0, 0);
//   rep(n,node2){
//     rep(k,26) rep(m1,node1) rep(m2,node1) if(edge1[k][x[n]][m1] && edge1[k][y[n]][m2]){
//       i = getNode2(m1, m2);
//       edge2[n][i] += edge1[k][x[n]][m1] * edge1[k][y[n]][m2];
//     }
//   }
// 
//   mt.changeSize(node2, node2);
//   rep(i,node2) rep(j,node2) mt[i][j] = edge2[i][j];
//   mt **= M;
//   wt(mt[0][0]);
// }