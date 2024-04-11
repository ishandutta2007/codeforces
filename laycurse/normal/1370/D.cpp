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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int K;
int A[200000];
int main(){
  int res;
  int len;
  int ok;
  int t;
  int c;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  int e98WHCEY;
  int cTE1_r3A;
  int RZTsC2BF;
  e98WHCEY = 1;
  cTE1_r3A = 1000000000;
  while(e98WHCEY < cTE1_r3A){
    if((e98WHCEY + cTE1_r3A)%2==0){
      RZTsC2BF = (e98WHCEY + cTE1_r3A) / 2;
    }
    else{
      RZTsC2BF = (e98WHCEY + cTE1_r3A - 1) / 2;
    }
    ok = 0;
    for(t=(0);t<(2);t++){
      int i;
      c = t;
      len = 0;
      for(i=(0);i<(N);i++){
        if(c==1){
          c^=1;
          len++;
          continue;
        }
        if(A[i] <= RZTsC2BF){
          c^=1;
          len++;
          continue;
        }
      }
      chmax(ok, len);
    }
    if(ok >= K){
      cTE1_r3A = RZTsC2BF;
    }
    else{
      e98WHCEY = RZTsC2BF + 1;
    }
  }
  res =cTE1_r3A;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, K;
// int A[2d5];
// {
//   int res, len, ok, t, c;
//   rd(N,K,A(N));
//   res = bsearch_min[int,x,1,1d9][
//     ok = 0;
//     rep(t,2){
//       c = t;
//       len = 0;
//       rep(i,N){
//         if(c==1) c^=1, len++, continue;
//         if(A[i] <= x) c^=1, len++, continue;
//       }
//       ok >?= len;
//     }
//   ](ok >= K);
//   wt(res);
// }