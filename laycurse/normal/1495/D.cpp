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
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
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
  inline Modint &operator++(){
    val++;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  inline Modint &operator--(){
    if(val == 0){
      val = MD - 1;
    }
    else{
      --val;
    }
    return *this;
  }
  inline Modint operator++(int a){
    Modint res(*this);
    val++;
    if(val >= MD){
      val -= MD;
    }
    return res;
  }
  inline Modint operator--(int a){
    Modint res(*this);
    if(val == 0){
      val = MD - 1;
    }
    else{
      --val;
    }
    return res;
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
struct graph{
  int N;
  int*es;
  int**edge;
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
  void getDist(int root, int res[], void *mem = wmem){
    int i;
    int j;
    int k;
    int*q;
    int s;
    int z;
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      res[i]=-1;
    }
    res[root]=0;
    s=0;
    z=1;
    q[0]=root;
    while(z){
      i=q[s++];
      z--;
      for(j=(0);j<(es[i]);j++){
        k=edge[i][j];
        if(res[k]>=0){
          continue;
        }
        res[k]=res[i]+1;
        q[s+z++]=k;
      }
    }
  }
  int getDist(int a, int b, void *mem = wmem){
    int i;
    int j;
    int k;
    int*q;
    int s;
    int z;
    int*d;
    if(a==b){
      return 0;
    }
    walloc1d(&d, N, &mem);
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      d[i] = -1;
    }
    d[a] = 0;
    s = 0;
    z = 1;
    q[0] = a;
    while(z){
      i = q[s++];
      z--;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(d[k] >= 0){
          continue;
        }
        d[k] = d[i] + 1;
        if(k==b){
          return d[k];
        }
        q[s+z++] = k;
      }
    }
    return -1;
  }
  int shortestPath(const int s, const int t, int res[], void *mem=wmem){
    int i;
    int j;
    int k;
    int*q;
    int qs = 0;
    int qe = 0;
    int*b;
    walloc1d(&b, N, &mem);
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      b[i] = -1;
    }
    b[s] = -2;
    q[qe++] = s;
    while(qe > qs){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(b[k]!=-1){
          continue;
        }
        b[k] = i;
        q[qe++] = k;
      }
      if(b[t]!=-1){
        break;
      }
    }
    if(b[t]==-1){
      return -1;
    }
    k = 0;
    res[k] = i = t;
    while(i != s){
      res[++k] = (i = b[i]);
    }
    std::reverse(res, res+k+1);
    return k;
  }
}
;
int N;
int M;
int A[600];
int B[600];
graph g;
int d[400][400];
Modint res[400][400];
int ps;
int p[401];
int ind[400];
int x[400];
int y[400];
int v[400];
int xx[400];
int yy[400];
Modint solve(int r1, int r2){
  int i;
  int j;
  int k;
  Modint res = 1;
  Modint tmp;
  ps = g.shortestPath(r1, r2, p);
  for(i=(0);i<(N);i++){
    ind[i] = i;
    xx[i] = x[i] = d[r1][i];
    yy[i] = y[i] = d[r2][i];
  }
  for(i=(0);i<(N);i++){
    v[i] = 0;
  }
  for(i=(0);i<(ps+1);i++){
    v[p[i]] = 1;
  }
  for(i=(0);i<(N);i++){
    if(!v[i]){
      int WYIGIcGE;
      j = ind[i];
      tmp = 0;
      for(WYIGIcGE=(0);WYIGIcGE<(g.es[j]);WYIGIcGE++){
        auto&k = g.edge[j][WYIGIcGE];
        if(xx[k] != xx[j] - 1 || yy[k] != yy[j] - 1){
          continue;
        }
        tmp++;
      }
      res *= tmp;
    }
  }
  return res;
}
int main(){
  int i;
  wmem = memarr;
  rd(N);
  rd(M);
  {
    int ao_dF3pO;
    for(ao_dF3pO=(0);ao_dF3pO<(M);ao_dF3pO++){
      rd(A[ao_dF3pO]);A[ao_dF3pO] += (-1);
      rd(B[ao_dF3pO]);B[ao_dF3pO] += (-1);
    }
  }
  g.setEdge(N,M,A,B);
  for(i=(0);i<(N);i++){
    g.getDist(i, d[i]);
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i);j<(N);j++){
      res[i][j] = res[j][i] = solve(i, j);
    }
  }
  {
    int ZIeRIny5;
    int iMWUTgY_;
    for(ZIeRIny5=(0);ZIeRIny5<(N);ZIeRIny5++){
      if(N==0){
        wt_L('\n');
      }
      else{
        for(iMWUTgY_=(0);iMWUTgY_<(N-1);iMWUTgY_++){
          wt_L(res[ZIeRIny5][iMWUTgY_]);
          wt_L(' ');
        }
        wt_L(res[ZIeRIny5][iMWUTgY_]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// #define MD 998244353
// int N, M, A[600], B[600];
// graph g;
// int d[400][400];
// Modint res[400][400];
// 
// int ps, p[401];
// int ind[400], x[400], y[400], v[400], xx[400], yy[400];
// 
// Modint solve(int r1, int r2){
//   int i, j, k;
//   Modint res = 1, tmp;
//   ps = g.shortestPath(r1, r2, p);
//   rep(i,N) ind[i] = i, xx[i] = x[i] = d[r1][i], yy[i] = y[i] = d[r2][i];
//   rep(i,N) v[i] = 0;
//   rep(i,ps+1) v[p[i]] = 1;
//   rep(i,N) if(!v[i]){
//     j = ind[i];
//     tmp = 0;
//     rep[g.edge[j]](k,g.es[j]){
//       if(xx[k] != xx[j] - 1 || yy[k] != yy[j] - 1) continue;
//       tmp++;
//     }
//     res *= tmp;
//   }
//   return res;
// }
// 
// {
//   rd(N,M,(A--,B--)(M));
//   g.setEdge(N,M,A,B);
//   rep(i,N) g.getDist(i, d[i]);
//   rep(i,N) rep(j,i,N) res[i][j] = res[j][i] = solve(i, j);
//   wt(res(N,N));
// }