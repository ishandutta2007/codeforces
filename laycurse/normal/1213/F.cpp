#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int K;
int P[200000];
int Q[200000];
int pp[200000];
int qq[200000];
int res[200000];
char resc[200001];
int main(){
  int a, aa, b, bb, i, j, k;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(P[Lj4PdHRW]);P[Lj4PdHRW] += (-1);
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=0;KL2GvlyY<(N);KL2GvlyY++){
      rd(Q[KL2GvlyY]);Q[KL2GvlyY] += (-1);
    }
  }
  for(i=0;i<(N);i++){
    pp[P[i]] = i;
  }
  for(i=0;i<(N);i++){
    qq[Q[i]] = i;
  }
  k = 0;
  a = b = -1;
  while(a < N-1 || b < N-1){
    k++;
    aa = a + 1;
    bb = b + 1;
    while(aa > a || bb > b){
      if(aa > a){
        a++;
        res[P[a]] = k;
        chmax(bb, qq[P[a]]);
      }
      if(bb > b){
        b++;
        res[Q[b]] = k;
        chmax(aa, pp[Q[b]]);
      }
    }
  }
  if(k < K){
    wt_L("NO");
    wt_L('\n');
    return 0;
  }
  wt_L("YES");
  wt_L('\n');
  for(i=0;i<(N);i++){
    resc[i] = 'a' +min_L(26, res[i])- 1;
  }
  wt_L(resc);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int N, K;
// int P[2d5], Q[2d5];
// 
// int pp[2d5], qq[2d5];
// int res[2d5];
// char resc[200001];
// {
//   int i, j, k;
//   int a, b, aa, bb;
// 
//   rd(N,K,(P--)(N),(Q--)(N));
// 
//   rep(i,N) pp[P[i]] = i;
//   rep(i,N) qq[Q[i]] = i;
// 
//   k = 0;
//   a = b = -1;
// 
//   while(a < N-1 || b < N-1){
//     k++;
//     aa = a + 1;
//     bb = b + 1;
// 
//     while(aa > a || bb > b){
//       if(aa > a){
//         a++;
//         res[P[a]] = k;
//         bb >?= qq[P[a]];
//       }
//       if(bb > b){
//         b++;
//         res[Q[b]] = k;
//         aa >?= pp[Q[b]];
//       }
//     }
//   }
// 
//   if(k < K) wt("NO"), return 0;
//   wt("YES");
//   rep(i,N) resc[i] = 'a' + min(26, res[i]) - 1;
//   wt(resc);
// }