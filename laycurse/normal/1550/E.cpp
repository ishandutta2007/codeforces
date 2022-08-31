#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
char S[200000+2];
int cnt[200000+2];
int dp[200000+2];
int go[17][200000+2];
int main(){
  int res;
  rd(N);
  rd(K);
  rd(S);
  int Lj4PdHRW;
  int KL2GvlyY;
  int Q5VJL1cS;
  Lj4PdHRW = 0;
  KL2GvlyY = N/K;
  while(Lj4PdHRW < KL2GvlyY){
    int i, j, mask;
    if((Lj4PdHRW + KL2GvlyY)%2==0){
      Q5VJL1cS = (Lj4PdHRW + KL2GvlyY) / 2;
    }
    else{
      Q5VJL1cS = (Lj4PdHRW + KL2GvlyY + 1) / 2;
    }
    for(j=(0);j<(K);j++){
      cnt[j] = 0;
    }
    for(j=(0);j<(K);j++){
      go[j][N] = 1073709056;
    }
    for(i=(N)-1;i>=(0);i--){
      if(S[i] != '?'){
        cnt[S[i]-'a']++;
      }
      if(i+Q5VJL1cS < N && S[i+Q5VJL1cS] != '?'){
        cnt[S[i+Q5VJL1cS]-'a']--;
      }
      for(j=(0);j<(K);j++){
        int k;
        go[j][i] = go[j][i+1];
        if(i+Q5VJL1cS > N){
          continue;
        }
        for(k=(0);k<(K);k++){
          if(k != j && cnt[k]){
            goto ao_dF3pO;
          }
        }
        go[j][i] = i+Q5VJL1cS;
        ao_dF3pO:;
      }
    }
    for(i=(0);i<(1<<K);i++){
      dp[i] = 1073709056;
    }
    dp[0] = 0;
    for(mask=(0);mask<(1<<K);mask++){
      if(dp[mask] < 1073709056){
        for(j=(0);j<(K);j++){
          if(!((mask) &(1<<(j)))){
            chmin(dp[mask|(1<<j)], go[j][dp[mask]]);
          }
        }
      }
    }
    if(dp[(1<<K)-1] < 1073709056){
      Lj4PdHRW = Q5VJL1cS;
    }
    else{
      KL2GvlyY = Q5VJL1cS - 1;
    }
  }
  res =KL2GvlyY;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210708-1

// --- original code ---
// //no-unlocked
// int N, K;
// char S[2d5+2];
// int cnt[], dp[], go[17][2d5+2];
// {
//   int res;
//   rd(N,K,S);
//   res = bsearch_max[int,x,0,N/K][
//     rep(j,K) cnt[j] = 0;
//     rep(j,K) go[j][N] = int_inf;
//     rrep(i,N){
//       if(S[i] != '?') cnt[S[i]-'a']++;
//       if(i+x < N && S[i+x] != '?') cnt[S[i+x]-'a']--;
//       rep(j,K){
//         go[j][i] = go[j][i+1];
//         if(i+x > N) continue;
//         rep(k,K) if(k != j && cnt[k]) break_continue;
//         go[j][i] = i+x;
//       }
//     }
//     rep(i,1<<K) dp[i] = int_inf;
//     dp[0] = 0;
//     rep(mask,1<<K) if(dp[mask] < int_inf) rep(j,K) if(!BIT_ith(mask,j)) dp[mask|(1<<j)] <?= go[j][dp[mask]];
//   ](dp[(1<<K)-1] < int_inf);
//   wt(res);
// }