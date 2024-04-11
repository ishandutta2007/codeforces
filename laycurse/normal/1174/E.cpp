#include<bits/stdc++.h>
using namespace std;
#define MD 1000000007
struct mint{
  static unsigned R, RR, Rinv, W, md, mdninv;
  unsigned val;
  mint(){
  }
  mint(int a){
    val = mulR(a);
  }
  mint(unsigned a){
    val = mulR(a);
  }
  mint(long long a){
    val = mulR(a);
  }
  mint(unsigned long long a){
    val = mulR(a);
  }
  int get_inv(long long a, int md){
    long long e, s=md, t=a, u=1, v=0;
    while(s){
      e=t/s;
      t-=e*s;
      u-=e*v;
      swap(t,s);
      swap(u,v);
    }
    if(u<0){
      u+=md;
    }
    return u;
  }
  void setmod(unsigned m){
    int i;
    unsigned t;
    W = 32;
    md = m;
    R = (1ULL << W) % md;
    RR = (unsigned long long)R*R % md;
    switch(m){
      case 104857601:
      Rinv = 2560000;
      mdninv = 104857599;
      break;
      case 998244353:
      Rinv = 232013824;
      mdninv = 998244351;
      break;
      case 1000000007:
      Rinv = 518424770;
      mdninv = 2226617417U;
      break;
      case 1000000009:
      Rinv = 171601999;
      mdninv = 737024967;
      break;
      case 1004535809:
      Rinv = 234947584;
      mdninv = 1004535807;
      break;
      case 1007681537:
      Rinv = 236421376;
      mdninv = 1007681535;
      break;
      case 1012924417:
      Rinv = 238887936;
      mdninv = 1012924415;
      break;
      case 1045430273:
      Rinv = 254466304;
      mdninv = 1045430271;
      break;
      case 1051721729:
      Rinv = 257538304;
      mdninv = 1051721727;
      break;
      default:
      Rinv = get_inv(R, md);
      mdninv = 0;
      t = 0;
      for(i=0;i<(int)W;i++){
        if(t%2==0){
          t+=md;
          mdninv |= (1U<<i);
        }
        t /= 2;
      }
    }
  }
  unsigned mulR(unsigned a){
    return (unsigned long long)a*R%md;
  }
  unsigned mulR(int a){
    if(a < 0){
      a = a%md+md;
    }
    return mulR((unsigned)a);
  }
  unsigned mulR(unsigned long long a){
    return mulR((unsigned)(a%md));
  }
  unsigned mulR(long long a){
    a %= md;
    if(a < 0){
      a += md;
    }
    return mulR((unsigned)a);
  }
  unsigned reduce(unsigned T){
    unsigned m=T * mdninv, t=(unsigned)((T + (unsigned long long)m*md) >> W);
    if(t >= md){
      t -= md;
    }
    return t;
  }
  unsigned reduce(unsigned long long T){
    unsigned m=(unsigned)T * mdninv, t=(unsigned)((T + (unsigned long long)m*md) >> W);
    if(t >= md){
      t -= md;
    }
    return t;
  }
  unsigned get(){
    return reduce(val);
  }
  mint &operator+=(mint a){
    val += a.val;
    if(val >= md){
      val -= md;
    }
    return *this;
  }
  mint &operator-=(mint a){
    if(val < a.val){
      val = val + md - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  mint &operator*=(mint a){
    val = reduce((unsigned long long)val*a.val);
    return *this;
  }
  mint &operator/=(mint a){
    return *this *= a.inverse();
  }
  mint operator+(mint a){
    return mint(*this)+=a;
  }
  mint operator-(mint a){
    return mint(*this)-=a;
  }
  mint operator*(mint a){
    return mint(*this)*=a;
  }
  mint operator/(mint a){
    return mint(*this)/=a;
  }
  mint operator+(int a){
    return mint(*this)+=mint(a);
  }
  mint operator-(int a){
    return mint(*this)-=mint(a);
  }
  mint operator*(int a){
    return mint(*this)*=mint(a);
  }
  mint operator/(int a){
    return mint(*this)/=mint(a);
  }
  mint operator+(long long a){
    return mint(*this)+=mint(a);
  }
  mint operator-(long long a){
    return mint(*this)-=mint(a);
  }
  mint operator*(long long a){
    return mint(*this)*=mint(a);
  }
  mint operator/(long long a){
    return mint(*this)/=mint(a);
  }
  mint operator-(void){
    mint res;
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

  mint inverse(){
    int a = val, b = md, u = 1, v = 0, t;
    mint res;
    while(b){
      t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    if(u < 0) u += md;
    res.val = (unsigned long long)u*RR % md;
    return res;
  }

  mint pw(unsigned long long b){
    mint a(*this), res;
    res.val = R;
    while(b){
      if(b&1) res *= a;
      b >>= 1;
      a *= a;
    }
    return res;
  }

  bool operator==(int a){return mulR(a)==val;}
  bool operator!=(int a){return mulR(a)!=val;}
};
unsigned mint::md, mint::W, mint::R, mint::Rinv, mint::mdninv, mint::RR;
mint operator+(int a, mint b){return mint(a)+=b;
}
mint operator-(int a, mint b){
  return mint(a)-=b;
}
mint operator*(int a, mint b){
  return mint(a)*=b;
}
mint operator/(int a, mint b){
  return mint(a)/=b;
}
mint operator+(long long a, mint b){
  return mint(a)+=b;
}
mint operator-(long long a, mint b){
  return mint(a)-=b;
}
mint operator*(long long a, mint b){
  return mint(a)*=b;
}
mint operator/(long long a, mint b){
  return mint(a)/=b;
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
inline void wt_L(mint x){
  int i;
  i = (int)x;
  wt_L(i);
}
template<class T> int FactorM_L(T N, T fac[]){
  T i;
  int sz=0;
  while(N%2==0){
    fac[sz] = 2;
    N /= 2;
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    while(N%i==0){
      fac[sz] = i;
      N /= i;
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    sz++;
  }
  return sz;
}
int N;
mint fac[1000001];
int fs;
int f[20];
mint solve(int M){
  int i, j, k, x, y;
  mint res, tmp;
  fs =FactorM_L(M, f);
  res = 0;
  do{
    tmp = 1;
    j = 1;
    x = 0;
    for(i=0;i<fs;i++){
      k = j * f[i];
      y = N - N / k - x;
      if(x){
        tmp *= fac[y+x] / fac[x]- fac[y+x-1] / fac[x-1];
      }
      else{
        tmp *= fac[y+x] / fac[x];
      }
      j = k;
      x += y;
    }
    res += tmp;
  }
  while(next_permutation(f,f+fs));
  return res;
}
int main(){
  int i, j;
  mint res;
  {
    mint x;
    x.setmod(MD);
  }
  rd(N);
  fac[0] = 1;
  for(i=1;i<N+1;i++){
    fac[i] = fac[i-1] * i;
  }
  j = 1;
  while(2*j <= N){
    j *= 2;
  }
  res = solve(j);
  if(j>=2 && j/2*3 <= N){
    res += solve(j/2*3);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190608-2

// --- original code ---
// //no-unlocked
// 
// int N;
// mint fac[1000001];
// 
// int fs, f[20];
// 
// mint solve(int M){
//   int i, j, k;
//   int x, y;
//   mint res, tmp;
// 
//   fs = FactorM(M, f);
// 
//   res = 0;
//   do{
//     tmp = 1;
//     j = 1;
//     x = 0;
//     rep(i,fs){
//       k = j * f[i];
//       y = N - N / k - x;
//       tmp *= fac[y+x] / fac[x] if[x, - fac[y+x-1] / fac[x-1]];
//       j = k;
//       x += y;
//     }
//     res += tmp;
//   }while(next_permutation(f,f+fs));
// 
//   return res;
// }
// 
// {
//   int i, j;
//   mint res;
// 
//   rd(N);
//   fac[0] = 1;
//   rep(i,1,N+1) fac[i] = fac[i-1] * i;
// 
//   j = 1;
//   while(2j <= N) j *= 2;
//   res = solve(j);
//   if(j>=2 && j/2*3 <= N) res += solve(j/2*3);
//   wt(res);
// }