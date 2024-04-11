#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
int K;
long long A[500000];
long long s[500000];
int main(){
  wmem = memarr;
  int i;
  int k;
  int fg = 0;
  long long res = 0;
  long long cur = 0;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  rsortA_L(N,A);
  for(i=(0);i<(N);i++){
    res += cur;
    cur += A[i];
    if(cur < 0){
      N -= i;
      for(k=(0);k<(N);k++){
        A[k] = A[k+i];
      }
      A[0] = cur;
      fg = 1;
      break;
    }
  }
  if(!fg){
    wt_L(res);
    wt_L('\n');
    return 0;
  }
  K =min_L(K+1, N);
  for(i=(0);i<(K);i++){
    s[i] = 0;
  }
  for(i=(0);i<(N);i++){
    res += s[i%K];
    s[i%K] += A[i];
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20201205-1

// --- original code ---
// //no-unlocked
// int N, K; ll A[5d5], s[5d5];
// {
//   int i, k, fg = 0;
//   ll res = 0, cur = 0;
//   rd(N,K,A(N));
//   rsortA(N,A);
//   rep(i,N){
//     res += cur;
//     cur += A[i];
//     if(cur < 0){
//       N -= i;
//       rep(k,N) A[k] = A[k+i];
//       A[0] = cur;
//       fg = 1;
//       break;
//     }
//   }
//   if(!fg) wt(res), return 0;
//   
//   K = min(K+1, N);
//   rep(i,K) s[i] = 0;
//   rep(i,N) res += s[i%K], s[i%K] += A[i];
// 
//   wt(res);
// }