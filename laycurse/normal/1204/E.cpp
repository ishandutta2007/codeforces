#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD 998244853
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
struct modint{
  unsigned val;
  modint(){
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
  unsigned ord(unsigned a){
    return a%MD;
  }
  unsigned ord(int a){
    a %= MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  unsigned ord(unsigned long long a){
    return a%MD;
  }
  unsigned ord(long long a){
    a %= MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  unsigned get(){
    return val;
  }
  modint &operator+=(modint a){
    val += a.val;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  modint &operator-=(modint a){
    if(val < a.val){
      val = val + MD - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  modint &operator*=(modint a){
    val = ((unsigned long long)val*a.val)%MD;
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
      res.val=MD-val;
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
    int a=val, b=MD, t, u=1, v=0;
    modint res;
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
  modint pw(unsigned long long b){
    modint a(*this), res;
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
inline void rd(int &x){
  int k, m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(int x){
  char f[10];
  int m=0, s=0;
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(modint x){
  int i;
  i = (int)x;
  wt_L(i);
}
int N;
int M;
modint C[4001][2001];
inline modint f(int a, int b){
  if(a < b){
    return 0;
  }
  return (a-b+1) * C[a+b][b] / (a+1);
}
int main(){
  int i, j, x1, x2, y1, y2;
  modint res;
  rd(N);
  rd(M);
  for(i=0;i<(4001);i++){
    C[i][0] = 1;
  }
  for(i=(1);i<(4001);i++){
    for(j=(1);j<(2001);j++){
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }
  res = 0;
  for(i=0;i<(N+M+1);i++){
    for(j=i%2;j<=min_L(N, i);j+=2){
      x1 = j + (i-j) / 2;
      y1 = (i-j) / 2;
      if(x1 < 0 || y1 < 0 || x1 > N || y1 > M){
        continue;
      }
      x2 = y2 = 0;
      if(i < N+M){
        x2 = N - x1;
        y2 = M - y1 - 1;
        if(y2 < 0){
          continue;
        }
      }
      res += j * f(x1, y1) * f(y2, x2);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// #define MD 998244853
// 
// int N, M;
// modint C[4001][2001];
// 
// inline modint f(int a, int b){
//   if(a < b) return 0;
//   return (a-b+1) * C[a+b][b] / (a+1);
// }
// 
// {
//   int i, j;
//   int x1, y1, x2, y2;
//   modint res;
//   
//   rd(N,M);
// 
//   rep(i,4001) C[i][0] = 1;
//   rep(i,1,4001) rep(j,1,2001) C[i][j] = C[i-1][j-1] + C[i-1][j];
// 
//   res = 0;
//   rep(i,N+M+1) for(j=i%2;j<=min(N,i);j+=2){
//     x1 = j + (i-j) / 2;
//     y1 = (i-j) / 2;
//     if(x1 < 0 || y1 < 0 || x1 > N || y1 > M) continue;
// 
//     x2 = y2 = 0;
//     if(i < N+M){
//       x2 = N - x1;
//       y2 = M - y1 - 1;
//       if(y2 < 0) continue;
//     }
// 
//     res += j * f(x1, y1) * f(y2, x2);
//   }
//   wt(res);
// }
//