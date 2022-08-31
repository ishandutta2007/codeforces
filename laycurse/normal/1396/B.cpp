#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
int A[100];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int sm;
    int mx;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      int WYIGIcGE;
      if(N==0){
        WYIGIcGE = 0;
      }
      else{
        WYIGIcGE = A[0];
        for(xr20shxY=(1);xr20shxY<(N);xr20shxY++){
          WYIGIcGE += A[xr20shxY];
        }
      }
      sm =WYIGIcGE;
    }
    {
      int ao_dF3pO;
      int tU__gIr_;
      if(N==0){
        tU__gIr_ = 0;
      }
      else{
        tU__gIr_ = A[0];
        for(ao_dF3pO=(1);ao_dF3pO<(N);ao_dF3pO++){
          tU__gIr_ = max_L(tU__gIr_, A[ao_dF3pO]);
        }
      }
      mx =tU__gIr_;
    }
    if(mx > sm-mx){
      wt_L("T");
      wt_L('\n');
      continue;
    }
    if(sm%2==1){
      wt_L("T");
      wt_L('\n');
      continue;
    }
    wt_L("HL");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[100];
// {
//   REP(rd_int()){
//     int sm, mx;
//     rd(N,A(N));
//     sm = sum(A(N));
//     mx = max(A(N));
//     if(mx > sm-mx) wt("T"), continue;
//     if(sm%2==1) wt("T"), continue;
//     wt("HL");
//   }
// }