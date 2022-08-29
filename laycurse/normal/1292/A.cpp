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
int N;
int R;
int C;
int cnt = 0;
int mp[2][100000];
int calc(int r, int c){
  int i;
  int j;
  int res = 0;
  i = r ^ 1;
  if(mp[r][c]==0){
    return 0;
  }
  for(j=(c-1);j<(c+2);j++){
    if(j < 0 || j >= N){
      continue;
    }
    res += mp[i][j];
  }
  return res;
}
int main(){
  int Q5VJL1cS;
  rd(N);
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    rd(R);R += (-1);
    rd(C);C += (-1);
    cnt -= calc(R, C);
    mp[R][C] ^= 1;
    cnt += calc(R, C);
    if(cnt){
      wt_L("No");
      wt_L('\n');
    }
    else{
      wt_L("Yes");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// int N, R, C;
// 
// int cnt = 0;
// int mp[2][1d5];
// 
// int calc(int r, int c){
//   int i, j, res = 0;
//   i = r ^ 1;
//   if(mp[r][c]==0) return 0;
//   rep(j,c-1,c+2){
//     if(j < 0 || j >= N) continue;
//     res += mp[i][j];
//   }
//   return res;
// }
// 
// {
//   rd(N);
//   REP(rd_int()){
//     rd(R--,C--);
//     cnt -= calc(R, C);
//     mp[R][C] ^= 1;
//     cnt += calc(R, C);
//     wt(if[cnt, "No", "Yes"]);
//   }
// }