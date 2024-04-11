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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
struct HLD{
  int N;
  int *es;
  int **edge;
  int *group;
  int *groupind;
  int groupNum;
  int *groupSize;
  int **groupNode;
  int *groupUpNode;
  int *groupDepth;
  void init(graph g, void **mem = &wmem){
    init(g.N, g.es, g.edge, mem);
  }
  void init(int N__, int *es__, int **edge__, void **mem = &wmem){
    int i;
    int j;
    int k;
    int x;
    int y;
    int mx;
    int *q;
    int q_st;
    int q_ed;
    int *sz;
    char *vis;
    void *tmpmem;
    N = N__;
    es = es__;
    edge = edge__;
    walloc1d(&group, N, mem);
    walloc1d(&groupind, N, mem);
    tmpmem = *mem;
    walloc1d(&q, N, &tmpmem);
    walloc1d(&sz, N, &tmpmem);
    walloc1d(&vis, N, &tmpmem);
    for(i=(0);i<(N);i++){
      vis[i] = 0;
    }
    q_st = 0;
    q_ed = 1;
    q[0] = 0;
    vis[0] = 1;
    while(q_st < q_ed){
      i = q[q_st++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(!vis[k]){
          vis[k] = 1;
          q[q_ed++] = k;
        }
      }
    }
    for(i=(0);i<(N);i++){
      sz[i] = 0;
    }
    for(j=N-1;j>=0;j--){
      i = q[j];
      sz[i] = 1;
      for(k=(0);k<(es[i]);k++){
        sz[i] += sz[edge[i][k]];
      }
    }
    for(i=(0);i<(N);i++){
      group[i] = -1;
    }
    groupNum = 0;
    for(j=(0);j<(N);j++){
      i = q[j];
      if(group[i]>=0){
        continue;
      }
      group[i] = groupNum++;
      groupind[i] = 0;
      for(;;){
        mx = -1;
        for(k=(0);k<(es[i]);k++){
          if(group[edge[i][k]] != -1){
            continue;
          }
          if(mx==-1){
            mx = k;
          }
          else if(sz[edge[i][k]] > sz[edge[i][mx]]){
            mx = k;
          }
        }
        if(mx==-1){
          break;
        }
        group[edge[i][mx]] = group[i];
        groupind[edge[i][mx]] = groupind[i]+1;
        i = edge[i][mx];
      }
    }
    walloc1d(&groupSize, groupNum, mem);
    walloc1d(&groupUpNode, groupNum, mem);
    walloc1d(&groupDepth, groupNum, mem);
    for(i=(0);i<(groupNum);i++){
      groupSize[i] = 0;
    }
    for(i=(0);i<(N);i++){
      groupSize[group[i]]++;
    }
    walloc1d(&groupNode, groupNum, mem);
    for(i=(0);i<(groupNum);i++){
      walloc1d(&groupNode[i], groupSize[i], mem);
    }
    for(i=(0);i<(N);i++){
      groupNode[group[i]][groupind[i]] = i;
    }
    for(i=(0);i<(groupNum);i++){
      groupDepth[i] = -1;
    }
    groupUpNode[0] = -1;
    groupDepth[0] = 0;
    for(x=(0);x<(groupNum);x++){
      for(y=(0);y<(groupSize[x]);y++){
        i = groupNode[x][y];
        for(j=(0);j<(es[i]);j++){
          k = edge[i][j];
          if(x != group[k] && groupDepth[group[k]]==-1){
            groupUpNode[group[k]] = i;
            groupDepth[group[k]] = groupDepth[x] + 1;
          }
        }
      }
    }
  }
  int lca(int x, int y){
    int x1;
    int y1;
    int x2;
    int y2;
    x1 = group[x];
    x2 = groupind[x];
    y1 = group[y];
    y2 = groupind[y];
    while(groupDepth[x1] > groupDepth[y1]){
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    while(groupDepth[x1] < groupDepth[y1]){
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    while(x1 != y1){
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    if(x2 <= y2){
      return x;
    }
    return y;
  }
  int depth(int x){
    int x1;
    int x2;
    int res = 0;
    x1 = group[x];
    x2 = groupind[x];
    while(groupUpNode[x1] != -1){
      res += x2 + 1;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    return res + x2;
  }
  int dist(int x, int y){
    int x1;
    int y1;
    int x2;
    int y2;
    int res = 0;
    x1 = group[x];
    x2 = groupind[x];
    y1 = group[y];
    y2 = groupind[y];
    while(groupDepth[x1] > groupDepth[y1]){
      res += x2 + 1;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    while(groupDepth[x1] < groupDepth[y1]){
      res += y2 + 1;
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    while(x1 != y1){
      res += x2 + y2 + 2;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    if(x2 <= y2){
      return res + y2 - x2;
    }
    return res + x2 - y2;
  }
  int up(int x){
    int x1 = group[x];
    int x2 = groupind[x];
    if(x2==0){
      return groupUpNode[x1];
    }
    return groupNode[x1][x2-1];
  }
  int up(int x, int d){
    int x1 = group[x];
    int x2 = groupind[x];
    while(d > x2){
      if(groupUpNode[x1]==-1){
        return -1;
      }
      d -= x2 + 1;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    return groupNode[x1][x2-d];
  }
}
;
int N;
int M;
int A[200000];
int B[200000];
int K;
int X[200000];
int dep[200000];
graph g;
HLD hld;
int main(){
  int e98WHCEY;
  wmem = memarr;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N-1);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
    }
  }
  g.setEdge(N,N-1,A,B);
  hld.init(g);
  for(e98WHCEY=(0);e98WHCEY<(M);e98WHCEY++){
    int i;
    rd(K);
    {
      int FmcKpFmN;
      for(FmcKpFmN=(0);FmcKpFmN<(K);FmcKpFmN++){
        rd(X[FmcKpFmN]);X[FmcKpFmN] += (-1);
      }
    }
    for(i=(0);i<(K);i++){
      dep[i] = hld.depth(X[i]);
    }
    sortA_L(K,dep,X);
    for(i=(0);i<(K-1);i++){
      if(dep[i]){
        dep[i]--;
        X[i] = hld.up(X[i]);
        if(hld.up(X[K-1],dep[K-1]-dep[i]) != X[i]){
          wt_L("NO");
          wt_L('\n');
          goto cTE1_r3A;
        }
      }
    }
    wt_L("YES");
    wt_L('\n');
    cTE1_r3A:;
  }
  return 0;
}
// cLay varsion 20200322-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[2d5];
// int K, X[2d5], dep[2d5];
// graph g;
// HLD hld;
// {
//   rd(N,M,(A--,B--)(N-1));
//   g.setEdge(N,N-1,A,B);
//   hld.init(g);
//   rep(M){
//     rd(K,(X--)(K));
//     rep(i,K) dep[i] = hld.depth(X[i]);
//     sortA(K,dep,X);
//     rep(i,K-1) if(dep[i]){
//       dep[i]--;
//       X[i] = hld.up(X[i]);
//       if(hld.up(X[K-1],dep[K-1]-dep[i]) != X[i]) wt("NO"), break_continue;
//     }
//     wt("YES");
//   }
// }