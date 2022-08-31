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
template<class T, class S> T inline fDiv(T a, S b){
  T m;
  if(b < 0){
    a = -a;
    b = -b;
  }
  m = a % b;
  if(m == 0){
    return a / b;
  }
  if(m < 0){
    m += b;
  }
  return (a - m) / b;
}
int K;
int N;
int P;
char S[1000000];
char C;
int dp[1000000];
void calc(int i){
  dp[i] = 0;
  if(S[i] != '0'){
    dp[i] += dp[2*i+1];
  }
  if(S[i] != '1'){
    dp[i] += dp[2*i+2];
  }
}
int main(){
  int cTE1_r3A, i;
  rd(K);
  rd(S);
  N = 1<<K;
  reverse(S,S+N-1);
  for(i=(N-1);i<(2*N);i++){
    dp[i] = 1;
  }
  for(i=(N-1)-1;i>=(0);i--){
    calc(i);
  }
  int RZTsC2BF = rd_int();
  for(cTE1_r3A=(0);cTE1_r3A<(RZTsC2BF);cTE1_r3A++){
    rd(P);
    rd(C);
    P = N-1-P;
    S[P] = C;
    while(P >= 0){
      calc(P);
      P = fDiv(P-1, 2);
    }
    wt_L(dp[0]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210607-1

// --- original code ---
// //no-unlocked
// int K, N, P;
// char S[1d6], C;
// int dp[];
// 
// void calc(int i){
//   dp[i] = 0;
//   if(S[i] != '0') dp[i] += dp[2*i+1];
//   if(S[i] != '1') dp[i] += dp[2*i+2];
// }
// 
// {
//   rd(K,S);
//   N = 1<<K;
//   reverse(S,S+N-1);
//   rep(i,N-1,2*N) dp[i] = 1;
//   rrep(i,N-1) calc(i);
//   REP(rd_int()){
//     rd(P,C);
//     P = N-1-P;
//     S[P] = C;
//     while(P >= 0){
//       calc(P);
//       P = fDiv(P-1, 2);
//     }
//     wt(dp[0]);
//   }
// }