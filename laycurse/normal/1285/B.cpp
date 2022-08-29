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
int A[100000];
int main(){
  int Lj4PdHRW;
  long long s;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    s = 0;
    for(i=(0);i<(N);i++){
      s += A[i];
      if(s <= 0){
        wt_L("NO");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    s = 0;
    for(i=(0);i<(N);i++){
      s += A[N-1-i];
      if(s <= 0){
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
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// {
//   ll s;
//   REP(rd_int()){
//     rd(N,A(N));
//     s = 0;
//     rep(i,N){
//       s += A[i];
//       if(s <= 0) wt("NO"), break_continue;
//     }
//     s = 0;
//     rep(i,N){
//       s += A[N-1-i];
//       if(s <= 0) wt("NO"), break_continue;
//     }
//     wt("YES");
//   }
// }