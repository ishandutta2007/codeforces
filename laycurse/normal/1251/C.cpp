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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int N;
char S[300002];
char x[300001];
char y[300001];
int xs;
int ys;
int main(){
  int Lj4PdHRW;
  int a;
  int b;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    N = rd(S);
    xs = ys = 0;
    for(i=(0);i<(N);i++){
      if(S[i]%2==0){
        x[xs++] = S[i];
      }
      else{
        y[ys++] = S[i];
      }
    }
    x[xs] = y[ys] = '9' + 1;
    a = b = 0;
    for(i=(0);i<(N);i++){
      if(x[a] <= y[b]){
        S[i] =x[a++];
      }
      else{
        S[i] =y[b++];
      }
    }
    wt_L(S);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191108-1

// --- original code ---
// //no-unlocked
// int N;
// char S[300002];
// char x[300001], y[300001]; int xs, ys;
// {
//   int a, b;
//   REP(rd_int()){
//     rd(S@N);
//     xs = ys = 0;
//     rep(i,N){
//       if(S[i]%2==0) x[xs++] = S[i];
//       else          y[ys++] = S[i];
//     }
//     x[xs] = y[ys] = '9' + 1;
//     a = b = 0;
//     rep(i,N) S[i] = if[x[a] <= y[b], x[a++], y[b++]];
//     wt(S);
//   }
// }