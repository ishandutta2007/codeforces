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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
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
struct dimcomp2{
  int B;
  dimcomp2(){
  }
  dimcomp2(int b){
    B = b;
  }
  dimcomp2(int a, int b){
    B = b;
  }
  inline void set(int b){
    B = b;
  }
  inline void set(int a, int b){
    B = b;
  }
  inline int mask(int a, int b){
    return a * B + b;
  }
  inline int operator()(int a, int b){
    return a * B + b;
  }
  inline void para(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
  inline void operator()(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
}
;
int N;
int M;
char S[1000][1002];
int cnt_r[1000];
int cnt_c[1000];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int mn;
  int mx;
  int er = 0;
  int ec = 0;
  int res = 0;
  unionFind uf;
  dimcomp2 dm;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(S[Lj4PdHRW]);
    }
  }
  dm.set(N,M);
  for(i=(0);i<(N);i++){
    for(j=(0);j<(M);j++){
      if(S[i][j]=='#'){
        cnt_r[i]++;
        cnt_c[j]++;
        res++;
      }
    }
  }
  for(i=(0);i<(N);i++){
    if(cnt_r[i]){
      mn = 1073709056;
      mx = -1073709056;
      for(j=(0);j<(M);j++){
        if(S[i][j]=='#'){
          chmin(mn, j);
          chmax(mx, j);
        }
      }
      if(mx - mn != cnt_r[i] - 1){
        wt_L(-1);
        wt_L('\n');
        return 0;
      }
    }
  }
  for(j=(0);j<(M);j++){
    if(cnt_c[j]){
      mn = 1073709056;
      mx = -1073709056;
      for(i=(0);i<(N);i++){
        if(S[i][j]=='#'){
          chmin(mn, i);
          chmax(mx, i);
        }
      }
      if(mx - mn != cnt_c[j] - 1){
        wt_L(-1);
        wt_L('\n');
        return 0;
      }
    }
  }
  for(i=(0);i<(N);i++){
    if(cnt_r[i]==0){
      er++;
    }
  }
  for(j=(0);j<(M);j++){
    if(cnt_c[j]==0){
      ec++;
    }
  }
  if(er && !ec){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  if(ec && !er){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  uf.walloc(N*M, 1);
  for(i=(0);i<(N);i++){
    for(j=(0);j<(M);j++){
      if(S[i][j]=='#'){
        if(i+1 < N && S[i+1][j]=='#'){
          res -= uf(dm(i,j), dm(i+1,j));
        }
        if(j+1 < M && S[i][j+1]=='#'){
          res -= uf(dm(i,j), dm(i,j+1));
        }
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, M;
// char S[1000][1002];
// int cnt_r[1000], cnt_c[1000];
// {
//   int i, j, k, mn, mx;
//   int er = 0, ec = 0, res = 0;
//   unionFind uf;
//   dimcomp2 dm;
// 
//   rd(N,M,S(N));
//   dm.set(N,M);
// 
//   rep(i,N) rep(j,M) if(S[i][j]=='#'){
//     cnt_r[i]++;
//     cnt_c[j]++;
//     res++;
//   }
// 
//   rep(i,N) if(cnt_r[i]){
//     mn = int_inf;
//     mx = -int_inf;
//     rep(j,M) if(S[i][j]=='#'){
//       mn <?= j;
//       mx >?= j;
//     }
//     if(mx - mn != cnt_r[i] - 1) wt(-1), return 0;
//   }
// 
//   rep(j,M) if(cnt_c[j]){
//     mn = int_inf;
//     mx = -int_inf;
//     rep(i,N) if(S[i][j]=='#'){
//       mn <?= i;
//       mx >?= i;
//     }
//     if(mx - mn != cnt_c[j] - 1) wt(-1), return 0;
//   }
// 
//   rep(i,N) if(cnt_r[i]==0) er++;
//   rep(j,M) if(cnt_c[j]==0) ec++;
//   if(er && !ec) wt(-1), return 0;
//   if(ec && !er) wt(-1), return 0;
// 
//   uf.walloc(N*M, 1);
//   rep(i,N) rep(j,M) if(S[i][j]=='#'){
//     if(i+1 < N && S[i+1][j]=='#') res -= uf(dm(i,j), dm(i+1,j));
//     if(j+1 < M && S[i][j+1]=='#') res -= uf(dm(i,j), dm(i,j+1));
//   }
// 
//   wt(res);
// }