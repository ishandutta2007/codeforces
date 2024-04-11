#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
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
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int N;
    rd(N);
    int M;
    rd(M);
    long long A[N];
    long long B[N];
    long long x[N];
    long long y[N];
    long long s;
    long long t;
    long long u;
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
        rd(B[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      x[i] =max_L(0, M - B[i]);
      y[i] =max_L(0, M - A[i]);
    }
    int ao_dF3pO;
    remove_reference<decltype( (A[ao_dF3pO]-x[ao_dF3pO]) - (B[ao_dF3pO]-y[ao_dF3pO]) )>::type tU__gIr_;
    int a2conNHc = 0;
    if((0) > ((N)-1)){
      tU__gIr_ = 0;
    }
    else{
      for(ao_dF3pO = 0; ao_dF3pO <= (N)-1; ao_dF3pO++){
        if(a2conNHc == 0){
          tU__gIr_ =  (A[ao_dF3pO]-x[ao_dF3pO]) - (B[ao_dF3pO]-y[ao_dF3pO]) ;
          a2conNHc = 1;
          continue;
        }
        tU__gIr_ +=  (A[ao_dF3pO]-x[ao_dF3pO]) - (B[ao_dF3pO]-y[ao_dF3pO]) ;
      }
      if(a2conNHc==0){
        tU__gIr_ = 0;
      }
    }
    s =tU__gIr_;
    for(i=(0);i<(N);i++){
      t = M - x[i] - y[i];
      if(s > 0){
        auto iMWUTgY_ = ((1)*min_L(t, s));
        auto AlM5nNnR = (( -1)*min_L(t, s));
        auto XJIcIBrW = (( -1)*min_L(t, s));
        x[i]+=iMWUTgY_;
        t+=AlM5nNnR;
        s+=XJIcIBrW;
      }
      if(s < 0){
        auto BUotOFBp = ((1)*min_L(t, -s));
        auto Q5rsz4fz = (( -1)*min_L(t, -s));
        auto GgkpftXM = ((  1)*min_L(t, -s));
        y[i]+=BUotOFBp;
        t+=Q5rsz4fz;
        s+=GgkpftXM;
      }
      u = t / 2;
      auto gEg5UqEA = ((1)* u);
      auto qSsg05KM = (( -1)* u);
      auto Hjfu7Vx7 = (( -1)* u);
      x[i]+=gEg5UqEA;
      t+=qSsg05KM;
      s+=Hjfu7Vx7;
      auto zT28qSmp = ((1)* t);
      auto aTqQ6rt8 = (( -1)* t);
      auto X9Iss0pP = ((  1)* t);
      y[i]+=zT28qSmp;
      t+=aTqQ6rt8;
      s+=X9Iss0pP;
    }
    wt_L(abs(s));
    wt_L('\n');
    for(i=(0);i<(N);i++){
      wt_L(x[i]);
      wt_L(' ');
      wt_L(y[i]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20211024-1

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N, @M; ll A[N], B[N], x[N], y[N], s, t, u;
//   rd((A,B)(N));
//   rep(i,N){
//     x[i] = max(0, M - B[i]);
//     y[i] = max(0, M - A[i]);
//   }
//   s = sum[i,0,N]( (A[i]-x[i]) - (B[i]-y[i]) );
//   rep(i,N){
//     t = M - x[i] - y[i];
//     if(s > 0) (x[i], t, s) += (1, -1, -1) * min(t, s);
//     if(s < 0) (y[i], t, s) += (1, -1,  1) * min(t, -s);
//     u = t / 2;
//     (x[i], t, s) += (1, -1, -1) * u;
//     (y[i], t, s) += (1, -1,  1) * t;
//   }
//   wt(abs(s));
//   rep(i,N) wt(x[i], y[i]);
// }