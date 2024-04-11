#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (998244353U)
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
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
struct Modint{
  unsigned val;
  Modint(){
    val=0;
  }
  Modint(int a){
    val = ord(a);
  }
  Modint(unsigned a){
    val = ord(a);
  }
  Modint(long long a){
    val = ord(a);
  }
  Modint(unsigned long long a){
    val = ord(a);
  }
  inline unsigned ord(unsigned a){
    return a%MD;
  }
  inline unsigned ord(int a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned ord(unsigned long long a){
    return a%MD;
  }
  inline unsigned ord(long long a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned get(){
    return val;
  }
  inline Modint &operator+=(Modint a){
    val += a.val;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  inline Modint &operator-=(Modint a){
    if(val < a.val){
      val = val + MD - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  inline Modint &operator*=(Modint a){
    val = ((unsigned long long)val*a.val)%MD;
    return *this;
  }
  inline Modint &operator/=(Modint a){
    return *this *= a.inverse();
  }
  inline Modint operator+(Modint a){
    return Modint(*this)+=a;
  }
  inline Modint operator-(Modint a){
    return Modint(*this)-=a;
  }
  inline Modint operator*(Modint a){
    return Modint(*this)*=a;
  }
  inline Modint operator/(Modint a){
    return Modint(*this)/=a;
  }
  inline Modint operator+(int a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(int a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(int a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(int a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator+(long long a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(long long a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(long long a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(long long a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator-(void){
    Modint res;
    if(val){
      res.val=MD-val;
    }
    else{
      res.val=0;
    }
    return res;
  }
  inline operator bool(void){
    return val!=0;
  }
  inline operator int(void){
    return get();
  }
  inline operator long long(void){
    return get();
  }
  inline Modint inverse(){
    int a = val;
    int b = MD;
    int u = 1;
    int v = 0;
    int t;
    Modint res;
    while(b){
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if(u < 0){
      u += MD;
    }
    res.val = u;
    return res;
  }
  inline Modint pw(unsigned long long b){
    Modint a(*this);
    Modint res;
    res.val = 1;
    while(b){
      if(b&1){
        res *= a;
      }
      b >>= 1;
      a *= a;
    }
    return res;
  }
  inline bool operator==(int a){
    return ord(a)==val;
  }
  inline bool operator!=(int a){
    return ord(a)!=val;
  }
}
;
inline Modint operator+(int a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(int a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(int a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(int a, Modint b){
  return Modint(a)/=b;
}
inline Modint operator+(long long a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(long long a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(long long a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(long long a, Modint b){
  return Modint(a)/=b;
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
inline void wt_L(Modint x){
  int i;
  i = (int)x;
  wt_L(i);
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
struct graph{
  int N;
  int*es;
  int**edge;
  void setDirectEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    walloc1d(&edge[0], M, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
    }
  }
}
;
int N;
int A[1500][1500];
vector<int> g[1500];
int mx[1500];
int nd[1500];
graph gr;
int node;
int m;
int a[3000];
int b[3000];
int ok[3000];
int sz;
int x[2000000];
int y[2000000];
int z[2000000];
Modint dp[3000][1501];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int s;
  int t;
  int u;
  int d1;
  int d2;
  unionFind uf;
  rd(N);
  {
    int Lj4PdHRW;
    int KL2GvlyY;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      for(KL2GvlyY=(0);KL2GvlyY<(N);KL2GvlyY++){
        rd(A[Lj4PdHRW][KL2GvlyY]);
      }
    }
  }
  for(i=(0);i<(N);i++){
    for(j=(i+1);j<(N);j++){
      arrInsert(sz, sz, x, i, y, j, z, A[i][j]);
    }
  }
  for(i=(0);i<(N);i++){
    g[i].push_back(i);
  }
  for(i=(0);i<(N);i++){
    nd[i] = node++;
    ok[nd[i]] = 1;
  }
  sortA_L(sz, z, x, y);
  uf.walloc(N,1);
  for(i=(0);i<(sz);i++){
    s = uf(x[i]);
    t = uf(y[i]);
    if(s!=t){
      uf(s, t);
      u = uf(x[i]);
      for(j=(0);j<(g[s].size());j++){
        for(k=(0);k<(g[t].size());k++){
          chmax(mx[u], A[g[s][j]][g[t][k]]);
        }
      }
      for(k=(0);k<(g[s+t-u].size());k++){
        g[u].push_back(g[s+t-u][k]);
      }
      arrInsert(m, m, a, node, b, nd[s]);
      arrInsert(m, m, a, node, b, nd[t]);
      nd[u] = node++;
    }
    s = uf(x[i]);
    if(mx[s] == z[i]){
      ok[nd[s]] = 1;
    }
  }
  gr.setDirectEdge(node, m, a, b);
  for(i=(0);i<(node);i++){
    if(gr.es[i]){
      d1 = gr.edge[i][0];
      d2 = gr.edge[i][1];
      s = t = 0;
      for(j=(0);j<(N);j++){
        if(dp[d1][j] != 0){
          s = j+1;
        }
      }
      for(k=(0);k<(N);k++){
        if(dp[d2][k] != 0){
          t = k+1;
        }
      }
      for(j=(0);j<(s);j++){
        for(k=(0);k<(t);k++){
          dp[i][j+k+1] += dp[d1][j] * dp[d2][k];
        }
      }
    }
    if(ok[i]){
      dp[i][0] += 1;
    }
  }
  {
    int aTqQ6rt8;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(aTqQ6rt8=(0);aTqQ6rt8<(N-1);aTqQ6rt8++){
        wt_L(dp[node-1][aTqQ6rt8]);
        wt_L(' ');
      }
      wt_L(dp[node-1][aTqQ6rt8]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200926-1

// --- original code ---
// //no-unlocked
// #define MD 998244353
// int N, A[1500][1500];
// vector<int> g[1500]; int mx[1500], nd[1500];
// 
// graph gr;
// int node, m, a[3000], b[3000], ok[3000];
// int sz, x[2d6], y[2d6], z[2d6];
// 
// Modint dp[3000][1501];
// 
// {
//   int i, j, k, s, t, u, d1, d2;
//   unionFind uf;
//   rd(N,A(N,N));
//   rep(i,N) rep(j,i+1,N) arrInsert(sz, sz, x, i, y, j, z, A[i][j]);
// 
//   rep(i,N) g[i].push_back(i);
//   rep(i,N) nd[i] = node++, ok[nd[i]] = 1;
// 
//   sortA(sz, z, x, y);
//   uf.walloc(N,1);
//   rep(i,sz){
//     s = uf(x[i]);
//     t = uf(y[i]);
//     if(s!=t){
//       uf(s, t);
//       u = uf(x[i]);
//       rep(j,g[s].size()) rep(k,g[t].size()) mx[u] >?= A[g[s][j]][g[t][k]];
//       rep(k,g[s+t-u].size()) g[u].push_back(g[s+t-u][k]);
//       arrInsert(m, m, a, node, b, nd[s]);
//       arrInsert(m, m, a, node, b, nd[t]);
//       nd[u] = node++;
//     }
//     s = uf(x[i]);
//     if(mx[s] == z[i]) ok[nd[s]] = 1;
//   }
// 
//   gr.setDirectEdge(node, m, a, b);
//   rep(i,node){
//     if(gr.es[i]){
//       d1 = gr.edge[i][0];
//       d2 = gr.edge[i][1];
//       s = t = 0;
//       rep(j,N) if(dp[d1][j] != 0) s = j+1;
//       rep(k,N) if(dp[d2][k] != 0) t = k+1;
//       rep(j,s) rep(k,t) dp[i][j+k+1] += dp[d1][j] * dp[d2][k];
//     }
//     if(ok[i]) dp[i][0] += 1;
//   }
// 
//   wt(dp[node-1](N));
// }