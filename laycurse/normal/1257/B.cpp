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
int X;
int Y;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(X);
    rd(Y);
    if(X==1){
      if(Y==1){
        wt_L("YES");
        wt_L('\n');
      }
      else{
        wt_L("NO");
        wt_L('\n');
      }
      continue;
    }
    if(X<=3){
      if(Y<=3){
        wt_L("YES");
        wt_L('\n');
      }
      else{
        wt_L("NO");
        wt_L('\n');
      }
      continue;
    }
    wt_L("YES");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191123-1

// --- original code ---
// //no-unlocked
// int X, Y;
// {
//   REP(rd_int()){
//     rd(X,Y);
//     if(X==1) wt(if[Y==1, "YES", "NO"]), continue;
//     if(X<=3) wt(if[Y<=3, "YES", "NO"]), continue;
//     wt("YES");
//   }
// }