#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int X;
int Y;
int K;
int A[500][500];
int B[500][500];
int res[500][500];
int tmp[500][500];
int main(){
  int AlM5nNnR, i;
  rd(X);
  rd(Y);
  rd(K);
  {
    int Lj4PdHRW;
    int KL2GvlyY;
    for(Lj4PdHRW=(0);Lj4PdHRW<(X);Lj4PdHRW++){
      for(KL2GvlyY=(0);KL2GvlyY<(Y-1);KL2GvlyY++){
        rd(A[Lj4PdHRW][KL2GvlyY]);
      }
    }
  }
  {
    int FmcKpFmN;
    int xr20shxY;
    for(FmcKpFmN=(0);FmcKpFmN<(X-1);FmcKpFmN++){
      for(xr20shxY=(0);xr20shxY<(Y);xr20shxY++){
        rd(B[FmcKpFmN][xr20shxY]);
      }
    }
  }
  if(K%2){
    int i;
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        res[i][j] = -1;
      }
    }
    {
      int APIVbQlN;
      int YREPHmFM;
      for(APIVbQlN=(0);APIVbQlN<(X);APIVbQlN++){
        if(Y==0){
          wt_L('\n');
        }
        else{
          for(YREPHmFM=(0);YREPHmFM<(Y-1);YREPHmFM++){
            wt_L(res[APIVbQlN][YREPHmFM]);
            wt_L(' ');
          }
          wt_L(res[APIVbQlN][YREPHmFM]);
          wt_L('\n');
        }
      }
    }
    return 0;
  }
  for(AlM5nNnR=(0);AlM5nNnR<(K/2);AlM5nNnR++){
    int i;
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        tmp[i][j] = 1073709056;
      }
    }
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        if(i-1 >= 0){
          chmin(tmp[i][j], res[i-1][j] + B[i-1][j]);
        }
        if(i+1 <  X){
          chmin(tmp[i][j], res[i+1][j] + B[i][j]);
        }
        if(j-1 >= 0){
          chmin(tmp[i][j], res[i][j-1] + A[i][j-1]);
        }
        if(j+1 <  Y){
          chmin(tmp[i][j], res[i][j+1] + A[i][j]);
        }
      }
    }
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        res[i][j] = tmp[i][j];
      }
    }
  }
  for(i=(0);i<(X);i++){
    int j;
    for(j=(0);j<(Y);j++){
      res[i][j] *= 2;
    }
  }
  {
    int lQU550vz;
    int qE8LMwYZ;
    for(lQU550vz=(0);lQU550vz<(X);lQU550vz++){
      if(Y==0){
        wt_L('\n');
      }
      else{
        for(qE8LMwYZ=(0);qE8LMwYZ<(Y-1);qE8LMwYZ++){
          wt_L(res[lQU550vz][qE8LMwYZ]);
          wt_L(' ');
        }
        wt_L(res[lQU550vz][qE8LMwYZ]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int X, Y, K;
// int A[500][500], B[][], res[][], tmp[][];
// {
//   rd(X,Y,K,A(X,Y-1),B(X-1,Y));
// 
//   if(K%2){
//     rep(i,X) rep(j,Y) res[i][j] = -1;
//     wt(res(X,Y));
//     return 0;
//   }
// 
//   rep(K/2){
//     rep(i,X) rep(j,Y) tmp[i][j] = int_inf;
//     rep(i,X) rep(j,Y){
//       if(i-1 >= 0) tmp[i][j] <?= res[i-1][j] + B[i-1][j];
//       if(i+1 <  X) tmp[i][j] <?= res[i+1][j] + B[i][j];
//       if(j-1 >= 0) tmp[i][j] <?= res[i][j-1] + A[i][j-1];
//       if(j+1 <  Y) tmp[i][j] <?= res[i][j+1] + A[i][j];
//     }
//     rep(i,X) rep(j,Y) res[i][j] = tmp[i][j];
//   }
//   rep(i,X) rep(j,Y) res[i][j] *= 2;
//   wt(res(X,Y));
// }