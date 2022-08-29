#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
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
inline void wt_L(char a){
  putchar(a);
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
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
int K;
int A[1000][1000];
int R1;
int C1;
int R2;
int C2;
vector<int> p[40];
int q[2100000];
int qs;
int qe;
int dis[1000040];
int d[40][1000][1000];
int main(){
  int AlM5nNnR, c;
  int i;
  int j;
  int k;
  int s;
  int sx;
  int sy;
  int nx;
  int ny;
  int nxy;
  int dr;
  int res;
  int dx[4] = {-1,1,0,0};
  int dy[4] = {0,0,-1,1};
  rd(N);
  rd(M);
  rd(K);
  dimcomp2 dm(N,M);
  for(i=(0);i<(N);i++){
    for(j=(0);j<(M);j++){
      rd(A[i][j]);A[i][j] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    for(j=(0);j<(M);j++){
      p[A[i][j]].push_back(dm(i,j));
    }
  }
  for(c=(0);c<(K);c++){
    qs = qe = 1000000 + 10000;
    for(i=(0);i<(N*M+K);i++){
      dis[i] = 1073709056;
    }
    dis[N*M+c] = 0;
    q[qe++] = N*M+c;
    while(qs < qe){
      k = q[qs++];
      if(k >= N*M){
        s = k - N*M;
        for(i=(0);i<(p[s].size());i++){
          j = p[s][i];
          if(dis[j] > dis[k]){
            dis[j] = dis[k];
            q[--qs] = j;
          }
        }
        continue;
      }
      dm(k,sx,sy);
      for(dr=(0);dr<(5);dr++){
        if(dr < 4){
          nx = sx + dx[dr];
          ny = sy + dy[dr];
          if(nx < 0 || nx >= N || ny < 0 || ny >= M){
            continue;
          }
          nxy = dm(nx, ny);
        }
        else{
          nxy = A[sx][sy] + N * M;
        }
        if(dis[nxy] > dis[k] + 1){
          dis[nxy] = dis[k] + 1;
          q[qe++] = nxy;
        }
      }
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(M);j++){
        d[c][i][j] = dis[dm(i,j)];
      }
    }
  }
  int XJIcIBrW = rd_int();
  for(AlM5nNnR=(0);AlM5nNnR<(XJIcIBrW);AlM5nNnR++){
    rd(R1);R1 += (-1);
    rd(C1);C1 += (-1);
    rd(R2);R2 += (-1);
    rd(C2);C2 += (-1);
    res = abs(R1-R2) + abs(C1-C2);
    for(i=(0);i<(K);i++){
      chmin(res, d[i][R1][C1] + d[i][R2][C2] + 1);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// //working_memory=1m
// int N, M, K, A[1000][1000];
// int R1, C1, R2, C2;
// 
// vector<int> p[40];
// 
// int q[2100000], qs, qe;
// int dis[1000040];
// int d[40][1000][1000];
// 
// {
//   int i, j, k, s, sx, sy, nx, ny, nxy, dr, res;
//   int dx[4] = {-1,1,0,0};
//   int dy[4] = {0,0,-1,1};
// 
//   rd(N,M,K);
//   dimcomp2 dm(N,M);
// 
//   rep(i,N) rep(j,M) rd(A[i][j]--);
// 
//   rep(i,N) rep(j,M) p[A[i][j]].push_back(dm(i,j));
// 
//   rep(c,K){
//     qs = qe = 1d6 + 1d4;
//     rep(i,N*M+K) dis[i] = int_inf;
//     dis[N*M+c] = 0;
//     q[qe++] = N*M+c;
//     while(qs < qe){
//       k = q[qs++];
//       if(k >= N*M){
//         s = k - N*M;
//         rep(i,p[s].size()){
//           j = p[s][i];
//           if(dis[j] > dis[k]){
//             dis[j] = dis[k];
//             q[--qs] = j;
//           }
//         }
//         continue;
//       }
//       dm(k,sx,sy);
//       rep(dr,5){
//         if(dr < 4){
//           nx = sx + dx[dr];
//           ny = sy + dy[dr];
//           if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
//           nxy = dm(nx, ny);
//         } else {
//           nxy = A[sx][sy] + N * M;
//         }
//         if(dis[nxy] > dis[k] + 1){
//           dis[nxy] = dis[k] + 1;
//           q[qe++] = nxy;
//         }
//       }
//     }
//     rep(i,N) rep(j,M) d[c][i][j] = dis[dm(i,j)];
//   }
// 
//   REP(rd_int()){
//     rd(R1--,C1--,R2--,C2--);
//     res = abs(R1-R2) + abs(C1-C2);
//     rep(i,K) res <?= d[i][R1][C1] + d[i][R2][C2] + 1;
//     wt(res);
//   }
// }