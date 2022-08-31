#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (998244353U)
#define MD_PRIMITIVE_ROOT (3U)
#define PI 3.14159265358979323846
void*wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
template <class T> struct LHeap{
  int*hp;
  int*place;
  int size;
  T*val;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place=(int*)std::malloc(N*sizeof(int));
    val=(T*)std::malloc(N*sizeof(T));
  }
  void malloc(int N, int ini){
    hp = (int*)std::malloc(N*sizeof(int));
    place=(int*)std::malloc(N*sizeof(int));
    val=(T*)std::malloc(N*sizeof(T));
    if(ini){
      init(N);
    }
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&val, N, mem);
  }
  void walloc(int N, int ini, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&val, N, mem);
    if(ini){
      init(N);
    }
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
struct fft_pnt{
  double x;
  double y;
  fft_pnt(void){
  }
  fft_pnt(double a, double b){
    x = a;
    y = b;
  }
  void set(double a, double b){
    x = a;
    y = b;
  }
  fft_pnt& operator+=(fft_pnt a){
    x+=a.x;
    y+=a.y;
    return *this;
  }
  fft_pnt& operator-=(fft_pnt a){
    x-=a.x;
    y-=a.y;
    return *this;
  }
  fft_pnt& operator*=(fft_pnt a){
    fft_pnt p = *this;
    x = p.x*a.x-p.y*a.y;
    y = p.x*a.y+p.y*a.x;
    return *this;
  }
  fft_pnt operator+(fft_pnt a){
    return fft_pnt(*this) += a;
  }
  fft_pnt operator-(fft_pnt a){
    return fft_pnt(*this) -= a;
  }
  fft_pnt operator*(fft_pnt a){
    return fft_pnt(*this) *= a;
  }
}
;
void fft_L(int n, fft_pnt x[], void *mem){
  int i;
  int j;
  int n1;
  int n2;
  int n3;
  int step = 1;
  double theta = 2*PI / n;
  double tmp;
  fft_pnt w1;
  fft_pnt w2;
  fft_pnt w3;
  fft_pnt a;
  fft_pnt b;
  fft_pnt c;
  fft_pnt d;
  fft_pnt aa;
  fft_pnt bb;
  fft_pnt cc;
  fft_pnt dd;
  fft_pnt*y = (fft_pnt*)mem;
  while(n > 2){
    n1 = n / 4;
    n2 = n1 + n1;
    n3 = n1 + n2;
    for(i=(0);i<(n1);i++){
      w1 = fft_pnt(cos(i*theta),-sin(i*theta));
      w2 = w1*w1;
      w3 = w1*w2;
      for(j=(0);j<(step);j++){
        a = x[j+step*i];
        b = x[j+step*(i+n1)];
        c = x[j+step*(i+n2)];
        d = x[j+step*(i+n3)];
        aa = a + c;
        bb = a - c;
        cc = b + d;
        dd = b - d;
        tmp = dd.y;
        dd.y = dd.x;
        dd.x = -tmp;
        y[j+step*(4*i  )] = aa + cc;
        y[j+step*(4*i+1)] = w1*(bb - dd);
        y[j+step*(4*i+2)] = w2*(aa - cc);
        y[j+step*(4*i+3)] = w3*(bb + dd);
      }
    }
    n /= 4;
    step *= 4;
    theta *= 4;
    swap(x,y);
  }
  if(n==2){
    for(i=(0);i<(step);i++){
      y[i] = x[i] + x[i+step];
      y[i+step] = x[i] - x[i+step];
    }
    n /= 2;
    step *= 2;
    theta *= 2;
    swap(x,y);
  }
  for(i=(0);i<(step);i++){
    y[i] = x[i];
  }
}
void fftinv_L(int n, fft_pnt x[], void *mem){
  int i;
  int j;
  int n1;
  int n2;
  int n3;
  int step = 1;
  double theta = 2*PI / n;
  double tmp;
  fft_pnt w1;
  fft_pnt w2;
  fft_pnt w3;
  fft_pnt a;
  fft_pnt b;
  fft_pnt c;
  fft_pnt d;
  fft_pnt aa;
  fft_pnt bb;
  fft_pnt cc;
  fft_pnt dd;
  fft_pnt*y = (fft_pnt*)mem;
  while(n > 2){
    n1 = n / 4;
    n2 = n1 + n1;
    n3 = n1 + n2;
    for(i=(0);i<(n1);i++){
      w1 = fft_pnt(cos(i*theta),sin(i*theta));
      w2 = w1*w1;
      w3 = w1*w2;
      for(j=(0);j<(step);j++){
        a = x[j+step*i];
        b = x[j+step*(i+n1)];
        c = x[j+step*(i+n2)];
        d = x[j+step*(i+n3)];
        aa = a + c;
        bb = a - c;
        cc = b + d;
        dd = b - d;
        tmp = dd.y;
        dd.y = dd.x;
        dd.x = -tmp;
        y[j+step*(4*i  )] = aa + cc;
        y[j+step*(4*i+1)] = w1*(bb + dd);
        y[j+step*(4*i+2)] = w2*(aa - cc);
        y[j+step*(4*i+3)] = w3*(bb - dd);
      }
    }
    n /= 4;
    step *= 4;
    theta *= 4;
    swap(x,y);
  }
  if(n==2){
    for(i=(0);i<(step);i++){
      y[i] = x[i] + x[i+step];
      y[i+step] = x[i] - x[i+step];
    }
    n /= 2;
    step *= 2;
    theta *= 2;
    swap(x,y);
  }
  for(i=(0);i<(step);i++){
    y[i] = x[i];
  }
}
void convolution_L(double A[], int As, double B[], int Bs, double res[], int Rs, void *mem = wmem){
  int i;
  int n;
  int n2;
  double mul;
  fft_pnt*a;
  fft_pnt*b;
  n =max_L(As+Bs, Rs);
  for(n2=1;n2<n;n2*=2){
    ;
  }
  walloc1d(&a, n2, &mem);
  walloc1d(&b, n2, &mem);
  for(i=(0);i<(As);i++){
    a[i].set(A[i], 0);
  }
  int bz47bCAl = n2;
  for(i=(As);i<(bz47bCAl);i++){
    a[i].set(0,0);
  }
  for(i=(0);i<(Bs);i++){
    b[i].set(B[i], 0);
  }
  int mRLrOZDI = n2;
  for(i=(Bs);i<(mRLrOZDI);i++){
    b[i].set(0,0);
  }
  fft_L(n2, a, mem);
  fft_L(n2, b, mem);
  for(i=(0);i<(n2);i++){
    a[i] *= b[i];
  }
  fftinv_L(n2, a, mem);
  mul = 1.0 / n2;
  for(i=(0);i<(Rs);i++){
    res[i] = a[i].x * mul;
  }
}
void convolution_L(double A[], int As, double res[], int Rs, void *mem = wmem){
  int i;
  int n;
  int n2;
  double mul;
  fft_pnt*a;
  n =max_L(As+As, Rs);
  for(n2=1;n2<n;n2*=2){
    ;
  }
  walloc1d(&a, n2, &mem);
  for(i=(0);i<(As);i++){
    a[i].set(A[i], 0);
  }
  int Ee8EXgVm = n2;
  for(i=(As);i<(Ee8EXgVm);i++){
    a[i].set(0,0);
  }
  fft_L(n2, a, mem);
  for(i=(0);i<(n2);i++){
    a[i] *= a[i];
  }
  fftinv_L(n2, a, mem);
  mul = 1.0 / n2;
  for(i=(0);i<(Rs);i++){
    res[i] = a[i].x * mul;
  }
}
void fft_L(int n, Modint x[], Modint root, void *mem){
  int i;
  int j;
  int n1;
  int n2;
  int n3;
  int step = 1;
  Modint w1;
  Modint w2;
  Modint w3;
  Modint a;
  Modint b;
  Modint c;
  Modint d;
  Modint aa;
  Modint bb;
  Modint cc;
  Modint dd;
  Modint tmp;
  Modint*y;
  walloc1d(&y, n, &mem);
  tmp = root.pw((MD-1)/4*3);
  root = root.pw((MD-1)/n);
  while(n > 2){
    n1 = n / 4;
    n2 = n1 + n1;
    n3 = n1 + n2;
    w1.val = 1;
    for(i=(0);i<(n1);i++){
      w2 = w1*w1;
      w3 = w1*w2;
      for(j=(0);j<(step);j++){
        a = x[j+step*i];
        b = x[j+step*(i+n1)];
        c = x[j+step*(i+n2)];
        d = x[j+step*(i+n3)];
        aa = a + c;
        bb = a - c;
        cc = b + d;
        dd = (b - d) * tmp;
        y[j+step*(4*i  )] = aa + cc;
        y[j+step*(4*i+1)] = w1*(bb - dd);
        y[j+step*(4*i+2)] = w2*(aa - cc);
        y[j+step*(4*i+3)] = w3*(bb + dd);
      }
      w1 *= root;
    }
    n /= 4;
    step *= 4;
    root *= root;
    root *= root;
    swap(x,y);
  }
  if(n==2){
    for(i=(0);i<(step);i++){
      y[i] = x[i] + x[i+step];
      y[i+step] = x[i] - x[i+step];
    }
    n /= 2;
    step *= 2;
    root *= root;
    swap(x,y);
  }
  for(i=(0);i<(step);i++){
    y[i] = x[i];
  }
}
void fftinv_L(int n, Modint x[], Modint root, void *mem){
  int i;
  int j;
  int n1;
  int n2;
  int n3;
  int step = 1;
  Modint w1;
  Modint w2;
  Modint w3;
  Modint a;
  Modint b;
  Modint c;
  Modint d;
  Modint aa;
  Modint bb;
  Modint cc;
  Modint dd;
  Modint tmp;
  Modint*y;
  walloc1d(&y, n, &mem);
  root = root.inverse();
  tmp = root.pw((MD-1)/4);
  root = root.pw((MD-1)/n);
  while(n > 2){
    n1 = n / 4;
    n2 = n1 + n1;
    n3 = n1 + n2;
    w1.val = 1;
    for(i=(0);i<(n1);i++){
      w2 = w1*w1;
      w3 = w1*w2;
      for(j=(0);j<(step);j++){
        a = x[j+step*i];
        b = x[j+step*(i+n1)];
        c = x[j+step*(i+n2)];
        d = x[j+step*(i+n3)];
        aa = a + c;
        bb = a - c;
        cc = b + d;
        dd = (b - d) * tmp;
        y[j+step*(4*i  )] = aa + cc;
        y[j+step*(4*i+1)] = w1*(bb + dd);
        y[j+step*(4*i+2)] = w2*(aa - cc);
        y[j+step*(4*i+3)] = w3*(bb - dd);
      }
      w1 *= root;
    }
    n /= 4;
    step *= 4;
    root *= root;
    root *= root;
    swap(x,y);
  }
  if(n==2){
    for(i=(0);i<(step);i++){
      y[i] = x[i] + x[i+step];
      y[i+step] = x[i] - x[i+step];
    }
    n /= 2;
    step *= 2;
    root *= root;
    swap(x,y);
  }
  for(i=(0);i<(step);i++){
    y[i] = x[i];
  }
}
void convolution_L(Modint A[], int As, Modint B[], int Bs, Modint res[], int Rs,  Modint root = MD_PRIMITIVE_ROOT, void *mem = wmem){
  int i;
  int n;
  int n2;
  Modint*a;
  Modint*b;
  Modint r;
  n =max_L(As+Bs, Rs);
  for(n2=1;n2<n;n2*=2){
    ;
  }
  walloc1d(&a, n2, &mem);
  walloc1d(&b, n2, &mem);
  for(i=(0);i<(As);i++){
    a[i] = A[i];
  }
  int MdJQmFnd = n2;
  for(i=(As);i<(MdJQmFnd);i++){
    a[i].val = 0;
  }
  for(i=(0);i<(Bs);i++){
    b[i] = B[i];
  }
  int MsHTBJEM = n2;
  for(i=(Bs);i<(MsHTBJEM);i++){
    b[i].val = 0;
  }
  fft_L(n2, a, root, mem);
  fft_L(n2, b, root, mem);
  for(i=(0);i<(n2);i++){
    a[i] *= b[i];
  }
  fftinv_L(n2, a, root, mem);
  r = Modint(n2).inverse();
  for(i=(0);i<(Rs);i++){
    res[i] = a[i] * r;
  }
}
void convolution_L(Modint A[], int As, Modint res[], int Rs, Modint root = MD_PRIMITIVE_ROOT, void *mem = wmem){
  int i;
  int n;
  int n2;
  Modint*a;
  Modint r;
  n =max_L(2*As, Rs);
  for(n2=1;n2<n;n2*=2){
    ;
  }
  walloc1d(&a, n2, &mem);
  for(i=(0);i<(As);i++){
    a[i] = A[i];
  }
  int pRrsnthG = n2;
  for(i=(As);i<(pRrsnthG);i++){
    a[i].val = 0;
  }
  fft_L(n2, a, root, mem);
  for(i=(0);i<(n2);i++){
    a[i] *= a[i];
  }
  fftinv_L(n2, a, root, mem);
  r = Modint(n2).inverse();
  for(i=(0);i<(Rs);i++){
    res[i] = a[i]*r;
  }
}
int N;
int M;
char S[200000+2];
int geta[100000];
vector<Modint> v[100000];
Modint arr1[200000];
Modint arr2[200000];
Modint arr[200000];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int x;
  int y;
  int sx;
  int sy;
  int sz;
  Modint res = 0;
  Modint tot = 0;
  rd(N);
  rd(M);
  rd(S);
  LHeap<int> hp;
  for(i=(0);i<(N/2);i++){
    int Q5VJL1cS;
    for(Q5VJL1cS=(0);Q5VJL1cS<(3);Q5VJL1cS++){
      v[i].push_back(0);
    }
    for(x=(0);x<(2);x++){
      for(y=(0);y<(2);y++){
        if(x==0 && S[2*i]=='b'){
          continue;
        }
        if(x==1 && S[2*i]=='w'){
          continue;
        }
        if(y==0 && S[2*i+1]=='b'){
          continue;
        }
        if(y==1 && S[2*i+1]=='w'){
          continue;
        }
        v[i][x-y+1] += 1;
      }
    }
  }
  hp.walloc(N/2, 1);
  for(i=(0);i<(N/2);i++){
    hp.change(i, v[i].size());
  }
  while(hp.size >= 2){
    x = hp.pop();
    y = hp.pop();
    sx = v[x].size();
    sy = v[y].size();
    sz = sx + sy - 1;
    for(i=(0);i<(sx);i++){
      arr1[i] = v[x][i];
    }
    for(i=(0);i<(sy);i++){
      arr2[i] = v[y][i];
    }
    convolution_L(arr1, sx, arr2, sy, arr, sz);
    v[x].clear();
    for(i=(0);i<(sz);i++){
      v[x].push_back(arr[i]);
    }
    hp.change(x, sz);
  }
  x = hp.pop();
  sz = v[x].size();
  for(i=(0);i<(sz);i++){
    arr[i] = v[x][i];
  }
  for(i=(0);i<(sz);i++){
    j = abs(i - sz/2);
    if(j%2){
      continue;
    }
    res += (j/2) * arr[i];
    tot += arr[i];
  }
  wt_L(res / tot);
  wt_L('\n');
  return 0;
}
// cLay version 20201206-1

