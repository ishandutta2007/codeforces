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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
int main(){
  int i;
  int N;
  rd(N);
  int L;
  rd(L);
  int K;
  rd(K);
  int D[N+1];
  int A[N];
  {
    int Nzj9Y0kE;
    for(Nzj9Y0kE=(0);Nzj9Y0kE<(N);Nzj9Y0kE++){
      rd(D[Nzj9Y0kE]);
    }
  }
  {
    int QAAnbtfa;
    for(QAAnbtfa=(0);QAAnbtfa<(N);QAAnbtfa++){
      rd(A[QAAnbtfa]);
    }
  }
  D[N] = L;
  long long dp[N+1][K+1] = {};
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(K+1);j++){
      dp[i+1][j] = 4611686016279904256LL;
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(K+1);j++){
      int m;
      for(m=(0);m<(i+1);m++){
        if(j+i-m <= K){
          chmin(dp[i+1][j+(i-m)], dp[m][j] + A[m] * (D[i+1] - D[m]));
        }
      }
    }
  }
  wt_L(dp[N][K]);
  wt_L('\n');
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20211231-1

// --- original code ---
// //no-unlocked
// int @N, @L, @K, D[N+1], A[N];
// rd(D(N), A(N)); D[N] = L;
// ll dp[N+1][K+1] = {};
// rep(i,N) rep(j,K+1) dp[i+1][j] = ll_inf;
// rep(i,N) rep(j,K+1){
//   rep(m,i+1) if(j+i-m <= K) dp[i+1][j+(i-m)] <?= dp[m][j] + A[m] * (D[i+1] - D[m]);
// }
// wt(dp[N][K]);