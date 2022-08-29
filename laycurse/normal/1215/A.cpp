#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
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
  int A1;
  int A2;
  int K1;
  int K2;
  int N;
  int i;
  int j;
  int res1;
  int res2;
  rd(A1);
  rd(A2);
  rd(K1);
  rd(K2);
  rd(N);
  if(K1 > K2){
    swap(K1, K2);
    swap(A1, A2);
  }
  res1 =max_L(0, N - (K1-1) * A1 - (K2-1) * A2);
  i =min_L(A1, N / K1);
  j = (N-i*K1) / K2;
  res2 = i + j;
  wt_L(res1);
  wt_L(' ');
  wt_L(res2);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// {
//   int A1, A2, K1, K2, N;
//   int i, j, res1, res2;
// 
//   rd(A1, A2, K1, K2, N);
// 
//   if(K1 > K2) swap(K1, K2), swap(A1, A2);
// 
//   res1 = max(0, N - (K1-1) * A1 - (K2-1) * A2);
// 
//   i = min(A1, N / K1);
//   j = (N-i*K1) / K2;
//   res2 = i + j;
// 
//   wt(res1, res2);
// }