// --- original code ---
// //no-unlocked
// #define MD 998244353
// int N, M;
// char S[2d5+2];
// 
// int geta[1d5];
// vector<Modint> v[1d5];
// 
// Modint arr1[2d5], arr2[2d5], arr[2d5];
// 
// {
//   int i, j, k, x, y, sx, sy, sz;
//   Modint res = 0, tot = 0;
//   rd(N,M,S);
//   LHeap<int> hp;
// 
//   rep(i,N/2){
//     rep(3) v[i].push_back(0);
//     rep(x,2) rep(y,2){
//       if(x==0 && S[2*i]=='b') continue;
//       if(x==1 && S[2*i]=='w') continue;
//       if(y==0 && S[2*i+1]=='b') continue;
//       if(y==1 && S[2*i+1]=='w') continue;
//       v[i][x-y+1] += 1;
//     }
//   }
// 
//   hp.walloc(N/2, 1);
//   rep(i,N/2) hp.change(i, v[i].size());
//   while(hp.size >= 2){
//     x = hp.pop();
//     y = hp.pop();
//     sx = v[x].size();
//     sy = v[y].size();
//     sz = sx + sy - 1;
//     rep(i,sx) arr1[i] = v[x][i];
//     rep(i,sy) arr2[i] = v[y][i];
//     convolution(arr1, sx, arr2, sy, arr, sz);
//     v[x].clear();
//     rep(i,sz) v[x].push_back(arr[i]);
//     hp.change(x, sz);
//   }
// 
//   x = hp.pop();
//   sz = v[x].size();
//   // wt(v[x](sz));
//   rep(i,sz) arr[i] = v[x][i];
//   rep(i,sz){
//     j = abs(i - sz/2);
//     if(j%2) continue;
//     res += (j/2) * arr[i];
//     tot += arr[i];
//   }
//   wt(res / tot);
// }