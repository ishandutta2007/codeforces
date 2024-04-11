#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
  inline int comp(int res[], void *mem = wmem){
    int i;
    int sz=0;
    int*cnt;
    walloc1d(&cnt, N, &mem);
    for(i=(0);i<(N);i++){
      cnt[i] = 0;
    }
    for(i=(0);i<(N);i++){
      cnt[get(i)] = 1;
    }
    for(i=(0);i<(N);i++){
      if(cnt[i]){
        cnt[i] = sz++;
      }
    }
    for(i=(0);i<(N);i++){
      res[i] = cnt[get(i)];
    }
    return sz;
  }
}
;
struct dimcomp3{
  int B;
  int C;
  dimcomp3(){
  }
  ;
  dimcomp3(int b, int c){
    B = b;
    C = c;
  }
  dimcomp3(int a, int b, int c){
    B = b;
    C = c;
  }
  inline void set(int b, int c){
    B = b;
    C = c;
  }
  inline void set(int a, int b, int c){
    B = b;
    C = c;
  }
  inline int mask(int a, int b, int c){
    return (a * B + b) * C + c;
  }
  inline int operator()(int a, int b, int c){
    return (a * B + b) * C + c;
  }
  inline void para(int mask, int &a, int &b, int &c){
    a = mask / (B*C);
    b = mask % (B*C) / C;
    c = mask % C;
  }
  inline void operator()(int mask, int &a, int &b, int &c){
    a = mask / (B*C);
    b = mask % (B*C) / C;
    c = mask % C;
  }
}
;
int X;
int Y;
char A[500][502];
int res[500][500];
unionFind uf;
dimcomp3 dm;
void doit(int x1, int y1, int x2, int y2){
  uf(dm(0,x1,y1), dm(1,x2,y2));
  uf(dm(1,x1,y1), dm(0,x2,y2));
  uf(dm(0,x2,y2), dm(1,x1,y1));
  uf(dm(1,x2,y2), dm(0,x1,y1));
}
int solve(void){
  int i;
  int cnt;
  int xx[4];
  int yy[4];
  int ind[4] = {0,1,2,3};
  uf.init(2*X*Y);
  random_shuffle(ind, ind+4);
  for(i=(0);i<(X);i++){
    int j;
    for(j=(0);j<(Y);j++){
      if(A[i][j]=='X'){
        int ni, nj;
        cnt = 0;
        {
          static int cTE1_r3A[4] = {-1, 0, 0, 1};
          static int RZTsC2BF[4] = {0, -1, 1, 0};
          int FmcKpFmN;
          for(FmcKpFmN=(0);FmcKpFmN<(4);FmcKpFmN++){
            ni = (i) + cTE1_r3A[FmcKpFmN];
            nj = (j) + RZTsC2BF[FmcKpFmN];
            if(A[ni][nj]=='.'){
              arrInsert(cnt, cnt, xx, ni, yy, nj);
            }
          }
        }
        if(cnt%2){
          return 0;
        }
        if(cnt==2){
          doit(xx[0], yy[0], xx[1], yy[1]);
        }
        if(cnt==4){
          doit(xx[ind[0]], yy[ind[0]], xx[ind[1]], yy[ind[1]]);
          doit(xx[ind[2]], yy[ind[2]], xx[ind[3]], yy[ind[3]]);
        }
      }
    }
  }
  for(i=(0);i<(X);i++){
    int j;
    for(j=(0);j<(Y);j++){
      if(uf(dm(0,i,j)) == uf(dm(1,i,j))){
        return 0;
      }
    }
  }
  for(i=(0);i<(X);i++){
    int j;
    for(j=(0);j<(Y);j++){
      if(A[i][j] == '.'){
        if(uf(dm(0,i,j)) < uf(dm(1,i,j))){
          res[i][j] =1;
        }
        else{
          res[i][j] =4;
        }
      }
    }
  }
  for(i=(0);i<(X);i++){
    int j;
    for(j=(0);j<(Y);j++){
      if(A[i][j] == 'X'){
        int ni, nj;
        {
          static int iMWUTgY_[4] = {-1, 0, 0, 1};
          static int AlM5nNnR[4] = {0, -1, 1, 0};
          int XJIcIBrW;
          for(XJIcIBrW=(0);XJIcIBrW<(4);XJIcIBrW++){
            ni = (i) + iMWUTgY_[XJIcIBrW];
            nj = (j) + AlM5nNnR[XJIcIBrW];
            if(A[ni][nj] == '.'){
              res[i][j] += res[ni][nj];
            }
          }
        }
      }
    }
  }
  wt_L("YES");
  wt_L('\n');
  {
    int Q5rsz4fz;
    int GgkpftXM;
    for(Q5rsz4fz=(0);Q5rsz4fz<(X);Q5rsz4fz++){
      if(Y==0){
        wt_L('\n');
      }
      else{
        for(GgkpftXM=(0);GgkpftXM<(Y-1);GgkpftXM++){
          wt_L(res[Q5rsz4fz][GgkpftXM]);
          wt_L(' ');
        }
        wt_L(res[Q5rsz4fz][GgkpftXM]);
        wt_L('\n');
      }
    }
  }
  return 1;
}
int main(){
  int ytthggxT;
  wmem = memarr;
  rd(X);
  rd(Y);
  {
    int aTqQ6rt8;
    for(aTqQ6rt8=(0);aTqQ6rt8<(X);aTqQ6rt8++){
      rd(A[aTqQ6rt8]);
    }
  }
  uf.walloc(2*X*Y);
  dm.set(2,X,Y);
  for(ytthggxT=(0);ytthggxT<(10);ytthggxT++){
    if(solve()){
      return 0;
    }
  }
  wt_L("NO");
  wt_L('\n');
  return 0;
}
// cLay version 20210904-1

