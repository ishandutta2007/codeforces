#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (1000000007U)
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
int N;
int M;
long long A[5000000+1];
int T[5000000+1];
long long P[200000+2];
long long K[200000+2];
long long B[200000+2];
long long W[200000+2];
long long resarr[5000000];
long long sm[2];
long long s;
long long tmp;
long long seed;
long long base;
long long rnd(){
  long long res = seed;
  seed = (seed * base + 233) % 1000000007;
  return res;
}
int main(){
  int hCmBdyQB, i;
  Modint res = 1;
  rd(N);
  rd(M);
  for(i=(1);i<(M+1);i++){
    rd(P[i]);
    rd(K[i]);
    rd(B[i]);
    rd(W[i]);
  }
  for(i=(1);i<(M+1);i++){
    int j;
    seed = B[i];
    base = W[i];
    for(j=(P[i-1]+1);j<(P[i]+1);j++){
      T[j-1] = (rnd()%2);
      A[j-1] = (rnd()%K[i]) + 1;
    }
  }
  if(T[0] != 0){
    for(i=(0);i<(N);i++){
      T[i] = 1 - T[i];
    }
  }
  for(i=(0);i<(N);i++){
    sm[T[i]] += A[i];
  }
  if(sm[0] <= sm[1]){
    for(i=(0);i<(N);i++){
      T[i] = 1 - T[i];
    }
    swap(sm[0], sm[1]);
  }
  else{
    resarr[0]++;
    A[0]--;
  }
  for(i=(0);i<(N);i++){
    if(T[i]==1){
      resarr[i] = A[i];
    }
  }
  for(hCmBdyQB=(0);hCmBdyQB<(2);hCmBdyQB++){
    for(i=(0);i<(N);i++){
      if(T[i] == 1){
        s += A[i];
        A[i] = 0;
        continue;
      }
      tmp =min_L(A[i], s);
      A[i] -= tmp;
      s -= tmp;
      resarr[i] += tmp;
    }
  }
  for(i=(0);i<(N);i++){
    res *= (resarr[i] ^ ((long long)(i+1)*(i+1))) + 1;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int N, M;
// ll A[5d6+1]; int T[];
// ll P[2d5+2], K[], B[], W[];
// ll resarr[5d6], sm[2], s, tmp;
// 
// ll seed, base;
// ll rnd(){
//   ll res = seed;
//   seed = (seed * base + 233) % 1000000007;
//   return res;
// }
// 
// {
//   Modint res = 1;
//   rd(N,M);
//   rep(i,1,M+1) rd(P[i], K[i], B[i], W[i]);
//   rep(i,1,M+1){
//     seed = B[i];
//     base = W[i];
//     rep(j, P[i-1]+1, P[i]+1){
//       T[j-1] = (rnd()%2);
//       A[j-1] = (rnd()%K[i]) + 1;
//     }
//   }
// 
//   if(T[0] != 0) rep(i,N) T[i] = 1 - T[i];
//   rep(i,N) sm[T[i]] += A[i];
//   if(sm[0] <= sm[1]){
//     rep(i,N) T[i] = 1 - T[i];
//     swap(sm[0], sm[1]);
//   } else {
//     resarr[0]++;
//     A[0]--;
//   }
// 
//   rep(i,N) if(T[i]==1) resarr[i] = A[i];
//   rep(2) rep(i,N){
//     if(T[i] == 1) s += A[i], A[i] = 0, continue;
//     tmp = min(A[i], s);
//     A[i] -= tmp;
//     s -= tmp;
//     resarr[i] += tmp;
//   }
// 
//   // wt(N);
//   // wt(A(N));
//   // wt(T(N));
//   // wt(resarr(N));
// 
//   rep(i,N) res *= (resarr[i] ^ ((ll)(i+1)*(i+1))) + 1;
//   wt(res);
// }