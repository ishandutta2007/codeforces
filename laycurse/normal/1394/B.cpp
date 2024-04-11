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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
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
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> > *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
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
}
;
int N;
int M;
int K;
int A[200000];
int B[200000];
int W[200000];
graph g;
int indeg[200000][9][9];
int dame1[9][9];
int dame2[9][9][9][9];
long long res;
int arr[9];
void solve(int dep){
  int i;
  if(dep==K){
    int j, j1;
    for(j=(0);j<(K);j++){
      if(dame1[j][arr[j]]){
        return;
      }
    }
    for(j1=(0);j1<(K);j1++){
      int j2;
      for(j2=(j1+1);j2<(K);j2++){
        if(dame2[j1][arr[j1]][j2][arr[j2]]){
          return;
        }
      }
    }
    res++;
    return;
  }
  for(i=(0);i<(dep+1);i++){
    arr[dep] = i;
    solve(dep+1);
  }
}
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int d;
  int x;
  rd(N);
  rd(M);
  rd(K);
  {
    int WYIGIcGE;
    for(WYIGIcGE=(0);WYIGIcGE<(M);WYIGIcGE++){
      rd(A[WYIGIcGE]);A[WYIGIcGE] += (-1);
      rd(B[WYIGIcGE]);B[WYIGIcGE] += (-1);
      rd(W[WYIGIcGE]);W[WYIGIcGE] += (-1);
    }
  }
  sortA_L(M,A,W,B);
  g.setDirectEdge(N,M,A,B);
  for(i=(0);i<(N);i++){
    if(g.es[i]==0){
      wt_L(0);
      wt_L('\n');
      return 0;
    }
    d = g.es[i];
    for(j=(0);j<(d);j++){
      k = g.edge[i][j];
      indeg[k][d-1][j]++;
    }
  }
  for(i=(0);i<(N);i++){
    int j1;
    for(j=(0);j<(K);j++){
      for(k=(0);k<(j+1);k++){
        if(indeg[i][j][k] > 1){
          dame1[j][k]++;
        }
      }
    }
    for(j1=(0);j1<(K);j1++){
      int k1;
      for(k1=(0);k1<(j1+1);k1++){
        int j2;
        for(j2=(0);j2<(K);j2++){
          int k2;
          for(k2=(0);k2<(j2+1);k2++){
            if(!(j1==j2 && k1==k2)){
              if(indeg[i][j1][k1]+indeg[i][j2][k2] >= 2){
                dame2[j1][k1][j2][k2] = 1;
              }
            }
          }
        }
      }
    }
  }
  solve(0);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, K, A[2d5], B[2d5], W[2d5];
// graph g;
// int indeg[2d5][9][9];
// int dame1[9][9];
// int dame2[9][9][9][9];
// 
// ll res;
// int arr[9];
// void solve(int dep){
//   if(dep==K){
//     rep(j,K) if(dame1[j][arr[j]]) return;
//     rep(j1,K) rep(j2,j1+1,K) if(dame2[j1][arr[j1]][j2][arr[j2]]) return;
//     res++;
//     return;
//   }
//   rep(i,dep+1) arr[dep] = i, solve(dep+1);
// }
// 
// {
//   int i, j, k, d, x;
//   rd(N,M,K,(A--,B--,W--)(M));
//   sortA(M,A,W,B);
//   g.setDirectEdge(N,M,A,B);
//   rep(i,N){
//     if(g.es[i]==0) wt(0), return 0;
//     d = g.es[i];
//     rep(j,d){
//       k = g.edge[i][j];
//       indeg[k][d-1][j]++;
//     }
//   }
//   rep(i,N){
//     rep(j,K) rep(k,j+1) if(indeg[i][j][k] > 1) dame1[j][k]++;
//     rep(j1,K) rep(k1,j1+1) rep(j2,K) rep(k2,j2+1) if(!(j1==j2 && k1==k2)) if(indeg[i][j1][k1]+indeg[i][j2][k2] >= 2) dame2[j1][k1][j2][k2] = 1;
//   }
//   solve(0);
//   wt(res);
// }