#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  return getchar();
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
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
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
long long q(int a, int b){
  wt_L("?");
  wt_L(' ');
  wt_L(a+1);
  wt_L(' ');
  wt_L(b+1);
  wt_L('\n');
  return rd_ll();
}
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int N;
    rd(N);
    int i;
    int j;
    int k;
    long long all = q(0,N-1);
    long long d;
    int cTE1_r3A;
    int RZTsC2BF;
    int FmcKpFmN;
    cTE1_r3A = 2;
    RZTsC2BF = N-1;
    while(cTE1_r3A < RZTsC2BF){
      if((cTE1_r3A + RZTsC2BF)%2==0){
        FmcKpFmN = (cTE1_r3A + RZTsC2BF) / 2;
      }
      else{
        FmcKpFmN = (cTE1_r3A + RZTsC2BF + 1) / 2;
      }
      if( q(0,FmcKpFmN-1) != all ){
        cTE1_r3A = FmcKpFmN;
      }
      else{
        RZTsC2BF = FmcKpFmN - 1;
      }
    }
    k =RZTsC2BF;
    d = all - q(0,k-1);
    j = k - d;
    all -= d * (d+1) / 2;
    long long t_ynMSdg;
    long long KrdatlYV;
    long long ao_dF3pO;
    t_ynMSdg = 0;
    KrdatlYV = N;
    while(t_ynMSdg < KrdatlYV){
      if((t_ynMSdg + KrdatlYV)%2==0){
        ao_dF3pO = (t_ynMSdg + KrdatlYV) / 2;
      }
      else{
        ao_dF3pO = (t_ynMSdg + KrdatlYV + 1) / 2;
      }
      if( ao_dF3pO*(ao_dF3pO+1)/2 <= all ){
        t_ynMSdg = ao_dF3pO;
      }
      else{
        KrdatlYV = ao_dF3pO - 1;
      }
    }
    i = j -KrdatlYV- 1;
    wt_L("!");
    wt_L(' ');
    wt_L(i+1);
    wt_L(' ');
    wt_L(j+1);
    wt_L(' ');
    wt_L(k+1);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20211024-1 [beta]

// --- original code ---
// //interactive
// ll q(int a, int b){
//   wt("?",a+1,b+1);
//   return rd_ll();
// }
// {
//   REP(rd_int()){
//     int @N, i, j, k; ll all = q(0,N-1), d;
//     k = bsearch_max[int,x,2,N-1]( q(0,x-1) != all );
//     d = all - q(0,k-1);
//     j = k - d;
//     all -= d * (d+1) / 2;
//     i = j - bsearch_max[ll,x,0,N]( x*(x+1)/2 <= all ) - 1;
//     wt("!",i+1,j+1,k+1);
//   }
// }