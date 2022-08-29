#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (998244353U)
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
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
template<class T> struct segtree_pg{
  int N;
  int logN;
  T *val;
  void malloc(int maxN, int once = 0);
  void walloc(int maxN, int once = 0, void **mem = &wmem);
  void free(void);
  T& operator[](int i);
  void setN(int n, int zerofill = 1, int dobuild = 1);
  void build(void);
  inline void build(int a);
  inline void change(int a, T v);
  inline T get(int a, int b);
}
;
int N;
int M;
int X;
int D;
char S[500000+2];
int cnt[20];
struct hoge{
  int lf;
  int rg;
  Modint c;
  Modint cl;
  Modint cr;
  Modint clr;
}
;
hoge gethoge(int k){
  hoge htmp;
  htmp.lf = htmp.rg = k;
  htmp.cl = htmp.cr = 1;
  htmp.clr = 0;
  htmp.c = cnt[k];
  return htmp;
}
segtree_pg_func(hoge &res, hoge a, hoge b){
  res.lf = a.lf;
  res.rg = b.rg;
  res.c = a.c * b.c;
  res.cl = a.cl * b.c;
  res.cr = a.c * b.cr;
  res.clr = a.cl * b.cr;
  if(a.rg==1){
    int v = a.rg * 10 + b.lf;
    res.c += a.cr * b.cl * cnt[v];
    res.cl += a.clr * b.cl * cnt[v];
    res.cr += a.cr * b.clr * cnt[v];
    res.clr += a.clr * b.clr * cnt[v];
  }
}

segtree_pg<hoge> t;
int main(){
  int WYIGIcGE, i;
  wmem = memarr;
  int len;
  hoge htmp;
  rd(N);
  rd(M);
  rd(S);
  for(i=(0);i<(10);i++){
    int j;
    for(j=(0);j<(10);j++){
      cnt[i+j]++;
    }
  }
  t.malloc(N);
  t.setN(N);
  htmp.lf = htmp.rg = htmp.c = htmp.cl = htmp.cr = htmp.clr = 0;
  for(i=(0);i<(t.N);i++){
    t[i] = htmp;
  }
  for(i=(0);i<(N);i++){
    t[i] = gethoge(S[i]-'0');
  }
  t.build();
  for(WYIGIcGE=(0);WYIGIcGE<(M);WYIGIcGE++){
    rd(X);X += (-1);
    rd(D);
    t.change(X,gethoge(D));
    htmp = t.get(0, N);
    wt_L(htmp.c);
    wt_L('\n');
  }
  return 0;
}
template<class T> void segtree_pg<T>::malloc(int maxN, int once /*= 0*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  val = new T[2*i];
  if(once){
    setN(maxN);
  }
}
template<class T> void segtree_pg<T>::walloc(int maxN, int once /*= 0*/, void **mem /*= &wmem*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  walloc1d(&val, 2*i, mem);
  if(once){
    setN(maxN);
  }
}
template<class T> void segtree_pg<T>::free(void){
  delete [] val;
}
template<class T> T& segtree_pg<T>::operator[](int i){
  return val[N+i];
}
template<class T> void segtree_pg<T>::setN(int n, int zerofill /*= 1*/, int dobuild /*= 1*/){
  int i;
  for(i=1,logN=0;i<n;i*=2,logN++){
    ;
  }
  N = i;
  if(dobuild){
    build();
  }
}
template<class T> void segtree_pg<T>::build(void){
  for(int i=N-1;i;i--){
    segtree_pg_func(val[i], val[2*i], val[2*i+1]);
  }
}
template<class T> inline void segtree_pg<T>::build(int a){
  while(a > 1){
    a /= 2;
    segtree_pg_func(val[a], val[2*a], val[2*a+1]);
  }
}
template<class T> inline void segtree_pg<T>::change(int a, T v){
  val[a+N] = v;
  build(a+N);
}
template<class T> inline T segtree_pg<T>::get(int a, int b){
  T res;
  T tmp;
  int fga = 0;
  int fgb = 0;
  a += N;
  b += N;
  while(a < b){
    if(a%2){
      if(fga){
        segtree_pg_func(res, res, val[a]);
      }
      else{
        res = val[a];
        fga = 1;
      }
      a++;
    }
    if(b%2){
      b--;
      if(fgb){
        segtree_pg_func(tmp, val[b], tmp);
      }
      else{
        tmp = val[b];
        fgb = 1;
      }
    }
    a /= 2;
    b /= 2;
  }
  if(fga==1 && fgb==0){
    return res;
  }
  if(fga==0 && fgb==1){
    return tmp;
  }
  if(fga==1 && fgb==1){
    segtree_pg_func(res, res, tmp);
    return res;
  }
  return res;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// #define MD 998244353
// int N, M, X, D;
// char S[5d5+2];
// int cnt[20];
// 
// struct hoge{
//   int lf, rg;
//   Modint c, cl, cr, clr;
// };
// 
// hoge gethoge(int k){
//   hoge htmp;
//   htmp.lf = htmp.rg = k;
//   htmp.cl = htmp.cr = 1;
//   htmp.clr = 0;
//   htmp.c = cnt[k];
//   return htmp;
// }
// 
// segtree_pg_func(hoge &res, hoge a, hoge b){
//   res.lf = a.lf;
//   res.rg = b.rg;
//   res.c = a.c * b.c;
//   res.cl = a.cl * b.c;
//   res.cr = a.c * b.cr;
//   res.clr = a.cl * b.cr;
//   if(a.rg==1){
//     int v = a.rg * 10 + b.lf;
//     res.c += a.cr * b.cl * cnt[v];
//     res.cl += a.clr * b.cl * cnt[v];
//     res.cr += a.cr * b.clr * cnt[v];
//     res.clr += a.clr * b.clr * cnt[v];
//   }
// }
// 
// segtree_pg<hoge> t;
// 
// {
//   int len;
//   hoge htmp;
//   rd(N,M,S);
// 
//   rep(i,10) rep(j,10) cnt[i+j]++;
// 
//   t.malloc(N);
//   t.setN(N);
// 
//   htmp.lf = htmp.rg = htmp.c = htmp.cl = htmp.cr = htmp.clr = 0;
//   rep(i,t.N) t[i] = htmp;
//   rep(i,N) t[i] = gethoge(S[i]-'0');
//   t.build();
// 
//   rep(M){
//     rd(X--,D);
//     t.change(X,gethoge(D));
//     htmp = t.get(0, N);
//     wt(htmp.c);
//   }
// }