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
inline void rd(long long &x){
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
long long segtree_rh_apply(long long f, long long a){
  return f;
}
long long segtree_rh_merge(long long a, long long b){
  return min_L(a, b);
}
long long segtree_rh_compose(long long f, long long g){
  return f;
}
long long val;
bool f(long long a){
  return a >= val;
}
int N;
long long S;
long long A[200000+1];
long long ss[200000+1];
segtree_rh<long long,long long> t;
int main(){
  int KL2GvlyY;
  wmem = memarr;
  int Q5VJL1cS = rd_int();
  for(KL2GvlyY=(0);KL2GvlyY<(Q5VJL1cS);KL2GvlyY++){
    int res = -1;
    int res1;
    int res2;
    int i;
    int j;
    rd(N);
    rd(S);
    {
      int RZTsC2BF;
      for(RZTsC2BF=(0);RZTsC2BF<(N);RZTsC2BF++){
        rd(A[RZTsC2BF]);
      }
    }
    for(i=(0);i<(N);i++){
      ss[i+1] = ss[i] + A[i];
    }
    t.walloc(N+1);
    t.setN(N+1);
    for(i=(0);i<(N+1);i++){
      t[i] = ss[i];
    }
    t.build();
    for(i=(0);i<(N);i++){
      val = ss[i] - S;
      j = t.max_right<f>(i);
      if(j > i+1 && j-i > res){
        auto hCmBdyQB = ((j-i));
        auto V9aVTaxx = (( i));
        auto APIVbQlN = (( j-2));
        res=hCmBdyQB;
        res1=V9aVTaxx;
        res2=APIVbQlN;
      }
    }
    if(res == -1){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    wt_L(res1+1);
    wt_L(' ');
    wt_L(res2+1);
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
  int H31bcJ8S = N;
  for(i=(1);i<(H31bcJ8S);i++){
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
// ll segtree_rh_apply(ll f, ll a){ return f; }
// ll segtree_rh_merge(ll a, ll b){ return min(a, b); }
// ll segtree_rh_compose(ll f, ll g){ return f; }
// 
// ll val;
// bool f(ll a){ return a >= val; }
// 
// int N; ll S, A[2d5+1], ss[];
// segtree_rh<ll,ll> t;
// {
//   REP(rd_int()){
//     int res = -1, res1, res2, i, j;
//     rd(N,S,A(N));
//     rep(i,N) ss[i+1] = ss[i] + A[i];
//     t.walloc(N+1);
//     t.setN(N+1);
//     rep(i,N+1) t[i] = ss[i];
//     t.build();
//     rep(i,N){
//       val = ss[i] - S;
//       j = t.max_right<f>(i);
//       if(j > i+1 && j-i > res) (res, res1, res2) = (j-i, i, j-2);
//     }
//     if(res == -1) wt(-1), continue;
//     wt(res1+1, res2+1);
//   }
// }