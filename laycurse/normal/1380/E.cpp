#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
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
struct unionFind{
  int *d;
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
int N;
int M;
int A[200000];
int X;
int Y;
unionFind uf;
int con[200000];
vector<int> ind[200000];
int main(){
  int i, xr20shxY;
  wmem = memarr;
  int res;
  int z;
  int c;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  uf.walloc(M);
  uf.init(M);
  res = N-1;
  for(i=(0);i<(N);i++){
    ind[A[i]].push_back(i);
  }
  for(i=(1);i<(N);i++){
    if(con[i]==0 && uf(A[i-1])==uf(A[i])){
      con[i]=1;
      res--;
    }
  }
  wt_L(res);
  wt_L('\n');
  for(xr20shxY=(0);xr20shxY<(M-1);xr20shxY++){
    rd(X);X += (-1);
    rd(Y);Y += (-1);
    X = uf(X);
    Y = uf(Y);
    uf(X, Y);
    z = uf(X);
    c = X + Y - z;
    for(int i : ind[c]){
      ind[z].push_back(i);
      if(i-1>=0 && con[i]==0 && uf(A[i-1])==uf(A[i])){
        con[i]=1;
        res--;
      }
      if(i+1<N && con[i+1]==0 && uf(A[i])==uf(A[i+1])){
        con[i+1]=1;
        res--;
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], X, Y;
// unionFind uf;
// int con[2d5];
// vector<int> ind[2d5];
// {
//   int res, z, c;
//   rd(N,M,(A--)(N));
//   uf.walloc(M);
//   uf.init(M);
// 
//   res = N-1;
//   rep(i,N) ind[A[i]].push_back(i);
//   rep(i,1,N) if(con[i]==0 && uf(A[i-1])==uf(A[i])) con[i]=1, res--;
//   wt(res);
// 
//   rep(M-1){
//     rd(X--, Y--);
//     X = uf(X);
//     Y = uf(Y);
//     uf(X, Y);
//     z = uf(X);
//     c = X + Y - z;
//     for(int i : ind[c]){
//       ind[z].push_back(i);
//       if(i-1>=0 && con[i]==0 && uf(A[i-1])==uf(A[i])) con[i]=1, res--;
//       if(i+1<N && con[i+1]==0 && uf(A[i])==uf(A[i+1])) con[i+1]=1, res--;
//     }
//     wt(res);
//   }
// }