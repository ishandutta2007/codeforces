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
template<class T> int Factor_L(T N, T fac[], int fs[]){
  T i;
  int sz = 0;
  if(N%2==0){
    fac[sz] = 2;
    fs[sz] = 1;
    N /= 2;
    while(N%2==0){
      N /= 2;
      fs[sz]++;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      fs[sz] = 1;
      N /= i;
      while(N%i==0){
        N /= i;
        fs[sz]++;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    fs[sz] = 1;
    sz++;
  }
  return sz;
}
int fs;
long long f[30];
int fn[30];
int mx;
long long res[100];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    long long N;
    rd(N);
    fs =Factor_L(N, f, fn);
    {
      int cTE1_r3A;
      int RZTsC2BF;
      if(fs==0){
        RZTsC2BF = 0;
      }
      else{
        RZTsC2BF = fn[0];
        for(cTE1_r3A=(1);cTE1_r3A<(fs);cTE1_r3A++){
          RZTsC2BF = max_L(RZTsC2BF, fn[cTE1_r3A]);
        }
      }
      mx =RZTsC2BF;
    }
    for(i=(0);i<(mx);i++){
      res[i] = 1;
    }
    for(i=(0);i<(fs);i++){
      int j;
      for(j=(0);j<(fn[i]);j++){
        res[mx-1-j] *= f[i];
      }
    }
    wt_L(mx);
    wt_L('\n');
    {
      int hCmBdyQB;
      if(mx==0){
        wt_L('\n');
      }
      else{
        for(hCmBdyQB=(0);hCmBdyQB<(mx-1);hCmBdyQB++){
          wt_L(res[hCmBdyQB]);
          wt_L(' ');
        }
        wt_L(res[hCmBdyQB]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20201205-1

// --- original code ---
// //no-unlocked
// int fs; ll f[30]; int fn[30], mx;
// ll res[100];
// {
//   REP(rd_int()){
//     ll @N;
//     fs = Factor(N, f, fn);
//     mx = max(fn(fs));
//     rep(i,mx) res[i] = 1;
//     rep(i,fs) rep(j,fn[i]) res[mx-1-j] *= f[i];
//     wt(mx);
//     wt(res(mx));
//   }
// }