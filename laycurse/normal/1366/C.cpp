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
int N;
int M;
int A[30][30];
int cnt[2][60];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int res = 0;
    int len;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      int RZTsC2BF;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        for(RZTsC2BF=(0);RZTsC2BF<(M);RZTsC2BF++){
          rd(A[cTE1_r3A][RZTsC2BF]);
        }
      }
    }
    len = N + M - 1;
    for(i=(0);i<(len/2);i++){
      cnt[0][i] = cnt[1][i] = 0;
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(M);j++){
        cnt[A[i][j]][min_L(i+j, N+M-2-i-j)]++;
      }
    }
    for(i=(0);i<(len/2);i++){
      res +=min_L(cnt[0][i], cnt[1][i]);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, A[30][30];
// int cnt[2][60];
// {
//   REP(rd_int()){
//     int res = 0, len;
//     rd(N,M,A(N,M));
//     len = N + M - 1;
//     rep(i,len/2) cnt[0][i] = cnt[1][i] = 0;
//     rep(i,N) rep(j,M) cnt[A[i][j]][min(i+j, N+M-2-i-j)]++;
//     rep(i,len/2) res += min(cnt[0][i], cnt[1][i]);
//     wt(res);
//   }
// }