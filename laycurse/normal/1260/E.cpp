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
int N;
int A[300000];
char chk[300000];
int main(){
  wmem = memarr;
  int i;
  int j;
  long long res = 0;
  Heap<int> hp;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int cTE1_r3A;
    int RZTsC2BF = 0;
    int FmcKpFmN;
    int xr20shxY;
    int WYIGIcGE;
    for(cTE1_r3A=(0);cTE1_r3A<(((N)-1)+1);cTE1_r3A++){
      xr20shxY = A[cTE1_r3A];
      if(RZTsC2BF==0 || FmcKpFmN>xr20shxY){
        FmcKpFmN = xr20shxY;
        RZTsC2BF = 1;
        WYIGIcGE = cTE1_r3A;
      }
    }
    j =WYIGIcGE;
  }
  for(i=(0);i<(j+1);i++){
    A[i] = 0;
  }
  for(i=(0);i<(19);i++){
    chk[(1<<i)-1] = 1;
  }
  hp.malloc(N);
  hp.init();
  for(i=(N)-1;i>=(0);i--){
    hp.push(A[i]);
    if(chk[i]){
      res += hp.pop();
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200214-1

// --- original code ---
// //no-unlocked
// int N;
// int A[3d5]; char chk[3d5];
// {
//   int i, j;
//   ll res = 0;
//   Heap<int> hp;
//   rd(N,A(N));
//   j = argmin(A(N));
//   rep(i,j+1) A[i] = 0;
// 
//   rep(i,19) chk[(1<<i)-1] = 1;
// 
//   hp.malloc(N);
//   hp.init();
//   rrep(i,N){
//     hp.push(A[i]);
//     if(chk[i]) res += hp.pop();
//   }
//   wt(res);
// }