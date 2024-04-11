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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int M;
int A[200000];
int B[200000];
int X;
int K;
int Y;
int ind[200000];
int main(){
  int i;
  int j;
  int k = 0;
  int m;
  int a;
  int b;
  int c;
  long long res = 0;
  long long tmp;
  rd(N);
  rd(M);
  rd(X);
  rd(K);
  rd(Y);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(M);e98WHCEY++){
      rd(B[e98WHCEY]);
    }
  }
  for(i=(0);i<(N);i++){
    if(k < M && B[k]==A[i]){
      ind[k++] = i;
    }
  }
  if(k < M){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  for(m=(0);m<(M+1);m++){
    if(m==0){
      a =0;
    }
    else{
      a =ind[m-1] + 1;
    }
    if(m==M){
      b =N-1;
    }
    else{
      b =ind[m] - 1;
    }
    if(a > b){
      continue;
    }
    tmp = 4611686016279904256LL;
    c = -1;
    if(a-1 >= 0){
      chmax(c, A[a-1]);
    }
    if(b+1 < N){
      chmax(c, A[b+1]);
    }
    for(i=(a);i<(b+1);i++){
      if(A[i] > c){
        break;
      }
    }
    if(i==b+1){
      chmin(tmp, (long long) (b-a+1) * Y);
    }
    for(i=1;;i++){
      if(i*K > b-a+1){
        break;
      }
      chmin(tmp, (long long) i * X + (long long) (b-a+1-i*K) * Y);
    }
    if(tmp==4611686016279904256LL){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
    res += tmp;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[2d5], X, K, Y;
// int ind[2d5];
// {
//   int i, j, k = 0, m, a, b, c;
//   ll res = 0, tmp;
//   rd(N,M,X,K,Y,A(N),B(M));
//   rep(i,N) if(k < M && B[k]==A[i]) ind[k++] = i;
//   if(k < M) wt(-1), return 0;
// 
//   rep(m,M+1){
//     a = if[m==0, 0, ind[m-1] + 1];
//     b = if[m==M, N-1, ind[m] - 1];
//     if(a > b) continue;
// 
//     tmp = ll_inf;
// 
//     c = -1;
//     if(a-1 >= 0) c >?= A[a-1];
//     if(b+1 < N) c >?= A[b+1];
//     rep(i,a,b+1) if(A[i] > c) break;
//     if(i==b+1) tmp <?= (ll) (b-a+1) * Y;
//     for(i=1;;i++){
//       if(i*K > b-a+1) break;
//       tmp <?= (ll) i * X + (ll) (b-a+1-i*K) * Y;
//     }
// 
//     if(tmp==ll_inf) wt(-1), return 0;
//     res += tmp;
//   }
//   wt(res);
// }