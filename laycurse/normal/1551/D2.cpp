#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int X;
int Y;
int K;
char res[100][102];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(X);
    rd(Y);
    rd(K);
    if(X%2){
      K -= Y/2;
    }
    if(K < 0 || K > (X/2)*(Y/2)*2 || K%2){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(X);i+=(2)){
      int j;
      for(j=(0);j<(Y);j+=(2)){
        char c;
        char d;
        c = ((i+j)%26) + 'a';
        d = c + 1;
        if(i+1 == X){
          res[i][j] = res[i][j+1] = c;
          continue;
        }
        if(j+1 == Y){
          res[i][j] = res[i+1][j] = c;
          continue;
        }
        if(K > 0){
          res[i][j] = res[i][j+1] = c;
          res[i+1][j] = res[i+1][j+1] = d;
          K -= 2;
          continue;
        }
        res[i][j] = res[i+1][j] = c;
        res[i][j+1] = res[i+1][j+1] = d;
      }
    }
    for(i=(0);i<(X);i++){
      res[i][Y] = '\0';
    }
    wt_L("YES");
    wt_L('\n');
    {
      int KrdatlYV;
      for(KrdatlYV=(0);KrdatlYV<(X);KrdatlYV++){
        wt_L(res[KrdatlYV]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int X, Y, K;
// char res[100][102];
// {
//   REP(rd_int()){
//     rd(X,Y,K);
//     if(X%2) K -= Y/2;
//     if(K < 0 || K > (X/2)*(Y/2)*2 || K%2) wt("NO"), continue;
// 
//     rep(i,0,X,2) rep(j,0,Y,2){
//       char c, d;
//       c = ((i+j)%26) + 'a';
//       d = c + 1;
//       if(i+1 == X){
//         res[i][j] = res[i][j+1] = c;
//         continue;
//       }
//       if(j+1 == Y){
//         res[i][j] = res[i+1][j] = c;
//         continue;
//       }
//       if(K > 0){
//         res[i][j] = res[i][j+1] = c;
//         res[i+1][j] = res[i+1][j+1] = d;
//         K -= 2;
//         continue;
//       }
//       res[i][j] = res[i+1][j] = c;
//       res[i][j+1] = res[i+1][j+1] = d;
//     }
//     rep(i,X) res[i][Y] = '\0';
// 
//     wt("YES");
//     wtLn(res(X));
//   }
// }