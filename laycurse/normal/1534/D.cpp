#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  return getchar();
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
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
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
}
inline void wt_L(char a){
  my_putchar(a);
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int d[2000][2000];
int ok[2000][2000];
int os;
int o[2000];
int es;
int e[2000];
int M;
int A[2000];
int B[2000];
void q(int n){
  int i;
  wt_L("?");
  wt_L(' ');
  wt_L(n+1);
  wt_L('\n');
  for(i=(0);i<(N);i++){
    rd(d[n][i]);
  }
}
int main(){
  int i;
  rd(N);
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      d[i][j] = -1;
    }
  }
  q(0);
  for(i=(1);i<(N);i++){
    if(d[0][i]%2){
      o[os++]= i;
    }
    else{
      e[es++]= i;
    }
  }
  if(os < es){
    for(i=(0);i<(os);i++){
      q(o[i]);
    }
  }
  else{
    for(i=(0);i<(es);i++){
      q(e[i]);
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i+1);j<(N);j++){
      ok[i][j] = 1;
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i+1);j<(N);j++){
      if(d[i][j] > 1 || d[j][i] > 1 || abs(d[0][i] - d[0][j]) != 1){
        ok[i][j] = 0;
      }
    }
  }
  wt_L("!");
  wt_L('\n');
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i+1);j<(N);j++){
      if(ok[i][j]){
        wt_L(i+1);
        wt_L(' ');
        wt_L(j+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210613-1 [beta]

// --- original code ---
// //interactive
// int N;
// int d[2000][2000], ok[2000][2000];
// int os, o[2000];
// int es, e[2000];
// int M, A[2000], B[2000];
// 
// void q(int n){
//   wt("?", n+1);
//   rep(i,N) rd(d[n][i]);
// }
// 
// {
//   rd(N);
//   rep(i,N) rep(j,N) d[i][j] = -1;
//   q(0);
//   rep(i,1,N) if[d[0][i]%2, o[os++], e[es++]] = i;
// 
//   if(os < es){
//     rep(i,os) q(o[i]);
//   } else {
//     rep(i,es) q(e[i]);
//   }
// 
//   rep(i,N) rep(j,i+1,N) ok[i][j] = 1;
//   rep(i,N) rep(j,i+1,N) if(d[i][j] > 1 || d[j][i] > 1 || abs(d[0][i] - d[0][j]) != 1) ok[i][j] = 0;
// 
//   wt("!");
//   rep(i,N) rep(j,i+1,N) if(ok[i][j]) wt(i+1,j+1);
// 
// }