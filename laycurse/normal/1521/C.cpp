#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int A[10000];
int sz;
int can[10];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    int mx;
    rd(N);
    sz = 0;
    for(i=(0);i<(N);i+=(2)){
      j = (i + 1) % N;
      wt_L("?");
      wt_L(' ');
      wt_L(1);
      wt_L(' ');
      wt_L(i+1);
      wt_L(' ');
      wt_L(j+1);
      wt_L(' ');
      wt_L(N-1);
      wt_L('\n');
      if(rd_int() >= N-1){
        can[sz++] = i;
        if(j > i){
          can[sz++] = j;
        }
      }
    }
    for(k=(0);k<(sz);k++){
      i = can[k];
      j = (i + 1) % N;
      wt_L("?");
      wt_L(' ');
      wt_L(1);
      wt_L(' ');
      wt_L(j+1);
      wt_L(' ');
      wt_L(i+1);
      wt_L(' ');
      wt_L(N-1);
      wt_L('\n');
      if(rd_int() == N){
        mx = i;
        break;
      }
    }
    for(k=(0);k<(N);k++){
      if(k == mx){
        A[k] = N;
        continue;
      }
      wt_L("?");
      wt_L(' ');
      wt_L(2);
      wt_L(' ');
      wt_L(k+1);
      wt_L(' ');
      wt_L(mx+1);
      wt_L(' ');
      wt_L(1);
      wt_L('\n');
      A[k] = rd_int();
    }
    wt_L("!");
    wt_L(' ');
    {
      int KrdatlYV;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(KrdatlYV=(0);KrdatlYV<(N-1);KrdatlYV++){
          wt_L(A[KrdatlYV]);
          wt_L(' ');
        }
        wt_L(A[KrdatlYV]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //interactive
// int N, A[1d4];
// int sz, can[10];
// {
//   REP(rd_int()){
//     int i, j, k, mx;
// 
//     rd(N);
//     sz = 0;
//     rep(i,0,N,2){
//       j = (i + 1) % N;
//       wt("?", 1, i+1, j+1, N-1);
//       if(rd_int() >= N-1){
//         can[sz++] = i;
//         if(j > i) can[sz++] = j;
//       }
//     }
//     rep(k,sz){
//       i = can[k];
//       j = (i + 1) % N;
//       wt("?", 1, j+1, i+1, N-1);
//       if(rd_int() == N) mx = i, break;
//     }
//     rep(k,N){
//       if(k == mx) A[k] = N, continue;
//       wt("?", 2, k+1, mx+1, 1);
//       A[k] = rd_int();
//     }
//     wt("!",A(N));
//   }
// }