#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
int N;
int Q;
int A[1000000];
int T;
int X;
int K;
int L;
int R;
char fg_rev[2000000];
char fg_swap[2000000];
long long sm[2000000];
void build(int n, int a, int b){
  int n1 = n * 2 + 1;
  int n2 = n * 2 + 2;
  int c = (a + b) / 2;
  int sz = b - a;
  if(sz==1){
    sm[n] = A[a];
    return;
  }
  build(n1, a, c);
  build(n2, c, b);
  sm[n] = sm[n1] + sm[n2];
}
void change(int n, int sz, int x, int v){
  int nx = 0;
  if(sz==1){
    sm[n] = v;
    return;
  }
  if(fg_rev[sz]){
    x = sz - 1 - x;
  }
  if(x >= sz / 2){
    nx = 1;
    x -= sz / 2;
  }
  if(fg_swap[sz/2]){
    nx ^= 1;
  }
  change(n*2+1+nx, sz/2, x, v);
  sm[n] = sm[2*n+1] + sm[2*n+2];
}
long long getsum(int n, int sz, int a, int b){
  int a1;
  int b1;
  int a2;
  int b2;
  long long res = 0;
  if(a==0 && b==sz){
    return sm[n];
  }
  if(fg_rev[sz]){
    {
      auto Lj4PdHRW = (sz-b);
      auto KL2GvlyY = ( sz-a);
      a = Lj4PdHRW;
      b = KL2GvlyY;
    }
  }
  a1 =min_L(a, sz/2);
  b1 =min_L(b, sz/2);
  a2 =max_L(a-sz/2, 0);
  b2 =max_L(b-sz/2, 0);
  if(fg_swap[sz/2]){
    swap(a1, a2);
    swap(b1, b2);
  }
  if(a1 < b1){
    res += getsum(2*n+1, sz/2, a1, b1);
  }
  if(a2 < b2){
    res += getsum(2*n+2, sz/2, a2, b2);
  }
  return res;
}
int main(){
  int t_ynMSdg;
  long long res;
  N = 1 << (rd_int());
  rd(Q);
  {
    int FmcKpFmN;
    for(FmcKpFmN=(0);FmcKpFmN<(N);FmcKpFmN++){
      rd(A[FmcKpFmN]);
    }
  }
  build(0, 0, N);
  for(t_ynMSdg=(0);t_ynMSdg<(Q);t_ynMSdg++){
    rd(T);
    if(T==1){
      rd(X);X += (-1);
      rd(K);
      change(0,N,X,K);
    }
    else if(T==2){
      rd(K);
      fg_rev[1<<K] ^= 1;
    }
    else if(T==3){
      rd(K);
      fg_swap[1<<K] ^= 1;
    }
    else if(T==4){
      rd(L);L += (-1);
      rd(R);R += (-1);
      res = getsum(0, N, L, R+1);
      wt_L(res);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// //working_memory=20m
// int N, Q, A[1d6];
// int T, X, K, L, R;
// 
// char fg_rev[2d6], fg_swap[2d6];
// ll sm[2d6];
// 
// void build(int n, int a, int b){
//   int n1 = n * 2 + 1;
//   int n2 = n * 2 + 2;
//   int c = (a + b) / 2;
//   int sz = b - a;
// 
//   if(sz==1) sm[n] = A[a], return;
//   build(n1, a, c);
//   build(n2, c, b);
//   sm[n] = sm[n1] + sm[n2];
// }
// 
// void change(int n, int sz, int x, int v){
//   int nx = 0;
//   if(sz==1) sm[n] = v, return;
//   if(fg_rev[sz]) x = sz - 1 - x;
//   if(x >= sz / 2) nx = 1, x -= sz / 2;
//   if(fg_swap[sz/2]) nx ^= 1;
//   change(n*2+1+nx, sz/2, x, v);
//   sm[n] = sm[2*n+1] + sm[2*n+2];
// }
// 
// ll getsum(int n, int sz, int a, int b){
//   int a1, b1, a2, b2;
//   ll res = 0;
// 
//   if(a==0 && b==sz) return sm[n];
// 
//   if(fg_rev[sz]) (a, b) = (sz-b, sz-a);
// 
//   a1 = min(a, sz/2);
//   b1 = min(b, sz/2);
//   a2 = max(a-sz/2, 0);
//   b2 = max(b-sz/2, 0);
// 
//   if(fg_swap[sz/2]) swap(a1, a2), swap(b1, b2);
//   if(a1 < b1) res += getsum(2*n+1, sz/2, a1, b1);
//   if(a2 < b2) res += getsum(2*n+2, sz/2, a2, b2);
// 
//   return res;
// }
// 
// 
// {
//   ll res;
//   N = 1 << (rd_int());
// //  N = 1<<18;
//   rd(Q,A(N));
// //  Q = 1d5;
// //  rep(i,N) A[i] = rand()%10000000;
//   build(0, 0, N);
//   rep(Q){
//     rd(T);
// //    T = rand()%4 + 1;
// //    printf("T %d\n", T);
//     if(T==1){
//       rd(X--,K);
// //      X = rand()%N;
// //      K = rand()%1d9;
//       change(0,N,X,K);
//     }else if(T==2){
//       rd(K);
// //      K = rand()%18;
//       fg_rev[1<<K] ^= 1;
//     }else if(T==3){
//       rd(K);
// //      K = rand()%18;
//       fg_swap[1<<K] ^= 1;
//     }else if(T==4){
//       rd(L--, R--);
// //      L = rand()%N;
// //      R = rand()%N;
// //      sortE(L, R);
//       res = getsum(0, N, L, R+1);
//       wt(res);
//     }
//   }
// }