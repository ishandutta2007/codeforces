#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
int L[200000];
int R[200000];
int inc[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int cur;
  Heap<pair<int,int>> hp;
  hp.walloc(200000);
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(L[cTE1_r3A]);
        rd(R[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      R[i] = -R[i];
    }
    sortA_L(N,L,R);
    for(i=(0);i<(N);i++){
      R[i] = -R[i];
    }
    cur = 0;
    hp.init();
    for(i=(0);i<(N);i++){
      inc[i] = 0;
    }
    for(i=(0);i<(N);i++){
      while(hp.size && hp.top().first < L[i]){
        hp.pop();
      }
      if(hp.size==0){
        cur++;
        inc[i]--;
      }
      if(hp.size==1){
        inc[hp.top().second]++;
      }
      hp.push( make_pair(R[i], i) );
    }
    {
      int YREPHmFM;
      int jZyWAPpY;
      if(N==0){
        jZyWAPpY = 0;
      }
      else{
        jZyWAPpY = inc[0];
        for(YREPHmFM=(1);YREPHmFM<(N);YREPHmFM++){
          jZyWAPpY = max_L(jZyWAPpY, inc[YREPHmFM]);
        }
      }
      cur +=jZyWAPpY;
    }
    wt_L(cur);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// int N, L[2d5], R[2d5];
// int inc[2d5];
// {
//   int cur;
//   Heap<pair<int,int>> hp;
//   hp.walloc(2d5);
//   REP(rd_int()){
//     rd(N,(L,R)(N));
//     
//     rep(i,N) R[i] = -R[i];
//     sortA(N,L,R);
//     rep(i,N) R[i] = -R[i];
// 
//     cur = 0;
//     hp.init();
//     rep(i,N) inc[i] = 0;
//     rep(i,N){
//       while(hp.size && hp.top().first < L[i]) hp.pop();
//       if(hp.size==0) cur++, inc[i]--;
//       if(hp.size==1) inc[hp.top().second]++;
//       hp.push( make_pair(R[i], i) );
//     }
// 
//     cur += max(inc(N));
//     wt(cur);
//   }
// }