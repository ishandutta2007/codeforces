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
int K;
long long L1;
long long R1;
long long L2;
long long R2;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    long long zero = 0;
    long long one = 0;
    long long ok = 0;
    long long res = 4611686016279904256LL;
    long long tmp;
    long long av;
    rd(N);
    rd(K);
    rd(L1);
    rd(R1);
    rd(L2);
    rd(R2);
    if(L1 > L2){
      swap(L1, L2);
      swap(R1, R2);
    }
    if(L2 > R1){
      zero = L2 - R1;
      one = R2 - L1;
    }
    else{
      ok =min_L(R1, R2)-max_L(L1, L2);
      one =max_L(R1, R2)-min_L(L1, L2)- ok;
    }
    if(K <= N * ok){
      wt_L(0);
      wt_L('\n');
      continue;
    }
    K -= N * ok;
    for(i=(1);i<(N+1);i++){
      av =min_L(one * i, K);
      chmin(res, zero * i + av + (K-av) * 2);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, K;
// ll L1, R1, L2, R2;
// {
//   REP(rd_int()){
//     ll zero = 0, one = 0, ok = 0;
//     ll res = ll_inf, tmp, av;
//     rd(N,K,L1,R1,L2,R2);
//     if(L1 > L2) swap(L1, L2), swap(R1, R2);
//     if(L2 > R1){
//       zero = L2 - R1;
//       one = R2 - L1;
//     } else {
//       ok = min(R1, R2) - max(L1, L2);
//       one = max(R1, R2) - min(L1, L2) - ok;
//     }
// 
//     if(K <= N * ok) wt(0), continue;
//     K -= N * ok;
//     rep(i,1,N+1){
//       av = min(one * i, K);
//       res <?= zero * i + av + (K-av) * 2;
//     }
//     wt(res);
//   }
// }