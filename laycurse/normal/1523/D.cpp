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
struct Rand{
  unsigned x;
  unsigned y;
  unsigned z;
  unsigned w;
  Rand(void){
    x=123456789;
    y=362436069;
    z=521288629;
    w=(unsigned)time(NULL);
  }
  Rand(unsigned seed){
    x=123456789;
    y=362436069;
    z=521288629;
    w=seed;
  }
  inline unsigned get(void){
    unsigned t;
    t = (x^(x<<11));
    x=y;
    y=z;
    z=w;
    w = (w^(w>>19))^(t^(t>>8));
    return w;
  }
  inline double getUni(void){
    return get()/4294967296.0;
  }
  inline int get(int a){
    return (int)(a*getUni());
  }
  inline int get(int a, int b){
    return a+(int)((b-a+1)*getUni());
  }
  inline long long get(long long a){
    return(long long)(a*getUni());
  }
  inline long long get(long long a, long long b){
    return a+(long long)((b-a+1)*getUni());
  }
  inline double get(double a, double b){
    return a+(b-a)*getUni();
  }
  inline int getExp(int a){
    return(int)(exp(getUni()*log(a+1.0))-1.0);
  }
  inline int getExp(int a, int b){
    return a+(int)(exp(getUni()*log((b-a+1)+1.0))-1.0);
  }
}
;
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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline int BIT_popcount_L(const int x){
  return __builtin_popcount(x);
}
inline int BIT_popcount_L(const long long x){
  return __builtin_popcountll(x);
}
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
template<class T, class S> void ZetaTransform_L(int N, T A[], S res[]){
  int i;
  int j;
  int x;
  int m;
  for(j=(0);j<(N);j++){
    res[j] = A[j];
  }
  for(i=1;i<N;i*=2){
    for(j=(i);j<(N);j+=(2*i)){
      m =min_L(N, j+i);
      for(x=(j);x<(m);x++){
        res[x] += res[x^i];
      }
    }
  }
}
template<class T> void ZetaTransform_L(int N, T A[]){
  int i;
  int j;
  int x;
  int m;
  for(i=1;i<N;i*=2){
    for(j=(i);j<(N);j+=(2*i)){
      m =min_L(N, j+i);
      for(x=(j);x<(m);x++){
        A[x] += A[x^i];
      }
    }
  }
}
int N;
int M;
int P;
char S[200000][62];
int sz;
int ok[60];
int cnt[1000000];
int opt = -1;
char res[62];
int main(){
  int KrdatlYV, Lj4PdHRW;
  int i;
  int j;
  int k;
  int c;
  int nd;
  Rand rnd;
  for(Lj4PdHRW=(0);Lj4PdHRW<(100);Lj4PdHRW++){
    rnd.get();
  }
  rd(N);
  rd(M);
  rd(P);
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){
      rd(S[e98WHCEY]);
    }
  }
  for(i=(0);i<(N);i++){
    for(j=(0);j<(M);j++){
      S[i][j] -= '0';
    }
  }
  nd =(divup_L(N,2));
  for(KrdatlYV=(0);KrdatlYV<(20);KrdatlYV++){
    int mask;
    i = rnd.get(N);
    sz = 0;
    for(k=(0);k<(M);k++){
      if(S[i][k]){
        ok[sz++] = k;
      }
    }
    for(mask=(0);mask<(1<<sz);mask++){
      cnt[mask] = 0;
    }
    for(i=(0);i<(N);i++){
      k = 0;
      for(j=(0);j<(sz);j++){
        if(!S[i][ok[j]]){
          k |= (1<<j);
        }
      }
      cnt[k]++;
    }
    ZetaTransform_L(1<<sz, cnt);
    for(mask=(0);mask<(1<<sz);mask++){
      if(cnt[mask] >= nd){
        c = sz -BIT_popcount_L(mask);
        if(c <= opt){
          continue;
        }
        opt = c;
        for(i=(0);i<(M);i++){
          res[i] = '0';
        }
        for(i=(0);i<(sz);i++){
          if(!((mask) &(1<<(i)))){
            res[ok[i]] = '1';
          }
        }
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210607-1

// --- original code ---
// //no-unlocked
// int N, M, P;
// char S[2d5][62];
// int sz, ok[60];
// int cnt[1d6];
// int opt = -1; char res[62];
// {
//   int i, j, k, c, nd;
//   Rand rnd;
//   rep(100) rnd.get();
// 
//   rd(N,M,P,S(N));
//   rep(i,N) rep(j,M) S[i][j] -= '0';
//   nd = N /+ 2;
// 
//   rep(20){
//     i = rnd.get(N);
//     sz = 0;
//     rep(k,M) if(S[i][k]) ok[sz++] = k;
//     rep(mask,1<<sz) cnt[mask] = 0;
//     rep(i,N){
//       k = 0;
//       rep(j,sz) if(!S[i][ok[j]]) k |= (1<<j);
//       cnt[k]++;
//     }
//     ZetaTransform(1<<sz, cnt);
//     rep(mask,1<<sz) if(cnt[mask] >= nd){
//       c = sz - BIT_popcount(mask);
//       if(c <= opt) continue;
//       opt = c;
//       rep(i,M) res[i] = '0';
//       rep(i,sz) if(!BIT_ith(mask,i)) res[ok[i]] = '1';
//     }
//   }
//   wt(res);
// }