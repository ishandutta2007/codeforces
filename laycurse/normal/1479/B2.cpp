#pragma GCC optimize ("Ofast")
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
template<class T> inline T getFirst(multiset<T> &a){
  return *(a.begin());
}
template<class T> inline T getFirst(set<T> &a){
  return *(a.begin());
}
int N;
int A[100000];
set<int> ind[100000+1];
int x;
int y;
int res;
int main(){
  int i;
  int k;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    ind[A[i]].insert(i);
  }
  for(i=(0);i<(N+1);i++){
    ind[i].insert(1073709056);
  }
  for(i=(0);i<(N);i++){
    k = A[i];
    ind[k].erase(i);
    if(x==k || y==k){
      continue;
    }
    res++;
    if(getFirst(ind[x]) < getFirst(ind[y])){
      y = k;
    }
    else{
      x = k;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210103-1 [bug fixed 2]

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// set<int> ind[1d5+1];
// int x, y, res;
// {
//   int i, k;
//   rd(N,A(N));
//   rep(i,N) ind[A[i]].insert(i);
//   rep(i,N+1) ind[i].insert(int_inf);
//   rep(i,N){
//     k = A[i];
//     ind[k].erase(i);
//     
//     if(x==k || y==k) continue;
//     res++;
//     if(getFirst(ind[x]) < getFirst(ind[y])){
//       y = k;
//     } else {
//       x = k;
//     }
//   }
//   wt(res);
// }