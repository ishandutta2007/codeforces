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
template<class T, class S> int arrCountVal(int N, T A[], S val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int A[80];
int sz;
int ps;
int pl[80];
int dp[3200][81];
int nx[3200][81];
int cost[81][81][81];
int res[3200];
int main(){
  int i;
  int j;
  int k;
  int m;
  int x;
  int y;
  int z;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  sz = arrCountVal(N,A,1)+1;
  k = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==1){
      k++;
    }
    if(A[i]==0){
      pl[ps++] = k;
    }
  }
  m = N * (N-1) / 2;
  for(i=(0);i<(m+1);i++){
    for(j=(0);j<(ps+1);j++){
      dp[i][j] = 1073709056;
    }
  }
  for(i=(0);i<(m+1);i++){
    dp[i][0] = 0;
  }
  for(k=(0);k<(sz);k++){
    for(j=(0);j<(ps+1);j++){
      cost[k][j][j] = 0;
      for(x=(j+1);x<(ps+1);x++){
        cost[k][j][x] = cost[k][j][x-1] + abs(pl[x-1] - k);
      }
    }
  }
  for(k=(0);k<(sz);k++){
    for(i=(0);i<(m+1);i++){
      for(j=(0);j<(ps+1);j++){
        nx[i][j] = 1073709056;
      }
    }
    for(i=(0);i<(m+1);i++){
      for(j=(0);j<(ps+1);j++){
        for(x=(j);x<(ps+1);x++){
          y = (x-j) * (x-j-1) / 2;
          z = cost[k][j][x];
          if(i+z <= m){
            chmin(nx[i+z][x], dp[i][j] + y);
          }
        }
      }
    }
    for(i=(0);i<(m+1);i++){
      for(j=(0);j<(ps+1);j++){
        dp[i][j] = nx[i][j];
      }
    }
  }
  for(i=(0);i<(m+1);i++){
    res[i] = ps * (ps-1) / 2 - dp[i][ps];
  }
  {
    int ytthggxT;
    if(m+1==0){
      wt_L('\n');
    }
    else{
      for(ytthggxT=(0);ytthggxT<(m+1-1);ytthggxT++){
        wt_L(res[ytthggxT]);
        wt_L(' ');
      }
      wt_L(res[ytthggxT]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200920-1

// --- original code ---
// //no-unlocked
// int N, A[80];
// int sz, ps, pl[80];
// int dp[3200][81], nx[3200][81];
// int cost[81][81][81];
// int res[3200];
// {
//   int i, j, k, m, x, y, z;
//   rd(N,A(N));
// 
//   sz = arrCountVal(N,A,1)+1;
// 
//   k = 0;
//   rep(i,N){
//     if(A[i]==1) k++;
//     if(A[i]==0) pl[ps++] = k;
//   }
// 
//   m = N * (N-1) / 2;
//   rep(i,m+1) rep(j,ps+1) dp[i][j] = int_inf;
//   rep(i,m+1) dp[i][0] = 0;
// 
//   rep(k,sz) rep(j,ps+1){
//     cost[k][j][j] = 0;
//     rep(x,j+1,ps+1) cost[k][j][x] = cost[k][j][x-1] + abs(pl[x-1] - k);
//   }
// 
//   rep(k,sz){
//     rep(i,m+1) rep(j,ps+1) nx[i][j] = int_inf;
//     rep(i,m+1) rep(j,ps+1) rep(x,j,ps+1){
//       y = (x-j) * (x-j-1) / 2;
//       z = cost[k][j][x];
//       if(i+z <= m) nx[i+z][x] <?= dp[i][j] + y;
//     }
//     rep(i,m+1) rep(j,ps+1) dp[i][j] = nx[i][j];
//   }
// 
//   rep(i,m+1) res[i] = ps * (ps-1) / 2 - dp[i][ps];
//   wt(res(m+1));
// }