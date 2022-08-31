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
inline void rd(long long &x){
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
  int bipartite(int res[] = NULL, void *mem = wmem){
    int i;
    int j;
    int k;
    int x;
    int*st;
    int sts;
    if(res==NULL){
      walloc1d(&res, N, &mem);
    }
    walloc1d(&st, N, &mem);
    for(i=(0);i<(N);i++){
      res[i] = -1;
    }
    for(x=(0);x<(N);x++){
      if(res[x]==-1){
        res[x] = 0;
        sts = 0;
        st[sts++] = x;
        while(sts){
          i = st[--sts];
          for(j=(0);j<(es[i]);j++){
            k = edge[i][j];
            if(res[k]==-1){
              res[k] = 1 - res[i];
              st[sts++] = k;
            }
            if(res[i] + res[k] != 1){
              return 0;
            }
          }
        }
      }
    }
    return 1;
  }
}
;
int N;
int M;
int A[200000];
int B[200000];
graph g;
int con[200000];
int f;
long long X[200000];
long long Y[200000];
long long c;
long long c1;
long long c2;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(X[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
        rd(Y[xr20shxY]);
      }
    }
    {
      int KrdatlYV;
      for(KrdatlYV=(0);KrdatlYV<(M);KrdatlYV++){
        rd(A[KrdatlYV]);A[KrdatlYV] += (-1);
        rd(B[KrdatlYV]);B[KrdatlYV] += (-1);
      }
    }
    g.setEdge(N,M,A,B);
    f = g.bipartite(con);
    if(f){
      int i;
      c1 = c2 = 0;
      for(i=(0);i<(N);i++){
        if(con[i]){
          c1+= Y[i] - X[i];
        }
        else{
          c2+= Y[i] - X[i];
        }
      }
      if(c1 != c2){
        wt_L("NO");
        wt_L('\n');
        continue;
      }
    }
    else{
      int i;
      c = 0;
      for(i=(0);i<(N);i++){
        c += Y[i] - X[i];
      }
      if(c % 2){
        wt_L("NO");
        wt_L('\n');
        continue;
      }
    }
    wt_L("YES");
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210613-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[];
// graph g;
// int con[], f;
// ll X[], Y[], c, c1, c2;
// {
//   REP(rd_int()){
//     rd(N,M,X(N),Y(N),(A--,B--)(M));
//     g.setEdge(N,M,A,B);
//     f = g.bipartite(con);
//     if(f){
//       c1 = c2 = 0;
//       rep(i,N) if[con[i], c1, c2] += Y[i] - X[i];
//       if(c1 != c2) wt("NO"), continue;
//     } else {
//       c = 0;
//       rep(i,N) c += Y[i] - X[i];
//       if(c % 2) wt("NO"), continue;
//     }
//     wt("YES");
//   }
// }