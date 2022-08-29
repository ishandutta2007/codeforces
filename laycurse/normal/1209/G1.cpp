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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int Q;
int A[200000];
int cnt[200000];
int mx[200000];
int main(){
  int i;
  int j;
  int k;
  int res = 0;
  rd(N);
  rd(Q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  for(i=0;i<(N);i++){
    cnt[A[i]]++;
    chmax(mx[A[i]], i);
  }
  i = j = k = 0;
  while(i < N){
    chmax(k, mx[A[i]]);
    chmax(j, cnt[A[i]]);
    if(i==k){
      res += j;
      j = 0;
    }
    i++;
  }
  wt_L(N-res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int N, Q, A[2d5], cnt[2d5], mx[2d5];
// {
//   int i, j, k, res = 0;
//   rd(N,Q,(A--)(N));
// 
//   rep(i,N){
//     cnt[A[i]]++;
//     mx[A[i]] >?= i;
//   }
// 
//   i = j = k = 0;
//   while(i < N){
//     k >?= mx[A[i]];
//     j >?= cnt[A[i]];
//     if(i==k){
//       res += j;
//       j = 0;
//     }
//     i++;
//   }
// 
//   wt(N-res);
// }