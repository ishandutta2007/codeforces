#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
struct graph{
  int N;
  int*es;
  int**edge;
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
  int bipartite(int res[] = NULL, void *mem = wmem){
    int i;
    int j;
    int k;
    int*st;
    int sts;
    if(res==NULL){
      walloc1d(&res, N, &mem);
    }
    walloc1d(&st, N, &mem);
    for(i=(0);i<(N);i++){
      res[i] = -1;
    }
    for(i=(0);i<(N);i++){
      if(res[i]==-1){
        res[i] = 0;
        sts = 0;
        st[sts++] = i;
        while(sts){
          i = st[--sts];
          for(j=(0);j<(es[i]);j++){
            k = edge[i][j];
            if(res[k]==-1){
              res[k] = 1 - res[i];
              st[sts++] = k;
            }
            if(res[i] + res[k] != 1){
              return 0;
            }
          }
        }
      }
    }
    return 1;
  }
}
;
int N;
int M;
int X[4000];
int Y[4000];
int B[4000];
int mn[200];
int mx[200];
int res[200];
int opt;
int tmp;
graph g;
int main(){
  int i, r;
  wmem = memarr;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);X[Lj4PdHRW] += (-1);
      rd(Y[Lj4PdHRW]);Y[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);
    }
  }
  g.setEdge(N,M,X,Y);
  if(g.bipartite()==0){
    wt_L("NO");
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(M);i++){
    {
      auto RZTsC2BF = (Y[i]);
      auto FmcKpFmN = ( X[i]);
      auto xr20shxY = ( -B[i]);
      X[M+i] = RZTsC2BF;
      Y[M+i] = FmcKpFmN;
      B[M+i] = xr20shxY;
    }
  }
  M *= 2;
  opt = -1073709056;
  for(r=(0);r<(N);r++){
    for(i=(0);i<(N);i++){
      mn[i] = -1073709056;
      mx[i] = 1073709056;
    }
    mn[r] = mx[r] = 0;
    for(;;){
      int fg = 0;
      for(i=(0);i<(M);i++){
        if(mn[X[i]] == -1073709056){
          continue;
        }
        if(B[i] == 0 && mn[Y[i]] < mn[X[i]] - 1){
          mn[Y[i]] = mn[X[i]] - 1;
          fg++;
        }
        if(B[i] == 0 && mx[Y[i]] > mx[X[i]] + 1){
          mx[Y[i]] = mx[X[i]] + 1;
          fg++;
        }
        if(B[i] != 0 && mn[Y[i]] < mn[X[i]] + B[i]){
          mn[Y[i]] = mn[X[i]] + B[i];
          fg++;
        }
        if(B[i] != 0 && mx[Y[i]] > mx[X[i]] + B[i]){
          mx[Y[i]] = mx[X[i]] + B[i];
          fg++;
        }
      }
      for(i=(0);i<(N);i++){
        if(mx[i] < mn[i] || mx[i] < 0){
          goto WYIGIcGE;
        }
      }
      if(!fg){
        break;
      }
    }
    int jZyWAPpY;
    int jbtyPBGc;
    if(N==0){
      jbtyPBGc = 0;
    }
    else{
      jbtyPBGc = mx[0];
      for(jZyWAPpY=(1);jZyWAPpY<(N);jZyWAPpY++){
        jbtyPBGc = max_L(jbtyPBGc, mx[jZyWAPpY]);
      }
    }
    if(opt <jbtyPBGc){
      {
        int AlM5nNnR;
        int XJIcIBrW;
        if(N==0){
          XJIcIBrW = 0;
        }
        else{
          XJIcIBrW = mx[0];
          for(AlM5nNnR=(1);AlM5nNnR<(N);AlM5nNnR++){
            XJIcIBrW = max_L(XJIcIBrW, mx[AlM5nNnR]);
          }
        }
        opt =XJIcIBrW;
      }
      for(i=(0);i<(N);i++){
        res[i] = mx[i];
      }
    }
    WYIGIcGE:;
  }
  if(opt==-1073709056){
    wt_L("NO");
    wt_L('\n');
    return 0;
  }
  wt_L("YES");
  wt_L('\n');
  wt_L(opt);
  wt_L('\n');
  {
    int gEg5UqEA;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(gEg5UqEA=(0);gEg5UqEA<(N-1);gEg5UqEA++){
        wt_L(res[gEg5UqEA]);
        wt_L(' ');
      }
      wt_L(res[gEg5UqEA]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20201206-1

// --- original code ---
// //no-unlocked
// int N, M, X[4000], Y[4000], B[4000];
// int mn[200], mx[200];
// int res[200], opt, tmp;
// graph g;
// {
//   rd(N,M,(X--,Y--,B)(M));
//   g.setEdge(N,M,X,Y);
//   if(g.bipartite()==0) wt("NO"), return 0;
// 
//   rep(i,M) (X[M+i], Y[M+i], B[M+i]) = (Y[i], X[i], -B[i]);
//   M *= 2;
// 
//   opt = -int_inf;
//   rep(r,N){
//     rep(i,N) mn[i] = -int_inf, mx[i] = int_inf;
//     mn[r] = mx[r] = 0;
//     for(;;){
//       int fg = 0;
//       rep(i,M){
//         if(mn[X[i]] == -int_inf) continue;
//         if(B[i] == 0 && mn[Y[i]] < mn[X[i]] - 1) mn[Y[i]] = mn[X[i]] - 1, fg++;
//         if(B[i] == 0 && mx[Y[i]] > mx[X[i]] + 1) mx[Y[i]] = mx[X[i]] + 1, fg++;
//         if(B[i] != 0 && mn[Y[i]] < mn[X[i]] + B[i]) mn[Y[i]] = mn[X[i]] + B[i], fg++;
//         if(B[i] != 0 && mx[Y[i]] > mx[X[i]] + B[i]) mx[Y[i]] = mx[X[i]] + B[i], fg++;
//       }
//       rep(i,N) if(mx[i] < mn[i] || mx[i] < 0) break_break_continue;
//       if(!fg) break;
//     }
//     if(opt < max(mx(N))){
//       opt = max(mx(N));
//       rep(i,N) res[i] = mx[i];
//     }
//   }
//   if(opt==-int_inf) wt("NO"), return 0;
//   wt("YES");
//   wt(opt);
//   wt(res(N));
// }