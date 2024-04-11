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
int X;
char S[100000+2];
char res[100000+2];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    N = rd(S);
    rd(X);
    for(i=(0);i<(N);i++){
      res[i] = '1';
    }
    res[N] = '\0';
    for(i=(0);i<(N);i++){
      if(S[i]=='0'){
        if(i+X < N){
          res[i+X] = '0';
        }
        if(i-X >=0){
          res[i-X] = '0';
        }
      }
    }
    for(i=(0);i<(N);i++){
      if(i-X >= 0 && res[i-X]=='1' && S[i]=='1'){
        continue;
      }
      if(i+X <  N && res[i+X]=='1' && S[i]=='1'){
        continue;
      }
      if(S[i]=='0'){
        continue;
      }
      wt_L(-1);
      wt_L('\n');
      goto Q5VJL1cS;
    }
    wt_L(res);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N, X;
// char S[1d5+2];
// char res[1d5+2];
// {
//   REP(rd_int()){
//     rd(S@N,X);
//     rep(i,N) res[i] = '1';
//     res[N] = '\0';
//     rep(i,N) if(S[i]=='0'){
//       if(i+X < N) res[i+X] = '0';
//       if(i-X >=0) res[i-X] = '0';
//     }
//     rep(i,N){
//       if(i-X >= 0 && res[i-X]=='1' && S[i]=='1') continue;
//       if(i+X <  N && res[i+X]=='1' && S[i]=='1') continue;
//       if(S[i]=='0') continue;
//       wt(-1);
//       break_continue;
//     }
//     wt(res);
//   }
// }