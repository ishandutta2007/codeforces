#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
template<class T> struct twoMultisets{
  multiset<T> a;
  multiset<T> b;
  T sa;
  T sb;
  twoMultisets(){
    clear();
  }
  void clear(){
    a.clear();
    b.clear();
    sa = sb = 0;
  }
  void insert(T x){
    if(b.size() == 0 || x < *b.begin()){
      a.insert(x);
      sa += x;
    }
    else{
      b.insert(x);
      sb += x;
    }
  }
  int erase(T x){
    typename multiset<T>::iterator it;
    it = a.find(x);
    if(it != a.end()){
      a.erase(it);
      sa -= x;
      return 1;
    }
    it = b.find(x);
    if(it != b.end()){
      b.erase(it);
      sb -= x;
      return 1;
    }
    return 0;
  }
  int size(void){
    return a.size() + b.size();
  }
  T allsum(void){
    return sa + sb;
  }
  void assign(int K){
    T x;
    typename multiset<T>::iterator it;
    while(a.size() < K){
      x = *b.begin();
      b.erase(b.begin());
      a.insert(x);
      sa += x;
      sb -= x;
    }
    while(a.size() > K){
      it = a.end();
      it--;
      x = *it;
      a.erase(it);
      b.insert(x);
      sa -= x;
      sb += x;
    }
  }
  T Kth(int K){
    assign(K);
    return *b.begin();
  }
  T Ksum(int K){
    assign(K);
    return sa;
  }
  T rKth(int K){
    return Kth(a.size() + b.size() - K - 1);
  }
  T rKsum(int K){
    assign(a.size() + b.size() - K);
    return sb;
  }
  T getMin(void){
    if(a.size()){
      return *a.begin();
    }
    if(b.size()){
      return *b.begin();
    }
    return 0;
  }
  T getMin(T x){
    if(a.size()){
      return *a.begin();
    }
    if(b.size()){
      return *b.begin();
    }
    return x;
  }
  T getMax(void){
    if(b.size()){
      return *b.rbegin();
    }
    if(a.size()){
      return *a.rbegin();
    }
    return 0;
  }
  T getMax(T x){
    if(b.size()){
      return *b.rbegin();
    }
    if(a.size()){
      return *a.rbegin();
    }
    return x;
  }
}
;
int N;
int A[300000];
int B[300000];
twoMultisets<int> s;
twoMultisets<int> t;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int res = 0;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
        rd(B[xr20shxY]);
      }
    }
    s.clear();
    for(i=(0);i<(N);i++){
      s.insert(A[i]);
    }
    t.clear();
    for(i=(0);i<(N);i++){
      t.insert(B[i]);
    }
    while(s.rKsum(N-N/4) < t.rKsum(N-N/4)){
      N++;
      res++;
      s.insert(100);
      t.insert(0);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[3d5], B[];
// twoMultisets<int> s, t;
// {
//   REP(rd_int()){
//     int res = 0;
//     rd(N,A(N),B(N));
//     s.clear();
//     rep(i,N) s.insert(A[i]);
//     t.clear();
//     rep(i,N) t.insert(B[i]);
//     while(s.rKsum(N-N/4) < t.rKsum(N-N/4)){
//       N++; res++;
//       s.insert(100);
//       t.insert(0);
//     }
//     wt(res);
//   }
// }