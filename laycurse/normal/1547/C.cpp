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
int K;
int As;
int Bs;
int A[101];
int B[101];
int res[200];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int aa = 0;
    int bb = 0;
    int ress = 0;
    rd(K);
    rd(As);
    rd(Bs);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(As);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(Bs);xr20shxY++){
        rd(B[xr20shxY]);
      }
    }
    A[As] = B[Bs] = 1073709056;
    while(aa < As || bb < Bs){
      if(A[aa] < B[bb]){
        if(A[aa]==0){
          K++;
        }
        if(K < A[aa]){
          wt_L(-1);
          wt_L('\n');
          goto Q5VJL1cS;
        }
        res[ress++] = A[aa++];
      }
      else{
        if(B[bb]==0){
          K++;
        }
        if(K < B[bb]){
          wt_L(-1);
          wt_L('\n');
          goto Q5VJL1cS;
        }
        res[ress++] = B[bb++];
      }
    }
    {
      int tU__gIr_;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(tU__gIr_=(0);tU__gIr_<(ress-1);tU__gIr_++){
          wt_L(res[tU__gIr_]);
          wt_L(' ');
        }
        wt_L(res[tU__gIr_]);
        wt_L('\n');
      }
    }
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210708-1

// --- original code ---
// //no-unlocked
// int K, As, Bs, A[101], B[101];
// int res[200];
// {
//   REP(rd_int()){
//     int aa = 0, bb = 0, ress = 0;
//     rd(K,As,Bs,A(As),B(Bs));
//     A[As] = B[Bs] = int_inf;
//     while(aa < As || bb < Bs){
//       if(A[aa] < B[bb]){
//         if(A[aa]==0) K++;
//         if(K < A[aa]) wt(-1), break_continue;
//         res[ress++] = A[aa++];
//       } else {
//         if(B[bb]==0) K++;
//         if(K < B[bb]) wt(-1), break_continue;
//         res[ress++] = B[bb++];
//       }
//     }
//     wt(res(ress));
//   }
// }