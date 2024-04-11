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
  long long U;
  long long V;
  long long t;
  rd(U);
  rd(V);
  if(U > V){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  if(U == V  &&  V == 0){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  if(U == V){
    wt_L(1);
    wt_L('\n');
    wt_L(U);
    wt_L('\n');
    return 0;
  }
  if(U%2 != V%2){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  t = (V - U) / 2;
  if((U & t)==0){
    wt_L(2);
    wt_L('\n');
    wt_L(t);
    wt_L(' ');
    wt_L(U+t);
    wt_L('\n');
    return 0;
  }
  wt_L(3);
  wt_L('\n');
  wt_L(U);
  wt_L(' ');
  wt_L(t);
  wt_L(' ');
  wt_L(t);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200314-1

// --- original code ---
// //no-unlocked
// {
//   ll U, V, t;
//   rd(U,V);
//   if(U > V) wt(-1), return 0;
//   if(U == V == 0) wt(0), return 0;
//   if(U == V) wtLn(1, U), return 0;
//   if(U%2 != V%2) wt(-1), return 0;
//   t = (V - U) / 2;
//   if((U & t)==0) wt(2), wt(t, U+t), return 0;
//   wt(3), wt(U, t, t);
// }