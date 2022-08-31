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
int res[1000][1000];
int main(){
  int i, j, k, x, y;
  rd(N);
  k = 0;
  for(x=0;x<(N/4);x++){
    for(y=0;y<(N/4);y++){
      for(i=0;i<(4);i++){
        for(j=0;j<(4);j++){
          res[4*x+i][4*y+j] = k++;
        }
      }
    }
  }
  for(i=0;i<(N);i++){
    {
      int Lj4PdHRW;
      if(N==0){
        putchar('\n');
      }
      else{
        for(Lj4PdHRW=0;Lj4PdHRW<(N-1);Lj4PdHRW++){
          wt_L(res[i][Lj4PdHRW]);
          wt_L(' ');
        }
        wt_L(res[i][Lj4PdHRW]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int N;
// int res[1000][1000];
// {
//   int i, j, k, x, y;
//   
//   rd(N);
//   k = 0;
//   rep(x,N/4) rep(y,N/4) rep(i,4) rep(j,4) res[4x+i][4y+j] = k++;
//   
//   rep(i,N) wt(res[i](N));
// }