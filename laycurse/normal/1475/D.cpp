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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
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
int N;
int M;
int A[200000];
int B[200000];
int s1;
int s2;
long long d1[200000];
long long d2[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int res = 1073709056;
    int i;
    int j;
    long long ok;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
        rd(B[xr20shxY]);
      }
    }
    s1 = s2 = 0;
    for(i=(0);i<(N);i++){
      if(B[i]==1){
        d1[s1++] = A[i];
      }
      if(B[i]==2){
        d2[s2++] = A[i];
      }
    }
    rsortA_L(s1, d1);
    rsortA_L(s2, d2);
    j = s2;
    {
      int tU__gIr_;
      long long a2conNHc;
      if(s2==0){
        a2conNHc = 0;
      }
      else{
        a2conNHc = d2[0];
        for(tU__gIr_=(1);tU__gIr_<(s2);tU__gIr_++){
          a2conNHc += d2[tU__gIr_];
        }
      }
      ok =a2conNHc;
    }
    for(i=(0);i<(s1+1);i++){
      while(j && ok - d2[j-1] >= M){
        ok -= d2[--j];
      }
      if(ok >= M){
        chmin(res, i + 2 * j);
      }
      if(i==s1){
        break;
      }
      ok += d1[i];
    }
    if(res == 1073709056){
      res = -1;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[2d5];
// int s1, s2; ll d1[2d5], d2[2d5];
// {
//   REP(rd_int()){
//     int res = int_inf, i, j; ll ok;
//     rd(N,M,A(N),B(N));
//     s1 = s2 = 0;
//     rep(i,N){
//       if(B[i]==1) d1[s1++] = A[i];
//       if(B[i]==2) d2[s2++] = A[i];
//     }
//     rsortA(s1, d1);
//     rsortA(s2, d2);
// 
//     j = s2;
//     ok = sum(d2(s2));
//     rep(i,s1+1){
//       while(j && ok - d2[j-1] >= M) ok -= d2[--j];
//       if(ok >= M) res <?= i + 2 * j;
//       if(i==s1) break;
//       ok += d1[i];
//     }
//     if(res == int_inf) res = -1;
//     wt(res);
//   }
// }