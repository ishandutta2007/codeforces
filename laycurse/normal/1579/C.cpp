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
int main(){
  int Lj4PdHRW;
  char S[10][21];
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int X;
    rd(X);
    int Y;
    rd(Y);
    int K;
    rd(K);
    int mx;
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(X);cTE1_r3A++){
        rd(S[cTE1_r3A]);
      }
    }
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        if(S[i][j] != '.'){
          mx = 0;
          while(i-mx-1 >= 0 && j-mx-1 >= 0 && j+mx+1 < Y && S[i-mx-1][j-mx-1] != '.' && S[i-mx-1][j+mx+1] != '.'){
            mx++;
          }
          if(mx >= K){
            int k;
            for(k=(0);k<(mx+1);k++){
              S[i-k][j-k] = S[i-k][j+k] = 'o';
            }
          }
        }
      }
    }
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        if(S[i][j] == '*'){
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
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// char S[10][21];
// REP(rd_int()){
//   int @X, @Y, @K, mx;
//   rd(S(X));
//   rep(i,X) rep(j,Y) if(S[i][j] != '.'){
//     mx = 0;
//     while(i-mx-1 >= 0 && j-mx-1 >= 0 && j+mx+1 < Y && S[i-mx-1][j-mx-1] != '.' && S[i-mx-1][j+mx+1] != '.') mx++;
//     if(mx >= K) rep(k,mx+1) S[i-k][j-k] = S[i-k][j+k] = 'o';
//   }
//   rep(i,X) rep(j,Y) if(S[i][j] == '*') wt("NO"), break_break_continue;
//   wt("YES");
// }