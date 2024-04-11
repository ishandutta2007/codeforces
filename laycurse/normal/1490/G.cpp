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
inline void rd(long long &x){
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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
template<class T> void arrRot(int k, int N, T A[], T B[] = NULL, void *mem = wmem){
  int i;
  int fg = 0;
  (k = moddw_L(k,N));
  if(B==NULL){
    walloc1d(&B, N, &mem);
    fg = 1;
  }
  for(i=(k);i<(N);i++){
    B[i-k] = A[i];
  }
  for(i=(0);i<(k);i++){
    B[N-k+i] = A[i];
  }
  if(fg){
    for(i=(0);i<(N);i++){
      A[i] = B[i];
    }
  }
}
int N;
int M;
long long A[200000];
long long X;
long long s[200000+1];
int sz;
int ind[200000+1];
long long up[200000+1];
long long res[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, q;
    long long nd;
    long long tm;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    arrRot(1,N,A);
    for(i=(0);i<(N);i++){
      s[i+1] = s[i] + A[i];
    }
    sz = 1;
    up[0] = ind[0] = 0;
    for(i=(1);i<(N+1);i++){
      if(up[sz-1] < s[i]){
        {
          auto ao_dF3pO = (s[i]);
          auto tU__gIr_ = ( i);
          up[sz] = ao_dF3pO;
          ind[sz] = tU__gIr_;
        }
        sz++;
      }
    }
    for(q=(0);q<(M);q++){
      rd(X);
      X -= A[N-1];
      nd = X - up[sz-1];
      res[q] = 0;
      if(nd > 0){
        if(s[N] <= 0){
          res[q] = -1;
          continue;
        }
        tm =(divup_L(nd,s[N]));
        res[q] += tm * N;
        X -= s[N] * tm;
      }
      int V9aVTaxx;
      int APIVbQlN;
      int YREPHmFM;
      V9aVTaxx = 0;
      APIVbQlN = sz-1;
      while(V9aVTaxx < APIVbQlN){
        if((V9aVTaxx + APIVbQlN)%2==0){
          YREPHmFM = (V9aVTaxx + APIVbQlN) / 2;
        }
        else{
          YREPHmFM = (V9aVTaxx + APIVbQlN - 1) / 2;
        }
        if(up[YREPHmFM] >= X){
          APIVbQlN = YREPHmFM;
        }
        else{
          V9aVTaxx = YREPHmFM + 1;
        }
      }
      tm =APIVbQlN;
      res[q] += ind[tm];
    }
    {
      int ZIeRIny5;
      if(q==0){
        wt_L('\n');
      }
      else{
        for(ZIeRIny5=(0);ZIeRIny5<(q-1);ZIeRIny5++){
          wt_L(res[ZIeRIny5]);
          wt_L(' ');
        }
        wt_L(res[ZIeRIny5]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 3]

// --- original code ---
// //no-unlocked
// int N, M; ll A[2d5], X;
// ll s[2d5+1];
// int sz, ind[2d5+1]; ll up[2d5+1];
// ll res[2d5];
// {
//   REP(rd_int()){
//     ll nd, tm;
//     rd(N,M,A(N));
//     arrRot(1,N,A);
//     rep(i,N) s[i+1] = s[i] + A[i];
//     sz = 1;
//     up[0] = ind[0] = 0;
//     rep(i,1,N+1) if(up[sz-1] < s[i]){
//       (up[sz], ind[sz]) = (s[i], i);
//       sz++;
//     }
//     rep(q,M){
//       rd(X);
//       X -= A[N-1];
//       nd = X - up[sz-1];
//       res[q] = 0;
//       if(nd > 0){
//         if(s[N] <= 0) res[q] = -1, continue;
//         tm = nd /+ s[N];
//         res[q] += tm * N;
//         X -= s[N] * tm;
//       }
//       tm = bsearch_min[int,x,0,sz-1](up[x] >= X);
//       res[q] += ind[tm];
//     }
//     wt(res(q));
//   }
// }