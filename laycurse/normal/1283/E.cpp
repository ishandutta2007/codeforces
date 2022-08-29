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
int N;
int cnt[200000+2];
int tmp[200000+2];
int ad[200000+2];
int main(){
  int Lj4PdHRW, i;
  int res1 = 0;
  int res2 = 0;
  rd(N);
  for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
    cnt[rd_int()]++;
  }
  N += 2;
  for(i=(0);i<(N);i++){
    tmp[i] = cnt[i];
  }
  for(i=(0);i<(N);i++){
    if(tmp[i]==0){
      continue;
    }
    if(tmp[i-1]){
      tmp[i] = 0;
      continue;
    }
    tmp[i+1] += tmp[i];
    tmp[i] = 0;
    i++;
  }
  for(i=(0);i<(N);i++){
    if(tmp[i]){
      res1++;
    }
  }
  for(i=(0);i<(N);i++){
    tmp[i] = cnt[i];
  }
  for(i=(0);i<(N);i++){
    ad[i] = 0;
  }
  for(i=(0);i<(N);i++){
    if(tmp[i]==0){
      continue;
    }
    if(tmp[i] && tmp[i-1] + ad[i-1] == 0){
      tmp[i]--;
      tmp[i-1]++;
    }
    if(ad[i] + tmp[i] > 1){
      tmp[i]--;
      ad[i+1]++;
    }
  }
  for(i=(0);i<(N);i++){
    if(tmp[i]+ad[i]){
      res2++;
    }
  }
  wt_L(res1);
  wt_L(' ');
  wt_L(res2);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// //no-unlocked
// int N, cnt[2d5+2];
// int tmp[2d5+2], ad[2d5+2];
// {
//   int res1 = 0, res2 = 0;
//   rd(N);
//   rep(N) cnt[rd_int()]++;
//   N += 2;
// 
//   rep(i,N) tmp[i] = cnt[i];
//   rep(i,N){
//     if(tmp[i]==0) continue;
//     if(tmp[i-1]) tmp[i] = 0, continue;
//     tmp[i+1] += tmp[i];
//     tmp[i] = 0;
//     i++;
//   }
//   rep(i,N) if(tmp[i]) res1++;
// 
//   rep(i,N) tmp[i] = cnt[i];
//   rep(i,N) ad[i] = 0;
//   rep(i,N){
//     if(tmp[i]==0) continue;
//     if(tmp[i] && tmp[i-1] + ad[i-1] == 0) tmp[i]--, tmp[i-1]++;
//     if(ad[i] + tmp[i] > 1) tmp[i]--, ad[i+1]++;
//   }
//   rep(i,N) if(tmp[i]+ad[i]) res2++;
// 
//   wt(res1, res2);
// }