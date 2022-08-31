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
int A[2000];
int es;
int e[2000];
int os;
int o[2000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, t_ynMSdg;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(2*N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    es = os = 0;
    for(i=(0);i<(2*N);i++){
      if(A[i]%2==0){
        e[es++] = i+1;
      }
      if(A[i]%2==1){
        o[os++] = i+1;
      }
    }
    for(t_ynMSdg=(0);t_ynMSdg<(N-1);t_ynMSdg++){
      if(es >= 2){
        wt_L(e[es-2]);
        wt_L(' ');
        wt_L(e[es-1]);
        wt_L('\n');
        es-=2;
        continue;
      }
      if(os >= 2){
        wt_L(o[os-2]);
        wt_L(' ');
        wt_L(o[os-1]);
        wt_L('\n');
        os-=2;
        continue;
      }
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[2000];
// int es, e[2000];
// int os, o[2000];
// {
//   REP(rd_int()){
//     rd(N,A(2N));
//     es = os = 0;
//     rep(i,2N){
//       if(A[i]%2==0) e[es++] = i+1;
//       if(A[i]%2==1) o[os++] = i+1;
//     }
//     rep(N-1){
//       if(es >= 2) wt(e[es-2], e[es-1]), es-=2, continue;
//       if(os >= 2) wt(o[os-2], o[os-1]), os-=2, continue;
//     }
//   }
// }