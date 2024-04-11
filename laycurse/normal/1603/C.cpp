#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define MD (998244353U)
void*wmem;
char memarr[241172480];
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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int main(){
  int FmcKpFmN, k;
  wmem = memarr;
  int sz[100000+1] = {};
  int*mx[100000+1];
  for(k=(1);k<(100000+1);k++){
    int i;
    walloc1d(&mx[k], sz[k-1]+1);
    for(i=(1);i<(k+1);i++){
      mx[k][sz[k]] =(divup_L(k,i));
      if(sz[k] && mx[k][sz[k]] == mx[k][sz[k]-1]){
        break;
      }
      sz[k]++;
    }
    while(mx[k][sz[k]-1] != 1){
      mx[k][sz[k]] = mx[k][sz[k]-1] - 1;
      sz[k]++;
    }
  }
  int xr20shxY = rd_int();
  for(FmcKpFmN=(0);FmcKpFmN<(xr20shxY);FmcKpFmN++){
    int N;
    rd(N);
    int A[N];
    {
      int KrdatlYV;
      for(KrdatlYV=(0);KrdatlYV<(N);KrdatlYV++){
        rd(A[KrdatlYV]);
      }
    }
    int x;
    int y;
    int i;
    int j;
    int k;
    int m;
    Modint dp[640] = {1};
    Modint nx[640];
    Modint res = 0;
    for(m=(N-1)-1;m>=(0);m--){
      auto V9aVTaxx = ((A[m]));
      auto APIVbQlN = (( A[m+1]));
      x=V9aVTaxx;
      y=APIVbQlN;
      for(i=(0);i<(sz[x]);i++){
        nx[i] = 0;
      }
      j = 0;
      for(i=(0);i<(sz[y]);i++){
        k = mx[y][i];
        if(y%k){
          k--;
        }
        while(mx[x][j] > k){
          j++;
        }
        nx[j] += dp[i];
      }
      nx[0]++;
      for(i=(0);i<(sz[x]);i++){
        dp[i] = nx[i];
      }
      for(i=(0);i<(sz[x]);i++){
        res += dp[i] * ((divup_L(x,mx[x][i]))- 1) * (m + 1);
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20211024-1

// --- original code ---
// //no-unlocked
// //working_memory=230m
// #define MD 998244353
// int sz[1d5+1] = {}, *mx[1d5+1];
// 
// rep(k,1,1d5+1){
//   walloc1d(&mx[k], sz[k-1]+1);
//   rep(i,1,k+1){
//     mx[k][sz[k]] = k /+ i;
//     if(sz[k] && mx[k][sz[k]] == mx[k][sz[k]-1]) break;
//     sz[k]++;
//   }
//   while(mx[k][sz[k]-1] != 1){
//     mx[k][sz[k]] = mx[k][sz[k]-1] - 1;
//     sz[k]++;
//   }
// }
// 
// REP(rd_int()){
//   int @N, @A[N], x, y, i, j, k, m;
//   Modint dp[640] = {1}, nx[640], res = 0;
//   rrep(m,N-1){
//     (x, y) = (A[m], A[m+1]);
//     rep(i,sz[x]) nx[i] = 0;
// 
//     j = 0;
//     rep(i,sz[y]){
//       k = mx[y][i];
//       if(y%k) k--;
//       while(mx[x][j] > k) j++;
//       nx[j] += dp[i];
//     }
//     nx[0]++;
// 
//     rep(i,sz[x]) dp[i] = nx[i];
//     rep(i,sz[x]) res += dp[i] * (x /+ mx[x][i] - 1) * (m + 1);
//   }
//   wt(res);
// }
//