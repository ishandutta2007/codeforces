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
int G[100000];
int ok1[100000];
int ok2[100000];
int main(){
  int Lj4PdHRW;
  int i;
  int j;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    for(i=(0);i<(N);i++){
      ok1[i] = ok2[i] = 0;
    }
    for(i=(0);i<(N);i++){
      rd(K);
      {
        int WYIGIcGE;
        for(WYIGIcGE=(0);WYIGIcGE<(K);WYIGIcGE++){
          rd(G[WYIGIcGE]);G[WYIGIcGE] += (-1);
        }
      }
      for(j=(0);j<(K);j++){
        if(ok2[G[j]]==0){
          ok1[i] = ok2[G[j]] = 1;
          break;
        }
      }
    }
    for(i=(0);i<(N);i++){
      if(!ok1[i]){
        break;
      }
    }
    for(j=(0);j<(N);j++){
      if(!ok2[j]){
        break;
      }
    }
    if(i==N){
      wt_L("OPTIMAL");
      wt_L('\n');
      continue;
    }
    wt_L("IMPROVE");
    wt_L('\n');
    wt_L(i+1);
    wt_L(' ');
    wt_L(j+1);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200322-1 [beta]

// --- original code ---
// //no-unlocked
// int N, K, G[1d5];
// int ok1[1d5], ok2[1d5];
// {
//   int i, j;
//   REP(rd_int()){
//     rd(N);
//     rep(i,N) ok1[i] = ok2[i] = 0;
//     rep(i,N){
//       rd(K,(G--)(K));
//       rep(j,K) if(ok2[G[j]]==0) ok1[i] = ok2[G[j]] = 1, break;
//     }
//     rep(i,N) if(!ok1[i]) break;
//     rep(j,N) if(!ok2[j]) break;
//     if(i==N) wt("OPTIMAL"), continue;
//     wt("IMPROVE");
//     wt(i+1, j+1);
//   }
// }