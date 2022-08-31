#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
void *wmem;
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
template<class T> int Factor_L(T N, T fac[], int fs[]){
  T i;
  int sz = 0;
  if(N%2==0){
    fac[sz] = 2;
    fs[sz] = 1;
    N /= 2;
    while(N%2==0){
      N /= 2;
      fs[sz]++;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      fs[sz] = 1;
      N /= i;
      while(N%i==0){
        N /= i;
        fs[sz]++;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    fs[sz] = 1;
    sz++;
  }
  return sz;
}
template<class T> int Divisor_L(T N, T res[], void *mem = wmem){
  int i;
  int j;
  int k;
  int s;
  int sz = 0;
  T *fc;
  int *fs;
  int fsz;
  walloc1d(&fc, 100, &mem);
  walloc1d(&fs, 100, &mem);
  fsz =Factor_L(N, fc, fs);
  res[sz++] = 1;
  for(i=(0);i<(fsz);i++){
    s = sz;
    k = s * fs[i];
    for(j=(0);j<(k);j++){
      res[sz++] = res[j] * fc[i];
    }
  }
  sort(res, res+sz);
  return sz;
}
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
  fft_pnt *y = (fft_pnt*)mem;
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
  fft_pnt *y = (fft_pnt*)mem;
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
  fft_pnt *a;
  fft_pnt *b;
  n =max_L(As+Bs, Rs);
  for(n2=1;n2<n;n2*=2){
    ;
  }
  walloc1d(&a, n2, &mem);
  walloc1d(&b, n2, &mem);
  for(i=(0);i<(As);i++){
    a[i].set(A[i], 0);
  }
  int NLJcSLph = n2;
  for(i=(As);i<(NLJcSLph);i++){
    a[i].set(0,0);
  }
  for(i=(0);i<(Bs);i++){
    b[i].set(B[i], 0);
  }
  int WZu7joIG = n2;
  for(i=(Bs);i<(WZu7joIG);i++){
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
  fft_pnt *a;
  n =max_L(As+As, Rs);
  for(n2=1;n2<n;n2*=2){
    ;
  }
  walloc1d(&a, n2, &mem);
  for(i=(0);i<(As);i++){
    a[i].set(A[i], 0);
  }
  int mRLrOZDI = n2;
  for(i=(As);i<(mRLrOZDI);i++){
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
int N;
int X;
int Y;
int A[200000+1];
int Q;
int L;
int ok[200000+1];
double a[500000];
double b[500000];
double c[1000000];
int ys;
int y[100000];
int res[200000];
int main(){
  int i, q;
  wmem = memarr;
  rd(N);
  rd(X);
  rd(Y);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N+1);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  rd(Q);
  for(i=(0);i<(N+1);i++){
    a[250000 + A[i]]++;
  }
  for(i=(0);i<(N+1);i++){
    b[250000 - A[i]]++;
  }
  convolution_L(a,500000,b,500000,c,1000000);
  for(i=(1);i<(200000+1);i++){
    if((int)(c[500000+i]+0.5)){
      ok[i] = 1;
    }
  }
  for(q=(0);q<(Q);q++){
    int ao_dF3pO;
    res[q] = -1;
    rd(L);
    L /= 2;
    ys =Divisor_L(L, y);
    for(ao_dF3pO=(ys)-1;ao_dF3pO>=(0);ao_dF3pO--){
      auto &i = y[ao_dF3pO];
      if(i-Y >= 0 && i-Y <= 200000 && ok[i-Y]){
        res[q] = 2*i;
        goto t_ynMSdg;
      }
    }
    t_ynMSdg:;
  }
  {
    int hCmBdyQB;
    if(Q==0){
      wt_L('\n');
    }
    else{
      for(hCmBdyQB=(0);hCmBdyQB<(Q-1);hCmBdyQB++){
        wt_L(res[hCmBdyQB]);
        wt_L(' ');
      }
      wt_L(res[hCmBdyQB]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N, X, Y, A[2d5+1], Q, L;
// int ok[2d5+1];
// double a[5d5], b[5d5], c[1d6];
// int ys, y[1d5];
// int res[2d5];
// {
//   rd(N,X,Y,A(N+1),Q);
//   rep(i,N+1) a[2.5d5 + A[i]]++;
//   rep(i,N+1) b[2.5d5 - A[i]]++;
//   convolution(a,5d5,b,5d5,c,1d6);
//   rep(i,1,2d5+1) if((int)(c[5d5+i]+0.5)) ok[i] = 1;
// 
//   rep(q,Q){
//     res[q] = -1;
//     rd(L);
//     L /= 2;
//     ys = Divisor(L, y);
//     rrep[y](i,ys) if(i-Y >= 0 && i-Y <= 2d5 && ok[i-Y]) res[q] = 2*i, break_continue;
//   }
//   wt(res(Q));
// }