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
int N;
int H;
int L;
int R;
int A[2000];
int dp[2000];
int nx[2000];
int main(){
  int RZTsC2BF, i;
  rd(N);
  rd(H);
  rd(L);
  rd(R);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(1);i<(H);i++){
    dp[i] = -1073709056;
  }
  for(RZTsC2BF=(0);RZTsC2BF<(N);RZTsC2BF++){
    auto &k = A[RZTsC2BF];
    for(i=(0);i<(H);i++){
      nx[i] = -1073709056;
    }
    for(i=(0);i<(H);i++){
      chmax(nx[(i+k-1)%H], dp[i]);
      chmax(nx[(i+k)%H], dp[i]);
    }
    for(i=(L);i<(R+1);i++){
      nx[i]++;
    }
    for(i=(0);i<(H);i++){
      dp[i] = nx[i];
    }
  }
  {
    int APIVbQlN;
    int YREPHmFM;
    if(H==0){
      YREPHmFM = 0;
    }
    else{
      YREPHmFM = dp[0];
      for(APIVbQlN=(1);APIVbQlN<(H);APIVbQlN++){
        YREPHmFM = max_L(YREPHmFM, dp[APIVbQlN]);
      }
    }
    wt_L(YREPHmFM);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200308-1

// --- original code ---
// //no-unlocked
// int N, H, L, R, A[2000];
// int dp[2000], nx[2000];
// {
//   rd(N,H,L,R,A(N));
// 
//   rep(i,1,H) dp[i] = -int_inf;
//   rep[A](k,N){
//     rep(i,H) nx[i] = -int_inf;
//     rep(i,H){
//       nx[(i+k-1)%H] >?= dp[i];
//       nx[(i+k)%H] >?= dp[i];
//     }
//     rep(i,L,R+1) nx[i]++;
//     rep(i,H) dp[i] = nx[i];
//   }
//   wt(max(dp(H)));
// }