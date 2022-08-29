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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
long long S;
long long A[100000];
long long arr[100001];
int main(){
  int Lj4PdHRW;
  int mx;
  int mxi;
  int res;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(S);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      arr[i+1] = arr[i] + A[i];
    }
    if(arr[N] <= S){
      wt_L(0);
      wt_L('\n');
      continue;
    }
    mx = -1;
    for(i=(0);i<(N);i++){
      if(mx < A[i]){
        mx = A[i];
        mxi = i;
      }
      if(arr[i+1] - mx <= S){
        res = mxi;
      }
    }
    wt_L(res+1);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// //no-unlocked
// int N; ll S, A[1d5];
// ll arr[100001];
// {
//   int mx, mxi, res;
//   REP(rd_int()){
//     rd(N,S,A(N));
//     rep(i,N) arr[i+1] = arr[i] + A[i];
//     if(arr[N] <= S) wt(0), continue;
//     mx = -1;
//     rep(i,N){
//       if(mx < A[i]) mx = A[i], mxi = i;
//       if(arr[i+1] - mx <= S) res = mxi;
//     }
//     wt(res+1);
//   }
// }