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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
inline void wt_L(char a){
  my_putchar(a);
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int main(){
  int Nzj9Y0kE;
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int i;
    int N;
    rd(N);
    long long X;
    rd(X);
    long long A[N];
    {
      int om7Ebh6q;
      for(om7Ebh6q=(0);om7Ebh6q<(N);om7Ebh6q++){
        rd(A[om7Ebh6q]);
      }
    }
    long long mx[N+1];
    long long res[N+1];
    long long t;
    for(i=(0);i<(N+1);i++){
      mx[i] = -4611686016279904256LL;
    }
    for(i=(0);i<(N);i++){
      int j;
      t = 0;
      chmax(mx[0], t);
      for(j=(i);j<(N);j++){
        t += A[j];
        chmax(mx[j-i+1], t);
      }
    }
    for(i=(0);i<(N+1);i++){
      int myTeyldV;
      remove_reference<decltype(mx[myTeyldV]+X*i)>::type PON0fmpo;
      int QDGVCdl1 = 0;
      if((0) > ((N+1)-1)){
        PON0fmpo = numeric_limits<remove_reference<decltype(mx[myTeyldV]+X*i)>::type>::lowest();
      }
      else{
        for(myTeyldV = 0; myTeyldV <= (N+1)-1; myTeyldV++){
          if(QDGVCdl1 == 0){
            PON0fmpo = mx[myTeyldV]+X*min_L(i, myTeyldV);
            QDGVCdl1 = 1;
            continue;
          }
          const auto ClGtuHe4 = mx[myTeyldV]+X*min_L(i, myTeyldV);
          if(PON0fmpo < ClGtuHe4){
            PON0fmpo = ClGtuHe4;
          }
        }
        if(QDGVCdl1==0){
          PON0fmpo = numeric_limits<remove_reference<decltype(mx[myTeyldV]+X*i)>::type>::lowest();
        }
      }
      res[i] =PON0fmpo;
    }
    {
      int a3zq_coq;
      if(N+1==0){
        wt_L('\n');
      }
      else{
        for(a3zq_coq=(0);a3zq_coq<(N+1-1);a3zq_coq++){
          wt_L(res[a3zq_coq]);
          wt_L(' ');
        }
        wt_L(res[a3zq_coq]);
        wt_L('\n');
      }
    }
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
// REP(rd_int()){
//   int @N; ll @X, @A[N], mx[N+1], res[N+1], t;
//   rep(i,N+1) mx[i] = -ll_inf;
//   rep(i,N){
//     t = 0;
//     mx[0] >?= t;
//     rep(j,i,N){
//       t += A[j];
//       mx[j-i+1] >?= t;
//     }
//   }
//   rep(i,N+1) res[i] = max[j,0,N+1](mx[j]+X*min(i,j));
//   wt(res(N+1));
// }