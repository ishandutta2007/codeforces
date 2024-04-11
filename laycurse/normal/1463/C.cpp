#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T1, class T2, class T3> inline T1 Kth1_L(const T1 a, const T2 b, const T3 c){
  if(a <= b){
    if(b <= c){
      return b;
    }
    if(c <= a){
      return a;
    }
    return c;
  }
  if(a <= c){
    return a;
  }
  if(c <= b){
    return b;
  }
  return c;
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
int N;
long long T[100000+1];
long long X[100000+1];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int res = 0;
    long long xx = 0;
    long long tt = 0;
    long long d;
    long long x1;
    long long x2;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(T[cTE1_r3A]);
        rd(X[cTE1_r3A]);
      }
    }
    T[N] = 4611686016279904256LL;
    for(i=(0);i<(N);i++){
      if(tt <= T[i]){
        if(X[i] >= xx){
          d =1;
        }
        else{
          d =-1;
        }
        tt = T[i] + d * (X[i] - xx);
        xx = X[i];
        if(tt <= T[i+1]){
          res++;
        }
      }
      else{
        x1 = xx - (tt - T[i]) * d;
        x2 = xx -max_L(0, tt - T[i+1])* d;
        if(Kth1_L(x1, x2, X[i])== X[i]){
          res++;
        }
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20201206-1

// --- original code ---
// //no-unlocked
// int N; ll T[1d5+1], X[1d5+1];
// {
//   REP(rd_int()){
//     int res = 0;
//     ll xx = 0, tt = 0, d, x1, x2;
//     rd(N,(T,X)(N));
//     T[N] = ll_inf;
//     rep(i,N){
//       if(tt <= T[i]){
//         d = if[X[i] >= xx, 1, -1];
//         tt = T[i] + d * (X[i] - xx);
//         xx = X[i];
//         if(tt <= T[i+1]) res++;
//       } else {
//         x1 = xx - (tt - T[i]) * d;
//         x2 = xx - max(0, tt - T[i+1]) * d;
//         if(Kth1(x1, x2, X[i]) == X[i]) res++;
//       }
//     }
//     wt(res);
//   }
// }