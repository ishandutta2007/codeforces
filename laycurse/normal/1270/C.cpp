#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
inline void rd(long long &x){
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
inline void wt_L(char a){
  putchar(a);
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
int N;
long long A[100000];
int main(){
  int Lj4PdHRW;
  long long p;
  long long x;
  long long tar = 1LL<<50;
  long long res[3];
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    p = x = 0;
    for(i=(0);i<(N);i++){
      p += A[i];
    }
    for(i=(0);i<(N);i++){
      x ^= A[i];
    }
    res[0] = tar ^ x;
    p += res[0];
    x ^= res[0];
    res[1] = res[2] = (2 * tar - p) / 2;
    wt_L(3);
    wt_L('\n');
    {
      int ao_dF3pO;
      if(3==0){
        putchar('\n');
      }
      else{
        for(ao_dF3pO=(0);ao_dF3pO<(3-1);ao_dF3pO++){
          wt_L(res[ao_dF3pO]);
          wt_L(' ');
        }
        wt_L(res[ao_dF3pO]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// int N; ll A[1d5];
// {
//   ll p, x, tar = 1LL<<50;
//   ll res[3];
//   REP(rd_int()){
//     rd(N,A(N));
//     p = x = 0;
//     rep(i,N) p += A[i];
//     rep(i,N) x ^= A[i];
//     res[0] = tar ^ x;
//     p += res[0];
//     x ^= res[0];
//     res[1] = res[2] = (2 * tar - p) / 2;
//     wt(3);
//     wt(res(3));
//   }
// }