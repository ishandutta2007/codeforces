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
int M;
int A;
int B;
int mx[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int i;
  int j;
  int res = 0;
  unionFind uf;
  rd(N);
  rd(M);
  uf.malloc(N);
  uf.init(N);
  for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
    rd(A);A += (-1);
    rd(B);B += (-1);
    uf(A,B);
  }
  for(i=(0);i<(N);i++){
    mx[uf(i)] = i;
  }
  for(i=(0);i<(N);i++){
    j = mx[uf(i)];
    while(i < j){
      if(uf(i) != uf(i+1)){
        res++;
        chmax(j, mx[uf(i+1)]);
        uf(i, i+1);
      }
      i++;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191123-1

// --- original code ---
// //no-unlocked
// int N, M, A, B;
// int mx[2d5];
// {
//   int i, j, res = 0;
//   unionFind uf;
//   rd(N,M);
//   uf.malloc(N);
//   uf.init(N);
//   rep(M){
//     rd(A--,B--);
//     uf(A,B);
//   }
//   rep(i,N) mx[uf(i)] = i;
//   rep(i,N){
//     j = mx[uf(i)];
//     while(i < j){
//       if(uf(i) != uf(i+1)){
//         res++;
//         j >?= mx[uf(i+1)];
//         uf(i, i+1);
//       }
//       i++;
//     }
//   }
//   wt(res);
// }