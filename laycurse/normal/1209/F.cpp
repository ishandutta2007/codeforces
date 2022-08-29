#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD 1000000007
void *wmem;
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
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for(i=0;i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=0;i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
struct mint{
  static unsigned md;
  static unsigned W;
  static unsigned R;
  static unsigned Rinv;
  static unsigned mdninv;
  static unsigned RR;
  unsigned val;
  mint(){
  }
  mint(int a){
    val = mulR(a);
  }
  mint(unsigned a){
    val = mulR(a);
  }
  mint(long long a){
    val = mulR(a);
  }
  mint(unsigned long long a){
    val = mulR(a);
  }
  int get_inv(long long a, int md){
    long long t=a;
    long long s=md;
    long long u=1;
    long long v=0;
    long long e;
    while(s){
      e=t/s;
      t-=e*s;
      u-=e*v;
      swap(t,s);
      swap(u,v);
    }
    if(u<0){
      u+=md;
    }
    return u;
  }
  void setmod(unsigned m){
    int i;
    unsigned t;
    W = 32;
    md = m;
    R = (1ULL << W) % md;
    RR = (unsigned long long)R*R % md;
    switch(m){
      case 104857601:
      Rinv = 2560000;
      mdninv = 104857599;
      break;
      case 998244353:
      Rinv = 232013824;
      mdninv = 998244351;
      break;
      case 1000000007:
      Rinv = 518424770;
      mdninv = 2226617417U;
      break;
      case 1000000009:
      Rinv = 171601999;
      mdninv = 737024967;
      break;
      case 1004535809:
      Rinv = 234947584;
      mdninv = 1004535807;
      break;
      case 1007681537:
      Rinv = 236421376;
      mdninv = 1007681535;
      break;
      case 1012924417:
      Rinv = 238887936;
      mdninv = 1012924415;
      break;
      case 1045430273:
      Rinv = 254466304;
      mdninv = 1045430271;
      break;
      case 1051721729:
      Rinv = 257538304;
      mdninv = 1051721727;
      break;
      default:
      Rinv = get_inv(R, md);
      mdninv = 0;
      t = 0;
      for(i=0;i<((int)W);i++){
        if(t%2==0){
          t+=md;
          mdninv |= (1U<<i);
        }
        t /= 2;
      }
    }
  }
  unsigned mulR(unsigned a){
    return (unsigned long long)a*R%md;
  }
  unsigned mulR(int a){
    if(a < 0){
      a = a%((int)md)+(int)md;
    }
    return mulR((unsigned)a);
  }
  unsigned mulR(unsigned long long a){
    return mulR((unsigned)(a%md));
  }
  unsigned mulR(long long a){
    a %= md;
    if(a < 0){
      a += md;
    }
    return mulR((unsigned)a);
  }
  unsigned reduce(unsigned T){
    unsigned m = T * mdninv;
    unsigned t = (unsigned)((T + (unsigned long long)m*md) >> W);
    if(t >= md){
      t -= md;
    }
    return t;
  }
  unsigned reduce(unsigned long long T){
    unsigned m = (unsigned)T * mdninv;
    unsigned t = (unsigned)((T + (unsigned long long)m*md) >> W);
    if(t >= md){
      t -= md;
    }
    return t;
  }
  unsigned get(){
    return reduce(val);
  }
  mint &operator+=(mint a){
    val += a.val;
    if(val >= md){
      val -= md;
    }
    return *this;
  }
  mint &operator-=(mint a){
    if(val < a.val){
      val = val + md - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  mint &operator*=(mint a){
    val = reduce((unsigned long long)val*a.val);
    return *this;
  }
  mint &operator/=(mint a){
    return *this *= a.inverse();
  }
  mint operator+(mint a){
    return mint(*this)+=a;
  }
  mint operator-(mint a){
    return mint(*this)-=a;
  }
  mint operator*(mint a){
    return mint(*this)*=a;
  }
  mint operator/(mint a){
    return mint(*this)/=a;
  }
  mint operator+(int a){
    return mint(*this)+=mint(a);
  }
  mint operator-(int a){
    return mint(*this)-=mint(a);
  }
  mint operator*(int a){
    return mint(*this)*=mint(a);
  }
  mint operator/(int a){
    return mint(*this)/=mint(a);
  }
  mint operator+(long long a){
    return mint(*this)+=mint(a);
  }
  mint operator-(long long a){
    return mint(*this)-=mint(a);
  }
  mint operator*(long long a){
    return mint(*this)*=mint(a);
  }
  mint operator/(long long a){
    return mint(*this)/=mint(a);
  }
  mint operator-(void){
    mint res;
    if(val){
      res.val=md-val;
    }
    else{
      res.val=0;
    }
    return res;
  }
  operator bool(void){
    return val!=0;
  }
  operator int(void){
    return get();
  }
  operator long long(void){
    return get();
  }
  mint inverse(){
    int a = val;
    int b = md;
    int u = 1;
    int v = 0;
    int t;
    mint res;
    while(b){
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if(u < 0){
      u += md;
    }
    res.val = (unsigned long long)u*RR % md;
    return res;
  }
  mint pw(unsigned long long b){
    mint a(*this);
    mint res;
    res.val = R;
    while(b){
      if(b&1){
        res *= a;
      }
      b >>= 1;
      a *= a;
    }
    return res;
  }
  bool operator==(int a){
    return mulR(a)==val;
  }
  bool operator!=(int a){
    return mulR(a)!=val;
  }
}
;
unsigned mint::md;
unsigned mint::W;
unsigned mint::R;
unsigned mint::Rinv;
unsigned mint::mdninv;
unsigned mint::RR;
mint operator+(int a, mint b){
  return mint(a)+=b;
}
mint operator-(int a, mint b){
  return mint(a)-=b;
}
mint operator*(int a, mint b){
  return mint(a)*=b;
}
mint operator/(int a, mint b){
  return mint(a)/=b;
}
mint operator+(long long a, mint b){
  return mint(a)+=b;
}
mint operator-(long long a, mint b){
  return mint(a)-=b;
}
mint operator*(long long a, mint b){
  return mint(a)*=b;
}
mint operator/(long long a, mint b){
  return mint(a)/=b;
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar(a);
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(mint x){
  int i;
  i = (int)x;
  wt_L(i);
}
struct graph{
  int N;
  int *es;
  int **edge;
  void setDirectEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    walloc1d(&edge[0], M, mem);
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      es[A[i]]++;
    }
    for(i=0;i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
    }
  }
}
;
template<class T> struct wgraph{
  int N;
  int *es;
  int **edge;
  T **cost;
  graph g;
  void setDirectEdge(int N__, int M, int A[], int B[], T C[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      es[A[i]]++;
    }
    walloc1d(&edge, N, mem);
    for(i=0;i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    walloc1d(&cost, N, mem);
    for(i=0;i<(N);i++){
      walloc1d(&cost[i], es[i], mem);
    }
    for(i=0;i<(N);i++){
      es[i] = 0;
    }
    for(i=0;i<(M);i++){
      edge[A[i]][es[A[i]]] = B[i];
      cost[A[i]][es[A[i]]++] = C[i];
    }
    g.N = N;
    g.es = es;
    g.edge = edge;
  }
}
;
int N;
int M;
int X[100000];
int Y[100000];
int nn;
int mm;
int A[2000000];
int B[2000000];
int C[2000000];
wgraph<int> g;
vector<int> con[2000000];
mint res[2000000];
int aa[2000000];
int cc[2000000];
int es;
int q[2000000];
int qs;
int qe;
int vis[2000000];
int main(){
  wmem = memarr;
  {
    mint x;
    x.setmod(MD);
  }
  int i;
  int j;
  int k;
  int d[10];
  int ds;
  int p;
  int pv;
  int s;
  mint now;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(M);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);X[Lj4PdHRW] += (-1);
      rd(Y[Lj4PdHRW]);Y[Lj4PdHRW] += (-1);
    }
  }
  nn = N;
  for(i=0;i<(M);i++){
    k = i + 1;
    ds = 0;
    while(k){
      d[ds++] = k % 10;
      k /= 10;
    }
    for(k = ds-1; k>=0; k--){
      if(k==ds-1){
        A[mm] =X[i];
      }
      else{
        A[mm] =nn-1;
      }
      if(k==0){
        B[mm] =Y[i];
      }
      else{
        B[mm] =nn++;
      }
      C[mm++] = d[k];
    }
    for(k = ds-1; k>=0; k--){
      if(k==ds-1){
        A[mm] =Y[i];
      }
      else{
        A[mm] =nn-1;
      }
      if(k==0){
        B[mm] =X[i];
      }
      else{
        B[mm] =nn++;
      }
      C[mm++] = d[k];
    }
  }
  g.setDirectEdge(nn, mm, A, B, C);
  vis[0] = 1;
  q[qe++] = 0;
  while(qs < qe){
    i = q[qs++];
    now = res[i];
    es = 0;
    con[i].push_back(i);
    for(j=0;j<(con[i].size());j++){
      s = con[i][j];
      for(k=0;k<(g.es[s]);k++){
        aa[es] = g.edge[s][k];
        cc[es++] = g.cost[s][k];
      }
    }
    sortA_L(es, cc, aa);
    pv = -1;
    for(i=0;i<(es);i++){
      k = aa[i];
      if(vis[k]){
        continue;
      }
      vis[k] = 1;
      res[k] = 10* now + cc[i];
      if(pv != cc[i]){
        p = k;
        pv = cc[i];
        q[qe++] = k;
      }
      else{
        con[p].push_back(k);
      }
    }
  }
  for(i=(1);i<(N);i++){
    wt_L(res[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int N, M, X[1d5], Y[1d5];
// int nn, mm, A[2d6], B[2d6], C[2d6];
// 
// wgraph<int> g;
// vector<int> con[2d6];
// 
// mint res[2d6];
// 
// int aa[2d6], cc[2d6], es;
// int q[2d6], qs, qe;
// int vis[2d6];
// 
// {
//   int i, j, k, d[10], ds, p, pv, s;
//   mint now;
//   rd(N,M,(X--,Y--)(M));
// 
//   nn = N;
//   rep(i,M){
//     k = i + 1;
//     ds = 0;
//     while(k) d[ds++] = k % 10, k /= 10;
//     for(k = ds-1; k>=0; k--){
//       A[mm] = if[k==ds-1, X[i], nn-1];
//       B[mm] = if[k==0, Y[i], nn++];
//       C[mm++] = d[k];
//     }
//     for(k = ds-1; k>=0; k--){
//       A[mm] = if[k==ds-1, Y[i], nn-1];
//       B[mm] = if[k==0, X[i], nn++];
//       C[mm++] = d[k];
//     }
//   }
// 
//   g.setDirectEdge(nn, mm, A, B, C);
// 
//   vis[0] = 1;
//   q[qe++] = 0;
//   while(qs < qe){
//     i = q[qs++];
//     now = res[i];
//     es = 0;
//     con[i].push_back(i);
//     rep(j,con[i].size()){
//       s = con[i][j];
//       rep(k,g.es[s]){
//         aa[es] = g.edge[s][k];
//         cc[es++] = g.cost[s][k];
//       }
//     }
// 
//     sortA(es, cc, aa);
//     pv = -1;
//     rep(i,es){
//       k = aa[i];
//       if(vis[k]) continue;
//       vis[k] = 1;
//       res[k] = 10 now + cc[i];
//       if(pv != cc[i]){
//         p = k;
//         pv = cc[i];
//         q[qe++] = k;
//       } else {
//         con[p].push_back(k);
//       }
//     }
//   }
// 
//   rep(i,1,N) wt(res[i]);
// }