#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
int N;
int cnt[150002];
int main(){
  int Lj4PdHRW, i, res=0;
  rd(N);
  for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
    rd(i);i += (-1);
    cnt[i]++;
  }
  for(i=0;i<(150001);i++){
    if(i && cnt[i-1]){
      res++;
    }
    else if(cnt[i]){
      cnt[i]--;
      res++;
    }
    else if(cnt[i+1]){
      cnt[i+1]--;
      res++;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int N, cnt[150002];
// {
//   int i, res = 0;
// 
//   rd(N);
//   rep(N){
//     rd(i--);
//     cnt[i]++;
//   }
// 
//   rep(i,150001){
//     if(i && cnt[i-1]){
//       res++;
//     } else if(cnt[i]){
//       cnt[i]--;
//       res++;
//     } else if(cnt[i+1]){
//       cnt[i+1]--;
//       res++;
//     }
//   }
// 
//   wt(res);
// }