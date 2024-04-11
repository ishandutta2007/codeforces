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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
int ps;
int p[200000];
int sz;
int lis[200000];
int main(){
  int cTE1_r3A, i;
  wmem = memarr;
  ps =Prime_L(200000, p);
  for(i=(0);i<(ps);i++){
    int j;
    for(j=(i+1);j<(ps);j++){
      if((long long) p[i] * p[j] > 200000){
        break;
      }
      lis[sz++] = p[i] * p[j];
    }
  }
  sortA_L(sz, lis);
  int RZTsC2BF = rd_int();
  for(cTE1_r3A=(0);cTE1_r3A<(RZTsC2BF);cTE1_r3A++){
    int i;
    int j;
    int k;
    int r;
    rd(N);
    for(i=(0);i<(10);i++){
      for(j=(i+1);j<(10);j++){
        for(k=(j+1);k<(10);k++){
          r = N - lis[i] - lis[j] - lis[k];
          if(r <= 0){
            continue;
          }
          if(r==lis[i] || r==lis[j] || r==lis[k]){
            continue;
          }
          wt_L("YES");
          wt_L('\n');
          wt_L(lis[i]);
          wt_L(' ');
          wt_L(lis[j]);
          wt_L(' ');
          wt_L(lis[k]);
          wt_L(' ');
          wt_L(r);
          wt_L('\n');
          goto FmcKpFmN;
        }
      }
    }
    wt_L("NO");
    wt_L('\n');
    FmcKpFmN:;
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N;
// int ps, p[2d5];
// int sz, lis[2d5];
// {
//   ps = Prime(2d5, p);
//   rep(i,ps) rep(j,i+1,ps){
//     if((ll) p[i] * p[j] > 2d5) break;
//     lis[sz++] = p[i] * p[j];
//   }
//   sortA(sz, lis);
//   REP(rd_int()){
//     int i, j, k, r;
//     rd(N);
//     rep(i,10) rep(j,i+1,10) rep(k,j+1,10){
//       r = N - lis[i] - lis[j] - lis[k];
//       if(r <= 0) continue;
//       if(r==lis[i] || r==lis[j] || r==lis[k]) continue;
//       wt("YES");
//       wt(lis[i], lis[j], lis[k], r);
//       break_break_break_continue;
//     }
//     wt("NO");
//   }
// }