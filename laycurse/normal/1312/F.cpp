#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
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
inline void rd(long long &x){
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
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
int N;
int X;
int Y;
int Z;
long long A[300000];
int g[3][1000];
int vis[1000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int res = 0;
    int i;
    int j;
    int k;
    int p;
    int all;
    long long b;
    rd(N);
    rd(X);
    rd(Y);
    rd(Z);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(j=(0);j<(1000);j++){
      for(i=(0);i<(3);i++){
        for(k=(0);k<(100);k++){
          vis[k] = 0;
        }
        if(j){
          vis[ g[0][max_L(0, j-X)] ] = 1;
        }
        if(j && i != 1){
          vis[ g[1][max_L(0, j-Y)] ] = 1;
        }
        if(j && i != 2){
          vis[ g[2][max_L(0, j-Z)] ] = 1;
        }
        for(k=(0);k<(100);k++){
          if(vis[k]==0){
            break;
          }
        }
        g[i][j] = k;
      }
    }
    for(p=1;;p++){
      for(j=(500);j<(1000);j++){
        for(i=(0);i<(3);i++){
          if(g[i][j] != g[i][j-p]){
            goto jZyWAPpY;
          }
        }
      }
      break;
      jZyWAPpY:;
    }
    all = 0;
    for(i=(0);i<(N);i++){
      if(A[i] > 500){
        j =g[0][A[i]%p+500/p*p];
      }
      else{
        j =g[0][A[i]];
      }
      all ^= j;
    }
    for(i=(0);i<(N);i++){
      if(A[i] > 500){
        j =g[0][A[i]%p+500/p*p];
      }
      else{
        j =g[0][A[i]];
      }
      b =max_L(A[i]-X, 0);
      if(b > 500){
        k =g[0][b%p+500/p*p];
      }
      else{
        k =g[0][b];
      }
      if(!(all ^ j ^ k)){
        res++;
      }
      b =max_L(A[i]-Y, 0);
      if(b > 500){
        k =g[1][b%p+500/p*p];
      }
      else{
        k =g[1][b];
      }
      if(!(all ^ j ^ k)){
        res++;
      }
      b =max_L(A[i]-Z, 0);
      if(b > 500){
        k =g[2][b%p+500/p*p];
      }
      else{
        k =g[2][b];
      }
      if(!(all ^ j ^ k)){
        res++;
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200308-1

// --- original code ---
// //no-unlocked
// int N, X, Y, Z; ll A[3d5];
// 
// int g[3][1000];
// int vis[1000];
// {
// /*  int p;
//   rep(X,1,6) rep(Y,1,6) rep(Z,1,6){
//     rep(j,1000) rep(i,3){
//       rep(k,100) vis[k] = 0;
// 
//       if(j) vis[ g[0][max(0,j-X)] ] = 1;
//       if(j && i != 1) vis[ g[1][max(0,j-Y)] ] = 1;
//       if(j && i != 2) vis[ g[2][max(0,j-Z)] ] = 1;
// 
//       rep(k,100) if(vis[k]==0) break;
//       g[i][j] = k;
//     }
// 
//     for(p=1;;p++){
//       rep(j,500,1000) rep(i,3) if(g[i][j] != g[i][j-p]) break_break_continue;
//       break;
//     }
//     wt(X, Y, Z, ":", p);
//   }*/
// 
//   REP(rd_int()){
//     int res = 0, i, j, k, p, all;
//     ll b;
//     rd(N,X,Y,Z,A(N));
// 
//     rep(j,1000) rep(i,3){
//       rep(k,100) vis[k] = 0;
// 
//       if(j) vis[ g[0][max(0,j-X)] ] = 1;
//       if(j && i != 1) vis[ g[1][max(0,j-Y)] ] = 1;
//       if(j && i != 2) vis[ g[2][max(0,j-Z)] ] = 1;
// 
//       rep(k,100) if(vis[k]==0) break;
//       g[i][j] = k;
//     }
// 
//     for(p=1;;p++){
//       rep(j,500,1000) rep(i,3) if(g[i][j] != g[i][j-p]) break_break_continue;
//       break;
//     }
// 
//     all = 0;
//     rep(i,N){
//       j = if[A[i] > 500, g[0][A[i]%p+500/p*p], g[0][A[i]]];
//       all ^= j;
//     }
//     rep(i,N){
//       j = if[A[i] > 500, g[0][A[i]%p+500/p*p], g[0][A[i]]];
// 
//       b = max(A[i]-X, 0);
//       k = if[b > 500, g[0][b%p+500/p*p], g[0][b]];
//       if(!(all ^ j ^ k)) res++;
// 
//       b = max(A[i]-Y, 0);
//       k = if[b > 500, g[1][b%p+500/p*p], g[1][b]];
//       if(!(all ^ j ^ k)) res++;
// 
//       b = max(A[i]-Z, 0);
//       k = if[b > 500, g[2][b%p+500/p*p], g[2][b]];
//       if(!(all ^ j ^ k)) res++;
//     }
// 
//     wt(res);
//   }
// }