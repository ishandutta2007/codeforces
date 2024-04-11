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
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
char S[200002];
int fix[200000];
int dist[200000];
int q[200000];
int qs;
int qe;
int main(){
  int i;
  int j;
  int k;
  rd(N);
  rd(K);
  rd(S);
  for(i=(0);i<(N);i++){
    if(S[i]=='W'){
      S[i] =1;
    }
    else{
      S[i] =0;
    }
  }
  for(i=(0);i<(N);i++){
    if(S[i]==S[moddw_L((i-1),N)] || S[i]==S[(i+1)%N]){
      fix[i] = 1;
    }
  }
  for(i=(0);i<(N);i++){
    if(fix[i]){
      break;
    }
  }
  if(i==N){
    if(K%2){
      for(i=(0);i<(N);i++){
        S[i] = 1 - S[i];
      }
    }
  }
  else{
    for(i=(0);i<(N);i++){
      dist[i] = - 1;
    }
    for(i=(0);i<(N);i++){
      if(fix[i]){
        dist[i] = 0;
        q[qe++] = i;
      }
    }
    while(qs < qe){
      i = q[qs++];
      j = (i+1) % N;
      if(dist[j] == -1){
        dist[j] = dist[i] + 1;
        q[qe++] = j;
      }
      j =moddw_L((i-1),N);
      if(dist[j] == -1){
        dist[j] = dist[i] + 1;
        q[qe++] = j;
      }
    }
    for(i=(0);i<(N);i++){
      chmin(dist[i], K);
    }
    for(i=(0);i<(N);i++){
      if(dist[i]%2){
        S[i] = 1 - S[i];
      }
    }
  }
  for(i=(0);i<(N);i++){
    if(S[i]==1){
      S[i] ='W';
    }
    else{
      S[i] ='B';
    }
  }
  wt_L(S);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int N, K;
// char S[200002];
// int fix[2d5], dist[2d5], q[2d5], qs, qe;
// {
//   int i, j, k;
// 
//   rd(N,K,S);
//   rep(i,N) S[i] = if[S[i]=='W', 1, 0];
// 
//   rep(i,N) if(S[i]==S[(i-1)%%N] || S[i]==S[(i+1)%N]) fix[i] = 1;
// 
//   rep(i,N) if(fix[i]) break;
//   if(i==N){
//     if(K%2) rep(i,N) S[i] = 1 - S[i];
//   } else {
//     rep(i,N) dist[i] = - 1;
//     rep(i,N) if(fix[i]) dist[i] = 0, q[qe++] = i;
//     while(qs < qe){
//       i = q[qs++];
//       j = (i+1) % N;
//       if(dist[j] == -1) dist[j] = dist[i] + 1, q[qe++] = j;
//       j = (i-1) %% N;
//       if(dist[j] == -1) dist[j] = dist[i] + 1, q[qe++] = j;
//     }
//     rep(i,N) dist[i] <?= K;
//     rep(i,N) if(dist[i]%2) S[i] = 1 - S[i];
//   }
// 
//   rep(i,N) S[i] = if[S[i]==1, 'W', 'B'];
//   wt(S);
// }