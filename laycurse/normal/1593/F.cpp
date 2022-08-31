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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
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
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int main(){
  int Lj4PdHRW;
  int N;
  int A;
  int B;
  int mn;
  int i;
  int k;
  int x;
  int y;
  char X[42];
  char res[42];
  int dp1[41][81][40][40];
  int dp2[41][81][40][40];
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    rd(A);
    rd(B);
    rd(X);
    for(i=(0);i<(N);i++){
      X[i] -= '0';
    }
    for(k=(0);k<(N+1);k++){
      for(i=(0);i<(81);i++){
        for(x=(0);x<(A);x++){
          for(y=(0);y<(B);y++){
            dp1[k][i][x][y] = dp2[k][i][x][y] = 0;
          }
        }
      }
    }
    dp1[0][40][0][0] = 1;
    for(k=(0);k<(N);k++){
      for(i=(0);i<(81);i++){
        for(x=(0);x<(A);x++){
          for(y=(0);y<(B);y++){
            if(dp1[k][i][x][y]){
              dp1[k+1][i+1][(10*x+X[k])%A][y] = 1;
              dp2[k+1][i+1][(10*x+X[k])%A][y] = x;
              dp1[k+1][i-1][x][(10*y+X[k])%B] = 2;
              dp2[k+1][i-1][x][(10*y+X[k])%B] = y;
            }
          }
        }
      }
    }
    mn = 1073709056;
    for(i=(0);i<(81);i++){
      if(dp1[N][i][0][0]){
        chmin(mn, abs(40 - i));
      }
    }
    if(mn >= N){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(81);i++){
      if(dp1[N][i][0][0] && mn == abs(40-i)){
        break;
      }
    }
    auto Q5rsz4fz = ((N));
    auto GgkpftXM = (( 0));
    auto gEg5UqEA = (( 0));
    k=Q5rsz4fz;
    x=GgkpftXM;
    y=gEg5UqEA;
    while(k){
      if(dp1[k][i][x][y] == 1){
        res[k-1] = 'R';
        x = dp2[k][i][x][y];
        i--;
      }
      else{
        res[k-1] = 'B';
        y = dp2[k][i][x][y];
        i++;
      }
      k--;
    }
    res[N] = '\0';
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int N, A, B, mn, i, k, x, y; char X[42], res[];
// int dp1[41][81][40][40], dp2[41][81][40][40];
// REP(rd_int()){
//   rd(N,A,B,X);
//   rep(i,N) X[i] -= '0';
//   rep(k,N+1) rep(i,81) rep(x,A) rep(y,B) dp1[k][i][x][y] = dp2[k][i][x][y] = 0;
//   dp1[0][40][0][0] = 1;
//   rep(k,N) rep(i,81) rep(x,A) rep(y,B) if(dp1[k][i][x][y]){
//     dp1[k+1][i+1][(10*x+X[k])%A][y] = 1;
//     dp2[k+1][i+1][(10*x+X[k])%A][y] = x;
//     dp1[k+1][i-1][x][(10*y+X[k])%B] = 2;
//     dp2[k+1][i-1][x][(10*y+X[k])%B] = y;
//   }
//   mn = int_inf;
//   rep(i,81) if(dp1[N][i][0][0]) mn <?= abs(40 - i);
//   if(mn >= N) wt(-1), continue;
//   rep(i,81) if(dp1[N][i][0][0] && mn == abs(40-i)) break;
//   (k, x, y) = (N, 0, 0);
//   while(k){
//     if(dp1[k][i][x][y] == 1){
//       res[k-1] = 'R';
//       x = dp2[k][i][x][y];
//       i--;
//     } else {
//       res[k-1] = 'B';
//       y = dp2[k][i][x][y];
//       i++;
//     }
//     k--;
//   }
//   res[N] = '\0';
//   wt(res);
// }