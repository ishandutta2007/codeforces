#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int N;
int X;
int A[100000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int mx;
    int res;
    rd(N);
    rd(X);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      if(A[i]==X){
        wt_L(1);
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    {
      int t_ynMSdg;
      int KrdatlYV;
      if(N==0){
        KrdatlYV = 0;
      }
      else{
        KrdatlYV = A[0];
        for(t_ynMSdg=(1);t_ynMSdg<(N);t_ynMSdg++){
          KrdatlYV = max_L(KrdatlYV, A[t_ynMSdg]);
        }
      }
      mx =KrdatlYV;
    }
    res =max_L(2,divup_L(X,mx));
    wt_L(res);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int N, X, A[1d5];
// {
//   REP(rd_int()){
//     int mx, res;
//     rd(N,X,A(N));
//     rep(i,N) if(A[i]==X) wt(1), break_continue;
//     mx = max(A(N));
//     res = max(2, X /+ mx);
//     wt(res);
//   }
// }