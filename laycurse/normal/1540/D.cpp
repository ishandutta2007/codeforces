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
template<class T, class S> inline T RoundUp(T a, S b){
  T m;
  if(b < 0){
    b = -b;
  }
  if(b <= 1){
    return a;
  }
  m = a % b;
  if(m == 0){
    return a;
  }
  if(m < 0){
    m += b;
  }
  return ((a + b - m) / b) * b;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int B[100000];
int Q;
int T;
int IND;
int X;
int memo[200][100000];
int ctm[200][100000];
int qtm[200];
int main(){
  int i, q;
  int res;
  int tmp;
  int t = 0;
  int up;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(B[Lj4PdHRW]);
    }
  }
  rd(Q);
  for(i=(0);i<(N);i++){
    B[i] = i - B[i];
  }
  for(i=(0);i<(200);i++){
    qtm[i] = -1;
  }
  for(i=(0);i<(200);i++){
    int j;
    for(j=(0);j<(N);j++){
      ctm[i][j] = -2;
    }
  }
  for(q=(0);q<(Q);q++){
    rd(T);
    rd(IND);IND += (-1);
    if(T==1){
      rd(X);
      B[IND] = IND - X;
      qtm[IND/500] = q;
    }
    else{
      up = RoundUp(IND+1, 500);
      chmin(up, N);
      res = B[IND];
      for(i=(IND+1);i<(up);i++){
        if(res >= B[i]){
          res++;
        }
      }
      IND = up;
      while(IND < N){
        up = IND + 500;
        chmin(up, N);
        if(ctm[IND/500][res] < qtm[IND/500]){
          ctm[IND/500][res] = q;
          tmp = res;
          for(i=(IND);i<(up);i++){
            if(res >= B[i]){
              res++;
            }
          }
          memo[IND/500][tmp] = res;
        }
        else{
          res = memo[IND/500][res];
        }
        IND = up;
      }
      wt_L(res+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210619-1 [beta]

// --- original code ---
// //no-unlocked
// int N, B[1d5], Q, T, IND, X;
// int memo[200][1d5], ctm[200][1d5], qtm[200];
// {
//   int res, tmp, t = 0, up;
//   rd(N,B(N),Q);
//   // N = Q = 1d5;
//   // rep(i,N) B[i] = rand()%(i+1);
//   rep(i,N) B[i] = i - B[i];
// 
//   rep(i,200) qtm[i] = -1;
//   rep(i,200) rep(j,N) ctm[i][j] = -2;
// 
//   rep(q,Q){
//     rd(T,IND--);
//     // T = 2;
//     // IND = rand()%100;
//     if(T==1){
//       rd(X);
//       B[IND] = IND - X;
//       qtm[IND/500] = q;
//     } else {
//       up = RoundUp(IND+1, 500);
//       up <?= N;
//       res = B[IND];
//       rep(i,IND+1,up) if(res >= B[i]) res++;
// 
//       IND = up;
//       while(IND < N){
//         up = IND + 500;
//         up <?= N;
//         if(ctm[IND/500][res] < qtm[IND/500]){
//           ctm[IND/500][res] = q;
//           tmp = res;
//           rep(i,IND,up) if(res >= B[i]) res++;
//           memo[IND/500][tmp] = res;
//         } else {
//           res = memo[IND/500][res];
//         }
//         IND = up;
//       }
// 
//       // t += res;
//       wt(res+1);
//     }
//   }
//   // wt(t);
// }