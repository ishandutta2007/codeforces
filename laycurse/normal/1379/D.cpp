#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
int N;
int H;
int M;
int K;
int HH[100000];
int MM[100000];
int a[100000];
int b[100000];
int solve(int t){
  int x;
  int y;
  int res = 0;
  x = lower_bound(b, b+N, t-K) - b;
  y = lower_bound(b, b+N, t) - b;
  res += y - x;
  x = lower_bound(b, b+N, t-K+M) - b;
  y = lower_bound(b, b+N, t+M) - b;
  res += y - x;
  return res;
}
int main(){
  int i;
  wmem = memarr;
  int res_t;
  int res_v = 1073709056;
  int tmp;
  rd(N);
  rd(H);
  rd(M);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(HH[Lj4PdHRW]);
      rd(MM[Lj4PdHRW]);
    }
  }
  K--;
  M /= 2;
  for(i=(0);i<(N);i++){
    a[i] = MM[i] % M;
  }
  for(i=(0);i<(N);i++){
    b[i] = a[i];
  }
  sortA_L(N,b);
  for(i=(0);i<(N);i++){
    tmp = solve(a[i]);
    if(res_v > tmp){
      res_t = a[i];
      res_v = tmp;
    }
  }
  wt_L(res_v);
  wt_L(' ');
  wt_L(res_t);
  wt_L('\n');
  for(i=(0);i<(N);i++){
    if(res_t-K <= a[i]-M  &&  a[i]-M < res_t || res_t-K <= a[i]  &&  a[i] < res_t){
      wt_L(i+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, H, M, K, HH[1d5], MM[1d5];
// int a[1d5], b[1d5];
// 
// int solve(int t){
//   int x, y, res = 0;
//   x = lower_bound(b, b+N, t-K) - b;
//   y = lower_bound(b, b+N, t) - b;
//   res += y - x;
//   x = lower_bound(b, b+N, t-K+M) - b;
//   y = lower_bound(b, b+N, t+M) - b;
//   res += y - x;
//   return res;
// }
// 
// {
//   int res_t, res_v = int_inf, tmp;
//   rd(N,H,M,K,(HH,MM)(N));
//   K--;
//   M /= 2;
//   rep(i,N) a[i] = MM[i] % M;
// 
//   rep(i,N) b[i] = a[i];
//   sortA(N,b);
//   rep(i,N){
//     tmp = solve(a[i]);
//     if(res_v > tmp){
//       res_t = a[i];
//       res_v = tmp;
//     }
//   }
// 
//   wt(res_v, res_t);
//   rep(i,N) if(res_t-K <= a[i]-M < res_t || res_t-K <= a[i] < res_t) wt(i+1);
// }