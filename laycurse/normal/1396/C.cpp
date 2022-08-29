#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
inline void rd(long long &x){
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
long long R1;
long long R2;
long long R3;
long long D;
long long A[1000000];
long long dp[1000000+1];
long long one[1000000];
long long two[1000000];
int main(){
  int i;
  rd(N);
  rd(R1);
  rd(R2);
  rd(R3);
  rd(D);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  chmin(R1, R3);
  for(i=(0);i<(N);i++){
    one[i] = A[i] * R1 + R3;
  }
  for(i=(0);i<(N);i++){
    two[i] =min_L(min_L(R2 + R1, R1 * (A[i]+2)), one[i]);
  }
  for(i=(1);i<(N+2);i++){
    dp[i] = 4611686016279904256LL;
  }
  for(i=(0);i<(N);i++){
    if(i+1==N){
      chmin(dp[i+1], dp[i] + one[i] +0);
    }
    else{
      chmin(dp[i+1], dp[i] + one[i] +D);
    }
    if(i+1==N){
      chmin(dp[i+1], dp[i] + two[i] + 2 * D +0);
    }
    else{
      chmin(dp[i+1], dp[i] + two[i] + 2 * D +D);
    }
    if(i+1 < N){
      if(i+2==N){
        chmin(dp[i+2], dp[i] + two[i] + two[i+1] + 3 * D +0);
      }
      else{
        chmin(dp[i+2], dp[i] + two[i] + two[i+1] + 3 * D +D);
      }
      if(i+2==N){
        chmin(dp[i+2], dp[i] + two[i] + one[i+1] + 2 * D);
      }
    }
  }
  wt_L(dp[N]);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N; ll R1, R2, R3, D, A[1d6];
// ll dp[1d6+1], one[1d6], two[1d6];
// {
//   rd(N,R1,R2,R3,D,A(N));
//   R1 <?= R3;
// 
//   rep(i,N) one[i] = A[i] * R1 + R3;
//   rep(i,N) two[i] = min(R2 + R1, R1 * (A[i]+2), one[i]);
// 
//   rep(i,1,N+2) dp[i] = ll_inf;
//   rep(i,N){
//     dp[i+1] <?= dp[i] + one[i] + if[i+1==N, 0, D];
//     dp[i+1] <?= dp[i] + two[i] + 2 * D + if[i+1==N, 0, D];
//     if(i+1 < N){
//       dp[i+2] <?= dp[i] + two[i] + two[i+1] + 3 * D + if[i+2==N, 0, D];
//       if(i+2==N) dp[i+2] <?= dp[i] + two[i] + one[i+1] + 2 * D;
//     }
//   }
//   wt(dp[N]);
// }