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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
long long K;
long long L[2000];
long long R[2000];
long long A[2000];
long long dp[2001];
int main(){
  int i;
  long long t;
  long long r;
  long long us;
  long long em;
  long long d;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(L[Lj4PdHRW]);
      rd(R[Lj4PdHRW]);
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(1);i<(N+1);i++){
    dp[i] = 4611686016279904256LL;
  }
  for(i=(0);i<(N);i++){
    int j;
    {
      auto xr20shxY = (0);
      auto WYIGIcGE = ( K);
      auto t_ynMSdg = ( 0);
      auto KrdatlYV = ( 0);
      t = xr20shxY;
      r = WYIGIcGE;
      us = t_ynMSdg;
      em = KrdatlYV;
    }
    for(j=(i);j<(N);j++){
      chmax(t, L[j]);
      em += A[j];
      d =min_L(em, r);
      {
        auto hCmBdyQB = (d);
        em -= hCmBdyQB;
        r -= hCmBdyQB;
      }
      us += d;
      d =(divup_L(em,K));
      t += d;
      r += d*K;
      d =min_L(em, r);
      {
        auto APIVbQlN = (d);
        em -= APIVbQlN;
        r -= APIVbQlN;
      }
      us += d;
      if(t > R[j]){
        break;
      }
      if(j==N-1 && t <= R[j]){
        chmin(dp[j+1], dp[i] + us);
      }
      if(j!=N-1 && t+1 <= L[j+1]){
        chmin(dp[j+1], dp[i] + us + r);
      }
    }
  }
  if(dp[N]==4611686016279904256LL){
    wt_L(-1);
    wt_L('\n');
  }
  else{
    wt_L(dp[N]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20201102-1

// --- original code ---
// //no-unlocked
// int N; ll K, L[2000], R[2000], A[2000];
// ll dp[2001];
// {
//   ll t, r, us, em, d;
//   rd(N,K,(L,R,A)(N));
//   rep(i,1,N+1) dp[i] = ll_inf;
// 
//   rep(i,N){
//     (t, r, us, em) = (0, K, 0, 0);
//     rep(j,i,N){
//       t >?= L[j];
//       em += A[j];
//       d = min(em, r);
//       (em, r) -= d;
//       us += d;
// 
//       d = em /+ K;
//       t += d;
//       r += d*K;
//       d = min(em, r);
//       (em, r) -= d;
//       us += d;
// 
//       if(t > R[j]) break;
//       if(j==N-1 && t <= R[j]) dp[j+1] <?= dp[i] + us;
//       if(j!=N-1 && t+1 <= L[j+1]) dp[j+1] <?= dp[i] + us + r;
//     }
//   }
// 
//   wt(if[dp[N]==ll_inf, -1, dp[N]]);
// }