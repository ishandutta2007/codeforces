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
int ps;
int p[20000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  ps =Prime_L(20101, p);
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int T;
    rd(T);
    int i;
    int j;
    int cTE1_r3A;
    int RZTsC2BF;
    int FmcKpFmN;
    cTE1_r3A = 0;
    RZTsC2BF = ps-1;
    while(cTE1_r3A < RZTsC2BF){
      if((cTE1_r3A + RZTsC2BF)%2==0){
        FmcKpFmN = (cTE1_r3A + RZTsC2BF) / 2;
      }
      else{
        FmcKpFmN = (cTE1_r3A + RZTsC2BF - 1) / 2;
      }
      if(p[FmcKpFmN] - 1 >= T){
        RZTsC2BF = FmcKpFmN;
      }
      else{
        cTE1_r3A = FmcKpFmN + 1;
      }
    }
    i =RZTsC2BF;
    int t_ynMSdg;
    int KrdatlYV;
    int ao_dF3pO;
    t_ynMSdg = 0;
    KrdatlYV = ps-1;
    while(t_ynMSdg < KrdatlYV){
      if((t_ynMSdg + KrdatlYV)%2==0){
        ao_dF3pO = (t_ynMSdg + KrdatlYV) / 2;
      }
      else{
        ao_dF3pO = (t_ynMSdg + KrdatlYV - 1) / 2;
      }
      if(p[ao_dF3pO] - p[i] >= T){
        KrdatlYV = ao_dF3pO;
      }
      else{
        t_ynMSdg = ao_dF3pO + 1;
      }
    }
    j =KrdatlYV;
    wt_L(p[i]*p[j]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// int ps, p[20000];
// {
//   ps = Prime(20101, p);
//   REP(rd_int()){
//     int @T, i, j;
//     i = bsearch_min[int,i,0,ps-1](p[i] - 1 >= T);
//     j = bsearch_min[int,j,0,ps-1](p[j] - p[i] >= T);
//     wt(p[i]*p[j]);
//   }
// }