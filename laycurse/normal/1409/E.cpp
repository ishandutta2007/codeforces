#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
long long K;
int X[200000];
int Y[200000];
int dp[200000+1];
int dp1[200000+1];
int dp2[200000+1];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int loop;
    int i;
    int k;
    int res = 0;
    rd(N);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(X[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
        rd(Y[xr20shxY]);
      }
    }
    sortA_L(N, X);
    for(loop=(0);loop<(2);loop++){
      dp[0] = 0;
      k = 0;
      for(i=(0);i<(N);i++){
        while(X[k] < X[i] - K){
          k++;
        }
        dp[i+1] =max_L(dp[i], i - k + 1);
      }
      for(i=(0);i<(N);i++){
        X[i] = 1000000000 - X[i];
      }
      reverse(X, X+N);
      if(loop==0){
        for(i=(0);i<(N+1);i++){
          dp1[i] = dp[i];
        }
      }
      if(loop==1){
        for(i=(0);i<(N+1);i++){
          dp2[i] = dp[i];
        }
      }
    }
    for(i=(0);i<(N+1);i++){
      chmax(res, dp1[i] + dp2[N-i]);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N; ll K; int X[2d5], Y[2d5];
// int dp[2d5+1], dp1[2d5+1], dp2[2d5+1];
// {
//   REP(rd_int()){
//     int i, k, res = 0;
//     rd(N,K,X(N),Y(N));
//     sortA(N, X);
//     rep(loop,2){
//       dp[0] = 0;
//       k = 0;
//       rep(i,N){
//         while(X[k] < X[i] - K) k++;
//         dp[i+1] = max(dp[i], i - k + 1);
//       }
// 
//       rep(i,N) X[i] = 1d9 - X[i];
//       reverse(X, X+N);
// 
//       if(loop==0) rep(i,N+1) dp1[i] = dp[i];
//       if(loop==1) rep(i,N+1) dp2[i] = dp[i];
//     }
//     rep(i,N+1) res >?= dp1[i] + dp2[N-i];
//     wt(res);
//   }
// }