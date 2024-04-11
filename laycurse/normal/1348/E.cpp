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
int K;
int A[500];
int B[500];
int dp[500];
int nx[500];
int main(){
  int i;
  int j;
  int x;
  int y;
  long long res = 0;
  long long tmp = 0;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
      rd(B[Lj4PdHRW]);
    }
  }
  dp[0] = 1;
  for(i=(0);i<(N);i++){
    for(j=(0);j<(K);j++){
      nx[j] = 0;
    }
    for(x=(0);x<(K);x++){
      y = (A[i] + B[i] - x) % K;
      if(x > A[i] || y > B[i]){
        continue;
      }
      for(j=(0);j<(K);j++){
        if(dp[j]){
          nx[(j+x)%K] = 1;
        }
      }
    }
    for(j=(0);j<(K);j++){
      dp[j] = nx[j];
    }
  }
  for(i=(0);i<(N);i++){
    tmp += A[i] + B[i];
  }
  for(x=(0);x<(K);x++){
    if(dp[x]){
      chmax(res, (tmp - x) / K);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, K, A[500], B[500];
// int dp[500], nx[500];
// {
//   int i, j, x, y;
//   ll res = 0, tmp = 0;
//   rd(N,K,(A,B)(N));
//   dp[0] = 1;
//   rep(i,N){
//     rep(j,K) nx[j] = 0;
//     rep(x,K){
//       y = (A[i] + B[i] - x) % K;
//       if(x > A[i] || y > B[i]) continue;
//       rep(j,K) if(dp[j]) nx[(j+x)%K] = 1;
//     }
//     rep(j,K) dp[j] = nx[j];
//   }
//   rep(i,N) tmp += A[i] + B[i];
//   rep(x,K) if(dp[x]) res >?= (tmp - x) / K;
//   wt(res);
// }