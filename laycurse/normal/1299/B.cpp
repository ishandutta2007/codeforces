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
inline void rd(long long &x){
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int N;
long long X[100000+2];
long long Y[100000+2];
int main(){
  int i;
  long long dx1;
  long long dy1;
  long long dx2;
  long long dy2;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);
      rd(Y[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(2);i++){
    X[i+N] = X[i];
  }
  for(i=(0);i<(2);i++){
    Y[i+N] = Y[i];
  }
  if(N%2){
    wt_L("NO");
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N/2);i++){
    dx1 = X[i+1] - X[i];
    dy1 = Y[i+1] - Y[i];
    dx2 = X[N/2+i+1] - X[N/2+i];
    dy2 = Y[N/2+i+1] - Y[N/2+i];
    if(dx1 != -dx2 || dy1 != -dy2){
      wt_L("NO");
      wt_L('\n');
      return 0;
    }
  }
  wt_L("YES");
  wt_L('\n');
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// int N; ll X[1d5+2], Y[1d5+2];
// {
//   ll dx1, dy1, dx2, dy2;
//   rd(N,(X,Y)(N));
//   rep(i,2) X[i+N] = X[i];
//   rep(i,2) Y[i+N] = Y[i];
// 
//   if(N%2) wt("NO"), return 0;
//   rep(i,N/2){
//     dx1 = X[i+1] - X[i];
//     dy1 = Y[i+1] - Y[i];
//     dx2 = X[N/2+i+1] - X[N/2+i];
//     dy2 = Y[N/2+i+1] - Y[N/2+i];
//     if(dx1 != -dx2 || dy1 != -dy2) wt("NO"), return 0;
//   }
// 
//   wt("YES");
// }