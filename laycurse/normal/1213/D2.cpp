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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
int A[200000];
vector<int> v[200001];
int main(){
  int i, k, res=1073709056, tmp;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=0;i<(N);i++){
    k = 0;
    while(A[i]){
      v[A[i]].push_back(k);
      A[i] /= 2;
      k++;
    }
  }
  for(i=0;i<(200001);i++){
    if(v[i].size() >= K){
      sort(v[i].begin(), v[i].end());
      tmp = 0;
      for(k=0;k<(K);k++){
        tmp += v[i][k];
      }
      chmin(res, tmp);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int N, K, A[2d5];
// vector<int> v[200001];
// {
//   int i, k, res = int_inf, tmp;
//   rd(N,K,A(N));
//   rep(i,N){
//     k = 0;
//     while(A[i]){
//       v[A[i]].push_back(k);
//       A[i] /= 2;
//       k++;
//     }
//   }
// 
//   rep(i,200001) if(v[i].size() >= K){
//     sort(v[i].begin(), v[i].end());
//     tmp = 0;
//     rep(k,K) tmp += v[i][k];
//     res <?= tmp;
//   }
// 
//   wt(res);
// }