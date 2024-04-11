#include<bits/stdc++.h>
using namespace std;
inline void rd(long long &x){
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
inline void wt_L(long long x){
  char f[20];
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int main(){
  long long A, B, C;
  rd(A);
  rd(B);
  rd(C);
  chmin(A, B+1);
  chmin(B, A+1);
  wt_L(A+B+2*C);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190601-1

// --- original code ---
// //no-unlocked
// {
//   ll A, B, C;
//   rd(A,B,C);
//   A <?= B+1;
//   B <?= A+1;
//   wt(A+B+2C);
// }