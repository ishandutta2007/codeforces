#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
template<class T> inline T pow4_L(T a){
  return a*a*a*a;
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
template<class T, class U> inline T LCM_L(T a, U b){
  return a/GCD_L(a,b)*b;
}
int N;
int M;
int A[500][500];
int res[500][500];
int main(){
  int i;
  int k = 1;
  for(i=(0);i<(16);i++){
    k =LCM_L(k, i+1);
  }
  rd(N);
  rd(M);
  {
    int e98WHCEY;
    int cTE1_r3A;
    for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){
      for(cTE1_r3A=(0);cTE1_r3A<(M);cTE1_r3A++){
        rd(A[e98WHCEY][cTE1_r3A]);
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(M);j++){
      if( (i+j)%2==0 ){
        res[i][j] = k;
        continue;
      }
      res[i][j] = k -(pow4_L(A[i][j]));
    }
  }
  {
    int a2conNHc;
    int hCmBdyQB;
    for(a2conNHc=(0);a2conNHc<(N);a2conNHc++){
      if(M==0){
        wt_L('\n');
      }
      else{
        for(hCmBdyQB=(0);hCmBdyQB<(M-1);hCmBdyQB++){
          wt_L(res[a2conNHc][hCmBdyQB]);
          wt_L(' ');
        }
        wt_L(res[a2conNHc][hCmBdyQB]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 2]

// --- original code ---
// //no-unlocked
// int N, M, A[500][500];
// int res[500][500];
// {
//   int k = 1;
//   rep(i,16) k = lcm(k,i+1);
// 
//   rd(N,M,A(N,M));
//   rep(i,N) rep(j,M){
//     if( (i+j)%2==0 ) res[i][j] = k, continue;
//     res[i][j] = k - A[i][j] ** 4;
//   }
//   wt(res(N,M));
// }