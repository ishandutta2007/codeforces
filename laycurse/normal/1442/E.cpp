#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
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
}
;
int N;
int A[200000];
int X[200000];
int Y[200000];
graph g;
int deg[200000];
int st[200000];
int ss;
int nx[200000];
int ns;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int mode;
    int res = 1073709056;
    int tmp;
    int cur;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N-1);xr20shxY++){
        rd(X[xr20shxY]);X[xr20shxY] += (-1);
        rd(Y[xr20shxY]);Y[xr20shxY] += (-1);
      }
    }
    if(N==1){
      wt_L(1);
      wt_L('\n');
      continue;
    }
    for(mode=(0);mode<(2);mode++){
      int i;
      g.setEdge(N,N-1,X,Y);
      for(i=(0);i<(N);i++){
        deg[i] = g.es[i];
      }
      ss = 0;
      for(i=(0);i<(N);i++){
        if(deg[i]==1){
          st[ss++] = i;
        }
      }
      tmp = 0;
      cur = mode;
      while(ss){
        tmp++;
        cur ^= 1;
        ns = 0;
        while(ss){
          int ZIeRIny5;
          i = st[--ss];
          if(A[i] != -1 && A[i] != cur){
            nx[ns++] = i;
            continue;
          }
          for(ZIeRIny5=(0);ZIeRIny5<(g.es[i]);ZIeRIny5++){
            auto &j = g.edge[i][ZIeRIny5];
            deg[j]--;
            if(deg[j]==1){
              st[ss++] = j;
            }
          }
        }
        ss = ns;
        for(i=(0);i<(ss);i++){
          st[i] = nx[i];
        }
      }
      chmin(res, tmp);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20201102-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], X[2d5], Y[2d5];
// graph g;
// int deg[2d5];
// int st[2d5], ss, nx[2d5], ns;
// {
//   REP(rd_int()){
//     int res = int_inf, tmp, cur;
//     rd(N,(A--)(N),(X--,Y--)(N-1));
//     if(N==1) wt(1), continue;
//     rep(mode,2){
//       g.setEdge(N,N-1,X,Y);
//       rep(i,N) deg[i] = g.es[i];
//       ss = 0;
//       rep(i,N) if(deg[i]==1) st[ss++] = i;
// 
//       tmp = 0;
//       cur = mode;
//       while(ss){
//         tmp++;
//         cur ^= 1;
//         ns = 0;
//         while(ss){
//           i = st[--ss];
//           if(A[i] != -1 && A[i] != cur) nx[ns++] = i, continue;
//           rep[g.edge[i]](j,g.es[i]){
//             deg[j]--;
//             if(deg[j]==1) st[ss++] = j;
//           }
//         }
//         ss = ns;
//         rep(i,ss) st[i] = nx[i];
//       }
//       res <?= tmp;
//     }
//     wt(res);
//   }
// }