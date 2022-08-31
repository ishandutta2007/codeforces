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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
char A[1000][1002];
char B[1000][1002];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, j;
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
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        {
          auto hCmBdyQB = ('0');
          A[i][j] -= hCmBdyQB;
          B[i][j] -= hCmBdyQB;
        }
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        A[i][j] ^= B[i][j];
      }
    }
    for(i=(0);i<(N);i++){
      if(A[i][0]){
        int j;
        for(j=(0);j<(N);j++){
          A[i][j] ^= 1;
        }
      }
    }
    for(j=(0);j<(N);j++){
      if(A[0][j]){
        for(i=(0);i<(N);i++){
          A[i][j] ^= 1;
        }
      }
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(N);j++){
        if(A[i][j]){
          wt_L("NO");
          wt_L('\n');
          goto Q5VJL1cS;
        }
      }
    }
    wt_L("YES");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// int N;
// char A[1000][1002], B[1000][1002];
// {
//   REP(rd_int()){
//     rd(N,A(N),B(N));
//     rep(i,N) rep(j,N) (A[i][j], B[i][j]) -= '0';
//     rep(i,N) rep(j,N) A[i][j] ^= B[i][j];
//     rep(i,N) if(A[i][0]) rep(j,N) A[i][j] ^= 1;
//     rep(j,N) if(A[0][j]) rep(i,N) A[i][j] ^= 1;
//     rep(i,N) rep(j,N) if(A[i][j]) wt("NO"), break_break_continue;
//     wt("YES");
//   }
// }