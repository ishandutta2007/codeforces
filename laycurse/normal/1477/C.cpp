#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
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
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
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
int N;
long long X[5000];
long long Y[5000];
Rand rnd;
int ind[5000];
double xx[5000];
double yy[5000];
int res[5000];
int main(){
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);
      rd(Y[Lj4PdHRW]);
    }
  }
  for(;;){
    int i;
    int n1;
    int n2;
    double th;
    double cc;
    double ss;
    long long tmp;
    for(i=(0);i<(N);i++){
      ind[i] = i;
    }
    th = rnd.getUni() * 2 * PI;
    cc = cos(th);
    ss = sin(th);
    for(i=(0);i<(N);i++){
      xx[i] = X[i] * cc - Y[i] * ss;
    }
    for(i=(0);i<(N);i++){
      yy[i] = X[i] * ss + Y[i] * cc;
    }
    n1 = (N+1) / 2;
    n2 = N - n1;
    sortA_L(N, xx, yy, ind);
    sortA_L(n1, yy, xx, ind);
    sortA_L(n2, yy + n1, xx + n1, ind + n1);
    for(i=(0);i<(n1);i++){
      res[2*i] = ind[i];
      if(2*i+1 < N){
        res[2*i+1] = ind[n1+i];
      }
    }
    for(i=(1);i<(N-1);i++){
      tmp = (X[res[i+1]] - X[res[i]]) * (X[res[i-1]] - X[res[i]]) + (Y[res[i+1]] - Y[res[i]]) * (Y[res[i-1]] - Y[res[i]]);
      if(tmp <= 0){
        goto e98WHCEY;
      }
    }
    break;
    e98WHCEY:;
  }
  {
    int V9aVTaxx;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(V9aVTaxx=(0);V9aVTaxx<(N-1);V9aVTaxx++){
        wt_L(res[V9aVTaxx]+1);
        wt_L(' ');
      }
      wt_L(res[V9aVTaxx]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// int N; ll X[5000], Y[5000];
// Rand rnd;
// int ind[5000]; double xx[5000], yy[5000];
// int res[5000];
// {
//   rd(N,(X,Y)(N));
//   for(;;){
//     int n1, n2;
//     double th, cc, ss;
//     ll tmp;
//     rep(i,N) ind[i] = i;
//     th = rnd.getUni() * 2 * PI;
//     cc = cos(th);
//     ss = sin(th);
//     rep(i,N) xx[i] = X[i] * cc - Y[i] * ss;
//     rep(i,N) yy[i] = X[i] * ss + Y[i] * cc;
//     n1 = (N+1) / 2;
//     n2 = N - n1;
//     sortA(N, xx, yy, ind);
//     sortA(n1, yy, xx, ind);
//     sortA(n2, yy + n1, xx + n1, ind + n1);
//     rep(i,n1){
//       res[2*i] = ind[i];
//       if(2*i+1 < N) res[2*i+1] = ind[n1+i];
//     }
//     // puts("");
//     // wt(res(N) + 1);
//     // rep(i,1,N-1){
//     //   tmp = (X[res[i+1]] - X[res[i]]) * (X[res[i-1]] - X[res[i]]) + (Y[res[i+1]] - Y[res[i]]) * (Y[res[i-1]] - Y[res[i]]);
//     //   wt(i, ":", tmp);
//     // }
//     rep(i,1,N-1){
//       tmp = (X[res[i+1]] - X[res[i]]) * (X[res[i-1]] - X[res[i]]) + (Y[res[i+1]] - Y[res[i]]) * (Y[res[i-1]] - Y[res[i]]);
//       if(tmp <= 0) break_continue;
//     }
//     break;
//   }
//   wt(res(N)+1);
// }