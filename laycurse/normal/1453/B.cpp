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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
long long A[200000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    long long res;
    long long tmp;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      remove_reference<decltype(abs(A[xr20shxY]-A[xr20shxY-1]))>::type WYIGIcGE;
      int t_ynMSdg = 0;
      if((1) > ((N)-1)){
        WYIGIcGE = 0;
      }
      else{
        for(xr20shxY = 1; xr20shxY <= (N)-1; xr20shxY++){
          if(t_ynMSdg == 0){
            WYIGIcGE = abs(A[xr20shxY]-A[xr20shxY-1]);
            t_ynMSdg = 1;
            continue;
          }
          WYIGIcGE += abs(A[xr20shxY]-A[xr20shxY-1]);
        }
      }
      res =WYIGIcGE;
    }
    chmax(tmp, max_L(abs(A[1] - A[0]), abs(A[N-1] - A[N-2])));
    for(i=(1);i<(N-1);i++){
      chmax(tmp, abs(A[i+1]-A[i]) + abs(A[i]-A[i-1]) - abs(A[i+1]-A[i-1]));
    }
    wt_L(res - tmp);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20201205-1

// --- original code ---
// //no-unlocked
// int N; ll A[2d5];
// {
//   REP(rd_int()){
//     ll res, tmp;
//     rd(N,A(N));
//     res = sum[i,1,N](abs(A[i]-A[i-1]));
//     tmp >?= max(abs(A[1] - A[0]), abs(A[N-1] - A[N-2]));
//     rep(i,1,N-1) tmp >?= abs(A[i+1]-A[i]) + abs(A[i]-A[i-1]) - abs(A[i+1]-A[i-1]);
//     wt(res - tmp);
//   }
// }