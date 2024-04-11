#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
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
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int N;
    rd(N);
    int A[N];
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    int ress = 0;
    int res1[N];
    int res2[N];
    int k;
    while(N){
      int KrdatlYV;
      remove_reference<decltype(A[KrdatlYV])>::type ao_dF3pO;
      int tU__gIr_ = 0;
      int a2conNHc;
      if((0) > ((N)-1)){
        ao_dF3pO = 0;
      }
      else{
        for(KrdatlYV = 0; KrdatlYV <= (N)-1; KrdatlYV++){
          if(tU__gIr_ == 0){
            ao_dF3pO = A[KrdatlYV];
            a2conNHc = KrdatlYV;
            tU__gIr_ = 1;
            continue;
          }
          const auto hCmBdyQB = A[KrdatlYV];
          if(ao_dF3pO <= hCmBdyQB){
            ao_dF3pO = hCmBdyQB;
            a2conNHc = KrdatlYV;
          }
        }
        if(tU__gIr_==0){
          ao_dF3pO = 0;
        }
      }
      k =a2conNHc;
      if(k < N-1){
        arrRot(1, N-k, A+k);
        arrInsert(ress, ress, res1, k, res2, N-1);
      }
      N--;
    }
    wt_L(ress);
    wt_L('\n');
    for(i=(0);i<(ress);i++){
      wt_L(res1[i]+1);
      wt_L(' ');
      wt_L(res2[i]+1);
      wt_L(' ');
      wt_L(1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N, @A[N];
//   int ress = 0, res1[N], res2[N], k;
//   while(N){
//     k = argmaxL(A(N));
//     if(k < N-1){
//       arrRot(1, N-k, A+k);
//       arrInsert(ress, ress, res1, k, res2, N-1);
//     }
//     N--;
//   }
//   wt(ress);
//   rep(i,ress) wt(res1[i]+1, res2[i]+1, 1);
// }