#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int main(){
  long long A;
  long long B;
  long long C;
  long long D;
  long long res = 0;
  long long i;
  long long t1;
  long long t2;
  rd(A);
  rd(B);
  rd(C);
  rd(D);
  for(i=(A+B);i<(B+C+1);i++){
    t1 =min_L(i-A-B, B+C-i)+ 1;
    chmin(t1, B - A + 1);
    chmin(t1, C - B + 1);
    t2 =min_L(i, D+1)- C;
    if(t2 > 0){
      res += t1 * t2;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// {
//   ll A, B, C, D, res = 0;
//   ll i, t1, t2;
//   rd(A,B,C,D);
//   rep(i,A+B,B+C+1){
//     t1 = min(i-A-B, B+C-i) + 1;
//     t1 <?= B - A + 1;
//     t1 <?= C - B + 1;
//     t2 = min(i, D+1) - C;
//     if(t2 > 0) res += t1 * t2;
//   }
//   wt(res);
// }