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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[500000];
int fs[500000];
int ls[500000];
int cnt[500000];
int se[500000];
int dp[500000+1];
int res;
int main(){
  int i;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    fs[i] = 1073709056;
    ls[i] = -1073709056;
  }
  for(i=(0);i<(N);i++){
    chmin(fs[A[i]], i);
    chmax(ls[A[i]], i);
    cnt[A[i]]++;
  }
  for(i=(0);i<(N);i++){
    se[i] = cnt[i];
  }
  for(i=(0);i<(N);i++){
    chmax(res, dp[i] + se[A[i]]);
    se[A[i]]--;
    chmax(dp[i+1], dp[i]);
    if(fs[A[i]] == i){
      chmax(dp[ls[A[i]]+1], dp[i] + cnt[A[i]]);
    }
  }
  chmax(res, dp[N]);
  wt_L(N - res);
  wt_L('\n');
  return 0;
}
// cLay version 20210103-1 [bug fixed 2]

// --- original code ---
// //no-unlocked
// int N, A[5d5];
// int fs[5d5], ls[5d5], cnt[5d5], se[5d5];
// int dp[5d5+1], res;
// {
//   rd(N,(A--)(N));
//   rep(i,N) fs[i] = int_inf, ls[i] = -int_inf;
//   rep(i,N){
//     fs[A[i]] <?= i;
//     ls[A[i]] >?= i;
//     cnt[A[i]]++;
//   }
//   rep(i,N) se[i] = cnt[i];
//   rep(i,N){
//     res >?= dp[i] + se[A[i]];
//     se[A[i]]--;
//     dp[i+1] >?= dp[i];
//     if(fs[A[i]] == i) dp[ls[A[i]]+1] >?= dp[i] + cnt[A[i]];
//   }
//   res >?= dp[N];
//   wt(N - res);
// }