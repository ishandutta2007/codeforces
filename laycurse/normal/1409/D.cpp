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
template<class T> inline int sod_L(T n){
  int res = 0;
  while(n){
    res += n%10;
    n /= 10;
  }
  return res;
}
int ds;
int d[30];
long long pw[20];
int main(){
  int Q5VJL1cS, i;
  pw[0] = 1;
  for(i=(1);i<(20);i++){
    pw[i] = pw[i-1] * 10;
  }
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    long long N;
    long long S;
    long long res = 0;
    rd(N);
    rd(S);
    while(sod_L(N)> S){
      ds =Digit_L(N, d);
      for(i=(0);i<(ds);i++){
        if(d[i]){
          break;
        }
      }
      {
        auto KrdatlYV = (pw[i] * (10 - d[i]));
        res += KrdatlYV;
        N += KrdatlYV;
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int ds, d[30];
// ll pw[20];
// {
//   pw[0] = 1;
//   rep(i,1,20) pw[i] = pw[i-1] * 10;
//   REP(rd_int()){
//     ll N, S, res = 0;
//     rd(N, S);
//     while(sod(N) > S){
//       ds = Digit(N, d);
//       rep(i,ds) if(d[i]) break;
//       (res, N) += pw[i] * (10 - d[i]);
//     }
//     wt(res);
//   }
// }