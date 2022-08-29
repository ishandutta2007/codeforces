#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
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
double solve(int n, double th){
  int i;
  double x = 0;
  double y = 0;
  double x1 = 0;
  double x2 = 0;
  double y1 = 0;
  double y2 = 0;
  for(i=(0);i<(2*n);i++){
    x += sin(th+PI*i/n);
    y += cos(th+PI*i/n);
    {
      auto Q5VJL1cS = (x);
      auto e98WHCEY = ( y);
      chmin(x1, Q5VJL1cS);
      chmin(y1, e98WHCEY);
    }
    {
      auto cTE1_r3A = (x);
      auto RZTsC2BF = ( y);
      chmax(x2, cTE1_r3A);
      chmax(y2, RZTsC2BF);
    }
  }
  return max_L(x2-x1, y2-y1);
}
int main(){
  int xr20shxY;
  int WYIGIcGE = rd_int();
  for(xr20shxY=(0);xr20shxY<(WYIGIcGE);xr20shxY++){
    int ao_dF3pO;
    int N = rd_int();
    double res;
    double x;
    double y;
    double z1;
    double z2;
    double t1;
    double t2;
    x = 0;
    y = PI / 4 / N;
    for(ao_dF3pO=(0);ao_dF3pO<(200);ao_dF3pO++){
      z1 = (x+x+y) / 3;
      z2 = (x+y+y) / 3;
      t1 = solve(N, z1);
      t2 = solve(N, z2);
      if(t1 > t2){
        x = z1;
      }
      else{
        y = z2;
      }
    }
    res = solve(N, (z1+z2)/2);
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// 
// double solve(int n, double th){
//   double x = 0, y = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;
//   rep(i,2*n){
//     x += sin(th+PI*i/n);
//     y += cos(th+PI*i/n);
//     (x1, y1) <?= (x, y);
//     (x2, y2) >?= (x, y);
//   }
//   return max(x2-x1, y2-y1);
// }
// 
// {
//   REP(rd_int()){
//     int N = rd_int();
//     double res, x, y, z1, z2, t1, t2;
//     x = 0;
//     y = PI / 4 / N;
//     rep(200){
//       z1 = (x+x+y) / 3;
//       z2 = (x+y+y) / 3;
//       t1 = solve(N, z1);
//       t2 = solve(N, z2);
//       if[t1 > t2, x = z1, y = z2];
//     }
//     res = solve(N, (z1+z2)/2);
//     wt(res);
//   }
// }