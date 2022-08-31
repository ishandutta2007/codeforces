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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
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
int X[1000][1000];
int Y[1000][1000];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
const char *dd = "ULDRULDR";
char res[1000][1002];
int st[1000000];
int sts;
int main(){
  int i;
  int si;
  int sj;
  int ni;
  int nj;
  int d;
  rd(N);
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      rd(X[i][j]);X[i][j] += (-1);
      rd(Y[i][j]);Y[i][j] += (-1);
    }
  }
  dimcomp2 dm(N,N);
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      for(d=(0);d<(4);d++){
        ni = i + dx[d];
        nj = j + dy[d];
        if(ni < 0 || nj < 0 || ni >= N || nj >= N){
          continue;
        }
        if(res[i][j] || res[ni][nj]){
          continue;
        }
        if(X[i][j]==-2 && X[ni][nj]==-2){
          {
            auto KrdatlYV = (dd[d]);
            auto ao_dF3pO = ( dd[d+2]);
            res[i][j] = KrdatlYV;
            res[ni][nj] = ao_dF3pO;
          }
        }
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      if(X[i][j]==-2 && !res[i][j]){
        for(d=(0);d<(4);d++){
          ni = i + dx[d];
          nj = j + dy[d];
          if(ni < 0 || nj < 0 || ni >= N || nj >= N){
            continue;
          }
          if(X[ni][nj]==-2 && res[ni][nj]){
            res[i][j] = dd[d];
          }
        }
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      if(X[i][j]==i && Y[i][j] == j && !res[i][j]){
        res[i][j] = 'X';
        sts = 0;
        st[sts++] = dm(i,j);
        while(sts){
          dm(st[--sts], si, sj);
          for(d=(0);d<(4);d++){
            ni = si + dx[d];
            nj = sj + dy[d];
            if(ni < 0 || nj < 0 || ni >= N || nj >= N || res[ni][nj] || X[ni][nj] != i || Y[ni][nj] != j){
              continue;
            }
            res[ni][nj] = dd[d+2];
            st[sts++] = dm(ni,nj);
          }
        }
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      if(!res[i][j]){
        wt_L("INVALID");
        wt_L('\n');
        return 0;
      }
    }
  }
  wt_L("VALID");
  wt_L('\n');
  {
    int Hjfu7Vx7;
    for(Hjfu7Vx7=(0);Hjfu7Vx7<(N);Hjfu7Vx7++){
      wt_L(res[Hjfu7Vx7]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200303-1 [beta]

// --- original code ---
// //no-unlocked
// int N, X[1000][1000], Y[1000][1000];
// 
// int dx[4] = {-1,0,1,0};
// int dy[4] = {0,-1,0,1};
// const char *dd = "ULDRULDR";
// char res[1000][1002];
// 
// int st[1000000], sts;
// 
// {
//   int si, sj, ni, nj, d;
// 
//   rd(N);
//   rep(i,N) rep(j,N) rd(X[i][j]--, Y[i][j]--);
// 
//   dimcomp2 dm(N,N);
// 
//   rep(i,N) rep(j,N) rep(d,4){
//     ni = i + dx[d];
//     nj = j + dy[d];
//     if(ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
//     if(res[i][j] || res[ni][nj]) continue;
//     if(X[i][j]==-2 && X[ni][nj]==-2) (res[i][j], res[ni][nj]) = (dd[d], dd[d+2]);
//   }
// 
//   rep(i,N) rep(j,N) if(X[i][j]==-2 && !res[i][j]) rep(d,4){
//     ni = i + dx[d];
//     nj = j + dy[d];
//     if(ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
//     if(X[ni][nj]==-2 && res[ni][nj]) res[i][j] = dd[d];
//   }
// 
//   rep(i,N) rep(j,N) if(X[i][j]==i && Y[i][j] == j && !res[i][j]){
//     res[i][j] = 'X';
//     sts = 0;
//     st[sts++] = dm(i,j);
//     while(sts){
//       dm(st[--sts], si, sj);
//       rep(d,4){
//         ni = si + dx[d];
//         nj = sj + dy[d];
//         if(ni < 0 || nj < 0 || ni >= N || nj >= N || res[ni][nj] || X[ni][nj] != i || Y[ni][nj] != j) continue;
//         res[ni][nj] = dd[d+2];
//         st[sts++] = dm(ni,nj);
//       }
//     }
//   }
// 
//   rep(i,N) rep(j,N) if(!res[i][j]) wt("INVALID"), return 0;
// 
//   wt("VALID");
//   wtLn(res(N));
// }