#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
  int i, sz=0;
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
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int N;
char S[100002];
char T[100002];
int dp[2][100001];
int main(){
  int i;
  N = rd(S);
  for(i=0;i<(N);i++){
    S[i] -= '0';
  }
  for(i=N-1;i>=0;i--){
    dp[0][i] =max_L(dp[0][i+1], dp[1][i+1]);
    dp[1][i] = dp[1][i+1];
    dp[S[i]][i]++;
  }
  for(i=0;i<(N);i++){
    T[i] = S[i];
    if(T[i] && dp[0][i] < dp[1][i]){
      T[i] = 0;
    }
  }
  for(i=0;i<(N);i++){
    T[i] += '0';
  }
  wt_L(T);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int N;
// char S[100002], T[100002];
// 
// int dp[2][100001];
// 
// {
//   int i;
//   
//   rd(S@N);
//   rep(i,N) S[i] -= '0';
// 
//   for(i=N-1;i>=0;i--){
//     dp[0][i] = max(dp[0][i+1], dp[1][i+1]);
//     dp[1][i] = dp[1][i+1];
//     dp[S[i]][i]++;
//   }
// 
//   rep(i,N){
//     T[i] = S[i];
//     if(T[i] && dp[0][i] < dp[1][i]) T[i] = 0;
//   }
//   rep(i,N) T[i] += '0';
//   wt(T);
// }