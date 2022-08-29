#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
struct rollbackUnionFind{
  int*d;
  int N;
  int M;
  int*h1;
  int*h2;
  int sz;
  int snapsz;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    h1 = (int*)std::malloc(2*n*sizeof(int));
    h2 = (int*)std::malloc(2*n*sizeof(int));
    M = n;
  }
  inline void malloc(const int n, const int fg){
    d = (int*)std::malloc(n*sizeof(int));
    h1 = (int*)std::malloc(2*n*sizeof(int));
    h2 = (int*)std::malloc(2*n*sizeof(int));
    M = n;
    if(fg){
      init(n);
    }
  }
  inline void free(void){
    std::free(d);
    std::free(h1);
    std::free(h2);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    walloc1d(&h1, 2*n, mem);
    walloc1d(&h2, 2*n, mem);
    M = n;
  }
  inline void walloc(const int n, const int fg, void **mem=&wmem){
    walloc1d(&d, n, mem);
    walloc1d(&h1, 2*n, mem);
    walloc1d(&h2, 2*n, mem);
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
    sz = 0;
    snapsz = 0;
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    while(d[a]>=0){
      a=d[a];
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
    h1[sz] = a;
    h2[sz] = d[a];
    sz++;
    h1[sz] = b;
    h2[sz] = d[b];
    sz++;
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
  inline int undo(void){
    if(sz==0){
      return 0;
    }
    sz--;
    d[h1[sz]] = h2[sz];
    sz--;
    d[h1[sz]] = h2[sz];
    if(snapsz > sz){
      snapsz = sz;
    }
    return 1;
  }
  inline void snapshot(void){
    snapsz = sz;
  }
  inline void rollback(void){
    while(snapsz < sz){
      sz--;
      d[h1[sz]] = h2[sz];
      sz--;
      d[h1[sz]] = h2[sz];
    }
  }
}
;
int N;
int M;
int K;
int C[500000];
int A[500000];
int B[500000];
int ng[500000];
map<pair<int,int>,int> c2;
vector<int> ind[500000];
int main(){
  int i, k;
  wmem = memarr;
  int x;
  int y;
  int z = 0;
  pair<int,int> p;
  long long res;
  long long ok = 0;
  rollbackUnionFind uf;
  rd(N);
  rd(M);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(C[Lj4PdHRW]);C[Lj4PdHRW] += (-1);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(M);e98WHCEY++){
      rd(A[e98WHCEY]);A[e98WHCEY] += (-1);
      rd(B[e98WHCEY]);B[e98WHCEY] += (-1);
    }
  }
  uf.walloc(2*N, 1);
  for(i=(0);i<(M);i++){
    {
      auto WYIGIcGE = (A[i]);
      auto t_ynMSdg = ( B[i]);
      x = WYIGIcGE;
      y = t_ynMSdg;
    }
    if(C[x] == C[y]){
      uf(x,y+N);
      uf(x+N,y);
      continue;
    }
    p = make_pair(min_L(C[x], C[y]),max_L(C[x], C[y]));
    if(c2.count(p)==0){
      c2[p] = z++;
    }
    ind[c2[p]].push_back(i);
  }
  for(i=(0);i<(N);i++){
    if(uf(i)==uf(i+N)){
      ng[C[i]] = 1;
    }
  }
  for(i=(0);i<(K);i++){
    if(!ng[i]){
      ok++;
    }
  }
  res = ok * (ok-1) / 2;
  uf.snapshot();
  for(k=(0);k<(z);k++){
    if(ng[C[A[ind[k][0]]]] || ng[C[B[ind[k][0]]]]){
      continue;
    }
    uf.rollback();
    for(int i : ind[k]){
      uf(A[i], B[i]+N);
      uf(A[i]+N, B[i]);
    }
    for(int i : ind[k]){
      if(uf(A[i]) == uf(A[i]+N) || uf(B[i]) == uf(B[i]+N)){
        res--;
        goto APIVbQlN;
      }
    }
    APIVbQlN:;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20201102-1

// --- original code ---
// //no-unlocked
// int N, M, K, C[5d5], A[5d5], B[5d5];
// int ng[5d5];
// map<pair<int,int>,int> c2;
// vector<int> ind[5d5];
// {
//   int x, y, z = 0;
//   pair<int,int> p;
//   ll res, ok = 0;
//   rollbackUnionFind uf;
//   rd(N,M,K,(C--)(N),(A--,B--)(M));
//   uf.walloc(2N, 1);
// 
//   rep(i,M){
//     (x, y) = (A[i], B[i]);
//     if(C[x] == C[y]) uf(x,y+N), uf(x+N,y), continue;
//     p = make_pair(min(C[x], C[y]), max(C[x], C[y]));
//     if(c2.count(p)==0) c2[p] = z++;
//     ind[c2[p]].push_back(i);
//   }
// 
//   rep(i,N) if(uf(i)==uf(i+N)) ng[C[i]] = 1;
//   rep(i,K) if(!ng[i]) ok++;
//   res = ok * (ok-1) / 2;
// 
//   uf.snapshot();
//   rep(k,z){
//     if(ng[C[A[ind[k][0]]]] || ng[C[B[ind[k][0]]]]) continue;
//     uf.rollback();
//     for(int i : ind[k]) uf(A[i], B[i]+N),  uf(A[i]+N, B[i]);
//     for(int i : ind[k]) if(uf(A[i]) == uf(A[i]+N) || uf(B[i]) == uf(B[i]+N)) res--, break_continue;
//   }
// 
//   wt(res);
// }