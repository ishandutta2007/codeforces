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
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int N;
    rd(N);
    int A;
    rd(A);
    int B;
    rd(B);
    int res[N];
    int m;
    if(A+B > N-2){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(N);i++){
      res[i] = i;
    }
    if(A==B+1){
      for(i=(0);i<(B+1);i++){
        swap(res[2*i+1], res[2*i+2]);
      }
      for(i=(2*B+3);i<(N);i++){
        res[i] = 2*B+3 - i - 1;
      }
    }
    else if(A==B || A==B-1){
      for(i=(0);i<(B);i++){
        swap(res[2*i], res[2*i+1]);
      }
      if(A==B){
        swap(res[2*B], res[2*B+1]);
        for(i=(2*B+2);i<(N);i++){
          res[i] = 2*B+2 - i - 1;
        }
      }
    }
    else{
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    int hCmBdyQB;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type V9aVTaxx;
    if(N==0){
      V9aVTaxx = 0;
    }
    else{
      V9aVTaxx = res[0];
      for(hCmBdyQB=(1);hCmBdyQB<(N);hCmBdyQB++){
        V9aVTaxx = min_L(V9aVTaxx, res[hCmBdyQB]);
      }
    }
    m =V9aVTaxx;
    for(i=(0);i<(N);i++){
      res[i] -= m - 1;
    }
    {
      int ZIeRIny5;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(ZIeRIny5=(0);ZIeRIny5<(N-1);ZIeRIny5++){
          wt_L(res[ZIeRIny5]);
          wt_L(' ');
        }
        wt_L(res[ZIeRIny5]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20211024-1 [beta]

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N, @A, @B, res[N], m;
//   if(A+B > N-2) wt(-1), continue;
//   rep(i,N) res[i] = i;
//   if(A==B+1){
//     rep(i,B+1) swap(res[2*i+1], res[2*i+2]);
//     rep(i,2*B+3,N) res[i] = 2*B+3 - i - 1;
//   } else if(A==B || A==B-1){
//     rep(i,B) swap(res[2*i], res[2*i+1]);
//     if(A==B){
//       swap(res[2*B], res[2*B+1]);
//       rep(i,2*B+2,N) res[i] = 2*B+2 - i - 1;
//     }
//   } else {
//     wt(-1), continue;
//   }
//   m = min(res(N));
//   rep(i,N) res[i] -= m - 1;
//   wt(res(N));
// }