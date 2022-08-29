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
template<class S> S arrErase(int k, int &sz, S a[]){
  int i;
  S res;
  res = a[k];
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  return res;
}
template<class S, class T> void arrErase(int k, int &sz, S a[], T b[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
}
template<class S, class T, class U> void arrErase(int k, int &sz, S a[], T b[], U c[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
  for(i=(k);i<(sz);i++){
    c[i] = c[i+1];
  }
}
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int main(){
  int Nzj9Y0kE;
  int N;
  int D;
  int A[200000+2];
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int x;
    int res;
    int mn;
    int mx;
    int ind;
    int val;
    rd(N);
    rd(D);
    {
      int om7Ebh6q;
      for(om7Ebh6q=(0);om7Ebh6q<(N);om7Ebh6q++){
        rd(A[om7Ebh6q]);
      }
    }
    arrInsert(0,N,A,0);
    int YGwFZBGH;
    remove_reference<decltype(A[YGwFZBGH]-A[YGwFZBGH-1])>::type OA9NF42T;
    int ATMZloZo = 0;
    int pyHJGNQc;
    if((1) > ((N)-1)){
      OA9NF42T = 0;
    }
    else{
      for(YGwFZBGH = 1; YGwFZBGH <= (N)-1; YGwFZBGH++){
        if(ATMZloZo == 0){
          OA9NF42T = A[YGwFZBGH]-A[YGwFZBGH-1];
          pyHJGNQc = YGwFZBGH;
          ATMZloZo = 1;
          continue;
        }
        const auto wbH8AaCb = A[YGwFZBGH]-A[YGwFZBGH-1];
        if(OA9NF42T > wbH8AaCb){
          OA9NF42T = wbH8AaCb;
          pyHJGNQc = YGwFZBGH;
        }
      }
      if(ATMZloZo==0){
        OA9NF42T = 0;
      }
    }
    ind =pyHJGNQc;
    res = A[ind] - A[ind-1];
    for(x=(ind-1);x<(ind+1);x++){
      if(x){
        val = arrErase(x,N,A);
        int PON0fmpo;
        remove_reference<decltype(A[PON0fmpo] - A[PON0fmpo-1])>::type QDGVCdl1;
        int RlTT0MFE = 0;
        if((1) > ((N)-1)){
          QDGVCdl1 = numeric_limits<remove_reference<decltype(A[PON0fmpo] - A[PON0fmpo-1])>::type>::max();
        }
        else{
          for(PON0fmpo = 1; PON0fmpo <= (N)-1; PON0fmpo++){
            if(RlTT0MFE == 0){
              QDGVCdl1 = A[PON0fmpo] - A[PON0fmpo-1];
              RlTT0MFE = 1;
              continue;
            }
            const auto BRSo37Cn = A[PON0fmpo] - A[PON0fmpo-1];
            if(QDGVCdl1 > BRSo37Cn){
              QDGVCdl1 = BRSo37Cn;
            }
          }
          if(RlTT0MFE==0){
            QDGVCdl1 = numeric_limits<remove_reference<decltype(A[PON0fmpo] - A[PON0fmpo-1])>::type>::max();
          }
        }
        mn=QDGVCdl1;
        int ZcmRJqJU;
        remove_reference<decltype(A[ZcmRJqJU] - A[ZcmRJqJU-1])>::type Jq7Vmy8K;
        int a3zq_coq = 0;
        if((1) > ((N)-1)){
          Jq7Vmy8K = numeric_limits<remove_reference<decltype(A[ZcmRJqJU] - A[ZcmRJqJU-1])>::type>::lowest();
        }
        else{
          for(ZcmRJqJU = 1; ZcmRJqJU <= (N)-1; ZcmRJqJU++){
            if(a3zq_coq == 0){
              Jq7Vmy8K = A[ZcmRJqJU] - A[ZcmRJqJU-1];
              a3zq_coq = 1;
              continue;
            }
            const auto mvgDJPkD = A[ZcmRJqJU] - A[ZcmRJqJU-1];
            if(Jq7Vmy8K < mvgDJPkD){
              Jq7Vmy8K = mvgDJPkD;
            }
          }
          if(a3zq_coq==0){
            Jq7Vmy8K = numeric_limits<remove_reference<decltype(A[ZcmRJqJU] - A[ZcmRJqJU-1])>::type>::lowest();
          }
        }
        mx=Jq7Vmy8K;
        chmax(res, min_L(mn, mx/2));
        chmax(res, min_L(mn, D-A[N-1]));
        arrInsert(x,N,A,val);
      }
    }
    wt_L(res-1);
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
// int N, D, A[2d5+2];
// REP(rd_int()){
//   int res, mn, mx, ind, val;
//   rd(N,D,A(N));
//   arrInsert(0,N,A,0);
// 
//   ind = argmin[i,1,N](A[i]-A[i-1]);
//   res = A[ind] - A[ind-1];
// 
//   rep(x,ind-1,ind+1) if(x){
//     val = arrErase(x,N,A);
//     @[mn,mx] = @[min,max][i,1,N](A[i] - A[i-1]);
//     res >?= min(mn, mx/2);
//     res >?= min(mn, D-A[N-1]);
//     arrInsert(x,N,A,val);
//   }
//   wt(res-1);
// }