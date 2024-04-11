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
template<class T> void Unique_L(int &N, T A[], int sorted=0){
  int i;
  int k;
  if(!sorted){
    sort(A, A+N);
  }
  k = 0;
  for(i=(0);i<(N);i++){
    if(k==0 || A[k-1]!=A[i]){
      A[k++] = A[i];
    }
  }
  N = k;
}
struct dimcomp2{
  int B;
  dimcomp2(){
  }
  dimcomp2(int b){
    B = b;
  }
  dimcomp2(int a, int b){
    B = b;
  }
  inline void set(int b){
    B = b;
  }
  inline void set(int a, int b){
    B = b;
  }
  inline int mask(int a, int b){
    return a * B + b;
  }
  inline int operator()(int a, int b){
    return a * B + b;
  }
  inline void para(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
  inline void operator()(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
}
;
int N;
int M;
int G;
int R;
int D[10000];
int dis[10000][1000];
int q[20000000+10];
int qs;
int qe;
int main(){
  int i;
  int j;
  int ni;
  int nj;
  long long res = 4611686016279904256LL;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(D[Lj4PdHRW]);
    }
  }
  rd(G);
  rd(R);
  Unique_L(M,D);
  dimcomp2 dm(M,G);
  qs = qe = 10000000+5;
  for(i=(0);i<(M);i++){
    for(j=(0);j<(G);j++){
      dis[i][j] = -1;
    }
  }
  dis[0][0] = 0;
  q[qe++] = 0;
  while(qs < qe){
    int loop;
    dm(q[qs++], i, j);
    if(i==M-1){
      if(j==0){
        chmin(res, (long long) (dis[i][j]-1) * (G + R) + G);
      }
      else{
        chmin(res, (long long) dis[i][j] * (G + R) + j);
      }
      continue;
    }
    for(loop=(0);loop<(2);loop++){
      if(loop==0){
        ni = i + 1;
      }
      if(loop==1){
        ni = i - 1;
      }
      if(ni < 0 || ni >= M){
        continue;
      }
      nj = j + D[max_L(i, ni)] - D[min_L(i, ni)];
      if(nj == G && dis[ni][0] == -1){
        dis[ni][0] = dis[i][j] + 1;
        q[qe++] = dm(ni,0);
      }
      if(nj < G && dis[ni][nj] == -1){
        dis[ni][nj] = dis[i][j];
        q[--qs] = dm(ni,nj);
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
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// //working_memory=10m
// int N, M, G, R;
// int D[1d4];
// 
// int dis[1d4][1d3];
// int q[2d7+10], qs, qe;
// 
// {
//   int i, j, ni, nj;
//   ll res = ll_inf;
// 
//   rd(N,M,D(M),G,R);
//   Unique(M,D);
//   dimcomp2 dm(M,G);
// 
//   qs = qe = 1d7+5;
//   rep(i,M) rep(j,G) dis[i][j] = -1;
//   dis[0][0] = 0;
//   
//   q[qe++] = 0;
//   while(qs < qe){
//     dm(q[qs++], i, j);
//     if(i==M-1){
//       if(j==0) res <?= (ll) (dis[i][j]-1) * (G + R) + G;
//       else     res <?= (ll) dis[i][j] * (G + R) + j;
//       continue;
//     }
// 
//     rep(loop,2){
//       if(loop==0) ni = i + 1;
//       if(loop==1) ni = i - 1;
//       if(ni < 0 || ni >= M) continue;
//       nj = j + D[max(i,ni)] - D[min(i,ni)];
//       if(nj == G && dis[ni][0] == -1){
//         dis[ni][0] = dis[i][j] + 1;
//         q[qe++] = dm(ni,0);
//       }
//       if(nj < G && dis[ni][nj] == -1){
//         dis[ni][nj] = dis[i][j];
//         q[--qs] = dm(ni,nj);
//       }
//     }
//   }
// 
//   wt(if[res==ll_inf,-1,res]);
// }