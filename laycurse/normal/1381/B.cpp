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
int P[4001];
int dp[2001];
void doit(int k){
  int i;
  if(!k){
    return;
  }
  for(i=(N+1)-1;i>=(k);i--){
    dp[i] |= dp[i-k];
  }
}
int main(){
  int Q5VJL1cS;
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int i;
    int mx = -1;
    int c = 0;
    rd(N);
    {
      int FmcKpFmN;
      for(FmcKpFmN=(0);FmcKpFmN<(2*N);FmcKpFmN++){
        rd(P[FmcKpFmN]);
      }
    }
    for(i=(0);i<(N+1);i++){
      dp[i] = 0;
    }
    dp[0] = 1;
    for(i=(0);i<(2*N+1);i++){
      if(i == 2*N || mx < P[i]){
        doit(i - c);
        c = i;
        mx = P[i];
      }
    }
    if(dp[N]){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, P[4001];
// int dp[2001];
// 
// void doit(int k){
//   if(!k) return;
//   rrep(i,k,N+1) dp[i] |= dp[i-k];
// }
// 
// {
//   REP(rd_int()){
//     int mx = -1, c = 0;
//     rd(N,P(2*N));
// 
//     rep(i,N+1) dp[i] = 0;
//     dp[0] = 1;
// 
//     rep(i,2*N+1) if(i == 2*N || mx < P[i]){
//       doit(i - c);
//       c = i;
//       mx = P[i];
//     }
// 
//     wt(if[dp[N], "YES", "NO"]);
//   }
// }