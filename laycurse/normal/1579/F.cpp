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
template<class T, class S> int arrCountVal(int N, T A[], S val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
template<class S> int arrCountVal(string A, S val){
  int i;
  int res = 0;
  for(i=(0);i<(A.size());i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int D;
int A[1000000];
int B[1000000];
int solve(int N, int A[]){
  int i;
  int mx = 0;
  int now = 0;
  if(arrCountVal(N,A,0)==0){
    return 1073709056;
  }
  for(i=(0);i<(2*N);i++){
    if(A[i%N] == 0){
      now = 0;
      continue;
    }
    now++;
    chmax(mx, now);
  }
  return mx;
}
int main(){
  int Q5VJL1cS;
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int res = 0;
    int g;
    int n;
    int i;
    int j;
    rd(N);
    rd(D);
    {
      int FmcKpFmN;
      for(FmcKpFmN=(0);FmcKpFmN<(N);FmcKpFmN++){
        rd(A[FmcKpFmN]);
      }
    }
    g =GCD_L(N, D);
    for(i=(0);i<(g);i++){
      n = 0;
      for(j=(0);j<(N/g);j++){
        B[j] = A[(i+(long long)D*j)%N];
      }
      chmax(res, solve(N/g, B));
    }
    if(res==1073709056){
      wt_L(-1);
      wt_L('\n');
    }
    else{
      wt_L(res);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int N, D, A[1d6], B[];
// 
// int solve(int N, int A[]){
//   int mx = 0, now = 0;
//   if(arrCountVal(N,A,0)==0) return int_inf;
//   rep(i,2*N){
//     if(A[i%N] == 0) now = 0, continue;
//     now++;
//     mx >?= now;
//   }
//   return mx;
// }
// 
// {
//   REP(rd_int()){
//     int res = 0, g, n, i, j;
//     rd(N,D,A(N));
//     g = gcd(N,D);
//     rep(i,g){
//       n = 0;
//       rep(j,N/g) B[j] = A[(i+(ll)D*j)%N];
//       res >?= solve(N/g, B);
//     }
// 
//     wt(if[res==int_inf, -1, res]);
//   }
// }