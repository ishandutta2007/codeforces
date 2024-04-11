#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
inline void rd(long long &x){
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
int X[200000];
int Y[200000];
long long A[200000];
graph g;
int d;
int dist[200000];
long long mn[200000];
long long mx[200000];
long long dp[200000];
long long dp_p[200000];
long long dp_m[200000];
int ind[200000];
int val[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int ZIeRIny5, i;
    rd(N);
    for(i=(0);i<(N-1);i++){
      X[i] = i+1;
      rd(Y[i]);Y[i] += (-1);
    }
    for(i=(0);i<(N-1);i++){
      rd(A[i+1]);
    }
    g.setEdge(N,N-1,X,Y);
    g.getDist(0, dist);
    {
      int WYIGIcGE;
      int t_ynMSdg;
      if(N==0){
        t_ynMSdg = 0;
      }
      else{
        t_ynMSdg = dist[0];
        for(WYIGIcGE=(1);WYIGIcGE<(N);WYIGIcGE++){
          t_ynMSdg = max_L(t_ynMSdg, dist[WYIGIcGE]);
        }
      }
      d =t_ynMSdg+ 1;
    }
    for(i=(0);i<(d);i++){
      mn[i] = 4611686016279904256LL;
      mx[i] = -4611686016279904256LL;
      dp_p[i] = dp_m[i] = -4611686016279904256LL;
    }
    for(i=(1);i<(N);i++){
      chmin(mn[dist[i]], A[i]);
    }
    for(i=(1);i<(N);i++){
      chmax(mx[dist[i]], A[i]);
    }
    for(i=(0);i<(N);i++){
      ind[i] = i;
      val[i] = dist[i];
    }
    sortA_L(N, val, ind);
    for(ZIeRIny5=(N)-1;ZIeRIny5>=(0);ZIeRIny5--){
      auto &n = ind[ZIeRIny5];
      int cd = dist[n];
      long long cmn;
      long long cmx;
      if(cd == d-1){
        dp[n] = 0;
      }
      else{
        int XJIcIBrW;
        dp[n] = -4611686016279904256LL;
        cmn = 4611686016279904256LL;
        cmx = -4611686016279904256LL;
        for(XJIcIBrW=(0);XJIcIBrW<(g.es[n]);XJIcIBrW++){
          auto &i = g.edge[n][XJIcIBrW];
          if(dist[i] > cd){
            chmin(cmn, A[i]);
            chmax(cmx, A[i]);
            chmax(dp[n], dp[i] + A[i] - mn[cd+1]);
            chmax(dp[n], dp[i] + mx[cd+1] - A[i]);
          }
        }
        chmax(dp[n], dp_p[cd+1] - cmn);
        chmax(dp[n], dp_m[cd+1] + cmx);
      }
      chmax(dp_p[cd], dp[n] + A[n]);
      chmax(dp_m[cd], dp[n] - A[n]);
    }
    wt_L(dp[0]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 2]

// --- original code ---
// //no-unlocked
// int N, X[2d5], Y[2d5]; ll A[2d5];
// graph g;
// int d, dist[2d5];
// ll mn[2d5], mx[2d5], dp[2d5], dp_p[2d5], dp_m[2d5];
// int ind[2d5], val[2d5];
// {
//   REP(rd_int()){
//     rd(N);
//     rep(i,N-1) X[i] = i+1, rd(Y[i]--);
//     rep(i,N-1) rd(A[i+1]);
//     g.setEdge(N,N-1,X,Y);
//     g.getDist(0, dist);
//     d = max(dist(N)) + 1;
//     rep(i,d) mn[i] = ll_inf, mx[i] = -ll_inf, dp_p[i] = dp_m[i] = -ll_inf;
//     rep(i,1,N) mn[dist[i]] <?= A[i];
//     rep(i,1,N) mx[dist[i]] >?= A[i];
// 
//     rep(i,N) ind[i] = i, val[i] = dist[i];
//     sortA(N, val, ind);
//     rrep[ind](n,N){
//       int cd = dist[n];
//       ll cmn, cmx;
// 
//       if(cd == d-1){
//         dp[n] = 0;
//       } else {
//         dp[n] = -ll_inf;
//         cmn = ll_inf;
//         cmx = -ll_inf;
//         rep[g.edge[n]](i,g.es[n]) if(dist[i] > cd){
//           cmn <?= A[i];
//           cmx >?= A[i];
//           dp[n] >?= dp[i] + A[i] - mn[cd+1];
//           dp[n] >?= dp[i] + mx[cd+1] - A[i];
//         }
//         dp[n] >?= dp_p[cd+1] - cmn;
//         dp[n] >?= dp_m[cd+1] + cmx;
//       }
//       dp_p[cd] >?= dp[n] + A[n];
//       dp_m[cd] >?= dp[n] - A[n];
//     }
//     wt(dp[0]);
//   }
// }