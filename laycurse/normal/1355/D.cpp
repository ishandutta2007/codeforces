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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int S;
int A[1000000];
int main(){
  int i;
  rd(N);
  rd(S);
  for(i=(0);i<(N);i++){
    A[i] = 1;
  }
  A[N-1] = S - (N-1);
  if(A[N-1] > N){
    wt_L("YES");
    wt_L('\n');
    {
      int Q5VJL1cS;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(Q5VJL1cS=(0);Q5VJL1cS<(N-1);Q5VJL1cS++){
          wt_L(A[Q5VJL1cS]);
          wt_L(' ');
        }
        wt_L(A[Q5VJL1cS]);
        wt_L('\n');
      }
    }
    wt_L(N);
    wt_L('\n');
  }
  else{
    wt_L("NO");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, S;
// int A[1d6];
// {
//   rd(N,S);
//   rep(i,N) A[i] = 1;
//   A[N-1] = S - (N-1);
//   if(A[N-1] > N){
//     wt("YES");
//     wt(A(N));
//     wt(N);
//   } else {
//     wt("NO");
//   }
// }