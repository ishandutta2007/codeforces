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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int A[5000];
int ps;
int p[5000];
int ms;
int m[5000];
int dp[5001];
int nx[5001];
int main(){
  int i, k;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    if(A[i]==1){
      p[ps++] = i;
    }
  }
  for(i=(0);i<(N);i++){
    if(A[i]==0){
      m[ms++] = i;
    }
  }
  for(i=(1);i<(ps+1);i++){
    dp[i] = 1073709056;
  }
  for(k=(0);k<(ms);k++){
    for(i=(0);i<(ps+1);i++){
      nx[i] = dp[i];
    }
    for(i=(0);i<(ps);i++){
      chmin(nx[i+1], dp[i] + abs(m[k] - p[i]));
    }
    for(i=(0);i<(ps+1);i++){
      dp[i] = nx[i];
    }
  }
  wt_L(dp[ps]);
  wt_L('\n');
  return 0;
}
// cLay version 20210508-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[5000];
// int ps, p[5000];
// int ms, m[5000];
// int dp[5001], nx[5001];
// {
//   rd(N,A(N));
//   rep(i,N) if(A[i]==1) p[ps++] = i;
//   rep(i,N) if(A[i]==0) m[ms++] = i;
//   rep(i,1,ps+1) dp[i] = int_inf;
//   rep(k,ms){
//     rep(i,ps+1) nx[i] = dp[i];
//     rep(i,ps) nx[i+1] <?= dp[i] + abs(m[k] - p[i]);
//     rep(i,ps+1) dp[i] = nx[i];
//   }
//   wt(dp[ps]);
// }