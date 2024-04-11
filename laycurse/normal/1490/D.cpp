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
int A[100];
int res[100];
void solve(int N, int A[], int d, int s){
  if(N==0){
    return;
  }
  int KL2GvlyY;
  remove_reference<decltype(A[KL2GvlyY])>::type Q5VJL1cS;
  int e98WHCEY = 0;
  int cTE1_r3A;
  if((0) > ((N)-1)){
    Q5VJL1cS = 0;
  }
  else{
    for(KL2GvlyY = 0; KL2GvlyY <= (N)-1; KL2GvlyY++){
      if(e98WHCEY == 0){
        Q5VJL1cS = A[KL2GvlyY];
        cTE1_r3A = KL2GvlyY;
        e98WHCEY = 1;
        continue;
      }
      const auto RZTsC2BF = A[KL2GvlyY];
      if(Q5VJL1cS < RZTsC2BF){
        Q5VJL1cS = RZTsC2BF;
        cTE1_r3A = KL2GvlyY;
      }
    }
  }
  int i = cTE1_r3A;
  res[i+s] = d;
  solve(i, A, d+1, s);
  solve(N-i-1, A+i+1, d+1, s+i+1);
}
int main(){
  int WYIGIcGE;
  int t_ynMSdg = rd_int();
  for(WYIGIcGE=(0);WYIGIcGE<(t_ynMSdg);WYIGIcGE++){
    rd(N);
    {
      int tU__gIr_;
      for(tU__gIr_=(0);tU__gIr_<(N);tU__gIr_++){
        rd(A[tU__gIr_]);A[tU__gIr_] += (-1);
      }
    }
    solve(N,A,0,0);
    {
      int V9aVTaxx;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(V9aVTaxx=(0);V9aVTaxx<(N-1);V9aVTaxx++){
          wt_L(res[V9aVTaxx]);
          wt_L(' ');
        }
        wt_L(res[V9aVTaxx]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 3]

// --- original code ---
// //no-unlocked
// int N, A[100];
// int res[100];
// void solve(int N, int A[], int d, int s){
//   if(N==0) return;
//   int i = argmax(A(N));
//   res[i+s] = d;
//   solve(i, A, d+1, s);
//   solve(N-i-1, A+i+1, d+1, s+i+1);
// }
// {
//   REP(rd_int()){
//     rd(N,(A--)(N));
//     solve(N,A,0,0);
//     wt(res(N));
//   }
// }