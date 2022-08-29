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
int N;
int As;
int Bs;
int A[200000];
int B[200000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int FmcKpFmN, t_ynMSdg;
    int i;
    int j;
    int k;
    int res = 0;
    rd(N);
    rd(As);
    rd(Bs);
    for(i=(0);i<(N);i++){
      A[i] = B[i] = 0;
    }
    for(FmcKpFmN=(0);FmcKpFmN<(As);FmcKpFmN++){
      A[rd_int()-1]++;
    }
    for(t_ynMSdg=(0);t_ynMSdg<(Bs);t_ynMSdg++){
      B[rd_int()-1]++;
    }
    for(i=(0);i<(N);i++){
      k =min_L(A[i], B[i]);
      auto V9aVTaxx = (k);
      As-=V9aVTaxx;
      Bs-=V9aVTaxx;
      A[i]-=V9aVTaxx;
      B[i]-=V9aVTaxx;
    }
    for(i=(0);i<(N);i++){
      while(As > Bs && A[i] >= 2){
        res++;
        auto ZIeRIny5 = (2);
        As-=ZIeRIny5;
        A[i]-=ZIeRIny5;
      }
    }
    for(i=(0);i<(N);i++){
      while(Bs > As && B[i] >= 2){
        res++;
        auto BUotOFBp = (2);
        Bs-=BUotOFBp;
        B[i]-=BUotOFBp;
      }
    }
    k =min_L(As, Bs);
    auto GgkpftXM = (k);
    As-=GgkpftXM;
    Bs-=GgkpftXM;
    res += k;
    res += As + Bs;
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210502-1 [beta]

// --- original code ---
// //no-unlocked
// int N, As, Bs, A[2d5], B[2d5];
// {
//   REP(rd_int()){
//     int i, j, k, res = 0;
//     rd(N,As,Bs);
//     rep(i,N) A[i] = B[i] = 0;
//     rep(As) A[rd_int()-1]++;
//     rep(Bs) B[rd_int()-1]++;
//     rep(i,N){
//       k = min(A[i], B[i]);
//       (As, Bs, A[i], B[i]) -= k;
//     }
//     rep(i,N) while(As > Bs && A[i] >= 2) res++, (As, A[i]) -= 2;
//     rep(i,N) while(Bs > As && B[i] >= 2) res++, (Bs, B[i]) -= 2;
//     k = min(As, Bs);
//     (As, Bs) -= k;
//     res += k;
//     res += As + Bs;
//     wt(res);
//   }
// }