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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int A[3000];
int tmp[3000];
int dp[3001][3001];
int dl[3001][3001];
vector<int> en[3001];
int solve(int s, int g){
  int res = 1073709056;
  int i;
  int j;
  int k;
  if(dp[s][g] >= 0){
    return dp[s][g];
  }
  if(s==0){
    return 0;
  }
  if(s+1 < g){
    chmin(res, solve(s, g-1));
  }
  for(j=(0);j<(en[g-1].size());j++){
    i = en[g-1][j];
    if(i < s){
      chmin(res, solve(i, s) + dl[i+1][s]);
    }
  }
  return dp[s][g] = res;
}
int main(){
  int Q5VJL1cS;
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int i, k;
    rd(N);
    {
      int FmcKpFmN;
      for(FmcKpFmN=(0);FmcKpFmN<(N);FmcKpFmN++){
        rd(A[FmcKpFmN]);
      }
    }
    for(i=(0);i<(N+1);i++){
      int j;
      for(j=(0);j<(N+1);j++){
        dp[i][j] = -1;
      }
    }
    for(k=(0);k<(N);k++){
      dl[k][k] = 0;
      for(i=(k)-1;i>=(0);i--){
        dl[i][k] = dl[i+1][k];
        if(i + A[i] >= k){
          dl[i][k]++;
        }
      }
    }
    for(i=(0);i<(N);i++){
      en[i].clear();
    }
    for(i=(0);i<(N);i++){
      en[i+A[i]].push_back(i);
    }
    wt_L(solve(N-1,N));
    wt_L('\n');
  }
  return 0;
}
// cLay version 20201205-1

// --- original code ---
// //no-unlocked
// int N, A[3000], tmp[3000];
// int dp[3001][3001], dl[3001][3001];
// vector<int> en[3001];
// 
// int solve(int s, int g){
//   int res = int_inf, i, j, k;
// 
//   if(dp[s][g] >= 0) return dp[s][g];
//   if(s==0) return 0;
// 
//   if(s+1 < g) res <?= solve(s, g-1);
//   rep(j,en[g-1].size()){
//     i = en[g-1][j];
//     if(i < s) res <?= solve(i, s) + dl[i+1][s];
//   }
// 
//   return dp[s][g] = res;
// }
// 
// {
//   REP(rd_int()){
//     rd(N,A(N));
//     rep(i,N+1) rep(j,N+1) dp[i][j] = -1;
//     rep(k,N){
//       dl[k][k] = 0;
//       rrep(i,k){
//         dl[i][k] = dl[i+1][k];
//         if(i + A[i] >= k) dl[i][k]++;
//       }
//     }
//     rep(i,N) en[i].clear();
//     rep(i,N) en[i+A[i]].push_back(i);
//     wt(solve(N-1,N));
//   }
// }