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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
char X[200000+2];
char Y[200000+2];
int main(){
  int i;
  int A;
  rd(A);
  int B;
  rd(B);
  int K;
  rd(K);
  int rm = B-2;
  if(A==0 || B==1){
    int i;
    if(K){
      wt_L("No");
      wt_L('\n');
      return 0;
    }
    for(i=(0);i<(B);i++){
      X[i] = Y[i] = '1';
    }
    for(i=(0);i<(A);i++){
      X[B+i] = Y[B+i] = '0';
    }
    wt_L("Yes");
    wt_L('\n');
    wt_L(X);
    wt_L('\n');
    wt_L(Y);
    wt_L('\n');
    return 0;
  }
  if(A+B-2 < K){
    wt_L("No");
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(A+B);i++){
    X[i] = Y[i] = '0';
  }
  X[0] = Y[0] = '1';
  X[1] = Y[1+K] = '1';
  for(i=(1);i<(A+B);i++){
    if(rm && X[i]==Y[i] && Y[i]=='0'){
      rm--;
      X[i] = Y[i] = '1';
    }
  }
  wt_L("Yes");
  wt_L('\n');
  wt_L(X);
  wt_L('\n');
  wt_L(Y);
  wt_L('\n');
  return 0;
}
// cLay version 20210223-1

// --- original code ---
// //no-unlocked
// char X[2d5+2], Y[];
// {
//   int @A, @B, @K, rm = B-2;
//   if(A==0 || B==1){
//     if(K) wt("No"), return 0;
//     rep(i,B) X[i] = Y[i] = '1';
//     rep(i,A) X[B+i] = Y[B+i] = '0';
//     wtLn("Yes", X, Y);
//     return 0;
//   }
//   if(A+B-2 < K) wt("No"), return 0;
//   rep(i,A+B) X[i] = Y[i] = '0';
//   X[0] = Y[0] = '1';
//   X[1] = Y[1+K] = '1';
//   rep(i,1,A+B) if(rm && X[i]==Y[i]=='0') rm--, X[i] = Y[i] = '1';
//   wtLn("Yes", X, Y);
// }