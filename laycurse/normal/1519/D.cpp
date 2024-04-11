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
long long A[5000];
long long B[5000];
long long calc(int x, int y){
  return A[x] * B[y] + A[y] * B[x] - A[x] * B[x] - A[y] * B[y];
}
int main(){
  int k;
  int x;
  int y;
  long long res = 0;
  long long tmp;
  long long ini;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){
      rd(B[e98WHCEY]);
    }
  }
  int FmcKpFmN;
  remove_reference<decltype(A[FmcKpFmN]*B[FmcKpFmN])>::type xr20shxY;
  int WYIGIcGE = 0;
  if((0) > ((N)-1)){
    xr20shxY = 0;
  }
  else{
    for(FmcKpFmN = 0; FmcKpFmN <= (N)-1; FmcKpFmN++){
      if(WYIGIcGE == 0){
        xr20shxY = A[FmcKpFmN]*B[FmcKpFmN];
        WYIGIcGE = 1;
        continue;
      }
      xr20shxY += A[FmcKpFmN]*B[FmcKpFmN];
    }
  }
  ini =xr20shxY;
  for(k=(0);k<(N);k++){
    int m;
    for(m=(0);m<(2);m++){
      x = y = k;
      if(m){
        x--;
      }
      if(x < 0){
        continue;
      }
      chmax(res, tmp = ini + calc(x, y));
      for(;;){
        x--;
        y++;
        if(x < 0 || y >= N){
          break;
        }
        chmax(res, tmp += calc(x, y));
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// //working_memory=10MB
// int N; ll A[5000], B[5000];
// 
// ll calc(int x, int y){
//   return A[x] * B[y] + A[y] * B[x] - A[x] * B[x] - A[y] * B[y];
// }
// 
// {
//   int x, y;
//   ll res = 0, tmp, ini;
//   rd(N,A(N),B(N));
//   ini = sum[i,0,N](A[i]*B[i]);
//   rep(k,N) rep(m,2){
//     x = y = k;
//     if(m) x--;
//     if(x < 0) continue;
// 
//     res >?= tmp = ini + calc(x, y);
//     for(;;){
//       x--; y++;
//       if(x < 0 || y >= N) break;
//       res >?= tmp += calc(x, y);
//     }
//   }
//   wt(res);
// }