#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
int N;
int A;
int R;
int M;
int H[100000];
long long sm[100000+1];
long long solve(int m, long long z){
  long long dw;
  long long up;
  long long ch;
  dw = z * m - sm[m];
  up = sm[N] - sm[m] - z * (N - m);
  ch =min_L(dw, up);
  return ch * M + (dw - ch) * A + (up - ch) * R;
}
int main(){
  int i, m;
  wmem = memarr;
  long long x;
  long long y;
  long long z1;
  long long z2;
  long long t1;
  long long t2;
  long long res = 4611686016279904256LL;
  rd(N);
  rd(A);
  rd(R);
  rd(M);
  {
    int KL2GvlyY;
    for(KL2GvlyY=(0);KL2GvlyY<(N);KL2GvlyY++){
      rd(H[KL2GvlyY]);
    }
  }
  if(N==0){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  chmin(M, A + R);
  sortA_L(N,H);
  for(i=(0);i<(N);i++){
    sm[i+1] = sm[i] + H[i];
  }
  for(m=(1);m<(N);m++){
    x = H[m-1];
    y = H[m];
    while(y - x > 5){
      z1 = (x+x+y) / 3;
      z2 = (x+y+y) / 3;
      t1 = solve(m, z1);
      t2 = solve(m, z2);
      if(t1 < t2){
        y = z2;
      }
      else{
        x = z1;
      }
    }
    while(x <= y){
      chmin(res, solve(m, x++));
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A, R, M, H[1d5];
// ll sm[1d5+1];
// 
// ll solve(int m, ll z){
//   ll dw, up, ch;
//   dw = z * m - sm[m];
//   up = sm[N] - sm[m] - z * (N - m);
//   ch = min(dw, up);
//   return ch * M + (dw - ch) * A + (up - ch) * R;
// }
// 
// {
//   ll x, y, z1, z2, t1, t2;
//   ll res = ll_inf;
//   rd(N,A,R,M,H(N));
// 
//   if(N==0) wt(0), return 0;
// 
//   M <?= A + R;
//   sortA(N,H);
//   rep(i,N) sm[i+1] = sm[i] + H[i];
// 
//   rep(m,1,N){
//     x = H[m-1];
//     y = H[m];
//     while(y - x > 5){
//       z1 = (x+x+y) / 3;
//       z2 = (x+y+y) / 3;
//       t1 = solve(m, z1);
//       t2 = solve(m, z2);
//       if[t1 < t2, y = z2, x = z1];
//     }
//     while(x <= y) res <?= solve(m, x++);
//   }
// 
//   wt(res);
// }