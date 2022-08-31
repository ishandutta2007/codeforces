#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
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
    i = getchar();
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
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar();
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
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int Slen;
int Tlen;
char S[402];
char T[402];
int nx[26][402];
int dp[402][402];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, j;
    int f1;
    int f2;
    Slen = rd(S);
    Tlen = rd(T);
    for(i=(0);i<(Slen);i++){
      S[i] -= 'a';
    }
    for(i=(0);i<(Tlen);i++){
      T[i] -= 'a';
    }
    for(j=(0);j<(26);j++){
      nx[j][Slen] = 1073709056;
    }
    for(i=(Slen)-1;i>=(0);i--){
      for(j=(0);j<(26);j++){
        nx[j][i] = nx[j][i+1];
      }
      nx[S[i]][i] = i;
    }
    for(f1=(0);f1<(Tlen);f1++){
      f2 = Tlen - f1;
      for(i=(0);i<(f1+1);i++){
        for(j=(0);j<(f2+1);j++){
          dp[i][j] = 1073709056;
        }
      }
      dp[0][0] = 0;
      for(i=(0);i<(f1+1);i++){
        for(j=(0);j<(f2+1);j++){
          if(dp[i][j] >= Slen){
            continue;
          }
          if(i < f1){
            chmin(dp[i+1][j], nx[T[i]][dp[i][j]] + 1);
          }
          if(j < f2){
            chmin(dp[i][j+1], nx[T[f1+j]][dp[i][j]] + 1);
          }
        }
      }
      if(dp[f1][f2] < 1073709056){
        wt_L("YES");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// int Slen, Tlen;
// char S[402], T[402];
// int nx[26][402];
// int dp[402][402];
// {
//   REP(rd_int()){
//     int f1, f2;
//     rd(S@Slen,T@Tlen);
//     rep(i,Slen) S[i] -= 'a';
//     rep(i,Tlen) T[i] -= 'a';
// 
//     rep(j,26) nx[j][Slen] = int_inf;
//     rrep(i,Slen){
//       rep(j,26) nx[j][i] = nx[j][i+1];
//       nx[S[i]][i] = i;
//     }
// 
//     rep(f1,Tlen){
//       f2 = Tlen - f1;
//       rep(i,f1+1) rep(j,f2+1) dp[i][j] = int_inf;
//       dp[0][0] = 0;
//       rep(i,f1+1) rep(j,f2+1){
//         if(dp[i][j] >= Slen) continue;
//         if(i < f1) dp[i+1][j] <?= nx[T[i]][dp[i][j]] + 1;
//         if(j < f2) dp[i][j+1] <?= nx[T[f1+j]][dp[i][j]] + 1;
//       }
//       if(dp[f1][f2] < int_inf) wt("YES"), break_continue;
//     }
//     wt("NO");
//   }
// }