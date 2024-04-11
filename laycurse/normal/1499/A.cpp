#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int N;
    rd(N);
    int K1;
    rd(K1);
    int K2;
    rd(K2);
    int W;
    rd(W);
    int B;
    rd(B);
    int ww;
    int bb;
    ww =min_L(K1, K2)+ (K1 -min_L(K1, K2)) / 2 + (K2 -min_L(K1, K2)) / 2;
    auto xr20shxY = (N - (K1));
    auto WYIGIcGE = (N - ( K2));
    K1=xr20shxY;
    K2=WYIGIcGE;
    bb =min_L(K1, K2)+ (K1 -min_L(K1, K2)) / 2 + (K2 -min_L(K1, K2)) / 2;
    if(ww >= W && bb >= B){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// {
//   REP(rd_int()){
//     int @N, @K1, @K2, @W, @B, ww, bb;
//     ww = min(K1,K2) + (K1 - min(K1,K2)) / 2 + (K2 - min(K1,K2)) / 2;
//     (K1, K2) = N - (K1, K2);
//     bb = min(K1,K2) + (K1 - min(K1,K2)) / 2 + (K2 - min(K1,K2)) / 2;
//     wt(if[ww >= W && bb >= B, "YES", "NO"]);
//   }
// }