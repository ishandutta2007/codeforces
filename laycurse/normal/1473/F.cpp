#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[1048576];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
template<class T, class S> struct maxflow{
  int node;
  int st;
  int ed;
  int*es;
  int*emem;
  int**edge;
  int**rev;
  int*level;
  int*qq;
  T**flow;
  T eps;
  void malloc(int N){
    int i;
    es = (int*)std::malloc(N*sizeof(int));
    emem = (int*)std::malloc(N*sizeof(int));
    level = (int*)std::malloc(N*sizeof(int));
    qq = (int*)std::malloc(N*sizeof(int));
    edge = (int**)std::malloc(N*sizeof(int*));
    rev = (int**)std::malloc(N*sizeof(int*));
    flow = (T**)std::malloc(N*sizeof(T*));
    for(i=(0);i<(N);i++){
      emem[i] = 0;
      edge[i] = rev[i] = NULL;
      flow[i] = NULL;
    }
  }
  void walloc(int N, void**mem = &wmem){
    int i;
    walloc1d(&es, N, mem);
    walloc1d(&emem, N, mem);
    walloc1d(&level, N, mem);
    walloc1d(&qq, N, mem);
    walloc1d(&edge, N, mem);
    walloc1d(&rev, N, mem);
    walloc1d(&flow, N, mem);
    (*mem) = (flow + N);
  }
  void levelize(void){
    int i;
    int j;
    int k;
    int t;
    int q_st = 0;
    int q_ed = 1;
    for(i=(0);i<(node);i++){
      level[i] = -1;
    }
    level[st] = 0;
    qq[0] = st;
    while(q_st != q_ed){
      i = qq[q_st++];
      t = level[i] + 1;
      for(j=(0);j<(es[i]);j++){
        if(flow[i][j] > eps){
          k = edge[i][j];
          if(level[k]!=-1){
            continue;
          }
          level[k] = t;
          qq[q_ed++] = k;
          if(k==ed){
            return;
          }
        }
      }
    }
  }
  S pushflow(int i, S lim){
    int j;
    int k;
    int ji;
    S s;
    S t;
    S res = 0;
    if(i==ed){
      return lim;
    }
    for(j=(0);j<(es[i]);j++){
      if(flow[i][j] > eps){
        k = edge[i][j];
        if(level[k] != level[i]+1){
          continue;
        }
        s =min_L(lim, (S)flow[i][j]);
        t = pushflow(k, s);
        if(!t){
          continue;
        }
        res += t;
        lim -= t;
        ji = rev[i][j];
        flow[i][j] -= t;
        flow[k][ji] += t;
        if(!lim){
          break;
        }
      }
    }
    if(lim){
      level[i] = -1;
    }
    return res;
  }
  S solve(int st_, int ed_){
    S res = 0;
    st = st_;
    ed = ed_;
    for(;;){
      levelize();
      if(level[ed] == -1){
        break;
      }
      res += pushflow(st, numeric_limits<S>::max());
    }
    return res;
  }
  void init(int N){
    int i;
    node = N;
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    eps = (T)1e-9;
  }
  void memoryExpand(int i, int sz){
    if(sz <= emem[i]){
      return;
    }
    sz =max_L(sz, max_L(3, emem[i]*2));
    emem[i]=sz;
    edge[i] = (int*)realloc(edge[i], sz*sizeof(int));
    rev[i] = (int*)realloc(rev[i], sz*sizeof(int));
    flow[i] = (T*)realloc(flow[i], sz*sizeof(T));
  }
  void addEdge(int n1, int n2, T f1, T f2 = 0){
    int s1 = es[n1]++;
    int s2 = es[n2]++;
    if(s1 >= emem[n1]){
      memoryExpand(n1, es[n1]);
    }
    if(s2 >= emem[n2]){
      memoryExpand(n2, es[n2]);
    }
    edge[n1][s1]=n2;
    edge[n2][s2]=n1;
    flow[n1][s1]=f1;
    flow[n2][s2]=f2;
    rev[n1][s1]=s2;
    rev[n2][s2]=s1;
  }
  void addEdgeAdv(int n1, int n2, T f1, T f2 = 0){
    int s1 = es[n1]++;
    int s2 = es[n2]++;
    edge[n1][s1]=n2;
    edge[n2][s2]=n1;
    flow[n1][s1]=f1;
    flow[n2][s2]=f2;
    rev[n1][s1]=s2;
    rev[n2][s2]=s1;
  }
  void setGraph(int N, int M, int n1[], int n2[], T f1[], T f2[]){
    int i;
    node = N;
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[n1[i]]++;
      es[n2[i]]++;
    }
    for(i=(0);i<(N);i++){
      memoryExpand(i, es[i]);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      addEdgeAdv(n1[i], n2[i], f1[i], f2[i]);
    }
    eps = (T)1e-9;
  }
  void setGraph_w(int N, int M, int n1[], int n2[], T f1[], T f2[], void **mem = wmem){
    int i;
    int j;
    int k;
    node = N;
    for(i=(0);i<(N);i++){
      es[i] = emem[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[n1[i]]++;
      es[n2[i]]++;
    }
    edge[0] = (int*)(*mem);
    int EE5PwD1R = N;
    for(i=(1);i<(EE5PwD1R);i++){
      edge[i] = edge[i-1] + es[i-1];
    }
    rev[0] = edge[N-1] + es[N-1];
    int Wv3_QJ0O = N;
    for(i=(1);i<(Wv3_QJ0O);i++){
      rev[i] = rev[i-1] + es[i-1];
    }
    flow[0] = (T*)(rev[N-1] + es[N-1]);
    int eNrGll8F = N;
    for(i=(1);i<(eNrGll8F);i++){
      flow[i] = flow[i-1] + es[i-1];
    }
    *mem = (void*)(flow[N-1] + es[N-1]);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      addEdgeAdv(n1[i], n2[i], f1[i], f2[i]);
    }
    eps = (T)1e-9;
  }
}
;
int N;
int A[3000];
int B[3000];
int ok[101];
int main(){
  int i;
  wmem = memarr;
  int node;
  int st;
  int ed;
  int res = 0;
  maxflow<int,int> flow;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){
      rd(B[e98WHCEY]);
    }
  }
  node = 2*N;
  st = node++;
  ed = node++;
  flow.malloc(node);
  flow.init(node);
  for(i=(0);i<(N);i++){
    if(B[i] <= 0){
      flow.addEdge(st, i, -B[i]);
    }
  }
  for(i=(0);i<(N);i++){
    if(B[i] > 0){
      flow.addEdge(i, ed, B[i]);
    }
  }
  for(i=(0);i<(N);i++){
    int j, k;
    for(k=(0);k<(101);k++){
      ok[k] = 0;
    }
    for(j=(i+1);j<(N);j++){
      if(!ok[A[j]] && A[j]%A[i]==0){
        ok[A[j]] = 1;
        flow.addEdge(i,j+N,1073709056);
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i+1);j<(N);j++){
      if(A[i]==A[j]){
        flow.addEdge(i+N,j+N,1073709056);
        break;
      }
    }
  }
  for(i=(0);i<(N);i++){
    flow.addEdge(i+N,i,1073709056);
  }
  for(i=(0);i<(N);i++){
    if(B[i] > 0){
      res += B[i];
    }
  }
  res -= flow.solve(st, ed);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// //working_memory=1MB
// int N, A[3000], B[3000], ok[101];
// {
//   int node, st, ed, res = 0;
//   maxflow<int,int> flow;
//   rd(N,A(N),B(N));
// 
//   node = 2*N;
//   st = node++;
//   ed = node++;
//   flow.malloc(node);
//   flow.init(node);
//   rep(i,N) if(B[i] <= 0) flow.addEdge(st, i, -B[i]);
//   rep(i,N) if(B[i] > 0) flow.addEdge(i, ed, B[i]);
//   rep(i,N){
//     rep(k,101) ok[k] = 0;
//     rep(j,i+1,N) if(!ok[A[j]] && A[j]%A[i]==0){
//       ok[A[j]] = 1;
//       flow.addEdge(i,j+N,int_inf);
//     }
//   }
//   rep(i,N){
//     rep(j,i+1,N) if(A[i]==A[j]){
//       flow.addEdge(i+N,j+N,int_inf);
//       break;
//     }
//   }
//   rep(i,N) flow.addEdge(i+N,i,int_inf);
// 
//   rep(i,N) if(B[i] > 0) res += B[i];
//   res -= flow.solve(st, ed);
//   wt(res);
// }