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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[1000000];
int nn;
int aa[1000000];
int solve(int N, int A[]){
  int i;
  int res = 0;
  int mask = 0;
  map<int,int> mp;
  mp[0] = -1;
  for(i=(0);i<(N);i++){
    mask ^= A[i];
    if(!mp.count(mask)){
      mp[mask] = i;
    }
    chmax(res, i - mp[mask]);
  }
  return res;
}
int main(){
  int bt;
  rd(N);
  {
    int Q5VJL1cS;
    for(Q5VJL1cS=(0);Q5VJL1cS<(N);Q5VJL1cS++){
      rd(A[Q5VJL1cS]);
    }
  }
  int i;
  int j;
  int res = 0;
  int mask = 0;
  for(bt=(31)-1;bt>=(0);bt--){
    mask |= (1<<bt);
    for(i=(0);i<(N);i++){
      if(((A[i]) &(1<<(bt)))){
        nn = 0;
        while(i < N &&((A[i]) &(1<<(bt)))){
          aa[nn++] = (A[i++] & mask);
        }
        chmax(res, solve(nn, aa));
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int N, A[1d6];
// 
// int nn, aa[];
// int solve(int N, int A[]){
//   int res = 0, mask = 0;
//   map<int,int> mp;
//   mp[0] = -1;
//   rep(i,N){
//     mask ^= A[i];
//     if(!mp.count(mask)) mp[mask] = i;
//     res >?= i - mp[mask];
//   }
//   // wt(A(N),":",res);
//   return res;
// }
// 
// {
//   rd(N,A(N));
//   int i, j, res = 0, mask = 0;
//   rrep(bt,31){
//     mask |= (1<<bt);
//     rep(i,N) if(BIT_ith(A[i], bt)){
//       nn = 0;
//       while(i < N && BIT_ith(A[i], bt)) aa[nn++] = (A[i++] & mask);
//       res >?= solve(nn, aa);
//     }
//   }
//   wt(res);
// }