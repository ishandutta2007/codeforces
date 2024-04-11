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
int K1;
int K2;
int main(){
  int Lj4PdHRW;
  int res;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int cTE1_r3A, xr20shxY;
    rd(N);
    rd(K1);
    rd(K2);
    res = 0;
    for(cTE1_r3A=(0);cTE1_r3A<(K1);cTE1_r3A++){
      if(rd_int()==N){
        res = 1;
      }
    }
    for(xr20shxY=(0);xr20shxY<(K2);xr20shxY++){
      rd_int();
    }
    if(res){
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
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// int N, K1, K2;
// {
//   int res;
//   REP(rd_int()){
//     rd(N,K1,K2);
//     res = 0;
//     rep(K1) if(rd_int()==N) res = 1;
//     rep(K2) rd_int();
//     wt( if[res, "YES", "NO"] );
//   }
// }