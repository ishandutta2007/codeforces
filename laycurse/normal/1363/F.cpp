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
char S[2002];
char T[2002];
int cntS[2002][26];
int cntT[2002][26];
int dp[2002][2002];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, j;
    rd(N);
    rd(S);
    rd(T);
    for(i=(0);i<(N);i++){
      S[i] -= 'a';
    }
    for(i=(0);i<(N);i++){
      T[i] -= 'a';
    }
    for(j=(0);j<(26);j++){
      cntS[N][j] = cntT[N][j] = 0;
    }
    for(i=(N)-1;i>=(0);i--){
      for(j=(0);j<(26);j++){
        cntS[i][j] = cntS[i+1][j];
      }
      for(j=(0);j<(26);j++){
        cntT[i][j] = cntT[i+1][j];
      }
      cntS[i][S[i]]++;
      cntT[i][T[i]]++;
    }
    for(j=(0);j<(26);j++){
      if(cntS[0][j] != cntT[0][j]){
        wt_L(-1);
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    for(i=(0);i<(N+1);i++){
      for(j=(0);j<(N+1);j++){
        dp[i][j] = 1073709056;
      }
    }
    dp[0][0] = 0;
    for(i=(0);i<(N+1);i++){
      for(j=(0);j<(N+1);j++){
        if(dp[i][j] < 1073709056){
          if(i<N && j<N && S[i]==T[j]){
            chmin(dp[i+1][j+1], dp[i][j]);
          }
          if(j<N && cntS[i][T[j]]){
            chmin(dp[i][j+1], dp[i][j] + 1);
          }
          if(i<N && cntS[i][S[i]] > cntT[j][S[i]]){
            chmin(dp[i+1][j], dp[i][j]);
          }
        }
      }
    }
    wt_L(dp[N][N]);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N;
// char S[2002], T[2002];
// int cntS[2002][26], cntT[2002][26];
// int dp[2002][2002];
// {
//   REP(rd_int()){
//     rd(N,S,T);
//     rep(i,N) S[i] -= 'a';
//     rep(i,N) T[i] -= 'a';
//     rep(j,26) cntS[N][j] = cntT[N][j] = 0;
//     rrep(i,N){
//       rep(j,26) cntS[i][j] = cntS[i+1][j];
//       rep(j,26) cntT[i][j] = cntT[i+1][j];
//       cntS[i][S[i]]++;
//       cntT[i][T[i]]++;
//     }
//     rep(j,26) if(cntS[0][j] != cntT[0][j]) wt(-1), break_continue;
// 
//     rep(i,N+1) rep(j,N+1) dp[i][j] = int_inf;
//     dp[0][0] = 0;
//     rep(i,N+1) rep(j,N+1) if(dp[i][j] < int_inf){
//       if(i<N && j<N && S[i]==T[j]) dp[i+1][j+1] <?= dp[i][j];
//       if(j<N && cntS[i][T[j]]) dp[i][j+1] <?= dp[i][j] + 1;
//       if(i<N && cntS[i][S[i]] > cntT[j][S[i]]) dp[i+1][j] <?= dp[i][j];
//     }
// 
//     wt(dp[N][N]);
//   }
// }