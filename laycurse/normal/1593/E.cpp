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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
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
  int TreeDiameter(int &a, int &b, void *mem = wmem){
    int i;
    int mx;
    int*d;
    walloc1d(&d, N, &mem);
    getDist(0, d, mem);
    mx = -1;
    for(i=(0);i<(N);i++){
      if(mx < d[i]){
        mx = d[i];
        a = i;
      }
    }
    getDist(a, d, mem);
    mx = -1;
    for(i=(0);i<(N);i++){
      if(mx < d[i]){
        mx = d[i];
        b = i;
      }
    }
    return mx;
  }
  int TreeDiameter(void *mem = wmem){
    int a;
    int b;
    return TreeDiameter(a, b, mem);
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
int K;
int A[400000];
int B[400000];
int ps;
int p[400000];
int chk[400000];
int d[400000];
int x;
int y;
int c;
graph g;
void dfs(int n, int b = -1){
  int Lj4PdHRW;
  d[n] = 0;
  for(Lj4PdHRW=(0);Lj4PdHRW<(g.es[n]);Lj4PdHRW++){
    auto&i = g.edge[n][Lj4PdHRW];
    if(i!=b){
      dfs(i, n);
      chmax(d[n], d[i] + 1);
    }
  }
  chmin(chk[n], d[n]);
}
int main(){
  int e98WHCEY;
  wmem = memarr;
  int cTE1_r3A = rd_int();
  for(e98WHCEY=(0);e98WHCEY<(cTE1_r3A);e98WHCEY++){
    int i;
    rd(N);
    rd(K);
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N-1);xr20shxY++){
        rd(A[xr20shxY]);A[xr20shxY] += (-1);
        rd(B[xr20shxY]);B[xr20shxY] += (-1);
      }
    }
    g.setEdge(N,N-1,A,B);
    g.TreeDiameter(x, y);
    ps = g.shortestPath(x, y, p);
    for(i=(0);i<(N);i++){
      chk[i] = 1073709056;
    }
    dfs(p[ps/2]);
    dfs(p[(ps+1)/2]);
    int tU__gIr_;
    remove_reference<decltype(1)>::type a2conNHc;
    int hCmBdyQB = 0;
    if((0) > ((N)-1)){
      a2conNHc = 0;
    }
    else{
      for(tU__gIr_ = 0; tU__gIr_ <= (N)-1; tU__gIr_++){
        if(chk[tU__gIr_] >= K){
          if(hCmBdyQB == 0){
            a2conNHc = 1;
            hCmBdyQB = 1;
            continue;
          }
          a2conNHc += 1;
        }
      }
      if(hCmBdyQB==0){
        a2conNHc = 0;
      }
    }
    wt_L(a2conNHc);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int N, K, A[4d5], B[];
// int ps, p[], chk[], d[], x, y, c;
// graph g;
// 
// void dfs(int n, int b = -1){
//   d[n] = 0;
//   rep[g.edge[n]](i,g.es[n]) if(i!=b){
//     dfs(i, n);
//     d[n] >?= d[i] + 1;
//   }
//   chk[n] <?= d[n];
// }
// 
// {
//   REP(rd_int()){
//     rd(N,K,(A--,B--)(N-1));
//     g.setEdge(N,N-1,A,B);
//     g.TreeDiameter(x, y);
//     ps = g.shortestPath(x, y, p);
//     rep(i,N) chk[i] = int_inf;
//     dfs(p[ps/2]);
//     dfs(p[(ps+1)/2]);
//     wt(sum[i,0,N @ chk[i] >= K](1));
//   }
// }