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
inline void rd(long long &x){
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
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
long long K;
long long A[200000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int xr20shxY;
    long long mx;
    rd(N);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    if(K%2){
      K =1;
    }
    else{
      K =2;
    }
    for(xr20shxY=(0);xr20shxY<(K);xr20shxY++){
      int i;
      {
        int KrdatlYV;
        long long ao_dF3pO;
        if(N==0){
          ao_dF3pO = 0;
        }
        else{
          ao_dF3pO = A[0];
          for(KrdatlYV=(1);KrdatlYV<(N);KrdatlYV++){
            ao_dF3pO = max_L(ao_dF3pO, A[KrdatlYV]);
          }
        }
        mx =ao_dF3pO;
      }
      for(i=(0);i<(N);i++){
        A[i] = mx - A[i];
      }
    }
    {
      int APIVbQlN;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(APIVbQlN=(0);APIVbQlN<(N-1);APIVbQlN++){
          wt_L(A[APIVbQlN]);
          wt_L(' ');
        }
        wt_L(A[APIVbQlN]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N;
// ll K, A[2d5];
// {
//   REP(rd_int()){
//     ll mx;
//     rd(N,K,A(N));
//     K = if[K%2, 1, 2];
//     rep(K){
//       mx = max(A(N));
//       rep(i,N) A[i] = mx - A[i];
//     }
//     wt(A(N));
//   }
// }