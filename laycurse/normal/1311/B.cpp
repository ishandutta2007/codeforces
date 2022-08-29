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
int M;
int A[100];
int P[100];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(M);xr20shxY++){
        rd(P[xr20shxY]);P[xr20shxY] += (-1);
      }
    }
    for(;;){
      int tU__gIr_;
      int fg = 0;
      for(tU__gIr_=(0);tU__gIr_<(M);tU__gIr_++){
        auto &i = P[tU__gIr_];
        if(A[i] > A[i+1]){
          fg++;
          swap(A[i], A[i+1]);
        }
      }
      if(!fg){
        break;
      }
    }
    for(i=(1);i<(N);i++){
      if(A[i-1] > A[i]){
        wt_L("NO");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L("YES");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int N, M, A[100], P[100];
// {
//   REP(rd_int()){
//     rd(N,M,A(N),(P--)(M));
//     for(;;){
//       int fg = 0;
//       rep[P](i,M) if(A[i] > A[i+1]){
//         fg++;
//         swap(A[i], A[i+1]);
//       }
//       if(!fg) break;
//     }
//     rep(i,1,N) if(A[i-1] > A[i]) wt("NO"), break_continue;
//     wt("YES");
//   }
// }