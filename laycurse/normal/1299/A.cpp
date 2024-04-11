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
int N;
int A[100000];
int cnt[30];
int main(){
  int i;
  int mx = -1;
  int mxind;
  int tmp;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(30);j++){
      if(A[i] & 1<<j){
        cnt[j]++;
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    tmp = 0;
    for(j=(0);j<(30);j++){
      if(cnt[j]==1 && (A[i] & 1<<j)){
        tmp += (1<<j);
      }
    }
    if(mx < tmp){
      mx = tmp;
      mxind = i;
    }
  }
  if(mxind > 0){
    swap(A[mxind], A[0]);
  }
  {
    int ao_dF3pO;
    if(N==0){
      putchar('\n');
    }
    else{
      for(ao_dF3pO=(0);ao_dF3pO<(N-1);ao_dF3pO++){
        wt_L(A[ao_dF3pO]);
        wt_L(' ');
      }
      wt_L(A[ao_dF3pO]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// int cnt[30];
// {
//   int mx = -1, mxind, tmp;
//   rd(N,A(N));
//   rep(i,N) rep(j,30) if(A[i] & 1<<j) cnt[j]++;
//   rep(i,N){
//     tmp = 0;
//     rep(j,30) if(cnt[j]==1 && (A[i] & 1<<j)) tmp += (1<<j);
//     if(mx < tmp) mx = tmp, mxind = i;
//   }
//   if(mxind > 0) swap(A[mxind], A[0]);
//   wt(A(N));
// }