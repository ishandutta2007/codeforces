#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define MD (1000000007U)
void*wmem;
char memarr[96000000];
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
template<class T> struct fenwick{
  int size;
  int memory;
  T*data;
  void malloc(int mem);
  void malloc(int mem, int fg);
  void walloc(int mem, void **workMemory = &wmem);
  void walloc(int mem, int fg, void **workMemory = &wmem);
  void free(void);
  void init(int N);
  void add(int k, T val);
  T get(int k);
  T range(int a, int b);
  int kth(T k);
}
;
struct Permutation{
  int n;
  int mem;
  int*dat;
  Permutation(){
    n = mem = 0;
  }
  Permutation(const int nn){
    n = mem = nn;
    if(mem > 0){
      dat = new int[mem];
    }
  }
  Permutation(const Permutation &a){
    int i;
    mem = n = a.n;
    dat = new int[mem];
    for(i=(0);i<(mem);i++){
      dat[i] = a.dat[i];
    }
  }
  ~Permutation(){
    if(mem){
      delete [] dat;
    }
  }
  void changeSize(const int nn){
    n = nn;
    if(mem < n){
      if(mem){
        delete [] dat;
      }
      mem = n;
      dat = new int[mem];
    }
  }
  Permutation& operator=(const Permutation &a){
    int i;
    changeSize(a.n);
    n = a.n;
    for(i=(0);i<(n);i++){
      dat[i] = a.dat[i];
    }
    return *this;
  }
  Permutation& operator=(const int a){
    int i;
    for(i=(0);i<(n);i++){
      dat[i] = i;
    }
    return *this;
  }
  Permutation& operator*=(const Permutation &a){
    int i;
    int*m;
    void*mv = wmem;
    if(n==0 || n!=a.n){
      changeSize(0);
      return *this;
    }
    walloc1d(&m, n, &mv);
    for(i=(0);i<(n);i++){
      m[i] = dat[a.dat[i]];
    }
    for(i=(0);i<(n);i++){
      dat[i] = m[i];
    }
    return *this;
  }
  Permutation operator*(const Permutation &a){
    return Permutation(*this) *= a;
  }
  bool operator==(const Permutation &a){
    int i;
    if(n != a.n){
      return false;
    }
    for(i=(0);i<(n);i++){
      if(dat[i] != a.dat[i]){
        return false;
      }
    }
    return true;
  }
  template<class T> void apply(T A[]){
    int i;
    T*B;
    void*mv = wmem;
    walloc1d(&B, n, &mv);
    for(i=(0);i<(n);i++){
      B[dat[i]] = A[i];
    }
    for(i=(0);i<(n);i++){
      A[i] = B[i];
    }
  }
  template<class T> void apply(T A[], T B[]){
    int i;
    for(i=(0);i<(n);i++){
      B[dat[i]] = A[i];
    }
  }
  int cycle_len(int res[] = NULL){
    int i;
    int j;
    int k;
    int sz = 0;
    int*vis;
    void*mv = wmem;
    if(res==NULL){
      walloc1d(&res, n, &mv);
    }
    walloc1d(&vis, n, &mv);
    for(i=(0);i<(n);i++){
      vis[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(!vis[i]){
        k = 0;
        j = i;
        while(vis[j]==0){
          vis[j] = 1;
          j = dat[j];
          k++;
        }
        res[sz++] = k;
      }
    }
    return sz;
  }
  void cycle_len_EachElement(int res[]){
    int i;
    int j;
    int k;
    int sz = 0;
    int*vis;
    void*mv = wmem;
    walloc1d(&vis, n, &mv);
    for(i=(0);i<(n);i++){
      vis[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(!vis[i]){
        k = 0;
        j = i;
        while(vis[j]==0){
          vis[j] = 1;
          j = dat[j];
          k++;
        }
        j = i;
        while(vis[j]==1){
          res[j] = k;
          vis[j] = 2;
          j = dat[j];
        }
      }
    }
  }
  template<class T> inline T getIndex(void *mem = wmem){
    int i;
    fenwick<int> t;
    T res;
    T*fac;
    walloc1d(&fac,n,&mem);
    fac[0] = 1;
    for(i=(1);i<(n);i++){
      fac[i] = i * fac[i-1];
    }
    t.walloc(n,&mem);
    t.init(n);
    for(i=(0);i<(n);i++){
      t.add(i,1);
    }
    res = 0;
    for(i=(0);i<(n);i++){
      t.add(dat[i], -1);
      res += fac[n-1-i] * t.get(dat[i]-1);
    }
    return res;
  }
  inline int& operator[](const int a){
    return dat[a];
  }
}
;
template<class S> inline Permutation pow_L(Permutation a, S b){
  Permutation res;
  res.changeSize(a.n);
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
int N;
int A[400000];
int B[400000];
int ind[400000];
Permutation p;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    Modint res;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
        rd(B[xr20shxY]);B[xr20shxY] += (-1);
      }
    }
    for(i=(0);i<(N);i++){
      ind[A[i]] = i;
    }
    p.changeSize(N);
    for(i=(0);i<(N);i++){
      p[i] = B[ind[i]];
    }
    res =(pow_L(Modint(2),p.cycle_len()));
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
template<class T> void fenwick<T>::malloc(int mem){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
}
template<class T> void fenwick<T>::malloc(int mem, int fg){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::walloc(int mem, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
}
template<class T> void fenwick<T>::walloc(int mem, int fg, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::free(void){
  memory = 0;
  free(data);
}
template<class T> void fenwick<T>::init(int N){
  size = N;
  memset(data,0,sizeof(T)*N);
}
template<class T> void fenwick<T>::add(int k, T val){
  while(k < size){
    data[k] += val;
    k |= k+1;
  }
}
template<class T> T fenwick<T>::get(int k){
  T res = 0;
  while(k>=0){
    res += data[k];
    k = (k&(k+1))-1;
  }
  return res;
}
template<class T> T fenwick<T>::range(int a, int b){
  if(a < 0){
    a = 0;
  }
  if(b >= size){
    b = size - 1;
  }
  if(b < a){
    return 0;
  }
  return get(b) - get(a-1);
}
template<class T> int fenwick<T>::kth(T k){
  int i=0;
  int j=size;
  int c;
  T v;
  while(i<j){
    c = (i+j)/2;
    v = get(c);
    if(v <= k){
      i=c+1;
    }
    else{
      j=c;
    }
  }
  return i==size?-1:i;
}
// cLay version 20210613-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[4d5], B[4d5], ind[4d5];
// Permutation p;
// {
//   REP(rd_int()){
//     Modint res;
//     rd(N,(A--)(N),(B--)(N));
//     rep(i,N) ind[A[i]] = i;
//     p.changeSize(N);
//     rep(i,N) p[i] = B[ind[i]];
//     res = Modint(2) ** p.cycle_len();
//     wt(res);
//   }
// }