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
int M;
int L[100000];
long long sm[100000+1];
int res[100000];
int main(){
  int i;
  int now = 0;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(L[Lj4PdHRW]);
    }
  }
  sm[N-1] = 0;
  for(i=(N-1)-1;i>=(0);i--){
    sm[i] = sm[i+1] + L[i+1];
  }
  for(i=(0);i<(M);i++){
    res[i] = now;
    if(now + L[i] > N){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
    if(N-now > sm[i]){
      if(N - now - sm[i] > L[i]){
        wt_L(-1);
        wt_L('\n');
        return 0;
      }
      now += N - now - sm[i];
    }
    else{
      now++;
    }
  }
  {
    int xr20shxY;
    if(M==0){
      wt_L('\n');
    }
    else{
      for(xr20shxY=(0);xr20shxY<(M-1);xr20shxY++){
        wt_L(res[xr20shxY]+1);
        wt_L(' ');
      }
      wt_L(res[xr20shxY]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200325-1

// --- original code ---
// //no-unlocked
// int N, M, L[1d5];
// ll sm[1d5+1];
// int res[1d5];
// {
//   int now = 0;
//   rd(N,M,L(M));
//   sm[N-1] = 0;
//   rrep(i,N-1) sm[i] = sm[i+1] + L[i+1];
//   rep(i,M){
//     res[i] = now;
//     if(now + L[i] > N) wt(-1), return 0;
//     if(N-now > sm[i]){
//       if(N - now - sm[i] > L[i]) wt(-1), return 0;
//       now += N - now - sm[i];
//     } else {
//       now++;
//     }
//   }
//   wt(res(M)+1);
// }