#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
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
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int Q;
int N;
int P[200];
int main(){
  int Lj4PdHRW, i, j, k;
  rd(Q);
  for(Lj4PdHRW=0;Lj4PdHRW<(Q);Lj4PdHRW++){
    rd(N);
    {
      int KL2GvlyY;
      for(KL2GvlyY=0;KL2GvlyY<(N);KL2GvlyY++){
        rd(P[KL2GvlyY]);P[KL2GvlyY] += (-1);
      }
    }
    {
      int FmcKpFmN, RZTsC2BF, cTE1_r3A=0, e98WHCEY, xr20shxY;
      for(e98WHCEY=(0);e98WHCEY<(((N)-1)+1);e98WHCEY++){
        FmcKpFmN = P[e98WHCEY];
        if(cTE1_r3A==0 || RZTsC2BF>FmcKpFmN){
          RZTsC2BF = FmcKpFmN;
          cTE1_r3A = 1;
          xr20shxY = e98WHCEY;
        }
      }
      k =xr20shxY;
    }
    for(i=0;i<(N);i++){
      if(P[(k+i)%N]!=i){
        break;
      }
    }
    for(j=0;j<(N);j++){
      if(P[(k+N-j)%N]!=j){
        break;
      }
    }
    if(i==N||j==N){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int Q, N, P[200];
// {
//   int i, j, k;
//   rd(Q);
//   rep(Q){
//     rd(N,(P--)(N));
//     k = argmin(P(N));
//     rep(i,N) if(P[(k+i)%N]!=i) break;
//     rep(j,N) if(P[(k+N-j)%N]!=j) break;
//     wt(if[i==N||j==N, "YES", "NO"]);
//   }
// }