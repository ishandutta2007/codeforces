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
    int N;
    rd(N);
    long long H[N];
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(H[cTE1_r3A]);
      }
    }
    long long cur[N];
    long long res;
    long long mn;
    long long v;
    long long xr20shxY;
    long long WYIGIcGE;
    long long t_ynMSdg;
    xr20shxY = 0;
    WYIGIcGE = 1000000000;
    while(xr20shxY < WYIGIcGE){
      int i;
      if((xr20shxY + WYIGIcGE)%2==0){
        t_ynMSdg = (xr20shxY + WYIGIcGE) / 2;
      }
      else{
        t_ynMSdg = (xr20shxY + WYIGIcGE + 1) / 2;
      }
      for(i=(0);i<(N);i++){
        cur[i] = H[i];
      }
      for(i=(N)-1;i>=(2);i--){
        v =min_L(H[i], cur[i] - t_ynMSdg);
        if(v < 0){
          break;
        }
        v /= 3;
        auto YREPHmFM = ((2)* v);
        auto jZyWAPpY = ((1)* v);
        auto jbtyPBGc = ((-3)* v);
        cur[i-2]+=YREPHmFM;
        cur[i-1]+=jZyWAPpY;
        cur[i]+=jbtyPBGc;
      }
      int ZIeRIny5;
      cLtraits_try_make_signed<remove_reference<decltype((*((long long*)NULL)))>::type>::type iMWUTgY_;
      if(N==0){
        iMWUTgY_ = 0;
      }
      else{
        iMWUTgY_ = cur[0];
        for(ZIeRIny5=(1);ZIeRIny5<(N);ZIeRIny5++){
          iMWUTgY_ = min_L(iMWUTgY_, cur[ZIeRIny5]);
        }
      }
      mn =iMWUTgY_;
      if(mn >= t_ynMSdg){
        xr20shxY = t_ynMSdg;
      }
      else{
        WYIGIcGE = t_ynMSdg - 1;
      }
    }
    res =WYIGIcGE;
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20211229-1

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N; ll @H[N], cur[N], res, mn, v;
//   res = bsearch_max[ll,x,0,1d9][
//     rep(i,N) cur[i] = H[i];
//     rrep(i,2,N){
//       v = min(H[i], cur[i] - x);
//       if(v < 0) break;
//       v /= 3;
//       (cur[i-2], cur[i-1], cur[i]) += (2,1,-3) * v;
//     }
//     mn = min(cur(N));
//   ](mn >= x);
//   wt(res);
// }