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
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
int N;
int A[200000];
int B[200000];
int pa[200000];
int pb[200000];
int cnt[200000];
int main(){
  int i;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){
      rd(B[e98WHCEY]);B[e98WHCEY] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    pa[A[i]] = i;
  }
  for(i=(0);i<(N);i++){
    pb[B[i]] = i;
  }
  for(i=(0);i<(N);i++){
    cnt[(moddw_L((pa[i] - pb[i]),N))]++;
  }
  {
    int tU__gIr_;
    int a2conNHc;
    if(N==0){
      a2conNHc = 0;
    }
    else{
      a2conNHc = cnt[0];
      for(tU__gIr_=(1);tU__gIr_<(N);tU__gIr_++){
        a2conNHc = max_L(a2conNHc, cnt[tU__gIr_]);
      }
    }
    wt_L(a2conNHc);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], B[2d5];
// int pa[2d5], pb[2d5];
// int cnt[2d5];
// {
//   rd(N,(A--)(N),(B--)(N));
//   rep(i,N) pa[A[i]] = i;
//   rep(i,N) pb[B[i]] = i;
//   rep(i,N) cnt[(pa[i] - pb[i]) %% N]++;
//   wt(max(cnt(N)));
// }