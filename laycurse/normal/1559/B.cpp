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
template<class T, class T1, class T2> inline void swapV(T &a, T1 x, T2 y){
  if(a == x){
    a = y;
  }
  else if(a == y){
    a = x;
  }
}
int N;
char S[102];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(S);
    for(i=(1);i<(N);i++){
      if(S[i]=='?' && S[i-1]!='?'){
        S[i] = S[i-1];
        swapV(S[i], 'B', 'R');
      }
    }
    for(i=(N)-1;i>=(1);i--){
      if(S[i-1]=='?' && S[i]!='?'){
        S[i-1] = S[i];
        swapV(S[i-1], 'B', 'R');
      }
    }
    for(i=(0);i<(N);i++){
      if(S[i]=='?'){
        if(i%2==0){
          S[i] ='B';
        }
        else{
          S[i] ='R';
        }
      }
    }
    wt_L(S);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210814-1

// --- original code ---
// //no-unlocked
// int N;
// char S[102];
// {
//   REP(rd_int()){
//     rd(N,S);
//     rep(i,1,N) if(S[i]=='?' && S[i-1]!='?'){
//       S[i] = S[i-1];
//       swapV(S[i], 'B', 'R');
//     }
//     rrep(i,1,N) if(S[i-1]=='?' && S[i]!='?'){
//       S[i-1] = S[i];
//       swapV(S[i-1], 'B', 'R');
//     }
//     rep(i,N) if(S[i]=='?'){
//       S[i] = if[i%2==0, 'B', 'R'];
//     }
//     wt(S);
//   }
// }