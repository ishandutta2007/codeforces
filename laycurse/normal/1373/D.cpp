#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[200000];
long long dp[4];
long long nx[4];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(4);i++){
      dp[i] = -4611686016279904256LL;
    }
    dp[0] = 0;
    for(i=(0);i<(N);i+=(2)){
      int j;
      for(j=(0);j<(4);j++){
        nx[j] = -4611686016279904256LL;
      }
      chmax(nx[0], dp[0] + A[i]);
      if(i-1 >= 0){
        chmax(nx[1], max_L(dp[0], dp[1])+ A[i-1]);
      }
      if(i+1 <  N){
        chmax(nx[2], max_L(dp[0], dp[2])+ A[i+1]);
      }
      chmax(nx[3], max_L(max_L(dp[1], dp[2]), dp[3])+ A[i]);
      for(j=(0);j<(4);j++){
        dp[j] = nx[j];
      }
    }
    {
      int jZyWAPpY;
      long long jbtyPBGc;
      if(4==0){
        jbtyPBGc = 0;
      }
      else{
        jbtyPBGc = dp[0];
        for(jZyWAPpY=(1);jZyWAPpY<(4);jZyWAPpY++){
          jbtyPBGc = max_L(jbtyPBGc, dp[jZyWAPpY]);
        }
      }
      wt_L(jbtyPBGc);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[2d5];
// ll dp[4], nx[4];
// {
//   REP(rd_int()){
//     rd(N,A(N));
//     rep(i,4) dp[i] = -ll_inf;
//     dp[0] = 0;
//     rep(i,0,N,2){
//       rep(j,4) nx[j] = -ll_inf;
//       nx[0] >?= dp[0] + A[i];
//       if(i-1 >= 0) nx[1] >?= max(dp[0],dp[1]) + A[i-1];
//       if(i+1 <  N) nx[2] >?= max(dp[0],dp[2]) + A[i+1];
//       nx[3] >?= max(dp[1],dp[2],dp[3]) + A[i];
//       rep(j,4) dp[j] = nx[j];
//     }
//     wt(max(dp(4)));
//   }
// }