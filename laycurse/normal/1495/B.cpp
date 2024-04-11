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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int P[100000];
int lef[100000];
int rig[100000];
int main(){
  int i;
  int res = 0;
  int cnt = 0;
  int mx;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(P[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    if(i && P[i-1] < P[i]){
      lef[i] = lef[i-1] + 1;
    }
  }
  for(i=(N)-1;i>=(0);i--){
    if(i+1 < N && P[i] > P[i+1]){
      rig[i] = rig[i+1] + 1;
    }
  }
  int xr20shxY;
  int WYIGIcGE;
  if(N==0){
    WYIGIcGE = 0;
  }
  else{
    WYIGIcGE = lef[0];
    for(xr20shxY=(1);xr20shxY<(N);xr20shxY++){
      WYIGIcGE = max_L(WYIGIcGE, lef[xr20shxY]);
    }
  }
  mx =WYIGIcGE;
  int ao_dF3pO;
  int tU__gIr_;
  if(N==0){
    tU__gIr_ = 0;
  }
  else{
    tU__gIr_ = rig[0];
    for(ao_dF3pO=(1);ao_dF3pO<(N);ao_dF3pO++){
      tU__gIr_ = max_L(tU__gIr_, rig[ao_dF3pO]);
    }
  }
  chmax(mx, tU__gIr_);
  for(i=(0);i<(N);i++){
    if(lef[i] == mx || rig[i] == mx){
      cnt++;
    }
  }
  if(cnt > 1){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N);i++){
    if(lef[i] == mx && rig[i] == mx && mx % 2 == 0){
      res++;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int N, P[1d5];
// int lef[1d5], rig[1d5];
// {
//   int res = 0, cnt = 0, mx;
//   rd(N,P(N));
//   rep(i,N) if(i && P[i-1] < P[i]) lef[i] = lef[i-1] + 1;
//   rrep(i,N) if(i+1 < N && P[i] > P[i+1]) rig[i] = rig[i+1] + 1;
// 
//   mx = max(lef(N));
//   mx >?= max(rig(N));
// 
//   rep(i,N) if(lef[i] == mx || rig[i] == mx) cnt++;
//   if(cnt > 1) wt(0), return 0;
// 
//   rep(i,N) if(lef[i] == mx && rig[i] == mx && mx % 2 == 0) res++;
//   wt(res);
// }