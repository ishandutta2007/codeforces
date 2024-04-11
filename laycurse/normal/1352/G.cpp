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
int ans[10][10];
int res[1000];
int main(){
  int ao_dF3pO;
  int i;
  int n;
  int p[10];
  for(n=(4);n<(8);n++){
    int Q5VJL1cS;
    for(Q5VJL1cS=(0);Q5VJL1cS<(n);Q5VJL1cS++){
      p[Q5VJL1cS] = Q5VJL1cS;
    }
    do{
      {
        for(i=(1);i<(n);i++){
          if(!(2 <= abs(p[i]-p[i-1])  &&  abs(p[i]-p[i-1]) <= 4)){
            break;
          }
        }
        if(i==n){
          break;
        }
      }
    }
    while(next_permutation(p,p+n));
    for(i=(0);i<(n);i++){
      ans[n][i] = p[i];
    }
  }
  int tU__gIr_ = rd_int();
  for(ao_dF3pO=(0);ao_dF3pO<(tU__gIr_);ao_dF3pO++){
    int j;
    rd(N);
    if(N<=3){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    i = 0;
    while(N - i >= 8){
      int j;
      for(j=(0);j<(4);j++){
        res[i+j] = ans[4][j] + i;
      }
      i += 4;
    }
    for(j=(0);j<(N-i);j++){
      res[i+j] = ans[N-i][j] + i;
    }
    {
      int iMWUTgY_;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(iMWUTgY_=(0);iMWUTgY_<(N-1);iMWUTgY_++){
          wt_L(res[iMWUTgY_]+1);
          wt_L(' ');
        }
        wt_L(res[iMWUTgY_]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N;
// int ans[10][10];
// int res[1000];
// {
//   int i, n, p[10];
//   rep(n,4,8){
//     rep_perm(p,n){
//       rep(i,1,n) if(!(2 <= abs(p[i]-p[i-1]) <= 4)) break;
//       if(i==n) break;
//     }
//     rep(i,n) ans[n][i] = p[i];
//   }
// 
//   REP(rd_int()){
//     rd(N);
//     if(N<=3) wt(-1), continue;
//     i = 0;
//     while(N - i >= 8){
//       rep(j,4) res[i+j] = ans[4][j] + i;
//       i += 4;
//     }
//     rep(j,N-i) res[i+j] = ans[N-i][j] + i;
//     wt(res(N)+1);
//   }
// }