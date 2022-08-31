#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
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
int N;
int M;
int Y[100000];
int LX[100000];
int RX[100000];
int lxy[100000];
int rxy[100000];
int X[100000];
int LY[100000];
int RY[100000];
int main(){
  int i;
  wmem = memarr;
  int cl = 0;
  int cr = 0;
  long long res = 1;
  fenwick<int> t;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(Y[Lj4PdHRW]);
      rd(LX[Lj4PdHRW]);
      rd(RX[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(M);e98WHCEY++){
      rd(X[e98WHCEY]);
      rd(LY[e98WHCEY]);
      rd(RY[e98WHCEY]);
    }
  }
  t.malloc(1000000+1, 1);
  t.add(0,1);
  t.add(1000000,1);
  for(i=(0);i<(N);i++){
    if(RX[i]-LX[i]==1000000){
      res++;
    }
  }
  for(i=(0);i<(N);i++){
    lxy[i] = rxy[i] = Y[i];
  }
  sortA_L(N, LX, lxy);
  sortA_L(N, RX, rxy);
  sortA_L(M, X, LY, RY);
  for(i=(0);i<(M);i++){
    while(cl < N && LX[cl] <= X[i]){
      t.add(lxy[cl++], 1);
    }
    while(cr < N && RX[cr] < X[i]){
      t.add(rxy[cr++], -1);
    }
    res += t.range(LY[i], RY[i]) - 1;
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
// cLay varsion 20200916-1

// --- original code ---
// //no-unlocked
// int N, M;
// int Y[1d5], LX[1d5], RX[1d5], lxy[1d5], rxy[1d5];
// int X[1d5], LY[1d5], RY[1d5];
// 
// {
//   int cl = 0, cr = 0;
//   ll res = 1;
//   fenwick<int> t;
//   rd(N,M,(Y,LX,RX)(N),(X,LY,RY)(M));
//   t.malloc(1d6+1, 1);
//   t.add(0,1);
//   t.add(1d6,1);
// 
//   rep(i,N) if(RX[i]-LX[i]==1d6) res++;
//   rep(i,N) lxy[i] = rxy[i] = Y[i];
//   sortA(N, LX, lxy);
//   sortA(N, RX, rxy);
//   sortA(M, X, LY, RY);
// 
//   rep(i,M){
//     while(cl < N && LX[cl] <= X[i]) t.add(lxy[cl++], 1);
//     while(cr < N && RX[cr] < X[i]) t.add(rxy[cr++], -1);
//     res += t.range(LY[i], RY[i]) - 1;
//   }
//   wt(res);
// }