// --- original code ---
// //no-unlocked
// int X, Y;
// char A[500][502];
// int res[500][500];
// unionFind uf;
// dimcomp3 dm;
// 
// void doit(int x1, int y1, int x2, int y2){
//   uf(dm(0,x1,y1), dm(1,x2,y2));
//   uf(dm(1,x1,y1), dm(0,x2,y2));
//   uf(dm(0,x2,y2), dm(1,x1,y1));
//   uf(dm(1,x2,y2), dm(0,x1,y1));
// }
// 
// int solve(void){
//   int cnt, xx[4], yy[4], ind[4] = {0,1,2,3};
//   uf.init(2*X*Y);
//   random_shuffle(ind, ind+4);
//   rep(i,X) rep(j,Y) if(A[i][j]=='X'){
//     cnt = 0;
//     rep_dist(ni,nj,i,j) if(A[ni][nj]=='.') arrInsert(cnt, cnt, xx, ni, yy, nj);
//     if(cnt%2) return 0;
//     if(cnt==2){
//       doit(xx[0], yy[0], xx[1], yy[1]);
//     }
//     if(cnt==4){
//       doit(xx[ind[0]], yy[ind[0]], xx[ind[1]], yy[ind[1]]);
//       doit(xx[ind[2]], yy[ind[2]], xx[ind[3]], yy[ind[3]]);
//     }
//   }
//   rep(i,X) rep(j,Y) if(uf(dm(0,i,j)) == uf(dm(1,i,j))) return 0;
// 
//   rep(i,X) rep(j,Y) if(A[i][j] == '.') res[i][j] = if[uf(dm(0,i,j)) < uf(dm(1,i,j)), 1, 4];
//   rep(i,X) rep(j,Y) if(A[i][j] == 'X'){
//     rep_dist(ni,nj,i,j) if(A[ni][nj] == '.') res[i][j] += res[ni][nj];
//   }
// 
//   wt("YES");
//   wt(res(X,Y));
//   return 1;
// }
// 
// {
//   rd(X,Y,A(X));
//   uf.walloc(2*X*Y);
//   dm.set(2,X,Y);
// 
//   rep(10) if(solve()) return 0;
//   wt("NO");
// }