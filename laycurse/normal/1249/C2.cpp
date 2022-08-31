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
inline void rd(long long &x){
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
long long N;
int sz = 40;
long long pw[40];
long long sm[40];
int main(){
  int Q5VJL1cS, i;
  long long res;
  sm[0] = pw[0] = 1;
  for(i=(1);i<(sz);i++){
    sm[i] = sm[i-1] + (pw[i] = 3* pw[i-1]);
  }
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    rd(N);
    res = 0;
    while(N > 0){
      for(i=(0);i<(sz);i++){
        if(N <= sm[i]){
          N -= pw[i];
          res += pw[i];
          break;
        }
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// ll N;
// int sz = 40; ll pw[40], sm[40];
// {
//   ll res;
// 
//   sm[0] = pw[0] = 1;
//   rep(i,1,sz) sm[i] = sm[i-1] + (pw[i] = 3 pw[i-1]);
// 
//   REP(rd_int()){
//     rd(N);
//     res = 0;
//     while(N > 0){
//       rep(i,sz) if(N <= sm[i]) N -= pw[i], res += pw[i], break;
//     }
//     wt(res);
//   }
// }