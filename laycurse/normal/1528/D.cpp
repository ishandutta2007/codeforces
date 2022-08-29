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
int M;
long long dist[600][600];
long long d[600];
long long nd[600];
long long tmp;
int vis[600];
long long res[600][600];
int main(){
  int cTE1_r3A, s;
  int i;
  int j;
  int k;
  int m;
  rd(N);
  rd(M);
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N);j++){
      dist[i][j] = 4611686016279904256LL;
    }
  }
  for(cTE1_r3A=(0);cTE1_r3A<(M);cTE1_r3A++){
    rd(i);
    rd(j);
    rd(k);
    dist[i][j] = k;
  }
  for(s=(0);s<(N);s++){
    for(i=(0);i<(N);i++){
      vis[i] = 0;
    }
    for(i=(0);i<(N);i++){
      d[i] = 4611686016279904256LL;
    }
    d[s] = 0;
    for(;;){
      m = -1;
      tmp = 4611686016279904256LL;
      for(i=(0);i<(N);i++){
        if(!vis[i] && tmp > d[i]){
          tmp = d[i];
          m = i;
        }
      }
      if(m == -1){
        break;
      }
      vis[m] = 1;
      for(i=(0);i<(N);i++){
        nd[i] = 4611686016279904256LL;
      }
      for(i=(0);i<(N);i++){
        chmin(nd[(i+d[m])%N], dist[m][i]);
      }
      for(i=(1);i<(2*N+5);i++){
        chmin(nd[(i+1)%N], nd[i%N] + 1);
      }
      for(i=(0);i<(N);i++){
        chmin(d[i], d[m] + nd[i]);
      }
    }
    for(i=(0);i<(N);i++){
      res[s][i] = d[i];
    }
  }
  {
    int GgkpftXM;
    int gEg5UqEA;
    for(GgkpftXM=(0);GgkpftXM<(N);GgkpftXM++){
      if(N==0){
        wt_L('\n');
      }
      else{
        for(gEg5UqEA=(0);gEg5UqEA<(N-1);gEg5UqEA++){
          wt_L(res[GgkpftXM][gEg5UqEA]);
          wt_L(' ');
        }
        wt_L(res[GgkpftXM][gEg5UqEA]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210524-1

// --- original code ---
// //no-unlocked
// int N, M;
// ll dist[600][600], d[600], nd[600], tmp;
// int vis[600];
// ll res[600][600];
// {
//   int i, j, k, m;
//   rd(N,M);
//   rep(i,N) rep(j,N) dist[i][j] = ll_inf;
//   rep(M){
//     rd(i,j,k);
//     dist[i][j] = k;
//   }
// 
//   rep(s,N){
//     rep(i,N) vis[i] = 0;
//     rep(i,N) d[i] = ll_inf;
//     d[s] = 0;
// 
//     for(;;){
//       m = -1;
//       tmp = ll_inf;
//       rep(i,N) if(!vis[i] && tmp > d[i]) tmp = d[i], m = i;
//       if(m == -1) break;
// 
//       vis[m] = 1;
//       rep(i,N) nd[i] = ll_inf;
//       rep(i,N) nd[(i+d[m])%N] <?= dist[m][i];
//       rep(i,1,2*N+5) nd[(i+1)%N] <?= nd[i%N] + 1;
//       rep(i,N) d[i] <?= d[m] + nd[i];
//     }
// 
//     rep(i,N) res[s][i] = d[i];
//   }
//   wt(res(N,N));
// }