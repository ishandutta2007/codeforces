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
int ask(int n){
  wt_L("?");
  wt_L(' ');
  wt_L(n+1);
  wt_L('\n');
  return rd_int();
}
int main(){
  int N;
  rd(N);
  int K;
  rd(K);
  int turn = 0;
  int p = 0;
  int x;
  int mn = -1;
  int mx = -1;
  int res;
  while(mn==-1 || mx==-1){
    p = (p + (turn++)) % N;
    x = ask(p);
    if(x < K){
      mn = p;
    }
    if(x > K){
      mx = p;
    }
  }
  if(mx < mn){
    mx += N;
  }
  int Q5VJL1cS;
  int e98WHCEY;
  int cTE1_r3A;
  Q5VJL1cS = mn;
  e98WHCEY = mx;
  while(Q5VJL1cS < e98WHCEY){
    if((Q5VJL1cS + e98WHCEY)%2==0){
      cTE1_r3A = (Q5VJL1cS + e98WHCEY) / 2;
    }
    else{
      cTE1_r3A = (Q5VJL1cS + e98WHCEY + 1) / 2;
    }
    if(ask(cTE1_r3A%N) <= K){
      Q5VJL1cS = cTE1_r3A;
    }
    else{
      e98WHCEY = cTE1_r3A - 1;
    }
  }
  res =e98WHCEY% N;
  wt_L("!");
  wt_L(' ');
  wt_L(res+1);
  wt_L('\n');
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //interactive
// int ask(int n){
//   wt("?", n+1);
//   return rd_int();
// }
// 
// {
//   int @N, @K;
//   int turn = 0, p = 0, x;
//   int mn = -1, mx = -1, res;
// 
//   while(mn==-1 || mx==-1){
//     p = (p + (turn++)) % N;
//     x = ask(p);
//     if(x < K) mn = p;
//     if(x > K) mx = p;
//   }
//   if(mx < mn) mx += N;
// 
//   res = bsearch_max[int,p,mn,mx](ask(p%N) <= K) % N;
//   wt("!", res+1);
// }