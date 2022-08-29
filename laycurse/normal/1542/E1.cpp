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
int N;
int M;
modint dp[501][130000];
modint sm[501][130000];
modint f[501];
int main(){
  {
    modint x;
    x.setmod(MD);
  }
  int i;
  int j;
  int mx;
  modint res = 0;
  modint tmp;
  modint mcf;
  rd(N);
  rd(M);
  res.setmod(M);
  mx = 1;
  dp[0][0] = dp[1][0] = 1;
  for(i=(2);i<(N+1);i++){
    int k;
    mx += i-1;
    for(k=(0);k<(mx);k++){
      sm[i-1][k+1] = sm[i-1][k] + dp[i-1][k];
    }
    for(k=(0);k<(mx);k++){
      dp[i][k] = sm[i-1][k+1];
      if(k-i+1 >= 0){
        dp[i][k] -= sm[i-1][k-i+1];
      }
    }
  }
  mcf = 1;
  for(i=(N+1)-1;i>=(2);i--){
    tmp = 0;
    for(j=(0);j<(i);j++){
      int k;
      for(k=(0);k<(j);k++){
        int m;
        for(m=(0);m<(mx);m++){
          if(m-(j-k)>=0){
            tmp += dp[i-1][m] * sm[i-1][m-(j-k)];
          }
        }
      }
    }
    res += mcf * tmp;
    mcf *= i;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210703-1

// --- original code ---
// //no-unlocked
// int N, M;
// modint dp[501][130000], sm[501][130000], f[501];
// {
//   int i, j, mx;
//   modint res = 0, tmp, mcf;
//   rd(N,M);
//   res.setmod(M);
// 
//   mx = 1;
//   dp[0][0] = dp[1][0] = 1;
//   rep(i,2,N+1){
//     mx += i-1;
//     rep(k,mx) sm[i-1][k+1] = sm[i-1][k] + dp[i-1][k];
//     rep(k,mx){
//       dp[i][k] = sm[i-1][k+1];
//       if(k-i+1 >= 0) dp[i][k] -= sm[i-1][k-i+1];
//     }
//   }
// 
//   mcf = 1;
//   rrep(i,2,N+1){
//     tmp = 0;
// 
//     rep(j,i) rep(k,j){
//       rep(m,mx) if(m-(j-k)>=0) tmp += dp[i-1][m] * sm[i-1][m-(j-k)];
//     }
// 
//     res += mcf * tmp;
//     mcf *= i;
//   }
// 
//   wt(res);
// }