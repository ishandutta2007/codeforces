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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> struct segtree_ph{
  int N;
  int logN;
  T*val;
  void malloc(int maxN, int once = 0);
  void walloc(int maxN, int once = 0, void **mem = &wmem);
  void free(void);
  T& operator[](int i);
  void setN(int n, int zerofill = 1, int dobuild = 1);
  void build(void);
  inline void build(int a);
  inline void change(int a, T v);
  inline T get(int a, int b);
}
;
struct sval{
  int sm;
  int mx1;
  int mx2;
}
;
sval segtree_ph_func(sval a, sval b){
  sval res;
  res.sm = a.sm + b.sm;
  res.mx1 =max_L(b.mx1, b.sm+a.mx1);
  res.mx2 =max_L(a.mx2, a.sm+b.mx2);
  return res;
}
segtree_ph<sval> t;
int N;
int A[200000];
vector<int> ind[200000];
int res[200000];
int main(){
  int loop;
  wmem = memarr;
  sval tmp1;
  sval tmp2;
  rd(N);
  {
    int Q5VJL1cS;
    for(Q5VJL1cS=(0);Q5VJL1cS<(N);Q5VJL1cS++){
      rd(A[Q5VJL1cS]);A[Q5VJL1cS] += (-1);
    }
  }
  t.walloc(N);
  for(loop=(0);loop<(2);loop++){
    int i, k;
    for(i=(0);i<(N);i++){
      ind[i].clear();
    }
    for(i=(0);i<(N);i++){
      ind[A[i]].push_back(i);
    }
    t.setN(N);
    for(i=(0);i<(N);i++){
      t[i] = {-1,-1,-1};
    }
    t.build();
    for(k=(N)-1;k>=(0);k--){
      int V9aVTaxx, jZyWAPpY;
      for(V9aVTaxx=(0);V9aVTaxx<(ind[k].size());V9aVTaxx++){
        auto&i = ind[k][V9aVTaxx];
        t.change(i, {1,1,1});
      }
      for(jZyWAPpY=(0);jZyWAPpY<(ind[k].size());jZyWAPpY++){
        auto&i = ind[k][jZyWAPpY];
        tmp1 = t.get(0, i+1);
        tmp2 = t.get(i, N);
        chmax(res[i], (tmp1.mx1 + tmp2.mx2 - loop - 1) / 2);
      }
    }
    for(i=(0);i<(N);i++){
      A[i] = N - 1 - A[i];
    }
  }
  {
    int XJIcIBrW;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(XJIcIBrW=(0);XJIcIBrW<(N-1);XJIcIBrW++){
        wt_L(res[XJIcIBrW]);
        wt_L(' ');
      }
      wt_L(res[XJIcIBrW]);
      wt_L('\n');
    }
  }
  return 0;
}
template<class T> void segtree_ph<T>::malloc(int maxN, int once /*= 0*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  val = new T[2*i];
  if(once){
    setN(maxN);
  }
}
template<class T> void segtree_ph<T>::walloc(int maxN, int once /*= 0*/, void **mem /*= &wmem*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  walloc1d(&val, 2*i, mem);
  if(once){
    setN(maxN);
  }
}
template<class T> void segtree_ph<T>::free(void){
  delete [] val;
}
template<class T> T& segtree_ph<T>::operator[](int i){
  return val[N+i];
}
template<class T> void segtree_ph<T>::setN(int n, int zerofill /*= 1*/, int dobuild /*= 1*/){
  int i;
  for(i=1,logN=0;i<n;i*=2,logN++){
    ;
  }
  N = i;
  if(dobuild){
    build();
  }
}
template<class T> void segtree_ph<T>::build(void){
  for(int i=N-1;i;i--){
    val[i] = segtree_ph_func(val[2*i], val[2*i+1]);
  }
}
template<class T> inline void segtree_ph<T>::build(int a){
  while(a > 1){
    a /= 2;
    val[a] = segtree_ph_func(val[2*a], val[2*a+1]);
  }
}
template<class T> inline void segtree_ph<T>::change(int a, T v){
  val[a+N] = v;
  build(a+N);
}
template<class T> inline T segtree_ph<T>::get(int a, int b){
  T res;
  T tmp;
  int fga = 0;
  int fgb = 0;
  a += N;
  b += N;
  while(a < b){
    if(a%2){
      if(fga){
        res = segtree_ph_func(res, val[a]);
      }
      else{
        res = val[a];
        fga = 1;
      }
      a++;
    }
    if(b%2){
      b--;
      if(fgb){
        tmp = segtree_ph_func(val[b], tmp);
      }
      else{
        tmp = val[b];
        fgb = 1;
      }
    }
    a /= 2;
    b /= 2;
  }
  if(fga==1 && fgb==0){
    return res;
  }
  if(fga==0 && fgb==1){
    return tmp;
  }
  if(fga==1 && fgb==1){
    return segtree_ph_func(res, tmp);
  }
  return res;
}
// cLay version 20210619-1 [beta]

// --- original code ---
// //no-unlocked
// struct sval{
//   int sm, mx1, mx2;
// };
// 
// sval segtree_ph_func(sval a, sval b){
//   sval res;
//   res.sm = a.sm + b.sm;
//   res.mx1 = max(b.mx1, b.sm+a.mx1);
//   res.mx2 = max(a.mx2, a.sm+b.mx2);
//   return res;
// }
// 
// segtree_ph<sval> t;
// 
// int N, A[2d5];
// VI ind[2d5];
// int res[2d5];
// 
// {
//   sval tmp1, tmp2;
//   rd(N,(A--)(N));
//   t.walloc(N);
//   rep(loop,2){
//     rep(i,N) ind[i].clear();
//     rep(i,N) ind[A[i]].push_back(i);
// 
//     t.setN(N);
//     rep(i,N) t[i] = {-1,-1,-1};
//     t.build();
// 
//     rrep(k,N){
//       rep[ind[k]](i,ind[k].size()) t.change(i, {1,1,1});
//       rep[ind[k]](i,ind[k].size()){
//         tmp1 = t.get(0, i+1);
//         tmp2 = t.get(i, N);
//         // wt(i, tmp1.mx1 + tmp2.mx2 - loop - 1, ":", tmp1.mx1, tmp2.mx2);
//         res[i] >?= (tmp1.mx1 + tmp2.mx2 - loop - 1) / 2;
//       }
//     }
//     rep(i,N) A[i] = N - 1 - A[i];
//   }
//   wt(res(N));
// }