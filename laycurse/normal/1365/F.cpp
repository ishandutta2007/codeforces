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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int A[500];
int B[500];
long long sz;
long long a[500];
long long b[500];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    long long x;
    long long y;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
        rd(B[xr20shxY]);
      }
    }
    sz = (N+1)/2;
    for(i=(0);i<(sz);i++){
      x =min_L(A[i], A[N-1-i]);
      y =max_L(A[i], A[N-1-i]);
      a[i] = x * 2000000000 + y;
      x =min_L(B[i], B[N-1-i]);
      y =max_L(B[i], B[N-1-i]);
      b[i] = x * 2000000000 + y;
    }
    sortA_L(sz, a);
    sortA_L(sz, b);
    for(i=(0);i<(sz);i++){
      if(a[i]!=b[i]){
        wt_L("No");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L("Yes");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[500], B[500];
// ll sz, a[500], b[500];
// {
//   REP(rd_int()){
//     ll x, y;
//     rd(N,A(N),B(N));
//     sz = (N+1)/2;
//     rep(i,sz){
//       x = min(A[i], A[N-1-i]);
//       y = max(A[i], A[N-1-i]);
//       a[i] = x * 2d9 + y;
//       x = min(B[i], B[N-1-i]);
//       y = max(B[i], B[N-1-i]);
//       b[i] = x * 2d9 + y;
//     }
//     sortA(sz, a);
//     sortA(sz, b);
//     rep(i,sz) if(a[i]!=b[i]) wt("No"), break_continue;
//     wt("Yes");
//   }
// }