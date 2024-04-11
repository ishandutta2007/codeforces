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
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int main(){
  int Lj4PdHRW;
  int x1;
  int x2;
  int y1;
  int y2;
  int x3;
  int x4;
  int y3;
  int y4;
  rd(x1);
  rd(y1);
  rd(x2);
  rd(y2);
  for(Lj4PdHRW=(0);Lj4PdHRW<(2);Lj4PdHRW++){
    rd(x3);
    rd(y3);
    rd(x4);
    rd(y4);
    if(x3 <= x1  &&  x1 <= x2  &&  x2 <= x4){
      if(y3 <= y1){
        chmax(y1, y4);
      }
      if(y4 >= y2){
        chmin(y2, y3);
      }
    }
    if(y3 <= y1  &&  y1 <= y2  &&  y2 <= y4){
      if(x3 <= x1){
        chmax(x1, x4);
      }
      if(x4 >= x2){
        chmin(x2, x3);
      }
    }
    if(x1 >= x2 || y1 >= y2){
      wt_L("NO");
      wt_L('\n');
      return 0;
    }
  }
  wt_L("YES");
  wt_L('\n');
  return 0;
}
// cLay varsion 20190925-1

// --- original code ---
// //no-unlocked
// {
//   int x1, x2, y1, y2;
//   int x3, x4, y3, y4;
//   rd(x1,y1,x2,y2);
// 
//   rep(2){
//     rd(x3,y3,x4,y4);
//     if(x3 <= x1 <= x2 <= x4){
//       if(y3 <= y1) y1 >?= y4;
//       if(y4 >= y2) y2 <?= y3;
//     }
//     if(y3 <= y1 <= y2 <= y4){
//       if(x3 <= x1) x1 >?= x4;
//       if(x4 >= x2) x2 <?= x3;
//     }
//     if(x1 >= x2 || y1 >= y2) wt("NO"), return 0;
//   }
// 
//   wt("YES");
// }