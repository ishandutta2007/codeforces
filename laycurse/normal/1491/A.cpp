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
template<class T, class S> int arrCountVal(int N, T A[], S val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
int N;
int Q;
int T;
int K;
int A[100000];
int one;
int zero;
int main(){
  int e98WHCEY;
  rd(N);
  rd(Q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  one = arrCountVal(N,A,1);
  zero = N - one;
  for(e98WHCEY=(0);e98WHCEY<(Q);e98WHCEY++){
    rd(T);
    rd(K);K += (-1);
    if(T==1){
      if(A[K]==1){
        one--;
      }
      else{
        zero--;
      }
      A[K] ^= 1;
      if(A[K]==1){
        one++;
      }
      else{
        zero++;
      }
    }
    else{
      if(K < one){
        wt_L(1);
        wt_L('\n');
      }
      else{
        wt_L(0);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int N, Q, T, K, A[1d5];
// int one, zero;
// {
//   rd(N,Q,A(N));
//   one = arrCountVal(N,A,1);
//   zero = N - one;
//   rep(Q){
//     rd(T, K--);
//     if(T==1){
//       if[A[K]==1, one, zero]--;
//       A[K] ^= 1;
//       if[A[K]==1, one, zero]++;
//     } else {
//       wt(if[K < one, 1, 0]);
//     }
//   }
// }