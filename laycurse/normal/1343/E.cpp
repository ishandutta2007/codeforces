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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
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
int A;
int B;
int C;
int P[200000];
int U[200000];
int V[200000];
long long s[200000+1];
graph g;
int distA[200000];
int distB[200000];
int distC[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  void *mem = wmem;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    long long res = 4611686016279904256LL;
    wmem = mem;
    rd(N);
    rd(M);
    rd(A);A += (-1);
    rd(B);B += (-1);
    rd(C);C += (-1);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(M);cTE1_r3A++){
        rd(P[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(M);xr20shxY++){
        rd(U[xr20shxY]);U[xr20shxY] += (-1);
        rd(V[xr20shxY]);V[xr20shxY] += (-1);
      }
    }
    g.setEdge(N,M,U,V);
    g.getDist(A, distA);
    g.getDist(B, distB);
    g.getDist(C, distC);
    sort(P,P+M);
    s[0] = 0;
    for(i=(0);i<(M);i++){
      s[i+1] = s[i] + P[i];
    }
    for(i=(0);i<(N);i++){
      int x = distA[i] + distC[i];
      int y = distB[i];
      if(x + y > M){
        continue;
      }
      chmin(res, 2 * s[y] + (s[x+y] - s[y]));
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, M, A, B, C, P[2d5], U[2d5], V[2d5];
// ll s[2d5+1];
// graph g;
// int distA[2d5], distB[2d5], distC[2d5];
// {
//   void *mem = wmem;
//   REP(rd_int()){
//     ll res = ll_inf;
//     wmem = mem;
//     rd(N,M,A--,B--,C--,P(M),(U--,V--)(M));
//     g.setEdge(N,M,U,V);
//     g.getDist(A, distA);
//     g.getDist(B, distB);
//     g.getDist(C, distC);
//     sort(P,P+M);
//     s[0] = 0;
//     rep(i,M) s[i+1] = s[i] + P[i];
//     rep(i,N){
//       int x = distA[i] + distC[i];
//       int y = distB[i];
//       if(x + y > M) continue;
//       res <?= 2 * s[y] + (s[x+y] - s[y]);
//     }
//     wt(res);
//   }
// }