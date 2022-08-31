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
inline void wt_L(int x){
  char f[10];
  int m=0, s=0;
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
int main(){
  int L, N, R, res1=0, res2=0;
  rd(N);
  rd(L);
  rd(R);
  res1 = (1<<L) - 1 + (N - L);
  res2 = (1<<R) - 1 + (N - R) * (1<<(R-1));
  wt_L(res1);
  wt_L(' ');
  wt_L(res2);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// {
//   int N, L, R;
//   int res1 = 0, res2 = 0;
//   rd(N,L,R);
// 
//   res1 = (1<<L) - 1 + (N - L);
//   res2 = (1<<R) - 1 + (N - R) * (1<<(R-1));
//   wt(res1, res2);
// }