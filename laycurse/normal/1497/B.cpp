#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
int N;
int M;
int A[100000];
int h[100000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int res = 0;
    int x;
    int y;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(M);i++){
      h[i] = 0;
    }
    for(i=(0);i<(N);i++){
      h[A[i]%M]++;
    }
    if(h[0]){
      res++;
      h[0] = 0;
    }
    if(M%2==0 && h[M/2]){
      res++;
      h[M/2] = 0;
    }
    for(i=(1);i<(M);i++){
      auto a2conNHc = ((h[i]));
      auto hCmBdyQB = (( h[M-i]));
      x=a2conNHc;
      y=hCmBdyQB;
      auto V9aVTaxx = (0);
      h[i]=V9aVTaxx;
      h[M-i]=V9aVTaxx;
      if(x > y){
        swap(x, y);
      }
      ;
      if(y){
        res +=max_L(1, y-x);
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int N, M, A[1d5], h[1d5];
// {
//   REP(rd_int()){
//     int res = 0, x, y;
//     rd(N,M,A(N));
//     rep(i,M) h[i] = 0;
//     rep(i,N) h[A[i]%M]++;
//     if(h[0]) res++, h[0] = 0;
//     if(M%2==0 && h[M/2]) res++, h[M/2] = 0;
//     rep(i,1,M){
//       (x, y) = (h[i], h[M-i]);
//       (h[i], h[M-i]) = 0;
//       sortE(x,y);
//       if(y) res += max(1, y-x);
//     }
//     wt(res);
//   }
// }