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
int N;
int A[200000];
int ind[200000];
int res[200000];
int dp[200001];
int bk[200001];
int sz;
int main(){
  int i;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    ind[i] = i;
  }
  sortA_L(N,A,ind);
  dp[0] = 0;
  for(i=(0);i<(N);i++){
    int j;
    dp[i+1] = 1073709056;
    for(j=(3);j<(6);j++){
      if(i-j+1 >= 0 && dp[i+1] > dp[i-j+1] + A[i] - A[i-j+1]){
        dp[i+1] = dp[i-j+1] + A[i] - A[i-j+1];
        bk[i+1] = j;
      }
    }
  }
  while(i){
    int j;
    sz++;
    for(j=(0);j<(bk[i]);j++){
      res[ind[i-1-j]] = sz;
    }
    i -= bk[i];
  }
  wt_L(dp[N]);
  wt_L(' ');
  wt_L(sz);
  wt_L('\n');
  {
    int a2conNHc;
    if(N==0){
      putchar('\n');
    }
    else{
      for(a2conNHc=(0);a2conNHc<(N-1);a2conNHc++){
        wt_L(res[a2conNHc]);
        wt_L(' ');
      }
      wt_L(res[a2conNHc]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], ind[2d5];
// int res[2d5], dp[200001], bk[200001], sz;
// {
//   rd(N,A(N));
//   rep(i,N) ind[i] = i;
//   sortA(N,A,ind);
//   dp[0] = 0;
//   rep(i,N){
//     dp[i+1] = int_inf;
//     rep(j,3,6) if(i-j+1 >= 0 && dp[i+1] > dp[i-j+1] + A[i] - A[i-j+1]){
//       dp[i+1] = dp[i-j+1] + A[i] - A[i-j+1];
//       bk[i+1] = j;
//     }
//   }
//   while(i){
//     sz++;
//     rep(j,bk[i]) res[ind[i-1-j]] = sz;
//     i -= bk[i];
//   }
//   wt(dp[N], sz);
//   wt(res(N));
// }