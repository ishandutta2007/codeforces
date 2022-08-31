#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[100000];
int B[100000];
int sa[100001];
int sb[100001];
map<int,int> mp;
int main(){
  int Lj4PdHRW;
  int res;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
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
    reverse(B,B+N);
    for(i=(0);i<(N);i++){
      if(A[i]==1){
        sa[i+1] = sa[i] +-1;
      }
      else{
        sa[i+1] = sa[i] +1;
      }
    }
    for(i=(0);i<(N);i++){
      if(B[i]==1){
        sb[i+1] = sb[i] +-1;
      }
      else{
        sb[i+1] = sb[i] +1;
      }
    }
    res = 0;
    mp.clear();
    for(i=(0);i<(N+1);i++){
      mp[sa[i]] = i;
    }
    for(i=(0);i<(N+1);i++){
      if(mp.count(-sb[i])){
        chmax(res, i + mp[-sb[i]]);
      }
    }
    wt_L(2*N-res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191214-1

// --- original code ---
// //no-unlocked
// int N, A[1d5], B[1d5];
// int sa[100001], sb[100001];
// map<int,int> mp;
// {
//   int res;
//   REP(rd_int()){
//     rd(N,A(N),B(N));
//     reverse(B,B+N);
// 
//     rep(i,N) sa[i+1] = sa[i] + if[A[i]==1, -1, 1];
//     rep(i,N) sb[i+1] = sb[i] + if[B[i]==1, -1, 1];
// 
//     res = 0;
//     mp.clear();
//     rep(i,N+1) mp[sa[i]] = i;
//     rep(i,N+1) if(mp.count(-sb[i])) res >?= i + mp[-sb[i]];
// 
//     wt(2N-res);
//   }
// }