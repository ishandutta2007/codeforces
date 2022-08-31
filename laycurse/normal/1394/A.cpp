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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int D;
int M;
int A[100000];
int xs;
int ys;
long long x[100000];
long long y[100000];
long long sx[100000+1];
long long sy[100000+1];
int main(){
  int i;
  wmem = memarr;
  long long res = 0;
  long long cur = 0;
  long long dame;
  rd(N);
  rd(D);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    if(A[i] <= M){
      x[xs++] = A[i];
    }
  }
  for(i=(0);i<(N);i++){
    if(A[i] >  M){
      y[ys++] = A[i];
    }
  }
  sortA_L(xs, x);
  sortA_L(ys, y);
  for(i=(0);i<(xs);i++){
    sx[i+1] = sx[i] + x[xs-1-i];
  }
  for(i=(0);i<(ys);i++){
    sy[i+1] = sy[i] + y[ys-1-i];
  }
  for(i=(0);i<(ys+1);i++){
    dame = (i-1) * D - (ys-i);
    if(dame < 0){
      dame = 0;
    }
    if(dame > xs){
      break;
    }
    chmax(res, sy[i] + sx[xs - dame]);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, D, M, A[1d5];
// int xs, ys; ll x[1d5], y[1d5];
// ll sx[1d5+1], sy[1d5+1];
// {
//   ll res = 0, cur = 0, dame;
//   rd(N,D,M,A(N));
//   rep(i,N) if(A[i] <= M) x[xs++] = A[i];
//   rep(i,N) if(A[i] >  M) y[ys++] = A[i];
//   sortA(xs, x);
//   sortA(ys, y);
//   rep(i,xs) sx[i+1] = sx[i] + x[xs-1-i];
//   rep(i,ys) sy[i+1] = sy[i] + y[ys-1-i];
// 
//   rep(i,ys+1){
//     dame = (i-1) * D - (ys-i);
//     if(dame < 0) dame = 0;
//     if(dame > xs) break;
//     res >?= sy[i] + sx[xs - dame];
//   }
// 
//   wt(res);
// }