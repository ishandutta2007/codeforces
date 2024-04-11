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
void wt_L(long long x){
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
int C[30], L, N;
int main(){
  int i, j, k;
  long long res=0, tmp;
  rd(N);
  rd(L);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(C[Lj4PdHRW]);
    }
  }
  for(i=1;i<N;i++){
    chmin(C[i], 2*C[i-1]);
  }
  for(i=N-2;i>=0;i--){
    chmin(C[i], C[i+1]);
  }
  k = L / (1<<(N-1));
  res += (long long)C[N-1] * k;
  L %= (1<<(N-1));
  tmp = 0;
  for(i=0;i<N;i++){
    if(L&1<<i){
      tmp += C[i];
    }
    else{
      chmin(tmp, C[i]);
    }
  }
  res += tmp;
  wt_L(res);
  putchar('\n');
  return 0;
}
// cLay varsion 20180108-2

// --- original code ---
// //no-unlocked
// int N, L, C[30];
// {
//   int i, j, k;
//   ll res = 0, tmp;
//   
//   rd(N,L,C(N));
//   rep(i,1,N) C[i] <?= 2C[i-1];
//   for(i=N-2;i>=0;i--) C[i] <?= C[i+1];
//   
//   k = L / (1<<(N-1));
//   res += (ll)C[N-1] * k;
//   L %= (1<<(N-1));
// 
//   tmp = 0;
//   rep(i,N){
//     if(L&1<<i){
//       tmp += C[i];
//     } else {
//       tmp <?= C[i];
//     }
//   }
//   res += tmp;
//   
//   wt(res);
// }