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
template<class T> int Factor_L(T N, T fac[], int fs[]){
  T i;
  int sz = 0;
  if(N%2==0){
    fac[sz] = 2;
    fs[sz] = 1;
    N /= 2;
    while(N%2==0){
      N /= 2;
      fs[sz]++;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      fs[sz] = 1;
      N /= i;
      while(N%i==0){
        N /= i;
        fs[sz]++;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    fs[sz] = 1;
    sz++;
  }
  return sz;
}
template<class T> int Divisor_L(T N, T res[], void *mem = wmem){
  int i;
  int j;
  int k;
  int s;
  int sz = 0;
  T*fc;
  int*fs;
  int fsz;
  walloc1d(&fc, 100, &mem);
  walloc1d(&fs, 100, &mem);
  fsz =Factor_L(N, fc, fs);
  res[sz++] = 1;
  for(i=(0);i<(fsz);i++){
    s = sz;
    k = s * fs[i];
    for(j=(0);j<(k);j++){
      res[sz++] = res[j] * fc[i];
    }
  }
  sort(res, res+sz);
  return sz;
}
int ys;
long long y[100000];
int fs;
int f[30];
int fn[30];
int cf[20000000+1];
int yy[20000000+1];
int ps;
int p[20000000];
int main(){
  int Lj4PdHRW, t_ynMSdg;
  wmem = memarr;
  int i;
  int j;
  int k;
  ps =Prime_L(20000000, p);
  for(Lj4PdHRW=(0);Lj4PdHRW<(ps);Lj4PdHRW++){
    auto&i = p[Lj4PdHRW];
    for(j=(i);j<(20000000+1);j+=(i)){
      if(yy[j]==0){
        yy[j] = i;
      }
    }
  }
  for(i=(2);i<(20000000+1);i++){
    k = i;
    while(k % yy[i] == 0){
      k /= yy[i];
    }
    cf[i] = cf[k] + 1;
  }
  int KrdatlYV = rd_int();
  for(t_ynMSdg=(0);t_ynMSdg<(KrdatlYV);t_ynMSdg++){
    long long C;
    rd(C);
    long long D;
    rd(D);
    long long X;
    rd(X);
    long long t;
    long long res = 0;
    ys =Divisor_L(X, y);
    for(i=(0);i<(ys);i++){
      t = D + X / y[i];
      if(t % C){
        continue;
      }
      t /= C;
      res += (1LL << cf[t]);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int ys; ll y[1d5];
// int fs, f[30], fn[30];
// int cf[2d7+1], yy[2d7+1];
// int ps, p[2d7];
// {
//   int i, j, k;
//   ps = Prime(2d7, p);
//   rep[p](i,ps) rep(j,i,2d7+1,i) if(yy[j]==0) yy[j] = i;
//   rep(i,2,2d7+1){
//     k = i;
//     while(k % yy[i] == 0) k /= yy[i];
//     cf[i] = cf[k] + 1;
//   }
//   REP(rd_int()){
//     ll @C, @D, @X, t, res = 0;
//     ys = Divisor(X, y);
//     rep(i,ys){
//       t = D + X / y[i];
//       if(t % C) continue;
//       t /= C;
//       res += (1LL << cf[t]);
//     }
//     wt(res);
//   }
// }