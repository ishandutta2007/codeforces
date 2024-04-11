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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int M;
long long A[100][100];
long long dp[100][100];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, x;
    long long res = 4611686016279904256LL;
    long long v;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      int RZTsC2BF;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        for(RZTsC2BF=(0);RZTsC2BF<(M);RZTsC2BF++){
          rd(A[cTE1_r3A][RZTsC2BF]);
        }
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(M);j++){
        A[i][j] -= i+j;
      }
    }
    for(x=(0);x<(N);x++){
      int y;
      for(y=(0);y<(M);y++){
        int j;
        v = A[x][y];
        for(i=(0);i<(N);i++){
          int j;
          for(j=(0);j<(M);j++){
            dp[i][j] = 4611686016279904256LL;
          }
        }
        if(A[0][0] >= v){
          chmin(dp[0][0], A[0][0] - v);
        }
        for(i=(1);i<(N);i++){
          if(A[i][0] >= v){
            chmin(dp[i][0], dp[i-1][0] + A[i][0] - v);
          }
        }
        for(j=(1);j<(M);j++){
          if(A[0][j] >= v){
            chmin(dp[0][j], dp[0][j-1] + A[0][j] - v);
          }
        }
        for(i=(1);i<(N);i++){
          for(j=(1);j<(M);j++){
            if(A[i][j] >= v){
              chmin(dp[i][j], min_L(dp[i-1][j], dp[i][j-1])+ A[i][j] - v);
            }
          }
        }
        chmin(res, dp[N-1][M-1]);
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M;
// ll A[100][100], dp[100][100];
// 
// {
//   REP(rd_int()){
//     ll res = ll_inf, v;
//     rd(N,M,A(N,M));
//     rep(i,N) rep(j,M) A[i][j] -= i+j;
//     rep(x,N) rep(y,M){
//       v = A[x][y];
//       rep(i,N) rep(j,M) dp[i][j] = ll_inf;
//       if(A[0][0] >= v) dp[0][0] <?= A[0][0] - v;
//       rep(i,1,N) if(A[i][0] >= v) dp[i][0] <?= dp[i-1][0] + A[i][0] - v;
//       rep(j,1,M) if(A[0][j] >= v) dp[0][j] <?= dp[0][j-1] + A[0][j] - v;
//       rep(i,1,N) rep(j,1,M) if(A[i][j] >= v) dp[i][j] <?= min(dp[i-1][j], dp[i][j-1]) + A[i][j] - v;
//       res <?= dp[N-1][M-1];
//     }
//     wt(res);
//   }
// }