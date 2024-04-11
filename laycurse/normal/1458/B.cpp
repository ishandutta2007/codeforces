#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[100];
int B[100];
double res[100];
double dp[101][10001];
int main(){
  int i, k;
  double sb;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
      rd(B[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    int cTE1_r3A;
    if(N==0){
      cTE1_r3A = 0;
    }
    else{
      cTE1_r3A = B[0];
      for(e98WHCEY=(1);e98WHCEY<(N);e98WHCEY++){
        cTE1_r3A += B[e98WHCEY];
      }
    }
    sb =cTE1_r3A;
  }
  for(i=(0);i<(101);i++){
    int j;
    for(j=(0);j<(10001);j++){
      dp[i][j] = -1073709056;
    }
  }
  dp[0][0] = 0;
  for(k=(0);k<(N);k++){
    for(i=(k+1)-1;i>=(0);i--){
      int j;
      for(j=(0);j<(100*i+1);j++){
        chmax(dp[i+1][j+A[k]], dp[i][j] + B[k]);
      }
    }
  }
  for(i=(1);i<(N+1);i++){
    int j;
    for(j=(0);j<(10001);j++){
      if(dp[i][j] >= 0){
        chmax(res[i-1], min_L(dp[i][j] + (sb - dp[i][j]) / 2.0, j));
      }
    }
  }
  {
    int AlM5nNnR;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(AlM5nNnR=(0);AlM5nNnR<(N-1);AlM5nNnR++){
        wt_L(res[AlM5nNnR]);
        wt_L(' ');
      }
      wt_L(res[AlM5nNnR]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20201229-1

// --- original code ---
// //no-unlocked
// int N; int A[100], B[100];
// double res[100], dp[101][10001];
// {
//   double sb;
//   rd(N,(A,B)(N));
//   sb = sum(B(N));
//   rep(i,101) rep(j,10001) dp[i][j] = -int_inf;
//   dp[0][0] = 0;
//   rep(k,N) rrep(i,k+1) rep(j,100*i+1) dp[i+1][j+A[k]] >?= dp[i][j] + B[k];
//   rep(i,1,N+1) rep(j,10001) if(dp[i][j] >= 0) res[i-1] >?= min(dp[i][j] + (sb - dp[i][j]) / 2.0, j);
//   wt(res(N));
// }