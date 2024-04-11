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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int A[4];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int mask;
    int k;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(4);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(mask=(0);mask<(1<<4);mask++){
      int i;
      for(i=(0);i<(4);i++){
        if(((mask) &(1<<(i)))){
          if(((mask) &(1<<((i+1)%4)))){
            k =1+1;
          }
          else{
            k =1+0;
          }
        }
        else{
          if(((mask) &(1<<((i+1)%4)))){
            k =0+1;
          }
          else{
            k =0+0;
          }
        }
        if(!(k <= A[i]  &&  A[i] <= k + N - 2)){
          goto xr20shxY;
        }
      }
      wt_L("YES");
      wt_L('\n');
      goto Q5VJL1cS;
      xr20shxY:;
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int N, A[4];
// {
//   REP(rd_int()){
//     int k;
//     rd(N,A(4));
//     rep(mask,1<<4){
//       rep(i,4){
//         k = if[BIT_ith(mask,i), 1, 0] + if[BIT_ith(mask,(i+1)%4), 1, 0];
//         if(!(k <= A[i] <= k + N - 2)) break_continue;
//       }
//       wt("YES"), break_continue;
//     }
//     wt("NO");
//   }
// }