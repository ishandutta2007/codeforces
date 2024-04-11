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
int A[100];
int go[100];
int main(){
  int Lj4PdHRW;
  int mn;
  int mi;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N-1);i++){
      go[i] = 1;
    }
    for(;;){
      mn = 1073709056;
      for(i=(0);i<(N-1);i++){
        if(go[i] && mn > A[i+1]){
          mn = A[i+1];
          mi = i;
        }
      }
      if(mn == 1073709056){
        break;
      }
      go[mi] = 0;
      if(A[mi] > A[mi+1]){
        swap(A[mi], A[mi+1]);
      }
      ;
    }
    {
      int a2conNHc;
      if(N==0){
        putchar('\n');
      }
      else{
        for(a2conNHc=(0);a2conNHc<(N-1);a2conNHc++){
          wt_L(A[a2conNHc]);
          wt_L(' ');
        }
        wt_L(A[a2conNHc]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// int N, A[100], go[100];
// {
//   int mn, mi;
//   REP(rd_int()){
//     rd(N,A(N));
//     rep(i,N-1) go[i] = 1;
//     for(;;){
//       mn = int_inf;
//       rep(i,N-1) if(go[i] && mn > A[i+1]){
//         mn = A[i+1];
//         mi = i;
//       }
//       if(mn == int_inf) break;
//       go[mi] = 0;
//       sortE(A[mi], A[mi+1]);
//     }
//     wt(A(N));
//   }
// }