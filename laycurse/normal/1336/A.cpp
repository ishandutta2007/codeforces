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
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
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
  void SubTreeSize(int root, int res[], void *mem = wmem){
    int i;
    int j;
    int k;
    int m;
    int *q;
    int qs = 0;
    int qe = 1;
    walloc1d(&q,N,&mem);
    for(i=(0);i<(N);i++){
      res[i] = -1;
    }
    res[root] = 0;
    q[0] = root;
    while(qs < qe){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(res[k]==0){
          continue;
        }
        res[k] = 0;
        q[qe++] = k;
      }
    }
    for(m=(N)-1;m>=(0);m--){
      i = q[m];
      res[i] = 1;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        res[i] += res[k];
      }
    }
  }
}
;
int N;
int K;
int A[200000];
int B[200000];
graph g;
int dist[200000];
int sz[200000];
long long gain[200000];
int main(){
  int i;
  wmem = memarr;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N-1);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
    }
  }
  g.setEdge(N,N-1,A,B);
  g.getDist(0, dist);
  g.SubTreeSize(0, sz);
  for(i=(0);i<(N);i++){
    gain[i] = dist[i] - sz[i] + 1;
  }
  rsortA_L(N, gain);
  {
    int RZTsC2BF;
    long long FmcKpFmN;
    if(K==0){
      FmcKpFmN = 0;
    }
    else{
      FmcKpFmN = gain[0];
      for(RZTsC2BF=(1);RZTsC2BF<(K);RZTsC2BF++){
        FmcKpFmN += gain[RZTsC2BF];
      }
    }
    wt_L(FmcKpFmN);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200418-1

// --- original code ---
// //no-unlocked
// int N, K, A[2d5], B[2d5];
// graph g;
// int dist[2d5], sz[2d5]; ll gain[2d5];
// 
// {
//   rd(N,K,(A--,B--)(N-1));
//   g.setEdge(N,N-1,A,B);
//   g.getDist(0, dist);
//   g.SubTreeSize(0, sz);
// 
//   rep(i,N) gain[i] = dist[i] - sz[i] + 1;
//   rsortA(N, gain);
//   wt(sum(gain(K)));
// }