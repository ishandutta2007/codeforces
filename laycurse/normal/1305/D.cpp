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
int A[1000];
int B[1000];
graph g;
int deg[1000];
int used[1000];
int st[1000];
int sts;
void done(int i){
  int Lj4PdHRW;
  used[i] = 1;
  for(Lj4PdHRW=(0);Lj4PdHRW<(g.es[i]);Lj4PdHRW++){
    auto &j = g.edge[i][Lj4PdHRW];
    if(used[j]==0){
      deg[j]--;
      if(deg[j]==1){
        st[sts++] = j;
      }
    }
  }
}
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  scanf("%d",&N);
  for(i=(0);i<(N-1);i++){
    scanf("%d%d",A+i,B+i);
  }
  for(i=(0);i<(N-1);i++){
    A[i]--;
    B[i]--;
  }
  g.setEdge(N,N-1,A,B);
  for(i=(0);i<(N-1);i++){
    deg[A[i]]++;
    deg[B[i]]++;
  }
  for(i=(0);i<(N);i++){
    if(deg[i]==1){
      st[sts++] = i;
    }
  }
  while(sts >= 2){
    i = st[--sts];
    j = st[--sts];
    done(i);
    done(j);
    printf("? %d %d\n",i+1,j+1);
    fflush(stdout);
    scanf("%d",&k);
    k--;
    if(i==k || j==k){
      printf("! %d\n", k+1);
      fflush(stdout);
      return 0;
    }
  }
  printf("! %d\n", st[0]+1);
  fflush(stdout);
  return 0;
}
// cLay varsion 20200303-1 [beta]

// --- original code ---
// int N, A[1000], B[1000];
// graph g;
// int deg[1000], used[1000], st[1000], sts;
// 
// void done(int i){
//   used[i] = 1;
//   rep[g.edge[i]](j,g.es[i]) if(used[j]==0){
//     deg[j]--;
//     if(deg[j]==1) st[sts++] = j;
//   }
// }
// 
// {
//   int i, j, k;
//   scanf("%d",&N);
//   rep(i,N-1) scanf("%d%d",A+i,B+i);
//   rep(i,N-1) A[i]--, B[i]--;
//   g.setEdge(N,N-1,A,B);
//   rep(i,N-1) deg[A[i]]++, deg[B[i]]++;
//   rep(i,N) if(deg[i]==1) st[sts++] = i;
//   while(sts >= 2){
//     i = st[--sts];
//     j = st[--sts];
//     done(i);
//     done(j);
//     printf("? %d %d\n",i+1,j+1);
//     fflush(stdout);
//     scanf("%d",&k);
//     k--;
//     if(i==k || j==k){
//       printf("! %d\n", k+1);
//       fflush(stdout);
//       return 0;
//     }
//   }
//   printf("! %d\n", st[0]+1);
//   fflush(stdout);
// }