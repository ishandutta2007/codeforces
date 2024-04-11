#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k, m=0;
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
  int k, m=0;
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
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class T> inline T GCD_L(T a,T b){
  T r;
  while(a){
    r=b;
    b=a;
    a=r%a;
  }
  return b;
}
long long N[2];
int Q;
int SX;
int EX;
long long SY;
long long EY;
int main(){
  int cTE1_r3A;
  long long g, m[2];
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(2);Lj4PdHRW++){
      rd(N[Lj4PdHRW]);
    }
  }
  rd(Q);
  {
    int KL2GvlyY;
    long long Q5VJL1cS;
    if(2==0){
      Q5VJL1cS = 0;
    }
    else{
      Q5VJL1cS = N[0];
      for(KL2GvlyY=(1);KL2GvlyY<(2);KL2GvlyY++){
        Q5VJL1cS = GCD_L(Q5VJL1cS, N[KL2GvlyY]);
      }
    }
    g =Q5VJL1cS;
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<((1) + 1);e98WHCEY++){
      m[e98WHCEY] = N[e98WHCEY] / g;
    }
  }
  for(cTE1_r3A=0;cTE1_r3A<(Q);cTE1_r3A++){
    rd(SX);SX += (-1);
    rd(SY);SY += (-1);
    rd(EX);EX += (-1);
    rd(EY);EY += (-1);
    if(SY/m[SX]==EY/m[EX]){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// ll N[2]; int Q;
// int SX, EX;
// ll SY, EY;
// {
//   ll g, m[2];
// 
//   rd(N(2),Q);
//   g = gcd(N(2));
//   m[0..1] = N[0..1] / g;
//   
//   rep(Q){
//     rd(SX--,SY--,EX--,EY--);
//     wt(if[SY/m[SX]==EY/m[EX], "YES", "NO"]);
//   }
// }