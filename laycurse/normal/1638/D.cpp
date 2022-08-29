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
struct dimcomp2{
  int B;
  dimcomp2(){
  }
  dimcomp2(int b){
    B = b;
  }
  dimcomp2(int a, int b){
    B = b;
  }
  inline void set(int b){
    B = b;
  }
  inline void set(int a, int b){
    B = b;
  }
  inline int mask(int a, int b){
    return a * B + b;
  }
  inline int operator()(int a, int b){
    return a * B + b;
  }
  inline void para(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
  inline void operator()(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
}
;
int X;
int Y;
int A[1000][1000];
int ok[1000][1000];
int s;
int st[1000000];
int ress;
int res[3][1000000];
dimcomp2 dm;
int chk(int i, int j){
  int di;
  int x;
  if(i < 0 || j < 0 || i >= X-1 || j >= Y-1 || ok[i][j]){
    return 0;
  }
  x =max_L(max_L(max_L(A[i][j], A[i+1][j]), A[i][j+1]), A[i+1][j+1]);
  if(x == -1){
    return 0;
  }
  for(di=(0);di<(2);di++){
    int dj;
    for(dj=(0);dj<(2);dj++){
      if(A[i+di][j+dj] != -1 && A[i+di][j+dj] != x){
        return 0;
      }
    }
  }
  return 1;
}
int main(){
  int i;
  int j;
  int k;
  rd(X);
  rd(Y);
  {
    int bs24PFPc;
    int R5MtCiij;
    for(bs24PFPc=(0);bs24PFPc<(X);bs24PFPc++){
      for(R5MtCiij=(0);R5MtCiij<(Y);R5MtCiij++){
        rd(A[bs24PFPc][R5MtCiij]);
      }
    }
  }
  dm.set(X,Y);
  for(i=(0);i<(X-1);i++){
    for(j=(0);j<(Y-1);j++){
      if(chk(i,j)){
        ok[i][j] = 1;
        st[s++] = dm(i,j);
      }
    }
  }
  while(s){
    int di;
    dm(st[--s], i, j);
    k = 1;
    for(di=(0);di<(2);di++){
      int dj;
      for(dj=(0);dj<(2);dj++){
        chmax(k, A[i+di][j+dj]);
        A[i+di][j+dj] = -1;
      }
    }
    arrInsert(ress, ress, res[0], i, res[1], j, res[2], k);
    for(di=(-1);di<(2);di++){
      int dj;
      for(dj=(-1);dj<(2);dj++){
        if(chk(i+di,j+dj)){
          ok[i+di][j+dj] = 1;
          st[s++] = dm(i+di, j+dj);
        }
      }
    }
  }
  k = -1;
  for(i=(0);i<(X);i++){
    for(j=(0);j<(Y);j++){
      chmax(k, A[i][j]);
    }
  }
  if(k != -1){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  wt_L(ress);
  wt_L('\n');
  for(i=(ress)-1;i>=(0);i--){
    wt_L(res[0][i]+1);
    wt_L(' ');
    wt_L(res[1][i]+1);
    wt_L(' ');
    wt_L(res[2][i]);
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
// int X, Y, A[1000][1000], ok[1000][1000];
// int s, st[1d6];
// int ress, res[3][1d6];
// dimcomp2 dm;
// 
// int chk(int i, int j){
//   int x;
//   if(i < 0 || j < 0 || i >= X-1 || j >= Y-1 || ok[i][j]) return 0;
//   x = max(A[i][j], A[i+1][j], A[i][j+1], A[i+1][j+1]);
//   if(x == -1) return 0;
//   rep(di,2) rep(dj,2) if(A[i+di][j+dj] != -1 && A[i+di][j+dj] != x) return 0;
//   return 1;
// }
// 
// {
//   int i, j, k;
//   rd(X,Y,A(X,Y));
//   dm.set(X,Y);
//   rep(i,X-1) rep(j,Y-1) if(chk(i,j)) ok[i][j] = 1, st[s++] = dm(i,j);
//   while(s){
//     dm(st[--s], i, j);
//     k = 1;
//     rep(di,2) rep(dj,2) k >?= A[i+di][j+dj], A[i+di][j+dj] = -1;
//     arrInsert(ress, ress, res[0], i, res[1], j, res[2], k);
//     rep(di,-1,2) rep(dj,-1,2) if(chk(i+di,j+dj)) ok[i+di][j+dj] = 1, st[s++] = dm(i+di, j+dj);
//   }
//   k = -1;
//   rep(i,X) rep(j,Y) k >?= A[i][j];
//   if(k != -1) wt(-1), return 0;
//   wt(ress);
//   rrep(i,ress) wt(res[0][i]+1, res[1][i]+1, res[2][i]);
// }