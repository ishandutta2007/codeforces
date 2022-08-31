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
char S[1002];
int N;
int a[1001];
int b[1001];
int M;
int res[1002];
int main(){
  int i, j;
  N = rd(S);
  for(i=(0);i<(N);i++){
    if(S[i]=='('){
      a[i+1] = a[i] +1;
    }
    else{
      a[i+1] = a[i] +0;
    }
  }
  for(i=(0);i<(N);i++){
    if(S[N-1-i]==')'){
      b[i+1] = b[i] +1;
    }
    else{
      b[i+1] = b[i] +0;
    }
  }
  for(i=(0);i<(N+1);i++){
    if(a[i]==b[N-i] && b[N-i]==0){
      wt_L(0);
      wt_L('\n');
      return 0;
    }
  }
  for(i=(0);i<(N+1);i++){
    if(a[i]==b[N-i]){
      break;
    }
  }
  for(j=(0);j<(i);j++){
    if(S[j]=='('){
      res[M++] = j;
    }
  }
  for(j=(i);j<(N);j++){
    if(S[j]==')'){
      res[M++] = j;
    }
  }
  wt_L(1);
  wt_L('\n');
  wt_L(M);
  wt_L('\n');
  {
    int tU__gIr_;
    if(M==0){
      wt_L('\n');
    }
    else{
      for(tU__gIr_=(0);tU__gIr_<(M-1);tU__gIr_++){
        wt_L(res[tU__gIr_]+1);
        wt_L(' ');
      }
      wt_L(res[tU__gIr_]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200303-1 [beta]

// --- original code ---
// //no-unlocked
// char S[1002];
// int N;
// 
// int a[1001], b[1001];
// int M, res[1002];
// {
//   rd(S@N);
//   rep(i,N) a[i+1] = a[i] + if[S[i]=='(', 1, 0];
//   rep(i,N) b[i+1] = b[i] + if[S[N-1-i]==')', 1, 0];
//   rep(i,N+1) if(a[i]==b[N-i]==0) wt(0), return 0;
//   rep(i,N+1) if(a[i]==b[N-i]) break;
//   rep(j,i) if(S[j]=='(') res[M++] = j;
//   rep(j,i,N) if(S[j]==')') res[M++] = j;
//   wt(1);
//   wt(M);
//   wt(res(M)+1);
// }