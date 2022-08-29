#include<bits/stdc++.h>
using namespace std;
void rd(int &x){
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
void wt_L(int x){
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
  int M, N;
  rd(N);
  rd(M);
  if(N <= 30){
    M %= (1<<N);
  }
  wt_L(M);
  putchar('\n');
  return 0;
}
// cLay varsion 20180108-2

// --- original code ---
// //no-unlocked
// {
//   int N, M;
//   rd(N,M);
//   if(N <= 30) M %= (1<<N);
//   wt(M);
// }