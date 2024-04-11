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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
int A[200000];
int up[400000];
int dw[400000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int x;
    int y;
    int res = 1073709056;
    rd(N);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    for(i=(0);i<(2*K);i++){
      up[i] = dw[i] = 0;
    }
    int t_ynMSdg = N/2;
    for(i=(0);i<(t_ynMSdg);i++){
      x =min_L(A[i], A[N-1-i]);
      y =max_L(A[i], A[N-1-i]);
      if(x+y-1 >= 0){
        dw[x+y-1]++;
      }
      if(x+y+1 < 2*K){
        up[x+y+1]++;
      }
      if(x-1 >= 0){
        dw[x-1]++;
      }
      if(K+y < 2*K){
        up[K+y]++;
      }
    }
    for(i=(1);i<(2*K);i++){
      up[i] += up[i-1];
    }
    for(i=(2*K)-1;i>=(1);i--){
      dw[i-1] += dw[i];
    }
    for(i=(0);i<(2*K-1);i++){
      chmin(res, up[i] + dw[i]);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, K, A[2d5];
// int up[4d5], dw[4d5];
// {
//   REP(rd_int()){
//     int x, y, res = int_inf;
//     rd(N,K,(A--)(N));
//     rep(i,2K) up[i] = dw[i] = 0;
// 
//     REP(i,N/2){
//       x = min(A[i], A[N-1-i]);
//       y = max(A[i], A[N-1-i]);
//       if(x+y-1 >= 0) dw[x+y-1]++;
//       if(x+y+1 < 2K) up[x+y+1]++;
//       if(x-1 >= 0) dw[x-1]++;
//       if(K+y < 2K) up[K+y]++;
// 
//     }
// 
//     rep(i,1,2K) up[i] += up[i-1];
//     rrep(i,1,2K) dw[i-1] += dw[i];
//     rep(i,2K-1) res <?= up[i] + dw[i];
//     wt(res);
//   }
// }