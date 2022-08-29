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
void sortF_L(int N, unsigned A[], void *mem = wmem){
  int i;
  int m;
  int bt;
  unsigned *arr;
  unsigned c;
  int *sz;
  if(N < 256){
    sort(A, A+N);
    return;
  }
  bt = sizeof(unsigned) * 8;
  walloc1d(&arr, N, &mem);
  walloc1d(&sz, N, &mem);
  for(m=0;m<bt;m+=8){
    for(i=(0);i<(257);i++){
      sz[i] = 0;
    }
    for(i=(0);i<(N);i++){
      sz[ 1+((A[i]>>m)&255u) ]++;
    }
    for(i=(1);i<(257);i++){
      sz[i] += sz[i-1];
    }
    for(i=(0);i<(N);i++){
      c = ((A[i]>>m)&255u);
      arr[sz[c]++] = A[i];
    }
    swap(A, arr);
  }
}
void sortF_L(int N, int A[], void *mem = wmem){
  int i;
  int x;
  int y;
  int z;
  int *arr;
  unsigned *send;
  if(N < 256){
    sort(A, A+N);
    return;
  }
  send = (unsigned*)A;
  sortF_L(N, send, mem);
  if(A[0] < 0 || A[N-1] >= 0){
    return;
  }
  x = 0;
  y = N;
  while(x < y){
    z = (x+y) / 2;
    if(A[z] < 0){
      y = z;
    }
    else{
      x = z+1;
    }
  }
  walloc1d(&arr, N, &mem);
  z = 0;
  for(i=(x);i<(N);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(x);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(N);i++){
    A[i] = arr[i];
  }
}
void sortF_L(int N, unsigned long long A[], void *mem = wmem){
  int i;
  int m;
  int bt;
  unsigned long long *arr;
  unsigned c;
  int *sz;
  if(N < 512){
    sort(A, A+N);
    return;
  }
  bt = sizeof(unsigned long long) * 8;
  walloc1d(&arr, N, &mem);
  walloc1d(&sz, N, &mem);
  for(m=0;m<bt;m+=8){
    for(i=(0);i<(257);i++){
      sz[i] = 0;
    }
    for(i=(0);i<(N);i++){
      sz[ 1+((A[i]>>m)&255u) ]++;
    }
    for(i=(1);i<(257);i++){
      sz[i] += sz[i-1];
    }
    for(i=(0);i<(N);i++){
      c = ((A[i]>>m)&255u);
      arr[sz[c]++] = A[i];
    }
    swap(A, arr);
  }
}
void sortF_L(int N, long long A[], void *mem = wmem){
  int i;
  int x;
  int y;
  int z;
  long long *arr;
  unsigned long long *send;
  if(N < 512){
    sort(A, A+N);
    return;
  }
  send = (unsigned long long*)A;
  sortF_L(N, send, mem);
  if(A[0] < 0 || A[N-1] >= 0){
    return;
  }
  x = 0;
  y = N;
  while(x < y){
    z = (x+y) / 2;
    if(A[z] < 0){
      y = z;
    }
    else{
      x = z+1;
    }
  }
  walloc1d(&arr, N, &mem);
  z = 0;
  for(i=(x);i<(N);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(x);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(N);i++){
    A[i] = arr[i];
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
template<class T> long long counterSumIsLT(int As, T A[], int Bs, T B[], T val){
  int i = 0;
  int j = Bs;
  long long res = 0;
  while(i < As){
    while(j && A[i] + B[j-1] >= val){
      j--;
    }
    if(!j){
      break;
    }
    while(i<As && A[i] + B[j-1] < val){
      i++;
      res += j;
    }
  }
  return res;
}
int N;
int A[400000];
int as;
int a[400000];
int bs;
int b[400000];
int main(){
  int bt;
  wmem = memarr;
  int all;
  int res = 0;
  long long cnt;
  long long tmp;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(bt=(30)-1;bt>=(0);bt--){
    int i;
    all = (1<<(bt+1))-1;
    as = bs = 0;
    for(i=(0);i<(N);i++){
      if(((A[i]) &(1<<(bt)))){
        a[as++] = (A[i]&all) ^(1<<(bt));
      }
      else{
        b[bs++] = (A[i]&all);
      }
    }
    sortF_L(as, a);
    sortF_L(bs, b);
    cnt = 0;
    tmp = counterSumIsLT(as, a, bs, b,(1<<(bt)));
    cnt += tmp;
    tmp = counterSumIsLT(as, a, as, a,(1<<(bt)));
    for(i=(0);i<(as);i++){
      if(a[i]+a[i] <(1<<(bt))){
        tmp--;
      }
    }
    cnt += (long long) as * (as-1) / 2 - tmp / 2;
    tmp = counterSumIsLT(bs, b, bs, b,(1<<(bt)));
    for(i=(0);i<(bs);i++){
      if(b[i]+b[i] <(1<<(bt))){
        tmp--;
      }
    }
    cnt += (long long) bs * (bs-1) / 2 - tmp / 2;
    if(cnt%2){
      res |=(1<<(bt));
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200303-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[4d5];
// 
// int as, a[4d5];
// int bs, b[4d5];
// 
// {
//   int all;
//   int res = 0;
//   ll cnt, tmp;
//   rd(N,A(N));
// 
//   rrep(bt,30){
//     all = (1<<(bt+1))-1;
//     as = bs = 0;
//     rep(i,N){
//       if(BIT_ith(A[i],bt)) a[as++] = (A[i]&all) ^ BIT_ith(bt);
//       else                 b[bs++] = (A[i]&all);
//     }
//     sortF(as, a);
//     sortF(bs, b);
//     cnt = 0;
// 
// //    wt("---",bt);
// //    wt(a(as));
// //    wt(b(bs));
// 
//     tmp = counterSumIsLT(as, a, bs, b, BIT_ith(bt));
//     cnt += tmp;
// //    wt(cnt);
// 
//     tmp = counterSumIsLT(as, a, as, a, BIT_ith(bt));
//     rep(i,as) if(a[i]+a[i] < BIT_ith(bt)) tmp--;
//     cnt += (ll) as * (as-1) / 2 - tmp / 2;
// //    wt(cnt);
// 
//     tmp = counterSumIsLT(bs, b, bs, b, BIT_ith(bt));
//     rep(i,bs) if(b[i]+b[i] < BIT_ith(bt)) tmp--;
//     cnt += (ll) bs * (bs-1) / 2 - tmp / 2;
// //    wt(cnt);
// 
//     if(cnt%2) res |= BIT_ith(bt);
//   }
// 
//   wt(res);
// }