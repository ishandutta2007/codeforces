#pragma GCC optimize ("Ofast")
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
inline void wt_L(Modint x){
  int i;
  i = (int)x;
  wt_L(i);
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
    return 1;
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
    set_shist = 0;
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
int K;
Arr1d<int> A;
Comb<Modint> c;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(K);
    A.malloc(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    for(i=(N)-1;i>=(0);i--){
      if(K >= A.dHist(i)){
        K -= A.dHist(i);
        continue;
      }
      wt_L(c.C(A.dHist(i), K));
      wt_L('\n');
      goto Q5VJL1cS;
    }
    wt_L(1);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// int N, K; Arr1d<int> A;
// Comb<Modint> c;
// {
//   REP(rd_int()){
//     rd(N,K,(A--)(N));
//     rrep(i,N){
//       if(K >= A.dHist(i)) K -= A.dHist(i), continue;
//       wt(c.C(A.dHist(i), K));
//       break_continue;
//     }
//     wt(1);
//   }
// }