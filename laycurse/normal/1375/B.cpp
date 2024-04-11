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
int M;
int A[300][300];
int res[300][300];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, j;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      int RZTsC2BF;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        for(RZTsC2BF=(0);RZTsC2BF<(M);RZTsC2BF++){
          rd(A[cTE1_r3A][RZTsC2BF]);
        }
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(M);j++){
        res[i][j] = 4;
      }
    }
    for(i=(0);i<(N);i++){
      res[i][0]--;
      res[i][M-1]--;
    }
    for(j=(0);j<(M);j++){
      res[0][j]--;
      res[N-1][j]--;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(M);j++){
        if(res[i][j] < A[i][j]){
          wt_L("NO");
          wt_L('\n');
          goto Q5VJL1cS;
        }
      }
    }
    wt_L("YES");
    wt_L('\n');
    {
      int AlM5nNnR;
      int XJIcIBrW;
      for(AlM5nNnR=(0);AlM5nNnR<(N);AlM5nNnR++){
        if(M==0){
          wt_L('\n');
        }
        else{
          for(XJIcIBrW=(0);XJIcIBrW<(M-1);XJIcIBrW++){
            wt_L(res[AlM5nNnR][XJIcIBrW]);
            wt_L(' ');
          }
          wt_L(res[AlM5nNnR][XJIcIBrW]);
          wt_L('\n');
        }
      }
    }
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, A[300][300];
// int res[300][300];
// {
//   REP(rd_int()){
//     rd(N,M,A(N,M));
//     rep(i,N) rep(j,M) res[i][j] = 4;
//     rep(i,N) res[i][0]--, res[i][M-1]--;
//     rep(j,M) res[0][j]--, res[N-1][j]--;
//     rep(i,N) rep(j,M) if(res[i][j] < A[i][j]) wt("NO"), break_break_continue;
//     wt("YES");
//     wt(res(N,M));
//   }
// }