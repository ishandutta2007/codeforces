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
char S[200002];
char T[200002];
int ab[200000];
int absz;
int ba[200000];
int basz;
int ress;
int res1[200000];
int res2[200000];
int main(){
  int i;
  rd(N);
  rd(S);
  rd(T);
  for(i=0;i<(N);i++){
    if(S[i]=='a' && T[i]=='b'){
      ab[absz++] = i;
    }
    if(S[i]=='b' && T[i]=='a'){
      ba[basz++] = i;
    }
  }
  if( (absz + basz)%2 ){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  while(absz >= 2){
    res1[ress] = ab[--absz];
    res2[ress++] = ab[--absz];
  }
  while(basz >= 2){
    res1[ress] = ba[--basz];
    res2[ress++] = ba[--basz];
  }
  if(absz && basz){
    res1[ress] = ab[0];
    res2[ress++] = ab[0];
    res1[ress] = ab[0];
    res2[ress++] = ba[0];
  }
  wt_L(ress);
  wt_L('\n');
  for(i=0;i<(ress);i++){
    wt_L(res1[i]+1);
    wt_L(' ');
    wt_L(res2[i]+1);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int N;
// char S[200002], T[200002];
// 
// int ab[2d5], absz;
// int ba[2d5], basz;
// 
// int ress, res1[2d5], res2[2d5];
// 
// {
//   rd(N,S,T);
//   rep(i,N){
//     if(S[i]=='a' && T[i]=='b') ab[absz++] = i;
//     if(S[i]=='b' && T[i]=='a') ba[basz++] = i;
//   }
// 
//   if( (absz + basz)%2 ) wt(-1), return 0;
// 
//   while(absz >= 2){
//     res1[ress] = ab[--absz];
//     res2[ress++] = ab[--absz];
//   }
// 
//   while(basz >= 2){
//     res1[ress] = ba[--basz];
//     res2[ress++] = ba[--basz];
//   }
// 
//   if(absz && basz){
//     res1[ress] = ab[0];
//     res2[ress++] = ab[0];
//     res1[ress] = ab[0];
//     res2[ress++] = ba[0];
//   }
// 
//   wt(ress);
//   rep(i,ress) wt(res1[i]+1, res2[i]+1);
// }