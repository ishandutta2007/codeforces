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
int A;
int B;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(A);
    rd(B);
    if(A > B){
      swap(A, B);
    }
    ;
    if(2*A<B || (A+B)%3){
      wt_L("NO");
      wt_L('\n');
    }
    else{
      wt_L("YES");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200214-1

// --- original code ---
// //no-unlocked
// int A, B;
// {
//   REP(rd_int()){
//     rd(A,B);
//     sortE(A,B);
//     wt(if[2A<B || (A+B)%3, "NO", "YES"]);
//   }
// }