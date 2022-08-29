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
int N;
int M;
int K;
int A[70][70];
int d[36][70];
int mx[70][70];
int dp[70];
int nx[70];
int main(){
  int i;
  int j;
  int k;
  int x;
  rd(N);
  rd(M);
  rd(K);
  {
    int Lj4PdHRW;
    int KL2GvlyY;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      for(KL2GvlyY=(0);KL2GvlyY<(M);KL2GvlyY++){
        rd(A[Lj4PdHRW][KL2GvlyY]);
      }
    }
  }
  x = M/2;
  for(k=(0);k<(N);k++){
    int tU__gIr_;
    for(i=(0);i<(x+1);i++){
      for(j=(0);j<(K);j++){
        d[i][j] = -1073709056;
      }
    }
    d[0][0] = 0;
    for(tU__gIr_=(0);tU__gIr_<(M);tU__gIr_++){
      auto &z = A[k][tU__gIr_];
      for(i=(x)-1;i>=(0);i--){
        for(j=(0);j<(K);j++){
          if(d[i][j] >= 0){
            chmax(d[i+1][(j+z)%K], d[i][j] + z);
          }
        }
      }
    }
    for(j=(0);j<(K);j++){
      mx[k][j] = -1073709056;
    }
    for(i=(0);i<(x+1);i++){
      for(j=(0);j<(K);j++){
        chmax(mx[k][j], d[i][j]);
      }
    }
  }
  for(i=(0);i<(K);i++){
    dp[i] = -1073709056;
  }
  dp[0] = 0;
  for(k=(0);k<(N);k++){
    for(i=(0);i<(K);i++){
      nx[i] = -1073709056;
    }
    for(i=(0);i<(K);i++){
      for(j=(0);j<(K);j++){
        chmax(nx[(i+j)%K], dp[i] + mx[k][j]);
      }
    }
    for(i=(0);i<(K);i++){
      dp[i] = nx[i];
    }
  }
  wt_L(dp[0]);
  wt_L('\n');
  return 0;
}
// cLay varsion 20201115-2

// --- original code ---
// //no-unlocked
// int N, M, K, A[70][70];
// 
// int d[36][70];
// int mx[70][70];
// int dp[70], nx[70];
// {
//   int i, j, k, x;
//   rd(N,M,K,A(N,M));
// 
//   x = M/2;
// 
//   rep(k,N){
//     rep(i,x+1) rep(j,K) d[i][j] = -int_inf;
//     d[0][0] = 0;
//     rep[A[k]](z,M){
//       rrep(i,x) rep(j,K) if(d[i][j] >= 0) d[i+1][(j+z)%K] >?= d[i][j] + z;
//     }
//     rep(j,K) mx[k][j] = -int_inf;
//     rep(i,x+1) rep(j,K) mx[k][j] >?= d[i][j];
//   }
// 
//   rep(i,K) dp[i] = -int_inf;
//   dp[0] = 0;
//   rep(k,N){
//     rep(i,K) nx[i] = -int_inf;
//     rep(i,K) rep(j,K) nx[(i+j)%K] >?= dp[i] + mx[k][j];
//     rep(i,K) dp[i] = nx[i];
//   }
// 
//   wt(dp[0]);
// }