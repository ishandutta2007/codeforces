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
int Q;
int T;
long long A[30];
long long X;
long long K;
long long res;
long long tmp[30];
int main(){
  int e98WHCEY;
  long long i;
  long long j;
  long long can1;
  long long s;
  long long cur;
  long long nd;
  long long pre;
  rd(N);
  rd(Q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(e98WHCEY=(0);e98WHCEY<(Q);e98WHCEY++){
    rd(T);
    rd(X);
    rd(K);
    if(T==1){
      A[X] = K;
      continue;
    }
    s = 0;
    for(i=(0);i<(N);i++){
      tmp[i] = A[i];
    }
    for(i=(0);i<(N);i++){
      s += tmp[i] * (1<<i);
    }
    if(s < K){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(X+1);i++){
      K -= tmp[i];
    }
    chmax(K, 0);
    res = 4611686016279904256LL;
    cur = 0;
    can1 = 0;
    for(i=(1);i<(X+1);i++){
      can1 += tmp[i] * ((1<<i) - 1);
    }
    if(can1 >= K){
      chmin(res, cur + K);
    }
    while(K > 0){
      for(i=(X+1);i<(N);i++){
        j =min_L(K / (1<<(i-X)), tmp[i]);
        tmp[i] -= j;
        K -= j * (1 << (i-X));
        cur += j * ((1 << (i-X)) - 1);
        can1 += j * (1 << (i-X)) * ((1 << X) - 1);
        if(can1 >= K){
          chmin(res, cur + K);
        }
        if(tmp[i]){
          if(i==X+1){
            K = 0;
            cur++;
            chmin(res, cur + K);
            break;
          }
          cur++;
          tmp[i]--;
          tmp[i-1]+=2;
          break;
        }
      }
      if(i==N){
        break;
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20201121-1

// --- original code ---
// //no-unlocked
// int N, Q, T; ll A[30], X, K;
// ll res, tmp[30];
// {
//   ll i, j, can1, s, cur, nd, pre;
// 
//   rd(N,Q,A(N));
//   rep(Q){
//     rd(T,X,K);
//     if(T==1) A[X] = K, continue;
// 
//     s = 0;
//     rep(i,N) tmp[i] = A[i];
//     rep(i,N) s += tmp[i] * (1<<i);
//     if(s < K) wt(-1), continue;
// 
//     rep(i,X+1) K -= tmp[i];
//     K >?= 0;
// 
//     res = ll_inf;
//     cur = 0;
//     can1 = 0;
//     rep(i,1,X+1) can1 += tmp[i] * ((1<<i) - 1);
//     if(can1 >= K) res <?= cur + K;
// 
//     while(K > 0){
//       rep(i,X+1,N){
//         j = min(K / (1<<(i-X)), tmp[i]);
//         tmp[i] -= j;
//         K -= j * (1 << (i-X));
//         cur += j * ((1 << (i-X)) - 1);
//         can1 += j * (1 << (i-X)) * ((1 << X) - 1);
//         if(can1 >= K) res <?= cur + K;
// 
//         if(tmp[i]){
//           if(i==X+1){
//             K = 0;
//             cur++;
//             res <?= cur + K;
//             break;
//           }
//           cur++;
//           tmp[i]--;
//           tmp[i-1]+=2;
//           break;
//         }
//       }
//       if(i==N) break;
//     }
// 
//     wt(res);
//   }
// }