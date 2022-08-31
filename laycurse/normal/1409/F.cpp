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
int K;
char S[202];
char T[4];
int dp[201][201];
int nx[201][201];
int main(){
  int i, k;
  int res = -1073709056;
  int p1;
  int p2;
  int p3;
  char c;
  rd(N);
  rd(K);
  rd(S);
  rd(T);
  for(i=(0);i<(N+1);i++){
    int j;
    for(j=(0);j<(K+1);j++){
      dp[i][j] = -1073709056;
    }
  }
  dp[0][K] = 0;
  for(k=(N)-1;k>=(0);k--){
    for(i=(0);i<(N+1);i++){
      int j;
      for(j=(0);j<(K+1);j++){
        nx[i][j] = -1073709056;
      }
    }
    for(c=('a');c<('z'+1);c++){
      if(c==S[k] || c==T[0] || c==T[1]){
        for(i=(0);i<(N+1);i++){
          int j;
          for(j=(0);j<(K+1);j++){
            if(dp[i][j] >= 0){
              if(c==T[1]){
                p1 =1;
              }
              else{
                p1 =0;
              }
              if(c==T[0]){
                p2 =i;
              }
              else{
                p2 =0;
              }
              if(c==S[k]){
                p3 =0;
              }
              else{
                p3 =1;
              }
              if(j-p3 >= 0){
                chmax(nx[i+p1][j-p3], dp[i][j] + p2);
              }
            }
          }
        }
      }
    }
    for(i=(0);i<(N+1);i++){
      int j;
      for(j=(0);j<(K+1);j++){
        dp[i][j] = nx[i][j];
      }
    }
  }
  for(i=(0);i<(N+1);i++){
    int j;
    for(j=(0);j<(K+1);j++){
      chmax(res, dp[i][j]);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N, K;
// char S[202], T[4];
// int dp[201][201], nx[201][201];
// {
//   int res = -int_inf, p1, p2, p3;
//   char c;
//   rd(N,K,S,T);
// 
//   rep(i,N+1) rep(j,K+1) dp[i][j] = -int_inf;
//   dp[0][K] = 0;
//   rrep(k,N){
//     rep(i,N+1) rep(j,K+1) nx[i][j] = -int_inf;
//     rep(c,'a','z'+1) if(c==S[k] || c==T[0] || c==T[1]){
//       rep(i,N+1) rep(j,K+1) if(dp[i][j] >= 0){
//         p1 = if[c==T[1], 1, 0];
//         p2 = if[c==T[0], i, 0];
//         p3 = if[c==S[k], 0, 1];
//         if(j-p3 >= 0) nx[i+p1][j-p3] >?= dp[i][j] + p2;
//       }
//     }
//     rep(i,N+1) rep(j,K+1) dp[i][j] = nx[i][j];
//   }
//   rep(i,N+1) rep(j,K+1) res >?= dp[i][j];
//   wt(res);
// }