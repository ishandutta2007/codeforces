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
template<class T> inline int sod_L(T n){
  int res = 0;
  while(n){
    res += n%10;
    n /= 10;
  }
  return res;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
long long mn[200][200];
int main(){
  int d, hCmBdyQB, i;
  long long v;
  for(i=(0);i<(200);i++){
    int j;
    for(j=(0);j<(200);j++){
      mn[i][j] = 4611686016279904256LL;
    }
  }
  for(i=(0);i<(1000);i++){
    chmin(mn[sod_L(i)][sod_L(i+1)], i);
  }
  for(d=(0);d<(17);d++){
    int f;
    for(f=(1);f<(10);f++){
      int mask;
      for(mask=(0);mask<(1<<d);mask++){
        v = f;
        for(i=(0);i<(d);i++){
          if(((mask) &(1<<(i)))){
            v = v * 10 +9;
          }
          else{
            v = v * 10 +8;
          }
        }
        chmin(mn[sod_L(v)][sod_L(v+1)], v);
      }
    }
  }
  int V9aVTaxx = rd_int();
  for(hCmBdyQB=(0);hCmBdyQB<(V9aVTaxx);hCmBdyQB++){
    int i;
    int x;
    int y;
    int t;
    long long res = 4611686016279904256LL;
    rd(N);
    rd(K);
    for(i=(0);i<(10);i++){
      int j;
      t = x = y = 0;
      for(j=(0);j<(K+1);j++){
        if(i+j >= 10){
          y++;
        }
        else{
          x++;
        }
        t += (i+j) % 10;
      }
      for(j=(0);j<(200);j++){
        int k;
        for(k=(0);k<(200);k++){
          if(t + x*j + y*k == N && mn[j][k] < 4611686016279904256LL){
            chmin(res, mn[j][k] * 10 + i);
          }
        }
      }
    }
    if(res==4611686016279904256LL){
      wt_L(-1);
      wt_L('\n');
    }
    else{
      wt_L(res);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, K;
// ll mn[200][200];
// {
//   ll v;
//   rep(i,200) rep(j,200) mn[i][j] = ll_inf;
//   rep(i,1000) mn[sod(i)][sod(i+1)] <?= i;
//   rep(d,17) rep(f,1,10) rep(mask,1<<d){
//     v = f;
//     rep(i,d) v = v * 10 + if[BIT_ith(mask,i), 9, 8];
//     mn[sod(v)][sod(v+1)] <?= v;
//   }
// 
//   REP(rd_int()){
//     int i, x, y, t;
//     ll res = ll_inf;
//     rd(N,K);
//     rep(i,10){
//       t = x = y = 0;
//       rep(j,K+1){
//         if[i+j >= 10, y++, x++];
//         t += (i+j) % 10;
//       }
//       rep(j,200) rep(k,200) if(t + x*j + y*k == N && mn[j][k] < ll_inf) res <?= mn[j][k] * 10 + i;
//     }
//     wt(if[res==ll_inf, -1, res]);
//   }
// }