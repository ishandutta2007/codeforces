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
unsigned long long HashMap_ullP_L[4];
template<class KEY, class VAL> struct HashMap{
  char*used;
  KEY*key;
  VAL*val;
  int mem;
  int n;
  int mask;
  HashMap(){
    mem = 0;
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
int N[4];
int A[4][200000];
int M;
HashMap<pair<int,int>,int> E;
int dp[200000];
int ind[200000];
int nx[200000];
int main(){
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
  int i;
  int j;
  int k;
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(4);Lj4PdHRW++){
      rd(N[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(4);i++){
    {
      int RZTsC2BF;
      for(RZTsC2BF=(0);RZTsC2BF<(N[i]);RZTsC2BF++){
        rd(A[i][RZTsC2BF]);
      }
    }
  }
  for(i=(0);i<(N[0]);i++){
    dp[i] = A[0][i];
    ind[i] = i;
  }
  sortA_L(N[0], dp, ind);
  for(k=(1);k<(4);k++){
    int tU__gIr_;
    rd(M);
    E.init(M);
    for(tU__gIr_=(0);tU__gIr_<(M);tU__gIr_++){
      rd(i);i += (-1);
      rd(j);j += (-1);
      E[{i,j}] = 1;
    }
    for(i=(0);i<(N[k]);i++){
      nx[i] = 1073709056;
      for(j=(0);j<(N[k-1]);j++){
        if(!E.exist({ind[j],i})){
          chmin(nx[i], A[k][i] + dp[j]);
          break;
        }
      }
    }
    for(i=(0);i<(N[k]);i++){
      dp[i] = nx[i];
      ind[i] = i;
    }
    sortA_L(N[k], dp, ind);
  }
  if(dp[0]==1073709056){
    wt_L(-1);
    wt_L('\n');
  }
  else{
    wt_L(dp[0]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 2]

// --- original code ---
// //no-unlocked
// int N[4], A[4][2d5];
// int M; HashMap<pair<int,int>,int> E;
// int dp[2d5], ind[2d5], nx[2d5];
// {
//   int i, j, k;
//   rd(N(4));
//   rep(i,4) rd(A[i](N[i]));
// 
//   rep(i,N[0]) dp[i] = A[0][i], ind[i] = i;
//   sortA(N[0], dp, ind);
// 
//   rep(k,1,4){
//     rd(M);
//     E.init(M);
//     rep(M){
//       rd(i--, j--);
//       E[{i,j}] = 1;
//     }
// 
//     rep(i,N[k]){
//       nx[i] = int_inf;
//       rep(j,N[k-1]) if(!E.exist({ind[j],i})){
//         nx[i] <?= A[k][i] + dp[j];
//         break;
//       }
//     }
// 
//     rep(i,N[k]) dp[i] = nx[i], ind[i] = i;
//     sortA(N[k], dp, ind);
//   }
//   wt(if[dp[0]==int_inf, -1, dp[0]]);
// }