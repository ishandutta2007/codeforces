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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
inline void wt_L(char a){
  putchar(a);
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
int A;
int B;
int U[500000];
int V[500000];
graph g;
int vis[200000];
int vis1[200000];
int vis2[200000];
int st[200000];
int sts;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  long long c1;
  long long c2;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, loop;
    rd(N);
    rd(M);
    rd(A);A += (-1);
    rd(B);B += (-1);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(M);cTE1_r3A++){
        rd(U[cTE1_r3A]);U[cTE1_r3A] += (-1);
        rd(V[cTE1_r3A]);V[cTE1_r3A] += (-1);
      }
    }
    g.setEdge(N,M,U,V);
    for(loop=(0);loop<(2);loop++){
      int i;
      for(i=(0);i<(N);i++){
        vis[i] = 0;
      }
      sts = 0;
      vis[A] = 1;
      st[sts++] = A;
      while(sts){
        int a2conNHc;
        i = st[--sts];
        for(a2conNHc=(0);a2conNHc<(g.es[i]);a2conNHc++){
          auto &j = g.edge[i][a2conNHc];
          if(!vis[j] && j != A && j != B){
            vis[j] = 1;
            st[sts++] = j;
          }
        }
      }
      if(loop==0){
        for(i=(0);i<(N);i++){
          vis1[i] = vis[i];
        }
      }
      if(loop==1){
        for(i=(0);i<(N);i++){
          vis2[i] = vis[i];
        }
      }
      swap(A,B);
    }
    c1 = c2 = 0;
    for(i=(0);i<(N);i++){
      if(i != A && i != B && vis1[i]==1 && vis2[i]==0){
        c1++;
      }
    }
    for(i=(0);i<(N);i++){
      if(i != A && i != B && vis1[i]==0 && vis2[i]==1){
        c2++;
      }
    }
    wt_L(c1 * c2);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191208-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M, A, B, U[5d5], V[5d5];
// graph g;
// 
// int vis[2d5], vis1[2d5], vis2[2d5];
// int st[2d5], sts;
// 
// {
//   ll c1, c2;
// 
//   REP(rd_int()){
//     rd(N,M,A--,B--,(U--,V--)(M));
//     g.setEdge(N,M,U,V);
//     rep(loop,2){
//       rep(i,N) vis[i] = 0;
//       sts = 0;
//       vis[A] = 1;
//       st[sts++] = A;
//       while(sts){
//         i = st[--sts];
//         rep[g.edge[i]](j,g.es[i]) if(!vis[j] && j != A && j != B) vis[j] = 1, st[sts++] = j;
//       }
// 
//       if(loop==0) rep(i,N) vis1[i] = vis[i];
//       if(loop==1) rep(i,N) vis2[i] = vis[i];
//       swap(A,B);
//     }
//     c1 = c2 = 0;
//     rep(i,N) if(i != A && i != B && vis1[i]==1 && vis2[i]==0) c1++;
//     rep(i,N) if(i != A && i != B && vis1[i]==0 && vis2[i]==1) c2++;
//     wt(c1 * c2);
//   }
// }