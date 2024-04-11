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
int Q;
int L;
int R;
char S[102];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int cTE1_r3A;
    rd(N);
    rd(Q);
    rd(S);
    for(cTE1_r3A=(0);cTE1_r3A<(Q);cTE1_r3A++){
      int i;
      rd(L);L += (-1);
      rd(R);R += (-1);
      for(i=(0);i<(L);i++){
        if(S[i]==S[L]){
          wt_L("YES");
          wt_L('\n');
          goto RZTsC2BF;
        }
      }
      for(i=(R+1);i<(N);i++){
        if(S[R]==S[i]){
          wt_L("YES");
          wt_L('\n');
          goto RZTsC2BF;
        }
      }
      wt_L("NO");
      wt_L('\n');
      RZTsC2BF:;
    }
  }
  return 0;
}
// cLay version 20201121-1

// --- original code ---
// //no-unlocked
// int N, Q, L, R;
// char S[102];
// {
//   REP(rd_int()){
//     rd(N,Q,S);
//     rep(Q){
//       rd(L--,R--);
//       rep(i,L) if(S[i]==S[L]) wt("YES"), break_continue;
//       rep(i,R+1,N) if(S[R]==S[i]) wt("YES"), break_continue;
//       wt("NO");
//     }
//   }
// }