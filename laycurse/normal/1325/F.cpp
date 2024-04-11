#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
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
template<class T> inline T pow2_L(T a){
  return a*a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
inline long long Isqrt_c_L(const long long n){
  long long r = sqrt(n);
  r =max_L(r-2, 0);
  while(pow2_L(r)< n ){
    r++;
  }
  return r;
}
struct graph{
  int N;
  int *es;
  int **edge;
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
int M;
int A[200000];
int B[200000];
int sqrtN;
graph g;
int sz;
int idp[100000];
int dep[100000];
int up[100000];
int solve(int n){
  int Lj4PdHRW;
  int i;
  int j;
  int k;
  int dame = 0;
  for(Lj4PdHRW=(0);Lj4PdHRW<(g.es[n]);Lj4PdHRW++){
    auto &i = g.edge[n][Lj4PdHRW];
    if(dep[i] >= 0 && dep[n] - dep[i] + 1>= sqrtN){
      sz = 0;
      k = n;
      for(;;){
        idp[sz++] = k;
        if(k == i){
          break;
        }
        k = up[k];
      }
      wt_L(2);
      wt_L('\n');
      wt_L(sz);
      wt_L('\n');
      {
        int RZTsC2BF;
        if(sz==0){
          wt_L('\n');
        }
        else{
          for(RZTsC2BF=(0);RZTsC2BF<(sz-1);RZTsC2BF++){
            wt_L(idp[RZTsC2BF]+1);
            wt_L(' ');
          }
          wt_L(idp[RZTsC2BF]+1);
          wt_L('\n');
        }
      }
      exit(0);
    }
    if(dep[i] >= 0){
      continue;
    }
    up[i] = n;
    dep[i] = dep[n] + 1;
    chmax(dame, solve(i));
  }
  if(dame==0){
    idp[sz++] = n;
    dame = sqrtN - 1;
  }
  return dame - 1;
}
int main(){
  int i;
  wmem = memarr;
  rd(N);
  rd(M);
  {
    int WYIGIcGE;
    for(WYIGIcGE=(0);WYIGIcGE<(M);WYIGIcGE++){
      rd(A[WYIGIcGE]);A[WYIGIcGE] += (-1);
      rd(B[WYIGIcGE]);B[WYIGIcGE] += (-1);
    }
  }
  g.setEdge(N,M,A,B);
  for(i=(0);i<(N);i++){
    dep[i] = up[i] = -1;
  }
  sqrtN =Isqrt_c_L(N);
  dep[0] = 0;
  solve(0);
  wt_L(1);
  wt_L('\n');
  {
    int a2conNHc;
    if(sqrtN==0){
      wt_L('\n');
    }
    else{
      for(a2conNHc=(0);a2conNHc<(sqrtN-1);a2conNHc++){
        wt_L(idp[a2conNHc]+1);
        wt_L(' ');
      }
      wt_L(idp[a2conNHc]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200314-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[2d5];
// 
// int sqrtN;
// graph g;
// int sz, idp[1d5], dep[1d5], up[1d5];
// 
// int solve(int n){
//   int i, j, k, dame = 0;
//   rep[g.edge[n]](i,g.es[n]){
//     if(dep[i] >= 0 && dep[n] - dep[i] + 1>= sqrtN){
//       sz = 0;
//       k = n;
//       for(;;){
//         idp[sz++] = k;
//         if(k == i) break;
//         k = up[k];
//       }
//       wt(2);
//       wt(sz);
//       wt(idp(sz)+1);
//       exit(0);
//     }
// 
//     if(dep[i] >= 0) continue;
//     up[i] = n;
//     dep[i] = dep[n] + 1;
//     dame >?= solve(i);
//   }
// 
//   if(dame==0) idp[sz++] = n, dame = sqrtN - 1;
//   return dame - 1;
// }
// 
// {
//   rd(N,M,(A--,B--)(M));
//   g.setEdge(N,M,A,B);
//   rep(i,N) dep[i] = up[i] = -1;
//   sqrtN = Isqrt_c(N);
//   dep[0] = 0;
//   solve(0);
// 
//   wt(1);
//   wt(idp(sqrtN)+1);
// }