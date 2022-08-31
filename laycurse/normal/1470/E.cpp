#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
template<class T> struct Arr1d{
  int n;
  int mem;
  T*d;
  T& operator[](int a){
    return d[a];
  }
  void sort(){
    reset();
    std::sort(d, d+n);
  }
  int set_cumulative_sum;
  int cumulative_sum_mem;
  T*cumulative_sum;
  void setSum(void){
    int i;
    set_cumulative_sum = 1;
    if(cumulative_sum_mem < n+1){
      delete[] cumulative_sum;
      cumulative_sum = new T[n+1];
      cumulative_sum_mem = n+1;
    }
    cumulative_sum[0] = 0;
    for(i=(0);i<(n);i++){
      cumulative_sum[i+1] = cumulative_sum[i] + d[i];
    }
  }
  T getSum(int i, int j){
    if(set_cumulative_sum==0){
      setSum();
    }
    return cumulative_sum[j+1] - cumulative_sum[i];
  }
  int set_const_len_left;
  int const_len_left_mem;
  int*const_len_left;
  void setConstLenLeft(void){
    int i;
    set_const_len_left = 1;
    if(const_len_left_mem < n){
      delete[] const_len_left;
      const_len_left = new int[n];
      const_len_left_mem = n;
    }
    for(i=(0);i<(n);i++){
      const_len_left[i] = 1;
    }
    for(i=(1);i<(n);i++){
      if(d[i]==d[i-1]){
        const_len_left[i] = const_len_left[i-1] + 1;
      }
    }
  }
  int ConstLenLeft(int st, T val){
    if(!set_const_len_left){
      setConstLenLeft();
    }
    if(val != d[st]){
      return 0;
    }
    return const_len_left[st];
  }
  int ConstLenLeft(int st){
    if(!set_const_len_left){
      setConstLenLeft();
    }
    return const_len_left[st];
  }
  int ConstLenLeftCyclic(int st, T val){
    if(!set_const_len_left){
      setConstLenLeft();
    }
    st %= n;
    if(st < 0){
      st += n;
    }
    if(val != d[st]){
      return 0;
    }
    if(const_len_left[st] != st+1 || d[st] != d[n-1]){
      return const_len_left[st];
    }
    if(const_len_left[n-1] == n){
      return 1073709056;
    }
    return const_len_left[st] + const_len_left[n-1];
  }
  int ConstLenLeftCyclic(int st){
    if(!set_const_len_left){
      setConstLenLeft();
    }
    st %= n;
    if(st < 0){
      st += n;
    }
    if(const_len_left[st] != st+1 || d[st] != d[n-1]){
      return const_len_left[st];
    }
    if(const_len_left[n-1] == n){
      return 1073709056;
    }
    return const_len_left[st] + const_len_left[n-1];
  }
  int set_const_len_right;
  int const_len_right_mem;
  int*const_len_right;
  void setConstLenRight(void){
    int i;
    set_const_len_right = 1;
    if(const_len_right_mem < n){
      delete[] const_len_right;
      const_len_right = new int[n];
      const_len_right_mem = n;
    }
    for(i=(0);i<(n);i++){
      const_len_right[i] = 1;
    }
    for(i=(n-1)-1;i>=(0);i--){
      if(d[i]==d[i+1]){
        const_len_right[i] = const_len_right[i+1] + 1;
      }
    }
  }
  int ConstLenRight(int st, T val){
    if(!set_const_len_right){
      setConstLenRight();
    }
    if(val != d[st]){
      return 0;
    }
    return const_len_right[st];
  }
  int ConstLenRight(int st){
    if(!set_const_len_right){
      setConstLenRight();
    }
    return const_len_right[st];
  }
  int ConstLenRightCyclic(int st, T val){
    if(!set_const_len_right){
      setConstLenRight();
    }
    if(val != d[st]){
      return 0;
    }
    st %= n;
    if(st < 0){
      st += n;
    }
    if(const_len_right[st] != n-st || d[st] != d[0]){
      return const_len_right[st];
    }
    if(const_len_right[0] == n){
      return 1073709056;
    }
    return const_len_right[st] + const_len_right[0];
  }
  int ConstLenRightCyclic(int st){
    if(!set_const_len_right){
      setConstLenRight();
    }
    st %= n;
    if(st < 0){
      st += n;
    }
    if(const_len_right[st] != n-st || d[st] != d[0]){
      return const_len_right[st];
    }
    if(const_len_right[0] == n){
      return 1073709056;
    }
    return const_len_right[st] + const_len_right[0];
  }
  int set_dhist;
  int dhist_mem;
  int*dhist;
  int*dhists;
  T dhist_mn;
  T dhist_mx;
  void setDHist(void){
    int i;
    int len;
    set_dhist = 1;
    if(n==0){
      return;
    }
    dhist_mn = dhist_mx = d[0];
    for(i=(1);i<(n);i++){
      if(dhist_mn > d[i]){
        dhist_mn = d[i];
      }
      if(dhist_mx < d[i]){
        dhist_mx = d[i];
      }
    }
    len = dhist_mx - dhist_mn + 1;
    if(dhist_mem < len){
      delete[] dhist;
      dhist = new int[len];
      delete[] dhists;
      dhists = new int[len+1];
      dhist_mem = len;
    }
    for(i=(0);i<(len);i++){
      dhist[i] = 0;
    }
    for(i=(0);i<(n);i++){
      dhist[d[i] - dhist_mn]++;
    }
    dhists[0] = 0;
    for(i=(0);i<(len);i++){
      dhists[i+1] = dhists[i] + dhist[i];
    }
  }
  int dHist(T x){
    if(set_dhist==0){
      setDHist();
    }
    if(n == 0 || x < dhist_mn || x > dhist_mx){
      return 0;
    }
    return dhist[x - dhist_mn];
  }
  int dHist(T x, T y){
    if(set_dhist==0){
      setDHist();
    }
    if(x < dhist_mn){
      x = dhist_mn;
    }
    if(y > dhist_mx){
      y = dhist_mx;
    }
    if(n == 0 || x > y){
      return 0;
    }
    return dhists[y-dhist_mn+1] - dhists[x-dhist_mn];
  }
  int set_shist;
  int shist_mem;
  T*shist;
  void setSHist(void){
    int i;
    set_shist = 1;
    if(shist_mem < n){
      delete[] shist;
      shist = new T[n];
      shist_mem = n;
    }
    for(i=(0);i<(n);i++){
      shist[i] = d[i];
    }
    std::sort(shist, shist + n);
  }
  int sHist(T x){
    if(set_shist==0){
      setSHist();
    }
    auto r = equal_range(shist, shist+n, x);
    return r.second - r.first;
  }
  int sHist(T x, T y){
    if(set_shist==0){
      setSHist();
    }
    return upper_bound(shist, shist+n, y) - lower_bound(shist, shist+n, x);
  }
  int set_prevLE;
  int prevLE_mem;
  int*prevLE;
  int setPrevLE(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    set_prevLE = 1;
    if(prevLE_mem < n){
      delete[] prevLE;
      prevLE = new int[n];
      prevLE_mem = n;
    }
    walloc1d(&st, n, &mem);
    for(i=(0);i<(n);i++){
      while(s && d[st[s-1]] > d[i]){
        s--;
      }
      if(s==0){
        prevLE[i] = -1;
      }
      else{
        prevLE[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int PrevLE(int i){
    if(set_prevLE==0){
      setPrevLE();
    }
    return prevLE[i];
  }
  int set_prevLT;
  int prevLT_mem;
  int*prevLT;
  int setPrevLT(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    set_prevLT = 1;
    if(prevLT_mem < n){
      delete[] prevLT;
      prevLT = new int[n];
      prevLT_mem = n;
    }
    walloc1d(&st, n, &mem);
    for(i=(0);i<(n);i++){
      while(s && d[st[s-1]] >= d[i]){
        s--;
      }
      if(s==0){
        prevLT[i] = -1;
      }
      else{
        prevLT[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int PrevLT(int i){
    if(set_prevLT==0){
      setPrevLT();
    }
    return prevLT[i];
  }
  int set_prevGE;
  int prevGE_mem;
  int*prevGE;
  int setPrevGE(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    set_prevGE = 1;
    if(prevGE_mem < n){
      delete[] prevGE;
      prevGE = new int[n];
      prevGE_mem = n;
    }
    walloc1d(&st, n, &mem);
    for(i=(0);i<(n);i++){
      while(s && d[st[s-1]] < d[i]){
        s--;
      }
      if(s==0){
        prevGE[i] = -1;
      }
      else{
        prevGE[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int PrevGE(int i){
    if(set_prevGE==0){
      setPrevGE();
    }
    return prevGE[i];
  }
  int set_prevGT;
  int prevGT_mem;
  int*prevGT;
  int setPrevGT(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    set_prevGT = 1;
    if(prevGT_mem < n){
      delete[] prevGT;
      prevGT = new int[n];
      prevGT_mem = n;
    }
    walloc1d(&st, n, &mem);
    for(i=(0);i<(n);i++){
      while(s && d[st[s-1]] <= d[i]){
        s--;
      }
      if(s==0){
        prevGT[i] = -1;
      }
      else{
        prevGT[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int PrevGT(int i){
    if(set_prevGT==0){
      setPrevGT();
    }
    return prevGT[i];
  }
  int set_nextLE;
  int nextLE_mem;
  int*nextLE;
  int setNextLE(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    set_nextLE = 1;
    if(nextLE_mem < n){
      delete[] nextLE;
      nextLE = new int[n];
      nextLE_mem = n;
    }
    walloc1d(&st, n, &mem);
    for(i=(n)-1;i>=(0);i--){
      while(s && d[st[s-1]] > d[i]){
        s--;
      }
      if(s==0){
        nextLE[i] = n;
      }
      else{
        nextLE[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int NextLE(int i){
    if(set_nextLE==0){
      setNextLE();
    }
    return nextLE[i];
  }
  int set_nextLT;
  int nextLT_mem;
  int*nextLT;
  int setNextLT(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    set_nextLT = 1;
    if(nextLT_mem < n){
      delete[] nextLT;
      nextLT = new int[n];
      nextLT_mem = n;
    }
    walloc1d(&st, n, &mem);
    for(i=(n)-1;i>=(0);i--){
      while(s && d[st[s-1]] >= d[i]){
        s--;
      }
      if(s==0){
        nextLT[i] = n;
      }
      else{
        nextLT[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int NextLT(int i){
    if(set_nextLT==0){
      setNextLT();
    }
    return nextLT[i];
  }
  int set_nextGE;
  int nextGE_mem;
  int*nextGE;
  int setNextGE(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    set_nextGE = 1;
    if(nextGE_mem < n){
      delete[] nextGE;
      nextGE = new int[n];
      nextGE_mem = n;
    }
    walloc1d(&st, n, &mem);
    for(i=(n)-1;i>=(0);i--){
      while(s && d[st[s-1]] < d[i]){
        s--;
      }
      if(s==0){
        nextGE[i] = n;
      }
      else{
        nextGE[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int NextGE(int i){
    if(set_nextGE==0){
      setNextGE();
    }
    return nextGE[i];
  }
  int set_nextGT;
  int nextGT_mem;
  int*nextGT;
  int setNextGT(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    set_nextGT = 1;
    if(nextGT_mem < n){
      delete[] nextGT;
      nextGT = new int[n];
      nextGT_mem = n;
    }
    walloc1d(&st, n, &mem);
    for(i=(n)-1;i>=(0);i--){
      while(s && d[st[s-1]] <= d[i]){
        s--;
      }
      if(s==0){
        nextGT[i] = n;
      }
      else{
        nextGT[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int NextGT(int i){
    if(set_nextGT==0){
      setNextGT();
    }
    return nextGT[i];
  }
  void reset(){
    set_cumulative_sum = 0;
    set_const_len_left = 0;
    set_const_len_right = 0;
    set_dhist = 0;
    set_prevLE = set_prevLT = set_prevGE = set_prevGT = 0;
    set_nextLE = set_nextLT = set_nextGE = set_nextGT = 0;
  }
  void memory_expand(int nn){
    if(mem < nn){
      delete[] d;
      d = new T[nn];
      mem = nn;
    }
  }
  void malloc(int nn){
    reset();
    memory_expand(nn);
    n = nn;
  }
  void setN(int nn){
    reset();
    memory_expand(nn);
    n = nn;
  }
  void set(vector<T> &a){
    int i;
    int nn = a.size();
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  void set(int nn, T a[]){
    int i;
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  void free(){
    destructor();
  }
  void constructor(){
    n = mem = 0;
    d = NULL;
    set_cumulative_sum = 0;
    cumulative_sum_mem = 0;
    cumulative_sum = NULL;
    set_const_len_left = 0;
    const_len_left_mem = 0;
    const_len_left = NULL;
    set_const_len_right = 0;
    const_len_right_mem = 0;
    const_len_right = NULL;
    set_dhist = 0;
    dhist_mem = 0;
    dhist = NULL;
    dhists = NULL;
    set_shist = 0;
    shist_mem = 0;
    shist = NULL;
    set_prevLE = set_prevLT = set_prevGE = set_prevGT = 0;
    prevLE_mem = prevLT_mem = prevGE_mem = prevGT_mem = 0;
    prevLE = prevLT = prevGE = prevGT = NULL;
    set_nextLE = set_nextLT = set_nextGE = set_nextGT = 0;
    nextLE_mem = nextLT_mem = nextGE_mem = nextGT_mem = 0;
    nextLE = nextLT = nextGE = nextGT = NULL;
  }
  void constructor(int nn){
    constructor();
    malloc(nn);
  }
  void destructor(){
    delete[] d;
    d = NULL;
    mem = n = 0;
    set_cumulative_sum = 0;
    cumulative_sum_mem = 0;
    delete[] cumulative_sum;
    cumulative_sum = NULL;
    set_const_len_left = 0;
    const_len_left_mem = 0;
    delete[] const_len_left;
    const_len_left = NULL;
    set_const_len_right = 0;
    const_len_right_mem = 0;
    delete[] const_len_right;
    const_len_right = NULL;
    set_dhist = 0;
    dhist_mem = 0;
    delete[] dhist;
    delete[] dhists;
    dhist = NULL;
    set_shist = 0;
    shist_mem = 0;
    delete[] shist;
    shist = NULL;
    set_prevLE = set_prevLT = set_prevGE = set_prevGT = 0;
    prevLE_mem = prevLT_mem = prevGE_mem = prevGT_mem = 0;
    delete[] prevLE;
    delete[] prevLT;
    delete[] prevGE;
    delete[] prevGT;
    prevLE = prevLT = prevGE = prevGT = NULL;
    set_nextLE = set_nextLT = set_nextGE = set_nextGT = 0;
    nextLE_mem = nextLT_mem = nextGE_mem = nextGT_mem = 0;
    delete[] nextLE;
    delete[] nextLT;
    delete[] nextGE;
    delete[] nextGT;
    nextLE = nextLT = nextGE = nextGT = NULL;
  }
  Arr1d(){
    constructor();
  }
  Arr1d(int nn){
    constructor(nn);
  }
  ~Arr1d(){
    destructor();
  }
}
;
int N;
int C;
int Q;
int A[30000];
int X;
long long Y;
long long cnt[5][30000+2];
int sz;
int lis[5];
int ind[5];
int usz[30000+2];
int ulis[30000+2][5];
int dsz[30000+2];
int dlis[30000+2][5];
Arr1d<__int128_t> skip[5];
int main(){
  int t_ynMSdg;
  wmem = memarr;
  int i;
  int j;
  int k;
  int c;
  for(i=(0);i<(5);i++){
    cnt[i][0] = 1;
  }
  for(i=(0);i<(5);i++){
    for(k=(0);k<(30000);k++){
      for(j=(0);j<(min_L(k, i)+1);j++){
        cnt[i][k+1] += cnt[i-j][k-j];
        if(cnt[i][k+1] > 2000000000000000000LL){
          cnt[i][k+1] = 2000000000000000000LL;
        }
      }
    }
  }
  int KrdatlYV = rd_int();
  for(t_ynMSdg=(0);t_ynMSdg<(KrdatlYV);t_ynMSdg++){
    int gEg5UqEA;
    rd(N);
    rd(C);
    rd(Q);
    {
      int a2conNHc;
      for(a2conNHc=(0);a2conNHc<(N);a2conNHc++){
        rd(A[a2conNHc]);
      }
    }
    for(k=(0);k<(N);k++){
      sz = 0;
      for(i=(0);i<(C+1);i++){
        if(k+i < N){
          arrInsert(sz, sz, ind, i, lis, A[k+i]);
        }
      }
      sortA_L(sz, lis, ind);
      j = usz[k] = dsz[k] = 0;
      for(i=(0);i<(sz);i++){
        if(ind[i] == 0){
          j++;
          continue;
        }
        if(j==0){
          ulis[k][usz[k]++] = ind[i];
        }
        if(j==1){
          dlis[k][dsz[k]++] = ind[i];
        }
      }
    }
    for(c=(0);c<(C+1);c++){
      skip[c].setN(N);
      for(k=(0);k<(N);k++){
        skip[c][k] = 0;
        for(i=(0);i<(usz[k]);i++){
          if(c >= ulis[k][i]){
            skip[c][k] += cnt[c-ulis[k][i]][N-k-ulis[k][i]-1];
          }
        }
      }
    }
    for(gEg5UqEA=(0);gEg5UqEA<(Q);gEg5UqEA++){
      rd(X);X += (-1);
      rd(Y);Y += (-1);
      if(Y >= cnt[C][N]){
        wt_L(-1);
        wt_L('\n');
        continue;
      }
      c = C;
      for(k=(0);k<(N);k++){
        int X9Iss0pP;
        int szDqbNYU;
        int ytthggxT;
        X9Iss0pP = k-1;
        szDqbNYU = N-1;
        while(X9Iss0pP < szDqbNYU){
          if((X9Iss0pP + szDqbNYU)%2==0){
            ytthggxT = (X9Iss0pP + szDqbNYU) / 2;
          }
          else{
            ytthggxT = (X9Iss0pP + szDqbNYU + 1) / 2;
          }
          if(skip[c].getSum(k,ytthggxT) <= Y  &&  Y < skip[c].getSum(k,ytthggxT) + cnt[c][N-ytthggxT-1]){
            X9Iss0pP = ytthggxT;
          }
          else{
            szDqbNYU = ytthggxT - 1;
          }
        }
        i =szDqbNYU+ 1;
        if(X < i){
          wt_L(A[X]);
          wt_L('\n');
          break;
        }
        Y -= skip[c].getSum(k, i-1);
        k = i;
        for(i=(0);i<(usz[k]);i++){
          if(c >= ulis[k][i]){
            if(Y < cnt[c-ulis[k][i]][N-k-ulis[k][i]-1]){
              if(X <= k + ulis[k][i]){
                wt_L(A[k+ulis[k][i]-(X-k)]);
                wt_L('\n');
                goto aTqQ6rt8;
              }
              c -= ulis[k][i];
              k += ulis[k][i];
              goto zT28qSmp;
            }
            else{
              Y -= cnt[c-ulis[k][i]][N-k-ulis[k][i]-1];
            }
          }
        }
        if(Y < cnt[c][N-k-1]){
          if(X == k){
            wt_L(A[k]);
            wt_L('\n');
            break;
          }
          continue;
        }
        else{
          Y -= cnt[c][N-k-1];
        }
        for(i=(0);i<(dsz[k]);i++){
          if(c >= dlis[k][i]){
            if(Y < cnt[c-dlis[k][i]][N-k-dlis[k][i]-1]){
              if(X <= k + dlis[k][i]){
                wt_L(A[k+dlis[k][i]-(X-k)]);
                wt_L('\n');
                goto aTqQ6rt8;
              }
              c -= dlis[k][i];
              k += dlis[k][i];
              goto zT28qSmp;
            }
            else{
              Y -= cnt[c-dlis[k][i]][N-k-dlis[k][i]-1];
            }
          }
        }
        zT28qSmp:;
      }
      aTqQ6rt8:;
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// int N, C, Q, A[3d4], X; ll Y;
// ll cnt[5][3d4+2];
// int sz, lis[5], ind[5];
// int usz[3d4+2], ulis[3d4+2][5];
// int dsz[3d4+2], dlis[3d4+2][5];
// Arr1d<__int128_t> skip[5];
// {
//   int i, j, k, c;
//   rep(i,5) cnt[i][0] = 1;
//   rep(i,5) rep(k,3d4) rep(j,min(k,i)+1){
//     cnt[i][k+1] += cnt[i-j][k-j];
//     if(cnt[i][k+1] > 2d18) cnt[i][k+1] = 2d18;
//   }
//   REP(rd_int()){
//     rd(N,C,Q,A(N));
// 
//     rep(k,N){
//       sz = 0;
//       rep(i,C+1) if(k+i < N) arrInsert(sz, sz, ind, i, lis, A[k+i]);
//       sortA(sz, lis, ind);
//       j = usz[k] = dsz[k] = 0;
//       rep(i,sz){
//         if(ind[i] == 0) j++, continue;
//         if(j==0) ulis[k][usz[k]++] = ind[i];
//         if(j==1) dlis[k][dsz[k]++] = ind[i];
//       }
//     }
// 
//     rep(c,C+1){
//       skip[c].setN(N);
//       rep(k,N){
//         skip[c][k] = 0;
//         rep(i,usz[k]) if(c >= ulis[k][i]) skip[c][k] += cnt[c-ulis[k][i]][N-k-ulis[k][i]-1];
//       }
//     }
// 
//     rep(Q){
//       rd(X--, Y--);
//       if(Y >= cnt[C][N]) wt(-1), continue;
//       c = C;
//       rep(k,N){
//         i = bsearch_max[int,i,k-1,N-1](skip[c].getSum(k,i) <= Y < skip[c].getSum(k,i) + cnt[c][N-i-1])+ 1;
//         if(X < i) wt(A[X]), break;
//         Y -= skip[c].getSum(k, i-1);
//         k = i;
// 
//         rep(i,usz[k]) if(c >= ulis[k][i]){
//           if(Y < cnt[c-ulis[k][i]][N-k-ulis[k][i]-1]){
//             if(X <= k + ulis[k][i]) wt(A[k+ulis[k][i]-(X-k)]), break_break;
//             c -= ulis[k][i];
//             k += ulis[k][i];
//             break_continue;
//           } else {
//             Y -= cnt[c-ulis[k][i]][N-k-ulis[k][i]-1];
//           }
//         }
//         if(Y < cnt[c][N-k-1]){
//           if(X == k) wt(A[k]), break;
//           continue;
//         } else {
//           Y -= cnt[c][N-k-1];
//         }
//         rep(i,dsz[k]) if(c >= dlis[k][i]){
//           if(Y < cnt[c-dlis[k][i]][N-k-dlis[k][i]-1]){
//             if(X <= k + dlis[k][i]) wt(A[k+dlis[k][i]-(X-k)]), break_break;
//             c -= dlis[k][i];
//             k += dlis[k][i];
//             break_continue;
//           } else {
//             Y -= cnt[c-dlis[k][i]][N-k-dlis[k][i]-1];
//           }
//         }
//       }
//     }
//   }
// }