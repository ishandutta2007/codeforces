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
int N = 3;
int mp[501][501];
int vis[501][501];
int get_cost(int rook){
  int i;
  int j;
  int di;
  int dj;
  int ti;
  int tj;
  int ni;
  int nj;
  int mn;
  int res = 0;
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N);j++){
      vis[i][j] = 0;
    }
  }
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N);j++){
      if(mp[i][j] == 0){
        goto RZTsC2BF;
      }
    }
  }
  RZTsC2BF:;
  vis[i][j] = 1;
  for(;;){
    mn = 1073709056;
    for(di=(-1);di<(2);di++){
      for(dj=(-1);dj<(2);dj++){
        if(di==dj && dj==0){
          continue;
        }
        if(rook && di && dj){
          continue;
        }
        {
          auto hCmBdyQB = (i);
          auto V9aVTaxx = ( j);
          ti = hCmBdyQB;
          tj = V9aVTaxx;
        }
        for(;;){
          {
            auto jZyWAPpY = (di);
            auto jbtyPBGc = ( dj);
            ti += jZyWAPpY;
            tj += jbtyPBGc;
          }
          if(ti < 0 || ti >= N || tj < 0 || tj >= N){
            break;
          }
          if(vis[ti][tj]==0 && mp[ti][tj] < mn){
            {
              auto ZIeRIny5 = (ti);
              auto iMWUTgY_ = ( tj);
              auto AlM5nNnR = ( mp[ti][tj]);
              ni = ZIeRIny5;
              nj = iMWUTgY_;
              mn = AlM5nNnR;
            }
          }
        }
      }
    }
    if(mn == 1073709056){
      res++;
      for(ti=(0);ti<(N);ti++){
        for(tj=(0);tj<(N);tj++){
          if(vis[ti][tj]==0 && mp[ti][tj] < mn){
            {
              auto GgkpftXM = (ti);
              auto gEg5UqEA = ( tj);
              auto qSsg05KM = ( mp[ti][tj]);
              ni = GgkpftXM;
              nj = gEg5UqEA;
              mn = qSsg05KM;
            }
          }
        }
      }
    }
    if(mn == 1073709056){
      break;
    }
    {
      auto Hjfu7Vx7 = (ni);
      auto zT28qSmp = ( nj);
      i = Hjfu7Vx7;
      j = zT28qSmp;
    }
    vis[i][j] = 1;
  }
  return res;
}
int main(){
  int i;
  int j;
  int k = 1;
  rd(N);
  if(N <= 2){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  for(i=(3);i<(N);i++){
    if(i%2){
      for(j=(0);j<(i+1);j++){
        mp[i][j] = k++;
      }
      for(j=(i)-1;j>=(0);j--){
        mp[j][i] = k++;
      }
    }
    else{
      for(j=(0);j<(i+1);j++){
        mp[j][i] = k++;
      }
      for(j=(i)-1;j>=(0);j--){
        mp[i][j] = k++;
      }
    }
  }
  mp[0][0] = k++;
  mp[0][1] = k++;
  mp[1][1] = k++;
  mp[2][1] = k++;
  mp[0][2] = k++;
  mp[2][0] = k++;
  mp[1][2] = k++;
  mp[2][2] = k++;
  mp[1][0] = k++;
  for(i=(0);i<(N);i++){
    {
      int HOAyP4rA;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(HOAyP4rA=(0);HOAyP4rA<(N-1);HOAyP4rA++){
          wt_L(mp[i][HOAyP4rA]);
          wt_L(' ');
        }
        wt_L(mp[i][HOAyP4rA]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200408-1

// --- original code ---
// //no-unlocked
// //no-fwrite
// int N = 3;
// int mp[501][501];
// int vis[501][501];
// 
// int get_cost(int rook){
//   int i, j, di, dj, ti, tj, ni, nj, mn, res = 0;
//   rep(i,N) rep(j,N) vis[i][j] = 0;
//   rep(i,N) rep(j,N) if(mp[i][j] == 0) break_break;
//   vis[i][j] = 1;
//   for(;;){
//     mn = int_inf;
//     rep(di,-1,2) rep(dj,-1,2){
//       if(di==dj==0) continue;
//       if(rook && di && dj) continue;
//       (ti, tj) = (i, j);
//       for(;;){
//         (ti, tj) += (di, dj);
//         if(ti < 0 || ti >= N || tj < 0 || tj >= N) break;
//         if(vis[ti][tj]==0 && mp[ti][tj] < mn){
//           (ni, nj, mn) = (ti, tj, mp[ti][tj]);
//         }
//       }
//     }
//     if(mn == int_inf){
//       res++;
//       rep(ti,N) rep(tj,N) if(vis[ti][tj]==0 && mp[ti][tj] < mn){
//         (ni, nj, mn) = (ti, tj, mp[ti][tj]);
//       }
//     }
//     if(mn == int_inf) break;
//     (i, j) = (ni, nj);
//     vis[i][j] = 1;
//   }
//   return res;
// }
// 
// {
//   int i, j, k = 1;
//   rd(N);
//   if(N <= 2) wt(-1), return 0;
// 
//   rep(i,3,N){
//     if(i%2){
//       rep(j,i+1) mp[i][j] = k++;
//       rrep(j,i) mp[j][i] = k++;
//     } else {
//       rep(j,i+1) mp[j][i] = k++;
//       rrep(j,i) mp[i][j] = k++;
//     }
//   }
// 
//   mp[0][0] = k++;
//   mp[0][1] = k++;
//   mp[1][1] = k++;
//   mp[2][1] = k++;
//   mp[0][2] = k++;
//   mp[2][0] = k++;
//   mp[1][2] = k++;
//   mp[2][2] = k++;
//   mp[1][0] = k++;
// 
//   rep(i,N) wt(mp[i](N));
// 
// /*  int i, j, ind[9];
//   rep(i,N*N) ind[i] = i;
//   do{
//     rep(i,N) rep(j,N) mp[i][j] = ind[i*N+j];
//     if(get_cost(1) < get_cost(0)){
//       wt("---");
//       rep(i,N) wt(mp[i](N));
//     }
//   } while(next_permutation(ind,ind+N*N));
// */
// 
// // 0 1 4
// // 8 2 6
// // 5 3 7
// }