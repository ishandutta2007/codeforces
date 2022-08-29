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
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
int N;
int X[1000];
int Y[1000];
int ress;
int res[1000];
int main(){
  int x;
  int y;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);
      rd(Y[Lj4PdHRW]);
    }
  }
  for(;;){
    int i;
    ress = 0;
    for(i=(0);i<(N);i++){
      if(moddw_L((X[i] + Y[i]),2)== 1 ){
        res[ress++] = i+1;
      }
    }
    if(ress == N){
      for(i=(0);i<(N);i++){
        X[i]++;
      }
      ress = 0;
    }
    if(ress == 0){
      for(i=(0);i<(N);i++){
        x = X[i];
        y = Y[i];
        X[i] = (x+y) / 2;
        Y[i] = (y-x) / 2;
      }
      continue;
    }
    wt_L(ress);
    wt_L('\n');
    {
      int ao_dF3pO;
      if(ress==0){
        putchar('\n');
      }
      else{
        for(ao_dF3pO=(0);ao_dF3pO<(ress-1);ao_dF3pO++){
          wt_L(res[ao_dF3pO]);
          wt_L(' ');
        }
        wt_L(res[ao_dF3pO]);
        wt_L('\n');
      }
    }
    break;
  }
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// int N, X[1000], Y[1000];
// int ress, res[1000];
// {
//   int x, y;
//   rd(N,(X,Y)(N));
//   for(;;){
//     ress = 0;
//     rep(i,N) if( (X[i] + Y[i]) %% 2 == 1 ) res[ress++] = i+1;
//     if(ress == N){
//       rep(i,N) X[i]++;
//       ress = 0;
//     }
//     if(ress == 0){
//       rep(i,N){
//         x = X[i];
//         y = Y[i];
//         X[i] = (x+y) / 2;
//         Y[i] = (y-x) / 2;
//       }
//       continue;
//     }
//     wt(ress);
//     wt(res(ress));
//     break;
//   }
// }