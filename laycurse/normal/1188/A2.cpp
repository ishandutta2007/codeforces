#include<bits/stdc++.h>
using namespace std;
void *wmem;
inline void rd(int &x){
  int k, m=0;
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
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(int x){
  char f[10];
  int m=0, s=0;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
struct graph{
  int N, **edge, *es;
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    es = (int*)(*mem);
    edge = (int**)(es+N);
    edge[0] = (int*)(edge+N);
    for(i=0;i<N;i++){
      es[i] = 0;
    }
    for(i=0;i<M;i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=1;i<N;i++){
      edge[i] = edge[i-1] + es[i-1];
    }
    (*mem) = edge[N-1] + es[N-1];
    for(i=0;i<N;i++){
      es[i] = 0;
    }
    for(i=0;i<M;i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
  void setDirectEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    es = (int*)(*mem);
    edge = (int**)(es+N);
    edge[0] = (int*)(edge+N);
    for(i=0;i<N;i++){
      es[i] = 0;
    }
    for(i=0;i<M;i++){
      es[A[i]]++;
    }
    for(i=1;i<N;i++){
      edge[i] = edge[i-1] + es[i-1];
    }
    (*mem) = edge[N-1] + es[N-1];
    for(i=0;i<N;i++){
      es[i] = 0;
    }
    for(i=0;i<M;i++){
      edge[A[i]][es[A[i]]++] = B[i];
    }
  }
  graph reverse(void **mem = &wmem){
    graph g;
    int i, j, k;
    g.N = N;
    g.es = (int*)(*mem);
    g.edge = (int**)(g.es + N);
    g.edge[0] = (int*)(g.edge + N);
    for(i=0;i<N;i++){
      g.es[i] = 0;
    }
    for(i=0;i<N;i++){
      for(j=0;j<es[i];j++){
        g.es[edge[i][j]]++;
      }
    }
    for(i=1;i<N;i++){
      g.edge[i] = g.edge[i-1] + g.es[i-1];
    }
    *mem = g.edge[N-1] + g.es[N-1];
    for(i=0;i<N;i++){
      g.es[i] = 0;
    }
    for(i=0;i<N;i++){
      for(j=0;j<es[i];j++){
        k = edge[i][j];
        g.edge[k][g.es[k]++] = i;
      }
    }
    return g;
  }
  graph reduce(int tn, int ind[], int self_e = 0, int dep_e = 0, void **mem = &wmem){
    graph g;
    int M=0, i, j, k, x, y;
    pair<int,int> *A;
    for(i=0;i<N;i++){
      M += es[i];
    }
    A = (pair<int,int>*)((int*)((int**)(*mem) + tn) + tn + M);
    M = 0;
    for(i=0;i<N;i++){
      x = ind[i];
      if(x < 0){
        continue;
      }
      for(j=0;j<es[i];j++){
        y = ind[edge[i][j]];
        if(y < 0){
          continue;
        }
        if(self_e==0 && x==y){
          continue;
        }
        A[M++] = make_pair(x, y);
      }
    }
    if(dep_e==0){
      sort(A, A+M);
      k = 0;
      for(i=0;i<M;i++){
        if(k && A[k-1]==A[i]){
          continue;
        }
        A[k++] = A[i];
      }
      M = k;
    }
    g.N = tn;
    g.es = (int*)(*mem);
    g.edge = (int**)(g.es + tn);
    g.edge[0] = (int*)(g.edge + tn);
    for(i=0;i<tn;i++){
      g.es[i] = 0;
    }
    for(i=0;i<M;i++){
      g.es[A[i].first]++;
    }
    for(i=1;i<tn;i++){
      g.edge[i] = g.edge[i-1] + g.es[i-1];
    }
    *mem = g.edge[tn-1] + g.es[tn-1];
    for(i=0;i<tn;i++){
      g.es[i] = 0;
    }
    for(i=0;i<M;i++){
      j = A[i].first;
      k = A[i].second;
      g.edge[j][g.es[j]++] = k;
    }
    return g;
  }
  void getDist(int root, int res[], void *mem = wmem){
    int i, j, k, *q, s, z;
    q=(int*)mem;
    for(i=0;i<N;i++){
      res[i]=-1;
    }
    res[root]=0;
    s=0;
    z=1;
    q[0]=root;
    while(z){
      i=q[s++];
      z--;
      for(j=0;j<es[i];j++){
        k=edge[i][j];
        if(res[k]>=0){
          continue;
        }
        res[k]=res[i]+1;
        q[s+z++]=k;
      }
    }
  }
  inline int sccDFS(int num[], int st, int mx){
    int i, j;
    num[st]=-2;
    for(i=0;i<es[st];i++){
      j=edge[st][i];
      if(num[j]==-1){
        mx=sccDFS(num,j,mx);
      }
    }
    num[st]=mx;
    return mx+1;
  }
  int scc(int res[], void *mem = wmem){
    graph r;
    int i, j, k, *nrv, *num, ret=0, *st, st_size;
    r = reverse(&mem);
    st = (int*)mem;
    num = st+N;
    nrv = num + N;
    for(i=0;i<N;i++){
      res[i] = num[i] = -1;
    }
    k = 0;
    for(i=0;i<N;i++){
      if(num[i]==-1){
        k = sccDFS(num,i,k);
      }
    }
    for(i=0;i<N;i++){
      nrv[num[i]] = i;
    }
    for(k=N-1;k>=0;k--){
      i=nrv[k];
      if(res[i]>=0){
        continue;
      }
      res[i]=ret;
      st_size=0;
      st[st_size++]=i;
      while(st_size){
        i=st[--st_size];
        for(j=0;j<r.es[i];j++){
          if(res[r.edge[i][j]]==-1){
            res[r.edge[i][j]]=ret;
            st[st_size++]=r.edge[i][j];
          }
        }
      }
      ret++;
    }
    return ret;
  }
  inline void bccDFS(int v, int u, int *res, int *rt, int &rts, int *S, int &Ss, int *inS, int *num, int &tm){
    int i, k;
    num[v] = ++tm;
    S[Ss++] = v;
    inS[v] = 1;
    rt[rts++] = v;
    for(i=0;i<es[v];i++){
      int w=edge[v][i];
      if(!num[w]){
        bccDFS(w, v, res, rt, rts, S, Ss, inS, num, tm);
      }
      else if(u != w && inS[w]){
        while(num[rt[rts-1]] > num[w]){
          rts--;
        }
      }
    }
    if(v == rt[rts-1]){
      k = S[Ss-1];
      for(;;){
        int w=S[--Ss];
        inS[w] = 0;
        res[w] = k;
        if(v==w){
          break;
        }
      }
      rts--;
    }
  }
  int bcc(int res[], void *mem=wmem){
    int *S, Ss=0, i, *inS, k, *num, *rt, rts=0, tm=0;
    pair<int,int> *arr;
    num = (int*)mem;
    rt = num + N;
    S = rt + N;
    inS = S + N;
    memset(num, 0, sizeof(int)*N);
    memset(inS, 0, sizeof(int)*N);
    for(i=0;i<N;i++){
      if(!num[i]){
        bccDFS(i, N, res, rt, rts, S, Ss, inS, num, tm);
      }
    }
    arr = (pair<int,int>*)mem;
    for(i=0;i<N;i++){
      arr[i].first = res[i];
      arr[i].second = i;
    }
    sort(arr, arr+N);
    k = 0;
    for(i=0;i<N;i++){
      if(i && arr[i].first != arr[i-1].first){
        k++;
      }
      res[arr[i].second] = k;
    }
    return k+1;
  }
  int shortestPath(const int s, const int t, int res[], void *mem=wmem){
    int *b, i, j, k, *q, qe=0, qs=0;
    b = (int*)mem;
    q = b + N;
    for(i=0;i<N;i++){
      b[i] = -1;
    }
    b[s] = -2;
    q[qe++] = s;
    while(qe > qs){
      i = q[qs++];
      for(j=0;j<es[i];j++){
        k = edge[i][j];
        if(b[k]!=-1){
          continue;
        }
        b[k] = i;
        q[qe++] = k;
      }
      if(b[t]!=-1){
        break;
      }
    }
    if(b[t]==-1){
      return -1;
    }
    k = 0;
    res[k] = i = t;
    while(i != s){
      res[++k] = (i = b[i]);
    }
    std::reverse(res, res+k+1);
    return k;
  }
}
;
char memarr[96000000];
int N;
int A[1000];
int B[1000];
int C[1000][1000];
graph g;
int path[1000];
int ps;
int ress;
int resA[100000];
int resB[100000];
int resC[100000];
void doit(int x, int y, int z){
  int i;
  ps = g.shortestPath(x, y, path);
  for(i=0;i<ps;i++){
    C[path[i]][path[i+1]] -= z;
    C[path[i+1]][path[i]] -= z;
  }
  resA[ress] = x + 1;
  resB[ress] = y + 1;
  resC[ress++] = z;
}
void solve(int n, int r, int b, int &x, int &y){
  int i, j, k, sx, sy;
  for(i=0;i<g.es[n];i++){
    k = g.edge[n][i];
    if(k==b){
      continue;
    }
    sx = sy = -1;
    solve(k, r, n, sx, sy);
    if(x==-1){
      x = sx;
    }
    else if(y==-1){
      y = sx;
    }
  }
  if(b>=0 && C[n][b]){
    k = C[n][b];
    if(x >= 0 && y >= 0){
      doit(x, y, -k/2);
      doit(r, x, k/2);
      doit(r, y, k/2);
    }
    else if(g.es[n]==1){
      doit(n, r, k);
    }
  }
  if(g.es[n]==1){
    x = n;
  }
}
int main(){
  int i, j, k, m, rt;
  wmem = memarr;
  rd(N);
  for(m=0;m<N-1;m++){
    rd(i);i += (-1);
    rd(j);j += (-1);
    rd(k);
    A[m] = i;
    B[m] = j;
    C[i][j] = C[j][i] = k;
  }
  g.setEdge(N,N-1,A,B);
  for(i=0;i<N;i++){
    if(g.es[i]==1){
      rt = i;
      break;
    }
  }
  i = j = -1;
  solve(rt, rt, -1, i, j);
  k = 0;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(C[i][j]){
        k++;
      }
    }
  }
  if(k){
    wt_L("NO");
    wt_L('\n');
  }
  else{
    wt_L("YES");
    wt_L('\n');
    wt_L(ress);
    wt_L('\n');
    for(i=0;i<ress;i++){
      wt_L(resA[i]);
      wt_L(' ');
      wt_L(resB[i]);
      wt_L(' ');
      wt_L(resC[i]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190706-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[1000], B[1000], C[1000][1000];
// 
// graph g;
// int path[1000], ps;
// 
// int ress, resA[1d5], resB[1d5], resC[1d5];
// 
// void doit(int x, int y, int z){
//   int i;
//   ps = g.shortestPath(x, y, path);
//   
//   rep(i,ps){
//     C[path[i]][path[i+1]] -= z;
//     C[path[i+1]][path[i]] -= z;
//   }
// 
//   resA[ress] = x + 1;
//   resB[ress] = y + 1;
//   resC[ress++] = z;
// }
// 
// 
// void solve(int n, int r, int b, int &x, int &y){
//   int i, j, k;
//   int sx, sy;
// 
//   rep(i, g.es[n]){
//     k = g.edge[n][i];
//     if(k==b) continue;
// 
//     sx = sy = -1;
//     solve(k, r, n, sx, sy);
//     if(x==-1)      x = sx;
//     else if(y==-1) y = sx;
//   }
// 
//   if(b>=0 && C[n][b]){
//     k = C[n][b];
//     if(x >= 0 && y >= 0){
//       doit(x, y, -k/2);
//       doit(r, x, k/2);
//       doit(r, y, k/2);
//     } else if(g.es[n]==1) {
//       doit(n, r, k);
//     }
//   }
// 
//   if(g.es[n]==1) x = n;
// }
// 
// 
// {
//   int i, j, k, m, rt;
// 
//   rd(N);
//   rep(m,N-1){
//     rd(i--,j--,k);
//     A[m] = i;
//     B[m] = j;
//     C[i][j] = C[j][i] = k;
//   }
//   g.setEdge(N,N-1,A,B);
// 
//   rep(i,N) if(g.es[i]==1) { rt = i; break; }
// 
//   i = j = -1;
//   solve(rt, rt, -1, i, j);
// 
//   k = 0;
//   rep(i,N) rep(j,N) if(C[i][j]) k++;
//   if(k){
//     wt("NO");
//   } else {
//     wt("YES");
//     wt(ress);
//     rep(i,ress) wt(resA[i], resB[i], resC[i]);
//   }
// }