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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
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
int N;
int A[100000];
int B[100000];
long long W[100000];
int deg[100000];
long long res[100000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int k;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(W[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N-1);xr20shxY++){
        rd(A[xr20shxY]);A[xr20shxY] += (-1);
        rd(B[xr20shxY]);B[xr20shxY] += (-1);
      }
    }
    for(i=(0);i<(N);i++){
      deg[i] = -1;
    }
    for(i=(0);i<(N-1);i++){
      deg[A[i]]++;
      deg[B[i]]++;
    }
    {
      int hCmBdyQB;
      long long V9aVTaxx;
      if(N==0){
        V9aVTaxx = 0;
      }
      else{
        V9aVTaxx = W[0];
        for(hCmBdyQB=(1);hCmBdyQB<(N);hCmBdyQB++){
          V9aVTaxx += W[hCmBdyQB];
        }
      }
      res[0] =V9aVTaxx;
    }
    rsortA_L(N, W, deg);
    k = 0;
    for(i=(0);i<(N);i++){
      int ZIeRIny5;
      for(ZIeRIny5=(0);ZIeRIny5<(deg[i]);ZIeRIny5++){
        res[k+1] = res[k] + W[i];
        k++;
      }
    }
    {
      int XJIcIBrW;
      if(N-1==0){
        wt_L('\n');
      }
      else{
        for(XJIcIBrW=(0);XJIcIBrW<(N-1-1);XJIcIBrW++){
          wt_L(res[XJIcIBrW]);
          wt_L(' ');
        }
        wt_L(res[XJIcIBrW]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20201229-1

// --- original code ---
// //no-unlocked
// int N, A[1d5], B[1d5]; ll W[1d5];
// int deg[1d5];
// ll res[1d5];
// {
//   REP(rd_int()){
//     int i, k;
//     rd(N,W(N),(A--,B--)(N-1));
//     rep(i,N) deg[i] = -1;
//     rep(i,N-1) deg[A[i]]++, deg[B[i]]++;
//     res[0] = sum(W(N));
//     rsortA(N, W, deg);
//     k = 0;
//     rep(i,N) rep(deg[i]) res[k+1] = res[k] + W[i], k++;
//     wt(res(N-1));
//   }
// }