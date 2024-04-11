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
template<class T> inline T getFirst(multiset<T> &a){
  return *(a.begin());
}
template<class T> inline T getLast(multiset<T> &a){
  typename multiset<T>::iterator it;
  it = a.end();
  it--;
  return *it;
}
template<class T> inline T getFirst(set<T> &a){
  return *(a.begin());
}
template<class T> inline T getLast(set<T> &a){
  typename set<T>::iterator it;
  it = a.end();
  it--;
  return *it;
}
int N;
int M;
int K;
int X;
int Y;
set<int> OX[100000];
set<int> OY[100000];
void eraseX(int x){
  for(int y : OX[x]){
    OY[y].erase(x);
  }
  OX[x].clear();
}
void eraseY(int y){
  for(int x : OY[y]){
    OX[x].erase(y);
  }
  OY[y].clear();
}
int main(){
  int Lj4PdHRW;
  int x1;
  int x2;
  int y1;
  int y2;
  int d;
  long long walk = 0;
  long long all;
  rd(N);
  rd(M);
  rd(K);
  for(Lj4PdHRW=(0);Lj4PdHRW<(K);Lj4PdHRW++){
    rd(X);X += (-1);
    rd(Y);Y += (-1);
    OX[X].insert(Y);
    OY[Y].insert(X);
  }
  all = (long long) N * M - K;
  d = 0;
  x1 = 0;
  x2 = N-1;
  y1 = 0;
  y2 = M-1;
  for(;;){
    if(x1 > x2 || y1 > y2){
      break;
    }
    if(d==0 && OY[y2].size()==x2-x1+1){
      eraseY(y2);
      y2--;
      continue;
    }
    if(d==1 && OX[x2].size()==y2-y1+1){
      eraseX(x2);
      x2--;
      continue;
    }
    if(d==2 && OY[y1].size()==x2-x1+1){
      eraseY(y1);
      y1++;
      continue;
    }
    if(d==3 && OX[x1].size()==y2-y1+1){
      eraseX(x1);
      x1++;
      continue;
    }
    if(d==0 && OX[x1].size()==0){
      d=(d+1)%4;
      x1++;
      walk += y2-y1+1;
      continue;
    }
    if(d==1 && OY[y2].size()==0){
      d=(d+1)%4;
      y2--;
      walk += x2-x1+1;
      continue;
    }
    if(d==2 && OX[x2].size()==0){
      d=(d+1)%4;
      x2--;
      walk += y2-y1+1;
      continue;
    }
    if(d==3 && OY[y1].size()==0){
      d=(d+1)%4;
      y1++;
      walk += x2-x1+1;
      continue;
    }
    if(d==0){
      walk += getFirst(OX[x1]) - y1;
    }
    if(d==1){
      walk += getFirst(OY[y2]) - x1;
    }
    if(d==2){
      walk += y2 - getLast(OX[x2]);
    }
    if(d==3){
      walk += x2 - getLast(OY[y1]);
    }
    break;
  }
  if(walk==all){
    wt_L("Yes");
    wt_L('\n');
  }
  else{
    wt_L("No");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int N, M, K, X, Y;
// set<int> OX[1d5], OY[1d5];
// 
// void eraseX(int x){
//   for(int y : OX[x]) OY[y].erase(x);
//   OX[x].clear();
// }
// 
// void eraseY(int y){
//   for(int x : OY[y]) OX[x].erase(y);
//   OY[y].clear();
// }
// 
// {
//   int x1, x2, y1, y2, d;
//   ll walk = 0, all;
//   rd(N,M,K);
//   rep(K){
//     rd(X--,Y--);
//     OX[X].insert(Y);
//     OY[Y].insert(X);
//   }
//   all = (ll) N * M - K;
// 
//   d = 0;
//   x1 = 0; x2 = N-1;
//   y1 = 0; y2 = M-1;
// 
//   for(;;){
//     if(x1 > x2 || y1 > y2) break;
// 
//     if(d==0 && OY[y2].size()==x2-x1+1) eraseY(y2), y2--, continue;
//     if(d==1 && OX[x2].size()==y2-y1+1) eraseX(x2), x2--, continue;
//     if(d==2 && OY[y1].size()==x2-x1+1) eraseY(y1), y1++, continue;
//     if(d==3 && OX[x1].size()==y2-y1+1) eraseX(x1), x1++, continue;
// 
//     if(d==0 && OX[x1].size()==0) d=(d+1)%4, x1++, walk += y2-y1+1, continue;
//     if(d==1 && OY[y2].size()==0) d=(d+1)%4, y2--, walk += x2-x1+1, continue;
//     if(d==2 && OX[x2].size()==0) d=(d+1)%4, x2--, walk += y2-y1+1, continue;
//     if(d==3 && OY[y1].size()==0) d=(d+1)%4, y1++, walk += x2-x1+1, continue;
// 
//     if(d==0) walk += getFirst(OX[x1]) - y1;
//     if(d==1) walk += getFirst(OY[y2]) - x1;
//     if(d==2) walk += y2 - getLast(OX[x2]);
//     if(d==3) walk += x2 - getLast(OY[y1]);
//     break;
//   }
//   wt(if[walk==all, "Yes", "No"]);
// }