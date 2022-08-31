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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int K;
int res[100];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    rd(K);
    if(N%2 == K%2){
      int i;
      if(N < K){
        wt_L("NO");
        wt_L('\n');
        continue;
      }
      for(i=(0);i<(K);i++){
        res[i] = 1;
      }
      res[K-1] = N - (K - 1);
    }
    else{
      int i;
      if(N%2){
        wt_L("NO");
        wt_L('\n');
        continue;
      }
      if(N < 2*K){
        wt_L("NO");
        wt_L('\n');
        continue;
      }
      for(i=(0);i<(K);i++){
        res[i] = 2;
      }
      res[K-1] = N - 2 * (K - 1);
    }
    wt_L("YES");
    wt_L('\n');
    {
      int WYIGIcGE;
      if(K==0){
        wt_L('\n');
      }
      else{
        for(WYIGIcGE=(0);WYIGIcGE<(K-1);WYIGIcGE++){
          wt_L(res[WYIGIcGE]);
          wt_L(' ');
        }
        wt_L(res[WYIGIcGE]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, K;
// int res[100];
// {
//   REP(rd_int()){
//     rd(N,K);
//     if(N%2 == K%2){
//       if(N < K) wt("NO"), continue;
//       rep(i,K) res[i] = 1;
//       res[K-1] = N - (K - 1);
//     } else {
//       if(N%2) wt("NO"), continue;
//       if(N < 2*K) wt("NO"), continue;
//       rep(i,K) res[i] = 2;
//       res[K-1] = N - 2 * (K - 1);
//     }
//     wt("YES");
//     wt(res(K));
//   }
// }