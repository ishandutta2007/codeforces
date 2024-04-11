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
int main(){
  int i;
  int L;
  int R;
  int k;
  int cnt[10];
  rd(L);
  rd(R);
  for(i=(L);i<(R+1);i++){
    int j;
    k = i;
    for(j=(0);j<(10);j++){
      cnt[j] = 0;
    }
    while(k){
      cnt[k%10]++;
      k/=10;
    }
    for(j=(0);j<(10);j++){
      if(cnt[j]>1){
        break;
      }
    }
    if(j==10){
      wt_L(i);
      wt_L('\n');
      return 0;
    }
  }
  wt_L(-1);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191006-1

// --- original code ---
// //no-unlocked
// {
//   int L, R;
//   int k, cnt[10];
//   rd(L,R);
//   rep(i,L,R+1){
//     k = i;
//     rep(j,10) cnt[j] = 0;
//     while(k) cnt[k%10]++, k/=10;
//     rep(j,10) if(cnt[j]>1) break;
//     if(j==10) wt(i), return 0;
//   }
//   wt(-1);
// }