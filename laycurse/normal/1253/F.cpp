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
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> > *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
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
inline void rd(long long &x){
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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    putchar(f[s]+'0');
  }
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(double x){
  printf("%.15f",x);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    putchar(x[i]);
  }
}
template<class S> void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
struct unionFind{
  int *d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void init(const int n){
    int i;
    N = n;
    for(i=(0);i<(n);i++){
      d[i] = -1;
    }
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    int t = a;
    int k;
    while(d[t]>=0){
      t=d[t];
    }
    while(d[a]>=0){
      k=d[a];
      d[a]=t;
      a=k;
    }
    return a;
  }
  inline int connect(int a, int b){
    if(d[a]>=0){
      a=get(a);
    }
    if(d[b]>=0){
      b=get(b);
    }
    if(a==b){
      return 0;
    }
    if(d[a] < d[b]){
      d[a] += d[b];
      d[b] = a;
    }
    else{
      d[b] += d[a];
      d[a] = b;
    }
    return 1;
  }
  inline int operator()(int a){
    return get(a);
  }
  inline int operator()(int a, int b){
    return connect(a,b);
  }
  inline int& operator[](const int a){
    return d[a];
  }
  inline int size(int a){
    a = get(a);
    return -d[a];
  }
  inline int sizeList(int res[]){
    int i;
    int sz=0;
    for(i=(0);i<(N);i++){
      if(d[i]<0){
        res[sz++] = -d[i];
      }
    }
    return sz;
  }
}
;
template <class T> struct LHeap{
  int *hp;
  int *place;
  int size;
  T *val;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place=(int*)std::malloc(N*sizeof(int));
    val=(T*)std::malloc(N*sizeof(T));
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&val, N, mem);
  }
  void free(){
    std::free(hp);
    std::free(place);
    std::free(val);
  }
  void init(int N){
    int i;
    size=0;
    for(i=(0);i<(N);i++){
      place[i]=-1;
    }
  }
  void up(int n){
    int m;
    while(n){
      m=(n-1)/2;
      if(val[hp[m]]<=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void down(int n){
    int m;
    for(;;){
      m=2*n+1;
      if(m>=size){
        break;
      }
      if(m+1<size&&val[hp[m]]>val[hp[m+1]]){
        m++;
      }
      if(val[hp[m]]>=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void change(int n, T v){
    T f = val[n];
    val[n] = v;
    if(place[n]==-1){
      place[n] = size;
      hp[size++] = n;
      up(place[n]);
    }
    else{
      if(f < v){
        down(place[n]);
      }
      else if(f > v){
        up(place[n]);
      }
    }
  }
  int pop(void){
    int res = hp[0];
    place[res] = -1;
    size--;
    if(size){
      hp[0]=hp[size];
      place[hp[0]]=0;
      down(0);
    }
    return res;
  }
}
;
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
    int ljoQAiQr = N;
    for(i=(1);i<(ljoQAiQr);i++){
      fixed[i] = 0;
    }
    int lKnVhCjA = N;
    for(i=(1);i<(lKnVhCjA);i++){
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
template<class T> struct wgraph{
  int N;
  int *es;
  int **edge;
  T **cost;
  graph g;
  void setEdge(int N__, int M, int A[], int B[], T C[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    walloc1d(&cost, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&cost[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]] = B[i];
      edge[B[i]][es[B[i]]] = A[i];
      cost[A[i]][es[A[i]]++] = C[i];
      cost[B[i]][es[B[i]]++] = C[i];
    }
    g.N = N;
    g.es = es;
    g.edge = edge;
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
template<class T> struct HLD_segtree{
  HLD *hld;
  segtree<T> *seg;
  void init(HLD *hld__, T initval[], void **mem = &wmem){
    int i;
    int j;
    hld = hld__;
    walloc1d(&seg, hld->groupNum, mem);
    for(i=(0);i<(hld->groupNum);i++){
      seg[i].walloc(hld->groupSize[i], 0, mem);
      seg[i].setN(hld->groupSize[i], 0, 0);
      if(initval!=NULL){
        for(j=(0);j<(hld->groupSize[i]);j++){
          seg[i][j] = initval[ hld->groupNode[i][j] ];
        }
      }
      else{
        for(j=(0);j<(hld->groupSize[i]);j++){
          seg[i][j] = 0;
        }
      }
      seg[i].build();
    }
  }
  inline void change(int u, int v, T val){
    int ug;
    int vg;
    int ui;
    int vi;
    ug = hld->group[u];
    vg = hld->group[v];
    while(ug != vg){
      if(hld->groupDepth[ug] < hld->groupDepth[vg]){
        swap(u, v);
        swap(ug, vg);
      }
      seg[ug].change(0, hld->groupind[u]+1, val);
      u = hld->groupUpNode[ug];
      ug = hld->group[u];
    }
    ui = hld->groupind[u];
    vi = hld->groupind[v];
    seg[ug].change(min_L(ui, vi),max_L(ui, vi)+1, val);
  }
  inline void add(int u, int v, T val){
    int ug;
    int vg;
    int ui;
    int vi;
    ug = hld->group[u];
    vg = hld->group[v];
    while(ug != vg){
      if(hld->groupDepth[ug] < hld->groupDepth[vg]){
        swap(u, v);
        swap(ug, vg);
      }
      seg[ug].add(0, hld->groupind[u]+1, val);
      u = hld->groupUpNode[ug];
      ug = hld->group[u];
    }
    ui = hld->groupind[u];
    vi = hld->groupind[v];
    seg[ug].add(min_L(ui, vi),max_L(ui, vi)+1, val);
  }
  inline pair<T,int> getMin(int u, int v){
    pair<T,int> res;
    pair<T,int> tmp;
    int ug;
    int vg;
    int ui;
    int vi;
    ug = hld->group[u];
    vg = hld->group[v];
    res.first = numeric_limits<T>::max();
    res.second = -1;
    while(ug != vg){
      if(hld->groupDepth[ug] < hld->groupDepth[vg]){
        swap(u, v);
        swap(ug, vg);
      }
      tmp = seg[ug].getMin(0, hld->groupind[u]+1);
      tmp.second = hld->groupNode[ug][tmp.second];
      chmin(res, tmp);
      u = hld->groupUpNode[ug];
      ug = hld->group[u];
    }
    ui = hld->groupind[u];
    vi = hld->groupind[v];
    tmp = seg[ug].getMin(min_L(ui, vi),max_L(ui, vi)+1);
    tmp.second = hld->groupNode[ug][tmp.second];
    chmin(res, tmp);
    return res;
  }
  inline T getMinVal(int u, int v){
    return getMin(u,v).first;
  }
  inline int getMinInd(int u, int v){
    return getMin(u,v).second;
  }
  inline T getSum(int u, int v){
    T res;
    int ug;
    int vg;
    int ui;
    int vi;
    ug = hld->group[u];
    vg = hld->group[v];
    res = 0;
    while(ug != vg){
      if(hld->groupDepth[ug] < hld->groupDepth[vg]){
        swap(u, v);
        swap(ug, vg);
      }
      res += seg[ug].getSum(0, hld->groupind[u]+1);
      u = hld->groupUpNode[ug];
      ug = hld->group[u];
    }
    ui = hld->groupind[u];
    vi = hld->groupind[v];
    res += seg[ug].getSum(min_L(ui, vi),max_L(ui, vi)+1);
    return res;
  }
}
;
int N;
int M;
int K;
int Q;
int A[300000];
int B[300000];
int X;
int Y;
long long C[300000];
int ss[100000];
int mmm;
int aaa[300000];
int bbb[300000];
long long ccc[300000];
int mm;
int aa[100000];
int bb[100000];
long long cc[100000];
long long arr[100000];
int main(){
  int jbtyPBGc;
  wmem = memarr;
  int i;
  int j;
  int k;
  wgraph<long long> g;
  unionFind uf;
  HLD hld;
  HLD_segtree<long long> t;
  LHeap<long long> hp;
  long long tmp;
  rd(N);
  rd(M);
  rd(K);
  rd(Q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
      rd(C[Lj4PdHRW]);
    }
  }
  g.setEdge(N,M,A,B,C);
  hp.malloc(N);
  hp.init(N);
  for(i=(0);i<(K);i++){
    hp.change(i,0);
  }
  for(i=(K);i<(N);i++){
    hp.change(i,4611686016279904256LL);
  }
  for(i=(0);i<(K);i++){
    ss[i] = i;
  }
  while(hp.size){
    i = hp.pop();
    for(j=(0);j<(g.es[i]);j++){
      k = g.edge[i][j];
      if(hp.val[k] > hp.val[i] + g.cost[i][j]){
        hp.change(k, hp.val[i] + g.cost[i][j]);
        ss[k] = ss[i];
      }
    }
  }
  uf.malloc(N);
  uf.init(N);
  for(i=(0);i<(M);i++){
    if(ss[A[i]] != ss[B[i]]){
      arrInsert(mmm, mmm, aaa, ss[A[i]], bbb, ss[B[i]], ccc, hp.val[A[i]] + hp.val[B[i]] + C[i]);
    }
  }
  sortA_L(mmm,ccc,aaa,bbb);
  for(i=(0);i<(mmm);i++){
    if(uf(aaa[i],bbb[i])){
      arrInsert(mm, mm, aa, aaa[i], bb, bbb[i], cc, ccc[i]);
    }
  }
  g.setEdge(K, mm, aa, bb, cc);
  hld.init(g.g);
  for(i=(0);i<(mm);i++){
    j = hld.depth(aa[i]);
    k = hld.depth(bb[i]);
    if(j > k){
      arr[aa[i]] = -cc[i];
    }
    else{
      arr[bb[i]] = -cc[i];
    }
  }
  t.init(&hld, arr);
  for(jbtyPBGc=(0);jbtyPBGc<(Q);jbtyPBGc++){
    rd(X);X += (-1);
    rd(Y);Y += (-1);
    k = hld.lca(X, Y);
    t.change(k,k,1);
    wt_L(-t.getMinVal(X,Y));
    wt_L('\n');
    t.change(k,k,arr[k]);
  }
  return 0;
}
// cLay varsion 20191125-1

// --- original code ---
// //no-unlocked
// int N, M, K, Q, A[3d5], B[3d5], X, Y; ll C[3d5];
// 
// int ss[1d5];
// int mmm, aaa[3d5], bbb[3d5]; ll ccc[3d5];
// int mm, aa[1d5], bb[1d5]; ll cc[1d5];
// ll arr[1d5];
// 
// {
//   int i, j, k;
//   wgraph<ll> g;
//   unionFind uf;
//   HLD hld;
//   HLD_segtree<ll> t;
//   LHeap<ll> hp;
//   ll tmp;
// 
//   rd(N,M,K,Q,(A--,B--,C)(M));
//   g.setEdge(N,M,A,B,C);
// 
//   hp.malloc(N);
//   hp.init(N);
//   rep(i,K) hp.change(i,0);
//   rep(i,K,N) hp.change(i,ll_inf);
//   rep(i,K) ss[i] = i;
//   while(hp.size){
//     i = hp.pop();
//     rep(j,g.es[i]){
//       k = g.edge[i][j];
//       if(hp.val[k] > hp.val[i] + g.cost[i][j]){
//         hp.change(k, hp.val[i] + g.cost[i][j]);
//         ss[k] = ss[i];
//       }
//     }
//   }
// 
//   uf.malloc(N);
//   uf.init(N);
//   rep(i,M) if(ss[A[i]] != ss[B[i]]) arrInsert(mmm, mmm, aaa, ss[A[i]], bbb, ss[B[i]], ccc, hp.val[A[i]] + hp.val[B[i]] + C[i]);
//   sortA(mmm,ccc,aaa,bbb);
//   rep(i,mmm) if(uf(aaa[i],bbb[i])) arrInsert(mm, mm, aa, aaa[i], bb, bbb[i], cc, ccc[i]);
// 
//   g.setEdge(K, mm, aa, bb, cc);
//   hld.init(g.g);
// 
//   rep(i,mm){
//     j = hld.depth(aa[i]);
//     k = hld.depth(bb[i]);
//     if(j > k) arr[aa[i]] = -cc[i];
//     else      arr[bb[i]] = -cc[i];
//   }
// 
//   t.init(&hld, arr);
//   rep(Q){
//     rd(X--,Y--);
//     k = hld.lca(X, Y);
//     t.change(k,k,1);
//     wt(-t.getMinVal(X,Y));
//     t.change(k,k,arr[k]);
//   }
// }