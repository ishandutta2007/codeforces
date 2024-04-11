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
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(double x){
  printf("%.9f",x);
}
int N;
int A[1000000];
int nx[1000000+1];
int pr[1000000+1];
double a[1000000+1];
int vol[1000000+1];
double res[1000000];
int main(){
  int i;
  int j;
  int k;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  a[0] = 1e100;
  vol[0] = 0;
  for(i=(0);i<(N);i++){
    a[i+1] = A[i];
  }
  for(i=(0);i<(N);i++){
    vol[i+1] = 1;
  }
  for(i=(0);i<(N);i++){
    nx[i] = i+1;
  }
  for(i=(0);i<(N);i++){
    pr[i+1] = i;
  }
  pr[0] = nx[N] = -1;
  i = 0;
  for(;;){
    if(i == -1 || nx[i] == -1){
      break;
    }
    j = nx[i];
    if(a[i] > a[j]){
      k = nx[j];
      a[i] = (a[i] * vol[i] + a[j] * vol[j]) / (vol[i] + vol[j]);
      vol[i] += vol[j];
      nx[i] = k;
      if(k >= 0){
        pr[k] = i;
      }
      if(pr[i] >= 0){
        i = pr[i];
      }
      continue;
    }
    i = nx[i];
  }
  i = k = 0;
  while(i >= 0){
    int V9aVTaxx;
    for(V9aVTaxx=(0);V9aVTaxx<(vol[i]);V9aVTaxx++){
      res[k++] = a[i];
    }
    i = nx[i];
  }
  {
    int jZyWAPpY;
    for(jZyWAPpY=(0);jZyWAPpY<(k);jZyWAPpY++){
      wt_L(res[jZyWAPpY]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200119-1
 
// --- original code ---
// //no-unlocked
// int N, A[1d6];
// 
// int nx[1d6+1], pr[1d6+1];
// double a[1d6+1]; int vol[1d6+1];
// 
// double res[1d6];
// {
//   int i, j, k;
// 
//   rd(N,A(N));
//   a[0] = 1e100;
//   vol[0] = 0;
//   rep(i,N) a[i+1] = A[i];
//   rep(i,N) vol[i+1] = 1;
//   rep(i,N) nx[i] = i+1;
//   rep(i,N) pr[i+1] = i;
//   pr[0] = nx[N] = -1;
// 
//   i = 0;
//   for(;;){
//     if(i == -1 || nx[i] == -1) break;
//     j = nx[i];
//     if(a[i] > a[j]){
//       k = nx[j];
//       a[i] = (a[i] * vol[i] + a[j] * vol[j]) / (vol[i] + vol[j]);
//       vol[i] += vol[j];
//       nx[i] = k;
//       if(k >= 0) pr[k] = i;
//       if(pr[i] >= 0) i = pr[i];
//       continue;
//     }
//     i = nx[i];
//   }
// 
//   i = k = 0;
//   while(i >= 0){
//     rep(vol[i]) res[k++] = a[i];
//     i = nx[i];
//   }
//   wtLn(res(k));
// }