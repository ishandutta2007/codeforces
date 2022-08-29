#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  return getchar();
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
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int main(){
  int i;
  int a;
  int b;
  int x;
  int y;
  int c1;
  int c2;
  int z1;
  int z2;
  int c;
  int z;
  rd(N);
  x = -1;
  y = N;
  a = b = 1073709056;
  while(y - x > 4){
    z1 = (x + y) / 2;
    z2 = z1 + 1;
    wt_L("?");
    wt_L(' ');
    wt_L(z1+1);
    wt_L('\n');
    rd(c1);
    wt_L("?");
    wt_L(' ');
    wt_L(z2+1);
    wt_L('\n');
    rd(c2);
    if(c1 < c2){
      y = z1;
      b = c1;
    }
    else{
      x = z2;
      a = c2;
    }
  }
  if(a < b){
    z = x;
    c = a;
  }
  else{
    z = y;
    c = b;
  }
  for(i=(x+1);i<(y);i++){
    wt_L("?");
    wt_L(' ');
    wt_L(i+1);
    wt_L('\n');
    rd(c1);
    if(c > c1){
      z = i;
      c = c1;
    }
  }
  wt_L("!");
  wt_L(' ');
  wt_L(z+1);
  wt_L('\n');
  return 0;
}
// cLay version 20210103-1 [bug fixed 2]

// --- original code ---
// //interactive
// int N;
// {
//   int a, b, x, y, c1, c2, z1, z2, c, z;
//   rd(N);
//   x = -1; y = N;
//   a = b = int_inf;
//   while(y - x > 4){
//     z1 = (x + y) / 2;
//     z2 = z1 + 1;
//     wt("?", z1+1);
//     rd(c1);
//     wt("?", z2+1);
//     rd(c2);
//     if(c1 < c2){
//       y = z1;
//       b = c1;
//     } else {
//       x = z2;
//       a = c2;
//     }
//   }
//   if(a < b){
//     z = x;
//     c = a;
//   } else {
//     z = y;
//     c = b;
//   }
//   rep(i,x+1,y){
//     wt("?", i+1);
//     rd(c1);
//     if(c > c1){
//       z = i;
//       c = c1;
//     }
//   }
//   wt("!", z+1);
// }