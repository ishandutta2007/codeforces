#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define MD (31607U)
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
inline void rd(Modint &x){
  int i;
  rd(i);
  x=i;
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
inline int BIT_popcount_L(const int x){
  return __builtin_popcount(x);
}
inline int BIT_popcount_L(const long long x){
  return __builtin_popcountll(x);
}
int N;
Modint A[21][21];
Modint p[21][21];
Modint tmp[3000000];
Modint m2[3000000];
Modint s[3000000];
Modint cc[3000000];
int bt[3000000];
int f[30];
int main(){
  int d1, i;
  Modint res = 0;
  Modint m1;
  rd(N);
  {
    int Lj4PdHRW;
    int KL2GvlyY;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      for(KL2GvlyY=(0);KL2GvlyY<(N);KL2GvlyY++){
        rd(A[Lj4PdHRW][KL2GvlyY]);
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      A[i][j] /= 10000;
    }
  }
  for(i=(0);i<(30);i++){
    if(i%2){
      f[i] =-1;
    }
    else{
      f[i] =1;
    }
  }
  for(i=(1);i<(1<<N);i++){
    int j;
    for(j=(0);j<(N);j++){
      if(((i) &(1<<(j)))){
        bt[i] = j;
        break;
      }
    }
  }
  for(d1=(0);d1<(2);d1++){
    int d2;
    for(d2=(0);d2<(2);d2++){
      int mask;
      m1 = 1;
      for(i=(0);i<(N);i++){
        int j;
        for(j=(0);j<(N);j++){
          p[i][j] = A[i][j];
        }
      }
      if(d1){
        for(i=(0);i<(N);i++){
          m1 *= p[i][i];
          p[i][i] = 1;
        }
      }
      if(d2){
        for(i=(0);i<(N);i++){
          m1 *= p[i][N-1-i];
          p[i][N-1-i] = 1;
        }
      }
      for(i=(0);i<(N);i++){
        cc[i] = 1;
      }
      for(i=(0);i<(N);i++){
        int j;
        for(j=(0);j<(N);j++){
          cc[j] *= p[i][j];
        }
      }
      for(mask=(0);mask<(1<<N);mask++){
        m2[mask] = m1;
        for(i=(0);i<(N);i++){
          if(((mask) &(1<<(i)))){
            m2[mask] *= cc[i];
          }
        }
        tmp[mask] = 1;
      }
      for(i=(0);i<(N);i++){
        for(mask=(0);mask<(1<<N);mask++){
          s[mask] = 1;
        }
        for(mask=(1);mask<(1<<N);mask++){
          s[mask] = s[mask^(1<<bt[mask])] * p[i][bt[mask]];
        }
        for(mask=(0);mask<(1<<N);mask++){
          tmp[mask] *= 1 - s[((1<<N)-1)^mask];
        }
      }
      for(mask=(0);mask<(1<<N);mask++){
        tmp[mask] *= m2[mask];
        res += f[BIT_popcount_L(mask)+d1+d2] * tmp[mask];
      }
    }
  }
  wt_L(1-res);
  wt_L('\n');
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// #define MD 31607
// int N; Modint A[21][21], p[21][21];
// Modint tmp[3d6], m2[], s[], cc[];
// int bt[];
// int f[30];
// {
//   Modint res = 0, m1;
//   rd(N,A(N,N));
//   rep(i,N) rep(j,N) A[i][j] /= 10000;
// 
//   // N = 21;
//   // rep(i,N) rep(j,N) A[i][j] = 1263; // 28806
// 
//   rep(i,30) f[i] = if[i%2, -1, 1];
//   rep(i,1,1<<N) rep(j,N) if(BIT_ith(i,j)) bt[i] = j, break;
// 
//   rep(d1,2) rep(d2,2){
//     m1 = 1;
//     rep(i,N) rep(j,N) p[i][j] = A[i][j];
//     if(d1) rep(i,N) m1 *= p[i][i], p[i][i] = 1;
//     if(d2) rep(i,N) m1 *= p[i][N-1-i], p[i][N-1-i] = 1;
// 
//     rep(i,N) cc[i] = 1;
//     rep(i,N) rep(j,N) cc[j] *= p[i][j];
// 
//     rep(mask,1<<N){
//       m2[mask] = m1;
//       rep(i,N) if(BIT_ith(mask,i)) m2[mask] *= cc[i];
//       tmp[mask] = 1;
//     }
// 
//     rep(i,N){
//       rep(mask,1<<N) s[mask] = 1;
//       rep(mask,1,1<<N) s[mask] = s[mask^(1<<bt[mask])] * p[i][bt[mask]];
//       // rep(mask,1<<N) rep(j,N) if(!BIT_ith(mask,j)) s[mask] *= p[i][j];
//       rep(mask,1<<N) tmp[mask] *= 1 - s[((1<<N)-1)^mask];
//     }
// 
//     rep(mask,1<<N){
//       tmp[mask] *= m2[mask];
//       res += f[BIT_popcount(mask)+d1+d2] * tmp[mask];
//     }
//   }
// 
//   wt(1-res);
// }