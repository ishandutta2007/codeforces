#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16]={0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> > *arr;
  walloc1d(&arr, N, &mem);
  for(i=0;i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=0;i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
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
template<class S> void arrErase(int k, int &sz, S a[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
}
template<class S, class T> void arrErase(int k, int &sz, S a[], T b[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
}
template<class S, class T, class U> void arrErase(int k, int &sz, S a[], T b[], U c[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
  for(i=(k);i<(sz);i++){
    c[i] = c[i+1];
  }
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
char memarr[96000000];
int N;
int R;
int A[100];
int B[100];
int dp[60001];
int nx[60001];
int val[100];
int main(){
  int NN, i, j, k, res=0;
  wmem = memarr;
  rd(N);
  rd(R);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
      rd(B[Lj4PdHRW]);
    }
  }
  NN = N;
  for(;;){
    int fg=0;
    for(i=0;i<(N);i++){
      if(A[i] <= R && B[i] >= 0){
        R += B[i];
        res++;
        fg = 1;
        arrErase(i, N, A, B);
        break;
      }
    }
    if(!fg){
      break;
    }
  }
  k = 0;
  for(i=0;i<(N);i++){
    if(B[i] < 0){
      A[k] = A[i];
      B[k++] = B[i];
    }
  }
  N = k;
  for(i=0;i<(N);i++){
    val[i] = - (A[i] + B[i]);
  }
  sortA_L(N, val, A, B);
  for(k=0;k<(N);k++){
    for(i=(max_L(A[k], -B[k]));i<(R+1);i++){
      chmax(dp[i+B[k]], dp[i]+1);
    }
  }
  {
    int Q5VJL1cS, e98WHCEY;
    if(R+1==0){
      e98WHCEY = 0;
    }
    else{
      e98WHCEY = dp[0];
      for(Q5VJL1cS=(1);Q5VJL1cS<(R+1);Q5VJL1cS++){
        e98WHCEY = max_L(e98WHCEY, dp[Q5VJL1cS]);
      }
    }
    res +=e98WHCEY;
  }
  if(res==NN){
    wt_L("YES");
    wt_L('\n');
  }
  else{
    wt_L("NO");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int N, R, A[100], B[100];
// 
// int dp[60001], nx[60001], val[100];
// 
// {
//   int i, j, k, res = 0, NN;
//   
//   rd(N,R,(A,B)(N));
//   NN = N;
// 
//   for(;;){
//     int fg = 0;
//     rep(i,N){
//       if(A[i] <= R && B[i] >= 0){
//         R += B[i];
//         res++;
//         fg = 1;
//         arrErase(i, N, A, B);
//         break;
//       }
//     }
//     if(!fg) break;
//   }
// 
//   k = 0;
//   rep(i,N) if(B[i] < 0){
//     A[k] = A[i];
//     B[k++] = B[i];
//   }
//   N = k;
// 
//   rep(i,N) val[i] = - (A[i] + B[i]);
//   sortA(N, val, A, B);
// 
//   rep(k,N){
//     rep(i,max(A[k],-B[k]),R+1){
//       dp[i+B[k]] >?= dp[i]+1;
//     }
//   }
// 
//   res += max(dp(R+1));
//   wt(if[res==NN, "YES", "NO"]);
// }