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
  T*a;
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
template<class T, class S> int arrCountVal(int N, T A[], S val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
int N;
int X;
int A[1000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    rd(X);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    if(Distinct(N,A)==1 && X==A[0]){
      wt_L(0);
      wt_L('\n');
      continue;
    }
    int xr20shxY;
    int WYIGIcGE;
    if(N==0){
      WYIGIcGE = 0;
    }
    else{
      WYIGIcGE = A[0];
      for(xr20shxY=(1);xr20shxY<(N);xr20shxY++){
        WYIGIcGE += A[xr20shxY];
      }
    }
    if(WYIGIcGE== N*X || arrCountVal(N,A,X)){
      wt_L(1);
      wt_L('\n');
      continue;
    }
    wt_L(2);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200916-1

// --- original code ---
// //no-unlocked
// int N, X, A[1000];
// {
//   REP(rd_int()){
//     rd(N,X,A(N));
//     if(Distinct(N,A)==1 && X==A[0]) wt(0), continue;
//     if(sum(A(N)) == N*X || arrCountVal(N,A,X)) wt(1), continue;
//     wt(2);
//   }
// }