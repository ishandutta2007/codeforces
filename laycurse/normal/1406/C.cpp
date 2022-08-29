#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
template<class T, class S> int arrCountVal(int N, T A[], S val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
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
  void SubTreeSize(int root, int res[], void *mem = wmem){
    int i;
    int j;
    int k;
    int m;
    int*q;
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
int A[100000];
int B[100000];
graph g;
int sz[100000];
int cn[100000];
int dep[100000];
int dis[100000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int mn;
    int mnc;
    int x;
    int y;
    int i;
    int j;
    int k;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N-1);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
        rd(B[cTE1_r3A]);B[cTE1_r3A] += (-1);
      }
    }
    g.setEdge(N,N-1,A,B);
    g.SubTreeSize(0, sz);
    g.getDist(0, dep);
    for(i=(0);i<(N);i++){
      cn[i] = N - sz[i];
    }
    for(i=(0);i<(N);i++){
      int ao_dF3pO;
      for(ao_dF3pO=(0);ao_dF3pO<(g.es[i]);ao_dF3pO++){
        auto &j = g.edge[i][ao_dF3pO];
        if(dep[j] > dep[i]){
          chmax(cn[i], sz[j]);
        }
      }
    }
    {
      int hCmBdyQB;
      int V9aVTaxx;
      if(N==0){
        V9aVTaxx = 0;
      }
      else{
        V9aVTaxx = cn[0];
        for(hCmBdyQB=(1);hCmBdyQB<(N);hCmBdyQB++){
          V9aVTaxx = min_L(V9aVTaxx, cn[hCmBdyQB]);
        }
      }
      mn =V9aVTaxx;
    }
    mnc = arrCountVal(N, cn, mn);
    if(mnc==1){
      int jZyWAPpY;
      for(jZyWAPpY=(0);jZyWAPpY<(2);jZyWAPpY++){
        wt_L(A[0]+1);
        wt_L(' ');
        wt_L(B[0]+1);
        wt_L('\n');
      }
      continue;
    }
    x = y = -1;
    for(i=(0);i<(N);i++){
      if(cn[i]==mn){
        if(x==-1){
          x = i;
          continue;
        }
        if(y==-1){
          y = i;
          continue;
        }
      }
    }
    for(i=(0);i<(N);i++){
      if(g.es[i]==1){
        break;
      }
    }
    k = g.edge[i][0];
    g.getDist(i,dis);
    if(dis[x] > dis[y]){
      j =x;
    }
    else{
      j =y;
    }
    wt_L(i+1);
    wt_L(' ');
    wt_L(k+1);
    wt_L('\n');
    wt_L(i+1);
    wt_L(' ');
    wt_L(j+1);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200913-1

// --- original code ---
// //no-unlocked
// int N, A[1d5], B[1d5];
// graph g;
// int sz[1d5], cn[1d5], dep[1d5], dis[1d5];
// {
//   REP(rd_int()){
//     int mn, mnc, x, y, i, j, k;
//     rd(N,(A--,B--)(N-1));
//     g.setEdge(N,N-1,A,B);
//     g.SubTreeSize(0, sz);
//     g.getDist(0, dep);
//     rep(i,N) cn[i] = N - sz[i];
//     rep(i,N) rep[g.edge[i]](j,g.es[i]) if(dep[j] > dep[i]) cn[i] >?= sz[j];
// 
//     mn = min(cn(N));
//     mnc = arrCountVal(N, cn, mn);
//     if(mnc==1){
//       rep(2) wt(A[0]+1, B[0]+1);
//       continue;
//     }
// 
//     x = y = -1;
//     rep(i,N) if(cn[i]==mn){
//       if(x==-1) x = i, continue;
//       if(y==-1) y = i, continue;
//     }
//     rep(i,N) if(g.es[i]==1) break;
//     k = g.edge[i][0];
//     g.getDist(i,dis);
//     j = if[dis[x] > dis[y], x, y];
//     wt(i+1, k+1);
//     wt(i+1, j+1);
//   }
// }