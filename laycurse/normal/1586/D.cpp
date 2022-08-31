#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
int arr[100];
int res[100];
int sz;
int s;
int st[100];
int q(int k, int d){
  int i;
  int res;
  for(i=(0);i<(N);i++){
    arr[i] = N;
  }
  arr[k] -= d;
  wt_L("?");
  wt_L(' ');
  {
    int Q5VJL1cS;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(Q5VJL1cS=(0);Q5VJL1cS<(N-1);Q5VJL1cS++){
        wt_L(arr[Q5VJL1cS]);
        wt_L(' ');
      }
      wt_L(arr[Q5VJL1cS]);
      wt_L('\n');
    }
  }
  rd(res);res += (-1);
  if(res >= k){
    res = -1;
  }
  return res;
}
int main(){
  int i;
  int j;
  int k;
  rd(N);
  for(i=(0);i<(N);i++){
    res[i] = -1;
  }
  for(i=(N)-1;i>=(0);i--){
    if(res[i] == -1){
      sz = 0;
      st[sz++] = i;
      for(k=(1);k<(N);k++){
        j = q(i,k);
        if(j==-1){
          break;
        }
        st[sz++] = j;
      }
      while(sz){
        res[st[--sz]] = s++;
      }
    }
  }
  wt_L("!");
  wt_L(' ');
  {
    int a2conNHc;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(a2conNHc=(0);a2conNHc<(N-1);a2conNHc++){
        wt_L(res[a2conNHc]+1);
        wt_L(' ');
      }
      wt_L(res[a2conNHc]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //interactive
// int N;
// int arr[100], res[100];
// int sz, s, st[100];
// 
// int q(int k, int d){
//   int res;
//   rep(i,N) arr[i] = N;
//   arr[k] -= d;
//   wt("?", arr(N));
//   rd(res--);
//   if(res >= k) res = -1;
//   return res;
// }
// 
// {
//   int i, j, k;
//   rd(N);
//   rep(i,N) res[i] = -1;
// 
//   rrep(i,N) if(res[i] == -1){
//     sz = 0;
//     st[sz++] = i;
//     rep(k,1,N){
//       j = q(i,k);
//       if(j==-1) break;
//       st[sz++] = j;
//     }
//     while(sz) res[st[--sz]] = s++;
//   }
// 
//   wt("!", res(N)+1);
// }