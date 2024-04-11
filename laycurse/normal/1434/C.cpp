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
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    long long A;
    rd(A);
    long long B;
    rd(B);
    long long C;
    rd(C);
    long long D;
    rd(D);
    long long i;
    long long res;
    if(A > B*C){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    long long cTE1_r3A;
    long long RZTsC2BF;
    long long FmcKpFmN;
    long long xr20shxY;
    cTE1_r3A = 1;
    RZTsC2BF = 2000000;
    remove_reference<decltype(A * xr20shxY - (D * i * (i-1) / 2 + (xr20shxY - i) * C) * B)>::type WYIGIcGE;
    remove_reference<decltype(A * xr20shxY - (D * i * (i-1) / 2 + (xr20shxY - i) * C) * B)>::type t_ynMSdg;
    remove_reference<decltype(A * xr20shxY - (D * i * (i-1) / 2 + (xr20shxY - i) * C) * B)>::type KrdatlYV;
    remove_reference<decltype(A * xr20shxY - (D * i * (i-1) / 2 + (xr20shxY - i) * C) * B)>::type ao_dF3pO;
    xr20shxY = cTE1_r3A;
    {
      i =min_L(xr20shxY, C/D+1);
      WYIGIcGE = A * xr20shxY - (D * i * (i-1) / 2 + (xr20shxY - i) * C) * B;
    }
    xr20shxY = RZTsC2BF;
    {
      i =min_L(xr20shxY, C/D+1);
      t_ynMSdg = A * xr20shxY - (D * i * (i-1) / 2 + (xr20shxY - i) * C) * B;
    }
    xr20shxY = FmcKpFmN = (cTE1_r3A + RZTsC2BF) / 2;
    {
      i =min_L(xr20shxY, C/D+1);
      KrdatlYV = A * xr20shxY - (D * i * (i-1) / 2 + (xr20shxY - i) * C) * B;
    }
    for(;;){
      if(RZTsC2BF - FmcKpFmN > FmcKpFmN - cTE1_r3A){
        xr20shxY = (FmcKpFmN + RZTsC2BF) / 2;
        if(xr20shxY == FmcKpFmN || xr20shxY == RZTsC2BF){
          break;
        }
      }
      else{
        xr20shxY = (cTE1_r3A + FmcKpFmN) / 2;
        if(xr20shxY == cTE1_r3A || xr20shxY == FmcKpFmN){
          break;
        }
      }
      {
        i =min_L(xr20shxY, C/D+1);
        ao_dF3pO = A * xr20shxY - (D * i * (i-1) / 2 + (xr20shxY - i) * C) * B;
      }
      if(RZTsC2BF - FmcKpFmN > FmcKpFmN - cTE1_r3A){
        if(KrdatlYV >= ao_dF3pO){
          RZTsC2BF = xr20shxY;
          t_ynMSdg = ao_dF3pO;
        }
        else{
          cTE1_r3A = FmcKpFmN;
          WYIGIcGE = KrdatlYV;
          FmcKpFmN = xr20shxY;
          KrdatlYV = ao_dF3pO;
        }
      }
      else{
        if(ao_dF3pO >= KrdatlYV){
          RZTsC2BF = FmcKpFmN;
          t_ynMSdg = KrdatlYV;
          FmcKpFmN = xr20shxY;
          KrdatlYV = ao_dF3pO;
        }
        else{
          cTE1_r3A = xr20shxY;
          WYIGIcGE = ao_dF3pO;
        }
      }
    }
    xr20shxY = RZTsC2BF;
    ao_dF3pO = t_ynMSdg;
    if(KrdatlYV >= ao_dF3pO){
      xr20shxY = FmcKpFmN;
      ao_dF3pO = KrdatlYV;
    }
    if(WYIGIcGE >= ao_dF3pO){
      xr20shxY = cTE1_r3A;
      ao_dF3pO = WYIGIcGE;
    }
    res =ao_dF3pO;
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20201115-1

// --- original code ---
// //no-unlocked
// {
//   REP(rd_int()){
//     ll @A, @B, @C, @D, i, res;
//     if(A > B*C) wt(-1), continue;
//     res = tsearch_max[ll,x,1,2d6][
//       i = min(x, C/D+1);
//     ](A * x - (D * i * (i-1) / 2 + (x - i) * C) * B);
//     wt(res);
//   }
// }