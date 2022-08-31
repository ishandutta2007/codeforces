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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
int s;
int a;
int b;
int c;
int q(int i, int j){
  if(i==j){
    return -1;
  }
  wt_L("?");
  wt_L(' ');
  wt_L(i+1);
  wt_L(' ');
  wt_L(j+1);
  wt_L('\n');
  return rd_int() - 1;
}
int main(){
  rd(N);
  s = q(0,N-1);
  a = 0;
  b = N;
  while(b - a > 1){
    c = (a+b) / 2;
    if(a <= s  &&  s < c){
      if(q(a,c-1) == s){
        b = c;
      }
      else{
        a = c;
      }
      continue;
    }
    if(c <= s  &&  s < b){
      if(q(c,b-1) == s){
        a = c;
      }
      else{
        b = c;
      }
      continue;
    }
    if(s < a){
      if(q(s,c-1) == s){
        b = c;
      }
      else{
        a = c;
      }
      continue;
    }
    if(b <= s){
      if(q(c,s) == s){
        a = c;
      }
      else{
        b = c;
      }
      continue;
    }
  }
  wt_L("!");
  wt_L(' ');
  wt_L(a+1);
  wt_L('\n');
  return 0;
}
// cLay version 20210103-1 [bug fixed 4]

// --- original code ---
// //interactive
// int N, s, a, b, c;
// 
// int q(int i, int j){
//   if(i==j) return -1;
//   wt("?", i+1, j+1);
//   return rd_int() - 1;
// }
// 
// {
//   rd(N);
//   s = q(0,N-1);
// 
//   a = 0; b = N;
//   while(b - a > 1){
//     c = (a+b) / 2;
// 
//     if(a <= s < c){
//       if(q(a,c-1) == s) b = c;
//       else              a = c;
//       continue;
//     }
//     if(c <= s < b){
//       if(q(c,b-1) == s) a = c;
//       else              b = c;
//       continue;
//     }
//     if(s < a){
//       if(q(s,c-1) == s) b = c;
//       else              a = c;
//       continue;
//     }
//     if(b <= s){
//       if(q(c,s) == s) a = c;
//       else            b = c;
//       continue;
//     }
//   }
//   wt("!", a+1);
// }