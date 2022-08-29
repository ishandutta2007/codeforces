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
int od[3][4] = {
  0, 1, 2, 3,
  0, 2, 3, 1,
  0, 3, 1, 2
};
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    long long N;
    long long p;
    long long st;
    long long res;
    int m;
    int b;
    rd(N);N += (-1);
    {
      auto cTE1_r3A = (N / 3);
      auto RZTsC2BF = ( N % 3);
      N = cTE1_r3A;
      m = RZTsC2BF;
    }
    st = 1;
    p = 1;
    while(N >= p){
      st += 3 * p;
      N -= p;
      p *= 4;
    }
    res = st + m * p;
    while(p > 1){
      p /= 4;
      b = N / p;
      N %= p;
      res += od[m][b] * p;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200412-1

// --- original code ---
// //no-unlocked
// int od[3][4] = {
//   0, 1, 2, 3,
//   0, 2, 3, 1,
//   0, 3, 1, 2
// };
// 
// {
//   REP(rd_int()){
//     ll N, p, st, res;
//     int m, b;
//     rd(N--);
//     (N, m) = (N / 3, N % 3);
// 
//     st = 1;
//     p = 1;
//     while(N >= p){
//       st += 3 * p;
//       N -= p;
//       p *= 4;
//     }
// 
//     res = st + m * p;
//     while(p > 1){
//       p /= 4;
//       b = N / p;
//       N %= p;
//       res += od[m][b] * p;
//     }
// 
//     wt(res);
//   }
// }
// 
// 
// /*int use[1d6];
// {
//   rep(i,1,1030) if(!use[i]){
//     rep(j,i+1,1d6) if(!use[j] && !use[i^j]){
//       use[i] = use[j] = use[i^j] = 1;
//       wt(i, j, i^j);
//       break;
//     }
//   }
// }*/