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
int N;
int Q;
int X;
char S[100000+2];
char C;
int calc(int i){
  if(0 <= i && i+2 < N && S[i]=='a' && S[i+1]=='b' && S[i+2]=='c'){
    return 1;
  }
  return 0;
}
int main(){
  int Q5VJL1cS, i;
  int res = 0;
  rd(N);
  rd(Q);
  rd(S);
  for(i=(0);i<(N);i++){
    res += calc(i);
  }
  for(Q5VJL1cS=(0);Q5VJL1cS<(Q);Q5VJL1cS++){
    rd(X);X += (-1);
    rd(C);
    for(i=(X-2);i<(X+1);i++){
      res -= calc(i);
    }
    S[X] = C;
    for(i=(X-2);i<(X+1);i++){
      res += calc(i);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20211024-1 [beta]

// --- original code ---
// //no-unlocked
// int N, Q, X; char S[1d5+2], C;
// int calc(int i){
//   if(0 <= i && i+2 < N && S[i]=='a' && S[i+1]=='b' && S[i+2]=='c') return 1;
//   return 0;
// }
// {
//   int res = 0;
//   rd(N,Q,S);
//   rep(i,N) res += calc(i);
//   rep(Q){
//     rd(X--,C);
//     rep(i,X-2,X+1) res -= calc(i);
//     S[X] = C;
//     rep(i,X-2,X+1) res += calc(i);
//     wt(res);
//   }
// }