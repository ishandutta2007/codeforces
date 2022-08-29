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
}
;
int N;
int M;
int A[200000];
int B[200000];
int K;
int P[200000];
graph g;
graph rg;
int d[200000];
int main(){
  int i;
  wmem = memarr;
  int a;
  int b;
  int res1 = 0;
  int res2 = 0;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
    }
  }
  rd(K);
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(K);e98WHCEY++){
      rd(P[e98WHCEY]);P[e98WHCEY] += (-1);
    }
  }
  g.setDirectEdge(N,M,A,B);
  rg.setDirectEdge(N,M,B,A);
  rg.getDist(P[K-1], d);
  for(i=(1);i<(K);i++){
    int WYIGIcGE;
    a = P[i-1];
    b = P[i];
    if(d[a] != d[b] + 1){
      res1++;
      res2++;
      continue;
    }
    for(WYIGIcGE=(0);WYIGIcGE<(g.es[a]);WYIGIcGE++){
      auto &j = g.edge[a][WYIGIcGE];
      if(j != b && d[a] == d[j] + 1){
        res2++;
        break;
      }
    }
  }
  wt_L(res1);
  wt_L(' ');
  wt_L(res2);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200227-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[2d5], K, P[2d5];
// graph g, rg;
// int d[2d5];
// {
//   int a, b, res1 = 0, res2 = 0;
//   rd(N,M,(A--,B--)(M),K,(P--)(K));
//   g.setDirectEdge(N,M,A,B);
//   rg.setDirectEdge(N,M,B,A);
//   rg.getDist(P[K-1], d);
// 
//   rep(i,1,K){
//     a = P[i-1];
//     b = P[i];
// 
//     if(d[a] != d[b] + 1) res1++, res2++, continue;
//     rep[g.edge[a]](j,g.es[a]){
//       if(j != b && d[a] == d[j] + 1) res2++, break;
//     }
//   }
// 
//   wt(res1, res2);
// }