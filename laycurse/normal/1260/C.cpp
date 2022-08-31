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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
template<class T, class U> void reduceFraction(T&a, U&b){
  T g=GCD_L(a,b);
  a/=g;
  b/=g;
}
long long A;
long long B;
long long K;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(A);
    rd(B);
    rd(K);
    if(A > B){
      swap(A, B);
    }
    ;
    reduceFraction(A,B);
    if(B >= A*(K-1)+2){
      wt_L("REBEL");
      wt_L('\n');
    }
    else{
      wt_L("OBEY");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200214-1

// --- original code ---
// //no-unlocked
// ll A, B, K;
// {
//   REP(rd_int()){
//     rd(A,B,K);
//     sortE(A,B);
//     reduceFraction(A,B);
//     wt(if[B >= A*(K-1)+2, "REBEL", "OBEY"]);
//   }
// }