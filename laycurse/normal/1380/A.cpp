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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int A[1000];
int x[1000];
int y[1000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      x[i] = y[i] = i;
    }
    for(i=(1);i<(N);i++){
      if(A[x[i-1]] < A[x[i]]){
        x[i] = x[i-1];
      }
    }
    for(i=(N-1)-1;i>=(0);i--){
      if(A[y[i+1]] < A[y[i]]){
        y[i] = y[i+1];
      }
    }
    for(i=(1);i<(N-1);i++){
      if(A[x[i-1]] < A[i] && A[i] > A[y[i+1]]){
        wt_L("YES");
        wt_L('\n');
        wt_L(x[i-1]+1);
        wt_L(' ');
        wt_L(i+1);
        wt_L(' ');
        wt_L(y[i+1]+1);
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[1000];
// int x[1000], y[1000];
// {
//   REP(rd_int()){
//     rd(N,A(N));
//     rep(i,N) x[i] = y[i] = i;
//     rep(i,1,N) if(A[x[i-1]] < A[x[i]]) x[i] = x[i-1];
//     rrep(i,N-1) if(A[y[i+1]] < A[y[i]]) y[i] = y[i+1];
// 
//     rep(i,1,N-1) if(A[x[i-1]] < A[i] && A[i] > A[y[i+1]]){
//       wt("YES");
//       wt(x[i-1]+1, i+1, y[i+1]+1);
//       break_continue;
//     }
//     wt("NO");
//   }
// }