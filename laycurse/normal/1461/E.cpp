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
inline void rd(__int128_t &x){
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
int main(){
  int KL2GvlyY;
  __int128_t K;
  rd(K);
  __int128_t L;
  rd(L);
  __int128_t R;
  rd(R);
  __int128_t T;
  rd(T);
  __int128_t X;
  rd(X);
  __int128_t Y;
  rd(Y);
  __int128_t skip;
  {
    auto Lj4PdHRW = (L);
    K -= Lj4PdHRW;
    R -= Lj4PdHRW;
  }
  if(K + Y <= R){
    K += Y;
  }
  K -= X;
  T--;
  if(K < 0){
    wt_L("No");
    wt_L('\n');
    return 0;
  }
  if(X >= Y){
    K -= (X - Y) * T;
    if(K >= 0){
      wt_L("Yes");
      wt_L('\n');
    }
    else{
      wt_L("No");
      wt_L('\n');
    }
    return 0;
  }
  for(KL2GvlyY=(0);KL2GvlyY<(2000000);KL2GvlyY++){
    if(K + Y <= R){
      K += Y;
    }
    skip = K / X;
    if(skip >= T){
      wt_L("Yes");
      wt_L('\n');
      return 0;
    }
    if(skip==0){
      wt_L("No");
      wt_L('\n');
      return 0;
    }
    K -= skip * X;
    T -= skip;
  }
  wt_L("Yes");
  wt_L('\n');
  return 0;
}
// cLay version 20201206-1

// --- original code ---
// //no-unlocked
// {
//   __int128_t @K, @L, @R, @T, @X, @Y, skip;
//   (K, R) -= L;
// 
//   if(K + Y <= R) K += Y;
//   K -= X;
//   T--;
//   if(K < 0) wt("No"), return 0;
// 
//   if(X >= Y){
//     K -= (X - Y) * T;
//     wt(if[K >= 0, "Yes", "No"]);
//     return 0;
//   }
// 
//   rep(2d6){
//     if(K + Y <= R) K += Y;
//     skip = K / X;
//     if(skip >= T) wt("Yes"), return 0;
//     if(skip==0) wt("No"), return 0;
//     K -= skip * X;
//     T -= skip;
//   }
// 
//   wt("Yes");
// }