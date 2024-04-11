#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (998244353U)
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
inline void wt_L(Modint x){
  int i;
  i = (int)x;
  wt_L(i);
}
int Prime_L(int N, int res[], void *mem=wmem){
  int i;
  int a;
  int b;
  int sz = 1;
  const int r = 23000;
  bool *isprime;
  int *sf;
  int ss = 1;
  walloc1d(&isprime, r, &mem);
  walloc1d(&sf, r, &mem);
  isprime = (bool*)mem;
  sf = (int*)(isprime + r);
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
template<class T> int Factor_L(T N, T fac[]){
  T i;
  int sz = 0;
  if(N%2==0){
    fac[sz] = 2;
    N /= 2;
    while(N%2==0){
      N /= 2;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      N /= i;
      while(N%i==0){
        N /= i;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    sz++;
  }
  return sz;
}
int ps;
int p[1000];
long long D;
long long X;
long long Y;
int fs;
long long f[30];
int fn[30];
map<long long,Modint> dp;
Modint solve(vector<int> v){
  int i;
  long long x = 1;
  vector<int> s;
  Modint res = 0;
  for(i=(0);i<(v.size());i++){
    if(v[i]){
      s.push_back(v[i]);
    }
  }
  sort(s.rbegin(), s.rend());
  v = s;
  for(i=(0);i<(v.size());i++){
    int j;
    for(j=(0);j<(v[i]);j++){
      x *= p[i];
    }
  }
  if(dp.count(x)){
    return dp[x];
  }
  for(i=(0);i<(v.size());i++){
    v[i]--;
    res += solve(v);
    v[i]++;
  }
  return dp[x] = res;
}
int main(){
  int WYIGIcGE;
  wmem = memarr;
  Modint res;
  ps =Prime_L(1000, p);
  rd(D);
  fs =Factor_L(D, f);
  dp[1] = 1;
  int t_ynMSdg = rd_int();
  for(WYIGIcGE=(0);WYIGIcGE<(t_ynMSdg);WYIGIcGE++){
    int i;
    vector<int> fn(fs);
    vector<int> fm(fs);
    rd(X);
    rd(Y);
    for(i=(0);i<(fs);i++){
      while(X%f[i]==0){
        fn[i]++;
        X /= f[i];
      }
      while(Y%f[i]==0){
        fn[i]--;
        Y /= f[i];
      }
    }
    for(i=(0);i<(fs);i++){
      if(fn[i] < 0){
        {
          auto ZIeRIny5 = (0);
          auto iMWUTgY_ = ( -fn[i]);
          fn[i] = ZIeRIny5;
          fm[i] = iMWUTgY_;
        }
      }
    }
    res = solve(fn) * solve(fm);
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200408-1

// --- original code ---
// //no-unlocked
// #define MD 998244353
// 
// int ps, p[1000];
// 
// ll D, X, Y;
// int fs; ll f[30];
// int fn[30];
// 
// map<ll,Modint> dp;
// 
// Modint solve(vector<int> v){
//   ll x = 1;
//   vector<int> s;
//   Modint res = 0;
// 
//   rep(i,v.size()) if(v[i]) s.push_back(v[i]);
//   sort(s.rbegin(), s.rend());
//   v = s;
// 
//   rep(i,v.size()) rep(j,v[i]) x *= p[i];
//   if(dp.count(x)) return dp[x];
// 
//   rep(i,v.size()){
//     v[i]--;
//     res += solve(v);
//     v[i]++;
//   }
// 
//   return dp[x] = res;
// }
// 
// {
//   Modint res;
//   ps = Prime(1000, p);
//   rd(D);
//   fs = Factor(D, f);
//   dp[1] = 1;
//   REP(rd_int()){
//     vector<int> fn(fs);
//     vector<int> fm(fs);
//     rd(X,Y);
//     rep(i,fs){
//       while(X%f[i]==0) fn[i]++, X /= f[i];
//       while(Y%f[i]==0) fn[i]--, Y /= f[i];
//     }
//     rep(i,fs) if(fn[i] < 0) (fn[i], fm[i]) = (0, -fn[i]);
//     res = solve(fn) * solve(fm);
//     wt(res);
//   }
// }