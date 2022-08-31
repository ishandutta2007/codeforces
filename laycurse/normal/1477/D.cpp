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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
int M;
int A[500000];
int B[500000];
int P[500000];
int Q[500000];
int num;
graph g;
set<int> unvis;
int dfs(int n, int u, int ls){
  int i;
  int k = 0;
  int ok = 0;
  vector<int> nx;
  vector<int> nd;
  for(int i : unvis){
    while(k < g.es[n] && g.edge[n][k] < i){
      k++;
    }
    if(k < g.es[n] && g.edge[n][k] == i){
      continue;
    }
    nx.push_back(i);
  }
  if(ls == 1){
    nd.push_back(u);
  }
  for(i=(0);i<(nx.size());i++){
    unvis.erase(nx[i]);
  }
  for(i=(0);i<(nx.size());i++){
    if(i == nx.size()-1 && nd.size() == 0){
      dfs(nx[i], n, 1);
      ok = 1;
    }
    else{
      if(dfs(nx[i], n, 0)){
        nd.push_back(nx[i]);
      }
    }
  }
  if(nd.size()){
    P[n] = num;
    for(i=(0);i<(nd.size());i++){
      P[nd[i]] = num + i + 1;
    }
    Q[n] = num + nd.size();
    for(i=(0);i<(nd.size());i++){
      Q[nd[i]] = num + i;
    }
    num += nd.size() + 1;
    ok = 1;
  }
  if(!ok && u == -1){
    P[n] = Q[n] = num++;
    ok = 1;
  }
  return 1 - ok;
}
int main(){
  int tU__gIr_;
  wmem = memarr;
  int a2conNHc = rd_int();
  for(tU__gIr_=(0);tU__gIr_<(a2conNHc);tU__gIr_++){
    int i;
    num = 1;
    unvis.clear();
    rd(N);
    rd(M);
    {
      int APIVbQlN;
      for(APIVbQlN=(0);APIVbQlN<(M);APIVbQlN++){
        rd(A[APIVbQlN]);A[APIVbQlN] += (-1);
        rd(B[APIVbQlN]);B[APIVbQlN] += (-1);
      }
    }
    g.setEdge(N,M,A,B);
    for(i=(0);i<(N);i++){
      sortA_L(g.es[i], g.edge[i]);
    }
    for(i=(0);i<(N);i++){
      unvis.insert(i);
    }
    for(i=(0);i<(N);i++){
      if(unvis.count(i)){
        unvis.erase(i);
        dfs(i, -1, 0);
      }
    }
    {
      int BUotOFBp;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(BUotOFBp=(0);BUotOFBp<(N-1);BUotOFBp++){
          wt_L(P[BUotOFBp]);
          wt_L(' ');
        }
        wt_L(P[BUotOFBp]);
        wt_L('\n');
      }
    }
    {
      int gEg5UqEA;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(gEg5UqEA=(0);gEg5UqEA<(N-1);gEg5UqEA++){
          wt_L(Q[gEg5UqEA]);
          wt_L(' ');
        }
        wt_L(Q[gEg5UqEA]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// int N, M, A[5d5], B[5d5];
// int P[5d5], Q[5d5], num;
// graph g;
// set<int> unvis;
// 
// int dfs(int n, int u, int ls){
//   int k = 0, ok = 0;
//   vector<int> nx, nd;
//   // puts("");
//   // wt(n,u,ls);
//   for(int i : unvis){
//     while(k < g.es[n] && g.edge[n][k] < i) k++;
//     if(k < g.es[n] && g.edge[n][k] == i) continue;
//     nx.push_back(i);
//   }
//   if(ls == 1) nd.push_back(u);
//   rep(i,nx.size()) unvis.erase(nx[i]);
//   rep(i,nx.size()){
//     if(i == nx.size()-1 && nd.size() == 0){
//       dfs(nx[i], n, 1);
//       ok = 1;
//     } else {
//       if(dfs(nx[i], n, 0)) nd.push_back(nx[i]);
//     }
//   }
//   if(nd.size()){
//     P[n] = num;
//     rep(i,nd.size()) P[nd[i]] = num + i + 1;
//     Q[n] = num + nd.size();
//     rep(i,nd.size()) Q[nd[i]] = num + i;
//     num += nd.size() + 1;
//     ok = 1;
//   }
//   if(!ok && u == -1){
//     P[n] = Q[n] = num++;
//     ok = 1;
//   }
//   return 1 - ok;
// }
// 
// {
//   REP(rd_int()){
//     num = 1;
//     unvis.clear();
//     rd(N,M,(A--,B--)(M));
//     g.setEdge(N,M,A,B);
//     rep(i,N) sortA(g.es[i], g.edge[i]);
//     rep(i,N) unvis.insert(i);
//     rep(i,N) if(unvis.count(i)){
//       unvis.erase(i);
//       dfs(i, -1, 0);
//     }
//     wt(P(N));
//     wt(Q(N));
//   }
// }