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
inline long long rd_ll(void){
  long long x;
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
int K;
vector<long long> A[3000];
int sz[3000];
long long sm[3000];
long long dp[20][3001];
long long res;
void solve(int d, int s, int t){
  int i, j;
  if(t-s == 1){
    int i;
    long long tmp = 0;
    chmax(res, dp[d][K]);
    for(i=(0);i<(A[s].size());i++){
      tmp += A[s][i];
      chmax(res, tmp + dp[d][K-1-i]);
    }
    return;
  }
  int m = (s + t) / 2;
  for(j=(0);j<(K+1);j++){
    dp[d+1][j] = dp[d][j];
  }
  for(i=(s);i<(m);i++){
    for(j=(K+1)-1;j>=(sz[i]);j--){
      chmax(dp[d+1][j], dp[d+1][j-sz[i]] + sm[i]);
    }
  }
  solve(d+1, m, t);
  for(j=(0);j<(K+1);j++){
    dp[d+1][j] = dp[d][j];
  }
  for(i=(m);i<(t);i++){
    for(j=(K+1)-1;j>=(sz[i]);j--){
      chmax(dp[d+1][j], dp[d+1][j-sz[i]] + sm[i]);
    }
  }
  solve(d+1, s, m);
}
int main(){
  int i;
  rd(N);
  rd(K);
  for(i=(0);i<(N);i++){
    int APIVbQlN;
    int YREPHmFM = rd_int();
    for(APIVbQlN=(0);APIVbQlN<(YREPHmFM);APIVbQlN++){
      A[i].push_back(rd_ll());
    }
  }
  for(i=(0);i<(N);i++){
    while(A[i].size() > K){
      A[i].pop_back();
    }
  }
  for(i=(0);i<(N);i++){
    sz[i] = A[i].size();
  }
  for(i=(0);i<(N);i++){
    {
      int gEg5UqEA;
      long long qSsg05KM;
      if(sz[i]==0){
        qSsg05KM = 0;
      }
      else{
        qSsg05KM = A[i][0];
        for(gEg5UqEA=(1);gEg5UqEA<(sz[i]);gEg5UqEA++){
          qSsg05KM += A[i][gEg5UqEA];
        }
      }
      sm[i] =qSsg05KM;
    }
  }
  solve(0, 0, N);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20201102-1

// --- original code ---
// //no-unlocked
// int N, K;
// vector<ll> A[3000];
// int sz[3000];
// ll sm[3000], dp[20][3001], res;
// 
// void solve(int d, int s, int t){
//   if(t-s == 1){
//     ll tmp = 0;
//     res >?= dp[d][K];
//     rep(i,A[s].size()){
//       tmp += A[s][i];
//       res >?= tmp + dp[d][K-1-i];
//     }
//     return;
//   }
// 
//   int m = (s + t) / 2;
// 
//   rep(j,K+1) dp[d+1][j] = dp[d][j];
//   rep(i,s,m) rrep(j,sz[i],K+1) dp[d+1][j] >?= dp[d+1][j-sz[i]] + sm[i];
//   solve(d+1, m, t);
// 
//   rep(j,K+1) dp[d+1][j] = dp[d][j];
//   rep(i,m,t) rrep(j,sz[i],K+1) dp[d+1][j] >?= dp[d+1][j-sz[i]] + sm[i];
//   solve(d+1, s, m);
// }
// 
// {
//   rd(N,K);
//   rep(i,N) REP(rd_int()) A[i].push_back(rd_ll());
//   rep(i,N) while(A[i].size() > K) A[i].pop_back();
//   rep(i,N) sz[i] = A[i].size();
//   rep(i,N) sm[i] = sum(A[i](sz[i]));
//   solve(0, 0, N);
//   wt(res);
// }