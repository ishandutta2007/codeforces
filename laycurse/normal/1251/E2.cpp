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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
template<class T> struct Heap{
  int size;
  T *val;
  void malloc(const int N){
    val = (T*) std::malloc(N*sizeof(T));
    size = 0;
  }
  void walloc(const int N, void **mem = &wmem){
    walloc1d(&val, N, mem);
    size = 0;
  }
  void free(){
    std::free(val);
  }
  void init(){
    size = 0;
  }
  void up(){
    int n = size - 1;
    int m;
    while(n){
      m = (n-1) / 2;
      if(val[m] <= val[n]){
        break;
      }
      swap(val[m], val[n]);
      n = m;
    }
  }
  void down(){
    int n = 0;
    int m;
    for(;;){
      m=2*n+1;
      if(m>=size){
        break;
      }
      if(m+1<size && val[m] > val[m+1]){
        m++;
      }
      if(val[m] >= val[n]){
        break;
      }
      swap(val[m], val[n]);
      n = m;
    }
  }
  T top(){
    return val[0];
  }
  T pop(){
    T res = val[0];
    size--;
    if(size > 0){
      val[0] = val[size];
      down();
    }
    return res;
  }
  T push(const T x){
    val[size++] = x;
    up();
    return x;
  }
}
;
template<class S> void wAdjEdge_L(const int N, const int M, const int *A, const S *B, int **res_sz, S ***res_B, void **mem = &wmem){
  int i;
  int j;
  int k;
  walloc1d(res_sz, N, mem);
  for(i=(0);i<(N);i++){
    (*res_sz)[i] = 0;
  }
  for(i=(0);i<(M);i++){
    (*res_sz)[A[i]]++;
  }
  walloc1d(res_B, N, mem);
  for(i=(0);i<(N);i++){
    walloc1d(&((*res_B)[i]), (*res_sz)[i], mem);
  }
  for(i=(0);i<(N);i++){
    (*res_sz)[i] = 0;
  }
  for(i=(0);i<(M);i++){
    (*res_B)[A[i]][(*res_sz)[A[i]]++] = B[i];
  }
}
int N;
int M[200000];
int P[200000];
int *num;
int **val;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  long long res;
  Heap<int> hp;
  hp.malloc(200000);
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(M[cTE1_r3A]);
        rd(P[cTE1_r3A]);
      }
    }
    res = 0;
    hp.init();
    wAdjEdge_L(N, N, M, P, &num, &val);
    for(i=(N)-1;i>=(0);i--){
      int j;
      for(j=(0);j<(num[i]);j++){
        hp.push(val[i][j]);
      }
      while(hp.size > N-i){
        res += hp.pop();
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191108-1

// --- original code ---
// //no-unlocked
// int N, M[2d5], P[2d5];
// int *num, **val;
// {
//   ll res;
//   Heap<int> hp;
//   hp.malloc(2d5);
//   REP(rd_int()){
//     rd(N,(M,P)(N));
//     res = 0;
//     hp.init();
//     wAdjEdge(N, N, M, P, &num, &val);
//     rrep(i,N){
//       rep(j,num[i]) hp.push(val[i][j]);
//       while(hp.size > N-i) res += hp.pop();
//     }
//     wt(res);
//   }
// }