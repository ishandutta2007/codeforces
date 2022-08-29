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
long long X;
long long D[400000];
int main(){
  int i;
  int j;
  long long res = 0;
  long long tmp = 0;
  long long rem;
  rd(N);
  rd(X);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(D[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    D[i+N] = D[i];
  }
  N *= 2;
  i = N-1;
  rem = X;
  for(j=(N)-1;j>=(0);j--){
    while(i>=0 && rem >= D[i]){
      tmp += D[i] * (D[i]+1) / 2;
      rem -= D[i];
      i--;
    }
    chmax(res, tmp);
    if(i >= 0){
      chmax(res, tmp + (2*D[i]-rem+1) * rem / 2);
    }
    rem += D[j];
    tmp -= D[j] * (D[j]+1) / 2;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N; ll X, D[4d5];
// {
//   int i, j;
//   ll res = 0, tmp = 0, rem;
//   rd(N,X,D(N));
//   rep(i,N) D[i+N] = D[i];
//   N *= 2;
// 
//   i = N-1;
//   rem = X;
//   rrep(j,N){
//     while(i>=0 && rem >= D[i]){
//       tmp += D[i] * (D[i]+1) / 2;
//       rem -= D[i];
//       i--;
//     }
//     res >?= tmp;
//     if(i >= 0) res >?= tmp + (2*D[i]-rem+1) * rem / 2;
// 
//     rem += D[j];
//     tmp -= D[j] * (D[j]+1) / 2;
//   }
//   wt(res);
// }