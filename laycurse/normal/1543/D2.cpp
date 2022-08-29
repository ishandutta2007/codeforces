#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
int next_marr(int len, int arr[], int lim){
  int i;
  for(i=(len)-1;i>=(0);i--){
    if(arr[i]+1 < lim){
      arr[i]++;
      return 1;
    }
    arr[i] = 0;
  }
  return 0;
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int arr[100];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int N;
    rd(N);
    int K;
    rd(K);
    long long y;
    long long m;
    long long c = 0;
    int cTE1_r3A;
    for(cTE1_r3A=(0);cTE1_r3A<(100);cTE1_r3A++){
      arr[cTE1_r3A] = 0;
    }
    do{
      {
        int i;
        y = 0;
        m = 1;
        for(i=(100)-1;i>=(0);i--){
          y += m;
          m *= K;
          if(arr[i]){
            break;
          }
        }
        if(c==0){
          y = 0;
        }
        if(c%2){
          y *= K-1;
        }
        c++;
        wt_L(y);
        wt_L('\n');
        if(rd_int()){
          break;
        }
      }
    }
    while(next_marr(100,arr,K));
  }
  return 0;
}
// cLay version 20210704-1 [beta]

// --- original code ---
// //interactive
// int arr[100];
// {
//   // int D = 4, K = 6, n = 0;
//   // int arr[100000][6], c[6], cc[6];
// 
//   // rep_marr(c,D,K){
//   //   rep(i,D) cc[i] = c[i];
//   //   rep(i,n) rep(j,D) cc[j] = (arr[i][j] - cc[j]) %% K;
//   //   rep(i,D) arr[n][i] = cc[i];
//   //   n++;
//   //   wt(c(D),":",cc(D));
//   // }
// 
//   // return 0;
//   REP(rd_int()){
//     int @N, @K;
//     ll y, m, c = 0;
//     rep_marr(arr,100,K){
//       y = 0; m = 1;
//       rrep(i,100){
//         y += m;
//         m *= K;
//         if(arr[i]) break;
//       }
//       if(c==0) y = 0;
//       if(c%2) y *= K-1;
//       c++;
//       wt(y);
//       if(rd_int()) break;
//     }
//   }
// }