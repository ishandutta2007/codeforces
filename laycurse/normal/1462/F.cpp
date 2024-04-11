#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class T> int coordcomp_L(int n, T arr[], int res[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int>*r;
  walloc1d(&r, n, &mem);
  for(i=(0);i<(n);i++){
    r[i].first = arr[i];
    r[i].second = i;
  }
  sort(r, r+n);
  if(res != NULL){
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      res[r[i].second] = k;
    }
  }
  else{
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      arr[r[i].second] = k;
    }
  }
  return k+1;
}
template<class T> int coordcomp_L(int n1, T arr1[], int n2, T arr2[], int res1[] = NULL, int res2[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int>*r;
  walloc1d(&r, n1+n2, &mem);
  for(i=(0);i<(n1);i++){
    r[i].first = arr1[i];
    r[i].second = i;
  }
  for(i=(0);i<(n2);i++){
    r[n1+i].first = arr2[i];
    r[n1+i].second = n1+i;
  }
  sort(r, r+n1+n2);
  for(i=(0);i<(n1+n2);i++){
    if(i && r[i].first != r[i-1].first){
      k++;
    }
    if(r[i].second < n1){
      if(res1!=NULL){
        res1[r[i].second] = k;
      }
      else{
        arr1[r[i].second] = k;
      }
    }
    else{
      if(res2!=NULL){
        res2[r[i].second-n1] = k;
      }
      else{
        arr2[r[i].second-n1] = k;
      }
    }
  }
  return k+1;
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
      dhist_mem = len;
    }
    for(i=(0);i<(len);i++){
      dhist[i] = 0;
    }
    for(i=(0);i<(n);i++){
      dhist[d[i] - dhist_mn]++;
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
    dhist = NULL;
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
int L[200000];
int R[200000];
Arr1d<int> tl;
Arr1d<int> tr;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int sz;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int res = 1073709056;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(L[cTE1_r3A]);
        rd(R[cTE1_r3A]);
      }
    }
    sz =coordcomp_L(N, L, N, R);
    tl.setN(sz);
    tr.setN(sz);
    for(i=(0);i<(sz);i++){
      tl[i] = tr[i] = 0;
    }
    for(i=(0);i<(N);i++){
      tl[L[i]]++;
      tr[R[i]]++;
    }
    for(i=(0);i<(N);i++){
      chmin(res, tr.getSum(0, L[i]-1) + tl.getSum(R[i]+1, sz-1));
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20201206-1

// --- original code ---
// //no-unlocked
// int N, L[2d5], R[2d5];
// Arr1d<int> tl, tr;
// {
//   int sz;
//   REP(rd_int()){
//     int res = int_inf;
//     rd(N,(L,R)(N));
//     sz = coordcomp(N, L, N, R);
//     tl.setN(sz);
//     tr.setN(sz);
//     rep(i,sz) tl[i] = tr[i] = 0;
//     rep(i,N) tl[L[i]]++, tr[R[i]]++;
//     rep(i,N) res <?= tr.getSum(0, L[i]-1) + tl.getSum(R[i]+1, sz-1);
//     wt(res);
//   }
// }