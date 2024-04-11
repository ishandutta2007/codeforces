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
long long N;
int M;
int cnt[31];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int FmcKpFmN;
    int i;
    int k;
    int res = 0;
    long long s = 0;
    rd(N);
    rd(M);
    for(i=(0);i<(31);i++){
      cnt[i] = 0;
    }
    for(FmcKpFmN=(0);FmcKpFmN<(M);FmcKpFmN++){
      rd(k);
      s += k;
      i = 0;
      while(k>1){
        k/=2;
        i++;
      }
      cnt[i]++;
    }
    if(s < N){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    k = 30;
    while(N){
      if(cnt[k]==0){
        k--;
        continue;
      }
      if(N >= (1<<k)){
        cnt[k]--;
        N -= (1<<k);
        s -= (1<<k);
        continue;
      }
      if(N <= s - (1<<k)){
        cnt[k]--;
        s -= (1<<k);
        continue;
      }
      res++;
      cnt[k]--;
      cnt[k-1]+=2;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// ll N; int M, cnt[31];
// {
//   REP(rd_int()){
//     int i, k, res = 0;
//     ll s = 0;
//     rd(N,M);
//     rep(i,31) cnt[i] = 0;
//     rep(M){
//       rd(k);
//       s += k;
//       i = 0;
//       while(k>1) k/=2, i++;
//       cnt[i]++;
//     }
//     if(s < N) wt(-1), continue;
// 
//     k = 30;
//     while(N){
//       if(cnt[k]==0) k--, continue;
//       if(N >= (1<<k)) cnt[k]--, N -= (1<<k), s -= (1<<k), continue;
//       if(N <= s - (1<<k)) cnt[k]--, s -= (1<<k), continue;
//       res++;
//       cnt[k]--;
//       cnt[k-1]+=2;
//     }
//     wt(res);
//   }
// }