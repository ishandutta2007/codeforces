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
inline void wt_L(double x){
  printf("%.15f",x);
}
int N = 10;
int mp[10][10];
int go[100];
double dp[100];
int main(){
  int k;
  int i;
  int j;
  int r;
  int ok;
  for(i=(0);i<(N);i++){
    {
      int Lj4PdHRW;
      for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
        rd(mp[i][Lj4PdHRW]);
      }
    }
  }
  for(k=(0);k<(N*N);k++){
    i = N - 1 - k/N;
    j = k%N;
    if(i%2==0){
      j = N - 1 - j;
    }
    if(mp[i][j]%2==0){
      go[k] = k + mp[i][j] * N;
    }
    else{
      go[k] = k + mp[i][j] * N - (k%N) + (N-1-(k%N));
    }
  }
  for(k=(N*N-1)-1;k>=(0);k--){
    ok = 0;
    for(r=(1);r<(7);r++){
      if(k + r >= N*N){
        continue;
      }
      ok++;
      dp[k] +=min_L(dp[k+r], dp[go[k+r]]);
    }
    dp[k] = (dp[k] + 6.0) / ok;
  }
  wt_L(dp[0]);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int N = 10;
// int mp[10][10], go[100];
// double dp[100];
// {
//   int i, j, r, ok;
//   rep(i,N) rd(mp[i](N));
//   rep(k,N*N){
//     i = N - 1 - k/N;
//     j = k%N;
//     if(i%2==0) j = N - 1 - j;
//     if(mp[i][j]%2==0) go[k] = k + mp[i][j] * N;
//     else              go[k] = k + mp[i][j] * N - (k%N) + (N-1-(k%N));
//   }
// 
//   rrep(k,N*N-1){
//     ok = 0;
//     rep(r,1,7){
//       if(k + r >= N*N) continue;
//       ok++;
//       dp[k] += min(dp[k+r], dp[go[k+r]]);
//     }
//     dp[k] = (dp[k] + 6.0) / ok;
//   }
//   wt(dp[0]);
// }