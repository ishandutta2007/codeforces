#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
int T;
int STR;
int INT;
int EXP;
int main(){
  int Lj4PdHRW;
  int mn;
  int mx;
  int s;
  int res;
  rd(T);
  for(Lj4PdHRW=0;Lj4PdHRW<(T);Lj4PdHRW++){
    rd(STR);
    rd(INT);
    rd(EXP);
    s = STR + INT + EXP;
    mn =max_L(STR, s/2+1);
    mx = STR + EXP;
    res =max_L(mx-mn+1, 0);
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int T, STR, INT, EXP;
// {
//   int mn, mx, s, res;
//   rd(T);
//   rep(T){
//     rd(STR,INT,EXP);
//     s = STR + INT + EXP;
//     mn = max(STR, s/2+1);
//     mx = STR + EXP;
//     res = max(mx-mn+1, 0);
//     wt(res);
//   }
// }