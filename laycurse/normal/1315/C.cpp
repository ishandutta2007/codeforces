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
int B[100];
int A[200];
int ap[200];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(B[cTE1_r3A]);B[cTE1_r3A] += (-1);
      }
    }
    for(i=(0);i<(2*N);i++){
      A[i] = ap[i] = -1;
    }
    for(i=(0);i<(N);i++){
      ap[B[i]] = i;
    }
    for(i=(0);i<(2*N);i++){
      int j;
      if(ap[i] >= 0){
        A[ap[i]*2] = i;
        continue;
      }
      for(j=(0);j<(N);j++){
        if(A[2*j] >= 0 && A[2*j+1] == -1){
          A[2*j+1] = i;
          goto ao_dF3pO;
        }
      }
      wt_L(-1);
      wt_L('\n');
      goto Q5VJL1cS;
      ao_dF3pO:;
    }
    {
      int V9aVTaxx;
      if(2*N==0){
        wt_L('\n');
      }
      else{
        for(V9aVTaxx=(0);V9aVTaxx<(2*N-1);V9aVTaxx++){
          wt_L(A[V9aVTaxx]+1);
          wt_L(' ');
        }
        wt_L(A[V9aVTaxx]+1);
        wt_L('\n');
      }
    }
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, B[100], A[200];
// int ap[200];
// {
//   REP(rd_int()){
//     rd(N,(B--)(N));
//     rep(i,2N) A[i] = ap[i] = -1;
//     rep(i,N) ap[B[i]] = i;
// 
//     rep(i,2N){
//       if(ap[i] >= 0){
//         A[ap[i]*2] = i;
//         continue;
//       }
//       rep(j,N) if(A[2j] >= 0 && A[2j+1] == -1) A[2j+1] = i, break_continue;
//       wt(-1), break_continue;
//     }
//     wt(A(2N)+1);
//   }
// }