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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
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
  int TopologicalSort(int res[], void *mem=wmem){
    int i;
    int j;
    int k;
    int rs;
    int *deg;
    int *q;
    int qs = 0;
    int qe = 0;
    walloc1d(&deg, N, &mem);
    walloc1d(&q, N, &mem);
    rs = 0;
    for(i=(0);i<(N);i++){
      deg[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        deg[edge[i][j]]++;
      }
    }
    for(i=(0);i<(N);i++){
      if(deg[i]==0){
        q[qe++] = i;
      }
    }
    while(qs < qe){
      i = q[qs++];
      res[rs++] = i;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        deg[k]--;
        if(deg[k]==0){
          q[qe++] = k;
        }
      }
    }
    if(rs==N){
      return 1;
    }
    return 0;
  }
}
;
int N;
int M;
int A[200000];
int B[200000];
graph g1;
graph g2;
int ress;
char res[200000+1];
int v1[200000];
int v2[200000];
int tmp[200000];
void dfs(graph &g, int n, int vis[]){
  int Lj4PdHRW;
  if(vis[n]){
    return;
  }
  vis[n] = 1;
  for(Lj4PdHRW=(0);Lj4PdHRW<(g.es[n]);Lj4PdHRW++){
    auto &i = g.edge[n][Lj4PdHRW];
    dfs(g,i,vis);
  }
}
int main(){
  wmem = memarr;
  int i;
  int j;
  rd(N);
  rd(M);
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(M);e98WHCEY++){
      rd(A[e98WHCEY]);A[e98WHCEY] += (-1);
      rd(B[e98WHCEY]);B[e98WHCEY] += (-1);
    }
  }
  g1.setDirectEdge(N,M,A,B);
  g2.setDirectEdge(N,M,B,A);
  if(g1.TopologicalSort(tmp)==0){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N);i++){
    res[i] = 'E';
    if(v1[i]==0 && v2[i]==0){
      res[i] = 'A';
      ress++;
    }
    dfs(g1, i, v1);
    dfs(g2, i, v2);
  }
  wt_L(ress);
  wt_L('\n');
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[2d5];
// graph g1, g2;
// 
// int ress; char res[2d5+1];
// int v1[2d5], v2[2d5];
// int tmp[2d5];
// 
// void dfs(graph &g, int n, int vis[]){
//   if(vis[n]) return;
//   vis[n] = 1;
//   rep[g.edge[n]](i,g.es[n]) dfs(g,i,vis);
// }
// 
// {
//   int i, j;
//   rd(N,M,(A--,B--)(M));
//   g1.setDirectEdge(N,M,A,B);
//   g2.setDirectEdge(N,M,B,A);
//   if(g1.TopologicalSort(tmp)==0) wt(-1), return 0;
//   
//   rep(i,N){
//     res[i] = 'E';
//     if(v1[i]==0 && v2[i]==0) res[i] = 'A', ress++;
//     dfs(g1, i, v1);
//     dfs(g2, i, v2);
//   }
// 
//   wt(ress);
//   wt(res);
// }