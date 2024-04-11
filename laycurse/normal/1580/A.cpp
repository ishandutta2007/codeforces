#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
  void reset(){
    set_cumulative_sum = 0;
  }
  void constructor(){
    n = mem = 0;
    d = NULL;
    set_cumulative_sum = 0;
    cumulative_sum_mem = 0;
    cumulative_sum = NULL;
  }
  void destructor(){
    delete[] d;
    d = NULL;
    mem = n = 0;
    set_cumulative_sum = 0;
    cumulative_sum_mem = 0;
    delete[] cumulative_sum;
    cumulative_sum = NULL;
  }
  void constructor(int nn){
    constructor();
    malloc(nn);
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
  void setN(int nn, T val){
    int i;
    reset();
    memory_expand(nn);
    n = nn;
    for(i=(0);i<(n);i++){
      d[i] = val;
    }
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
template<class T> struct Arr2d{
  int n1;
  int n2;
  int mem1;
  int mem2;
  T**d;
  T* operator[](int a){
    return d[a];
  }
  int set_cumulative_sum;
  int cumulative_sum_mem1;
  int cumulative_sum_mem2;
  T**cumulative_sum;
  void setSum(void){
    int i;
    int j;
    set_cumulative_sum = 1;
    if(cumulative_sum_mem1 < n1+1 || cumulative_sum_mem2 < n2+1){
      for(i=(0);i<(cumulative_sum_mem1);i++){
        delete[] cumulative_sum[i];
      }
      delete[] cumulative_sum;
      cumulative_sum_mem1 = n1+1;
      cumulative_sum_mem2 = n2+1;
      cumulative_sum = new T*[cumulative_sum_mem1];
      for(i=(0);i<(cumulative_sum_mem1);i++){
        cumulative_sum[i] = new T[cumulative_sum_mem2];
      }
    }
    for(i=(0);i<(n1+1);i++){
      cumulative_sum[i][0] = 0;
    }
    for(i=(0);i<(n2+1);i++){
      cumulative_sum[0][i] = 0;
    }
    for(i=(0);i<(n1);i++){
      for(j=(0);j<(n2);j++){
        cumulative_sum[i+1][j+1] = cumulative_sum[i+1][j] + cumulative_sum[i][j+1] - cumulative_sum[i][j] + d[i][j];
      }
    }
  }
  T getSum(int r1, int c1, int r2, int c2){
    if(!set_cumulative_sum){
      setSum();
    }
    return cumulative_sum[r2+1][c2+1] - cumulative_sum[r2+1][c1] - cumulative_sum[r1][c2+1] + cumulative_sum[r1][c1];
  }
  T getSumBorder(int r1, int c1, int r2, int c2){
    T res;
    if(!set_cumulative_sum){
      setSum();
    }
    res = cumulative_sum[r2+1][c2+1] - cumulative_sum[r2+1][c1] - cumulative_sum[r1][c2+1] + cumulative_sum[r1][c1];
    if(r2 - r1 > 1 && c2 - c1 > 1){
      res -= cumulative_sum[r2][c2] - cumulative_sum[r2][c1+1] - cumulative_sum[r1+1][c2] + cumulative_sum[r1+1][c1+1];
    }
    return res;
  }
  void reset(){
    set_cumulative_sum = 0;
  }
  void constructor(){
    n1 = n2 = mem1 = mem2 = 0;
    d = NULL;
    set_cumulative_sum = 0;
    cumulative_sum_mem1 = cumulative_sum_mem2 = 0;
    cumulative_sum = NULL;
  }
  void destructor(){
    int i;
    if(d != NULL){
      for(i=(0);i<(mem1);i++){
        delete[] d[i];
      }
      delete[] d;
    }
    d = NULL;
    mem1 = mem2 = n1 = n2 = 0;
    set_cumulative_sum = 0;
    if(cumulative_sum != NULL){
      for(i=(0);i<(cumulative_sum_mem1);i++){
        delete[] cumulative_sum[i];
      }
      delete[] cumulative_sum;
    }
    cumulative_sum_mem1 = cumulative_sum_mem2 = 0;
    cumulative_sum = NULL;
  }
  void constructor(int nn1, int nn2){
    constructor();
    malloc(nn1, nn2);
  }
  void memory_expand(int nn1, int nn2){
    int i;
    if(mem1 < nn1 || mem2 < nn2){
      if(d != NULL){
        for(i=(0);i<(mem1);i++){
          delete[] d[i];
        }
        delete[] d;
      }
      d = new T*[nn1];
      for(i=(0);i<(nn1);i++){
        d[i] = new T[nn2];
      }
      mem1 = nn1;
      mem2 = nn2;
    }
  }
  void malloc(int nn1, int nn2){
    reset();
    memory_expand(nn1, nn2);
    n1 = nn1;
    n2 = nn2;
  }
  void setN(int nn1, int nn2){
    reset();
    memory_expand(nn1, nn2);
    n1 = nn1;
    n2 = nn2;
  }
  void setN(int nn1, int nn2, T val){
    int i;
    int j;
    reset();
    memory_expand(nn1, nn2);
    n1 = nn1;
    n2 = nn2;
    for(i=(0);i<(n1);i++){
      for(j=(0);j<(n2);j++){
        d[i][j] = val;
      }
    }
  }
  void set(vector<vector<T>> &a){
    int i;
    int j;
    int nn1 = a.size();
    int nn2 = a[0].size();
    setN(nn1, nn2);
    for(i=(0);i<(nn1);i++){
      for(j=(0);j<(nn2);j++){
        d[i][j] = a[i][j];
      }
    }
  }
  void set(int nn1, int nn2, T **a){
    int i;
    int j;
    setN(nn1, nn2);
    for(i=(0);i<(nn1);i++){
      for(j=(0);j<(nn2);j++){
        d[i][j] = a[i][j];
      }
    }
  }
  void free(){
    destructor();
  }
  Arr2d(){
    constructor();
  }
  Arr2d(int nn1, int nn2){
    constructor(nn1, nn2);
  }
  ~Arr2d(){
    destructor();
  }
}
;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int X;
  int Y;
  char buf[400][402];
  Arr2d<int> A;
  Arr1d<int> v;
  Arr1d<int> w;
  int dp[402];
  int ad;
  int mn;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, x1;
    int res = 1073709056;
    rd(X);
    rd(Y);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(X);cTE1_r3A++){
        rd(buf[cTE1_r3A]);
      }
    }
    A.setN(X,Y);
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        A[i][j] = buf[i][j] - '0';
      }
    }
    for(x1=(0);x1<(X);x1++){
      int x2;
      for(x2=(x1+4);x2<(X);x2++){
        v.setN(Y);
        w.setN(Y);
        for(i=(0);i<(Y);i++){
          v[i] = A.getSum(x1+1,i,x2-1,i) + (1 - A[x1][i]) + (1 - A[x2][i]);
        }
        for(i=(0);i<(Y);i++){
          w[i] = x2 - x1 - 1 - A.getSum(x1+1,i,x2-1,i);
        }
        for(i=(0);i<(Y);i++){
          dp[i] = w[i] - v.getSum(0,i);
          if(i){
            chmin(dp[i], dp[i-1]);
          }
          if(i >= 3){
            chmin(res, w[i] + v.getSum(0,i-1) + dp[i-3]);
          }
        }
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int X, Y; char buf[400][402];
// Arr2d<int> A;
// Arr1d<int> v, w;
// int dp[402], ad, mn;
// REP(rd_int()){
//   int res = int_inf;
//   rd(X,Y,buf(X));
//   A.setN(X,Y);
//   rep(i,X) rep(j,Y) A[i][j] = buf[i][j] - '0';
// 
//   rep(x1,X) rep(x2,x1+4,X){
//     v.setN(Y);
//     w.setN(Y);
//     rep(i,Y) v[i] = A.getSum(x1+1,i,x2-1,i) + (1 - A[x1][i]) + (1 - A[x2][i]);
//     rep(i,Y) w[i] = x2 - x1 - 1 - A.getSum(x1+1,i,x2-1,i);
//     rep(i,Y){
//       dp[i] = w[i] - v.getSum(0,i);
//       if(i) dp[i] <?= dp[i-1];
//       if(i >= 3) res <?= w[i] + v.getSum(0,i-1) + dp[i-3];
//     }
//   }
//   wt(res);
// }