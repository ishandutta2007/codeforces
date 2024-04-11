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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[300000];
int res[300000+3];
int pre[300000+3];
int mx[300000+3];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int k;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      res[i] = 1073709056;
    }
    for(i=(0);i<(N+1);i++){
      pre[i] = -1;
    }
    for(i=(0);i<(N+1);i++){
      mx[i] = 0;
    }
    for(i=(0);i<(N);i++){
      k = A[i];
      chmax(mx[k], i - pre[k]);
      pre[k] = i;
    }
    for(i=(0);i<(N+1);i++){
      chmax(mx[i], N - pre[i]);
    }
    for(i=(N+1)-1;i>=(0);i--){
      res[mx[i]-1] = i;
    }
    for(i=(1);i<(N);i++){
      chmin(res[i], res[i-1]);
    }
    for(i=(0);i<(N);i++){
      if(res[i]==1073709056){
        res[i] = -1;
      }
    }
    {
      int XJIcIBrW;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(XJIcIBrW=(0);XJIcIBrW<(N-1);XJIcIBrW++){
          wt_L(res[XJIcIBrW]);
          wt_L(' ');
        }
        wt_L(res[XJIcIBrW]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200926-1

// --- original code ---
// //no-unlocked
// int N, A[3d5];
// int res[3d5+3];
// int pre[3d5+3], mx[3d5+3];
// {
//   REP(rd_int()){
//     int i, k;
//     rd(N,A(N));
//     rep(i,N) res[i] = int_inf;
// 
//     rep(i,N+1) pre[i] = -1;
//     rep(i,N+1) mx[i] = 0;
//     rep(i,N){
//       k = A[i];
//       mx[k] >?= i - pre[k];
//       pre[k] = i;
//     }
//     rep(i,N+1) mx[i] >?= N - pre[i];
//     rrep(i,N+1) res[mx[i]-1] = i;
//     rep(i,1,N) res[i] <?= res[i-1];
// 
//     rep(i,N) if(res[i]==int_inf) res[i] = -1;
//     wt(res(N));
//   }
// }