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
struct Rand{
  unsigned x;
  unsigned y;
  unsigned z;
  unsigned w;
  Rand(void){
    x=123456789;
    y=362436069;
    z=521288629;
    w=(unsigned)time(NULL);
  }
  Rand(unsigned seed){
    x=123456789;
    y=362436069;
    z=521288629;
    w=seed;
  }
  inline unsigned get(void){
    unsigned t;
    t = (x^(x<<11));
    x=y;
    y=z;
    z=w;
    w = (w^(w>>19))^(t^(t>>8));
    return w;
  }
  inline double getUni(void){
    return get()/4294967296.0;
  }
  inline int get(int a){
    return (int)(a*getUni());
  }
  inline int get(int a, int b){
    return a+(int)((b-a+1)*getUni());
  }
  inline long long get(long long a){
    return(long long)(a*getUni());
  }
  inline long long get(long long a, long long b){
    return a+(long long)((b-a+1)*getUni());
  }
  inline double get(double a, double b){
    return a+(b-a)*getUni();
  }
  inline int getExp(int a){
    return(int)(exp(getUni()*log(a+1.0))-1.0);
  }
  inline int getExp(int a, int b){
    return a+(int)(exp(getUni()*log((b-a+1)+1.0))-1.0);
  }
}
;
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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
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
    my_putchar(f[s]+'0');
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
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
    my_putchar(f[s]+'0');
  }
}
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
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
template <class T> struct DijkstraHeap{
  int*hp;
  int*place;
  int size;
  char*visited;
  T*val;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place = (int*)std::malloc(N*sizeof(int));
    visited = (char*)std::malloc(N*sizeof(char));
    val = (T*)std::malloc(N*sizeof(T));
  }
  void free(){
    std::free(hp);
    std::free(place);
    std::free(visited);
    std::free(val);
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&visited, N, mem);
    walloc1d(&val, N, mem);
  }
  void malloc(int N, int init_fg){
    malloc(N);
    if(init_fg){
      init(N);
    }
  }
  void walloc(int N, int init_fg, void **mem=&wmem){
    walloc(N,mem);
    if(init_fg){
      init(N);
    }
  }
  void init(int N){
    int i;
    size = 0;
    for(i=(0);i<(N);i++){
      place[i]=-1;
    }
    for(i=(0);i<(N);i++){
      visited[i]=0;
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
    if(visited[n]||(place[n]>=0&&val[n]<=v)){
      return;
    }
    val[n]=v;
    if(place[n]==-1){
      place[n]=size;
      hp[size++]=n;
      up(place[n]);
    }
    else{
      up(place[n]);
    }
  }
  int pop(void){
    int res=hp[0];
    place[res]=-1;
    size--;
    if(size){
      hp[0]=hp[size];
      place[hp[0]]=0;
      down(0);
    }
    visited[res]=1;
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
template<class T> struct wgraph{
  int N;
  int*es;
  int**edge;
  T**cost;
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
  template<class S> S getDistT(int a, int b, S unreachable = -1, void *mem = wmem){
    int i;
    int j;
    DijkstraHeap<S> hp;
    hp.walloc(N, &mem);
    hp.init(N);
    hp.change(a,0);
    while(hp.size){
      i = hp.pop();
      if(i==b){
        return hp.val[i];
      }
      for(j=(0);j<(es[i]);j++){
        hp.change(edge[i][j], hp.val[i]+cost[i][j]);
      }
    }
    return unreachable;
  }
}
;
struct dimcomp2{
  int B;
  dimcomp2(){
  }
  dimcomp2(int b){
    B = b;
  }
  dimcomp2(int a, int b){
    B = b;
  }
  inline void set(int b){
    B = b;
  }
  inline void set(int a, int b){
    B = b;
  }
  inline int mask(int a, int b){
    return a * B + b;
  }
  inline int operator()(int a, int b){
    return a * B + b;
  }
  inline void para(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
  inline void operator()(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
}
;
unsigned long long HashMap_ullP_L[4];
template<class KEY, class VAL> struct HashMap{
  char*used;
  KEY*key;
  VAL*val;
  int mem;
  int n;
  int mask;
  int init_flag;
  VAL init_val;
  HashMap(){
    mem = 0;
    init_flag = 0;
  }
  ~HashMap(){
    free();
  }
  void expand(int nn){
    if(mem >= nn){
      return;
    }
    if(mem){
      free();
    }
    mem = nn;
    used = new char[nn];
    key = new KEY[nn];
    val = new VAL[nn];
  }
  void free(){
    if(mem){
      mem = 0;
      delete[] used;
      delete[] key;
      delete[] val;
    }
  }
  void init(int nn){
    int i;
    n = 1;
    nn = nn + (nn + 1) / 2;
    while(n < nn){
      n *= 2;
    }
    mask = n - 1;
    expand(n);
    for(i=(0);i<(n);i++){
      used[i] = 0;
    }
    init_flag = 0;
  }
  void init(int nn, VAL ini){
    int i;
    n = 1;
    nn = nn + (nn + 1) / 2;
    while(n < nn){
      n *= 2;
    }
    mask = n - 1;
    expand(n);
    for(i=(0);i<(n);i++){
      used[i] = 0;
    }
    init_flag = 1;
    init_val = ini;
  }
  inline int getHash(const int a){
    unsigned long long d = a;
    d = (((d * HashMap_ullP_L[0]) >> 32) * HashMap_ullP_L[1]) & mask;
    return d;
  }
  inline int getHash(const unsigned a){
    unsigned long long d = a;
    d = (((d * HashMap_ullP_L[0]) >> 32) * HashMap_ullP_L[1]) & mask;
    return d;
  }
  inline int getHash(const long long a){
    unsigned long long d = a;
    d = (((((d * HashMap_ullP_L[0]) >> 32) * HashMap_ullP_L[1]) >> 32) * HashMap_ullP_L[2]) & mask;
    return d;
  }
  inline int getHash(const unsigned long long a){
    unsigned long long d = a;
    d = (((((d * HashMap_ullP_L[0]) >> 32) * HashMap_ullP_L[1]) >> 32) * HashMap_ullP_L[2]) & mask;
    return d;
  }
  inline int getHash(const pair<int,int> a){
    unsigned long long d = (((unsigned long long)a.first) << 32) + ((unsigned long long)a.second);
    d = (((((d * HashMap_ullP_L[0]) >> 32) * HashMap_ullP_L[1]) >> 32) * HashMap_ullP_L[2]) & mask;
    return d;
  }
  inline VAL& operator[](const KEY a){
    int k = getHash(a);
    for(;;){
      if(used[k]==1 && key[k]==a){
        break;
      }
      if(used[k]==0){
        used[k] = 1;
        key[k] = a;
        if(init_flag){
          val[k] = init_val;
        }
        break;
      }
      k = (k+1) & mask;
    }
    return val[k];
  }
  inline bool exist(const KEY a){
    int k = getHash(a);
    for(;;){
      if(used[k]==1 && key[k]==a){
        return true;
      }
      if(used[k]==0){
        break;
      }
      k = (k+1) & mask;
    }
    return false;
  }
  template<class S> inline bool exist(const KEY a, S &res){
    int k = getHash(a);
    for(;;){
      if(used[k]==1 && key[k]==a){
        res = val[k];
        return true;
      }
      if(used[k]==0){
        break;
      }
      k = (k+1) & mask;
    }
    return false;
  }
}
;
int main(){
  int Nzj9Y0kE;
  wmem = memarr;
  {
    int i;
    int j;
    int k;
    Rand rnd;
    for(i=(0);i<(20);i++){
      rnd.get(2);
    }
    for(i=(0);i<(4);i++){
      for(j=(0);j<(32);j++){
        k = rnd.get(1,62);
        HashMap_ullP_L[i] |= (1ULL << k);
      }
      HashMap_ullP_L[i] |= (1ULL << 0);
      HashMap_ullP_L[i] |= (1ULL << 63);
    }
  }
  int N;
  int K;
  int R1[100000];
  int C1[100000];
  int R2[100000];
  int C2[100000];
  HashMap<pair<int,int>,int> hs;
  static int node;
  static int mm;
  static int a[700000];
  static int b[700000];
  static int c[700000];
  wgraph<int> g;
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int i;
    rd(N);
    rd(K);
    {
      int om7Ebh6q;
      for(om7Ebh6q=(0);om7Ebh6q<(N);om7Ebh6q++){
        rd(R1[om7Ebh6q]);R1[om7Ebh6q] += (-1);
        rd(C1[om7Ebh6q]);C1[om7Ebh6q] += (-1);
        rd(R2[om7Ebh6q]);R2[om7Ebh6q] += (-1);
        rd(C2[om7Ebh6q]);C2[om7Ebh6q] += (-1);
      }
    }
    int x;
    int y1;
    int y2;
    int st;
    int ed;
    int ss;
    int ee;
    int aa;
    int bb;
    int cc;
    dimcomp2 dm(K+1,K+1);
    hs.init(2*N,0);
    for(i=(0);i<(N);i++){
      if(R1[i] == R2[i]){
        x = R1[i];
        y1 =min_L(C1[i], C2[i]);
        y2 =max_L(C1[i], C2[i]);
        auto wbH8AaCb = ((dm(x,y2)));
        auto QBN4sCMC = (( dm(x+1,y2)));
        aa=wbH8AaCb;
        bb=QBN4sCMC;
        hs[{aa,bb}]++;
        auto lmouyaID = ((K-1-x));
        auto Dc_3QP3Y = (( K-1-y2));
        auto myTeyldV = (( K-1-y1));
        x=lmouyaID;
        y1=Dc_3QP3Y;
        y2=myTeyldV;
        auto PON0fmpo = ((dm(x,y2)));
        auto QDGVCdl1 = (( dm(x+1,y2)));
        aa=PON0fmpo;
        bb=QDGVCdl1;
        hs[{aa,bb}]++;
      }
      else{
        x = C1[i];
        y1 =min_L(R1[i], R2[i]);
        y2 =max_L(R1[i], R2[i]);
        auto BRSo37Cn = ((dm(y2,x)));
        auto c6807iQa = (( dm(y2,x+1)));
        aa=BRSo37Cn;
        bb=c6807iQa;
        hs[{aa,bb}]++;
        auto VwTh6lJ3 = ((K-1-x));
        auto ZcmRJqJU = (( K-1-y2));
        auto Jq7Vmy8K = (( K-1-y1));
        x=VwTh6lJ3;
        y1=ZcmRJqJU;
        y2=Jq7Vmy8K;
        auto a3zq_coq = ((dm(y2,x)));
        auto q6vsg2lB = (( dm(y2,x+1)));
        aa=a3zq_coq;
        bb=q6vsg2lB;
        hs[{aa,bb}]++;
      }
    }
    node = (K+1) * (K+1);
    mm = 0;
    st = dm(0, 0);
    ed = dm(K/2, K/2);
    for(i=(0);i<(K+1);i++){
      int j;
      for(j=(0);j<(K+1);j++){
        ss = dm(i,j);
        if(i+1 <= K){
          cc = 0;
          ee = dm(i+1,j);
          hs.exist({ss,ee}, cc);
          arrInsert(mm, mm, a, ss, b, ee, c, cc);
        }
        if(j+1 <= K){
          cc = 0;
          ee = dm(i,j+1);
          hs.exist({ss,ee}, cc);
          arrInsert(mm, mm, a, ss, b, ee, c, cc);
        }
      }
    }
    g.setEdge(node, mm, a, b, c);
    wt_L(N - g.getDistT<int>(st,ed));
    wt_L('\n');
  }
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
// cLay version 20211231-1

// --- original code ---
// //no-unlocked
// int N, K, R1[1d5], C1[], R2[], C2[];
// HashMap<pair<int,int>,int> hs;
// static int node, mm, a[7d5], b[], c[];
// wgraph<int> g;
// 
// REP(rd_int()){
//   rd(N,K,(R1--,C1--,R2--,C2--)(N));
// 
//   int x, y1, y2, st, ed, ss, ee, aa, bb, cc;
//   dimcomp2 dm(K+1,K+1);
// 
//   hs.init(2*N,0);
//   rep(i,N){
//     if(R1[i] == R2[i]){
//       x = R1[i];
//       y1 = min(C1[i], C2[i]);
//       y2 = max(C1[i], C2[i]);
// 
//       (aa, bb) = (dm(x,y2), dm(x+1,y2));
//       hs[{aa,bb}]++;
// 
//       (x, y1, y2) = (K-1-x, K-1-y2, K-1-y1);
//       (aa, bb) = (dm(x,y2), dm(x+1,y2));
//       hs[{aa,bb}]++;
//     } else {
//       x = C1[i];
//       y1 = min(R1[i], R2[i]);
//       y2 = max(R1[i], R2[i]);
// 
//       (aa, bb) = (dm(y2,x), dm(y2,x+1));
//       hs[{aa,bb}]++;
// 
//       (x, y1, y2) = (K-1-x, K-1-y2, K-1-y1);
//       (aa, bb) = (dm(y2,x), dm(y2,x+1));
//       hs[{aa,bb}]++;
//     }
//   }
// 
//   node = (K+1) * (K+1);
//   mm = 0;
//   st = dm(0, 0);
//   ed = dm(K/2, K/2);
// 
//   rep(i,K+1) rep(j,K+1){
//     ss = dm(i,j);
//     if(i+1 <= K){
//       cc = 0;
//       ee = dm(i+1,j);
//       hs.exist({ss,ee}, cc);
//       arrInsert(mm, mm, a, ss, b, ee, c, cc);
//     }
//     if(j+1 <= K){
//       cc = 0;
//       ee = dm(i,j+1);
//       hs.exist({ss,ee}, cc);
//       arrInsert(mm, mm, a, ss, b, ee, c, cc);
//     }
//   }
//   g.setEdge(node, mm, a, b, c);
//   wt(N - g.getDistT<int>(st,ed));
// }