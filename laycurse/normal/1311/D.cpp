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
int A;
int B;
int C;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(A);
    rd(B);
    rd(C);
    int res = 1073709056;
    int tmp;
    int resA;
    int resB;
    int resC;
    for(i=(1);i<(20000+1);i++){
      int j;
      for(j=(i);j<(20000+1);j+=(i)){
        int k;
        for(k=(j);k<(20000+1);k+=(j)){
          tmp = abs(A-i) + abs(B-j) + abs(C-k);
          if(res > tmp){
            res = tmp;
            resA = i;
            resB = j;
            resC = k;
          }
        }
      }
    }
    wt_L(res);
    wt_L('\n');
    wt_L(resA);
    wt_L(' ');
    wt_L(resB);
    wt_L(' ');
    wt_L(resC);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int A, B, C;
// {
//   REP(rd_int()){
//     rd(A,B,C);
//     int res = int_inf, tmp;
//     int resA, resB, resC;
//     rep(i,1,2d4+1) rep(j,i,2d4+1,i) rep(k,j,2d4+1,j){
//       tmp = abs(A-i) + abs(B-j) + abs(C-k);
//       if(res > tmp){
//         res = tmp;
//         resA = i;
//         resB = j;
//         resC = k;
//       }
//     }
//     wt(res);
//     wt(resA, resB, resC);
//   }
// }