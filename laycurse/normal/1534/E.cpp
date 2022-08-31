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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
}
inline int my_getchar(){
  return getchar();
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
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int K;
int t[500];
int ind[500];
int q[500][500];
int chk(int d){
  int i, k;
  for(i=(0);i<(N);i++){
    ind[i] = i;
  }
  for(k=(0);k<(d);k++){
    rsortA_L(N,t,ind);
    for(i=(0);i<(K);i++){
      q[k][i] = ind[i];
      t[i]--;
    }
  }
  int FmcKpFmN;
  cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type xr20shxY;
  if(N==0){
    xr20shxY = 0;
  }
  else{
    xr20shxY = t[0];
    for(FmcKpFmN=(1);FmcKpFmN<(N);FmcKpFmN++){
      xr20shxY = max_L(xr20shxY, t[FmcKpFmN]);
    }
  }
  return xr20shxY;
}
int main(){
  int i;
  wmem = memarr;
  int res = 0;
  int d;
  rd(N);
  rd(K);
  if(N%2==1 && K%2==0){
    wt_L("-1");
    wt_L('\n');
    return 0;
  }
  for(d=0;;d++){
    if(K*d - N >= 0 && (K*d - N)%2 == 0){
      int i;
      for(i=(0);i<(N);i++){
        t[i] = 1;
      }
      for(i=(0);i<((K*d-N)/2);i++){
        t[i%N]+=2;
      }
      if(!chk(d)){
        break;
      }
    }
  }
  for(i=(0);i<(d);i++){
    wt_L("?");
    wt_L(' ');
    {
      int jZyWAPpY;
      if(K==0){
        wt_L('\n');
      }
      else{
        for(jZyWAPpY=(0);jZyWAPpY<(K-1);jZyWAPpY++){
          wt_L(q[i][jZyWAPpY]+1);
          wt_L(' ');
        }
        wt_L(q[i][jZyWAPpY]+1);
        wt_L('\n');
      }
    }
    res ^= rd_int();
  }
  wt_L("!");
  wt_L(' ');
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210619-1 [beta]

// --- original code ---
// //interactive
// int N, K;
// int t[500], ind[];
// int q[500][500];
// 
// int chk(int d){
//   rep(i,N) ind[i] = i;
//   rep(k,d){
//     rsortA(N,t,ind);
//     rep(i,K) q[k][i] = ind[i], t[i]--;
//   }
//   return max(t(N));
// }
// 
// {
//   int res = 0, d;
//   rd(N,K);
//   if(N%2==1 && K%2==0) wt("-1"), return 0;
//   for(d=0;;d++) if(K*d - N >= 0 && (K*d - N)%2 == 0){
//     rep(i,N) t[i] = 1;
//     rep(i,(K*d-N)/2) t[i%N]+=2;
//     if(!chk(d)) break;
//   }
//   rep(i,d){
//     wt("?",q[i](K)+1);
//     res ^= rd_int();
//   }
//   wt("!",res);
// }