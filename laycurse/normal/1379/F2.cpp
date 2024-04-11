#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[419430400];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> void malloc1d(T **arr, int x){
  (*arr) = (T*)malloc(x*sizeof(T));
}
template<class T> void free1d(T *arr){
  free(arr);
}
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> > *arr;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
template<class T> struct fenwick{
  int size;
  int memory;
  T *data;
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
template<class S, class T1, class T2> struct rangeTree2d{
  int N;
  int N2;
  int *sz;
  S *tot;
  fenwick<S> *w;
  T1 **d1;
  T1 *ddd1;
  T2 *d2;
  inline void build(int nn, T1 dd1[], T2 dd2[], S ww[] = NULL, void **mem = &wmem){
    int i;
    int j;
    int i1;
    int i2;
    int k1;
    int k2;
    int s;
    int s1;
    int s2;
    S *www;
    N = nn;
    for(N2=1;N2<N;N2*=2){
      ;
    }
    walloc1d(&sz,2*N2,mem);
    walloc1d(&tot,2*N2,mem);
    walloc1d(&w,2*N2,mem);
    walloc1d(&d1,2*N2,mem);
    walloc1d(&d2,nn,mem);
    malloc1d(&www,nn);
    walloc1d(&ddd1,nn);
    if(ww==NULL){
      for(i=(0);i<(N);i++){
        www[i] = 1;
      }
    }
    else{
      for(i=(0);i<(N);i++){
        www[i] = ww[i];
      }
    }
    for(i=(0);i<(N);i++){
      ddd1[i] = dd1[i];
    }
    for(i=(0);i<(N);i++){
      d2[i] = dd2[i];
    }
    sortA_L(N,d2,ddd1,www);
    for(i=(0);i<(N);i++){
      sz[N2+i] = 1;
      walloc1d(&d1[N2+i], 1, mem);
      d1[N2+i][0] = ddd1[i];
      w[N2+i].walloc(1, mem);
      w[N2+i].init(1);
      w[N2+i].add(0,www[i]);
      tot[N2+i] = www[i];
    }
    for(i=(N);i<(N2);i++){
      sz[N2+i] = 0;
      tot[N2+i] = 0;
    }
    for(i=(N2)-1;i>=(1);i--){
      i1 = 2*i;
      i2 = 2*i + 1;
      s1 = sz[i1];
      s2 = sz[i2];
      sz[i] = s1 + s2;
      s = k1 = k2 = 0;
      walloc1d(&d1[i], sz[i], mem);
      w[i].walloc(sz[i], mem);
      w[i].init(sz[i]);
      while(k1 < s1 || k2 < s2){
        if(k2==s2){
          d1[i][s] = d1[i1][k1];
          w[i].add(s,w[i1].range(k1,k1));
          s++;
          k1++;
          continue;
        }
        if(k1==s1){
          d1[i][s] = d1[i2][k2];
          w[i].add(s,w[i2].range(k2,k2));
          s++;
          k2++;
          continue;
        }
        if(d1[i1][k1] < d1[i2][k2]){
          d1[i][s] = d1[i1][k1];
          w[i].add(s,w[i1].range(k1,k1));
          s++;
          k1++;
          continue;
        }
        else{
          d1[i][s] = d1[i2][k2];
          w[i].add(s,w[i2].range(k2,k2));
          s++;
          k2++;
          continue;
        }
      }
    }
    free1d(www);
  }
  inline int add(T1 x, T2 y, S v){
    int a;
    int b;
    int z;
    a = lower_bound(d2, d2+N, y) - d2;
    b = upper_bound(d2, d2+N, y) - d2;
    z = lower_bound(ddd1+a, ddd1+b, x) - ddd1 + N2;
    while(z){
      a = lower_bound(d1[z], d1[z]+sz[z], x) - d1[z];
      w[z].add(a, v);
      z /= 2;
    }
  }
  inline S query(T1 x1, T1 x2, T2 y1, T2 y2){
    S res = 0;
    int a;
    int b;
    int z1;
    int z2;
    a = lower_bound(d2, d2+N, y1) - d2 + N2;
    b = lower_bound(d2, d2+N, y2) - d2 + N2;
    while(a < b){
      if(a%2){
        z1 = lower_bound(d1[a], d1[a]+sz[a], x1) - d1[a];
        z2 = lower_bound(d1[a], d1[a]+sz[a], x2) - d1[a];
        if(z1 < z2){
          res += w[a].range(z1,z2-1);
        }
        a++;
      }
      if(b%2){
        b--;
        z1 = lower_bound(d1[b], d1[b]+sz[b], x1) - d1[b];
        z2 = lower_bound(d1[b], d1[b]+sz[b], x2) - d1[b];
        if(z1 < z2){
          res += w[b].range(z1,z2-1);
        }
      }
      a /= 2;
      b /= 2;
    }
    return res;
  }
}
;
int N;
int M;
int Q;
int t[200000];
int x[200000];
int y[200000];
int sz;
int tx[200000];
int ty[200000];
int w[200000];
rangeTree2d<int,int,int> t1;
rangeTree2d<int,int,int> t2;
set<long long> s1;
set<long long> s2;
int main(){
  int i;
  wmem = memarr;
  int fg;
  long long dame = 0;
  long long xy;
  rd(N);
  rd(M);
  rd(Q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(Q);Lj4PdHRW++){
      rd(x[Lj4PdHRW]);
      rd(y[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(Q);i++){
    if(x[i]%2==1){
      {
        auto RZTsC2BF = (1);
        auto FmcKpFmN = ( x[i]/2);
        auto xr20shxY = ( y[i]/2);
        t[i] = RZTsC2BF;
        x[i] = FmcKpFmN;
        y[i] = xr20shxY;
      }
    }
    else{
      {
        auto WYIGIcGE = (2);
        auto t_ynMSdg = ( x[i]/2-1);
        auto KrdatlYV = ( y[i]/2-1);
        t[i] = WYIGIcGE;
        x[i] = t_ynMSdg;
        y[i] = KrdatlYV;
      }
    }
  }
  sz = 0;
  for(i=(0);i<(Q);i++){
    if(t[i]==1){
      arrInsert(sz, sz, tx, x[i], ty, y[i]);
    }
  }
  t1.build(sz, tx, ty, w);
  sz = 0;
  for(i=(0);i<(Q);i++){
    if(t[i]==2){
      arrInsert(sz, sz, tx, x[i], ty, y[i]);
    }
  }
  t2.build(sz, tx, ty, w);
  for(i=(0);i<(Q);i++){
    xy = (long long) x[i] * 1000000000 + y[i];
    if(t[i]==1){
      if(s1.count(xy)){
        fg = -1;
        s1.erase(xy);
      }
      else{
        fg = 1;
        s1.insert(xy);
      }
      t1.add(x[i], y[i], fg);
      dame += fg * t2.query(x[i], 1073709056, y[i], 1073709056);
    }
    else{
      if(s2.count(xy)){
        fg = -1;
        s2.erase(xy);
      }
      else{
        fg = 1;
        s2.insert(xy);
      }
      t2.add(x[i], y[i], fg);
      dame += fg * t1.query(-1, x[i]+1, -1, y[i]+1);
    }
    if(dame==0){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
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
  if(b==-1){
    b=size-1;
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
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// //working_memory=400m
// int N, M, Q;
// int t[2d5], x[2d5], y[2d5];
// int sz, tx[2d5], ty[2d5], w[2d5];
// rangeTree2d<int,int,int> t1, t2;
// set<ll> s1, s2;
// {
//   int fg;
//   ll dame = 0, xy;
//   rd(N,M,Q,(x,y)(Q));
//   rep(i,Q){
//     if(x[i]%2==1){
//       (t[i], x[i], y[i]) = (1, x[i]/2, y[i]/2);
//     } else {
//       (t[i], x[i], y[i]) = (2, x[i]/2-1, y[i]/2-1);
//     }
//   }
// 
//   sz = 0;
//   rep(i,Q) if(t[i]==1) arrInsert(sz, sz, tx, x[i], ty, y[i]);
//   t1.build(sz, tx, ty, w);
// 
//   sz = 0;
//   rep(i,Q) if(t[i]==2) arrInsert(sz, sz, tx, x[i], ty, y[i]);
//   t2.build(sz, tx, ty, w);
// 
//   rep(i,Q){
//     xy = (ll) x[i] * 1d9 + y[i];
//     if(t[i]==1){
//       if(s1.count(xy)){
//         fg = -1;
//         s1.erase(xy);
//       } else {
//         fg = 1;
//         s1.insert(xy);
//       }
//       t1.add(x[i], y[i], fg);
//       dame += fg * t2.query(x[i], int_inf, y[i], int_inf);
//     } else {
//       if(s2.count(xy)){
//         fg = -1;
//         s2.erase(xy);
//       } else {
//         fg = 1;
//         s2.insert(xy);
//       }
//       t2.add(x[i], y[i], fg);
//       dame += fg * t1.query(-1, x[i]+1, -1, y[i]+1);
//     }
//     wt(if[dame==0, "YES", "NO"]);
//   }
// }