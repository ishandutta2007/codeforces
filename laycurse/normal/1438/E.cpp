#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
  void reset(){
    set_cumulative_sum = 0;
    set_const_len_left = 0;
    set_const_len_right = 0;
    set_dhist = 0;
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
Arr1d<long long> A;
int main(){
  int i;
  long long res = 0;
  rd(N);
  A.malloc(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i+2);j<(N);j++){
      if(A.getSum(i+1,j-1) > 2*A[i]){
        break;
      }
      if(A[i] <= A[j]){
        continue;
      }
      if((A[i]^A[j]) == A.getSum(i+1,j-1)){
        res++;
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i-1)-1;j>=(0);j--){
      if(A.getSum(j+1,i-1) > 2*A[i]){
        break;
      }
      if(A[i] < A[j]){
        continue;
      }
      if((A[i]^A[j]) == A.getSum(j+1,i-1)){
        res++;
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20201115-1

// --- original code ---
// //no-unlocked
// int N; Arr1d<ll> A;
// {
//   ll res = 0;
//   rd(N,A(N));
//   rep(i,N) rep(j,i+2,N){
//     if(A.getSum(i+1,j-1) > 2*A[i]) break;
//     if(A[i] <= A[j]) continue;
//     if((A[i]^A[j]) == A.getSum(i+1,j-1)) res++;
//   }
//   rep(i,N) rrep(j,0,i-1){
//     if(A.getSum(j+1,i-1) > 2*A[i]) break;
//     if(A[i] < A[j]) continue;
//     if((A[i]^A[j]) == A.getSum(j+1,i-1)) res++;
//   }
//   wt(res);
// }