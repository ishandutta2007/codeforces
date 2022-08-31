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
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    long long X;
    rd(X);
    long long Y;
    rd(Y);
    long long A;
    rd(A);
    long long B;
    rd(B);
    long long res = 0;
    long long tmp;
    if(X > Y){
      swap(X, Y);
    }
    ;
    if(A > B){
      swap(A, B);
    }
    ;
    if(A == B){
      wt_L(X/A);
      wt_L('\n');
      continue;
    }
    ;
    tmp =min_L(min_L((Y-X) / (B-A), X/A), Y/B);
    auto RZTsC2BF = (tmp * (-A));
    auto FmcKpFmN = (tmp * ( -B));
    auto xr20shxY = (tmp * ( 1));
    X+=RZTsC2BF;
    Y+=FmcKpFmN;
    res+=xr20shxY;
    tmp = X / (A+B);
    auto WYIGIcGE = (tmp * (-A-B));
    auto t_ynMSdg = (tmp * ( -A-B));
    auto KrdatlYV = (tmp * ( 2));
    X+=WYIGIcGE;
    Y+=t_ynMSdg;
    res+=KrdatlYV;
    for(;;){
      if(X > Y){
        swap(X, Y);
      }
      ;
      if(A > B){
        swap(A, B);
      }
      ;
      if(X < A || Y < B){
        break;
      }
      auto a2conNHc = ((-A));
      auto hCmBdyQB = (( -B));
      auto V9aVTaxx = (( 1));
      X+=a2conNHc;
      Y+=hCmBdyQB;
      res+=V9aVTaxx;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210607-1

// --- original code ---
// //no-unlocked
// {
//   REP(rd_int()){
//     ll @X, @Y, @A, @B, res = 0, tmp;
//     sortE(X,Y);
//     sortE(A,B);
//     if(A == B) wt(X/A), continue;;
// 
//     tmp = min((Y-X) / (B-A), X/A, Y/B);
//     (X, Y, res) += tmp * (-A, -B, 1);
// 
//     tmp = X / (A+B);
//     (X, Y, res) += tmp * (-A-B, -A-B, 2);
// 
//     for(;;){
//       sortE(X,Y);
//       sortE(A,B);
//       if(X < A || Y < B) break;
//       (X, Y, res) += (-A, -B, 1);
//     }
// 
//     wt(res);
//   }
// }