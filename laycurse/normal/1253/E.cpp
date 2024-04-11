#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int M;
int X[80];
int S[80];
int dp[100001];
int nx[100001];
int main(){
  int i, k;
  wmem = memarr;
  int d;
  int s;
  int res;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);
      rd(S[Lj4PdHRW]);
    }
  }
  sortA_L(N,X,S);
  for(i=(1);i<(M+1);i++){
    dp[i] = 1073709056;
  }
  for(k=(0);k<(N);k++){
    for(i=(0);i<(M+1);i++){
      if(dp[i] < 1073709056){
        d =max_L(0, X[k]-S[k]-1-i);
        chmin(dp[min_L(M, X[k]+S[k]+d)], dp[i] + d);
      }
    }
  }
  res = 1073709056;
  for(i=(0);i<(M+1);i++){
    chmin(res, dp[i] + M - i);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191123-1

// --- original code ---
// //no-unlocked
// int N, M, X[80], S[80];
// int dp[100001], nx[100001];
// {
//   int d, s, res;
//   rd(N,M,(X,S)(N));
//   sortA(N,X,S);
// 
//   rep(i,1,M+1) dp[i] = int_inf;
//   rep(k,N){
//     rep(i,M+1) if(dp[i] < int_inf){
//       d = max(0, X[k]-S[k]-1-i);
//       dp[min(M, X[k]+S[k]+d)] <?= dp[i] + d;
//     }
//   }
// 
//   res = int_inf;
//   rep(i,M+1) res <?= dp[i] + M - i;
//   wt(res);
// }