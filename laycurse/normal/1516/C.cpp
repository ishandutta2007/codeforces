#pragma GCC optimize ("Ofast")
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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
int N;
int A[100];
int dp[200000+1];
int sm;
int d;
int main(){
  int i;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  d = 2048;
  for(i=(0);i<(N);i++){
    d =GCD_L(d, A[i]);
  }
  for(i=(0);i<(N);i++){
    A[i] /= d;
  }
  dp[0] = 1;
  for(i=(0);i<(N);i++){
    int j;
    for(j=(200000+1)-1;j>=(A[i]);j--){
      dp[j] |= dp[j-A[i]];
    }
  }
  int tU__gIr_;
  cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type a2conNHc;
  if(N==0){
    a2conNHc = 0;
  }
  else{
    a2conNHc = A[0];
    for(tU__gIr_=(1);tU__gIr_<(N);tU__gIr_++){
      a2conNHc += A[tU__gIr_];
    }
  }
  sm =a2conNHc;
  if(sm%2 || dp[sm/2]==0){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N);i++){
    if(A[i] % 2){
      wt_L(1);
      wt_L('\n');
      wt_L(i+1);
      wt_L('\n');
      break;
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N, A[100];
// int dp[2d5+1], sm, d;
// {
//   rd(N,A(N));
//   d = 2048;
//   rep(i,N) d = gcd(d, A[i]);
//   rep(i,N) A[i] /= d;
// 
//   dp[0] = 1;
//   rep(i,N) rrep(j,A[i],2d5+1) dp[j] |= dp[j-A[i]];
//   sm = sum(A(N));
//   if(sm%2 || dp[sm/2]==0) wt(0), return 0;
// 
//   rep(i,N) if(A[i] % 2) wtLn(1,i+1), break;
// }