#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
int N;
int L;
int S[100000];
int mn[100000];
int mx[100000];
int has[100000];
int cnt[1000000+2];
int main(){
  int i;
  long long res = 0;
  rd(N);
  for(i=(0);i<(N);i++){
    int j;
    rd(L);
    {
      int Q5VJL1cS;
      for(Q5VJL1cS=(0);Q5VJL1cS<(L);Q5VJL1cS++){
        rd(S[Q5VJL1cS]);
      }
    }
    {
      int RZTsC2BF;
      int FmcKpFmN;
      if(L==0){
        FmcKpFmN = 0;
      }
      else{
        FmcKpFmN = S[0];
        for(RZTsC2BF=(1);RZTsC2BF<(L);RZTsC2BF++){
          FmcKpFmN = min_L(FmcKpFmN, S[RZTsC2BF]);
        }
      }
      mn[i] =FmcKpFmN;
    }
    {
      int t_ynMSdg;
      int KrdatlYV;
      if(L==0){
        KrdatlYV = 0;
      }
      else{
        KrdatlYV = S[0];
        for(t_ynMSdg=(1);t_ynMSdg<(L);t_ynMSdg++){
          KrdatlYV = max_L(KrdatlYV, S[t_ynMSdg]);
        }
      }
      mx[i] =KrdatlYV;
    }
    for(j=(1);j<(L);j++){
      if(S[j-1] < S[j]){
        has[i] = 1;
      }
    }
  }
  for(i=(0);i<(N);i++){
    if(has[i]){
      cnt[1000000+1]++;
    }
    else{
      cnt[mx[i]]++;
    }
  }
  for(i=(1000000+2)-1;i>=(1);i--){
    cnt[i-1] += cnt[i];
  }
  for(i=(0);i<(N);i++){
    if(has[i]){
      res += N;
      continue;
    }
    res += cnt[mn[i]+1];
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// int N, L, S[1d5];
// int mn[1d5], mx[1d5], has[1d5];
// 
// int cnt[1d6+2];
// 
// {
//   ll res = 0;
//   rd(N);
//   rep(i,N){
//     rd(L,S(L));
//     mn[i] = min(S(L));
//     mx[i] = max(S(L));
//     rep(j,1,L) if(S[j-1] < S[j]) has[i] = 1;
//   }
//   rep(i,N) cnt[if[has[i], 1d6+1, mx[i]]]++;
//   rrep(i,1,1d6+2) cnt[i-1] += cnt[i];
//   rep(i,N){
//     if(has[i]) res += N, continue;
//     res += cnt[mn[i]+1];
//   }
//   wt(res);
// }