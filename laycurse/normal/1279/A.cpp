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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int main(){
  int Lj4PdHRW;
  long long A[3];
  long long s;
  long long m;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(3);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      long long WYIGIcGE;
      if(3==0){
        WYIGIcGE = 0;
      }
      else{
        WYIGIcGE = A[0];
        for(xr20shxY=(1);xr20shxY<(3);xr20shxY++){
          WYIGIcGE += A[xr20shxY];
        }
      }
      s =WYIGIcGE;
    }
    {
      int ao_dF3pO;
      long long tU__gIr_;
      if(3==0){
        tU__gIr_ = 0;
      }
      else{
        tU__gIr_ = A[0];
        for(ao_dF3pO=(1);ao_dF3pO<(3);ao_dF3pO++){
          tU__gIr_ = max_L(tU__gIr_, A[ao_dF3pO]);
        }
      }
      m =tU__gIr_;
    }
    if(divup_L(s,2)< m){
      wt_L("No");
      wt_L('\n');
    }
    else{
      wt_L("Yes");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// //no-unlocked
// {
//   ll A[3], s, m;
//   REP(rd_int()){
//     rd(A(3));
//     s = sum(A(3));
//     m = max(A(3));
//     wt( if[s/+2 < m, "No", "Yes"] );
//   }
// }