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
int res[200000+1];
int ress;
int arr[200000+1];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int FmcKpFmN, i;
    int A;
    rd(A);
    int B;
    rd(B);
    int n1;
    int n2;
    int mn;
    int mx;
    for(i=(0);i<(A+B+1);i++){
      arr[i] = 0;
    }
    n1 = (A+B) / 2;
    n2 = (A+B) - n1;
    for(FmcKpFmN=(0);FmcKpFmN<(2);FmcKpFmN++){
      swap(n1,n2);
      mn =max_L(0, A-n2)+max_L(0, B-n1);
      mx =min_L(n1, A)+min_L(n2, B);
      for(i=(mn);i<(mx+1);i+=(2)){
        arr[i] = 1;
      }
    }
    ress = 0;
    for(i=(0);i<(A+B+1);i++){
      if(arr[i]){
        res[ress++] = i;
      }
    }
    wt_L(ress);
    wt_L('\n');
    {
      int YREPHmFM;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(YREPHmFM=(0);YREPHmFM<(ress-1);YREPHmFM++){
          wt_L(res[YREPHmFM]);
          wt_L(' ');
        }
        wt_L(res[YREPHmFM]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210819-1 [beta]

// --- original code ---
// //no-unlocked
// int res[2d5+1];
// int ress, arr[];
// {
//   REP(rd_int()){
//     int @A, @B, n1, n2, mn, mx;
//     rep(i,A+B+1) arr[i] = 0;
// 
//     n1 = (A+B) / 2;
//     n2 = (A+B) - n1;
//     rep(2){
//       swap(n1,n2);
//       mn = max(0, A-n2) + max(0, B-n1);
//       mx = min(n1, A) + min(n2, B);
//       rep(i,mn,mx+1,2) arr[i] = 1;
//     }
// 
//     ress = 0;
//     rep(i,A+B+1) if(arr[i]) res[ress++] = i;
//     wt(ress);
//     wt(res(ress));
//   }
// }