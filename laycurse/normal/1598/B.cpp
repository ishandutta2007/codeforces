#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int N;
    rd(N);
    int A[N][5];
    {
      int cTE1_r3A;
      int RZTsC2BF;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        for(RZTsC2BF=(0);RZTsC2BF<(5);RZTsC2BF++){
          rd(A[cTE1_r3A][RZTsC2BF]);
        }
      }
    }
    int x;
    int y;
    int z;
    for(i=(0);i<(5);i++){
      int j;
      for(j=(i+1);j<(5);j++){
        int k;
        x = y = z = 0;
        for(k=(0);k<(N);k++){
          if(A[k][i] && A[k][j]){
            z++;
          }
          else if(A[k][i]){
            x++;
          }
          else if(A[k][j]){
            y++;
          }
          else{
            ;
          }
        }
        if(x+y+z == N && x+z >= N/2 && y+z >= N/2){
          wt_L("YES");
          wt_L('\n');
          goto Q5VJL1cS;
        }
      }
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N, @A[N][5];
//   int x, y, z;
//   rep(i,5) rep(j,i+1,5){
//     x = y = z = 0;
//     rep(k,N) if[A[k][i] && A[k][j], z++, A[k][i], x++, A[k][j], y++];
//     if(x+y+z == N && x+z >= N/2 && y+z >= N/2) wt("YES"), break_break_continue;
//   }
//   wt("NO");
// }