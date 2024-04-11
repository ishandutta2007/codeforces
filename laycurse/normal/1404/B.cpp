#pragma GCC optimize ("Ofast")
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
  int TreeDiameter(int &a, int &b, void *mem = wmem){
    int i;
    int mx;
    int*d;
    walloc1d(&d, N, &mem);
    getDist(0, d, mem);
    mx = -1;
    for(i=(0);i<(N);i++){
      if(mx < d[i]){
        mx = d[i];
        a = i;
      }
    }
    getDist(a, d, mem);
    mx = -1;
    for(i=(0);i<(N);i++){
      if(mx < d[i]){
        mx = d[i];
        b = i;
      }
    }
    return mx;
  }
  int TreeDiameter(void *mem = wmem){
    int a;
    int b;
    return TreeDiameter(a, b, mem);
  }
}
;
int N;
int A;
int B;
int DA;
int DB;
int X[100000];
int Y[100000];
graph g;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    rd(A);A += (-1);
    rd(B);B += (-1);
    rd(DA);
    rd(DB);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N-1);cTE1_r3A++){
        rd(X[cTE1_r3A]);X[cTE1_r3A] += (-1);
        rd(Y[cTE1_r3A]);Y[cTE1_r3A] += (-1);
      }
    }
    g.setEdge(N,N-1,X,Y);
    if(g.getDist(A,B) <= DA){
      wt_L("Alice");
      wt_L('\n');
      continue;
    }
    {
      auto xr20shxY = (g.TreeDiameter());
      chmin(DA, xr20shxY);
      chmin(DB, xr20shxY);
    }
    if(DB > 2*DA){
      wt_L("Bob");
      wt_L('\n');
    }
    else{
      wt_L("Alice");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200916-1

// --- original code ---
// //no-unlocked
// int N, A, B, DA, DB, X[1d5], Y[1d5];
// graph g;
// {
//   REP(rd_int()){
//     rd(N,A--,B--,DA,DB,(X--,Y--)(N-1));
//     g.setEdge(N,N-1,X,Y);
// 
//     if(g.getDist(A,B) <= DA) wt("Alice"), continue;
//     
//     (DA, DB) <?= g.TreeDiameter();
//     wt(if[DB > 2*DA, "Bob", "Alice"]);
//   }
// }