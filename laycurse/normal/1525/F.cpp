#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
void*wmem;
char memarr[96000000];
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
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
    sz =max_L(sz,max_L(3, emem[i]*2));
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
    int vzsjNTAU = N;
    for(i=(1);i<(vzsjNTAU);i++){
      edge[i] = edge[i-1] + es[i-1];
    }
    rev[0] = edge[N-1] + es[N-1];
    int pp18CKSr = N;
    for(i=(1);i<(pp18CKSr);i++){
      rev[i] = rev[i-1] + es[i-1];
    }
    flow[0] = (T*)(rev[N-1] + es[N-1]);
    int CnS5KYSU = N;
    for(i=(1);i<(CnS5KYSU);i++){
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
int M;
int K;
int A[100000];
int B[100000];
long long X[50];
long long Y[50];
int cs;
int command[50];
int t[50];
int tt[50];
int ress;
int res[100];
int ok1[50];
int ok2[50];
maxflow<int,int> flow;
int matchcnt(void){
  int i;
  int node;
  int st;
  int ed;
  node = 2*N;
  st = node++;
  ed = node++;
  flow.init(node);
  for(i=(0);i<(N);i++){
    flow.addEdge(st, i, 1);
  }
  for(i=(0);i<(N);i++){
    flow.addEdge(i+N, ed, 1);
  }
  for(i=(0);i<(M);i++){
    if(ok1[A[i]] && ok2[B[i]]){
      flow.addEdge(A[i], B[i]+N, 1);
    }
  }
  return flow.solve(st, ed);
}
int main(){
  int AlM5nNnR;
  wmem = memarr;
  int i;
  int j;
  int k;
  int cnt;
  long long opt;
  long long tmp;
  rd(N);
  rd(M);
  rd(K);
  {
    int FmcKpFmN;
    for(FmcKpFmN=(0);FmcKpFmN<(M);FmcKpFmN++){
      rd(A[FmcKpFmN]);A[FmcKpFmN] += (-1);
      rd(B[FmcKpFmN]);B[FmcKpFmN] += (-1);
    }
  }
  {
    int t_ynMSdg;
    for(t_ynMSdg=(0);t_ynMSdg<(K);t_ynMSdg++){
      rd(X[t_ynMSdg]);
      rd(Y[t_ynMSdg]);
    }
  }
  flow.malloc(100000);
  for(i=(0);i<(K);i++){
    chmin(Y[i], X[i]);
  }
  for(i=(0);i<(N);i++){
    ok1[i] = ok2[i] = 1;
  }
  cnt = matchcnt();
  while(cnt){
    for(i=(0);i<(N);i++){
      if(ok1[i]){
        ok1[i] = 0;
        tmp = matchcnt();
        if(tmp == cnt-1){
          cnt = tmp;
          command[cs++] = i+1;
          goto APIVbQlN;
        }
        ok1[i] = 1;
      }
    }
    for(i=(0);i<(N);i++){
      if(ok2[i]){
        ok2[i] = 0;
        tmp = matchcnt();
        if(tmp == cnt-1){
          cnt = tmp;
          command[cs++] = -(i+1);
          goto APIVbQlN;
        }
        ok2[i] = 1;
      }
    }
    APIVbQlN:;
  }
  for(AlM5nNnR=(0);AlM5nNnR<(N-1-K);AlM5nNnR++){
    if(cs > 0){
      cs--;
    }
  }
  for(i=(0);i<(cs);i++){
    int gEg5UqEA;
    remove_reference<decltype(Y[gEg5UqEA])>::type qSsg05KM;
    int Hjfu7Vx7 = 0;
    int zT28qSmp;
    if((0) > ((K-i)-1)){
      qSsg05KM = 0;
    }
    else{
      for(gEg5UqEA = 0; gEg5UqEA <= (K-i)-1; gEg5UqEA++){
        if(Hjfu7Vx7 == 0){
          qSsg05KM = Y[gEg5UqEA];
          zT28qSmp = gEg5UqEA;
          Hjfu7Vx7 = 1;
          continue;
        }
        const auto aTqQ6rt8 = Y[gEg5UqEA];
        if(qSsg05KM > aTqQ6rt8){
          qSsg05KM = aTqQ6rt8;
          zT28qSmp = gEg5UqEA;
        }
      }
    }
    tt[i] = t[i] =zT28qSmp;
  }
  opt = 0;
  for(i=(0);i<(cs);i++){
    opt += Y[t[i]];
  }
  for(k=(0);k<(K);k++){
    tmp = X[k];
    for(i=(0);i<(cs);i++){
      if(K-1-i < k){
        tmp += Y[tt[i]];
      }
    }
    if(tmp < opt){
      for(i=(0);i<(cs);i++){
        t[i] = tt[i];
      }
      for(i=(0);i<(cs);i++){
        if(K-1-i >= k){
          t[i] = k;
        }
      }
      opt = tmp;
    }
  }
  sortA_L(cs, t);
  j = 0;
  for(i=(0);i<(K);i++){
    while(j < cs && t[j] == i){
      res[ress++] = command[j];
      j++;
    }
    res[ress++] = 0;
  }
  wt_L(ress);
  wt_L('\n');
  {
    int sMcf5Tpe;
    if(ress==0){
      wt_L('\n');
    }
    else{
      for(sMcf5Tpe=(0);sMcf5Tpe<(ress-1);sMcf5Tpe++){
        wt_L(res[sMcf5Tpe]);
        wt_L(' ');
      }
      wt_L(res[sMcf5Tpe]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210508-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M, K, A[1d5], B[1d5];
// ll X[50], Y[50];
// int cs, command[50], t[50], tt[50];
// int ress, res[100];
// 
// int ok1[50], ok2[50];
// maxflow<int,int> flow;
// 
// int matchcnt(void){
//   int node, st, ed;
//   node = 2*N;
//   st = node++;
//   ed = node++;
//   flow.init(node);
//   rep(i,N) flow.addEdge(st, i, 1);
//   rep(i,N) flow.addEdge(i+N, ed, 1);
//   rep(i,M) if(ok1[A[i]] && ok2[B[i]]) flow.addEdge(A[i], B[i]+N, 1);
//   return flow.solve(st, ed);
// }
// 
// {
//   int i, j, k, cnt;
//   ll opt, tmp;
//   rd(N,M,K,(A--,B--)(M),(X,Y)(K));
//   flow.malloc(1d5);
// 
//   rep(i,K) Y[i] <?= X[i];
// 
//   rep(i,N) ok1[i] = ok2[i] = 1;
//   cnt = matchcnt();
// 
//   while(cnt){
//     rep(i,N) if(ok1[i]){
//       ok1[i] = 0;
//       tmp = matchcnt();
//       if(tmp == cnt-1){
//         cnt = tmp;
//         command[cs++] = i+1;
//         break_continue;
//       }
//       ok1[i] = 1;
//     }
//     rep(i,N) if(ok2[i]){
//       ok2[i] = 0;
//       tmp = matchcnt();
//       if(tmp == cnt-1){
//         cnt = tmp;
//         command[cs++] = -(i+1);
//         break_continue;
//       }
//       ok2[i] = 1;
//     }
//   }
//   rep(N-1-K) if(cs > 0) cs--;
// 
//   rep(i,cs) tt[i] = t[i] = argmin(Y(K-i));
//   
//   opt = 0;
//   rep(i,cs) opt += Y[t[i]];
//   rep(k,K){
//     tmp = X[k];
//     rep(i,cs) if(K-1-i < k) tmp += Y[tt[i]];
//     if(tmp < opt){
//       rep(i,cs) t[i] = tt[i];
//       rep(i,cs) if(K-1-i >= k) t[i] = k;
//       opt = tmp;
//     }
//   }
// 
//   sortA(cs, t);
//   j = 0;
//   rep(i,K){
//     while(j < cs && t[j] == i) res[ress++] = command[j], j++;
//     res[ress++] = 0;
//   }
// 
//   wt(ress);
//   wt(res(ress));
// }