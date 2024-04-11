#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
struct Timer{
  double x;
  double gettimeofday_sec(void){
    timeval t;
    gettimeofday(&t, 0);
    return t.tv_sec + t.tv_usec * 1e-6;
  }
  void set(void){
    x = gettimeofday_sec();
  }
  double get(void){
    return gettimeofday_sec() - x;
  }
}
;
struct Rand{
  unsigned x;
  unsigned y;
  unsigned z;
  unsigned w;
  Rand(void){
    x=123456789;
    y=362436069;
    z=521288629;
    w=(unsigned)time(NULL);
  }
  Rand(unsigned seed){
    x=123456789;
    y=362436069;
    z=521288629;
    w=seed;
  }
  inline unsigned get(void){
    unsigned t;
    t = (x^(x<<11));
    x=y;
    y=z;
    z=w;
    w = (w^(w>>19))^(t^(t>>8));
    return w;
  }
  inline double getUni(void){
    return get()/4294967296.0;
  }
  inline int get(int a){
    return (int)(a*getUni());
  }
  inline int get(int a, int b){
    return a+(int)((b-a+1)*getUni());
  }
  inline long long get(long long a){
    return(long long)(a*getUni());
  }
  inline long long get(long long a, long long b){
    return a+(long long)((b-a+1)*getUni());
  }
  inline double get(double a, double b){
    return a+(b-a)*getUni();
  }
  inline int getExp(int a){
    return(int)(exp(getUni()*log(a+1.0))-1.0);
  }
  inline int getExp(int a, int b){
    return a+(int)(exp(getUni()*log((b-a+1)+1.0))-1.0);
  }
}
;
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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
long long A[200000];
int fs;
long long f[100];
long long ord(long long x){
  while(x > 0 && x % 2 == 0){
    x /= 2;
  }
  while(x > 0 && x % 3 == 0){
    x /= 3;
  }
  while(x > 0 && x % 5 == 0){
    x /= 5;
  }
  while(x > 0 && x % 7 == 0){
    x /= 7;
  }
  return x;
}
int main(){
  int x;
  int y;
  int res;
  int ft = 1;
  long long tmp;
  long long p;
  long long r;
  long long g;
  Rand rnd;
  Timer timer;
  set<long long> chk;
  timer.set();
  chk.insert(0LL);
  chk.insert(1LL);
  rd(N);
  {
    int WYIGIcGE;
    for(WYIGIcGE=(0);WYIGIcGE<(N);WYIGIcGE++){
      rd(A[WYIGIcGE]);
    }
  }
  res = N;
  while(timer.get() < 2){
    int ZIeRIny5, i;
    x = rnd.get(N);
    y = rnd.get(N);
    fs = 0;
    if(ft){
      f[fs++] = 2;
      f[fs++] = 3;
      f[fs++] = 5;
      f[fs++] = 7;
      ft = 0;
    }
    for(i=(-1);i<(2);i++){
      f[fs++] = ord(A[x] + i);
      f[fs++] = ord(A[y] + i);
    }
    for(i=(-1);i<(2);i++){
      int j;
      for(j=(-1);j<(2);j++){
        g =GCD_L(A[x]+i, A[y]+j);
        f[fs++] = ord(g);
      }
    }
    for(ZIeRIny5=(0);ZIeRIny5<(fs);ZIeRIny5++){
      int j;
      auto &p = f[ZIeRIny5];
      if(chk.count(p)){
        continue;
      }
      chk.insert(p);
      tmp = 0;
      for(j=(0);j<(N);j++){
        if(A[j] <= p){
          tmp += p - A[j];
        }
        else{
          r = A[j] % p;
          tmp +=min_L(r, p-r);
        }
        if(tmp >= res){
          break;
        }
      }
      chmin(res, tmp);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200303-1 [beta]

// --- original code ---
// //no-unlocked
// int N; ll A[2d5];
// int fs; ll f[100];
// 
// ll ord(ll x){
//   while(x > 0 && x % 2 == 0) x /= 2;
//   while(x > 0 && x % 3 == 0) x /= 3;
//   while(x > 0 && x % 5 == 0) x /= 5;
//   while(x > 0 && x % 7 == 0) x /= 7;
//   return x;
// }
// 
// {
//   int x, y, res, ft = 1;
//   ll tmp, p, r, g;
//   Rand rnd;
//   Timer timer;
//   set<ll> chk;
// 
//   timer.set();
//   chk.insert(0LL);
//   chk.insert(1LL);
// 
//   rd(N,A(N));
//   res = N;
// 
//   while(timer.get() < 2){
//     x = rnd.get(N);
//     y = rnd.get(N);
//     fs = 0;
// 
//     if(ft){
//       f[fs++] = 2;
//       f[fs++] = 3;
//       f[fs++] = 5;
//       f[fs++] = 7;
//       ft = 0;
//     }
// 
//     rep(i,-1,2){
//       f[fs++] = ord(A[x] + i);
//       f[fs++] = ord(A[y] + i);
//     }
//     rep(i,-1,2) rep(j,-1,2){
//       g = gcd(A[x]+i, A[y]+j);
//       f[fs++] = ord(g);
//     }
// 
//     rep[f](p,fs){
//       if(chk.count(p)) continue;
//       chk.insert(p);
//       tmp = 0;
//       rep(j,N){
//         if(A[j] <= p){
//           tmp += p - A[j];
//         } else {
//           r = A[j] % p;
//           tmp += min(r, p-r);
//         }
//         if(tmp >= res) break;
//       }
//       res <?= tmp;
//     }
//   }
//   wt(res);
// }