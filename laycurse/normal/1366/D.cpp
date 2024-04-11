#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
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
int Prime_L(int N, int res[], void *mem=wmem){
  int i;
  int a;
  int b;
  int sz = 1;
  const int r = 23000;
  bool *isprime;
  int *sf;
  int ss = 1;
  walloc1d(&isprime, r, &mem);
  walloc1d(&sf, r, &mem);
  isprime = (bool*)mem;
  sf = (int*)(isprime + r);
  N /= 2;
  res[0] = 2;
  b =min_L(r, N);
  for(i=(1);i<(b);i++){
    isprime[i] = 1;
  }
  for(i=(1);i<(b);i++){
    if(isprime[i]){
      res[sz++] = 2*i+1;
      sf[ss] = 2*i*(i+1);
      if(sf[ss] < N){
        while(sf[ss] < r){
          isprime[sf[ss]] = 0;
          sf[ss] += res[ss];
        }
        ss++;
      }
    }
  }
  for(a=r; a<N; a+=r){
    b =min_L(a + r, N);
    isprime -= r;
    for(i=(a);i<(b);i++){
      isprime[i] = 1;
    }
    for(i=(1);i<(ss);i++){
      while(sf[i] < b){
        isprime[sf[i]] = 0;
        sf[i] += res[i];
      }
    }
    for(i=(a);i<(b);i++){
      if(isprime[i]){
        res[sz++] = 2*i+1;
      }
    }
  }
  return sz;
}
int N;
int A[500000];
int res1[500000];
int res2[500000];
int ps;
int p[1000000];
int f[10000000+1];
int main(){
  int Lj4PdHRW, i;
  wmem = memarr;
  ps =Prime_L(10000000, p);
  for(Lj4PdHRW=(0);Lj4PdHRW<(ps);Lj4PdHRW++){
    int j;
    auto &i = p[Lj4PdHRW];
    for(j=(i);j<(10000000+1);j+=(i)){
      f[j] = i;
    }
  }
  rd(N);
  {
    int RZTsC2BF;
    for(RZTsC2BF=(0);RZTsC2BF<(N);RZTsC2BF++){
      rd(A[RZTsC2BF]);
    }
  }
  for(i=(0);i<(N);i++){
    int x = 1;
    int y = A[i];
    int z = f[y];
    while(y%z==0){
      x *= z;
      y /= z;
    }
    if(y==1){
      res1[i] = res2[i] = -1;
      continue;
    }
    res1[i] = x;
    res2[i] = y;
  }
  {
    int tU__gIr_;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(tU__gIr_=(0);tU__gIr_<(N-1);tU__gIr_++){
        wt_L(res1[tU__gIr_]);
        wt_L(' ');
      }
      wt_L(res1[tU__gIr_]);
      wt_L('\n');
    }
  }
  {
    int V9aVTaxx;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(V9aVTaxx=(0);V9aVTaxx<(N-1);V9aVTaxx++){
        wt_L(res2[V9aVTaxx]);
        wt_L(' ');
      }
      wt_L(res2[V9aVTaxx]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[5d5], res1[5d5], res2[5d5];
// int ps, p[1d6];
// int f[1d7+1];
// {
//   ps = Prime(1d7, p);
//   rep[p](i,ps) rep(j,i,1d7+1,i) f[j] = i;
// 
//   rd(N,A(N));
//   rep(i,N){
//     int x = 1, y = A[i], z = f[y];
//     while(y%z==0) x *= z, y /= z;
//     if(y==1) res1[i] = res2[i] = -1, continue;
//     res1[i] = x;
//     res2[i] = y;
//   }
//   wt(res1(N));
//   wt(res2(N));
// }