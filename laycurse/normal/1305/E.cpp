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
int N;
int M;
int A[5000];
int main(){
  int i;
  int j;
  int k;
  rd(N);
  rd(M);
  for(i=(0);i<(N);i++){
    A[N-1-i] = 1000000000 - 100000 * i;
  }
  for(i=(0);i<(N);i++){
    k = i / 2;
    if(M >= k){
      M -= k;
      A[i] = i+1;
      continue;
    }
    A[i] = i + 1 + 2 * (k - M);
    M = 0;
    break;
  }
  if(M){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  {
    int cTE1_r3A;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(cTE1_r3A=(0);cTE1_r3A<(N-1);cTE1_r3A++){
        wt_L(A[cTE1_r3A]);
        wt_L(' ');
      }
      wt_L(A[cTE1_r3A]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200303-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M;
// int A[5000];
// {
//   int i, j, k;
//   rd(N,M);
//   rep(i,N) A[N-1-i] = 1d9 - 1d5 * i;
//   rep(i,N){
//     k = i / 2;
//     if(M >= k){
//       M -= k;
//       A[i] = i+1;
//       continue;
//     }
//     A[i] = i + 1 + 2 * (k - M);
//     M = 0;
//     break;
//   }
//   if(M) wt(-1), return 0;
//   wt(A(N));
// }