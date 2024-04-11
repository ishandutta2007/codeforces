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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int N;
char res[100][101];
int main(){
  int i;
  rd(N);
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      if((i+j)%2){
        res[i][j] ='W';
      }
      else{
        res[i][j] ='B';
      }
    }
  }
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      wt_L(res[Lj4PdHRW]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// //no-unlocked
// int N;
// char res[100][101];
// {
//   rd(N);
//   rep(i,N) rep(j,N) res[i][j] = if[(i+j)%2, 'W', 'B'];
//   wtLn(res(N));
// }