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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int main(){
  int Lj4PdHRW;
  int N;
  int D;
  int x;
  int t;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    rd(D);
    for(x=1;;){
      t =divup_L(D,x);
      if(x-1 + t <= N){
        wt_L("YES");
        wt_L('\n');
        goto Q5VJL1cS;
      }
      if(t==1){
        break;
      }
      x =divup_L(D,(t-1));
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200112-1

// --- original code ---
// //no-unlocked
// {
//   int N, D;
//   int x, t;
//   REP(rd_int()){
//     rd(N, D);
//     for(x=1;;){
//       t = D /+ x;
//       if(x-1 + t <= N) wt("YES"), break_continue;
//       if(t==1) break;
//       x = D /+ (t-1);
//     }
//     wt("NO");
//   }
// }