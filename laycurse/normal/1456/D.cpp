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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
long long T[5001];
long long X[5001];
char ok[5003][5003];
long long dp[5003];
int main(){
  int i;
  long long tt;
  long long r;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(T[Lj4PdHRW]);
      rd(X[Lj4PdHRW]);
    }
  }
  arrInsert(0, N, T, 0LL, X, 0LL);
  ok[0][0] = 1;
  for(i=(0);i<(N-1);i++){
    int j;
    for(j=(0);j<(N);j++){
      if(ok[i][j]){
        if(j==i+1){
          int k;
          if(i==N-2 && j==N-1){
            wt_L("YES");
            wt_L('\n');
            return 0;
          }
          tt = T[i+2] - T[i];
          r = tt - abs(X[i+2] - X[i]);
          chmin(r, T[i+2] - T[i+1]);
          if(r >= 0){
            ok[i+2][0] = 1;
            chmax(dp[i+2], r);
          }
          for(k=(i+3);k<(N);k++){
            if(tt >= abs(X[i] - X[k]) + abs(X[k] - X[i+2]) && T[i+2] - T[i+1] >= abs(X[k] - X[i+2])){
              ok[i+2][k] = 1;
            }
          }
        }
        else if(j==0){
          int k;
          tt = dp[i] + T[i+1] - T[i];
          r = tt - abs(X[i+1] - X[i]);
          chmin(r, T[i+1] - T[i]);
          if(r >= 0){
            ok[i+1][0] = 1;
            chmax(dp[i+1], r);
          }
          for(k=(i+2);k<(N);k++){
            if(tt >= abs(X[i] - X[k]) + abs(X[k] - X[i+1]) && T[i+1] - T[i] >= abs(X[k] - X[i+1])){
              ok[i+1][k] = 1;
            }
          }
        }
        else{
          if(T[i+1] - T[i] >= abs(X[i+1] - X[i])){
            ok[i+1][j] = 1;
          }
        }
      }
    }
  }
  for(i=(0);i<(N);i++){
    if(ok[N-1][i]){
      wt_L("YES");
      wt_L('\n');
      return 0;
    }
  }
  wt_L("NO");
  wt_L('\n');
  return 0;
}
// cLay version 20201205-1

// --- original code ---
// //no-unlocked
// int N; ll T[5001], X[5001];
// char ok[5003][5003];
// ll dp[5003];
// {
//   ll tt, r;
//   rd(N,(T,X)(N));
//   arrInsert(0, N, T, 0LL, X, 0LL);
//   ok[0][0] = 1;
// 
//   rep(i,N-1) rep(j,N) if(ok[i][j]){
//     if(j==i+1){
//       if(i==N-2 && j==N-1) wt("YES"), return 0;
// 
//       tt = T[i+2] - T[i];
//       r = tt - abs(X[i+2] - X[i]);
//       r <?= T[i+2] - T[i+1];
//       if(r >= 0) ok[i+2][0] = 1, dp[i+2] >?= r;
// 
//       rep(k,i+3,N) if(tt >= abs(X[i] - X[k]) + abs(X[k] - X[i+2]) && T[i+2] - T[i+1] >= abs(X[k] - X[i+2])) ok[i+2][k] = 1;
//     } else if(j==0){
//       tt = dp[i] + T[i+1] - T[i];
//       r = tt - abs(X[i+1] - X[i]);
//       r <?= T[i+1] - T[i];
//       if(r >= 0) ok[i+1][0] = 1, dp[i+1] >?= r;
// 
//       rep(k,i+2,N) if(tt >= abs(X[i] - X[k]) + abs(X[k] - X[i+1]) && T[i+1] - T[i] >= abs(X[k] - X[i+1])) ok[i+1][k] = 1;
//     } else {
//       if(T[i+1] - T[i] >= abs(X[i+1] - X[i])) ok[i+1][j] = 1;
//     }
//   }
// 
//   rep(i,N) if(ok[N-1][i]) wt("YES"), return 0;
//   wt("NO");
// }