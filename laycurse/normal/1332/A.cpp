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
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int A;
    int B;
    int C;
    int D;
    int X;
    int Y;
    int X1;
    int Y1;
    int X2;
    int Y2;
    rd(A);
    rd(B);
    rd(C);
    rd(D);
    rd(X);
    rd(Y);
    rd(X1);
    rd(Y1);
    rd(X2);
    rd(Y2);
    if(X1==X2 && A+B){
      wt_L("No");
      wt_L('\n');
      continue;
    }
    if(Y1==Y2 && C+D){
      wt_L("No");
      wt_L('\n');
      continue;
    }
    if(X1 <= X+B-A  &&  X+B-A <= X2 && Y1 <= Y+D-C  &&  Y+D-C <= Y2){
      wt_L("Yes");
      wt_L('\n');
    }
    else{
      wt_L("No");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200322-1 [beta]

// --- original code ---
// //no-unlocked
// {
//   REP(rd_int()){
//     int A,B,C,D,X,Y,X1,Y1,X2,Y2;
//     rd(A,B,C,D,X,Y,X1,Y1,X2,Y2);
//     if(X1==X2 && A+B) wt("No"), continue;
//     if(Y1==Y2 && C+D) wt("No"), continue;
//     wt(if[X1 <= X+B-A <= X2 && Y1 <= Y+D-C <= Y2, "Yes", "No"]);
//   }
// }