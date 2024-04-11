#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
int Prime_L(int N, int res[], void *mem=wmem){
  int i;
  int a;
  int b;
  int sz = 1;
  const int r = 23000;
  bool*isprime;
  int*sf;
  int ss = 1;
  walloc1d(&isprime, r, &mem);
  walloc1d(&sf, r, &mem);
  N /= 2;
  res[0] = 2;
  b =min_L(r, N);
  for(i=(1);i<(b);i++){
    isprime[i] = 1;
  }
  for(i=(1);i<(b);i++){
    if(isprime[i]){
      res[sz++] = 2*i+1;
      sf[ss] = 2*i*(i+1);
      if(sf[ss] < N){
        while(sf[ss] < r){
          isprime[sf[ss]] = 0;
          sf[ss] += res[ss];
        }
        ss++;
      }
    }
  }
  for(a=r; a<N; a+=r){
    b =min_L(a + r, N);
    isprime -= r;
    for(i=(a);i<(b);i++){
      isprime[i] = 1;
    }
    for(i=(1);i<(ss);i++){
      while(sf[i] < b){
        isprime[sf[i]] = 0;
        sf[i] += res[i];
      }
    }
    for(i=(a);i<(b);i++){
      if(isprime[i]){
        res[sz++] = 2*i+1;
      }
    }
  }
  return sz;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
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
int segtree_rh_apply(int f, int a){
  return f;
}
int segtree_rh_merge(int a, int b){
  return max_L(a, b);
}
int segtree_rh_compose(int f, int g){
  return f;
}
int f_st;
bool f(int a){
  return a < f_st;
}
int N;
int K;
int A[200000];
int ps;
int p[10000];
int sz;
int h[200000];
int dp[21][200000+1];
int arr[22];
segtree_rh<int,int> t;
int main(){
  int KL2GvlyY;
  wmem = memarr;
  int i;
  int j;
  int k;
  int res;
  ps =Prime_L(10000, p);
  t.walloc(200000+1);
  int Q5VJL1cS = rd_int();
  for(KL2GvlyY=(0);KL2GvlyY<(Q5VJL1cS);KL2GvlyY++){
    rd(N);
    rd(K);
    {
      int RZTsC2BF;
      for(RZTsC2BF=(0);RZTsC2BF<(N);RZTsC2BF++){
        rd(A[RZTsC2BF]);
      }
    }
    for(i=(0);i<(ps);i++){
      if(p[i]*p[i] <= 10000000){
        k = p[i] * p[i];
        for(j=(0);j<(N);j++){
          if(A[j]%k==0){
            A[j] /= k;
          }
        }
      }
    }
    sz =coordcomp_L(N, A);
    for(i=(0);i<(sz);i++){
      h[i] = -1;
    }
    t.setN(N+1);
    for(i=(0);i<(N);i++){
      t[i] = h[A[i]];
      h[A[i]] = i;
    }
    t[N] = N;
    t.build();
    for(i=(0);i<(K+1);i++){
      for(j=(0);j<(N+1);j++){
        dp[i][j] = 1073709056;
      }
    }
    dp[0][0] = 0;
    for(j=(0);j<(N+1);j++){
      f_st = j;
      arr[0] = j;
      for(i=(0);i<(K+1);i++){
        arr[i+1] = t.max_right<f>(min_L(arr[i]+1, N));
      }
      for(i=(0);i<(K+1);i++){
        if(dp[i][j] < 1073709056){
          for(k=(i);k<(K+1);k++){
            chmin(dp[i][arr[k-i+1]], dp[i][j] + 1);
          }
        }
      }
    }
    int qSsg05KM;
    remove_reference<decltype(dp[qSsg05KM][N])>::type Hjfu7Vx7;
    int zT28qSmp = 0;
    if((0) > ((K+1)-1)){
      Hjfu7Vx7 = numeric_limits<remove_reference<decltype(dp[qSsg05KM][N])>::type>::max();
    }
    else{
      for(qSsg05KM = 0; qSsg05KM <= (K+1)-1; qSsg05KM++){
        if(zT28qSmp == 0){
          Hjfu7Vx7 = dp[qSsg05KM][N];
          zT28qSmp = 1;
          continue;
        }
        const auto X9Iss0pP = dp[qSsg05KM][N];
        if(Hjfu7Vx7 > X9Iss0pP){
          Hjfu7Vx7 = X9Iss0pP;
        }
      }
    }
    res =Hjfu7Vx7;
    wt_L(res);
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
  int memzHCbB = N;
  for(i=(1);i<(memzHCbB);i++){
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
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int segtree_rh_apply(int f, int a){ return f; }
// int segtree_rh_merge(int a, int b){ return max(a, b); }
// int segtree_rh_compose(int f, int g){ return f; }
// 
// int f_st;
// bool f(int a){
//   return a < f_st;
// }
// 
// int N, K, A[2d5];
// int ps, p[1d4];
// int sz, h[2d5];
// int dp[21][2d5+1], arr[22];
// segtree_rh<int,int> t;
// {
//   int i, j, k, res;
//   ps = Prime(1d4, p);
//   t.walloc(2d5+1);
//   REP(rd_int()){
//     rd(N,K,A(N));
//     rep(i,ps) if(p[i]*p[i] <= 1d7){
//       k = p[i] * p[i];
//       rep(j,N) if(A[j]%k==0) A[j] /= k;
//     }
//     sz = coordcomp(N, A);
//     rep(i,sz) h[i] = -1;
//     t.setN(N+1);
//     rep(i,N){
//       t[i] = h[A[i]];
//       h[A[i]] = i;
//     }
//     t[N] = N;
//     t.build();
// 
//     rep(i,K+1) rep(j,N+1) dp[i][j] = int_inf;
//     dp[0][0] = 0;
//     rep(j,N+1){
//       f_st = j;
//       arr[0] = j;
//       rep(i,K+1) arr[i+1] = t.max_right<f>(min(arr[i]+1,N));
//       rep(i,K+1) if(dp[i][j] < int_inf) rep(k,i,K+1) dp[i][arr[k-i+1]] <?= dp[i][j] + 1;
//     }
// 
//     res = min[i,0,K+1](dp[i][N]);
//     wt(res);
//   }
// }