#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (1000000007U)
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int M;
int Q;
int A[2000];
int B[2000];
int C[2000];
long long dp[2000];
long long nx[2000];
long long mx[2000];
int main(){
  int FmcKpFmN, i;
  int t = 0;
  int mi;
  long long nt;
  Modint res = 0;
  rd(N);
  rd(M);
  rd(Q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
      rd(C[Lj4PdHRW]);
    }
  }
  for(i=(1);i<(N);i++){
    dp[i] = -4611686016279904256LL;
  }
  int xr20shxY = min_L(3000, Q);
  for(FmcKpFmN=(0);FmcKpFmN<(xr20shxY);FmcKpFmN++){
    t++;
    for(i=(0);i<(N);i++){
      nx[i] = -4611686016279904256LL;
    }
    for(i=(0);i<(M);i++){
      if(dp[A[i]] != -4611686016279904256LL){
        chmax(nx[B[i]], dp[A[i]] + C[i]);
      }
      if(dp[B[i]] != -4611686016279904256LL){
        chmax(nx[A[i]], dp[B[i]] + C[i]);
      }
    }
    for(i=(0);i<(N);i++){
      dp[i] = nx[i];
    }
    {
      int APIVbQlN;
      long long YREPHmFM;
      if(N==0){
        YREPHmFM = 0;
      }
      else{
        YREPHmFM = dp[0];
        for(APIVbQlN=(1);APIVbQlN<(N);APIVbQlN++){
          YREPHmFM = max_L(YREPHmFM, dp[APIVbQlN]);
        }
      }
      res +=YREPHmFM;
    }
  }
  for(i=(0);i<(M);i++){
    mx[i] =max_L(dp[A[i]], dp[B[i]])+ C[i];
  }
  while(t < Q){
    {
      int Q5rsz4fz;
      int GgkpftXM = 0;
      long long gEg5UqEA;
      long long qSsg05KM;
      int Hjfu7Vx7;
      for(Q5rsz4fz=(0);Q5rsz4fz<(((M)-1)+1);Q5rsz4fz++){
        qSsg05KM = mx[Q5rsz4fz];
        if(GgkpftXM==0 || gEg5UqEA<qSsg05KM){
          gEg5UqEA = qSsg05KM;
          GgkpftXM = 1;
          Hjfu7Vx7 = Q5rsz4fz;
        }
      }
      mi =Hjfu7Vx7;
    }
    nt = Q - t;
    for(i=(0);i<(M);i++){
      if(mi != i && C[i] > C[mi]){
        chmin(nt, (mx[mi] - mx[i]) / (C[i] - C[mi]));
      }
    }
    if(nt == 0){
      nt = 1;
    }
    res += Modint(mx[mi] + mx[mi] + (nt - 1) * C[mi]) * nt / 2;
    for(i=(0);i<(M);i++){
      mx[i] += C[i] * nt;
    }
    t += nt;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, Q, A[2000], B[2000], C[2000];
// ll dp[2000], nx[2000], mx[2000];
// {
//   int t = 0, mi;
//   ll nt;
//   Modint res = 0;
//   rd(N,M,Q,(A--,B--,C)(M));
// 
//   rep(i,1,N) dp[i] = -ll_inf;
//   REP(min(3000,Q)){
//     t++;
//     rep(i,N) nx[i] = -ll_inf;
//     rep(i,M){
//       if(dp[A[i]] != -ll_inf) nx[B[i]] >?= dp[A[i]] + C[i];
//       if(dp[B[i]] != -ll_inf) nx[A[i]] >?= dp[B[i]] + C[i];
//     }
//     rep(i,N) dp[i] = nx[i];
//     res += max(dp(N));
//   }
// 
//   rep(i,M) mx[i] = max(dp[A[i]], dp[B[i]]) + C[i];
//   while(t < Q){
//     mi = argmax(mx(M));
//     nt = Q - t;
//     rep(i,M) if(mi != i && C[i] > C[mi]){
//       nt <?= (mx[mi] - mx[i]) / (C[i] - C[mi]);
//     }
//     if(nt == 0) nt = 1;
// 
//     res += Modint(mx[mi] + mx[mi] + (nt - 1) * C[mi]) * nt / 2;
//     rep(i,M) mx[i] += C[i] * nt;
//     t += nt;
//   }
// 
//   wt(res);
// }