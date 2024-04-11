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
int T;
int Y;
long long X;
int res[100000+1];
int main(){
  int i, t;
  wmem = memarr;
  long long z;
  rd(N);
  rd(M);
  for(i=(1);i<(M+1);i++){
    res[i] = 1073709056;
  }
  for(t=(0);t<(N);t++){
    rd(T);
    rd(X);
    rd(Y);
    for(i=(M+1)-1;i>=(0);i--){
      if(res[i] < 1073709056){
        int FmcKpFmN;
        z = i;
        for(FmcKpFmN=(0);FmcKpFmN<(Y);FmcKpFmN++){
          if(T==1){
            z = (z + ((divup_L(X,100000))));
          }
          if(T==2){
            z =(divup_L((z * X),100000));
          }
          if(z > M || res[z] < 1073709056){
            break;
          }
          res[z] = t + 1;
        }
      }
    }
  }
  for(i=(0);i<(M+1);i++){
    if(res[i]==1073709056){
      res[i] = -1;
    }
  }
  arrRot(1,M+1,res);
  {
    int ao_dF3pO;
    if(M==0){
      wt_L('\n');
    }
    else{
      for(ao_dF3pO=(0);ao_dF3pO<(M-1);ao_dF3pO++){
        wt_L(res[ao_dF3pO]);
        wt_L(' ');
      }
      wt_L(res[ao_dF3pO]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210328-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M, T, Y; ll X;
// int res[1d5+1];
// {
//   ll z;
//   rd(N,M);
//   rep(i,1,M+1) res[i] = int_inf;
// 
//   rep(t,N){
//     rd(T, X, Y);
//     rrep(i,M+1) if(res[i] < int_inf){
//       z = i;
//       rep(Y){
//         if(T==1) z = (z + (X /+ 1d5));
//         if(T==2) z = (z * X) /+ 1d5;
//         if(z > M || res[z] < int_inf) break;
//         res[z] = t + 1;
//       }
//     }
//   }
// 
//   rep(i,M+1) if(res[i]==int_inf) res[i] = -1;
//   arrRot(1,M+1,res);
//   wt(res(M));
// }