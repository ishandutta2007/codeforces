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
template<class SVAL, class SFUN> struct segtree_rh{
  int N;
  int logN;
  int trueN;
  SVAL*val;
  SFUN*fun;
  char*dofun;
  void malloc(int maxN, int once = 0);
  void walloc(int maxN, int once = 0, void **mem = &wmem);
  void free(void);
  SVAL& operator[](int i);
  void setN(int n, int zerofill = 1, int dobuild = 1);
  void build(void);
  inline void push_one(int a);
  inline void push(int a);
  inline void build(int a);
  inline void change(int a, int b, SFUN f);
  inline SVAL get(int a, int b);
  template<bool (*f)(SVAL)> int max_right(int a, int mx);
  template<bool (*f)(SVAL)> int max_right(int a);
  template<bool (*f)(SVAL)> int min_left(int b, int mn);
  template<bool (*f)(SVAL)> int min_left(int b);
}
;
struct sval{
  int len;
  long long sm;
  long long mn;
  long long mx;
}
;
sval segtree_rh_merge(sval a, sval b){
  sval res;
  res.len = a.len + b.len;
  if(a.len % 2 == 0){
    res.sm = a.sm + b.sm;
    res.mx =max_L(a.mx, b.mx + a.sm);
    res.mn =min_L(a.mn, b.mn + a.sm);
  }
  else{
    res.sm = a.sm - b.sm;
    res.mx =max_L(a.mx, -b.mn + a.sm);
    res.mn =min_L(a.mn, -b.mx + a.sm);
  }
  return res;
}
sval segtree_rh_apply(int tmp, sval a){
  return a;
}
int segtree_rh_compose(int tmp, int hoge){
  return 0;
}
bool f(sval a){
  return a.mn > 0 && a.mx < 0;
}
int N;
int A[300000];
segtree_rh<sval,int> t;
long long dp[300000+1];
int main(){
  int cTE1_r3A;
  wmem = memarr;
  int RZTsC2BF = rd_int();
  for(cTE1_r3A=(0);cTE1_r3A<(RZTsC2BF);cTE1_r3A++){
    int i;
    int j;
    sval tmp;
    rd(N);
    {
      int WYIGIcGE;
      for(WYIGIcGE=(0);WYIGIcGE<(N);WYIGIcGE++){
        rd(A[WYIGIcGE]);
      }
    }
    t.walloc(N);
    t.setN(N);
    for(i=(0);i<(N);i++){
      t[i] = {1, A[i], A[i], -4611686016279904256LL};
    }
    t.build();
    for(i=(0);i<(N+1);i++){
      dp[i] = 0;
    }
    for(i=(N)-1;i>=(0);i--){
      j = t.max_right<f>(i) + 1;
      if(j > N){
        continue;
      }
      tmp = t.get(i,j);
      if(tmp.sm == 0){
        dp[i] = 1 + dp[j];
      }
    }
    int YREPHmFM;
    cLtraits_try_make_signed<remove_reference<decltype((*((long long*)NULL)))>::type>::type jZyWAPpY;
    if(N==0){
      jZyWAPpY = 0;
    }
    else{
      jZyWAPpY = dp[0];
      for(YREPHmFM=(1);YREPHmFM<(N);YREPHmFM++){
        jZyWAPpY += dp[YREPHmFM];
      }
    }
    wt_L(jZyWAPpY);
    wt_L('\n');
  }
  return 0;
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::malloc(int maxN, int once /*= 0*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  val = new SVAL[2*i];
  fun = new SFUN[i];
  dofun = new char[i];
  if(once){
    setN(maxN);
  }
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::walloc(int maxN, int once /*= 0*/, void **mem /*= &wmem*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  walloc1d(&val, 2*i, mem);
  walloc1d(&fun, i, mem);
  walloc1d(&dofun, i, mem);
  if(once){
    setN(maxN);
  }
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::free(void){
  delete [] val;
  delete [] fun;
}
template<class SVAL, class SFUN> SVAL& segtree_rh<SVAL, SFUN>::operator[](int i){
  return val[N+i];
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::setN(int n, int zerofill /*= 1*/, int dobuild /*= 1*/){
  int i;
  for(i=1,logN=0;i<n;i*=2,logN++){
    ;
  }
  trueN = n;
  N = i;
  if(dobuild){
    build();
  }
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::build(void){
  int i;
  for(i=N-1;i;i--){
    val[i] = segtree_rh_merge(val[2*i], val[2*i+1]);
  }
  int jG1yfsum = N;
  for(i=(1);i<(jG1yfsum);i++){
    dofun[i] = 0;
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::push_one(int a){
  if(dofun[a]){
    if(2*a < N){
      if(dofun[2*a]){
        fun[2*a] = segtree_rh_compose(fun[a], fun[2*a]);
      }
      else{
        fun[2*a] = fun[a];
        dofun[2*a] = 1;
      }
    }
    val[2*a] = segtree_rh_apply(fun[a], val[2*a]);
    if(2*a+1 < N){
      if(dofun[2*a+1]){
        fun[2*a+1] = segtree_rh_compose(fun[a], fun[2*a+1]);
      }
      else{
        fun[2*a+1] = fun[a];
        dofun[2*a+1] = 1;
      }
    }
    val[2*a+1] = segtree_rh_apply(fun[a], val[2*a+1]);
    dofun[a] = 0;
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::push(int a){
  int i;
  for(i=logN;i;i--){
    push_one(a>>i);
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::build(int a){
  while(a > 1){
    a /= 2;
    val[a] = segtree_rh_merge(val[2*a], val[2*a+1]);
    if(dofun[a]){
      val[a] = segtree_rh_apply(fun[a], val[a]);
    }
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::change(int a, int b, SFUN f){
  int aa;
  int bb;
  if(a >= b){
    return;
  }
  aa = (a += N);
  bb = (b += N);
  push(a);
  push(b-1);
  if(a%2){
    val[a] = segtree_rh_apply(f, val[a]);
    a++;
  }
  if(b%2){
    b--;
    val[b] = segtree_rh_apply(f, val[b]);
  }
  a /= 2;
  b /= 2;
  while(a < b){
    if(a%2){
      val[a] = segtree_rh_apply(f, val[a]);
      if(dofun[a]){
        fun[a] = segtree_rh_compose(f, fun[a]);
      }
      else{
        fun[a] = f;
        dofun[a] = 1;
      }
      a++;
    }
    if(b%2){
      b--;
      val[b] = segtree_rh_apply(f, val[b]);
      if(dofun[b]){
        fun[b] = segtree_rh_compose(f, fun[b]);
      }
      else{
        fun[b] = f;
        dofun[b] = 1;
      }
    }
    a /= 2;
    b /= 2;
  }
  build(aa);
  build(bb-1);
}
template<class SVAL, class SFUN> inline SVAL segtree_rh<SVAL, SFUN>::get(int a, int b){
  SVAL res;
  SVAL tmp;
  int fga = 0;
  int fgb = 0;
  a += N;
  b += N;
  push(a);
  push(b-1);
  while(a < b){
    if(a%2){
      if(fga){
        res = segtree_rh_merge(res, val[a]);
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
        tmp = segtree_rh_merge(val[b], tmp);
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
    return segtree_rh_merge(res, tmp);
  }
  return res;
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::max_right(int a, int mx){
  int fg = 0;
  int ta = a;
  int sz = 1;
  SVAL cur;
  SVAL tmp;
  if(a>=mx){
    return mx;
  }
  a += N;
  push(a);
  for(;;){
    while(a%2==0){
      a /= 2;
      sz *= 2;
    }
    if(ta + sz <= mx){
      if(fg==0){
        tmp = val[a];
      }
      else{
        tmp = segtree_rh_merge(cur, val[a]);
      }
    }
    if(ta + sz > mx || !f(tmp)){
      while(a < N){
        push_one(a);
        a *= 2;
        sz /= 2;
        if(ta + sz <= mx){
          if(fg==0){
            tmp = val[a];
          }
          else{
            tmp = segtree_rh_merge(cur, val[a]);
          }
        }
        if(ta + sz <= mx && f(tmp)){
          fg = 1;
          cur = tmp;
          a++;
          ta += sz;
        }
      }
      return a - N;
    }
    fg = 1;
    cur = tmp;
    if((a & (a+1)) == 0){
      break;
    }
    a++;
    ta += sz;
  }
  return mx;
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::max_right(int a){
  return max_right<f>(a, trueN);
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::min_left(int b, int mn){
  int fg = 0;
  int tb = b;
  int sz = 1;
  SVAL cur;
  SVAL tmp;
  if(b <= mn){
    return mn;
  }
  b += N;
  push(b-1);
  for(;;){
    while(b%2==0){
      b /= 2;
      sz *= 2;
    }
    if(tb - sz >= mn){
      if(fg==0){
        tmp = val[b-1];
      }
      else{
        tmp = segtree_rh_merge(val[b-1], cur);
      }
    }
    if(tb - sz < mn || !f(tmp)){
      while(b-1 < N){
        push_one(b-1);
        b *= 2;
        sz /= 2;
        if(tb - sz >= mn){
          if(fg==0){
            tmp = val[b-1];
          }
          else{
            tmp = segtree_rh_merge(val[b-1], cur);
          }
        }
        if(tb - sz >= mn && f(tmp)){
          fg = 1;
          cur = tmp;
          b--;
          tb -= sz;
        }
      }
      return b - N;
    }
    fg = 1;
    cur = tmp;
    b--;
    tb -= sz;
    if(tb <= mn){
      break;
    }
  }
  return mn;
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::min_left(int b){
  return min_left<f>(b, 0);
}
// cLay version 20211024-1 [beta]

// --- original code ---
// //no-unlocked
// struct sval {
//   int len;
//   ll sm, mn, mx;
// };
// 
// sval segtree_rh_merge(sval a, sval b){
//   sval res;
//   res.len = a.len + b.len;
//   if(a.len % 2 == 0){
//     res.sm = a.sm + b.sm;
//     res.mx = max(a.mx, b.mx + a.sm);
//     res.mn = min(a.mn, b.mn + a.sm);
//   } else {
//     res.sm = a.sm - b.sm;
//     res.mx = max(a.mx, -b.mn + a.sm);
//     res.mn = min(a.mn, -b.mx + a.sm);
//   }
//   return res;
// }
// 
// sval segtree_rh_apply(int tmp, sval a){ return a; }
// int segtree_rh_compose(int tmp, int hoge){ return 0; }
// 
// bool f(sval a){
//   return a.mn > 0 && a.mx < 0;
// }
// 
// int N, A[3d5];
// segtree_rh<sval,int> t;
// ll dp[3d5+1];
// {
//   REP(rd_int()){
//     int i, j;
//     sval tmp;
//     rd(N,A(N));
//     t.walloc(N);
//     t.setN(N);
//     rep(i,N) t[i] = {1, A[i], A[i], -ll_inf};
//     t.build();
// 
//     rep(i,N+1) dp[i] = 0;
//     rrep(i,N){
//       j = t.max_right<f>(i) + 1;
//       if(j > N) continue;
//       tmp = t.get(i,j);
//       if(tmp.sm == 0) dp[i] = 1 + dp[j];
//     }
//     wt(sum(dp(N)));
//   }
// }