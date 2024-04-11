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
template<class T> struct fenwick{
  int size;
  int memory;
  T*data;
  void malloc(int mem);
  void malloc(int mem, int fg);
  void walloc(int mem, void **workMemory = &wmem);
  void walloc(int mem, int fg, void **workMemory = &wmem);
  void free(void);
  void init(int N);
  void add(int k, T val);
  T get(int k);
  T range(int a, int b);
  int kth(T k);
}
;
#define M 500
int N;
int A[200000];
fenwick<int> t;
fenwick<long long> f;
long long res[200000];
long long v[M];
long long wa[M];
int main(){
  int i;
  wmem = memarr;
  int x;
  int y;
  int z;
  long long t1;
  long long t2;
  long long f1;
  long long f2;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  t.walloc(300000+2, 1);
  f.walloc(300000+2, 1);
  for(i=(0);i<(N);i++){
    int k;
    for(k=(1);k<(M);k++){
      v[k] += A[i] % k;
    }
    t.add(A[i], 1);
    f.add(A[i], A[i]);
    if(A[i] < M){
      res[i] += v[A[i]];
      for(k=(A[i]);k<(M);k++){
        wa[k] += A[i];
      }
    }
    else{
      for(x=(0);x<(300000+1);x+=(A[i])){
        y =min_L(300000, x + A[i]-1);
        res[i] += f.range(x,y) - t.range(x,y) * (long long)x;
      }
    }
    res[i] += A[i] * (long long) t.range(A[i]+1, 300000+1);
    y = A[i];
    t2 = t.get(y);
    f2 = f.get(y);
    res[i] += A[i] * t2;
    while(y >= 1){
      z = A[i] / y;
      x = A[i] / (z+1);
      while(12 <= x  &&  x < M && wa[x] == wa[x-11]){
        x -= 10;
      }
      if(x < M){
        f1 =wa[x];
      }
      else{
        f1 =f.get(x);
      }
      res[i] -= (f2-f1) * z;
      y = x;
      f2 = f1;
    }
    if(i){
      res[i] += res[i-1];
    }
  }
  {
    int APIVbQlN;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(APIVbQlN=(0);APIVbQlN<(N-1);APIVbQlN++){
        wt_L(res[APIVbQlN]);
        wt_L(' ');
      }
      wt_L(res[APIVbQlN]);
      wt_L('\n');
    }
  }
  return 0;
}
template<class T> void fenwick<T>::malloc(int mem){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
}
template<class T> void fenwick<T>::malloc(int mem, int fg){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::walloc(int mem, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
}
template<class T> void fenwick<T>::walloc(int mem, int fg, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::free(void){
  memory = 0;
  free(data);
}
template<class T> void fenwick<T>::init(int N){
  size = N;
  memset(data,0,sizeof(T)*N);
}
template<class T> void fenwick<T>::add(int k, T val){
  while(k < size){
    data[k] += val;
    k |= k+1;
  }
}
template<class T> T fenwick<T>::get(int k){
  T res = 0;
  while(k>=0){
    res += data[k];
    k = (k&(k+1))-1;
  }
  return res;
}
template<class T> T fenwick<T>::range(int a, int b){
  if(a < 0){
    a = 0;
  }
  if(b >= size){
    b = size - 1;
  }
  if(b < a){
    return 0;
  }
  return get(b) - get(a-1);
}
template<class T> int fenwick<T>::kth(T k){
  int i=0;
  int j=size;
  int c;
  T v;
  while(i<j){
    c = (i+j)/2;
    v = get(c);
    if(v <= k){
      i=c+1;
    }
    else{
      j=c;
    }
  }
  return i==size?-1:i;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// #define M 500
// int N, A[2d5];
// fenwick<int> t;
// fenwick<ll> f;
// ll res[], v[M], wa[M];
// {
//   int x, y, z;
//   ll t1, t2, f1, f2;
//   rd(N,A(N));
// 
//   // N = 2d5;
//   // rep(i,N) A[i] = rand()%1d5+2d5+1;
// 
//   t.walloc(3d5+2, 1);
//   f.walloc(3d5+2, 1);
//   rep(i,N){
//     rep(k,1,M) v[k] += A[i] % k;
//     t.add(A[i], 1);
//     f.add(A[i], A[i]);
//     if(A[i] < M){
//       res[i] += v[A[i]];
//       rep(k,A[i],M) wa[k] += A[i];
//     } else {
//       rep(x,0,3d5+1,A[i]){
//         y = min(3d5, x + A[i]-1);
//         res[i] += f.range(x,y) - t.range(x,y) * (ll)x;
//       }
//     }
// 
//     res[i] += A[i] * (ll) t.range(A[i]+1, 3d5+1);
//     y = A[i];
//     t2 = t.get(y);
//     f2 = f.get(y);
//     res[i] += A[i] * t2;
//     while(y >= 1){
//       z = A[i] / y;
//       x = A[i] / (z+1);
//       while(12 <= x < M && wa[x] == wa[x-11]) x -= 10;
//       f1 = if[x < M, wa[x], f.get(x)];
//       res[i] -= (f2-f1) * z;
//       y = x;
//       f2 = f1;
//     }
// 
//     if(i) res[i] += res[i-1];
//   }
//   wt(res(N));
//   // wt(res(10));
// }