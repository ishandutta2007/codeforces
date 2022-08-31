#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (998244353U)
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
template<class T> int Factor_L(T N, T fac[], int fs[]){
  T i;
  int sz = 0;
  if(N%2==0){
    fac[sz] = 2;
    fs[sz] = 1;
    N /= 2;
    while(N%2==0){
      N /= 2;
      fs[sz]++;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      fs[sz] = 1;
      N /= i;
      while(N%i==0){
        N /= i;
        fs[sz]++;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    fs[sz] = 1;
    sz++;
  }
  return sz;
}
template<class T> inline T pow2_L(T a){
  return a*a;
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
int F[100000+1];
int fs;
int f[30];
int fn[30];
int main(){
  int Lj4PdHRW, k;
  Modint res = 0;
  Modint tmp;
  Modint fc;
  Modint ps;
  Modint p2s;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int A;
    rd(A);
    int x;
    rd(x);
    F[A] += x;
  }
  for(k=(1);k<(100000+1);k++){
    int i;
    Modint pw;
    Modint pwi;
    long long tot = 0;
    fs =Factor_L(k, f, fn);
    int FmcKpFmN;
    int xr20shxY;
    if(fs==0){
      xr20shxY = 0;
    }
    else{
      xr20shxY = fn[0];
      for(FmcKpFmN=(1);FmcKpFmN<(fs);FmcKpFmN++){
        xr20shxY = max_L(xr20shxY, fn[FmcKpFmN]);
      }
    }
    if(xr20shxY>= 2){
      continue;
    }
    tot = 0;
    for(i=(k);i<(100000+1);i+=(k)){
      tot += F[i];
    }
    if(tot <= 1){
      continue;
    }
    ps = p2s = 0;
    for(i=(k);i<(100000+1);i+=(k)){
      ps += F[i] * Modint(i);
    }
    for(i=(k);i<(100000+1);i+=(k)){
      p2s += F[i] *(pow2_L(Modint(i)));
    }
    pw =(pow_L(Modint(2),(tot-2)));
    pwi = pw / 2;
    tmp = 0;
    for(i=(k);i<(100000+1);i+=(k)){
      fc = (ps - i) * pw;
      tmp += i * fc * F[i];
      fc = ((pow2_L((ps - i)))+ (p2s -(pow2_L(Modint(i))))) * pwi;
      tmp += fc * F[i];
    }
    if(fs%2==1){
      res -=tmp;
    }
    else{
      res +=tmp;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20201115-2

// --- original code ---
// //no-unlocked
// #define MD 998244353
// int F[1d5+1];
// int fs, f[30], fn[30];
// {
//   Modint res = 0, tmp, fc;
//   Modint ps, p2s;
// 
//   REP(rd_int()){
//     int @A, @x;
//     F[A] += x;
//   }
//   rep(k,1,1d5+1){
//     Modint pw, pwi;
//     ll tot = 0;
// 
//     fs = Factor(k, f, fn);
//     if(max(fn(fs)) >= 2) continue;
// 
//     tot = 0;
//     rep(i,k,1d5+1,k) tot += F[i];
//     if(tot <= 1) continue;
// 
//     ps = p2s = 0;
//     rep(i,k,1d5+1,k) ps += F[i] * Modint(i);
//     rep(i,k,1d5+1,k) p2s += F[i] * Modint(i) ** 2;
// 
//     pw = Modint(2) ** (tot-2);
//     pwi = pw / 2;
// 
//     tmp = 0;
//     rep(i,k,1d5+1,k){
//       fc = (ps - i) * pw;
//       tmp += i * fc * F[i];
//       fc = ((ps - i) ** 2 + (p2s - Modint(i)**2)) * pwi;
//       tmp += fc * F[i];
//     }
//     res if[fs%2==1, -=, +=] tmp;
//   }
//   wt(res);
// }