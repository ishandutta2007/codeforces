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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T> int FactorM_L(T N, T fac[]){
  T i;
  int sz = 0;
  while(N%2==0){
    fac[sz] = 2;
    N /= 2;
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    while(N%i==0){
      fac[sz] = i;
      N /= i;
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    sz++;
  }
  return sz;
}
int fs;
int f[100];
int solve(int N){
  int e = 1;
  if(N==1){
    return 0;
  }
  if(N==2){
    return 1;
  }
  if(N%2==1){
    return 1;
  }
  while(N%2==0){
    e *= 2;
    N /= 2;
  }
  fs =FactorM_L(N, f);
  if(fs > 1){
    return 1;
  }
  if(fs==0){
    return 0;
  }
  if(e==2){
    return 0;
  }
  return 1;
}
int main(){
  int Q5VJL1cS;
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int N = rd_int();
    if(solve(N)==0){
      wt_L("FastestFinger");
      wt_L('\n');
    }
    else{
      wt_L("Ashishgup");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// 
// int fs, f[100];
// int solve(int N){
//   int e = 1;
//   if(N==1) return 0;
//   if(N==2) return 1;
//   if(N%2==1) return 1;
//   while(N%2==0) e *= 2, N /= 2;
//   fs = FactorM(N, f);
//   if(fs > 1) return 1;
//   if(fs==0) return 0;
//   if(e==2) return 0;
//   return 1;
// }
// {
//   REP(rd_int()){
//     int N = rd_int();
//     wt(if[solve(N)==0, "FastestFinger", "Ashishgup"]);
//   }
// }