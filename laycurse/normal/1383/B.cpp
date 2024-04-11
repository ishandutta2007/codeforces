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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int A[100000];
int solve(int on, int zr, int my, int op){
  if(on==0){
    return my;
  }
  if(on && solve(on-1, zr, op, my^1)==0){
    return 1;
  }
  if(zr && solve(on, zr-1, op, my)==0){
    return 1;
  }
  return 0;
}
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int sm = 0;
    int bt;
    int zr = 0;
    int on = 0;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      sm ^= A[i];
    }
    if(sm==0){
      wt_L("DRAW");
      wt_L('\n');
      continue;
    }
    for(bt=(30)-1;bt>=(0);bt--){
      if(sm & 1<<bt){
        break;
      }
    }
    for(i=(0);i<(N);i++){
      if(A[i] & 1<<bt){
        on++;
      }
      else{
        zr++;
      }
    }
    on %= 4;
    zr %= 2;
    if(on==1 || zr==1){
      wt_L("WIN");
      wt_L('\n');
    }
    else{
      wt_L("LOSE");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// 
// int solve(int on, int zr, int my, int op){
//   if(on==0) return my;
//   if(on && solve(on-1, zr, op, my^1)==0) return 1;
//   if(zr && solve(on, zr-1, op, my)==0) return 1;
//   return 0;
// }
// 
// {
// //  rep(i,1,15,2) rep(j,15) wt(i,j,solve(i,j,0,0));
// //  return 0;
// 
//   REP(rd_int()){
//     int sm = 0, bt, zr = 0, on = 0;
//     rd(N,A(N));
//     rep(i,N) sm ^= A[i];
//     if(sm==0) wt("DRAW"), continue;
//     rrep(bt,30) if(sm & 1<<bt) break;
//     rep(i,N) if[A[i] & 1<<bt, on, zr]++;
//     on %= 4;
//     zr %= 2;
//     wt(if[on==1 || zr==1, "WIN", "LOSE"]);
//   }
// }