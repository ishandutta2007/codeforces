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
template<class T> inline void walloc2d(T ***arr, int x, int y, void **mem = &wmem){
  int i;
  walloc1d(arr, x, mem);
  for(i=(0);i<(x);i++){
    walloc1d(&((*arr)[i]), y, mem);
  }
}
struct Rand{
  unsigned x;
  unsigned y;
  unsigned z;
  unsigned w;
  Rand(void){
    x=123456789;
    y=362436069;
    z=521288629;
    w=(unsigned)time(NULL);
  }
  Rand(unsigned seed){
    x=123456789;
    y=362436069;
    z=521288629;
    w=seed;
  }
  inline unsigned get(void){
    unsigned t;
    t = (x^(x<<11));
    x=y;
    y=z;
    z=w;
    w = (w^(w>>19))^(t^(t>>8));
    return w;
  }
  inline double getUni(void){
    return get()/4294967296.0;
  }
  inline int get(int a){
    return (int)(a*getUni());
  }
  inline int get(int a, int b){
    return a+(int)((b-a+1)*getUni());
  }
  inline long long get(long long a){
    return(long long)(a*getUni());
  }
  inline long long get(long long a, long long b){
    return a+(long long)((b-a+1)*getUni());
  }
  inline double get(double a, double b){
    return a+(b-a)*getUni();
  }
  inline int getExp(int a){
    return(int)(exp(getUni()*log(a+1.0))-1.0);
  }
  inline int getExp(int a, int b){
    return a+(int)(exp(getUni()*log((b-a+1)+1.0))-1.0);
  }
}
;
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void rd(char &c){
  int i;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class T> inline int isPrime_L(T n){
  T i;
  if(n<=1){
    return 0;
  }
  if(n<=3){
    return 1;
  }
  if(n%2==0){
    return 0;
  }
  for(i=3;i*i<=n;i+=2){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}
#define PS 7
int N;
char T[200000+2];
int L1;
int L2;
int LEN;
Rand rnd;
long long p[PS];
long long md[PS];
long long pw[PS][200000+2];
int s[200000+2];
int t[200000+2];
long long **od;
long long **ev;
long long **h1;
long long **h2;
int main(){
  int ZIeRIny5;
  wmem = memarr;
  int i;
  int j;
  int k;
  int od_v;
  int ev_v;
  long long hs1;
  long long hs2;
  walloc2d(&od,PS,200000+2);
  walloc2d(&ev,PS,200000+2);
  rd(N);
  rd(T);
  for(i=(0);i<(N);i++){
    T[i] -= '0';
  }
  for(i=(0);i<(100);i++){
    rnd.get();
  }
  for(i=(0);i<(PS);i++){
    md[i] = rnd.get(100000000,1000000000);
    while(!isPrime_L(md[i])){
      md[i]++;
    }
    p[i] = rnd.get((int)10, (int)(md[i]-10));
    pw[i][0] = 1;
    for(j=(1);j<(200000+2);j++){
      pw[i][j] = (pw[i][j-1] * p[i]) % md[i];
    }
  }
  s[0] = t[0] = 0;
  for(i=(0);i<(N);i++){
    s[i+1] = s[i] + T[i];
  }
  for(i=(0);i<(N);i++){
    t[i+1] = t[i] + (1-T[i]);
  }
  for(i=(0);i<(N);i++){
    if(T[i]==0){
      if(s[i]%2){
        od_v = 1;
        ev_v = 2;
      }
      else{
        od_v = 2;
        ev_v = 1;
      }
    }
    else{
      od_v = ev_v = 0;
    }
    for(j=(0);j<(PS);j++){
      od[j][i+1] = (od[j][i] + od_v * pw[j][t[i]]) % md[j];
    }
    for(j=(0);j<(PS);j++){
      ev[j][i+1] = (ev[j][i] + ev_v * pw[j][t[i]]) % md[j];
    }
  }
  int iMWUTgY_ = rd_int();
  for(ZIeRIny5=(0);ZIeRIny5<(iMWUTgY_);ZIeRIny5++){
    rd(L1);L1 += (-1);
    rd(L2);L2 += (-1);
    rd(LEN);
    if(L1 > L2){
      swap(L1, L2);
    }
    ;
    if(s[L1] % 2 != s[L2] % 2){
      h1 = od;
      h2 = ev;
    }
    else{
      h1 = h2 = od;
    }
    for(j=(0);j<(PS);j++){
      hs1 = (h1[j][L1+LEN] - h1[j][L1]) % md[j];
      hs1 = (hs1 * pw[j][t[L2] - t[L1]]) % md[j];
      hs2 = (h2[j][L2+LEN] - h2[j][L2]) % md[j];
      if(hs1 < 0){
        hs1 += md[j];
      }
      if(hs2 < 0){
        hs2 += md[j];
      }
      if(hs1 != hs2){
        wt_L("No");
        wt_L('\n');
        goto AlM5nNnR;
      }
    }
    wt_L("Yes");
    wt_L('\n');
    AlM5nNnR:;
  }
  return 0;
}
// cLay varsion 20200227-1

// --- original code ---
// //no-unlocked
// #define PS 7
// 
// int N; char T[2d5+2];
// int L1, L2, LEN;
// 
// Rand rnd;
// ll p[PS], md[PS];
// ll pw[PS][2d5+2];
// 
// int s[2d5+2], t[2d5+2];
// ll **od, **ev, **h1, **h2;
// 
// {
//   int i, j, k, od_v, ev_v;
//   ll hs1, hs2;
// 
//   walloc2d(&od,PS,2d5+2);
//   walloc2d(&ev,PS,2d5+2);
// 
//   rd(N,T);
//   rep(i,N) T[i] -= '0';
// 
//   rep(i,100) rnd.get();
//   rep(i,PS){
//     md[i] = rnd.get(1d8,1d9);
//     while(!isPrime(md[i])) md[i]++;
//     p[i] = rnd.get((int)10, (int)(md[i]-10));
// 
//     pw[i][0] = 1;
//     rep(j,1,2d5+2) pw[i][j] = (pw[i][j-1] * p[i]) % md[i];
//   }
// 
//   s[0] = t[0] = 0;
//   rep(i,N) s[i+1] = s[i] + T[i];
//   rep(i,N) t[i+1] = t[i] + (1-T[i]);
// 
//   rep(i,N){
//     if(T[i]==0){
//       if(s[i]%2) od_v = 1, ev_v = 2;
//       else       od_v = 2, ev_v = 1;
//     } else {
//       od_v = ev_v = 0;
//     }
//     rep(j,PS) od[j][i+1] = (od[j][i] + od_v * pw[j][t[i]]) % md[j];
//     rep(j,PS) ev[j][i+1] = (ev[j][i] + ev_v * pw[j][t[i]]) % md[j];
//   }
// 
//   REP(rd_int()){
//     rd(L1--,L2--,LEN);
//     sortE(L1, L2);
//     if(s[L1] % 2 != s[L2] % 2){
//       //wt("dif :", s[L2] - s[L1]);
//       h1 = od;
//       h2 = ev;
//     } else {
//       //wt("same :", s[L2] - s[L1]);
//       h1 = h2 = od;
//     }
//     rep(j,PS){
//       hs1 = (h1[j][L1+LEN] - h1[j][L1]) % md[j];
//       hs1 = (hs1 * pw[j][t[L2] - t[L1]]) % md[j];
//       hs2 = (h2[j][L2+LEN] - h2[j][L2]) % md[j];
//       if(hs1 < 0) hs1 += md[j];
//       if(hs2 < 0) hs2 += md[j];
//       //wt(j,":",hs1,hs2);
//       if(hs1 != hs2) wt("No"), break_continue;
//     }
//     wt("Yes");
//   }
// }