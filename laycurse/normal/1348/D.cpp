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
int ress;
int res[100];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int c = 1;
    int i;
    ress = 0;
    rd(N);N += (-1);
    for(;;){
      if(N <= 2*c){
        res[ress++] = N - c;
        break;
      }
      i =min_L(c, N / 2 - c);
      res[ress++] = i;
      c += i;
      N -= c;
    }
    wt_L(ress);
    wt_L('\n');
    {
      int xr20shxY;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(xr20shxY=(0);xr20shxY<(ress-1);xr20shxY++){
          wt_L(res[xr20shxY]);
          wt_L(' ');
        }
        wt_L(res[xr20shxY]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N;
// int ress, res[100];
// {
//   REP(rd_int()){
//     int c = 1, i;
//     ress = 0;
//     rd(N--);
//     for(;;){
//       if(N <= 2*c){
//         res[ress++] = N - c;
//         break;
//       }
//       i = min(c, N / 2 - c);
//       res[ress++] = i;
//       c += i;
//       N -= c;
//     }
//     wt(ress);
//     wt(res(ress));
//   }
// }