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
template<class T> int coordcomp_L(int n, T arr[], int res[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int>*r;
  walloc1d(&r, n, &mem);
  for(i=(0);i<(n);i++){
    r[i].first = arr[i];
    r[i].second = i;
  }
  sort(r, r+n);
  if(res != NULL){
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      res[r[i].second] = k;
    }
  }
  else{
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      arr[r[i].second] = k;
    }
  }
  return k+1;
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
}
;
int N;
int A[200000];
int X[200000];
int Y[200000];
graph g;
int sz;
int st[200000];
int ed[200000];
set<int> s[200000];
int EulerTour(int now, int *es, int **edge, int st[], int ed[], int ind = 0, int bef = -1){
  int i;
  int k;
  st[now] = ind++;
  for(i=(0);i<(es[now]);i++){
    k = edge[now][i];
    if(k==bef){
      continue;
    }
    ind = EulerTour(k, es, edge, st, ed, ind, now);
  }
  ed[now] = ind;
  return ind;
}
int ok[200000];
int up[200000];
void dfs1(int n, int b = -1){
  int Q5VJL1cS;
  set<int>::iterator it;
  ok[n] = 1;
  for(Q5VJL1cS=(0);Q5VJL1cS<(g.es[n]);Q5VJL1cS++){
    auto &i = g.edge[n][Q5VJL1cS];
    if(i==b){
      continue;
    }
    dfs1(i, n);
    if(ok[i]==0){
      ok[n] = 0;
    }
  }
  it = s[A[n]].lower_bound(st[n]);
  it++;
  if(it != s[A[n]].end() && *it < ed[n]){
    ok[n] = 0;
  }
}
void dfs2(int n, int fg = 1, int b = -1){
  int RZTsC2BF, WYIGIcGE;
  set<int>::iterator it;
  int cnt = 0;
  int all = 0;
  int chk;
  it = s[A[n]].begin();
  if(*it < st[n]){
    fg = 0;
  }
  it = s[A[n]].lower_bound(ed[n]);
  if(it != s[A[n]].end()){
    fg = 0;
  }
  up[n] = fg;
  cnt += fg;
  all++;
  for(RZTsC2BF=(0);RZTsC2BF<(g.es[n]);RZTsC2BF++){
    auto &i = g.edge[n][RZTsC2BF];
    if(i==b){
      continue;
    }
    cnt += ok[i];
    all++;
  }
  for(WYIGIcGE=(0);WYIGIcGE<(g.es[n]);WYIGIcGE++){
    auto &i = g.edge[n][WYIGIcGE];
    if(i==b){
      continue;
    }
    chk = 1;
    it = s[A[n]].lower_bound(st[n]+1);
    if(it!=s[A[n]].end() && *it < st[i]){
      chk = 0;
    }
    it = s[A[n]].lower_bound(ed[i]);
    if(it!=s[A[n]].end() && *it < ed[n]){
      chk = 0;
    }
    cnt -= ok[i];
    dfs2(i, chk && cnt==all-1, n);
    cnt += ok[i];
  }
}
int main(){
  int i;
  wmem = memarr;
  rd(N);
  {
    int ao_dF3pO;
    for(ao_dF3pO=(0);ao_dF3pO<(N);ao_dF3pO++){
      rd(A[ao_dF3pO]);
    }
  }
  {
    int hCmBdyQB;
    for(hCmBdyQB=(0);hCmBdyQB<(N-1);hCmBdyQB++){
      rd(X[hCmBdyQB]);X[hCmBdyQB] += (-1);
      rd(Y[hCmBdyQB]);Y[hCmBdyQB] += (-1);
    }
  }
  g.setEdge(N,N-1,X,Y);
  sz = EulerTour(0, g.es, g.edge, st, ed);
  coordcomp_L(N,A);
  for(i=(0);i<(N);i++){
    s[A[i]].insert(st[i]);
  }
  dfs1(0);
  dfs2(0);
  {
    int jbtyPBGc;
    remove_reference<decltype(ok[jbtyPBGc]*up[jbtyPBGc])>::type ZIeRIny5;
    int iMWUTgY_ = 0;
    if((0) > ((N)-1)){
      ZIeRIny5 = 0;
    }
    else{
      for(jbtyPBGc = 0; jbtyPBGc <= (N)-1; jbtyPBGc++){
        if(iMWUTgY_ == 0){
          ZIeRIny5 = ok[jbtyPBGc]*up[jbtyPBGc];
          iMWUTgY_ = 1;
          continue;
        }
        ZIeRIny5 += ok[jbtyPBGc]*up[jbtyPBGc];
      }
    }
    wt_L(ZIeRIny5);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// int N, A[2d5], X[2d5], Y[2d5];
// graph g;
// int sz, st[2d5], ed[2d5];
// set<int> s[2d5];
// 
// int EulerTour(int now, int *es, int **edge, int st[], int ed[], int ind = 0, int bef = -1){
//   int i, k;
// 
//   st[now] = ind++;
//   rep(i,es[now]){
//     k = edge[now][i];
//     if(k==bef) continue;
//     ind = EulerTour(k, es, edge, st, ed, ind, now);
//   }
//   ed[now] = ind;
//   return ind;
// }
// 
// int ok[2d5], up[2d5];
// 
// void dfs1(int n, int b = -1){
//   set<int>::iterator it;
//   ok[n] = 1;
//   rep[g.edge[n]](i,g.es[n]){
//     if(i==b) continue;
//     dfs1(i, n);
//     if(ok[i]==0) ok[n] = 0;
//   }
//   it = s[A[n]].lower_bound(st[n]);
//   it++;
//   if(it != s[A[n]].end() && *it < ed[n]) ok[n] = 0;
// }
// 
// void dfs2(int n, int fg = 1, int b = -1){
//   set<int>::iterator it;
//   int cnt = 0, all = 0, chk;
// 
//   it = s[A[n]].begin();
//   if(*it < st[n]) fg = 0;
//   it = s[A[n]].lower_bound(ed[n]);
//   if(it != s[A[n]].end()) fg = 0;
//   up[n] = fg;
// 
//   cnt += fg;
//   all++;
//   rep[g.edge[n]](i,g.es[n]){
//     if(i==b) continue;
//     cnt += ok[i];
//     all++;
//   }
// 
//   rep[g.edge[n]](i,g.es[n]){
//     if(i==b) continue;
//     chk = 1;
//     it = s[A[n]].lower_bound(st[n]+1);
//     if(it!=s[A[n]].end() && *it < st[i]) chk = 0;
//     it = s[A[n]].lower_bound(ed[i]);
//     if(it!=s[A[n]].end() && *it < ed[n]) chk = 0;
//     cnt -= ok[i];
//     dfs2(i, chk && cnt==all-1, n);
//     cnt += ok[i];
//   }
// }
// 
// {
//   rd(N,A(N),(X--,Y--)(N-1));
//   g.setEdge(N,N-1,X,Y);
//   sz = EulerTour(0, g.es, g.edge, st, ed);
//   coordcomp(N,A);
//   rep(i,N) s[A[i]].insert(st[i]);
//   dfs1(0);
//   dfs2(0);
//   wt(sum[i,0,N](ok[i]*up[i]));
// }