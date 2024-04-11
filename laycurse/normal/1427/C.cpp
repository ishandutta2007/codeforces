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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int R;
int N;
int T[100000+1];
int X[100000+1];
int Y[100000+1];
int dp[100000+1];
int mx[100000+1];
int main(){
  int i;
  int t;
  int d;
  rd(R);
  rd(N);N += (1);
  for(i=(1);i<(N);i++){
    rd(T[i]);
    rd(X[i]);X[i] += (-1);
    rd(Y[i]);Y[i] += (-1);
  }
  for(i=(1);i<(N);i++){
    dp[i] = -1073709056;
  }
  for(i=(0);i<(N);i++){
    mx[i] = -1073709056;
  }
  for(i=(0);i<(N);i++){
    int j;
    if(i){
      chmax(mx[i], mx[i-1]);
    }
    chmax(dp[i], mx[i]);
    for(j=(i+1);j<(N);j++){
      t = T[j] - T[i];
      if(t >= 1000){
        chmax(mx[j], dp[i] + 1);
        break;
      }
      d = abs(X[i]-X[j]) + abs(Y[i]-Y[j]);
      if(t >= d){
        chmax(dp[j], dp[i] + 1);
      }
    }
  }
  {
    int KrdatlYV;
    int ao_dF3pO;
    if(N==0){
      ao_dF3pO = 0;
    }
    else{
      ao_dF3pO = dp[0];
      for(KrdatlYV=(1);KrdatlYV<(N);KrdatlYV++){
        ao_dF3pO = max_L(ao_dF3pO, dp[KrdatlYV]);
      }
    }
    wt_L(ao_dF3pO);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20201003-1

// --- original code ---
// //no-unlocked
// int R, N, T[1d5+1], X[1d5+1], Y[1d5+1];
// int dp[1d5+1], mx[1d5+1];
// {
//   int t, d;
//   rd(R,N++);
//   rep(i,1,N) rd(T[i],X[i]--,Y[i]--);
//   rep(i,1,N) dp[i] = -int_inf;
//   rep(i,N) mx[i] = -int_inf;
//   rep(i,N){
//     if(i) mx[i] >?= mx[i-1];
//     dp[i] >?= mx[i];
//     rep(j,i+1,N){
//       t = T[j] - T[i];
//       if(t >= 1000) mx[j] >?= dp[i] + 1, break;
//       d = abs(X[i]-X[j]) + abs(Y[i]-Y[j]);
//       if(t >= d) dp[j] >?= dp[i] + 1;
//     }
//   }
//   wt(max(dp(N)));
// }