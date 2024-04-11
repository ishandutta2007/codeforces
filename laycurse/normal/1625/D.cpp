#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1, class T2> void sortA_index_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    b[i] = i;
  }
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
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
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
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
inline void wt_L(char a){
  my_putchar(a);
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int xorMax(int X, int N, int A[], int bt = 31){
  int i;
  int k;
  for(i=(bt)-1;i>=(0);i--){
    if(!(A[N-1] & 1 << i)){
      continue;
    }
    if(A[0] & 1 << i){
      X ^= (1 << i);
      continue;
    }
    k = lower_bound(A, A+N, A[N-1] & (~((1 << i) - 1))) - A;
    if(!(X & 1 << i)){
      X ^= (1 << i);
      A += k;
      N -= k;
    }
    else{
      N = k;
    }
  }
  return X;
}
long long xorMax(long long X, int N, long long A[], int bt = 63){
  int i;
  int k;
  for(i=(bt)-1;i>=(0);i--){
    if(!(A[N-1] & 1LL << i)){
      continue;
    }
    if(A[0] & 1LL << i){
      X ^= (1LL << i);
      continue;
    }
    k = lower_bound(A, A+N, A[N-1] & (~((1LL << i) - 1))) - A;
    if(!(X & 1LL << i)){
      X ^= (1LL << i);
      A += k;
      N -= k;
    }
    else{
      N = k;
    }
  }
  return X;
}
int N;
int K;
int A[300000];
int ind[300000];
int ress;
int res[300000];
void solve(int x, int y, int b){
  if(x > y){
    return;
  }
  int z = x;
  int i;
  int j;
  int mx;
  int tmp;
  int mxi;
  while(z <= y && !((A[z]) &(1<<(b)))){
    z++;
  }
  if(((K) &(1<<(b)))){
    if(z==x || z==y+1){
      res[ress++] = ind[x];
      return;
    }
    for(i=(x);i<(z);i++){
      tmp = xorMax(A[i], y-z+1, A+z);
      if(mx < tmp){
        mx = tmp;
        mxi = i;
      }
    }
    if(mx < K){
      res[ress++] = ind[x];
      return;
    }
    for(j=(z);j<(y+1);j++){
      if((A[mxi]^A[j]) == mx){
        res[ress++] = ind[mxi];
        res[ress++] = ind[j];
        break;
      }
    }
  }
  else{
    solve(x,z-1,b-1);
    solve(z,y,b-1);
  }
}
int main(){
  wmem = memarr;
  rd(N);
  rd(K);
  {
    int R5MtCiij;
    for(R5MtCiij=(0);R5MtCiij<(N);R5MtCiij++){
      rd(A[R5MtCiij]);
    }
  }
  if(K==0){
    int i;
    for(i=(0);i<(N);i++){
      res[i] = i;
    }
    wt_L(N);
    wt_L('\n');
    {
      int wbH8AaCb;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(wbH8AaCb=(0);wbH8AaCb<(N-1);wbH8AaCb++){
          wt_L(res[wbH8AaCb]+1);
          wt_L(' ');
        }
        wt_L(res[wbH8AaCb]+1);
        wt_L('\n');
      }
    }
    return 0;
  }
  sortA_index_L(N,A,ind);
  solve(0, N-1, 30);
  if(ress<=1){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  wt_L(ress);
  wt_L('\n');
  {
    int Dc_3QP3Y;
    if(ress==0){
      wt_L('\n');
    }
    else{
      for(Dc_3QP3Y=(0);Dc_3QP3Y<(ress-1);Dc_3QP3Y++){
        wt_L(res[Dc_3QP3Y]+1);
        wt_L(' ');
      }
      wt_L(res[Dc_3QP3Y]+1);
      wt_L('\n');
    }
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20211231-1

// --- original code ---
// //no-unlocked
// int N, K, A[3d5], ind[];
// int ress, res[];
// 
// void solve(int x, int y, int b){
//   if(x > y) return;
// 
//   int z = x, i, j, mx, tmp, mxi;
//   while(z <= y && !BIT_ith(A[z],b)) z++;
// 
//   // wtSp(b,":");
//   // rep(i,x,y+1) wtSp(A[i]); wt("");
// 
//   if(BIT_ith(K,b)){
//     if(z==x || z==y+1) res[ress++] = ind[x], return;
//     rep(i,x,z){
//       tmp = xorMax(A[i], y-z+1, A+z);
//       if(mx < tmp) mx = tmp, mxi = i;
//     }
//     if(mx < K) res[ress++] = ind[x], return;
//     rep(j,z,y+1) if((A[mxi]^A[j]) == mx){
//       res[ress++] = ind[@[mxi,j]];
//       break;
//     }
//   } else {
//     solve(x,z-1,b-1);
//     solve(z,y,b-1);
//   }
// }
// 
// {
//   rd(N,K,A(N));
// 
//   if(K==0){
//     rep(i,N) res[i] = i;
//     wt(N);
//     wt(res(N)+1);
//     return 0;
//   }
//   sortA_index(N,A,ind);
// 
//   solve(0, N-1, 30);
//   // wt(ress,":",res(ress));
//   if(ress<=1) wt(-1), return 0;
// 
//   wt(ress);
//   wt(res(ress)+1);
// }