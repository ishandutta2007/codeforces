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
template<class T> int runLength(int N, T *arr, void *val_s = NULL, void *len_s = NULL){
  int i;
  int rN;
  T *val = (T*) val_s;
  int *len = (int*) len_s;
  if(N==0){
    return 0;
  }
  if(val==NULL || len==NULL){
    void *mem = wmem;
    if(val==NULL){
      walloc1d(&val, N, &mem);
    }
    if(len==NULL){
      walloc1d(&len, N, &mem);
    }
  }
  rN = 1;
  val[0] = arr[0];
  len[0] = 1;
  for(i=(1);i<(N);i++){
    if(val[rN-1] == arr[i]){
      len[rN-1]++;
    }
    else{
      val[rN] = arr[i];
      len[rN] = 1;
      rN++;
    }
  }
  return rN;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
int A[200000];
int sz;
int val[200000];
int len[200000];
int cnt1[200000];
int cnt2[200000];
long long sm1[200000];
long long sm2[200000];
int main(){
  int i;
  wmem = memarr;
  long long res = 4611686016279904256LL;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  sortF_L(N, A);
  sz = runLength(N, A, val, len);
  for(i=(1);i<(sz);i++){
    cnt1[i] = cnt1[i-1] + len[i-1];
  }
  for(i=(1);i<(sz);i++){
    sm1[i] = sm1[i-1] + (long long)val[i-1] * len[i-1];
  }
  for(i=(sz-1)-1;i>=(0);i--){
    cnt2[i] = cnt2[i+1] + len[i+1];
  }
  for(i=(sz-1)-1;i>=(0);i--){
    sm2[i] = sm2[i+1] + (long long)val[i+1] * len[i+1];
  }
  for(i=(0);i<(sz);i++){
    if(len[i] >= K){
      chmin(res, 0);
      continue;
    }
    if(len[i] + cnt1[i] >= K){
      chmin(res, (long long) val[i] * cnt1[i] - sm1[i] - (len[i] + cnt1[i] - K));
    }
    if(len[i] + cnt2[i] >= K){
      chmin(res, sm2[i] - (long long) val[i] * cnt2[i] - (len[i] + cnt2[i] - K));
    }
    chmin(res, ((long long) val[i] * cnt1[i] - sm1[i]) + (sm2[i] - (long long) val[i] * cnt2[i]) - (N - K));
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200322-1 [beta]

// --- original code ---
// //no-unlocked
// int N, K;
// int A[2d5];
// 
// int sz, val[2d5], len[2d5];
// int cnt1[2d5], cnt2[2d5];
// ll sm1[2d5], sm2[2d5];
// {
//   ll res = ll_inf;
//   rd(N,K,A(N));
//   sortF(N, A);
// 
//   sz = runLength(N, A, val, len);
//   rep(i,1,sz) cnt1[i] = cnt1[i-1] + len[i-1];
//   rep(i,1,sz) sm1[i] = sm1[i-1] + (ll)val[i-1] * len[i-1];
//   rrep(i,sz-1) cnt2[i] = cnt2[i+1] + len[i+1];
//   rrep(i,sz-1) sm2[i] = sm2[i+1] + (ll)val[i+1] * len[i+1];
//   
//   rep(i,sz){
//     if(len[i] >= K) res <?= 0, continue;
//     if(len[i] + cnt1[i] >= K) res <?= (ll) val[i] * cnt1[i] - sm1[i] - (len[i] + cnt1[i] - K);
//     if(len[i] + cnt2[i] >= K) res <?= sm2[i] - (ll) val[i] * cnt2[i] - (len[i] + cnt2[i] - K);
//     res <?= ((ll) val[i] * cnt1[i] - sm1[i]) + (sm2[i] - (ll) val[i] * cnt2[i]) - (N - K);
//   }
// 
//   wt(res);
// }