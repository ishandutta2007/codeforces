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
template<class S> void arrErase(int k, int &sz, S a[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
}
template<class S, class T> void arrErase(int k, int &sz, S a[], T b[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
}
template<class S, class T, class U> void arrErase(int k, int &sz, S a[], T b[], U c[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
  for(i=(k);i<(sz);i++){
    c[i] = c[i+1];
  }
}
int fs;
int f[100];
int fn[100];
int ys;
int y[200000];
int ed[200000];
int cs;
int c[100];
int ress;
int res[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int N;
    rd(N);
    fs =Factor_L(N, f, fn);
    ys =Divisor_L(N, y);
    arrErase(0, ys, y);
    if(fs==2 && fn[0]==fn[1] && fn[1]==1){
      {
        int cTE1_r3A;
        if(ys==0){
          wt_L('\n');
        }
        else{
          for(cTE1_r3A=(0);cTE1_r3A<(ys-1);cTE1_r3A++){
            wt_L(y[cTE1_r3A]);
            wt_L(' ');
          }
          wt_L(y[cTE1_r3A]);
          wt_L('\n');
        }
      }
      wt_L(1);
      wt_L('\n');
      continue;
    }
    if(fs==1){
      {
        int xr20shxY;
        if(ys==0){
          wt_L('\n');
        }
        else{
          for(xr20shxY=(0);xr20shxY<(ys-1);xr20shxY++){
            wt_L(y[xr20shxY]);
            wt_L(' ');
          }
          wt_L(y[xr20shxY]);
          wt_L('\n');
        }
      }
      wt_L(0);
      wt_L('\n');
      continue;
    }
    cs = 0;
    for(i=(0);i<(fs);i++){
      c[cs++] = f[i];
      if(i==fs-1){
        c[cs++] =N;
      }
      else{
        c[cs++] =f[i] * f[(i+1)%fs];
      }
    }
    for(i=(0);i<(ys);i++){
      ed[i] = 0;
    }
    for(i=(0);i<(ys);i++){
      int j;
      for(j=(0);j<(cs);j++){
        if(y[i]==c[j]){
          ed[i] = 1;
          break;
        }
      }
    }
    ress = 0;
    for(i=(0);i<(fs);i++){
      int j;
      res[ress++] = c[2*i];
      for(j=(0);j<(ys);j++){
        if(!ed[j] && y[j]%f[i]==0){
          ed[j] = 1;
          res[ress++] = y[j];
        }
      }
      res[ress++] = c[2*i+1];
    }
    {
      int AlM5nNnR;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(AlM5nNnR=(0);AlM5nNnR<(ress-1);AlM5nNnR++){
          wt_L(res[AlM5nNnR]);
          wt_L(' ');
        }
        wt_L(res[AlM5nNnR]);
        wt_L('\n');
      }
    }
    wt_L(0);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200916-1

// --- original code ---
// //no-unlocked
// int fs, f[100], fn[100];
// int ys, y[2d5], ed[2d5];
// int cs, c[100];
// int ress, res[2d5];
// {
//   REP(rd_int()){
//     int @N;
//     fs = Factor(N, f, fn);
//     ys = Divisor(N, y);
//     arrErase(0, ys, y);
// 
//     if(fs==2 && fn[0]==fn[1]==1) wt(y(ys)), wt(1), continue;
//     if(fs==1) wt(y(ys)), wt(0), continue;
// 
//     cs = 0;
//     rep(i,fs){
//       c[cs++] = f[i];
//       c[cs++] = if[i==fs-1, N, f[i] * f[(i+1)%fs]];
//     }
// 
//     rep(i,ys) ed[i] = 0;
//     rep(i,ys) rep(j,cs) if(y[i]==c[j]) ed[i] = 1, break;
// 
//     ress = 0;
//     rep(i,fs){
//       res[ress++] = c[2*i];
//       rep(j,ys) if(!ed[j] && y[j]%f[i]==0) ed[j] = 1, res[ress++] = y[j];
//       res[ress++] = c[2*i+1];
//     }
// 
//     wt(res(ress));
//     wt(0);
//   }
// }