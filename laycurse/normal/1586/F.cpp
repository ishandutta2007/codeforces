#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
template<class T, class S, class U> inline void DigitF_L(T n, int sz, S res[], U b){
  int i;
  for(i=(0);i<(sz);i++){
    res[i] = n % b;
    n /= b;
  }
}
int main(){
  int i, k;
  int N;
  rd(N);
  int K;
  rd(K);
  int m[N][N];
  int d[N][11];
  int ress = 0;
  int res[1000000];
  int mx = 0;
  for(i=(0);i<(N);i++){
    DigitF_L(i,11,d[i],K);
  }
  for(k=(0);k<(11);k++){
    if(d[0][k] != d[N-1][k]){
      mx = k;
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i+1);j<(N);j++){
      for(k=(mx+1)-1;k>=(0);k--){
        if(d[i][k] != d[j][k]){
          res[ress++] = k;
          break;
        }
      }
    }
  }
  wt_L(mx+1);
  wt_L('\n');
  {
    int KrdatlYV;
    if(ress==0){
      wt_L('\n');
    }
    else{
      for(KrdatlYV=(0);KrdatlYV<(ress-1);KrdatlYV++){
        wt_L(res[KrdatlYV]+1);
        wt_L(' ');
      }
      wt_L(res[KrdatlYV]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int @N, @K;
// int m[N][N], d[N][11];
// int ress = 0, res[1d6], mx = 0;
// rep(i,N) DigitF(i,11,d[i],K);
// rep(k,11) if(d[0][k] != d[N-1][k]) mx = k;
// rep(i,N) rep(j,i+1,N) rrep(k,mx+1) if(d[i][k] != d[j][k]) res[ress++] = k, break;
// wt(mx+1);
// wt(res(ress)+1);