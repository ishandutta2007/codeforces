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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
char S[1000000+2];
int cnt;
int len;
char arr[1000000+2];
int solve(int len, char arr[]){
  int i;
  int dp[3] = {};
  int nx[3] = {};
  for(i=(0);i<(len);i++){
    nx[0] = dp[0] + arr[i];
    nx[1] =min_L(dp[0], dp[1])+ 1 - arr[i];
    nx[2] =min_L(min_L(dp[0], dp[1]), dp[2])+ arr[i];
    {
      auto cTE1_r3A = (nx[0]);
      auto RZTsC2BF = ( nx[1]);
      auto FmcKpFmN = ( nx[2]);
      dp[0] = cTE1_r3A;
      dp[1] = RZTsC2BF;
      dp[2] = FmcKpFmN;
    }
  }
  {
    int xr20shxY;
    int WYIGIcGE;
    if(3==0){
      WYIGIcGE = 0;
    }
    else{
      WYIGIcGE = dp[0];
      for(xr20shxY=(1);xr20shxY<(3);xr20shxY++){
        WYIGIcGE = min_L(WYIGIcGE, dp[xr20shxY]);
      }
    }
    return WYIGIcGE;
  }
}
int main(){
  int ao_dF3pO;
  int tU__gIr_ = rd_int();
  for(ao_dF3pO=(0);ao_dF3pO<(tU__gIr_);ao_dF3pO++){
    int i, s;
    int res = 1073709056;
    int tmp;
    int add;
    rd(N);
    rd(K);
    rd(S);
    for(i=(0);i<(N);i++){
      S[i] -= '0';
    }
    cnt = 0;
    for(i=(0);i<(N);i++){
      cnt += S[i];
    }
    for(s=(0);s<(K);s++){
      add = cnt;
      len = 0;
      for(i=(s);i<(N);i+=(K)){
        add -= (arr[len++] = S[i]);
      }
      tmp = solve(len, arr);
      chmin(res, tmp + add);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, K;
// char S[1d6+2];
// 
// int cnt, len;
// char arr[1d6+2];
// 
// int solve(int len, char arr[]){
//   int i, dp[3] = {}, nx[3] = {};
//   rep(i,len){
//     nx[0] = dp[0] + arr[i];
//     nx[1] = min(dp[0], dp[1]) + 1 - arr[i];
//     nx[2] = min(dp[0], dp[1], dp[2]) + arr[i];
//     (dp[0], dp[1], dp[2]) = (nx[0], nx[1], nx[2]);
//   }
//   return min(dp(3));
// }
// 
// {
//   REP(rd_int()){
//     int res = int_inf, tmp, add;
//     rd(N,K,S);
//     rep(i,N) S[i] -= '0';
// 
//     cnt = 0;
//     rep(i,N) cnt += S[i];
// 
//     rep(s,K){
//       add = cnt;
//       len = 0;
//       rep(i,s,N,K) add -= (arr[len++] = S[i]);
//       tmp = solve(len, arr);
//       res <?= tmp + add;
//     }
//     wt(res);
//   }
// }