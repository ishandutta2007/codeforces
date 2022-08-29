#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
template<class T, class S> inline int Digit_L(T n, S b){
  int res = 0;
  while(n){
    res++;
    n /= b;
  }
  return res;
}
template<class T, class S> inline int Digit_L(T n, S res[]){
  int sz = 0;
  while(n){
    res[sz++] = n % 10;
    n /= 10;
  }
  return sz;
}
long long A;
long long K;
int s;
int d[20];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int add;
    rd(A);
    rd(K);K += (-1);
    while(K--){
      s =Digit_L(A, d);
      {
        int FmcKpFmN;
        int xr20shxY;
        if(s==0){
          xr20shxY = 0;
        }
        else{
          xr20shxY = d[0];
          for(FmcKpFmN=(1);FmcKpFmN<(s);FmcKpFmN++){
            xr20shxY = min_L(xr20shxY, d[FmcKpFmN]);
          }
        }
        {
          int KrdatlYV;
          int ao_dF3pO;
          if(s==0){
            ao_dF3pO = 0;
          }
          else{
            ao_dF3pO = d[0];
            for(KrdatlYV=(1);KrdatlYV<(s);KrdatlYV++){
              ao_dF3pO = max_L(ao_dF3pO, d[KrdatlYV]);
            }
          }
          add =ao_dF3pO*xr20shxY;
        }
      }
      if(add==0){
        break;
      }
      A += add;
    }
    wt_L(A);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// ll A, K;
// int s, d[20];
// {
//   REP(rd_int()){
//     int add;
//     rd(A,K--);
//     while(K--){
//       s = Digit(A, d);
//       add = max(d(s)) * min(d(s));
//       if(add==0) break;
//       A += add;
//     }
//     wt(A);
//   }
// }