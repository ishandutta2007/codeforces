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
void*wmem;
char memarr[96000000];
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int main(){
  int xr20shxY;
  wmem = memarr;
  int N;
  rd(N);
  long long A[N];
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  int e98WHCEY;
  long long cTE1_r3A;
  if(N==0){
    cTE1_r3A = 0;
  }
  else{
    cTE1_r3A = A[0];
    for(e98WHCEY=(1);e98WHCEY<(N);e98WHCEY++){
      cTE1_r3A += A[e98WHCEY];
    }
  }
  long long sm = cTE1_r3A;
  sortA_L(N,A);
  int WYIGIcGE = rd_int();
  for(xr20shxY=(0);xr20shxY<(WYIGIcGE);xr20shxY++){
    int APIVbQlN;
    int i;
    long long X;
    rd(X);
    long long Y;
    rd(Y);
    long long res = 4611686016279904256LL;
    int ao_dF3pO;
    int tU__gIr_;
    int a2conNHc;
    ao_dF3pO = 0;
    tU__gIr_ = N;
    while(ao_dF3pO < tU__gIr_){
      if((ao_dF3pO + tU__gIr_)%2==0){
        a2conNHc = (ao_dF3pO + tU__gIr_) / 2;
      }
      else{
        a2conNHc = (ao_dF3pO + tU__gIr_ - 1) / 2;
      }
      if(A[a2conNHc] >= X){
        tU__gIr_ = a2conNHc;
      }
      else{
        ao_dF3pO = a2conNHc + 1;
      }
    }
    i =tU__gIr_;
    for(APIVbQlN=(0);APIVbQlN<(2);APIVbQlN++){
      if(0 <= i  &&  i < N){
        chmin(res, max_L(0, X-A[i])+max_L(0, Y-(sm-A[i])));
      }
      i--;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210917-1

// --- original code ---
// //no-unlocked
// int @N; ll @A[N], sm = sum(A(N));
// sortA(N,A);
// REP(rd_int()){
//   int i;
//   ll @X, @Y, res = ll_inf;
//   i = bsearch_min[int,i,0,N](A[i] >= X);
//   rep(2){
//     if(0 <= i < N) res <?= max(0, X-A[i]) + max(0, Y-(sm-A[i]));
//     i--;
//   }
//   wt(res);
// }