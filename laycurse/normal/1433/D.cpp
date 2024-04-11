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
int A[5000];
int as;
int a[5000];
int bs;
int b[5000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    as = bs = 0;
    for(i=(0);i<(N);i++){
      if(A[i]==A[0]){
        a[as++] = i+1;
      }
    }
    for(i=(0);i<(N);i++){
      if(A[i]!=A[0]){
        b[bs++] = i+1;
      }
    }
    if(as==N){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    wt_L("YES");
    wt_L('\n');
    for(i=(0);i<(bs);i++){
      wt_L(a[0]);
      wt_L(' ');
      wt_L(b[i]);
      wt_L('\n');
    }
    for(i=(1);i<(as);i++){
      wt_L(a[i]);
      wt_L(' ');
      wt_L(b[0]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20201115-2

// --- original code ---
// //no-unlocked
// int N, A[5000];
// int as, a[5000], bs, b[5000];
// {
//   REP(rd_int()){
//     rd(N,A(N));
//     as = bs = 0;
//     rep(i,N) if(A[i]==A[0]) a[as++] = i+1;
//     rep(i,N) if(A[i]!=A[0]) b[bs++] = i+1;
//     if(as==N) wt("NO"), continue;
//     wt("YES");
//     rep(i,bs) wt(a[0], b[i]);
//     rep(i,1,as) wt(a[i], b[0]);
//   }
// }