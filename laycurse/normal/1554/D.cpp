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
char res[100000+2];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int N;
    rd(N);
    int k;
    int s;
    if(N <= 26){
      int i;
      for(i=(0);i<(N);i++){
        res[i] = 'a' + i;
      }
    }
    else{
      int i;
      k = (N-3) / 2;
      s = 0;
      for(i=(0);i<(k);i++){
        res[s++] = 'z';
      }
      res[s++] = 'y';
      for(i=(0);i<(k+1);i++){
        res[s++] = 'z';
      }
      for(i=(0);i<(24);i++){
        if(s < N){
          res[s++] = 'a' + i;
        }
      }
    }
    res[N] = '\0';
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// char res[1d5+2];
// {
//   REP(rd_int()){
//     int @N, k, s;
//     if(N <= 26){
//       rep(i,N) res[i] = 'a' + i;
//     } else {
//       k = (N-3) / 2;
//       s = 0;
//       rep(i,k) res[s++] = 'z';
//       res[s++] = 'y';
//       rep(i,k+1) res[s++] = 'z';
//       rep(i,24) if(s < N) res[s++] = 'a' + i;
//     }
//     res[N] = '\0';
//     wt(res);
//   }
// }