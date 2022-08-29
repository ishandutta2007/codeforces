#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
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
template<class T> int runLength(int N, T *arr, void *val_s = NULL, void *len_s = NULL){
  int i;
  int rN;
  T*val = (T*) val_s;
  int*len = (int*) len_s;
  if(N==0){
    return 0;
  }
  if(val==NULL || len==NULL){
    void*mem = wmem;
    if(val==NULL){
      walloc1d(&val, N, &mem);
    }
    if(len==NULL){
      walloc1d(&len, N, &mem);
    }
  }
  rN = 1;
  val[0] = arr[0];
  len[0] = 1;
  for(i=(1);i<(N);i++){
    if(val[rN-1] == arr[i]){
      len[rN-1]++;
    }
    else{
      val[rN] = arr[i];
      len[rN] = 1;
      rN++;
    }
  }
  return rN;
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
struct unionFind{
  int*d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void malloc(const int n, const int fg){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
    if(fg){
      init(n);
    }
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void walloc(const int n, const int fg, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
    if(fg){
      init(n);
    }
  }
  inline void init(const int n){
    int i;
    N = n;
    for(i=(0);i<(n);i++){
      d[i] = -1;
    }
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    int t = a;
    int k;
    while(d[t]>=0){
      t=d[t];
    }
    while(d[a]>=0){
      k=d[a];
      d[a]=t;
      a=k;
    }
    return a;
  }
  inline int connect(int a, int b){
    if(d[a]>=0){
      a=get(a);
    }
    if(d[b]>=0){
      b=get(b);
    }
    if(a==b){
      return 0;
    }
    if(d[a] < d[b]){
      d[a] += d[b];
      d[b] = a;
    }
    else{
      d[b] += d[a];
      d[a] = b;
    }
    return 1;
  }
  inline int operator()(int a){
    return get(a);
  }
  inline int operator()(int a, int b){
    return connect(a,b);
  }
  inline int& operator[](const int a){
    return d[a];
  }
  inline int size(int a){
    a = get(a);
    return -d[a];
  }
  inline int sizeList(int res[]){
    int i;
    int sz=0;
    for(i=(0);i<(N);i++){
      if(d[i]<0){
        res[sz++] = -d[i];
      }
    }
    return sz;
  }
}
;
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
int N;
char S[500000+4];
int sz;
int len[500000+3];
char val[500000+3];
int sm[500000+4];
int es;
int ev[500000+3];
int eind[500000+3];
fenwick<long long> inner;
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int x;
  int y;
  int z;
  long long cnt0 = 0;
  long long cnt1 = 0;
  long long cnt2 = 0;
  long long hasi = 0;
  long long res = 0;
  long long tmp;
  long long cr = 0;
  long long nx;
  long long pre = 0;
  long long nlen;
  unionFind uf;
  rd(N);
  rd(S);
  arrInsert(0, N, S, '0');
  arrInsert(N, N, S, '0');
  j = k = 0;
  for(i=(0);i<(N-1);i++){
    if(S[i]=='0'){
      k = 0;
    }
    else{
      k++;
    }
    chmax(j, k);
    res -= j;
  }
  j = k = 0;
  for(i=(N)-1;i>=(0);i--){
    if(S[i]=='0'){
      k = 0;
    }
    else{
      k++;
    }
    chmax(j, k);
    res -= j;
  }
  sz = runLength(N, S, val, len);
  for(i=(0);i<(sz);i++){
    sm[i+1] = sm[i] + len[i];
  }
  uf.walloc(sz, 1);
  inner.walloc(N+1, 1);
  for(i=(0);i<(sz);i++){
    if(val[i]=='1'){
      arrInsert(es, es, ev, len[i], eind, i);
    }
  }
  sortA_L(es, ev, eind);
  for(i=(0);i<(sz);i++){
    if(val[i]=='0'){
      cnt0++;
      cnt1 += len[i];
      cnt2 += (long long) len[i] * (len[i]+1) / 2;
    }
  }
  for(i=(0);i<(sz);i++){
    if(val[i]=='1'){
      for(j=(1);j<(len[i]+1);j++){
        inner.add(j, len[i]-j+1);
      }
    }
  }
  for(k=(0);k<(es+1);k++){
    if(k==es){
      nx =N+1;
    }
    else{
      nx =ev[k];
    }
    while(cr < nx){
      tmp = cnt2;
      tmp += cnt1 * cr * 2;
      tmp -= len[uf(0)] * cr;
      tmp -= len[uf(sz-1)] * cr;
      tmp +=max_L(0LL, cnt0 - 2)* cr * cr;
      tmp += inner.get(cr);
      res += cr * (tmp - pre);
      pre = tmp;
      cr++;
    }
    if(k == es){
      break;
    }
    x = uf(eind[k]-1);
    y = uf(eind[k]);
    z = uf(eind[k]+1);
    for(j=(1);j<(len[y]+1);j++){
      inner.add(j, -(len[y]-j+1));
    }
    cnt0--;
    cnt1 -= len[x];
    cnt2 -= (long long) len[x] * (len[x]+1) / 2;
    cnt0--;
    cnt1 -= len[z];
    cnt2 -= (long long) len[z] * (len[z]+1) / 2;
    nlen = len[x] + len[y] + len[z];
    uf(x,y);
    uf(x,z);
    y = uf(y);
    len[y] = nlen;
    cnt0++;
    cnt1 += len[y];
    cnt2 += (long long) len[y] * (len[y]+1) / 2;
  }
  wt_L(res);
  wt_L('\n');
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
// cLay varsion 20201003-1

// --- original code ---
// //no-unlocked
// int N; char S[5d5+4];
// int sz, len[5d5+3]; char val[5d5+3];
// int sm[5d5+4];
// int es, ev[5d5+3], eind[5d5+3];
// fenwick<ll> inner;
// {
//   int i, j, k, x, y, z;
//   ll cnt0 = 0, cnt1 = 0, cnt2 = 0, hasi = 0, res = 0, tmp, cr = 0, nx, pre = 0;
//   ll nlen;
//   unionFind uf;
// 
//   rd(N,S);
//   arrInsert(0, N, S, '0');
//   arrInsert(N, N, S, '0');
// 
//   j = k = 0;
//   rep(i,N-1){
//     if[S[i]=='0', k = 0, k++];
//     j >?= k;
//     res -= j;
//   }
//   j = k = 0;
//   rrep(i,N){
//     if[S[i]=='0', k = 0, k++];
//     j >?= k;
//     res -= j;
//   }
// 
//   sz = runLength(N, S, val, len);
//   rep(i,sz) sm[i+1] = sm[i] + len[i];
// 
//   uf.walloc(sz, 1);
//   inner.walloc(N+1, 1);
// 
//   rep(i,sz) if(val[i]=='1') arrInsert(es, es, ev, len[i], eind, i);
//   sortA(es, ev, eind);
// 
//   rep(i,sz) if(val[i]=='0'){
//     cnt0++;
//     cnt1 += len[i];
//     cnt2 += (ll) len[i] * (len[i]+1) / 2;
//   }
// 
//   rep(i,sz) if(val[i]=='1'){
//     rep(j,1,len[i]+1) inner.add(j, len[i]-j+1);
//   }
// 
//   // wt(val(sz));
//   // wt(len(sz));
// 
//   rep(k,es+1){
//     nx = if[k==es, N+1, ev[k]];
//     while(cr < nx){
//       tmp = cnt2;
//       tmp += cnt1 * cr * 2;
//       tmp -= len[uf(0)] * cr;
//       tmp -= len[uf(sz-1)] * cr;
//       tmp += max(0LL, cnt0 - 2) * cr * cr;
//       tmp += inner.get(cr);
//       res += cr * (tmp - pre);
//       pre = tmp;
//       // wt(cr, tmp, ":", cnt0, cnt1, cnt2);
//       cr++;
//     }
//     if(k == es) break;
// 
//     x = uf(eind[k]-1);
//     y = uf(eind[k]);
//     z = uf(eind[k]+1);
//     rep(j,1,len[y]+1) inner.add(j, -(len[y]-j+1));
// 
//     cnt0--;
//     cnt1 -= len[x];
//     cnt2 -= (ll) len[x] * (len[x]+1) / 2;
//     cnt0--;
//     cnt1 -= len[z];
//     cnt2 -= (ll) len[z] * (len[z]+1) / 2;
//     nlen = len[x] + len[y] + len[z];
//     uf(x,y);
//     uf(x,z);
//     y = uf(y);
//     len[y] = nlen;
//     cnt0++;
//     cnt1 += len[y];
//     cnt2 += (ll) len[y] * (len[y]+1) / 2;
//   }
// 
//   wt(res);
// }