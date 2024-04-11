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
int M;
char S[1002];
char nx[1002];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int cTE1_r3A;
    rd(N);
    rd(M);
    rd(S);
    for(cTE1_r3A=(0);cTE1_r3A<(M);cTE1_r3A++){
      int i;
      int fg = 0;
      int k;
      for(i=(0);i<(N);i++){
        nx[i] = S[i];
      }
      for(i=(0);i<(N);i++){
        if(S[i]=='0'){
          k = 0;
          if(i-1 >= 0 && nx[i-1] == '1'){
            k++;
          }
          if(i+1 <  N && nx[i+1] == '1'){
            k++;
          }
          if(k==1){
            fg++;
            S[i] = '1';
          }
        }
      }
      if(!fg){
        break;
      }
    }
    wt_L(S);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210607-1

// --- original code ---
// //no-unlocked
// int N, M;
// char S[1002], nx[1002];
// {
//   REP(rd_int()){
//     rd(N,M,S);
//     rep(M){
//       int fg = 0, k;
//       rep(i,N) nx[i] = S[i];
//       rep(i,N) if(S[i]=='0'){
//         k = 0;
//         if(i-1 >= 0 && nx[i-1] == '1') k++;
//         if(i+1 <  N && nx[i+1] == '1') k++;
//         if(k==1) fg++, S[i] = '1';
//       }
//       if(!fg) break;
//     }
//     wt(S);
//   }
// }