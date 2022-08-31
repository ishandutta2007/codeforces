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
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> > *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
}
template<class T1, class T2, class T3, class T4> void sortA_L(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem = wmem){
  int i;
  pair<pair<T1, T2>, pair<T3, T4> > *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first.first = a[i];
    arr[i].first.second = b[i];
    arr[i].second.first = c[i];
    arr[i].second.second = d[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first.first;
    b[i] = arr[i].first.second;
    c[i] = arr[i].second.first;
    d[i] = arr[i].second.second;
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
template<class S> void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
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
template<class S, class T, class U> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
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
int N;
int X[50000];
int Y[50000];
int Z[50000];
int ind[50000];
int ress;
int res1[50000];
int res2[50000];
int main(){
  int i;
  wmem = memarr;
  int k;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);
      rd(Y[Lj4PdHRW]);
      rd(Z[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    ind[i] = i + 1;
  }
  sortA_L(N, X, Y, Z, ind);
  for(i=(1);i<(N);i++){
    if(X[i]==X[i-1] && Y[i]==Y[i-1] && ind[i] >= 0 && ind[i-1] >= 0){
      arrInsert(ress, ress, res1, ind[i-1], res2, ind[i]);
      ind[i-1] = ind[i] = -1;
    }
  }
  k = N;
  N = 0;
  for(i=(0);i<(k);i++){
    if(ind[i] >= 0){
      X[N] = X[i];
      Y[N] = Y[i];
      ind[N] = ind[i];
      N++;
    }
  }
  for(i=(1);i<(N);i++){
    if(X[i]==X[i-1] && ind[i] >= 0 && ind[i-1] >= 0){
      arrInsert(ress, ress, res1, ind[i-1], res2, ind[i]);
      ind[i-1] = ind[i] = -1;
    }
  }
  k = N;
  N = 0;
  for(i=(0);i<(k);i++){
    if(ind[i] >= 0){
      X[N] = X[i];
      ind[N] = ind[i];
      N++;
    }
  }
  for(i=(1);i<(N);i++){
    if(ind[i] >= 0 && ind[i-1] >= 0){
      arrInsert(ress, ress, res1, ind[i-1], res2, ind[i]);
      ind[i-1] = ind[i] = -1;
    }
  }
  for(i=(0);i<(ress);i++){
    wt_L(res1[i]);
    wt_L(' ');
    wt_L(res2[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191108-1

// --- original code ---
// //no-unlocked
// int N, X[5d4], Y[5d4], Z[5d4], ind[5d4];
// int ress, res1[5d4], res2[5d4];
// {
//   int k;
// 
//   rd(N,(X,Y,Z)(N));
//   rep(i,N) ind[i] = i + 1;
// 
//   sortA(N, X, Y, Z, ind);
// 
//   rep(i,1,N) if(X[i]==X[i-1] && Y[i]==Y[i-1] && ind[i] >= 0 && ind[i-1] >= 0){
//     arrInsert(ress, ress, res1, ind[i-1], res2, ind[i]);
//     ind[i-1] = ind[i] = -1;
//   }
//   k = N;
//   N = 0;
//   rep(i,k) if(ind[i] >= 0){
//     X[N] = X[i];
//     Y[N] = Y[i];
//     ind[N] = ind[i];
//     N++;
//   }
// 
//   rep(i,1,N) if(X[i]==X[i-1] && ind[i] >= 0 && ind[i-1] >= 0){
//     arrInsert(ress, ress, res1, ind[i-1], res2, ind[i]);
//     ind[i-1] = ind[i] = -1;
//   }
//   k = N;
//   N = 0;
//   rep(i,k) if(ind[i] >= 0){
//     X[N] = X[i];
//     ind[N] = ind[i];
//     N++;
//   }
// 
//   rep(i,1,N) if(ind[i] >= 0 && ind[i-1] >= 0){
//     arrInsert(ress, ress, res1, ind[i-1], res2, ind[i]);
//     ind[i-1] = ind[i] = -1;
//   }
// 
//   rep(i,ress) wt(res1[i], res2[i]);
// }