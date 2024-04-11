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
int N;
int res[300][300];
int main(){
  int i;
  int j;
  int k = 1;
  rd(N);
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N);j++){
      if(i%2){
        res[j][i] = k++;
      }
      else{
        res[N-1-j][i] = k++;
      }
    }
  }
  for(i=(0);i<(N);i++){
    {
      int Lj4PdHRW;
      if(N==0){
        putchar('\n');
      }
      else{
        for(Lj4PdHRW=(0);Lj4PdHRW<(N-1);Lj4PdHRW++){
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
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int N, res[300][300];
// {
//   int i, j, k = 1;
//   rd(N);
//   rep(i,N) rep(j,N) res[if[i%2,j,N-1-j]][i] = k++;
//   rep(i,N) wt(res[i](N));
// }