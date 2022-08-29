#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (998244353U)
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
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
template<class S> void arrErase(int k, int &sz, S a[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
}
template<class S, class T> void arrErase(int k, int &sz, S a[], T b[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
}
template<class S, class T, class U> void arrErase(int k, int &sz, S a[], T b[], U c[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
  for(i=(k);i<(sz);i++){
    c[i] = c[i+1];
  }
}
int N;
long long A[200000];
long long nd;
long long c;
long long up[20][200000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int x;
    Modint res = 0;
    int i;
    int j;
    int k;
    int n;
    int ss;
    int ee;
    long long f;
    long long e;
    long long ok;
    long long ls;
    long long r;
    long long cur;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    res = 0;
    int xr20shxY;
    cLtraits_try_make_signed<remove_reference<decltype((*((long long*)NULL)))>::type>::type WYIGIcGE;
    if(N==0){
      WYIGIcGE = 0;
    }
    else{
      WYIGIcGE = A[0];
      for(xr20shxY=(1);xr20shxY<(N);xr20shxY++){
        WYIGIcGE += A[xr20shxY];
      }
    }
    nd =WYIGIcGE/ 2 + 1;
    if(N<=3){
      int mask;
      for(mask=(0);mask<(1<<N);mask++){
        c = 0;
        for(i=(0);i<(N);i++){
          if(((mask) &(1<<(i)))){
            c+= A[i];
          }
        }
        if(c >= nd){
          res++;
        }
      }
      wt_L(res);
      wt_L('\n');
      continue;
    }
    reverse(A, A+N);
    c = 0;
    for(i=(0);i<(N);i++){
      c += A[N-1-i];
      if(i >= 1 && c >= nd){
        res++;
      }
    }
    f = A[0];
    e = A[N-1];
    arrErase(0, N, A);
    arrErase(N-1, N, A);
    for(i=(0);i<(N);i++){
      up[0][i] = A[i];
    }
    for(k=(1);k<(20);k++){
      for(i=(0);i<(N);i++){
        j = i + (1<<k);
        up[k][i] = up[k-1][i];
        if(j < N){
          up[k][i] += up[k-1][j];
        }
      }
    }
    for(x=(0);x<(3);x++){
      int y;
      for(y=(0);y<(2);y++){
        c = ss = 0;
        n = N;
        if(x){
          c += f;
        }
        if(y){
          c += e;
          n--;
        }
        ee = n;
        if(x==2){
          ss = 1;
          ee = 2;
        }
        if(x <= 1 && c >= nd){
          res++;
        }
        for(i=(ss);i<(ee);i++){
          if(c + up[19][i] >= nd){
            j = i;
            cur = c;
            for(k=(20)-1;k>=(0);k--){
              if(j < n && cur + up[k][j] < nd){
                cur += up[k][j];
                j += (1<<k) * 2;
              }
            }
            if(j < n){
              res += (n - j + 1) / 2;
            }
          }
          c += A[i];
        }
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// #define MD 998244353
// int N; ll A[2d5], nd, c;
// 
// ll up[20][2d5];
// 
// {
//   REP(rd_int()){
//     Modint res = 0;
//     int i, j, k, n, ss, ee;
//     ll f, e, ok, ls, r, cur;
//     rd(N,A(N));
// 
//     // {
//     //   int arr[2000];
//     //   int cs, c[20];
//     //   int ps, p[20];
//     //   ll sm = 0, pm = 0;
//     //   rep(i,N) sm += A[i];
//     //   rep(mask,1<<N){
//     //     DigitF(mask, N, arr, 2);
//     //     cs = ps = 0;
//     //     rep(i,N) if(arr[i] == 0) c[cs++] = i;
//     //     rep(i,N) if(arr[i] == 1) p[ps++] = i;
//     //     rep(i,2,cs) if(c[i]-c[i-1] < c[i-1]-c[i-2]) break_continue;
//     //     rep(i,2,ps) if(p[i]-p[i-1] > p[i-1]-p[i-2]) break_continue;
//     //     pm = 0;
//     //     rep(i,N) if(arr[i]) pm += A[i];
//     //     if(sm - pm < pm) res++, wt(arr(N));
//     //   }
//     //   wt(res);
//     // }
// 
// 
//     res = 0;
// 
//     nd = sum(A(N)) / 2 + 1;
//     if(N<=3){
//       rep(mask,1<<N){
//         c = 0;
//         rep(i,N) if(BIT_ith(mask,i)) c+= A[i];
//         if(c >= nd) res++;
//       }
//       wt(res);
//       continue;
//     }
//     reverse(A, A+N);
// 
//     c = 0;
//     rep(i,N){
//       c += A[N-1-i];
//       if(i >= 1 && c >= nd) res++;
//     }
// 
//     f = A[0];
//     e = A[N-1];
//     arrErase(0, N, A);
//     arrErase(N-1, N, A);
// 
//     rep(i,N) up[0][i] = A[i];
//     rep(k,1,20) rep(i,N){
//       j = i + (1<<k);
//       up[k][i] = up[k-1][i];
//       if(j < N) up[k][i] += up[k-1][j];
//     }
// 
//     rep(x,3) rep(y,2){
//       c = ss = 0;
//       n = N;
//       if(x) c += f;
//       if(y) c += e, n--;
//       ee = n;
//       if(x==2) ss = 1, ee = 2;
// 
//       if(x <= 1 && c >= nd) res++;
//       rep(i,ss,ee){
//         if(c + up[19][i] >= nd){
//           j = i;
//           cur = c;
//           rrep(k,20) if(j < n && cur + up[k][j] < nd) cur += up[k][j], j += (1<<k) * 2;
//           if(j < n) res += (n - j + 1) / 2;
//           // wt(x, y, ":", c, ":", i, j, n, ":", res);
//         }
//         c += A[i];
//       }
//     }
// 
//     wt(res);
//   }
// }