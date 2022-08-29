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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int N;
int res[200000];
int main(){
  int i;
  rd(N);
  if(N%2==0){
    wt_L("NO");
    wt_L('\n');
    return 0;
  }
  for(i=0;i<(N);i++){
    res[N * (i%2) + i] = 2*i;
    res[N * (1-i%2) + i] = 2*i + 1;
  }
  wt_L("YES");
  wt_L('\n');
  {
    int Lj4PdHRW;
    if(2*N==0){
      putchar('\n');
    }
    else{
      for(Lj4PdHRW=0;Lj4PdHRW<(2*N-1);Lj4PdHRW++){
        wt_L(res[Lj4PdHRW]+1);
        wt_L(' ');
      }
      wt_L(res[Lj4PdHRW]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int N, res[2d5];
// {
//   rd(N);
//   if(N%2==0){ wt("NO"); return 0; }
// 
//   rep(i,N){
//     res[N * (i%2) + i] = 2i;
//     res[N * (1-i%2) + i] = 2i + 1;
//   }
// 
//   wt("YES");
//   wt(res(2N)+1);
// }