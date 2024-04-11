#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
int N;
int M;
int A[200000];
long long res[200000];
long long dp[200000];
int main(){
  int i;
  wmem = memarr;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  sortA_L(N,A);
  res[0] = dp[0] = A[0];
  for(i=(0);i<(N);i++){
    dp[i] = A[i];
    if(i-M >= 0){
      dp[i] += dp[i-M];
    }
    res[i] = res[i-1] + dp[i];
  }
  {
    int RZTsC2BF;
    if(N==0){
      putchar('\n');
    }
    else{
      for(RZTsC2BF=(0);RZTsC2BF<(N-1);RZTsC2BF++){
        wt_L(res[RZTsC2BF]);
        wt_L(' ');
      }
      wt_L(res[RZTsC2BF]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191123-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5];
// ll res[2d5], dp[2d5];
// {
//   rd(N,M,A(N));
//   sortA(N,A);
//   res[0] = dp[0] = A[0];
//   rep(i,N){
//     dp[i] = A[i];
//     if(i-M >= 0) dp[i] += dp[i-M];
//     res[i] = res[i-1] + dp[i];
//   }
//   wt(res(N));
// }