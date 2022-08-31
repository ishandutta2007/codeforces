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
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
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
int N;
int M;
int X[200000];
int Y[200000];
int OP[200000];
int K[200000];
int ttm[200000];
int p[200000];
int res[200000];
int arr[200000];
int arr2[200000];
int main(){
  wmem = memarr;
  long long s;
  long long e;
  long long pp;
  long long x;
  long long y;
  long long t;
  long long tt;
  long long i;
  long long j;
  long long c;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);
      rd(Y[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(M);e98WHCEY++){
      rd(OP[e98WHCEY]);
      rd(K[e98WHCEY]);K[e98WHCEY] += (-1);
    }
  }
  for(i=(0);i<(M);i++){
    ttm[i] = i;
  }
  for(i=(0);i<(M);i++){
    p[i] = X[K[i]] + Y[K[i]];
  }
  sortA_L(M, p, K, ttm);
  for(s=(0);s<(M);s++){
    e = s+1;
    while(e < M && p[e] == p[s]){
      e++;
    }
    pp = p[s];
    if(pp < 500){
      for(i=(s);i<(e);i++){
        auto APIVbQlN = ((X[K[i]]));
        auto YREPHmFM = (( Y[K[i]]));
        auto jZyWAPpY = (( ttm[i] + X[K[i]]));
        x=APIVbQlN;
        y=YREPHmFM;
        t=jZyWAPpY;
        if(i+1 < e && K[i] == K[i+1]){
          i++;
          tt = ttm[i];
        }
        else{
          tt = 1073709056;
        }
        for(j=(t);j<(min_L(t+y, M));j++){
          arr[j]++;
        }
        for(j=(tt);j<(min_L(tt+pp, M));j++){
          if(j >= t && (j-t)%pp < y){
            arr[j]--;
          }
        }
      }
      for(i=(pp);i<(M);i++){
        arr[i] += arr[i-pp];
      }
      for(i=(0);i<(M);i++){
        res[i] += arr[i];
      }
      for(i=(0);i<(M);i++){
        arr[i] = 0;
      }
    }
    else{
      for(i=(s);i<(e);i++){
        auto X9Iss0pP = ((X[K[i]]));
        auto szDqbNYU = (( Y[K[i]]));
        auto ytthggxT = (( ttm[i] + X[K[i]]));
        x=X9Iss0pP;
        y=szDqbNYU;
        t=ytthggxT;
        if(i+1 < e && K[i] == K[i+1]){
          i++;
          tt = ttm[i];
        }
        else{
          tt = 1073709056;
        }
        c = 0;
        for(j=t; j<min_L(M, tt); j+=pp){
          arr2[j]++;
          c++;
        }
        for(j=t+y; j<min_L(M, tt); j+=pp){
          arr2[j]--;
          c--;
        }
        if(tt < M){
          arr2[tt] -= c;
        }
      }
    }
    s = e - 1;
  }
  for(i=(1);i<(M);i++){
    arr2[i] += arr2[i-1];
  }
  for(i=(0);i<(M);i++){
    res[i] += arr2[i];
  }
  {
    int XNa8avth;
    for(XNa8avth=(0);XNa8avth<(M);XNa8avth++){
      wt_L(res[XNa8avth]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int N, M, X[2d5], Y[], OP[], K[], ttm[], p[];
// int res[], arr[], arr2[];
// {
//   ll s, e, pp, x, y, t, tt, i, j, c;
//   rd(N,M,(X,Y)(N),(OP,K--)(M));
//   rep(i,M) ttm[i] = i;
//   rep(i,M) p[i] = X[K[i]] + Y[K[i]];
//   sortA(M, p, K, ttm);
// 
//   rep(s,M){
//     e = s+1;
//     while(e < M && p[e] == p[s]) e++;
//     pp = p[s];
// 
//     if(pp < 500){
//       rep(i,s,e){
//         (x, y, t) = (X[K[i]], Y[K[i]], ttm[i] + X[K[i]]);
//         if(i+1 < e && K[i] == K[i+1]){
//           i++;
//           tt = ttm[i];
//         } else {
//           tt = int_inf;
//         }
//         rep(j,t,min(t+y,M)) arr[j]++;
//         rep(j,tt,min(tt+pp,M)) if(j >= t && (j-t)%pp < y) arr[j]--;
//       }
//       rep(i,pp,M) arr[i] += arr[i-pp];
//       rep(i,M) res[i] += arr[i];
//       rep(i,M) arr[i] = 0;
//     } else {
//       rep(i,s,e){
//         (x, y, t) = (X[K[i]], Y[K[i]], ttm[i] + X[K[i]]);
//         if(i+1 < e && K[i] == K[i+1]){
//           i++;
//           tt = ttm[i];
//         } else {
//           tt = int_inf;
//         }
//         c = 0;
//         for(j=t; j<min(M,tt); j+=pp) arr2[j]++, c++;
//         for(j=t+y; j<min(M,tt); j+=pp) arr2[j]--, c--;
//         if(tt < M) arr2[tt] -= c;
//       }
//     }
//     s = e - 1;
//   }
// 
//   rep(i,1,M) arr2[i] += arr2[i-1];
//   rep(i,M) res[i] += arr2[i];
//   wtLn(res(M));
// }