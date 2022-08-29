#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
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
template<class T> int Distinct(int N, T A[], int sorted=0, void *mem = wmem){
  int i;
  int k;
  int res = 1;
  T *a;
  if(N==0){
    return 0;
  }
  if(sorted){
    for(i=(1);i<(N);i++){
      if(A[i]!=A[i-1]){
        res++;
      }
    }
  }
  else{
    walloc1d(&a,N,&mem);
    for(i=(0);i<(N);i++){
      a[i] = A[i];
    }
    sort(a,a+N);
    for(i=(1);i<(N);i++){
      if(a[i]!=a[i-1]){
        res++;
      }
    }
  }
  return res;
}
int N;
int T[200000];
int res[200000];
int opt;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(T[cTE1_r3A]);
      }
    }
    if(Distinct(N,T)==1){
      int i;
      opt = 1;
      for(i=(0);i<(N);i++){
        res[i] = 1;
      }
    }
    else if(N%2==0){
      int i;
      opt = 2;
      for(i=(0);i<(N);i++){
        res[i] = 1 + i%2;
      }
    }
    else{
      int i;
      for(i=(1);i<(N+1);i++){
        if(T[i%N]==T[i-1]){
          break;
        }
      }
      if(i==N+1){
        opt = 3;
        for(i=(0);i<(N);i++){
          res[i] = 1 + i%2;
        }
        res[N-1] = 3;
      }
      else{
        int j;
        opt = 2;
        for(j=(0);j<(N);j++){
          if(j>=i){
            res[j] = 1 +(j+1)%2;
          }
          else{
            res[j] = 1 +j%2;
          }
        }
      }
    }
    wt_L(opt);
    wt_L('\n');
    {
      int YREPHmFM;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(YREPHmFM=(0);YREPHmFM<(N-1);YREPHmFM++){
          wt_L(res[YREPHmFM]);
          wt_L(' ');
        }
        wt_L(res[YREPHmFM]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200322-1 [beta]

// --- original code ---
// //no-unlocked
// int N, T[2d5];
// int res[2d5], opt;
// {
//   REP(rd_int()){
//     rd(N,T(N));
//     if(Distinct(N,T)==1){
//       opt = 1;
//       rep(i,N) res[i] = 1;
//     } else if(N%2==0) {
//       opt = 2;
//       rep(i,N) res[i] = 1 + i%2;
//     } else {
//       rep(i,1,N+1) if(T[i%N]==T[i-1]) break;
//       if(i==N+1){
//         opt = 3;
//         rep(i,N) res[i] = 1 + i%2;
//         res[N-1] = 3;
//       } else {
//         opt = 2;
//         rep(j,N) res[j] = 1 + if[j>=i, (j+1), j]%2;
//       }
//     }
//     wt(opt);
//     wt(res(N));
//   }
// }