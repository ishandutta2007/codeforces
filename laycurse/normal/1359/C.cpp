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
    long long H;
    long long C;
    long long T;
    long long tmp1;
    long long tmp2;
    long long x1;
    long long z;
    long long x2;
    rd(H);
    rd(C);
    rd(T);
    {
      auto cTE1_r3A = (C);
      H -= cTE1_r3A;
      T -= cTE1_r3A;
    }
    if(2*T <= H){
      wt_L(2);
      wt_L('\n');
      continue;
    }
    long long RZTsC2BF;
    long long FmcKpFmN;
    long long xr20shxY;
    RZTsC2BF = 0;
    FmcKpFmN = 1000000;
    while(RZTsC2BF < FmcKpFmN){
      if((RZTsC2BF + FmcKpFmN)%2==0){
        xr20shxY = (RZTsC2BF + FmcKpFmN) / 2;
      }
      else{
        xr20shxY = (RZTsC2BF + FmcKpFmN + 1) / 2;
      }
      if( (xr20shxY+1)*H >= T * (2*xr20shxY+1) ){
        RZTsC2BF = xr20shxY;
      }
      else{
        FmcKpFmN = xr20shxY - 1;
      }
    }
    tmp1 =FmcKpFmN;
    tmp2 = tmp1 + 1;
    x1 = (tmp1 + 1) * H * (2 * tmp2 + 1);
    z = T * (2 * tmp1 + 1) * (2 * tmp2 + 1);
    x2 = (tmp2 + 1) * H * (2 * tmp1 + 1);
    if(x1 - z <= z - x2){
      wt_L(2*tmp1+1);
      wt_L('\n');
    }
    else{
      wt_L(2*tmp2+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// {
//   REP(rd_int()){
//     ll H, C, T;
//     ll tmp1, tmp2, x1, z, x2;
//     rd(H,C,T);
//     (H, T) -= C;
//     if(2*T <= H) wt(2), continue;
// 
//     tmp1 = bsearch_max[ll,x,0,1d6]( (x+1)*H >= T * (2x+1) );
//     tmp2 = tmp1 + 1;
// 
//     x1 = (tmp1 + 1) * H * (2 * tmp2 + 1);
//     z = T * (2 * tmp1 + 1) * (2 * tmp2 + 1);
//     x2 = (tmp2 + 1) * H * (2 * tmp1 + 1);
//     wt(if[x1 - z <= z - x2, 2*tmp1+1, 2*tmp2+1]);
//   }
// }