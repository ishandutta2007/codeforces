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
int A[500000];
int B[500000];
int T[500000];
int cur[500000];
int ind[500000];
int val[500000];
graph g;
int ress;
int res[500000];
int main(){
  int WYIGIcGE, i;
  wmem = memarr;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){
      rd(T[e98WHCEY]);T[e98WHCEY] += (-1);
    }
  }
  g.setEdge(N,M,A,B);
  for(i=(0);i<(N);i++){
    ind[i] = i;
    val[i] = T[i];
  }
  sortA_L(N,val,ind);
  for(WYIGIcGE=(0);WYIGIcGE<(N);WYIGIcGE++){
    int ao_dF3pO;
    auto &i = ind[WYIGIcGE];
    if(cur[i]!=T[i]){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
    res[ress++] = i;
    for(ao_dF3pO=(0);ao_dF3pO<(g.es[i]);ao_dF3pO++){
      auto &j = g.edge[i][ao_dF3pO];
      if(cur[j]==cur[i]){
        cur[j]++;
      }
    }
  }
  {
    int hCmBdyQB;
    if(ress==0){
      wt_L('\n');
    }
    else{
      for(hCmBdyQB=(0);hCmBdyQB<(ress-1);hCmBdyQB++){
        wt_L(res[hCmBdyQB]+1);
        wt_L(' ');
      }
      wt_L(res[hCmBdyQB]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, A[5d5], B[5d5], T[5d5];
// int cur[5d5], ind[5d5], val[5d5];
// graph g;
// int ress, res[5d5];
// {
//   rd(N,M,(A--,B--)(M),(T--)(N));
//   g.setEdge(N,M,A,B);
// 
//   rep(i,N) ind[i] = i, val[i] = T[i];
//   sortA(N,val,ind);
// 
//   rep[ind](i,N){
//     if(cur[i]!=T[i]) wt(-1), return 0;
//     res[ress++] = i;
//     rep[g.edge[i]](j,g.es[i]) if(cur[j]==cur[i]) cur[j]++;
//   }
// 
//   wt(res(ress)+1);
// }