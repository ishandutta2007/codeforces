#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
inline void rd(int &x){
  int k, m=0;
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
  char f[10];
  int m=0, s=0;
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
int main(){
  int Lj4PdHRW, N, cnt[2]={}, res;
  rd(N);
  for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
    cnt[rd_int()%2]++;
  }
  {
    int KL2GvlyY, Q5VJL1cS;
    if(2==0){
      Q5VJL1cS = 0;
    }
    else{
      Q5VJL1cS = cnt[0];
      for(KL2GvlyY=(1);KL2GvlyY<(2);KL2GvlyY++){
        Q5VJL1cS = min_L(Q5VJL1cS, cnt[KL2GvlyY]);
      }
    }
    res =Q5VJL1cS;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// {
//   int N, cnt[2] = {}, res;
//   rd(N);
//   rep(N) cnt[rd_int()%2]++;
//   res = min(cnt(2));
//   wt(res);
// }