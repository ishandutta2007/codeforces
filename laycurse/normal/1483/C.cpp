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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> struct Arr1d{
  int n;
  int mem;
  T*d;
  T& operator[](int a){
    return d[a];
  }
  void sort(){
    reset();
    std::sort(d, d+n);
  }
  int set_nextLT;
  int nextLT_mem;
  int*nextLT;
  int setNextLT(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    set_nextLT = 1;
    if(nextLT_mem < n){
      delete[] nextLT;
      nextLT = new int[n];
      nextLT_mem = n;
    }
    walloc1d(&st, n, &mem);
    for(i=(n)-1;i>=(0);i--){
      while(s && d[st[s-1]] >= d[i]){
        s--;
      }
      if(s==0){
        nextLT[i] = n;
      }
      else{
        nextLT[i] = st[s-1];
      }
      st[s++] = i;
    }
    return 0;
  }
  int NextLT(int i){
    if(set_nextLT==0){
      setNextLT();
    }
    return nextLT[i];
  }
  void reset(){
    set_nextLT = 0;
  }
  void constructor(){
    n = mem = 0;
    d = NULL;
    set_nextLT = 0;
    nextLT_mem = 0;
    nextLT = NULL;
  }
  void destructor(){
    delete[] d;
    d = NULL;
    mem = n = 0;
    set_nextLT = 0;
    nextLT_mem = 0;
    delete[] nextLT;
    nextLT = NULL;
  }
  void constructor(int nn){
    constructor();
    malloc(nn);
  }
  void memory_expand(int nn){
    if(mem < nn){
      delete[] d;
      d = new T[nn];
      mem = nn;
    }
  }
  void malloc(int nn){
    reset();
    memory_expand(nn);
    n = nn;
  }
  void setN(int nn){
    reset();
    memory_expand(nn);
    n = nn;
  }
  void set(vector<T> &a){
    int i;
    int nn = a.size();
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  void set(int nn, T a[]){
    int i;
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  void free(){
    destructor();
  }
  Arr1d(){
    constructor();
  }
  Arr1d(int nn){
    constructor(nn);
  }
  ~Arr1d(){
    destructor();
  }
}
;
int N;
Arr1d<int> H;
Arr1d<int> B;
long long domx[20][300000+2];
long long getmx(int i){
  int k;
  long long res = -4611686016279904256LL;
  for(k=(0);k<(20);k++){
    chmax(res, domx[k][i]);
    if(i & (1<<k)){
      i ^= (1<<k);
    }
  }
  return res;
}
void appmx(int x, int y, long long v){
  int k;
  for(k=(0);k<(20);k++){
    if(x == y){
      break;
    }
    if(x & (1<<k)){
      chmax(domx[k][x], v);
      x += (1<<k);
    }
    if(y & (1<<k)){
      y -= (1<<k);
      chmax(domx[k][y], v);
    }
  }
}
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  long long res;
  long long tmp;
  rd(N);
  H.malloc(N);
  {
    int cTE1_r3A;
    for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
      rd(H[cTE1_r3A]);
    }
  }
  B.malloc(N);
  {
    int xr20shxY;
    for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
      rd(B[xr20shxY]);
    }
  }
  for(i=(0);i<(20);i++){
    for(j=(0);j<(N+1);j++){
      domx[i][j] = -4611686016279904256LL;
    }
  }
  appmx(0, 1, 0);
  for(i=(0);i<(N);i++){
    tmp = getmx(i);
    j = H.NextLT(i);
    appmx(i+1, j+1, tmp + B[i]);
    if(j != N){
      appmx(j, j+1, tmp);
    }
  }
  res = getmx(N);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210321-1 [beta]

// --- original code ---
// //no-unlocked
// int N;
// Arr1d<int> H, B;
// 
// ll domx[20][3d5+2];
// 
// ll getmx(int i){
//   ll res = -ll_inf;
//   rep(k,20){
//     res >?= domx[k][i];
//     if(i & (1<<k)) i ^= (1<<k);
//   }
//   return res;
// }
// 
// void appmx(int x, int y, ll v){
//   rep(k,20){
//     if(x == y) break;
//     if(x & (1<<k)){
//       domx[k][x] >?= v;
//       x += (1<<k);
//     }
//     if(y & (1<<k)){
//       y -= (1<<k);
//       domx[k][y] >?= v;
//     }
//   }
// }
// 
// {
//   int i, j, k;
//   ll res, tmp;
//   rd(N,H(N),B(N));
//   rep(i,20) rep(j,N+1) domx[i][j] = -ll_inf;
//   appmx(0, 1, 0);
//   rep(i,N){
//     tmp = getmx(i);
//     j = H.NextLT(i);
//     appmx(i+1, j+1, tmp + B[i]);
//     if(j != N) appmx(j, j+1, tmp);
//   }
//   res = getmx(N);
//   wt(res);
// }