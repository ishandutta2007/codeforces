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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
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
  graph reduce(int tn, int ind[], int self_e = 0, int dep_e = 0, void **mem = &wmem){
    int i;
    int j;
    int k;
    int M = 0;
    int x;
    int y;
    graph g;
    void *tmem;
    pair<int,int> *A;
    for(i=(0);i<(N);i++){
      M += es[i];
    }
    tmem = ((char*)(*mem)) + sizeof(int**) * N + sizeof(int*) * N + sizeof(int) * M + 16 * (N+2);
    walloc1d(&A, M, &tmem);
    M = 0;
    for(i=(0);i<(N);i++){
      x = ind[i];
      if(x < 0){
        continue;
      }
      for(j=(0);j<(es[i]);j++){
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
      for(i=(0);i<(M);i++){
        if(k && A[k-1]==A[i]){
          continue;
        }
        A[k++] = A[i];
      }
      M = k;
    }
    g.N = tn;
    walloc1d(&g.es, tn, mem);
    walloc1d(&g.edge, tn, mem);
    for(i=(0);i<(tn);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      g.es[A[i].first]++;
    }
    for(i=(0);i<(tn);i++){
      walloc1d(&g.edge[i], g.es[i], mem);
    }
    for(i=(0);i<(tn);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i].first;
      k = A[i].second;
      g.edge[j][g.es[j]++] = k;
    }
    return g;
  }
  inline void bccDFS(int v, int u, int *res, int *rt, int &rts, int *S, int &Ss, int *inS, int *num, int &tm){
    int i;
    int k;
    num[v] = ++tm;
    S[Ss++] = v;
    inS[v] = 1;
    rt[rts++] = v;
    for(i=(0);i<(es[v]);i++){
      int w = edge[v][i];
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
        int w = S[--Ss];
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
    int i;
    int k;
    int *rt;
    int *S;
    int *num;
    int *inS;
    pair<int,int> *arr;
    int rts = 0;
    int Ss = 0;
    int tm = 0;
    walloc1d(&num, N, &mem);
    walloc1d(&rt, N, &mem);
    walloc1d(&S, N, &mem);
    walloc1d(&inS, N, &mem);
    memset(num, 0, sizeof(int)*N);
    memset(inS, 0, sizeof(int)*N);
    for(i=(0);i<(N);i++){
      if(!num[i]){
        bccDFS(i, N, res, rt, rts, S, Ss, inS, num, tm);
      }
    }
    arr = (pair<int,int>*)mem;
    for(i=(0);i<(N);i++){
      arr[i].first = res[i];
      arr[i].second = i;
    }
    sort(arr, arr+N);
    k = 0;
    for(i=(0);i<(N);i++){
      if(i && arr[i].first != arr[i-1].first){
        k++;
      }
      res[arr[i].second] = k;
    }
    return k+1;
  }
  int preorder(int res[], int root = 0, void *mem=wmem){
    int i;
    int j;
    int k;
    int *st;
    int sts;
    int sz = 0;
    char *vis;
    walloc1d(&vis, N, &mem);
    walloc1d(&st, N, &mem);
    sts = 0;
    st[sts++] = root;
    for(i=(0);i<(N);i++){
      vis[i] = 0;
    }
    vis[root] = 1;
    while(sts){
      i = st[--sts];
      res[sz++] = i;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(vis[k]){
          continue;
        }
        vis[k] = 1;
        st[sts++] = k;
      }
    }
    return sz;
  }
}
;
int N;
int M;
int W[200000];
int A[200000];
int B[200000];
int S;
int nn;
int grp[200000];
int vis[200000];
int od[200000];
long long dp1[200000];
long long dp2[200000];
long long ww[200000];
int sz[200000];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int d;
  long long s;
  graph og;
  graph g;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(W[Lj4PdHRW]);
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=(0);KL2GvlyY<(M);KL2GvlyY++){
      rd(A[KL2GvlyY]);A[KL2GvlyY] += (-1);
      rd(B[KL2GvlyY]);B[KL2GvlyY] += (-1);
    }
  }
  rd(S);S += (-1);
  og.setEdge(N,M,A,B);
  nn = og.bcc(grp);
  g = og.reduce(nn, grp);
  for(i=(0);i<(N);i++){
    ww[grp[i]] += W[i];
  }
  for(i=(0);i<(N);i++){
    sz[grp[i]]++;
  }
  S = grp[S];
  g.preorder(od, S);
  for(k=(nn)-1;k>=(0);k--){
    i = od[k];
    s = ww[i];
    vis[i] = 1;
    for(j=(0);j<(g.es[i]);j++){
      d = g.edge[i][j];
      if(!vis[d]){
        continue;
      }
      if(sz[d] >= 2){
        sz[i] += sz[d];
        s += dp2[d];
      }
    }
    dp1[i] = dp2[i] = s;
    for(j=(0);j<(g.es[i]);j++){
      d = g.edge[i][j];
      if(sz[d] >= 2){
        chmax(dp1[i], dp1[d] + s - dp2[d]);
      }
      else{
        chmax(dp1[i], dp1[d] + s);
      }
    }
  }
  wt_L(dp1[S]);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// //no-unlocked
// int N, M, W[2d5], A[2d5], B[2d5], S;
// 
// int nn, grp[2d5], vis[2d5], od[2d5];
// ll dp1[2d5], dp2[2d5];
// ll ww[2d5]; int sz[2d5];
// {
//   int i, j, k, d;
//   ll s;
//   graph og, g;
//   rd(N,M,W(N),(A--,B--)(M),S--);
// 
//   og.setEdge(N,M,A,B);
//   nn = og.bcc(grp);
//   g = og.reduce(nn, grp);
//   rep(i,N) ww[grp[i]] += W[i];
//   rep(i,N) sz[grp[i]]++;
//   S = grp[S];
//   g.preorder(od, S);
//   rrep(k,nn){
//     i = od[k];
//     s = ww[i];
//     vis[i] = 1;
//     rep(j,g.es[i]){
//       d = g.edge[i][j];
//       if(!vis[d]) continue;
//       if(sz[d] >= 2){
//         sz[i] += sz[d];
//         s += dp2[d];
//       }
//     }
//     dp1[i] = dp2[i] = s;
//     rep(j,g.es[i]){
//       d = g.edge[i][j];
//       if(sz[d] >= 2) dp1[i] >?= dp1[d] + s - dp2[d];
//       else           dp1[i] >?= dp1[d] + s;
//     }
//   }
//   wt(dp1[S]);
// }