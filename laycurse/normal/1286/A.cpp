#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
inline void wt_L(char a){
  putchar(a);
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(double x){
  printf("%.15f",x);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    putchar(x[i]);
  }
}
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int P[100];
int zero;
int one;
int dp[2][101];
int nx[2][101];
int main(){
  int i, k;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(P[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    if(P[i]==0){
      P[i] =-1;
    }
    else if(P[i]%2){
      P[i] =0;
    }
    else{
      P[i] =1;
    }
  }
  zero =divup_L(N,2);
  one = N / 2;
  for(k=(0);k<(2);k++){
    for(i=(0);i<(zero+1);i++){
      dp[k][i] = 1073709056;
    }
  }
  for(k=(0);k<(2);k++){
    dp[k][zero] = 0;
  }
  for(i=(0);i<(N);i++){
    for(k=(0);k<(2);k++){
      int j;
      for(j=(0);j<(zero+1);j++){
        nx[k][j] = 1073709056;
      }
    }
    if(P[i]==0 || P[i]==-1){
      int j;
      for(j=(1);j<(zero+1);j++){
        chmin(nx[0][j-1], dp[0][j]);
      }
      for(j=(1);j<(zero+1);j++){
        chmin(nx[0][j-1], dp[1][j] + 1);
      }
    }
    if(P[i]==1 || P[i]==-1){
      int j;
      for(j=(0);j<(zero+1);j++){
        chmin(nx[1][j], dp[0][j] + 1);
      }
      for(j=(0);j<(zero+1);j++){
        chmin(nx[1][j], dp[1][j]);
      }
    }
    for(k=(0);k<(2);k++){
      int j;
      for(j=(0);j<(zero+1);j++){
        dp[k][j] = nx[k][j];
      }
    }
  }
  wt_L(min_L(dp[0][0], dp[1][0]));
  wt_L('\n');
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// int N, P[100];
// int zero, one;
// int dp[2][101], nx[2][101];
// {
//   rd(N,P(N));
//   rep(i,N) P[i] = if[P[i]==0, -1, P[i]%2, 0, 1];
//   zero = N /+ 2;
//   one = N / 2;
// 
//   rep(k,2) rep(i,zero+1) dp[k][i] = int_inf;
//   rep(k,2) dp[k][zero] = 0;
//   rep(i,N){
//     rep(k,2) rep(j,zero+1) nx[k][j] = int_inf;
//     if(P[i]==0 || P[i]==-1){
//       rep(j,1,zero+1) nx[0][j-1] <?= dp[0][j];
//       rep(j,1,zero+1) nx[0][j-1] <?= dp[1][j] + 1;
//     }
//     if(P[i]==1 || P[i]==-1){
//       rep(j,zero+1) nx[1][j] <?= dp[0][j] + 1;
//       rep(j,zero+1) nx[1][j] <?= dp[1][j];
//     }
//     rep(k,2) rep(j,zero+1) dp[k][j] = nx[k][j];
//   }
//   wt(min(dp[0][0], dp[1][0]));
// }