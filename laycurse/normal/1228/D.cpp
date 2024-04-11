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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
struct graph{
  int N;
  int *es;
  int **edge;
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
int A[300000];
int B[300000];
int res[100000];
int sz[4];
int vis[100000];
int main(){
  int i;
  wmem = memarr;
  int con = 0;
  graph g;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
    }
  }
  g.setEdge(N,M,A,B);
  for(i=(0);i<(N);i++){
    if(g.es[i]==0){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
  }
  for(i=(0);i<(N);i++){
    sortA_L(g.es[i], g.edge[i]);
  }
  for(i=(0);i<(N);i++){
    if(res[i]==0){
      int j;
      con++;
      if(con > 3){
        wt_L(-1);
        wt_L('\n');
        return 0;
      }
      res[i] = con;
      for(j=(i+1);j<(N);j++){
        if(g.es[j] == g.es[i]){
          int k;
          for(k=(0);k<(g.es[i]);k++){
            if(g.edge[i][k] != g.edge[j][k]){
              break;
            }
          }
          if(k < g.es[i]){
            continue;
          }
          res[j] = con;
        }
      }
    }
  }
  if(con != 3){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N);i++){
    sz[res[i]]++;
  }
  for(i=(0);i<(N);i++){
    if(g.es[i] != N - sz[res[i]]){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
  }
  {
    int KL2GvlyY;
    if(N==0){
      putchar('\n');
    }
    else{
      for(KL2GvlyY=(0);KL2GvlyY<(N-1);KL2GvlyY++){
        wt_L(res[KL2GvlyY]);
        wt_L(' ');
      }
      wt_L(res[KL2GvlyY]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191006-1

// --- original code ---
// //no-unlocked
// int N, M, A[3d5], B[3d5];
// int res[1d5], sz[4], vis[1d5];
// {
//   int con = 0;
//   graph g;
//   rd(N,M,(A--,B--)(M));
//   g.setEdge(N,M,A,B);
// 
//   rep(i,N) if(g.es[i]==0) wt(-1), return 0;
//   rep(i,N) sortA(g.es[i], g.edge[i]);
// 
//   rep(i,N) if(res[i]==0){
//     con++;
//     if(con > 3) wt(-1), return 0;
//     res[i] = con;
//     rep(j,i+1,N) if(g.es[j] == g.es[i]){
//       rep(k,g.es[i]) if(g.edge[i][k] != g.edge[j][k]) break;
//       if(k < g.es[i]) continue;
//       res[j] = con;
//     }
//   }
//   if(con != 3) wt(-1), return 0;
// 
//   rep(i,N) sz[res[i]]++;
//   rep(i,N) if(g.es[i] != N - sz[res[i]]) wt(-1), return 0;
// 
//   wt(res(N));
// }