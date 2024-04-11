#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
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
template<class T> void malloc1d(T **arr, int x){
  (*arr) = (T*)malloc(x*sizeof(T));
}
template<class T> void free1d(T *arr){
  free(arr);
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
template<class T> struct segtree{
  int N;
  int logN;
  T *sum;
  T *mn;
  int *mnind;
  T *fixval;
  char *fixed;
  T *addval;
  void malloc(int maxN, int once = 0){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    sum = new T[2*i];
    mn = new T[2*i];
    mnind = new int[2*i];
    fixval = new T[i];
    addval = new T[i];
    fixed = new char[i];
    if(once){
      setN(maxN);
    }
  }
  void walloc(int maxN, int once = 0, void **mem = &wmem){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    walloc1d(&sum, 2*i, mem);
    walloc1d(&mn, 2*i, mem);
    walloc1d(&mnind, 2*i, mem);
    walloc1d(&fixval, i, mem);
    walloc1d(&addval, i, mem);
    walloc1d(&fixed, i, mem);
    if(once){
      setN(maxN);
    }
  }
  void free(void){
    delete [] sum;
    delete [] mn;
    delete [] mnind;
    delete [] fixval;
    delete [] addval;
    delete [] fixed;
  }
  T& operator[](int i){
    return sum[N+i];
  }
  void setN(int n, int zerofill = 1, int dobuild = 1){
    int i;
    for(i=1,logN=0;i<n;i*=2,logN++){
      ;
    }
    N = i;
    if(zerofill){
      for(i=(0);i<(N);i++){
        sum[N+i] = 0;
      }
    }
    if(dobuild){
      build();
    }
  }
  void build(void){
    int i;
    for(i=(0);i<(N);i++){
      mn[N+i] = sum[N+i];
      mnind[N+i] = i;
    }
    for(i=N-1;i;i--){
      sum[i] = sum[2*i] + sum[2*i+1];
      if(mn[2*i] <= mn[2*i+1]){
        mn[i] = mn[2*i];
        mnind[i] = mnind[2*i];
      }
      else{
        mn[i] = mn[2*i+1];
        mnind[i] = mnind[2*i+1];
      }
    }
    int eNrGll8F = N;
    for(i=(1);i<(eNrGll8F);i++){
      fixed[i] = 0;
    }
    int bz47bCAl = N;
    for(i=(1);i<(bz47bCAl);i++){
      addval[i] = 0;
    }
  }
  inline void push_one(int a, int sz, int st){
    if(fixed[a]){
      if(sz > 1){
        fixed[a*2] = fixed[a*2+1] = 1;
        fixval[a*2] = fixval[a*2+1] = fixval[a];
        sum[a*2] = sum[a*2+1] = sz * fixval[a];
        mn[a*2] = mn[a*2+1] = fixval[a];
        mnind[a*2] = st;
        mnind[a*2+1] = st + sz;
      }
      else{
        sum[a*2] = sum[a*2+1] = sz * fixval[a];
        mn[a*2] = mn[a*2+1] = fixval[a];
        mnind[a*2] = st;
        mnind[a*2+1] = st + sz;
      }
      fixed[a] = 0;
      addval[a] = 0;
      return;
    }
    if(addval[a] != 0){
      if(sz > 1){
        if(fixed[a*2]){
          fixval[a*2] += addval[a];
        }
        else{
          addval[a*2] += addval[a];
        }
        if(fixed[a*2+1]){
          fixval[a*2+1] += addval[a];
        }
        else{
          addval[a*2+1] += addval[a];
        }
        sum[a*2] += sz * addval[a];
        sum[a*2+1] += sz * addval[a];
        mn[a*2] += addval[a];
        mn[a*2+1] += addval[a];
      }
      else{
        sum[a*2] += sz * addval[a];
        sum[a*2+1] += sz * addval[a];
        mn[a*2] += addval[a];
        mn[a*2+1] += addval[a];
      }
      addval[a] = 0;
      return;
    }
  }
  inline void push(int a){
    int i;
    int aa = a - N;
    int nd;
    int sz;
    int st;
    for(i=logN;i;i--){
      nd = a>>i;
      sz = 1<<(i-1);
      st = 2 * sz * (aa>>i);
      push_one(nd, sz, st);
    }
  }
  inline void build(int a){
    int sz = 1;
    int st = a - N;
    while(a > 1){
      if(a%2){
        st += sz;
      }
      a /= 2;
      sz *= 2;
      if(fixed[a]){
        sum[a] = sz * fixval[a];
        mn[a] = fixval[a];
      }
      else{
        sum[a] = sum[a*2] + sum[a*2+1];
        if(mn[a*2] <= mn[a*2+1]){
          mn[a] = mn[a*2];
          mnind[a] = mnind[a*2];
        }
        else{
          mn[a] = mn[a*2+1];
          mnind[a] = mnind[a*2+1];
        }
        if(addval[a] != 0){
          mn[a] += addval[a];
          sum[a] += sz * addval[a];
        }
      }
    }
  }
  inline void change(int a, int b, T val){
    int sz = 1;
    int aa;
    int bb;
    int st_a = a;
    int st_b = b;
    if(a >= b){
      return;
    }
    aa = (a += N);
    bb = (b += N);
    push(a);
    push(b-1);
    if(a%2){
      sum[a] = mn[a] = val;
      a++;
      st_a += sz;
    }
    if(b%2){
      b--;
      st_b -= sz;
      sum[b] = mn[b] = val;
    }
    a /= 2;
    b /= 2;
    while(a < b){
      sz *= 2;
      if(a%2){
        fixed[a]=1;
        fixval[a]=val;
        sum[a] = sz * val;
        mn[a] = val;
        mnind[a] = st_a;
        a++;
        st_a += sz;
      }
      if(b%2){
        b--;
        st_b -= sz;
        fixed[b]=1;
        fixval[b]=val;
        sum[b] = sz * val;
        mn[b] = val;
        mnind[b] = st_b;
      }
      a /= 2;
      b /= 2;
    }
    build(aa);
    build(bb-1);
  }
  inline void add(int a, int b, T val){
    int sz = 1;
    int aa;
    int bb;
    if(a >= b){
      return;
    }
    aa = (a += N);
    bb = (b += N);
    push(a);
    push(b-1);
    if(a%2){
      sum[a] += val;
      mn[a] += val;
      a++;
    }
    if(b%2){
      b--;
      sum[b] += val;
      mn[b] += val;
    }
    a /= 2;
    b /= 2;
    while(a < b){
      sz *= 2;
      if(a%2){
        if(fixed[a]){
          fixval[a] += val;
        }
        else{
          addval[a] += val;
        }
        sum[a] += sz * val;
        mn[a] += val;
        a++;
      }
      if(b%2){
        b--;
        if(fixed[b]){
          fixval[b] += val;
        }
        else{
          addval[b] += val;
        }
        sum[b] += sz * val;
        mn[b] += val;
      }
      a /= 2;
      b /= 2;
    }
    build(aa);
    build(bb-1);
  }
  inline pair<T,int> getMin(int a, int b){
    pair<T,int> res;
    pair<T,int> tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    push(a);
    push(b-1);
    while(a < b){
      if(a%2){
        if(fga){
          res =min_L(res, make_pair(mn[a], mnind[a]));
        }
        else{
          res = make_pair(mn[a], mnind[a]);
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =min_L(make_pair(mn[b], mnind[b]), tmp);
        }
        else{
          tmp = make_pair(mn[b], mnind[b]);
          fgb = 1;
        }
      }
      a /= 2;
      b /= 2;
    }
    if(fga==1 && fgb==0){
      return res;
    }
    if(fga==0 && fgb==1){
      return tmp;
    }
    if(fga==1 && fgb==1){
      res =min_L(res, tmp);
      return res;
    }
    return res;
  }
  inline T getMinVal(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    push(a);
    push(b-1);
    while(a < b){
      if(a%2){
        if(fga){
          res =min_L(res, mn[a]);
        }
        else{
          res = mn[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =min_L(mn[b], tmp);
        }
        else{
          tmp = mn[b];
          fgb = 1;
        }
      }
      a /= 2;
      b /= 2;
    }
    if(fga==1 && fgb==0){
      return res;
    }
    if(fga==0 && fgb==1){
      return tmp;
    }
    if(fga==1 && fgb==1){
      res =min_L(res, tmp);
      return res;
    }
    return res;
  }
  inline int getMinInd(int a, int b){
    return getMin(a,b).second;
  }
  inline T getSum(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    push(a);
    push(b-1);
    while(a < b){
      if(a%2){
        if(fga){
          res = res + sum[a];
        }
        else{
          res = sum[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp = sum[b] + tmp;
        }
        else{
          tmp = sum[b];
          fgb = 1;
        }
      }
      a /= 2;
      b /= 2;
    }
    if(fga==1 && fgb==0){
      return res;
    }
    if(fga==0 && fgb==1){
      return tmp;
    }
    if(fga==1 && fgb==1){
      res = res + tmp;
      return res;
    }
    return res;
  }
}
;
template<class T> struct Grid1d{
  int n;
  T *d;
  int set_s;
  int set_d;
  T *d_s;
  int *up;
  int *dw;
  int *lf;
  int *rg;
  void malloc(const int nn){
    n = nn;
    set_s = 0;
    set_d = 0;
    malloc1d(&d, n);
  }
  void free(void){
    free1d(d);
    if(set_s){
      free1d(d_s);
    }
    if(set_d){
      free1d(up);
      free1d(dw);
    }
  }
  T& operator[](int a){
    return d[a];
  }
  void setSum(void){
    int i;
    if(set_s == 0){
      set_s = 1;
      malloc1d(&d_s, n+1);
    }
    d_s[0] = 0;
    for(i=(0);i<(n);i++){
      d_s[i+1] = d_s[i] + d[i];
    }
  }
  void setDir(void){
    int i;
    if(set_d == 0){
      set_d = 1;
      malloc1d(&up, n);
      malloc1d(&dw, n);
      lf = dw;
      rg = up;
    }
    lf[0] = 1;
    for(i=(1);i<(n);i++){
      if(d[i]==d[i-1]){
        lf[i] = 1 + lf[i-1];
      }
      else{
        lf[i] = 1 ;
      }
    }
    rg[n-1] = 1;
    for(i=n-2;i>=0;i--){
      if(d[i]==d[i+1]){
        rg[i] = 1 + rg[i+1];
      }
      else{
        rg[i] = 1 ;
      }
    }
  }
  void setDirMatch(const T v){
    int i;
    if(set_d == 0){
      set_d = 1;
      malloc1d(&up, n);
      malloc1d(&dw, n);
      lf = dw;
      rg = up;
    }
    if(d[0]==v){
      lf[0] =1;
    }
    else{
      lf[0] =0;
    }
    for(i=(1);i<(n);i++){
      if(d[i]==v){
        lf[i] =1 + lf[i-1];
      }
      else{
        lf[i] =0;
      }
    }
    if(d[n-1]==v){
      rg[n-1] =1;
    }
    else{
      rg[n-1] =0;
    }
    for(i=n-2;i>=0;i--){
      if(d[i]==v){
        rg[i] =1 + rg[i+1];
      }
      else{
        rg[i] =0;
      }
    }
  }
  inline T getSum(const int a, const int b){
    return d_s[b+1] - d_s[a];
  }
}
;
int N;
int M;
int K;
int A[50][20000];
Grid1d<int> g[50];
int dp1[20000];
int dp2[20000];
int nx1[20000];
int nx2[20000];
int main(){
  int tm;
  wmem = memarr;
  int res;
  int v;
  int i;
  int j;
  int k;
  segtree<int> t;
  rd(N);
  rd(M);
  rd(K);
  for(i=(0);i<(N);i++){
    {
      int Q5VJL1cS;
      for(Q5VJL1cS=(0);Q5VJL1cS<(M);Q5VJL1cS++){
        rd(A[i][Q5VJL1cS]);
      }
    }
  }
  for(k=(0);k<(N);k++){
    g[k].malloc(M);
  }
  for(k=(0);k<(N);k++){
    for(i=(0);i<(M);i++){
      g[k][i] = A[k][i];
    }
  }
  for(k=(0);k<(N);k++){
    g[k].setSum();
  }
  for(i=(0);i<(M);i++){
    dp1[i] = g[0].getSum(i,min_L(i+K-1, M-1));
    if(N>1){
      dp1[i] += g[1].getSum(i,min_L(i+K-1, M-1));
    }
  }
  for(i=(0);i<(M);i++){
    dp2[i] = g[0].getSum(max_L(max_L(0, i-K+1), 0),i);
    if(N>1){
      dp2[i] += g[1].getSum(max_L(max_L(0, i-K+1), 0),i);
    }
  }
  t.malloc(M);
  for(tm=(1);tm<(N);tm++){
    t.setN(M);
    for(i=(0);i<(M);i++){
      t[i] = -dp2[i];
    }
    t.build();
    for(i=(M)-1;i>=(0);i--){
      t.add(i,M,A[tm][i]);
      v = -t.getMinVal(0,M);
      v += g[tm].getSum(i,min_L(i+K-1, M-1));
      if(tm+1 < N){
        v += g[tm+1].getSum(i,min_L(i+K-1, M-1));
      }
      nx1[i] = v;
    }
    t.setN(M);
    for(i=(0);i<(M);i++){
      t[i] = -dp1[i];
    }
    t.build();
    for(i=(0);i<(M);i++){
      t.add(0,i+1,A[tm][i]);
      v = -t.getMinVal(0,M);
      v += g[tm].getSum(max_L(max_L(0, i-K+1), 0),i);
      ;
      if(tm+1 < N){
        v += g[tm+1].getSum(max_L(max_L(0, i-K+1), 0),i);
      }
      ;
      nx2[i] = v;
    }
    for(i=(0);i<(M-K+1);i++){
      j = i + K - 1;
      nx1[i] = nx2[j] =max_L(nx1[i], nx2[j]);
    }
    for(i=(0);i<(M);i++){
      dp1[i] = nx1[i];
    }
    for(i=(0);i<(M);i++){
      dp2[i] = nx2[i];
    }
  }
  {
    int qE8LMwYZ;
    int dKuENJNI;
    if(M==0){
      dKuENJNI = 0;
    }
    else{
      dKuENJNI = dp1[0];
      for(qE8LMwYZ=(1);qE8LMwYZ<(M);qE8LMwYZ++){
        dKuENJNI = max_L(dKuENJNI, dp1[qE8LMwYZ]);
      }
    }
    int HOAyP4rA;
    if(M==0){
      HOAyP4rA = 0;
    }
    else{
      HOAyP4rA = dp2[0];
      for(qE8LMwYZ=(1);qE8LMwYZ<(M);qE8LMwYZ++){
        HOAyP4rA = max_L(HOAyP4rA, dp2[qE8LMwYZ]);
      }
    }
    res =max_L(dKuENJNI, HOAyP4rA);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200214-1

// --- original code ---
// //no-unlocked
// int N, M, K, A[50][2d4];
// 
// Grid1d<int> g[50];
// int dp1[2d4], dp2[2d4], nx1[2d4], nx2[2d4];
// 
// {
//   int res, v, i, j, k;
//   segtree<int> t;
//   rd(N,M,K);
//   rep(i,N) rd(A[i](M));
// 
//   rep(k,N) g[k].malloc(M);
//   rep(k,N) rep(i,M) g[k][i] = A[k][i];
//   rep(k,N) g[k].setSum();
//   rep(i,M){
//     dp1[i] = g[0].getSum(i,min(i+K-1,M-1));
//     if(N>1) dp1[i] += g[1].getSum(i,min(i+K-1,M-1));
//   }
//   rep(i,M){
//     dp2[i] = g[0].getSum(max(0,i-K+1,0),i);
//     if(N>1) dp2[i] += g[1].getSum(max(0,i-K+1,0),i);
//   }
// 
//   t.malloc(M);
// 
//   rep(tm,1,N){
//     t.setN(M);
//     rep(i,M) t[i] = -dp2[i];
//     t.build();
//     rrep(i,M){
//       t.add(i,M,A[tm][i]);
//       v = -t.getMinVal(0,M);
//       v += g[tm].getSum(i,min(i+K-1,M-1));
//       if(tm+1 < N) v += g[tm+1].getSum(i,min(i+K-1,M-1));
//       nx1[i] = v;
//     }
// 
//     t.setN(M);
//     rep(i,M) t[i] = -dp1[i];
//     t.build();
//     rep(i,M){
//       t.add(0,i+1,A[tm][i]);
//       v = -t.getMinVal(0,M);
//       v += g[tm].getSum(max(0,i-K+1,0),i);;
//       if(tm+1 < N) v += g[tm+1].getSum(max(0,i-K+1,0),i);;
//       nx2[i] = v;
//     }
// 
//     rep(i,M-K+1){
//       j = i + K - 1;
//       nx1[i] = nx2[j] = max(nx1[i], nx2[j]);
//     }
// 
//     rep(i,M) dp1[i] = nx1[i];
//     rep(i,M) dp2[i] = nx2[i];
//   }
//   res = max(dp1(M), dp2(M));
//   wt(res);
// }