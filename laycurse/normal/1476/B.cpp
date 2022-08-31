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
int N;
int K;
long long P[100];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    long long res;
    long long s;
    long long ok;
    rd(N);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(P[cTE1_r3A]);
      }
    }
    long long xr20shxY;
    long long WYIGIcGE;
    long long t_ynMSdg;
    xr20shxY = 0;
    WYIGIcGE = 100000000000000LL;
    while(xr20shxY < WYIGIcGE){
      int i;
      if((xr20shxY + WYIGIcGE)%2==0){
        t_ynMSdg = (xr20shxY + WYIGIcGE) / 2;
      }
      else{
        t_ynMSdg = (xr20shxY + WYIGIcGE - 1) / 2;
      }
      ok = 1;
      s = t_ynMSdg + P[0];
      for(i=(1);i<(N);i++){
        if(P[i] * 100 > K * s){
          ok = 0;
          break;
        }
        s += P[i];
      }
      if(ok){
        WYIGIcGE = t_ynMSdg;
      }
      else{
        xr20shxY = t_ynMSdg + 1;
      }
    }
    res =WYIGIcGE;
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// int N, K; ll P[100];
// {
//   REP(rd_int()){
//     ll res, s, ok;
//     rd(N,K,P(N));
//     res = bsearch_min[ll, x, 0, 1d14][
//       ok = 1;
//       s = x + P[0];
//       rep(i,1,N){
//         if(P[i] * 100 > K * s) ok = 0, break;
//         s += P[i];
//       }
//     ](ok);
//     wt(res);
//   }
// }