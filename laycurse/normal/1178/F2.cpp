#include<bits/stdc++.h>
using namespace std;
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
    int a=val, b=md, t, u=1, v=0;
    mint res;
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
    res.val = (unsigned long long)u*RR % md;
    return res;
  }
  mint pw(unsigned long long b){
    mint a(*this), res;
    res.val = R;
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
    return mulR(a)==val;
  }
  bool operator!=(int a){
    return mulR(a)!=val;
  }
}
;
mint operator+(int a, mint b){
  return mint(a)+=b;
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
unsigned mint::R, mint::RR, mint::Rinv, mint::W, mint::md, mint::mdninv;
#define MD 998244353
int N;
int M;
int C[1000000];
int vis[1000][1000];
mint dp[1000][1000];
int gmn[500];
int gmx[500];
mint solve(int a, int b){
  int dame, i, j, k, mn, mx;
  mint lef, mul, rig;
  if(a > b){
    return 1;
  }
  if(vis[a][b]){
    return dp[a][b];
  }
  vis[a][b] = 1;
  j = 1073709056;
  for(i=a;i<b+1;i++){
    chmin(j, C[i]);
  }
  mn = gmn[j];
  mx = gmx[j];
  lef = rig = 0;
  dame = mn;
  for(i=mn;i>=a;i--){
    chmin(dame, gmn[C[i]]);
    if(i <= dame){
      lef += solve(a,i-1) * solve(i,mn-1);
    }
  }
  dame = mx;
  for(i=mx;i<=b;i++){
    chmax(dame, gmx[C[i]]);
    if(i >= dame){
      rig += solve(mx+1,i) * solve(i+1,b);
    }
  }
  mul = 1;
  for(i=mn;i<mx+1;i++){
    if(C[i]==j){
      continue;
    }
    k = i;
    while(C[k+1]!=j){
      k++;
    }
    mul *= solve(i,k);
    i = k;
  }
  return dp[a][b] = lef * rig * mul;
}
int main(){
  int i, j, k, mn, mx;
  mint res;
  {
    mint x;
    x.setmod(MD);
  }
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<M;Lj4PdHRW++){
      rd(C[Lj4PdHRW]);C[Lj4PdHRW] += (-1);
    }
  }
  k = 1;
  for(i=1;i<M;i++){
    if(C[i]==C[i-1]){
      continue;
    }
    C[k++] = C[i];
  }
  M = k;
  if(M > 2*N){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  for(i=0;i<N;i++){
    gmn[i] = M;
  }
  for(i=0;i<N;i++){
    gmx[i] = -1;
  }
  for(i=0;i<M;i++){
    chmin(gmn[C[i]], i);
  }
  for(i=0;i<M;i++){
    chmax(gmx[C[i]], i);
  }
  for(k=0;k<N;k++){
    for(i=gmn[k]+1;i<gmx[k];i++){
      if(C[i] < k){
        wt_L(0);
        wt_L('\n');
        return 0;
      }
    }
  }
  res = solve(0, M-1);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190721-1

// --- original code ---
// //no-unlocked
// #define MD 998244353
// 
// int N, M;
// int C[1d6];
// 
// int vis[1000][1000];
// mint dp[1000][1000];
// 
// int gmn[500], gmx[500];
// 
// mint solve(int a, int b){
//   int i, j, k, mn, mx, dame;
//   mint lef, rig, mul;
// 
//   if(a > b) return 1;
//   if(vis[a][b]) return dp[a][b];
//   vis[a][b] = 1;
// 
//   j = int_inf;
//   rep(i,a,b+1) j <?= C[i];
//   mn = gmn[j];
//   mx = gmx[j];
// 
//   lef = rig = 0;
//   dame = mn;
//   for(i=mn;i>=a;i--){
//     dame <?= gmn[C[i]];
//     if(i <= dame) lef += solve(a,i-1) * solve(i,mn-1);
//   }
//   dame = mx;
//   for(i=mx;i<=b;i++){
//     dame >?= gmx[C[i]];
//     if(i >= dame) rig += solve(mx+1,i) * solve(i+1,b);
//   }
// 
//   mul = 1;
//   rep(i,mn,mx+1){
//     if(C[i]==j) continue;
//     k = i;
//     while(C[k+1]!=j) k++;
//     mul *= solve(i,k);
//     i = k;
//   }
// 
//   return dp[a][b] = lef * rig * mul;
// }
// 
// {
//   int i, j, k, mn, mx;
//   mint res;
//   rd(N,M,(C--)(M));
//   
//   k = 1;
//   rep(i,1,M){
//     if(C[i]==C[i-1]) continue;
//     C[k++] = C[i];
//   }
//   M = k;
// 
//   if(M > 2N){
//     wt(0);
//     return 0;
//   }
// 
//   rep(i,N) gmn[i] = M;
//   rep(i,N) gmx[i] = -1;
//   rep(i,M) gmn[C[i]] <?= i;
//   rep(i,M) gmx[C[i]] >?= i;
// 
//   rep(k,N){
//     rep(i,gmn[k]+1,gmx[k]) if(C[i] < k){
//       wt(0);
//       return 0;
//     }
//   }
// 
//   res = solve(0, M-1);
//   wt(res);
// }