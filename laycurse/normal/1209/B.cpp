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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[100];
int B[100];
char S[102];
int main(){
  int i;
  int k;
  int t;
  int res = 0;
  rd(N);
  rd(S);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
      rd(B[Lj4PdHRW]);
    }
  }
  for(i=0;i<(N);i++){
    S[i] -= '0';
  }
  for(t=0;t<(1000);t++){
    k = 0;
    for(i=0;i<(N);i++){
      k += S[i];
    }
    chmax(res, k);
    for(i=0;i<(N);i++){
      if(B[i]==t){
        B[i] += A[i];
        S[i] ^= 1;
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int N, A[100], B[100];
// char S[102];
// {
//   int i, k, t, res = 0;
//   rd(N,S,(A,B)(N));
//   rep(i,N) S[i] -= '0';
//   rep(t,1000){
//     k = 0;
//     rep(i,N) k += S[i];
//     res >?= k;
// 
//     rep(i,N) if(B[i]==t){
//       B[i] += A[i];
//       S[i] ^= 1;
//     }
//   }
//   wt(res);
// }