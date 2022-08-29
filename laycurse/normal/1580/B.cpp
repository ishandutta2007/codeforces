#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define MD (1000000007U)
struct modint{
  static unsigned md;
  unsigned val;
  modint(){
    val=0;
  }
  modint(int a){
    val = ord(a);
  }
  modint(unsigned a){
    val = ord(a);
  }
  modint(long long a){
    val = ord(a);
  }
  modint(unsigned long long a){
    val = ord(a);
  }
  void setmod(unsigned m){
    md = m;
  }
  unsigned ord(unsigned a){
    return a%md;
  }
  unsigned ord(int a){
    a %= (int)md;
    if(a < 0){
      a += md;
    }
    return a;
  }
  unsigned ord(unsigned long long a){
    return a%md;
  }
  unsigned ord(long long a){
    a %= (int)md;
    if(a < 0){
      a += md;
    }
    return a;
  }
  unsigned get(){
    return val;
  }
  inline modint &operator++(){
    val++;
    if(val >= md){
      val -= md;
    }
    return *this;
  }
  inline modint &operator--(){
    if(val == 0){
      val = md - 1;
    }
    else{
      --val;
    }
    return *this;
  }
  inline modint operator++(int a){
    modint res(*this);
    val++;
    if(val >= md){
      val -= md;
    }
    return res;
  }
  inline modint operator--(int a){
    modint res(*this);
    if(val == 0){
      val = md - 1;
    }
    else{
      --val;
    }
    return res;
  }
  modint &operator+=(modint a){
    val += a.val;
    if(val >= md){
      val -= md;
    }
    return *this;
  }
  modint &operator-=(modint a){
    if(val < a.val){
      val = val + md - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  modint &operator*=(modint a){
    val = ((unsigned long long)val*a.val)%md;
    return *this;
  }
  modint &operator/=(modint a){
    return *this *= a.inverse();
  }
  modint operator+(modint a){
    return modint(*this)+=a;
  }
  modint operator-(modint a){
    return modint(*this)-=a;
  }
  modint operator*(modint a){
    return modint(*this)*=a;
  }
  modint operator/(modint a){
    return modint(*this)/=a;
  }
  modint operator+(int a){
    return modint(*this)+=modint(a);
  }
  modint operator-(int a){
    return modint(*this)-=modint(a);
  }
  modint operator*(int a){
    return modint(*this)*=modint(a);
  }
  modint operator/(int a){
    return modint(*this)/=modint(a);
  }
  modint operator+(long long a){
    return modint(*this)+=modint(a);
  }
  modint operator-(long long a){
    return modint(*this)-=modint(a);
  }
  modint operator*(long long a){
    return modint(*this)*=modint(a);
  }
  modint operator/(long long a){
    return modint(*this)/=modint(a);
  }
  modint operator-(void){
    modint res;
    if(val){
      res.val=md-val;
    }
    else{
      res.val=0;
    }
    return res;
  }
  operator bool(void){
    return val!=0;
  }
  operator int(void){
    return get();
  }
  operator long long(void){
    return get();
  }
  modint inverse(){
    int a = val;
    int b = md;
    int u = 1;
    int v = 0;
    int t;
    modint res;
    while(b){
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if(u < 0){
      u += md;
    }
    res.val = u;
    return res;
  }
  modint pw(unsigned long long b){
    modint a(*this);
    modint res;
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
  bool operator==(int a){
    return ord(a)==val;
  }
  bool operator!=(int a){
    return ord(a)!=val;
  }
}
;
unsigned modint::md;
modint operator+(int a, modint b){
  return modint(a)+=b;
}
modint operator-(int a, modint b){
  return modint(a)-=b;
}
modint operator*(int a, modint b){
  return modint(a)*=b;
}
modint operator/(int a, modint b){
  return modint(a)/=b;
}
modint operator+(long long a, modint b){
  return modint(a)+=b;
}
modint operator-(long long a, modint b){
  return modint(a)-=b;
}
modint operator*(long long a, modint b){
  return modint(a)*=b;
}
modint operator/(long long a, modint b){
  return modint(a)/=b;
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
inline void wt_L(modint x){
  int i;
  i = (int)x;
  wt_L(i);
}
modint comb[101][101];
modint fac[101];
modint solve_cL_memo_val[102][102][102];
char solve_cL_memo_exist[102][102][102];
modint solve_cL_func(int N, int M, int K );
modint solve(int N,int M,int K){
  if(!solve_cL_memo_exist[N - (-1)][M - (-1)][K - (-1)]){
    solve_cL_memo_val[N - (-1)][M - (-1)][K - (-1)] = solve_cL_func(N,M,K);
    solve_cL_memo_exist[N - (-1)][M - (-1)][K - (-1)] = 1;
  }
  return solve_cL_memo_val[N - (-1)][M - (-1)][K - (-1)];
}
void solve_clear(int N,int M,int K){
  int Lj4PdHRW;
  int KL2GvlyY;
  int Q5VJL1cS;
  for(Lj4PdHRW=(0);Lj4PdHRW<(102);Lj4PdHRW++){
    for(KL2GvlyY=(0);KL2GvlyY<(102);KL2GvlyY++){
      for(Q5VJL1cS=(0);Q5VJL1cS<(102);Q5VJL1cS++){
        solve_cL_memo_exist[Lj4PdHRW][KL2GvlyY][Q5VJL1cS] = 0;
      }
    }
  }
}
modint solve_cL_func(int N, int M, int K ){
  int i;
  if(N==0 && K==0){
    return 1;
  }
  if(N==0){
    return 0;
  }
  if(M==1 && K==1){
    return fac[N];
  }
  if(M==1){
    return 0;
  }
  if(N < K){
    return 0;
  }
  if(K==0 && N < M){
    return fac[N];
  }
  if(N < M){
    return 0;
  }
  modint res = 0;
  modint tmp;
  for(i=(0);i<(N/2);i++){
    int k;
    tmp = 0;
    for(k=(0);k<(K+1);k++){
      tmp += solve(i,M-1,k) * solve(N-1-i,M-1,K-k);
    }
    res += tmp * comb[N-1][i] * 2;
  }
  if(N%2==1){
    int k;
    tmp = 0;
    for(k=(0);k<(K+1);k++){
      tmp += solve((N-1)/2,M-1,k) * solve((N-1)/2,M-1,K-k);
    }
    res += tmp * comb[N-1][i];
  }
  return res;
}
int main(){
  int i;
  {
    modint x;
    x.setmod(MD);
  }
  int N;
  rd(N);
  int M;
  rd(M);
  int K;
  rd(K);
  int P;
  rd(P);
  modint res;
  res.setmod(P);
  for(i=(0);i<(101);i++){
    comb[i][0] = 1;
  }
  for(i=(1);i<(101);i++){
    int j;
    for(j=(1);j<(101);j++){
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
    }
  }
  fac[0] = 1;
  for(i=(1);i<(101);i++){
    fac[i] = fac[i-1] * i;
  }
  res = solve(N,M,K);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// modint comb[101][101], fac[101];
// modint solve(int N, int M, int K : Memoize[-1:100, -1:100, -1:100]){
//   if(N==0 && K==0) return 1;
//   if(N==0) return 0;
//   if(M==1 && K==1) return fac[N];
//   if(M==1) return 0;
//   if(N < K) return 0;
//   if(K==0 && N < M) return fac[N];
//   if(N < M) return 0;
// 
//   modint res = 0, tmp;
//   rep(i,N/2){
//     tmp = 0;
//     rep(k,K+1) tmp += solve(i,M-1,k) * solve(N-1-i,M-1,K-k);
//     res += tmp * comb[N-1][i] * 2;
//   }
//   if(N%2==1){
//     tmp = 0;
//     rep(k,K+1) tmp += solve((N-1)/2,M-1,k) * solve((N-1)/2,M-1,K-k);
//     res += tmp * comb[N-1][i];
//   }
//   return res;
// }
// {
//   int @N, @M, @K, @P;
//   modint res;
//   res.setmod(P);
//   rep(i,101) comb[i][0] = 1;
//   rep(i,1,101) rep(j,1,101) comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
//   fac[0] = 1;
//   rep(i,1,101) fac[i] = fac[i-1] * i;
//   res = solve(N,M,K);
//   wt(res);
// }