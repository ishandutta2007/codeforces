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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
int As;
int Bs;
long long A[200000];
long long B[200000];
long long res[200000];
int main(){
  int i;
  wmem = memarr;
  long long tmp;
  rd(As);
  rd(Bs);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(As);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(Bs);e98WHCEY++){
      rd(B[e98WHCEY]);
    }
  }
  sortA_L(As, A);
  {
    int FmcKpFmN;
    remove_reference<decltype(A[FmcKpFmN]-A[FmcKpFmN-1])>::type xr20shxY;
    int WYIGIcGE = 0;
    if((1) > ((As)-1)){
      xr20shxY = 0;
    }
    else{
      for(FmcKpFmN = 1; FmcKpFmN <= (As)-1; FmcKpFmN++){
        if(WYIGIcGE == 0){
          xr20shxY = A[FmcKpFmN]-A[FmcKpFmN-1];
          WYIGIcGE = 1;
          continue;
        }
        xr20shxY =GCD_L(xr20shxY, A[FmcKpFmN]-A[FmcKpFmN-1]);
      }
    }
    tmp =xr20shxY;
  }
  for(i=(0);i<(Bs);i++){
    res[i] =GCD_L(tmp, A[0]+B[i]);
  }
  {
    int YREPHmFM;
    if(Bs==0){
      wt_L('\n');
    }
    else{
      for(YREPHmFM=(0);YREPHmFM<(Bs-1);YREPHmFM++){
        wt_L(res[YREPHmFM]);
        wt_L(' ');
      }
      wt_L(res[YREPHmFM]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20201229-1

// --- original code ---
// //no-unlocked
// int As, Bs; ll A[2d5], B[2d5], res[2d5];
// {
//   ll tmp;
//   rd(As, Bs, A(As), B(Bs));
//   sortA(As, A);
//   tmp = gcd[i,1,As](A[i]-A[i-1]);
//   rep(i,Bs) res[i] = gcd(tmp, A[0]+B[i]);
//   wt(res(Bs));
// }