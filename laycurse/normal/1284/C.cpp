#pragma GCC optimize ("Ofast")
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
    a %= md;
    if(a < 0){
      a += md;
    }
    return a;
  }
  unsigned ord(unsigned long long a){
    return a%md;
  }
  unsigned ord(long long a){
    a %= md;
    if(a < 0){
      a += md;
    }
    return a;
  }
  unsigned get(){
    return val;
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
inline void rd(int &x){
  int k;
  int m=0;
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
modint fac[300000];
int main(){
  int i, k;
  {
    modint x;
    x.setmod(MD);
  }
  modint res = 0;
  modint tmp;
  rd(N);
  rd(M);
  res.setmod(M);
  fac[0] = 1;
  for(i=(0);i<(N);i++){
    fac[i+1] = (i+1) * fac[i];
  }
  for(k=(1);k<(N+1);k++){
    res += fac[k] * fac[N-k] * (N - k + 1) * (N - k + 1);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M;
// modint fac[3d5];
// {
//   modint res = 0, tmp;
//   rd(N,M);
//   res.setmod(M);
// 
//   fac[0] = 1;
//   rep(i,N) fac[i+1] = (i+1) * fac[i];
// 
//   rep(k,1,N+1){
//     res += fac[k] * fac[N-k] * (N - k + 1) * (N - k + 1);
//   }
// 
//   wt(res);
// }