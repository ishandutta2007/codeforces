#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define MD (1000000007U)
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
template<class T, class S, class U> inline void DigitF_L(T n, int sz, S res[], U b){
  int i;
  for(i=(0);i<(sz);i++){
    res[i] = n % b;
    n /= b;
  }
}
int N;
int A[20];
Modint dp[5000000];
Modint res;
Modint t1;
Modint t2;
Modint t3;
Modint p[15][15];
int pw[15];
int arr[15];
int bs;
int btl[15];
vector<Modint> tmp[14][20000];
Modint tmp2;
vector<int> ad[14][20000];
int ad2;
int main(){
  int i;
  int j;
  int k;
  int mask;
  int m2;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  pw[0] = 1;
  for(i=(0);i<(N);i++){
    pw[i+1] = pw[i] * 3;
  }
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N);j++){
      p[i][j] = Modint(A[i]) / (A[i]+A[j]);
    }
  }
  for(k=(0);k<(N);k++){
    for(mask=(0);mask<(1<<N);mask++){
      if(!((mask) &(1<<(k)))){
        bs = 0;
        for(i=(0);i<(N);i++){
          if(((mask) &(1<<(i)))){
            btl[bs++] = i;
          }
        }
        for(m2=(0);m2<(1<<bs);m2++){
          tmp2 = 1;
          ad2 = pw[k];
          for(i=(0);i<(bs);i++){
            if(((m2) &(1<<(i)))){
              tmp2 = tmp2 *p[k][btl[i]];
            }
            else{
              tmp2 = tmp2 *p[btl[i]][k];
            }
            if(((m2) &(1<<(i)))){
              ad2 += pw[btl[i]];
            }
          }
          tmp[k][mask].push_back(tmp2);
          ad[k][mask].push_back(ad2);
        }
      }
    }
  }
  for(i=(0);i<(N);i++){
    dp[pw[i]] = 1;
  }
  for(mask=(0);mask<(pw[N]);mask++){
    DigitF_L(mask,N,arr,3);
    for(k=(0);k<(N);k++){
      if(arr[k] == 1){
        break;
      }
    }
    if(k==N){
      continue;
    }
    m2 = 0;
    for(i=(0);i<(N);i++){
      if(arr[i]==0){
        m2 |= (1<<i);
      }
    }
    for(j=(0);j<(tmp[k][m2].size());j++){
      dp[mask+ad[k][m2][j]] += dp[mask] * tmp[k][m2][j];
    }
  }
  res = dp[pw[N]-1];
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210819-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[20];
// Modint dp[5d6], res, t1, t2, t3, p[15][15];
// int pw[15], arr[15], bs, btl[15];
// vector<Modint> tmp[14][2d4]; Modint tmp2;
// vector<int> ad[14][2d4]; int ad2;
// {
//   int i, j, k, mask, m2;
//   rd(N,A(N));
// 
//   pw[0] = 1;
//   rep(i,N) pw[i+1] = pw[i] * 3;
// 
//   rep(i,N) rep(j,N) p[i][j] = Modint(A[i]) / (A[i]+A[j]);
// 
//   rep(k,N){
//     rep(mask,1<<N) if(!BIT_ith(mask,k)){
//       bs = 0;
//       rep(i,N) if(BIT_ith(mask,i)) btl[bs++] = i;
//       rep(m2,1<<bs){
//         tmp2 = 1;
//         ad2 = pw[k];
//         rep(i,bs){
//           tmp2 = tmp2 * if[BIT_ith(m2,i), p[k][btl[i]], p[btl[i]][k]];
//           if(BIT_ith(m2,i)) ad2 += pw[btl[i]];
//         }
//         tmp[k][mask].push_back(tmp2);
//         ad[k][mask].push_back(ad2);
//       }
//     }
//   }
// 
//   rep(i,N) dp[pw[i]] = 1;
//   rep(mask,pw[N]){
//     DigitF(mask,N,arr,3);
//     rep(k,N) if(arr[k] == 1) break;
//     if(k==N) continue;
// 
//     m2 = 0;
//     rep(i,N) if(arr[i]==0) m2 |= (1<<i);
//     rep(j,tmp[k][m2].size()){
//       dp[mask+ad[k][m2][j]] += dp[mask] * tmp[k][m2][j];
//     }
//   }
// 
//   res = dp[pw[N]-1];
//   wt(res);
// }