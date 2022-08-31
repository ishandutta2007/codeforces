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
int M;
int A[200000];
int B[200000];
int tmp[200000];
int deg[200000];
graph g;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int res = 1;
    int ok = 0;
    int now = 0;
    set<int> s;
    set<int>::iterator it;
    rd(N);
    M = 0;
    for(i=(0);i<(N);i++){
      int FmcKpFmN;
      int xr20shxY = rd_int();
      for(FmcKpFmN=(0);FmcKpFmN<(xr20shxY);FmcKpFmN++){
        A[M] = rd_int() - 1;
        B[M++] = i;
      }
    }
    g.setDirectEdge(N,M,A,B);
    for(i=(0);i<(N);i++){
      deg[i] = 0;
    }
    for(i=(0);i<(M);i++){
      deg[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      if(!deg[i]){
        s.insert(i);
      }
    }
    while(s.size()){
      int jZyWAPpY;
      it = s.lower_bound(now);
      if(it == s.end()){
        now = 0;
        res++;
        continue;
      }
      ok++;
      now = *it;
      s.erase(now);
      for(jZyWAPpY=(0);jZyWAPpY<(g.es[now]);jZyWAPpY++){
        auto&i = g.edge[now][jZyWAPpY];
        deg[i]--;
        if(deg[i]==0){
          s.insert(i);
        }
      }
    }
    if(ok!=N){
      wt_L(-1);
      wt_L('\n');
    }
    else{
      wt_L(res);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210917-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[], tmp[];
// int deg[];
// graph g;
// {
//   REP(rd_int()){
//     int res = 1, ok = 0, now = 0;
//     set<int> s;
//     set<int>::iterator it;
// 
//     rd(N);
//     M = 0;
//     rep(i,N) REP(rd_int()){
//       A[M] = rd_int() - 1;
//       B[M++] = i;
//     }
//     g.setDirectEdge(N,M,A,B);
//     rep(i,N) deg[i] = 0;
//     rep(i,M) deg[B[i]]++;
//     rep(i,N) if(!deg[i]) s.insert(i);
// 
//     while(s.size()){
//       it = s.lower_bound(now);
//       if(it == s.end()){
//         now = 0;
//         res++;
//         continue;
//       }
// 
//       ok++;
//       now = *it;
//       s.erase(now);
//       rep[g.edge[now]](i,g.es[now]){
//         deg[i]--;
//         if(deg[i]==0) s.insert(i);
//       }
//     }
//     wt(if[ok!=N, -1, res]);
//   }
// }