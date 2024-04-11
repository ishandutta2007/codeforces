#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
int N;
int L;
int A[100000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    double sx;
    double sy;
    double x;
    double y;
    double res = 0;
    double tm;
    rd(N);
    rd(L);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    i = 0;
    j = N-1;
    x = 0;
    y = L;
    sx = 1;
    sy = 1;
    while(i <= j){
      if( (A[i] - x) / sx <= (y - A[j]) / sy ){
        res += tm = (A[i] - x) / sx;
        x += tm * sx;
        y -= tm * sy;
        i++;
        sx++;
      }
      else{
        res += tm = (y - A[j]) / sy;
        x += tm * sx;
        y -= tm * sy;
        j--;
        sy++;
      }
    }
    res += (y - x) / (sx + sy);
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20201003-1

// --- original code ---
// //no-unlocked
// int N, L, A[1d5];
// {
//   REP(rd_int()){
//     int i, j;
//     double sx, sy, x, y, res = 0, tm;
//     rd(N,L,A(N));
// 
//     i = 0; j = N-1;
//     x = 0; y = L;
//     sx = 1; sy = 1;
// 
//     while(i <= j){
//       if( (A[i] - x) / sx <= (y - A[j]) / sy ){
//         res += tm = (A[i] - x) / sx;
//         x += tm * sx;
//         y -= tm * sy;
//         i++;
//         sx++;
//       } else {
//         res += tm = (y - A[j]) / sy;
//         x += tm * sx;
//         y -= tm * sy;
//         j--;
//         sy++;
//       }
//     }
//     res += (y - x) / (sx + sy);
//     wt(res);
//   }
// }