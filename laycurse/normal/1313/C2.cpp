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
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int M[500000];
long long dp[500000];
long long dp1[500000];
long long dp2[500000];
int h[500000+2];
int w[500000+2];
int sz;
int main(){
  int loop;
  int i;
  int k;
  int ind;
  long long s;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(M[Lj4PdHRW]);
    }
  }
  for(loop=(0);loop<(2);loop++){
    int RZTsC2BF;
    s = 0;
    sz = 0;
    for(RZTsC2BF=(0);RZTsC2BF<(2);RZTsC2BF++){
      arrInsert(sz, sz, h, 0, w, 0);
    }
    for(i=(0);i<(N);i++){
      while(h[sz-2] > M[i]){
        s -= (long long)(h[sz-1] - h[sz-2]) * w[sz-1];
        w[sz-2] += w[sz-1];
        sz--;
      }
      if(h[sz-1] > M[i]){
        s -= (long long)(h[sz-1] - M[i]) * w[sz-1];
        h[sz-1] = M[i];
      }
      s += M[i];
      if(h[sz-1] == M[i]){
        w[sz-1]++;
      }
      else{
        h[sz] = M[i];
        w[sz++] = 1;
      }
      dp[i] = s;
    }
    if(loop==0){
      for(i=(0);i<(N);i++){
        dp1[i] = dp[i];
      }
    }
    else{
      for(i=(0);i<(N);i++){
        dp2[i] = dp[N-1-i];
      }
    }
    reverse(M, M+N);
  }
  s = 0;
  for(i=(0);i<(N);i++){
    if(s < dp1[i] + dp2[i] - M[i]){
      ind = i;
      s = dp1[i] + dp2[i] - M[i];
    }
  }
  k = M[ind];
  for(i=(ind)-1;i>=(0);i--){
    M[i] = (chmin(k, M[i]));
  }
  k = M[ind];
  for(i=(ind);i<(N);i++){
    M[i] = (chmin(k, M[i]));
  }
  {
    int AlM5nNnR;
    if(N==0){
      putchar('\n');
    }
    else{
      for(AlM5nNnR=(0);AlM5nNnR<(N-1);AlM5nNnR++){
        wt_L(M[AlM5nNnR]);
        wt_L(' ');
      }
      wt_L(M[AlM5nNnR]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int N, M[5d5];
// ll dp[5d5], dp1[5d5], dp2[5d5];
// int h[5d5+2], w[5d5+2], sz;
// {
//   int i, k, ind;
//   ll s;
//   rd(N,M(N));
// 
//   rep(loop,2){
//     s = 0;
//     sz = 0;
//     rep(2) arrInsert(sz, sz, h, 0, w, 0);
//     rep(i,N){
//       while(h[sz-2] > M[i]){
//         s -= (ll)(h[sz-1] - h[sz-2]) * w[sz-1];
//         w[sz-2] += w[sz-1];
//         sz--;
//       }
//       if(h[sz-1] > M[i]){
//         s -= (ll)(h[sz-1] - M[i]) * w[sz-1];
//         h[sz-1] = M[i];
//       }
//       s += M[i];
//       if(h[sz-1] == M[i]){
//         w[sz-1]++;
//       } else {
//         h[sz] = M[i];
//         w[sz++] = 1;
//       }
// 
//       dp[i] = s;
//     }
//     if(loop==0){
//       rep(i,N) dp1[i] = dp[i];
//     } else {
//       rep(i,N) dp2[i] = dp[N-1-i];
//     }
//     reverse(M, M+N);
//   }
// 
//   s = 0;
//   rep(i,N) if(s < dp1[i] + dp2[i] - M[i]){
//     ind = i;
//     s = dp1[i] + dp2[i] - M[i];
//   }
// 
//   k = M[ind];
//   rrep(i,ind) M[i] = (k <?= M[i]);
//   k = M[ind];
//   rep(i,ind,N) M[i] = (k <?= M[i]);
// 
//   wt(M(N));
// }