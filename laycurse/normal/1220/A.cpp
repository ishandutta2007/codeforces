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
inline void rd(char &c){
  int i;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
char S[100002];
int res[100000];
int ress;
int main(){
  int i;
  int z = 0;
  int n = 0;
  rd(N);
  rd(S);
  for(i=(0);i<(N);i++){
    if(S[i]=='n'){
      res[ress++] = 1;
    }
  }
  for(i=(0);i<(N);i++){
    if(S[i]=='z'){
      res[ress++] = 0;
    }
  }
  {
    int Lj4PdHRW;
    if(ress==0){
      putchar('\n');
    }
    else{
      for(Lj4PdHRW=(0);Lj4PdHRW<(ress-1);Lj4PdHRW++){
        wt_L(res[Lj4PdHRW]);
        wt_L(' ');
      }
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
// char S[100002];
// int res[1d5], ress;
// {
//   int z = 0, n = 0;
//   rd(N,S);
//   rep(i,N) if(S[i]=='n') res[ress++] = 1;
//   rep(i,N) if(S[i]=='z') res[ress++] = 0;
//   wt(res(ress));
// }