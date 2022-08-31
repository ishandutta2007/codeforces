#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (998244353U)
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
int N;
int M = 26;
int A[26];
Modint dp[3][3][201][201];
Modint nx[3][3][201][201];
int main(){
  int i, k, t, x;
  int mx = 0;
  Modint res = 1;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    if(i%4 < 2){
      mx++;
    }
  }
  for(i=(0);i<(N);i++){
    if(i < 2){
      res *=M;
    }
    else{
      res *=M-1;
    }
  }
  for(x=(0);x<(3);x++){
    int y;
    for(y=(0);y<(3);y++){
      for(i=(0);i<(mx+1);i++){
        int j;
        for(j=(0);j<(mx+1);j++){
          dp[x][y][i][j] = 0;
        }
      }
    }
  }
  dp[0][0][0][0] = 1;
  for(t=(0);t<(N);t++){
    for(x=(0);x<(3);x++){
      int y;
      for(y=(0);y<(3);y++){
        for(i=(0);i<(mx+1);i++){
          int j;
          for(j=(0);j<(mx+1);j++){
            nx[x][y][i][j] = 0;
          }
        }
      }
    }
    for(x=(0);x<(3);x++){
      int y;
      for(y=(0);y<(3);y++){
        for(i=(0);i<(mx+1);i++){
          int j;
          for(j=(0);j<(mx+1);j++){
            if(x==0&&t>=2){
              nx[y][0][i][j] += dp[x][y][i][j] * (M-3);
            }
            else{
              nx[y][0][i][j] += dp[x][y][i][j] * (M-2);
            }
          }
        }
      }
    }
    for(x=(0);x<(3);x++){
      if(x!=1){
        int y;
        for(y=(0);y<(3);y++){
          for(i=(0);i<(mx);i++){
            int j;
            for(j=(0);j<(mx+1);j++){
              nx[y][1][i+1][j] += dp[x][y][i][j];
            }
          }
        }
      }
    }
    for(x=(0);x<(3);x++){
      if(x!=2){
        int y;
        for(y=(0);y<(3);y++){
          for(i=(0);i<(mx+1);i++){
            int j;
            for(j=(0);j<(mx);j++){
              nx[y][2][i][j+1] += dp[x][y][i][j];
            }
          }
        }
      }
    }
    for(x=(0);x<(3);x++){
      int y;
      for(y=(0);y<(3);y++){
        for(i=(0);i<(mx+1);i++){
          int j;
          for(j=(0);j<(mx+1);j++){
            dp[x][y][i][j] = nx[x][y][i][j];
          }
        }
      }
    }
  }
  for(k=(0);k<(M);k++){
    for(i=(A[k]+1);i<(mx+1);i++){
      int j;
      for(j=(0);j<(mx+1);j++){
        for(x=(0);x<(3);x++){
          int y;
          for(y=(0);y<(3);y++){
            res -= dp[x][y][i][j];
          }
        }
      }
    }
  }
  for(k=(0);k<(M);k++){
    int l;
    for(l=(k+1);l<(M);l++){
      for(i=(A[k]+1);i<(mx+1);i++){
        int j;
        for(j=(A[l]+1);j<(mx+1);j++){
          for(x=(0);x<(3);x++){
            int y;
            for(y=(0);y<(3);y++){
              res += dp[x][y][i][j];
            }
          }
        }
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// #define MD 998244353
// int N, M = 26, A[26];
// Modint dp[3][3][201][201], nx[3][3][201][201];
// {
//   int mx = 0;
//   Modint res = 1;
//   rd(N,A(M));
// 
//   rep(i,N) if(i%4 < 2) mx++;
// 
//   rep(i,N) res *= if[i < 2, M, M-1];
// 
//   rep(x,3) rep(y,3) rep(i,mx+1) rep(j,mx+1) dp[x][y][i][j] = 0;
//   dp[0][0][0][0] = 1;
//   rep(t,N){
//     rep(x,3) rep(y,3) rep(i,mx+1) rep(j,mx+1) nx[x][y][i][j] = 0;
// 
//     rep(x,3) rep(y,3) rep(i,mx+1) rep(j,mx+1) nx[y][0][i][j] += dp[x][y][i][j] * (if[x==0&&t>=2, M-3, M-2]);
// 
//     rep(x,3) if(x!=1) rep(y,3) rep(i,mx) rep(j,mx+1) nx[y][1][i+1][j] += dp[x][y][i][j];
//     rep(x,3) if(x!=2) rep(y,3) rep(i,mx+1) rep(j,mx) nx[y][2][i][j+1] += dp[x][y][i][j];
// 
//     rep(x,3) rep(y,3) rep(i,mx+1) rep(j,mx+1) dp[x][y][i][j] = nx[x][y][i][j];
//   }
// 
//   rep(k,M) rep(i,A[k]+1,mx+1) rep(j,mx+1){
//     rep(x,3) rep(y,3) res -= dp[x][y][i][j];
//   }
//   rep(k,M) rep(l,k+1,M) rep(i,A[k]+1,mx+1) rep(j,A[l]+1,mx+1){
//     rep(x,3) rep(y,3) res += dp[x][y][i][j];
//   }
// 
//   wt(res);
// }