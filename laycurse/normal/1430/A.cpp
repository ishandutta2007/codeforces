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
int res[1001][3];
int main(){
  int t_ynMSdg;
  int i;
  int j;
  int k;
  int m;
  for(i=0;3*i<=1000;i++){
    for(j=0;3*i+5*j<=1000;j++){
      for(k=0;3*i+5*j+7*k<=1000;k++){
        m = 3*i+5*j+7*k;
        {
          auto FmcKpFmN = (i);
          auto xr20shxY = ( j);
          auto WYIGIcGE = ( k);
          res[m][0] = FmcKpFmN;
          res[m][1] = xr20shxY;
          res[m][2] = WYIGIcGE;
        }
      }
    }
  }
  int KrdatlYV = rd_int();
  for(t_ynMSdg=(0);t_ynMSdg<(KrdatlYV);t_ynMSdg++){
    int N;
    rd(N);
    if(res[N][0]==res[N][1] && res[N][1]==res[N][2] && res[N][2]==0){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    wt_L(res[N][0]);
    wt_L(' ');
    wt_L(res[N][1]);
    wt_L(' ');
    wt_L(res[N][2]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20201102-1

// --- original code ---
// //no-unlocked
// int res[1001][3];
// {
//   int i, j, k, m;
//   for(i=0;3*i<=1000;i++) for(j=0;3*i+5*j<=1000;j++) for(k=0;3*i+5*j+7*k<=1000;k++){
//     m = 3*i+5*j+7*k;
//     (res[m][0], res[m][1], res[m][2]) = (i, j, k);
//   }
//   REP(rd_int()){
//     int @N;
//     if(res[N][0]==res[N][1]==res[N][2]==0) wt(-1), continue;
//     wt(res[N][0], res[N][1], res[N][2]);
//   }
// }