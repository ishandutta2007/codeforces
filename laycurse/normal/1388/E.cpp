#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
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
  pair<T1, pair<T2, T3> > *arr;
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
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
}
template<class T1, class T2, class T3> void rsortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  sortA_L(N, a, b, c, mem);
  reverse(a, a+N);
  reverse(b, b+N);
  reverse(c, c+N);
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
#define EPS 1e-9
int N;
int X1[2000];
int X2[2000];
int Y[2000];
int sz;
double mn[4000000];
double mx[4000000];
int ch;
double d[4000000];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int nn;
  double res = 1e150;
  double th;
  double nx;
  double tmp;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X1[Lj4PdHRW]);
      rd(X2[Lj4PdHRW]);
      rd(Y[Lj4PdHRW]);
    }
  }
  rsortA_L(N,Y,X1,X2);
  for(i=(0);i<(N);i++){
    for(j=(i+1);j<(N);j++){
      if(Y[i] != Y[j]){
        mn[sz] = -(double)(X2[i] - X1[j]) / (Y[i] - Y[j]);
        mx[sz] = -(double)(X1[i] - X2[j]) / (Y[i] - Y[j]);
        sz++;
      }
    }
  }
  if(sz==0){
    {
      int xr20shxY;
      int WYIGIcGE;
      if(N==0){
        WYIGIcGE = 0;
      }
      else{
        WYIGIcGE = X1[0];
        for(xr20shxY=(1);xr20shxY<(N);xr20shxY++){
          WYIGIcGE = min_L(WYIGIcGE, X1[xr20shxY]);
        }
      }
      {
        int ao_dF3pO;
        int tU__gIr_;
        if(N==0){
          tU__gIr_ = 0;
        }
        else{
          tU__gIr_ = X2[0];
          for(ao_dF3pO=(1);ao_dF3pO<(N);ao_dF3pO++){
            tU__gIr_ = max_L(tU__gIr_, X2[ao_dF3pO]);
          }
        }
        res =tU__gIr_-WYIGIcGE;
      }
    }
    wt_L(res);
    wt_L('\n');
    return 0;
  }
  sortA_L(sz, mn, mx);
  th = mn[0];
  for(i=(0);i<(sz);i++){
    if(th <= mn[i] + EPS){
      d[ch++] = th;
      d[ch++] = mn[i];
    }
    chmax(th, mx[i]);
  }
  d[ch++] = th;
  k = 0;
  nn = -1;
  while(k+1 < N && Y[k]==Y[k+1] && X1[k] > X1[k+1]){
    k++;
  }
  for(i=(0);i<(ch);i++){
    if(nn==-1){
      nx = 1e150;
      nn = N;
      for(j=(k+1);j<(N);j++){
        if(Y[k] != Y[j]){
          tmp = -(X1[k] - X1[j]) / (double)(Y[k] - Y[j]);
          if(nx > tmp){
            nx = tmp;
            nn = j;
          }
        }
      }
    }
    if(d[i] < nx){
      mn[i] = (double)X1[k] + (double)Y[k] * d[i];
    }
    else{
      i--;
      k = nn;
      nn = -1;
      continue;
    }
  }
  k = 0;
  nn = -1;
  while(k+1 < N && Y[k]==Y[k+1] && X2[k] < X2[k+1]){
    k++;
  }
  for(i=(ch)-1;i>=(0);i--){
    if(nn==-1){
      nx = -1e150;
      nn = N;
      for(j=(k+1);j<(N);j++){
        if(Y[k] != Y[j]){
          tmp = -(X2[k] - X2[j]) / (double)(Y[k] - Y[j]);
          if(nx < tmp){
            nx = tmp;
            nn = j;
          }
        }
      }
    }
    if(d[i] > nx){
      mx[i] = (double)X2[k] + (double)Y[k] * d[i];
    }
    else{
      i++;
      k = nn;
      nn = -1;
      continue;
    }
  }
  for(i=(0);i<(ch);i++){
    chmin(res, mx[i] - mn[i]);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// #define EPS 1e-9
// 
// int N;
// int X1[2000], X2[2000], Y[2000];
// 
// int sz;
// double mn[4d6], mx[4d6];
// 
// int ch; double d[4d6];
// 
// {
//   int i, j, k, nn;
//   double res = double_inf, th, nx, tmp;
// 
//   rd(N,(X1,X2,Y)(N));
//   rsortA(N,Y,X1,X2);
// 
//   rep(i,N) rep(j,i+1,N) if(Y[i] != Y[j]){
//     mn[sz] = -(double)(X2[i] - X1[j]) / (Y[i] - Y[j]);
//     mx[sz] = -(double)(X1[i] - X2[j]) / (Y[i] - Y[j]);
//     sz++;
//   }
// 
//   if(sz==0){
//     res = max(X2(N)) - min(X1(N));
//     wt(res);
//     return 0;
//   }
// 
//   sortA(sz, mn, mx);
//   th = mn[0];
//   rep(i,sz){
//     if(th <= mn[i] + EPS){
//       d[ch++] = th;
//       d[ch++] = mn[i];
//     }
//     th >?= mx[i];
//   }
//   d[ch++] = th;
// 
//   k = 0;
//   nn = -1;
//   while(k+1 < N && Y[k]==Y[k+1] && X1[k] > X1[k+1]) k++;
//   rep(i,ch){
//     if(nn==-1){
//       nx = double_inf;
//       nn = N;
//       rep(j,k+1,N) if(Y[k] != Y[j]){
//         tmp = -(X1[k] - X1[j]) / (double)(Y[k] - Y[j]);
//         if(nx > tmp){
//           nx = tmp;
//           nn = j;
//         }
//       }
//     }
//     if(d[i] < nx){
//       mn[i] = (double)X1[k] + (double)Y[k] * d[i];
//     } else {
//       i--;
//       k = nn;
//       nn = -1;
//       continue;
//     }
//   }
// 
//   k = 0;
//   nn = -1;
//   while(k+1 < N && Y[k]==Y[k+1] && X2[k] < X2[k+1]) k++;
//   rrep(i,ch){
//     if(nn==-1){
//       nx = -double_inf;
//       nn = N;
//       rep(j,k+1,N) if(Y[k] != Y[j]){
//         tmp = -(X2[k] - X2[j]) / (double)(Y[k] - Y[j]);
//         if(nx < tmp){
//           nx = tmp;
//           nn = j;
//         }
//       }
//     }
// //    wt(i,d[i],k,X2[k],Y[k]);
//     if(d[i] > nx){
//       mx[i] = (double)X2[k] + (double)Y[k] * d[i];
//     } else {
//       i++;
//       k = nn;
//       nn = -1;
//       continue;
//     }
//   }
// 
// //  rep(i,ch) wt(d[i], mn[i], mx[i]);
//   rep(i,ch) res <?= mx[i] - mn[i];
//   wt(res);
// }