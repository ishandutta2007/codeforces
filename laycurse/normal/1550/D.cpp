#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define MD (1000000007U)
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
struct Modint{
  unsigned val;
  Modint(){
    val=0;
  }
  Modint(int a){
    val = ord(a);
  }
  Modint(unsigned a){
    val = ord(a);
  }
  Modint(long long a){
    val = ord(a);
  }
  Modint(unsigned long long a){
    val = ord(a);
  }
  inline unsigned ord(unsigned a){
    return a%MD;
  }
  inline unsigned ord(int a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned ord(unsigned long long a){
    return a%MD;
  }
  inline unsigned ord(long long a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned get(){
    return val;
  }
  inline Modint &operator++(){
    val++;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  inline Modint &operator--(){
    if(val == 0){
      val = MD - 1;
    }
    else{
      --val;
    }
    return *this;
  }
  inline Modint operator++(int a){
    Modint res(*this);
    val++;
    if(val >= MD){
      val -= MD;
    }
    return res;
  }
  inline Modint operator--(int a){
    Modint res(*this);
    if(val == 0){
      val = MD - 1;
    }
    else{
      --val;
    }
    return res;
  }
  inline Modint &operator+=(Modint a){
    val += a.val;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  inline Modint &operator-=(Modint a){
    if(val < a.val){
      val = val + MD - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  inline Modint &operator*=(Modint a){
    val = ((unsigned long long)val*a.val)%MD;
    return *this;
  }
  inline Modint &operator/=(Modint a){
    return *this *= a.inverse();
  }
  inline Modint operator+(Modint a){
    return Modint(*this)+=a;
  }
  inline Modint operator-(Modint a){
    return Modint(*this)-=a;
  }
  inline Modint operator*(Modint a){
    return Modint(*this)*=a;
  }
  inline Modint operator/(Modint a){
    return Modint(*this)/=a;
  }
  inline Modint operator+(int a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(int a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(int a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(int a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator+(long long a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(long long a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(long long a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(long long a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator-(void){
    Modint res;
    if(val){
      res.val=MD-val;
    }
    else{
      res.val=0;
    }
    return res;
  }
  inline operator bool(void){
    return val!=0;
  }
  inline operator int(void){
    return get();
  }
  inline operator long long(void){
    return get();
  }
  inline Modint inverse(){
    int a = val;
    int b = MD;
    int u = 1;
    int v = 0;
    int t;
    Modint res;
    while(b){
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if(u < 0){
      u += MD;
    }
    res.val = u;
    return res;
  }
  inline Modint pw(unsigned long long b){
    Modint a(*this);
    Modint res;
    res.val = 1;
    while(b){
      if(b&1){
        res *= a;
      }
      b >>= 1;
      a *= a;
    }
    return res;
  }
  inline bool operator==(int a){
    return ord(a)==val;
  }
  inline bool operator!=(int a){
    return ord(a)!=val;
  }
}
;
inline Modint operator+(int a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(int a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(int a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(int a, Modint b){
  return Modint(a)/=b;
}
inline Modint operator+(long long a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(long long a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(long long a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(long long a, Modint b){
  return Modint(a)/=b;
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
inline void wt_L(Modint x){
  int i;
  i = (int)x;
  wt_L(i);
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> struct Comb{
  int mem_fact;
  T*factri;
  T*ifactri;
  int mem_dfact;
  T*dfactri;
  int mem_pw2;
  int mem_pw3;
  int mem_pw10;
  int mem_rep1;
  T*pw2c;
  T*pw3c;
  T*pw10c;
  T*rep1c;
  int mem_ipw2;
  int mem_ipw3;
  int mem_ipw10;
  T*ipw2c;
  T*ipw3c;
  T*ipw10c;
  Comb(){
    mem_fact = 0;
    mem_dfact = 0;
    mem_pw2 = mem_pw3 = mem_pw10 = mem_rep1 = 0;
    mem_ipw2 = mem_ipw3 = mem_ipw10 = 0;
  }
  inline void expand_fact(int k){
    int i;
    if(k <= mem_fact){
      return;
    }
    chmax(k, 2 * mem_fact);
    if(mem_fact == 0){
      factri = (T*)malloc(k * sizeof(T));
      ifactri = (T*)malloc(k * sizeof(T));
      factri[0] = 1;
      for(i=(1);i<(k);i++){
        factri[i] = i * factri[i-1];
      }
      ifactri[k-1] = 1 / factri[k-1];
      for(i=(k-1)-1;i>=(0);i--){
        ifactri[i] = (i+1) * ifactri[i+1];
      }
    }
    else{
      factri = (T*)realloc(factri, k * sizeof(T));
      ifactri = (T*)realloc(ifactri, k * sizeof(T));
      for(i=(mem_fact);i<(k);i++){
        factri[i] = i * factri[i-1];
      }
      ifactri[k-1] = 1 / factri[k-1];
      for(i=(k-1)-1;i>=(mem_fact);i--){
        ifactri[i] = (i+1) * ifactri[i+1];
      }
    }
    mem_fact = k;
  }
  inline T fac(int k){
    if(mem_fact < k+1){
      expand_fact(k+1);
    }
    return factri[k];
  }
  inline T ifac(int k){
    if(mem_fact < k+1){
      expand_fact(k+1);
    }
    return ifactri[k];
  }
  inline T C(int a, int b){
    if(b < 0 || b > a){
      return 0;
    }
    if(mem_fact < a+1){
      expand_fact(a+1);
    }
    return factri[a] * ifactri[b] * ifactri[a-b];
  }
  inline T P(int a, int b){
    if(b < 0 || b > a){
      return 0;
    }
    if(mem_fact < a+1){
      expand_fact(a+1);
    }
    return factri[a] * ifactri[a-b];
  }
  inline T H(int a, int b){
    if(a==0 && b==0){
      return 1;
    }
    if(a <= 0 || b < 0){
      return 0;
    }
    if(mem_fact < a+b){
      expand_fact(a+b);
    }
    return C(a+b-1, b);
  }
  inline T Multinomial(int sz, int a[]){
    int i;
    int s = 0;
    T res;
    for(i=(0);i<(sz);i++){
      s += a[i];
    }
    if(mem_fact < s+1){
      expand_fact(s+1);
    }
    res = factri[s];
    for(i=(0);i<(sz);i++){
      res *= ifactri[a[i]];
    }
    return res;
  }
  inline T Multinomial(int a){
    return 1;
  }
  inline T Multinomial(int a, int b){
    if(mem_fact < a+b+1){
      expand_fact(a+b+1);
    }
    return factri[a+b] * ifactri[a] * ifactri[b];
  }
  inline T Multinomial(int a, int b, int c){
    if(mem_fact < a+b+c+1){
      expand_fact(a+b+c+1);
    }
    return factri[a+b+c] * ifactri[a] * ifactri[b] * ifactri[c];
  }
  inline T Multinomial(int a, int b, int c, int d){
    if(mem_fact < a+b+c+d+1){
      expand_fact(a+b+c+d+1);
    }
    return factri[a+b+c+d] * ifactri[a] * ifactri[b] * ifactri[c] * ifactri[d];
  }
  inline T Catalan(int n){
    if(n < 0){
      return 0;
    }
    if(mem_fact < 2*n+1){
      expand_fact(2*n+1);
    }
    return factri[2*n] * ifactri[n] * ifactri[n+1];
  }
  inline T Catalan(int n, int m, int k){
    if(k <= 0){
      return C(n+m, n);
    }
    if(n < k || m < k){
      return 0;
    }
    return C(n+m, m) - C(n+m, k-1);
  }
  inline T Catalan_s(long long n, long long m, long long k){
    if(k <= 0){
      return C_s(n+m, n);
    }
    if(n < k || m < k){
      return 0;
    }
    return C_s(n+m, m) - C_s(n+m, k-1);
  }
  inline T C_s(long long a, long long b){
    long long i;
    T res;
    if(b < 0 || b > a){
      return 0;
    }
    if(b > a - b){
      b = a - b;
    }
    res = 1;
    for(i=(0);i<(b);i++){
      res *= a - i;
      res /= i + 1;
    }
    return res;
  }
  inline T P_s(long long a, long long b){
    long long i;
    T res;
    if(b < 0 || b > a){
      return 0;
    }
    res = 1;
    for(i=(0);i<(b);i++){
      res *= a - i;
    }
    return res;
  }
  inline T H_s(long long a, long long b){
    if(a==0 && b==0){
      return 1;
    }
    if(a <= 0 || b < 0){
      return 0;
    }
    return C_s(a+b-1, b);
  }
  inline T per_s(long long n, long long k){
    T d;
    int m;
    if(n < 0 || k < 0){
      return 0;
    }
    if(n == k  &&  k == 0){
      return 1;
    }
    if(n == 0 || k == 0){
      return 0;
    }
    if(k==1){
      return 1;
    }
    if(k==2){
      d = n / 2;
      return d;
    }
    if(k==3){
      d = (n-1) / 6;
      m = (n-1) % 6;
      if(m==0){
        return 3 * d * d + d;
      }
      if(m==1){
        return 3 * d * d + 2 * d;
      }
      if(m==2){
        return 3 * d * d + 3 * d + 1;
      }
      if(m==3){
        return 3 * d * d + 4 * d + 1;
      }
      if(m==4){
        return 3 * d * d + 5 * d + 2;
      }
      if(m==5){
        return 3 * d * d + 6 * d + 3;
      }
    }
    assert(0 && "per_s should be k <= 3");
    return -1;
  }
  inline void expand_dfact(int k){
    int i;
    if(k <= mem_dfact){
      return;
    }
    chmax(k, 3);
    chmax(k, 2 * mem_dfact);
    if(mem_dfact==0){
      dfactri = (T*)malloc(k * sizeof(T));
      dfactri[0] = dfactri[1] = 1;
      for(i=(2);i<(k);i++){
        dfactri[i] = i * dfactri[i-2];
      }
    }
    else{
      dfactri = (T*)realloc(dfactri, k * sizeof(T));
      for(i=(mem_dfact);i<(k);i++){
        dfactri[i] = i * dfactri[i-2];
      }
    }
    mem_dfact = k;
  }
  inline void expand_pw2(int k){
    int i;
    if(k <= mem_pw2){
      return;
    }
    chmax(k, 2 * mem_pw2);
    if(mem_pw2==0){
      pw2c = (T*)malloc(k * sizeof(T));
      pw2c[0] = 1;
      for(i=(1);i<(k);i++){
        pw2c[i] = 2 * pw2c[i-1];
      }
    }
    else{
      pw2c = (T*)realloc(pw2c, k * sizeof(T));
      for(i=(mem_pw2);i<(k);i++){
        pw2c[i] = 2 * pw2c[i-1];
      }
    }
    mem_pw2 = k;
  }
  inline void expand_ipw2(int k){
    int i;
    if(k <= mem_ipw2){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * mem_ipw2);
    if(mem_ipw2==0){
      ipw2c = (T*)malloc(k * sizeof(T));
      ipw2c[0] = 1;
      ipw2c[1] = ipw2c[0] / 2;
      for(i=(1);i<(k);i++){
        ipw2c[i] = ipw2c[1] * ipw2c[i-1];
      }
    }
    else{
      ipw2c = (T*)realloc(ipw2c, k * sizeof(T));
      for(i=(mem_ipw2);i<(k);i++){
        ipw2c[i] = ipw2c[1] * ipw2c[i-1];
      }
    }
    mem_ipw2 = k;
  }
  inline void expand_pw3(int k){
    int i;
    if(k <= mem_pw3){
      return;
    }
    chmax(k, 2 * mem_pw3);
    if(mem_pw3==0){
      pw3c = (T*)malloc(k * sizeof(T));
      pw3c[0] = 1;
      for(i=(1);i<(k);i++){
        pw3c[i] = 3 * pw3c[i-1];
      }
    }
    else{
      pw3c = (T*)realloc(pw3c, k * sizeof(T));
      for(i=(mem_pw3);i<(k);i++){
        pw3c[i] = 3 * pw3c[i-1];
      }
    }
    mem_pw3 = k;
  }
  inline void expand_ipw3(int k){
    int i;
    if(k <= mem_ipw3){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * mem_ipw3);
    if(mem_ipw3==0){
      ipw3c = (T*)malloc(k * sizeof(T));
      ipw3c[0] = 1;
      ipw3c[1] = ipw3c[0] / 3;
      for(i=(1);i<(k);i++){
        ipw3c[i] = ipw3c[1] * ipw3c[i-1];
      }
    }
    else{
      ipw3c = (T*)realloc(ipw3c, k * sizeof(T));
      for(i=(mem_ipw3);i<(k);i++){
        ipw3c[i] = ipw3c[1] * ipw3c[i-1];
      }
    }
    mem_ipw3 = k;
  }
  inline void expand_pw10(int k){
    int i;
    if(k <= mem_pw10){
      return;
    }
    chmax(k, 2 * mem_pw10);
    if(mem_pw10==0){
      pw10c = (T*)malloc(k * sizeof(T));
      pw10c[0] = 1;
      for(i=(1);i<(k);i++){
        pw10c[i] = 10 * pw10c[i-1];
      }
    }
    else{
      pw10c = (T*)realloc(pw10c, k * sizeof(T));
      for(i=(mem_pw10);i<(k);i++){
        pw10c[i] = 10 * pw10c[i-1];
      }
    }
    mem_pw10 = k;
  }
  inline void expand_ipw10(int k){
    int i;
    if(k <= mem_ipw10){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * mem_ipw10);
    if(mem_ipw10==0){
      ipw10c = (T*)malloc(k * sizeof(T));
      ipw10c[0] = 1;
      ipw10c[1] = ipw10c[0] / 10;
      for(i=(1);i<(k);i++){
        ipw10c[i] = ipw10c[1] * ipw10c[i-1];
      }
    }
    else{
      ipw10c = (T*)realloc(ipw10c, k * sizeof(T));
      for(i=(mem_ipw10);i<(k);i++){
        ipw10c[i] = ipw10c[1] * ipw10c[i-1];
      }
    }
    mem_ipw10 = k;
  }
  inline void expand_rep1(int k){
    int i;
    if(k <= mem_rep1){
      return;
    }
    chmax(k, 2 * mem_rep1);
    if(mem_rep1==0){
      rep1c = (T*)malloc(k * sizeof(T));
      rep1c[0] = 0;
      for(i=(1);i<(k);i++){
        rep1c[i] = 10 * rep1c[i-1] + 1;
      }
    }
    else{
      rep1c = (T*)realloc(rep1c, k * sizeof(T));
      for(i=(mem_rep1);i<(k);i++){
        rep1c[i] = 10 * rep1c[i-1] + 1;
      }
    }
    mem_rep1 = k;
  }
  inline T dfac(int k){
    if(k >= 0){
      if(mem_dfact < k+1){
        expand_dfact(k+1);
      }
      return dfactri[k];
    }
    if(k==-1){
      return 1;
    }
    k = - k - 2;
    if(k % 4 == 1){
      return 1 / (-dfac(k));
    }
    return 1 / dfac(k);
  }
  inline T pw2(int k){
    if(k >= 0){
      if(mem_pw2 < k+1){
        expand_pw2(k+1);
      }
      return pw2c[k];
    }
    else{
      k = -k;
      if(mem_ipw2 < k+1){
        expand_ipw2(k+1);
      }
      return ipw2c[k];
    }
  }
  inline T pw3(int k){
    if(k >= 0){
      if(mem_pw3 < k+1){
        expand_pw3(k+1);
      }
      return pw3c[k];
    }
    else{
      k = -k;
      if(mem_ipw3 < k+1){
        expand_ipw3(k+1);
      }
      return ipw3c[k];
    }
  }
  inline T pw10(int k){
    if(k >= 0){
      if(mem_pw10 < k+1){
        expand_pw10(k+1);
      }
      return pw10c[k];
    }
    else{
      k = -k;
      if(mem_ipw10 < k+1){
        expand_ipw10(k+1);
      }
      return ipw10c[k];
    }
  }
  inline T repunit(int k){
    if(mem_rep1 < k+1){
      expand_rep1(k+1);
    }
    return rep1c[k];
  }
}
;
template<> inline Modint Comb<Modint>::C_s(long long a, long long b){
  long long i;
  Modint res;
  Modint d;
  if(b < 0 || b > a){
    return 0;
  }
  if(b > a - b){
    b = a - b;
  }
  res = d = 1;
  for(i=(0);i<(b);i++){
    res *= a - i;
    d *= i + 1;
  }
  return res / d;
}
int N;
int L;
int R;
Comb<Modint> c;
int type[400000];
int yoyu[400000];
int d[2];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int cur = 0;
    Modint res = 0;
    rd(N);
    rd(L);
    rd(R);
    for(i=(0);i<(N);i++){
      type[i] = 0;
      yoyu[i] = R - (i+1);
    }
    for(i=(0);i<(N);i++){
      type[N+i] = 1;
      yoyu[N+i] = (i+1) - L;
    }
    d[0] = d[1] = 0;
    sortA_L(2*N,yoyu,type);
    for(i=(0);i<(N+1);i++){
      res += (yoyu[i] - cur) * c.C(N - i, N/2 - d[0]);
      if(N%2==1){
        res += (yoyu[i] - cur) * c.C(N - i, N/2 - d[1]);
      }
      d[type[i]]++;
      cur = yoyu[i];
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210708-1

// --- original code ---
// //no-unlocked
// int N, L, R;
// Comb<Modint> c;
// int type[4d5], yoyu[], d[2];
// {
//   REP(rd_int()){
//     int cur = 0;
//     Modint res = 0;
//     rd(N,L,R);
//     rep(i,N) type[i] = 0, yoyu[i] = R - (i+1);
//     rep(i,N) type[N+i] = 1, yoyu[N+i] = (i+1) - L;
//     d[0] = d[1] = 0;
//     sortA(2N,yoyu,type);
//     rep(i,N+1){
//       res += (yoyu[i] - cur) * c.C(N - i, N/2 - d[0]);
//       if(N%2==1) res += (yoyu[i] - cur) * c.C(N - i, N/2 - d[1]);
//       d[type[i]]++;
//       cur = yoyu[i];
//     }
//     wt(res);
//   }
// }