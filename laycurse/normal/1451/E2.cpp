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
int arr[1000000];
int fn[1000000];
int res[1000000];
int tmp[1000000];
int main(){
  int i, loop;
  int x;
  int y;
  int mask;
  int k;
  rd(N);
  for(i=(1);i<(N);i++){
    wt_L("XOR");
    wt_L(' ');
    wt_L(1);
    wt_L(' ');
    wt_L(i+1);
    wt_L('\n');
    rd(arr[i]);
  }
  for(loop=(0);loop<(2);loop++){
    if(loop==0){
      mask =1;
    }
    else{
      mask =N-2;
    }
    for(i=(0);i<(N);i++){
      fn[i] = -1;
    }
    for(i=(0);i<(N);i++){
      if(fn[arr[i]&mask] >= 0){
        {
          auto WYIGIcGE = (fn[arr[i]&mask]);
          auto t_ynMSdg = ( i);
          x = WYIGIcGE;
          y = t_ynMSdg;
        }
        wt_L("AND");
        wt_L(' ');
        wt_L(x+1);
        wt_L(' ');
        wt_L(y+1);
        wt_L('\n');
        k = (rd_int() & mask);
        res[x] |= k;
        res[y] |= k;
        if(x != 0 && y != 0){
          res[0] |= ((arr[x]^res[x]) & mask);
        }
        for(i=(1);i<(N);i++){
          if(i!=x && i!=y){
            res[i] |= ((arr[i]^res[0]) & mask);
          }
        }
        break;
      }
      fn[arr[i]&mask] = i;
    }
  }
  wt_L("!");
  wt_L(' ');
  {
    int tU__gIr_;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(tU__gIr_=(0);tU__gIr_<(N-1);tU__gIr_++){
        wt_L(res[tU__gIr_]);
        wt_L(' ');
      }
      wt_L(res[tU__gIr_]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20201121-1

// --- original code ---
// //interactive
// int N;
// int arr[1d6], fn[1d6];
// int res[1d6], tmp[1d6];
// {
//   int x, y, mask, k;
//   rd(N);
//   rep(i,1,N){
//     wt("XOR", 1, i+1);
//     rd(arr[i]);
//   }
//   rep(loop,2){
//     mask = if[loop==0, 1, N-2];
//     rep(i,N) fn[i] = -1;
//     rep(i,N){
//       if(fn[arr[i]&mask] >= 0){
//         (x, y) = (fn[arr[i]&mask], i);
//         wt("AND", x+1, y+1);
//         k = (rd_int() & mask);
//         res[x] |= k;
//         res[y] |= k;
//         if(x != 0 && y != 0) res[0] |= ((arr[x]^res[x]) & mask);
//         rep(i,1,N) if(i!=x && i!=y) res[i] |= ((arr[i]^res[0]) & mask);
//         break;
//       }
//       fn[arr[i]&mask] = i;
//     }
//   }
//   wt("!",res(N));
// }