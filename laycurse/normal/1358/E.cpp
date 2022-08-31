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
int N;
long long A[500000];
long long X;
long long s[500000+1];
int main(){
  int i;
  long long mx = -4611686016279904256LL;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<((N+1)/2);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  rd(X);
  for(i=((N+1)/2);i<(N);i++){
    A[i] = X;
  }
  for(i=(0);i<(N);i++){
    s[i+1] = s[i] + A[i];
  }
  for(i=(0);i<((N+1)/2);i++){
    chmax(mx, s[i] - i * X);
    if(mx < s[N-i]){
      wt_L(N-i);
      wt_L('\n');
      return 0;
    }
  }
  wt_L(-1);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N; ll A[5d5], X;
// ll s[5d5+1];
// {
//   ll mx = -ll_inf;
//   rd(N,A((N+1)/2),X);
//   rep(i,(N+1)/2,N) A[i] = X;
//   rep(i,N) s[i+1] = s[i] + A[i];
// 
//   rep(i,(N+1)/2){
//     mx >?= s[i] - i * X;
//     if(mx < s[N-i]) wt(N-i), return 0;
//   }
//   wt(-1);
// }