#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
inline int my_getchar(){
  return getchar();
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
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
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
int main(){
  int N;
  rd(N);
  int i;
  int k;
  int b;
  int r;
  int per;
  int mx = -1;
  int tmp;
  int now[1000] = {};
  int sz;
  int lis[1000];
  if(N <= 3){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  for(k=(2);k<(N+1);k++){
    {
      auto Q5VJL1cS = (N / k);
      auto e98WHCEY = ( N % k);
      b = Q5VJL1cS;
      r = e98WHCEY;
    }
    if(b < k){
      break;
    }
    tmp = (k-1) * (b-1) +max_L(0, r-1);
    if(mx < tmp){
      mx = tmp;
      per = k;
    }
  }
  for(;;){
    sz = 0;
    for(i=(0);i<(N);i++){
      if(now[i]==0 && i%per!=per-1 && i!=N-1){
        lis[sz++] = i;
      }
    }
    if(sz < per){
      break;
    }
    for(i=(0);i<(per);i++){
      now[lis[i]] = 1;
    }
    wt_L(per);
    wt_L(' ');
    {
      int ao_dF3pO;
      if(per==0){
        wt_L('\n');
      }
      else{
        for(ao_dF3pO=(0);ao_dF3pO<(per-1);ao_dF3pO++){
          wt_L(lis[ao_dF3pO]+1);
          wt_L(' ');
        }
        wt_L(lis[ao_dF3pO]+1);
        wt_L('\n');
      }
    }
    rd(k);k += (-1);
    for(i=(0);i<(per);i++){
      now[(k+i)%N] = 0;
    }
  }
  wt_L(0);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200911-1

// --- original code ---
// //interactive
// {
//   int @N;
//   int i, k, b, r, per, mx = -1, tmp, now[1000] = {};
//   int sz, lis[1000];
// 
//   if(N <= 3) wt(0), return 0;
// 
//   rep(k,2,N+1){
//     (b, r) = (N / k, N % k);
//     if(b < k) break;
//     tmp = (k-1) * (b-1) + max(0, r-1);
//     if(mx < tmp) mx = tmp, per = k;
//   }
// 
//   for(;;){
//     sz = 0;
//     rep(i,N) if(now[i]==0 && i%per!=per-1 && i!=N-1) lis[sz++] = i;
//     if(sz < per) break;
// 
//     rep(i,per) now[lis[i]] = 1;
//     wt(per, lis(per)+1);
// 
//     rd(k--);
//     rep(i,per) now[(k+i)%N] = 0;
//   }
//   wt(0);
// }