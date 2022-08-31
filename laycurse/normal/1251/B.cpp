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
int len;
int zero;
int odd;
char S[52];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    zero = odd = 0;
    for(i=(0);i<(N);i++){
      int j;
      len = rd(S);
      for(j=(0);j<(len);j++){
        if(S[j]=='0'){
          zero ^= 1;
        }
      }
      if(len%2){
        odd = 1;
      }
    }
    if(!odd && zero){
      wt_L(N-1);
      wt_L('\n');
    }
    else{
      wt_L(N);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191108-1

// --- original code ---
// //no-unlocked
// int N, len, zero, odd;
// char S[52];
// {
//   REP(rd_int()){
//     rd(N);
//     zero = odd = 0;
//     rep(i,N){
//       rd(S@len);
//       rep(j,len) if(S[j]=='0') zero ^= 1;
//       if(len%2) odd = 1;
//     }
//     wt(if[!odd && zero, N-1, N]);
//   }
// }