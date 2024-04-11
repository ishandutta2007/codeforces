#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
inline long long rd_ll(void){
  long long x;
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
int Prime_L(int N, int res[], void *mem=wmem){
  int i;
  int a;
  int b;
  int sz = 1;
  const int r = 23000;
  bool*isprime;
  int*sf;
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
template<class T> void Unique_L(int &N, T A[], int sorted=0){
  int i;
  int k;
  if(!sorted){
    sort(A, A+N);
  }
  k = 0;
  for(i=(0);i<(N);i++){
    if(k==0 || A[k-1]!=A[i]){
      A[k++] = A[i];
    }
  }
  N = k;
}
template<class T, class S> void Unique_L(int &N, T A[], S B[], int sorted=0){
  int i;
  int k = 0;
  if(!sorted){
    sortA_L(N, A, B);
  }
  for(i=(0);i<(N);i++){
    if(!k || A[k-1]!=A[i]){
      A[k] = A[i];
      B[k] = B[i];
      k++;
    }
    else{
      B[k-1] += B[i];
    }
  }
  N=k;
}
int N;
int A[300000];
int cnt[300000];
int ps;
int p[1000];
int p2[1000];
int dv[1000000+1];
int main(){
  int Q5VJL1cS, i, xr20shxY;
  wmem = memarr;
  ps =Prime_L(1000, p);
  for(i=(0);i<(ps);i++){
    p2[i] = p[i]*p[i];
  }
  for(Q5VJL1cS=(0);Q5VJL1cS<(ps);Q5VJL1cS++){
    int j;
    auto &i = p2[Q5VJL1cS];
    for(j=(i);j<(1000000+1);j+=(i)){
      dv[j] = i;
    }
  }
  int WYIGIcGE = rd_int();
  for(xr20shxY=(0);xr20shxY<(WYIGIcGE);xr20shxY++){
    int Hjfu7Vx7;
    int res1;
    int res2;
    rd(N);
    {
      int ao_dF3pO;
      for(ao_dF3pO=(0);ao_dF3pO<(N);ao_dF3pO++){
        rd(A[ao_dF3pO]);
      }
    }
    for(i=(0);i<(N);i++){
      while(dv[A[i]]){
        A[i] /= dv[A[i]];
      }
    }
    for(i=(0);i<(N);i++){
      cnt[i] = 1;
    }
    Unique_L(N, A, cnt);
    {
      int ZIeRIny5;
      int iMWUTgY_;
      if(N==0){
        iMWUTgY_ = 0;
      }
      else{
        iMWUTgY_ = cnt[0];
        for(ZIeRIny5=(1);ZIeRIny5<(N);ZIeRIny5++){
          iMWUTgY_ = max_L(iMWUTgY_, cnt[ZIeRIny5]);
        }
      }
      res1 =iMWUTgY_;
    }
    for(i=(0);i<(N);i++){
      if(cnt[i]%2==0){
        A[i] = 1;
      }
    }
    Unique_L(N, A, cnt);
    {
      int Q5rsz4fz;
      int GgkpftXM;
      if(N==0){
        GgkpftXM = 0;
      }
      else{
        GgkpftXM = cnt[0];
        for(Q5rsz4fz=(1);Q5rsz4fz<(N);Q5rsz4fz++){
          GgkpftXM = max_L(GgkpftXM, cnt[Q5rsz4fz]);
        }
      }
      res2 =GgkpftXM;
    }
    int zT28qSmp = rd_int();
    for(Hjfu7Vx7=(0);Hjfu7Vx7<(zT28qSmp);Hjfu7Vx7++){
      if(rd_ll()==0){
        wt_L(res1);
        wt_L('\n');
      }
      else{
        wt_L(res2);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// int N, A[3d5], cnt[3d5];
// int ps, p[1d3], p2[1d3], dv[1d6+1];
// {
//   ps = Prime(1d3, p);
//   rep(i,ps) p2[i] = p[i]*p[i];
//   rep[p2](i,ps) rep(j,i,1d6+1,i) dv[j] = i;
//   REP(rd_int()){
//     int res1, res2;
//     rd(N,A(N));
//     rep(i,N) while(dv[A[i]]) A[i] /= dv[A[i]];
//     rep(i,N) cnt[i] = 1;
//     Unique(N, A, cnt);
//     res1 = max(cnt(N));
//     rep(i,N) if(cnt[i]%2==0) A[i] = 1;
//     Unique(N, A, cnt);
//     res2 = max(cnt(N));
//     REP(rd_int()) wt(if[rd_ll()==0, res1, res2]);
//   }
// }