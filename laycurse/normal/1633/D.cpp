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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
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
template<class T> inline T pow2_L(T a){
  return a*a;
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
inline long long Isqrt_f_L(const long long n){
  long long r = sqrt(n);
  r =max_L(r-2, 0);
  while((pow2_L((r+1)))<= n ){
    r++;
  }
  return r;
}
int main(){
  int OA9NF42T;
  int N;
  int K;
  int B[1000];
  int C[1000];
  int i;
  int j;
  int k;
  int m;
  int dp[30001];
  int cdp[1000000+1];
  for(i=(0);i<(1000000+1);i++){
    cdp[i] = 1073709056;
  }
  cdp[1] = 0;
  for(i=(1);i<(1000000+1);i++){
    k =Isqrt_f_L(i);
    for(j=(1);j<(k+1);j++){
      m = i + j;
      if(m > 1000000){
        break;
      }
      chmin(cdp[m], cdp[i] + 1);
    }
    for(j=(k+1)-1;j>=(1);j--){
      m = i + (double)i / j;
      if(m > 1000000){
        break;
      }
      chmin(cdp[m], cdp[i] + 1);
    }
  }
  int ATMZloZo = rd_int();
  for(OA9NF42T=(0);OA9NF42T<(ATMZloZo);OA9NF42T++){
    rd(N);
    rd(K);
    {
      int QBN4sCMC;
      for(QBN4sCMC=(0);QBN4sCMC<(N);QBN4sCMC++){
        rd(B[QBN4sCMC]);
      }
    }
    {
      int myTeyldV;
      for(myTeyldV=(0);myTeyldV<(N);myTeyldV++){
        rd(C[myTeyldV]);
      }
    }
    chmin(K, N * 30);
    for(i=(0);i<(K+1);i++){
      dp[i] = 0;
    }
    for(k=(0);k<(N);k++){
      m = cdp[B[k]];
      for(i=(K+1)-1;i>=(m);i--){
        chmax(dp[i], dp[i-m] + C[k]);
      }
    }
    wt_L(dp[K]);
    wt_L('\n');
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220116-1 [+beta]

// --- original code ---
// //no-unlocked
// int N, K, B[1000], C[1000];
// int i, j, k, m, dp[30001], cdp[1d6+1];
// 
// rep(i,1d6+1) cdp[i] = int_inf;
// cdp[1] = 0;
// rep(i,1,1d6+1){
//   k = Isqrt(i);
//   rep(j,1,k+1){
//     m = i + j;
//     if(m > 1d6) break;
//     cdp[m] <?= cdp[i] + 1;
//   }
//   rrep(j,1,k+1){
//     m = i + (double)i / j;
//     if(m > 1d6) break;
//     cdp[m] <?= cdp[i] + 1;
//   }
// }
// 
// REP(rd_int()){
//   rd(N,K,B(N),C(N));
//   K <?= N * 30;
//   rep(i,K+1) dp[i] = 0;
//   rep(k,N){
//     m = cdp[B[k]];
//     rrep(i,m,K+1) dp[i] >?= dp[i-m] + C[k];
//   }
//   wt(dp[K]);
// }