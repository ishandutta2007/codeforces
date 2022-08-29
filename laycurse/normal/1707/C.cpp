#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
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
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
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
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
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
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
struct unionFind{
  int*d;
  int N;
  int M;
  unionFind(){
  }
  unionFind(const char mode, const int n, void **mem = &wmem){
    if(mode == 'm'){
      malloc(n);
    }
    if(mode == 'w'){
      walloc(n, mem);
    }
  }
  unionFind(const char mode, const int n, const int fg, void **mem = &wmem){
    if(mode == 'm'){
      malloc(n, fg);
    }
    if(mode == 'w'){
      walloc(n, fg, mem);
    }
  }
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void malloc(const int n, const int fg){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
    if(fg){
      init(n);
    }
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void walloc(const int n, const int fg, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
    if(fg){
      init(n);
    }
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
  inline int comp(int res[], void *mem = wmem){
    int i;
    int sz=0;
    int*cnt;
    walloc1d(&cnt, N, &mem);
    for(i=(0);i<(N);i++){
      cnt[i] = 0;
    }
    for(i=(0);i<(N);i++){
      cnt[get(i)] = 1;
    }
    for(i=(0);i<(N);i++){
      if(cnt[i]){
        cnt[i] = sz++;
      }
    }
    for(i=(0);i<(N);i++){
      res[i] = cnt[get(i)];
    }
    return sz;
  }
}
;
template<class T> struct segtree{
  int N;
  int logN;
  T*sum;
  T*mn;
  int*mnind;
  T*fixval;
  char*fixed;
  T*addval;
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
    int gt9Icayh = N;
    for(i=(1);i<(gt9Icayh);i++){
      fixed[i] = 0;
    }
    int rnB8a3xI = N;
    for(i=(1);i<(rnB8a3xI);i++){
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
}
;
struct HLD{
  int N;
  int*es;
  int**edge;
  int*group;
  int*groupind;
  int groupNum;
  int*groupSize;
  int**groupNode;
  int*groupUpNode;
  int*groupDepth;
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
    int*q;
    int q_st;
    int q_ed;
    int*sz;
    char*vis;
    void*tmpmem;
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
int id;
int st[200000];
int ed[200000];
int vis[200000];
void EulerTour(graph &g, int n){
  int Nzj9Y0kE;
  int i;
  int j;
  int k;
  st[n] = id++;
  vis[n] = 1;
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(g.es[n]);Nzj9Y0kE++){
    auto&i = g.edge[n][Nzj9Y0kE];
    if(vis[i]==0){
      EulerTour(g, i);
    }
  }
  ed[n] = id;
}
int main(){
  int i;
  wmem = memarr;
  int N;
  int M;
  int A[200000];
  int B[200000];
  int C[200000];
  int mm = 0;
  int aa[200000];
  int bb[200000];
  int z;
  int d;
  int tmp;
  graph g;
  HLD hld;
  unionFind uf;
  segtree<int> t;
  char res[200000+2] = {};
  rd(N);
  rd(M);
  {
    int QAAnbtfa;
    for(QAAnbtfa=(0);QAAnbtfa<(M);QAAnbtfa++){
      rd(A[QAAnbtfa]);A[QAAnbtfa] += (-1);
      rd(B[QAAnbtfa]);B[QAAnbtfa] += (-1);
    }
  }
  uf.walloc(N,1);
  for(i=(0);i<(M);i++){
    C[i] = uf(A[i],B[i]);
  }
  for(i=(0);i<(M);i++){
    if(C[i]){
      arrInsert(mm, mm, aa, A[i], bb, B[i]);
    }
  }
  g.setEdge(N,mm,aa,bb);
  hld.init(g);
  t.walloc(N,1);
  EulerTour(g, 0);
  for(i=(0);i<(M);i++){
    if(C[i]==0){
      t.add(0, N, 1);
      z = hld.lca(A[i],B[i]);
      d = hld.dist(A[i],B[i]);
      if(z == A[i]){
        tmp = hld.up(B[i],d-1);
        t.add(st[tmp], ed[tmp], 1);
        t.add(0, N, -1);
      }
      else{
        t.add(st[A[i]], ed[A[i]], -1);
      }
      if(z == B[i]){
        tmp = hld.up(A[i],d-1);
        t.add(st[tmp], ed[tmp], 1);
        t.add(0, N, -1);
      }
      else{
        t.add(st[B[i]], ed[B[i]], -1);
      }
    }
  }
  for(i=(0);i<(N);i++){
    res[i] = '1';
  }
  for(i=(0);i<(N);i++){
    if(t.getSum(st[i],st[i]+1)){
      res[i]--;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220506-1 [+]

// --- original code ---
// //no-unlocked
// 
// int id, st[2d5], ed[], vis[];
// void EulerTour(graph &g, int n){
//   int i, j, k;
//   st[n] = id++;
//   vis[n] = 1;
//   rep[g.edge[n]](i,g.es[n]) if(vis[i]==0) EulerTour(g, i);
//   ed[n] = id;
// }
// 
// {
//   int N, M, A[2d5], B[], C[], mm = 0, aa[], bb[], z, d, tmp;
//   graph g;
//   HLD hld;
//   unionFind uf;
//   segtree<int> t;
//   char res[2d5+2] = {};
// 
//   rd(N,M,(A--,B--)(M));
// 
//   uf.walloc(N,1);
//   rep(i,M) C[i] = uf(A[i],B[i]);
// 
//   rep(i,M) if(C[i]) arrInsert(mm, mm, aa, A[i], bb, B[i]);
//   g.setEdge(N,mm,aa,bb);
//   hld.init(g);
// 
//   t.walloc(N,1);
//   EulerTour(g, 0);
// 
//   rep(i,M) if(C[i]==0){
//     t.add(0, N, 1);
//     z = hld.lca(A[i],B[i]);
//     d = hld.dist(A[i],B[i]);
// 
//     if(z == A[i]){
//       tmp = hld.up(B[i],d-1);
//       t.add(st[tmp], ed[tmp], 1);
//       t.add(0, N, -1);
//     } else {
//       t.add(st[A[i]], ed[A[i]], -1);
//     }
// 
//     if(z == B[i]){
//       tmp = hld.up(A[i],d-1);
//       t.add(st[tmp], ed[tmp], 1);
//       t.add(0, N, -1);
//     } else {
//       t.add(st[B[i]], ed[B[i]], -1);
//     }
//   }
//   rep(i,N) res[i] = '1';
//   rep(i,N) if(t.getSum(st[i],st[i]+1)) res[i]--;
//   wt(res);
// }