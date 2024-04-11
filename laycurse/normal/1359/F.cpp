#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
}
template<class T> inline T pow2_L(T a){
  return a*a;
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
long long crossProd_L(long long x1, long long y1, long long x2, long long y2){
  return x1 * y2 - x2 * y1;
}
#define EPS 1e-9
int N;
int X[25000];
int Y[25000];
int DX[25000];
int DY[25000];
int S[25000];
int nx[25000];
int ny[25000];
long long p[25000];
int gcd_memo[2001][2001];
int main(){
  int i;
  int dx;
  int dy;
  int g;
  int s1;
  int s2;
  double res = 1e150;
  double d;
  double x;
  double y;
  double d1;
  double d2;
  for(i=(0);i<(2001);i++){
    int j;
    for(j=(0);j<(2001);j++){
      if(i||j){
        gcd_memo[i][j] =GCD_L(i, j);
      }
    }
  }
  rd(N);
  {
    int RZTsC2BF;
    for(RZTsC2BF=(0);RZTsC2BF<(N);RZTsC2BF++){
      rd(X[RZTsC2BF]);
      rd(Y[RZTsC2BF]);
      rd(DX[RZTsC2BF]);
      rd(DY[RZTsC2BF]);
      rd(S[RZTsC2BF]);
    }
  }
  for(i=(0);i<(N);i++){
    g =GCD_L(abs(DX[i]), abs(DY[i]));
    {
      auto ao_dF3pO = (g);
      DX[i] /= ao_dF3pO;
      DY[i] /= ao_dF3pO;
    }
  }
  for(i=(0);i<(N);i++){
    {
      auto hCmBdyQB = (X[i]+DX[i]);
      auto V9aVTaxx = ( Y[i]+DY[i]);
      nx[i] = hCmBdyQB;
      ny[i] = V9aVTaxx;
    }
  }
  for(i=(0);i<(N);i++){
    p[i] = X[i] * ny[i] - Y[i] * nx[i];
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i+1);j<(N);j++){
      if(crossProd_L(DX[i],DY[i],DX[j],DY[j])==0){
        dx = X[j] - X[i];
        dy = Y[j] - Y[i];
        g = gcd_memo[abs(dx)][abs(dy)];
        {
          auto AlM5nNnR = (g);
          dx /= AlM5nNnR;
          dy /= AlM5nNnR;
        }
        s1 = s2 = 0;
        if(dx==DX[i] && dy==DY[i]){
          s1 = S[i];
        }
        if(dx==-DX[j] && dy==-DY[j]){
          s2 = S[j];
        }
        if(s1+s2 <= 0){
          continue;
        }
        d =(pow2_L((X[j]-X[i])))+(pow2_L((Y[j]-Y[i])));
        chmin(res, d / ((s1+s2)*(s1+s2)));
      }
      else{
        x = y = 1.0 / (DY[j] * DX[i] - DY[i] * DX[j]);
        x *= p[j] * DX[i] - p[i] * DX[j];
        y *= p[j] * DY[i] - p[i] * DY[j];
        if( (x-X[i])*DX[i] < 0 || (x-X[j])*DX[j] < 0 ){
          continue;
        }
        d1 =(pow2_L((x-X[i])))+(pow2_L((y-Y[i])));
        d2 =(pow2_L((x-X[j])))+(pow2_L((y-Y[j])));
        chmin(res, max_L(d1/(S[i]*S[i]), d2/(S[j]*S[j])));
      }
    }
  }
  if(res==1e150){
    wt_L("No show :(");
    wt_L('\n');
  }
  else{
    wt_L(sqrt(res));
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// #define EPS 1e-9
// 
// int N, X[25000], Y[25000], DX[25000], DY[25000], S[25000];
// int nx[25000], ny[25000]; ll p[25000];
// int gcd_memo[2001][2001];
// {
//   int dx, dy, g, s1, s2;
//   double res = double_inf;
//   double d, x, y, d1, d2;
// 
//   rep(i,2001) rep(j,2001) if(i||j) gcd_memo[i][j] = gcd(i,j);
// 
//   rd(N,(X,Y,DX,DY,S)(N));
// 
//   rep(i,N){
//     g = gcd(abs(DX[i]), abs(DY[i]));
//     (DX[i], DY[i]) /= g;
//   }
//   rep(i,N) (nx[i],ny[i]) = (X[i]+DX[i], Y[i]+DY[i]);
//   rep(i,N) p[i] = X[i] * ny[i] - Y[i] * nx[i];
// 
//   rep(i,N) rep(j,i+1,N){
//     if(crossProd(DX[i],DY[i],DX[j],DY[j])==0){
//       dx = X[j] - X[i];
//       dy = Y[j] - Y[i];
//       g = gcd_memo[abs(dx)][abs(dy)];
//       (dx, dy) /= g;
//       s1 = s2 = 0;
//       if(dx==DX[i] && dy==DY[i]) s1 = S[i];
//       if(dx==-DX[j] && dy==-DY[j]) s2 = S[j];
//       if(s1+s2 <= 0) continue;
//       d = (X[j]-X[i])**2 + (Y[j]-Y[i])**2;
//       res <?= d / ((s1+s2)*(s1+s2));
//     } else {
//       x = y = 1.0 / (DY[j] * DX[i] - DY[i] * DX[j]);
//       x *= p[j] * DX[i] - p[i] * DX[j];
//       y *= p[j] * DY[i] - p[i] * DY[j];
//       if( (x-X[i])*DX[i] < 0 || (x-X[j])*DX[j] < 0 ) continue;
//       d1 = (x-X[i])**2 + (y-Y[i])**2;
//       d2 = (x-X[j])**2 + (y-Y[j])**2;
//       res <?= max(d1/(S[i]*S[i]), d2/(S[j]*S[j]));
//     }
//   }
// 
//   wt(if[res==double_inf, "No show :(", sqrt(res)]);
// }