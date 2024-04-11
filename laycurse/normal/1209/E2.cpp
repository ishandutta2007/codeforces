#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
  for(i=0;i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=0;i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int TEST;
int N;
int M;
int A[12][2000];
int dp[4096];
int nx[4096];
int mx[2000];
int ind[4096];
int s[4096];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int i;
  int j;
  int k;
  int kk;
  int m;
  rd(TEST);
  for(Lj4PdHRW=0;Lj4PdHRW<(TEST);Lj4PdHRW++){
    rd(N);
    rd(M);
    for(i=0;i<(N);i++){
      for(j=0;j<(M);j++){
        rd(A[i][j]);
      }
    }
    for(j=0;j<(M);j++){
      ind[j] = j;
      mx[j] = 0;
      for(i=0;i<(N);i++){
        chmax(mx[j], A[i][j]);
      }
    }
    rsortA_L(M, mx, ind);
    for(i=0;i<(1<<N);i++){
      dp[i] = 0;
    }
    for(kk=0;kk<(min_L(N, M));kk++){
      k = ind[kk];
      for(i=0;i<(1<<N);i++){
        s[i] = 0;
        for(j=0;j<(N);j++){
          if(i&1<<j){
            s[i] += A[j][k];
          }
        }
      }
      for(m=0;m<(N);m++){
        for(i=0;i<(1<<N);i++){
          j = 2*i;
          if(j >= (1<<N)){
            j ^= ((1<<N) | 1);
          }
          chmax(s[i], s[j]);
        }
      }
      for(i=0;i<(1<<N);i++){
        nx[i] = dp[i];
      }
      for(i=0;i<(1<<N);i++){
        m = ((1<<N)-1) ^ i;
        for(j=m; j; j = ((j-1)&m)){
          chmax(nx[i|j], dp[i] + s[j]);
        }
      }
      for(i=0;i<(1<<N);i++){
        dp[i] = nx[i];
      }
    }
    wt_L(nx[(1<<N)-1]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int TEST, N, M, A[12][2000];
// int dp[4096], nx[4096], mx[2000], ind[4096], s[4096];
// {
//   int i, j, k, kk, m;
//   
//   rd(TEST);
//   rep(TEST){
//     rd(N,M);
//     rep(i,N) rep(j,M) rd(A[i][j]);
//     rep(j,M){
//       ind[j] = j;
//       mx[j] = 0;
//       rep(i,N) mx[j] >?= A[i][j];
//     }
//     rsortA(M, mx, ind);
// 
//     rep(i,1<<N) dp[i] = 0;
//     rep(kk,min(N,M)){
//       k = ind[kk];
//       rep(i,1<<N){
//         s[i] = 0;
//         rep(j,N) if(i&1<<j) s[i] += A[j][k];
//       }
//       rep(m,N){
//         rep(i,1<<N){
//           j = 2*i;
//           if(j >= (1<<N)) j ^= ((1<<N) | 1);
//           s[i] >?= s[j];
//         }
//       }
//       rep(i,1<<N) nx[i] = dp[i];
//       rep(i,1<<N){
//         m = ((1<<N)-1) ^ i;
//         for(j=m; j; j = ((j-1)&m)){
//           nx[i|j] >?= dp[i] + s[j];
//         }
//       }
//       rep(i,1<<N) dp[i] = nx[i];
//     }
//     
//     wt(nx[(1<<N)-1]);
//   }
// }