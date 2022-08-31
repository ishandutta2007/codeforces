#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int hCmBdyQB, i;
    int N;
    rd(N);
    int B[N];
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(B[cTE1_r3A]);B[cTE1_r3A] += (-1);
      }
    }
    int P[N];
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
        rd(P[xr20shxY]);P[xr20shxY] += (-1);
      }
    }
    int res[N];
    int dist[N];
    int cur = 0;
    for(i=(0);i<(N);i++){
      dist[i] = -1;
    }
    for(i=(0);i<(N);i++){
      if(B[i] == i){
        dist[i] = res[i] = 0;
        break;
      }
    }
    if(P[0] != i){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    for(hCmBdyQB=(1);hCmBdyQB<(N);hCmBdyQB++){
      auto&k = P[hCmBdyQB];
      if(dist[B[k]] == -1){
        wt_L(-1);
        wt_L('\n');
        goto Q5VJL1cS;
      }
      dist[k] = ++cur;
      res[k] = dist[k] - dist[B[k]];
    }
    {
      int YREPHmFM;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(YREPHmFM=(0);YREPHmFM<(N-1);YREPHmFM++){
          wt_L(res[YREPHmFM]);
          wt_L(' ');
        }
        wt_L(res[YREPHmFM]);
        wt_L('\n');
      }
    }
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20211024-1 [beta]

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N, @B[N]--, @P[N]--, res[N], dist[N], cur = 0;
// 
//   rep(i,N) dist[i] = -1;
//   rep(i,N) if(B[i] == i) dist[i] = res[i] = 0, break;
//   if(P[0] != i) wt(-1), continue;
//   rep[P](k,1,N){
//     if(dist[B[k]] == -1) wt(-1), break_continue;
//     dist[k] = ++cur;
//     res[k] = dist[k] - dist[B[k]];
//   }
//   wt(res(N));
// }