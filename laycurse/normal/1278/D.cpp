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
struct unionFind{
  int *d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void init(const int n){
    int i;
    N = n;
    for(i=(0);i<(n);i++){
      d[i] = -1;
    }
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    int t = a;
    int k;
    while(d[t]>=0){
      t=d[t];
    }
    while(d[a]>=0){
      k=d[a];
      d[a]=t;
      a=k;
    }
    return a;
  }
  inline int connect(int a, int b){
    if(d[a]>=0){
      a=get(a);
    }
    if(d[b]>=0){
      b=get(b);
    }
    if(a==b){
      return 0;
    }
    if(d[a] < d[b]){
      d[a] += d[b];
      d[b] = a;
    }
    else{
      d[b] += d[a];
      d[a] = b;
    }
    return 1;
  }
  inline int operator()(int a){
    return get(a);
  }
  inline int operator()(int a, int b){
    return connect(a,b);
  }
  inline int& operator[](const int a){
    return d[a];
  }
  inline int size(int a){
    a = get(a);
    return -d[a];
  }
  inline int sizeList(int res[]){
    int i;
    int sz=0;
    for(i=(0);i<(N);i++){
      if(d[i]<0){
        res[sz++] = -d[i];
      }
    }
    return sz;
  }
}
;
int N;
int L[500000];
int R[500000];
int ev[1000000];
int sz;
int arr[500000];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  unionFind uf;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(L[Lj4PdHRW]);L[Lj4PdHRW] += (-1);
      rd(R[Lj4PdHRW]);R[Lj4PdHRW] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    ev[L[i]] = i+1;
  }
  for(i=(0);i<(N);i++){
    ev[R[i]] = -(i+1);
  }
  uf.malloc(N);
  uf.init(N);
  for(i=(0);i<(2*N);i++){
    j = ev[i];
    if(ev[i] > 0){
      j = ev[i] - 1;
      arr[sz++] = j;
    }
    else{
      j = -ev[i] - 1;
      for(k=sz-1;;k--){
        if(arr[k]==j){
          break;
        }
        if(uf(arr[k],j)==0){
          wt_L("NO");
          wt_L('\n');
          return 0;
        }
      }
      arrErase(k,sz,arr);
    }
  }
  if(uf.size(0)==N){
    wt_L("YES");
    wt_L('\n');
  }
  else{
    wt_L("NO");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191214-1

// --- original code ---
// //no-unlocked
// int N, L[5d5], R[5d5], ev[1d6];
// int sz, arr[5d5];
// {
//   int i, j, k;
//   unionFind uf;
//   rd(N,(L--,R--)(N));
//   rep(i,N) ev[L[i]] = i+1;
//   rep(i,N) ev[R[i]] = -(i+1);
//   uf.malloc(N);
//   uf.init(N);
//   rep(i,2N){
//     j = ev[i];
//     if(ev[i] > 0){
//       j = ev[i] - 1;
//       arr[sz++] = j;
//     } else {
//       j = -ev[i] - 1;
//       for(k=sz-1;;k--){
//         if(arr[k]==j) break;
//         if(uf(arr[k],j)==0) wt("NO"), return 0;
//       }
//       arrErase(k,sz,arr);
//     }
//   }
//   wt(if[uf.size(0)==N, "YES", "NO"]);
// }