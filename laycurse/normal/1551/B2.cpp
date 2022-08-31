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
template<class T, class S> inline T RoundDown(T a, S b){
  T m;
  if(b < 0){
    b = -b;
  }
  if(b <= 1){
    return a;
  }
  m = a % b;
  if(m == 0){
    return a;
  }
  if(m < 0){
    m += b;
  }
  return ((a - m) / b) * b;
}
int N;
int K;
int A[200000];
int a[200000];
int b[200000];
int hist[200000];
int res[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int c = 0;
    rd(N);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    for(i=(0);i<(N);i++){
      hist[i] = 0;
    }
    for(i=(0);i<(N);i++){
      if(hist[A[i]] < K){
        auto ao_dF3pO = ((A[i]));
        auto tU__gIr_ = (( i));
        auto a2conNHc = (( c+1));
        a[c]=ao_dF3pO;
        b[c]=tU__gIr_;
        c=a2conNHc;
        hist[A[i]]++;
      }
    }
    c = RoundDown(c, K);
    sortA_L(c, a, b);
    for(i=(0);i<(N);i++){
      res[i] = 0;
    }
    for(i=(0);i<(c);i++){
      res[b[i]] = i % K + 1;
    }
    {
      int jZyWAPpY;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(jZyWAPpY=(0);jZyWAPpY<(N-1);jZyWAPpY++){
          wt_L(res[jZyWAPpY]);
          wt_L(' ');
        }
        wt_L(res[jZyWAPpY]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N, K, A[2d5];
// int a[], b[], hist[];
// int res[];
// {
//   REP(rd_int()){
//     int i, j, c = 0;
//     rd(N,K,(A--)(N));
//     rep(i,N) hist[i] = 0;
//     rep(i,N) if(hist[A[i]] < K){
//       (a[c], b[c], c) = (A[i], i, c+1);
//       hist[A[i]]++;
//     }
//     c = RoundDown(c, K);
//     sortA(c, a, b);
//     rep(i,N) res[i] = 0;
//     rep(i,c) res[b[i]] = i % K + 1;
//     wt(res(N));
//   }
// }