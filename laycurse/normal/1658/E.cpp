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
template<class T1, class T2, class T3, class T4> void sortA_L(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem = wmem){
  int i;
  pair<pair<T1, T2>, pair<T3, T4> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first.first = a[i];
    arr[i].first.second = b[i];
    arr[i].second.first = c[i];
    arr[i].second.second = d[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first.first;
    b[i] = arr[i].first.second;
    c[i] = arr[i].second.first;
    d[i] = arr[i].second.second;
  }
}
template<class T1, class T2, class T3> void rsortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  sortA_L(N, a, b, c, mem);
  reverse(a, a+N);
  reverse(b, b+N);
  reverse(c, c+N);
}
template<class T1, class T2, class T3, class T4> void rsortA_L(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem = wmem){
  sortA_L(N, a, b, c, d, mem);
  reverse(a, a+N);
  reverse(b, b+N);
  reverse(c, c+N);
  reverse(d, d+N);
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T> struct fenwick2d{
  int sizeX;
  int sizeY;
  int memory;
  T*data;
  void malloc(int mem){
    memory=mem;
    data=(T*)std::malloc(sizeof(T)*mem);
  }
  void *malloc(int mem, void *workMemory){
    memory=mem;
    data=(T*)workMemory;
    return data+mem;
  }
  void init(int X, int Y){
    sizeX=X;
    sizeY=Y;
    memset(data,0,sizeof(T)*X*Y);
  }
  void add(int x, int y, T val){
    int k;
    while(x<sizeX){
      k=y;
      while(k<sizeY){
        data[x*sizeY+k]+=val;
        k|=k+1;
      }
      x|=x+1;
    }
  }
  T get(int x, int y){
    int k;
    T res=0;
    while(x>=0){
      k=y;
      while(k>=0){
        res+=data[x*sizeY+k];
        k=(k&(k+1))-1;
      }
      x=(x&(x+1))-1;
    }
    return res;
  }
  T range(int x1, int y1, int x2, int y2){
    return get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1);
  }
}
;
int N;
int K;
int A[2000][2000];
int x[4000000];
int y[4000000];
int v[4000000];
int ind[4000000];
char res[2000][2002];
int cnt;
fenwick2d<int> f;
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  rd(N);
  rd(K);
  {
    int OA9NF42T;
    int ATMZloZo;
    for(OA9NF42T=(0);OA9NF42T<(N);OA9NF42T++){
      for(ATMZloZo=(0);ATMZloZo<(N);ATMZloZo++){
        rd(A[OA9NF42T][ATMZloZo]);
      }
    }
  }
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N);j++){
      x[i*N+j] = i+j;
      y[i*N+j] = N-1+j-i;
      v[i*N+j] = A[i][j];
      ind[i*N+j] = i*N+j;
    }
  }
  rsortA_L(N*N,v,x,y,ind);
  wmem = f.malloc(4*N*N, wmem);
  f.init(2*N, 2*N);
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N);j++){
      res[i][j] = 'G';
    }
  }
  for(k=(0);k<(N*N);k++){
    if(f.get(x[k],y[k]) != cnt){
      continue;
    }
    i = ind[k] / N;
    j = ind[k] % N;
    res[i][j] = 'M';
    cnt++;
    f.add(max_L(0, x[k]-K),max_L(0, y[k]-K), 1);
    if(y[k]+K+1 < 2*N){
      f.add(max_L(0, x[k]-K), y[k]+K+1, -1);
    }
    if(x[k]+K+1 < 2*N){
      f.add(x[k]+K+1,max_L(0, y[k]-K), -1);
    }
    if(x[k]+K+1 < 2*N && y[k]+K+1 < 2*N){
      f.add(x[k]+K+1, y[k]+K+1, 1);
    }
  }
  {
    int CglcDhNV;
    for(CglcDhNV=(0);CglcDhNV<(N);CglcDhNV++){
      wt_L(res[CglcDhNV]);
      wt_L('\n');
    }
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
// cLay version 20220312-1

// --- original code ---
// //no-unlocked
// template<class T>
// struct fenwick2d{
//   int sizeX, sizeY, memory; T *data;
//   
//   void malloc(int mem){memory=mem;data=(T*)std::malloc(sizeof(T)*mem);}
//   void *malloc(int mem, void *workMemory){memory=mem;data=(T*)workMemory;return data+mem;}
//   void init(int X, int Y){sizeX=X;sizeY=Y;memset(data,0,sizeof(T)*X*Y);}
//   void add(int x, int y, T val){int k;while(x<sizeX){k=y;while(k<sizeY)data[x*sizeY+k]+=val,k|=k+1;x|=x+1;}}
//   T get(int x, int y){int k;T res=0;while(x>=0){k=y;while(k>=0)res+=data[x*sizeY+k],k=(k&(k+1))-1;x=(x&(x+1))-1;}return res;}
//   T range(int x1, int y1, int x2, int y2){return get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1);}
// };
// 
// 
// 
// int N, K, A[2000][2000];
// int x[4d6], y[], v[], ind[];
// char res[2000][2002]; int cnt;
// fenwick2d<int> f;
// {
//   int i, j, k;
//   rd(N,K,A(N,N));
//   rep(i,N) rep(j,N) x[i*N+j] = i+j, y[i*N+j] = N-1+j-i, v[i*N+j] = A[i][j], ind[i*N+j] = i*N+j;
//   rsortA(N*N,v,x,y,ind);
//   wmem = f.malloc(4*N*N, wmem);
//   f.init(2*N, 2*N);
//   rep(i,N) rep(j,N) res[i][j] = 'G';
//   rep(k,N*N){
//     if(f.get(x[k],y[k]) != cnt) continue;
//     i = ind[k] / N;
//     j = ind[k] % N;
//     res[i][j] = 'M';
//     cnt++;
//     f.add(max(0,x[k]-K), max(0,y[k]-K), 1);
//     if(y[k]+K+1 < 2*N) f.add(max(0,x[k]-K), y[k]+K+1, -1);
//     if(x[k]+K+1 < 2*N) f.add(x[k]+K+1, max(0,y[k]-K), -1);
//     if(x[k]+K+1 < 2*N && y[k]+K+1 < 2*N) f.add(x[k]+K+1, y[k]+K+1, 1);
//   }
//   wtLn(res(N));
// }