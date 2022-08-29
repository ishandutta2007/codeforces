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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int As;
int Bs;
char A[5002];
char B[5002];
int dp[5001][5001];
int main(){
  int i;
  int res = 0;
  rd(As);
  rd(Bs);
  rd(A);
  rd(B);
  for(i=(0);i<(As+1);i++){
    int j;
    for(j=(0);j<(Bs+1);j++){
      chmax(res, dp[i][j]);
      if(i < As){
        chmax(dp[i+1][j], dp[i][j] - 1);
      }
      if(j < Bs){
        chmax(dp[i][j+1], dp[i][j] - 1);
      }
      if(i < As && j < Bs && A[i]==B[j]){
        chmax(dp[i+1][j+1], dp[i][j] + 2);
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20201115-2

// --- original code ---
// //no-unlocked
// int As, Bs;
// char A[5002], B[5002];
// int dp[5001][5001];
// {
//   int res = 0;
//   rd(As, Bs, A, B);
//   rep(i,As+1) rep(j,Bs+1){
//     res >?= dp[i][j];
//     if(i < As) dp[i+1][j] >?= dp[i][j] - 1;
//     if(j < Bs) dp[i][j+1] >?= dp[i][j] - 1;
//     if(i < As && j < Bs && A[i]==B[j]) dp[i+1][j+1] >?= dp[i][j] + 2;
//   }
//   wt(res);
// }