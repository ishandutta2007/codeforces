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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
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
inline int Ilog2_s_L(const int n){
  int res;
  if(n <= 0){
    return -1;
  }
  res = __builtin_ffs(n) - 1;
  if(n == (1<<res)){
    return res;
  }
  return -1;
}
inline int Ilog2_s_L(const long long n){
  int res;
  if(n <= 0){
    return -1;
  }
  res = __builtin_ffsll(n) - 1;
  if(n == (1LL<<res)){
    return res;
  }
  return -1;
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
  int getDist(int a, int b, void *mem = wmem){
    int i;
    int j;
    int k;
    int*q;
    int s;
    int z;
    int*d;
    if(a==b){
      return 0;
    }
    walloc1d(&d, N, &mem);
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      d[i] = -1;
    }
    d[a] = 0;
    s = 0;
    z = 1;
    q[0] = a;
    while(z){
      i = q[s++];
      z--;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(d[k] >= 0){
          continue;
        }
        d[k] = d[i] + 1;
        if(k==b){
          return d[k];
        }
        q[s+z++] = k;
      }
    }
    return -1;
  }
}
;
int N;
int node;
int M;
int A[2000000];
int B[2000000];
graph g;
int d[2000000];
int v[2000000];
int arr[2000000];
int ind[2000000];
int res[2000000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int ao_dF3pO;
    int i;
    int j;
    int k;
    rd(N);
    node = (1<<N);
    M = node * N / 2;
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(M);cTE1_r3A++){
        rd(A[cTE1_r3A]);
        rd(B[cTE1_r3A]);
      }
    }
    g.setEdge(node,M,A,B);
    g.getDist(0,d);
    for(i=(0);i<(node);i++){
      auto t_ynMSdg = ((d[i]));
      auto KrdatlYV = (( i));
      arr[i]=t_ynMSdg;
      ind[i]=KrdatlYV;
    }
    sortA_L(node, arr, ind);
    k = 0;
    for(ao_dF3pO=(0);ao_dF3pO<(node);ao_dF3pO++){
      int hCmBdyQB;
      auto&i = ind[ao_dF3pO];
      v[i] = 0;
      if(d[i] == 0){
        continue;
      }
      if(d[i] == 1){
        v[i] = (1<<k);
        k++;
        continue;
      }
      for(hCmBdyQB=(0);hCmBdyQB<(g.es[i]);hCmBdyQB++){
        auto&j = g.edge[i][hCmBdyQB];
        if(d[i] > d[j]){
          v[i] |= v[j];
        }
      }
    }
    for(i=(0);i<(node);i++){
      res[v[i]] = i;
    }
    {
      int jbtyPBGc;
      if(node==0){
        wt_L('\n');
      }
      else{
        for(jbtyPBGc=(0);jbtyPBGc<(node-1);jbtyPBGc++){
          wt_L(res[jbtyPBGc]);
          wt_L(' ');
        }
        wt_L(res[jbtyPBGc]);
        wt_L('\n');
      }
    }
    if(Ilog2_s_L(N)==-1){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(node);i++){
      arr[i] = 0;
    }
    for(i=(0);i<(node);i++){
      for(j=(0);j<(N);j++){
        if(((i) &(1<<(j)))){
          arr[i] ^= j;
        }
      }
    }
    for(i=(0);i<(node);i++){
      res[i] = arr[v[i]];
    }
    {
      int Hjfu7Vx7;
      if(node==0){
        wt_L('\n');
      }
      else{
        for(Hjfu7Vx7=(0);Hjfu7Vx7<(node-1);Hjfu7Vx7++){
          wt_L(res[Hjfu7Vx7]);
          wt_L(' ');
        }
        wt_L(res[Hjfu7Vx7]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210704-1 [beta]

// --- original code ---
// //no-unlocked
// int N, node, M, A[2d6], B[];
// graph g;
// int d[], v[];
// int arr[], ind[];
// int res[];
// {
//   REP(rd_int()){
//     int i, j, k;
//     rd(N);
//     node = (1<<N);
//     M = node * N / 2;
//     rd((A,B)(M));
//     g.setEdge(node,M,A,B);
//     g.getDist(0,d);
//     rep(i,node) (arr[i], ind[i]) = (d[i], i);
//     sortA(node, arr, ind);
// 
//     k = 0;
//     rep[ind](i,node){
//       v[i] = 0;
//       if(d[i] == 0) continue;
//       if(d[i] == 1) v[i] = (1<<k), k++, continue;
//       rep[g.edge[i]](j,g.es[i]) if(d[i] > d[j]) v[i] |= v[j];
//     }
// 
//     rep(i,node) res[v[i]] = i;
//     wt(res(node));
// 
//     if(Ilog2_s(N)==-1) wt(-1), continue;
// 
//     rep(i,node) arr[i] = 0;
//     rep(i,node) rep(j,N) if(BIT_ith(i,j)) arr[i] ^= j;
//     rep(i,node) res[i] = arr[v[i]];
//     wt(res(node));
//   }
// }