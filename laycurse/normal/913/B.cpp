#include<bits/stdc++.h>
using namespace std;
void rd(int &x){
  int k, m=0;
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
void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int N, P[1001], deg[1001], has[1001];
int main(){
  int i, j, k;
  rd(N);
  for(i=1;i<N;i++){
    rd(P[i]);
    P[i]--;
  }
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=1;Lj4PdHRW<(N-1) + 1;Lj4PdHRW++){
      has[P[Lj4PdHRW]] = 1;
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=1;KL2GvlyY<(N-1) + 1;KL2GvlyY++){
      deg[P[KL2GvlyY]] += 1 - has[KL2GvlyY];
    }
  }
  for(i=0;i<N;i++){
    if(has[i] && deg[i] < 3){
      wt_L("No");
      putchar('\n');
      return 0;
    }
  }
  wt_L("Yes");
  putchar('\n');
  return 0;
}
// cLay varsion 20180108-2

// --- original code ---
// //no-unlocked
// int N, P[1001], has[1001], deg[1001];
// {
//   int i, j, k;
//   
//   rd(N);
//   rep(i,1,N) rd(P[i]), P[i]--;
//   has[P[1..N-1]] = 1;
//   deg[P[1..N-1]] += 1 - has[1..];
// 
//   rep(i,N) if(has[i] && deg[i] < 3){
//     wt("No");
//     return 0;
//   }
//   wt("Yes");
// }