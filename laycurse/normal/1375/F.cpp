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
long long A[3];
int ind[3] = {1,2,3};
int d = -1;
int doit(long long x){
  int i;
  int k;
  printf("%lld\n",x);
  fflush(stdout);
  scanf("%d", &i);
  if(i==0){
    return 1;
  }
  d = i;
  for(k=(0);k<(3);k++){
    if(ind[k]==i){
      A[k] += x;
    }
  }
  return 0;
}
int main(){
  wmem = memarr;
  long long x;
  scanf("%lld%lld%lld",A,A+1,A+2);
  printf("First\n");
  fflush(stdout);
  for(;;){
    sortA_L(3, A, ind);
    if(d!=ind[2]){
      x = A[2];
    }
    else if(A[2] - A[1] == A[1] - A[0]){
      x = A[1] - A[0];
    }
    else{
      x = 2 * A[2] - A[1] - A[0];
    }
    if(doit(x)){
      break;
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// ll A[3];
// int ind[3] = {1,2,3}, d = -1;
// 
// int doit(ll x){
//   int i, k;
//   printf("%lld\n",x);
//   fflush(stdout);
//   scanf("%d", &i);
//   if(i==0) return 1;
//   d = i;
//   rep(k,3) if(ind[k]==i) A[k] += x;
//   return 0;
// }
// 
// {
//   ll x;
//   scanf("%lld%lld%lld",A,A+1,A+2);
//   printf("First\n");
//   fflush(stdout);
// 
//   for(;;){
//     sortA(3, A, ind);
//     if(d!=ind[2]){
//       x = A[2];
//     } else if(A[2] - A[1] == A[1] - A[0]) {
//       x = A[1] - A[0];
//     } else {
//       x = 2 * A[2] - A[1] - A[0];
//     }
//     if(doit(x)) break;
//   }
// }