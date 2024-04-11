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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
}
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
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
int query(int i, int j, int k){
  wt_L('?');
  wt_L(' ');
  wt_L(i+1);
  wt_L(' ');
  wt_L(j+1);
  wt_L(' ');
  wt_L(k+1);
  wt_L('\n');
  return rd_int();
}
void ans(int i, int j){
  wt_L('!');
  wt_L(' ');
  wt_L(i+1);
  wt_L(' ');
  wt_L(j+1);
  wt_L('\n');
}
int main(){
  int Nzj9Y0kE;
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int i;
    int N;
    rd(N);
    int x = 0;
    int y = 1;
    int z;
    int mx;
    int t;
    mx = -1;
    for(i=(2);i<(N);i++){
      t = query(x, y, i);
      if(mx < t){
        mx = t;
        z = i;
      }
    }
    mx = -1;
    for(i=(1);i<(N);i++){
      if(i!=z){
        t = query(x,i,z);
        if(mx < t){
          mx = t;
          y = i;
        }
      }
    }
    for(i=(0);i<(N);i++){
      if(i != x && i != y && i != z){
        break;
      }
    }
    if(query(i,x,y) == mx){
      ans(x,y);
      continue;
    }
    if(query(i,x,z) == mx){
      ans(x,z);
      continue;
    }
    ans(y,z);
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220116-1 [+beta]

// --- original code ---
// //interactive
// 
// int query(int i, int j, int k){
//   wt('?', i+1, j+1, k+1);
//   return rd_int();
// }
// 
// void ans(int i, int j){
//   wt('!', i+1, j+1);
// }
// 
// {
//   REP(rd_int()){
//     int @N, x = 0, y = 1, z, mx, t;
// 
//     mx = -1;
//     rep(i,2,N){
//       t = query(x, y, i);
//       if(mx < t) mx = t, z = i;
//     }
//     mx = -1;
//     rep(i,1,N) if(i!=z){
//       t = query(x,i,z);
//       if(mx < t) mx = t, y = i;
//     }
// 
//     rep(i,N) if(i != x && i != y && i != z) break;
// 
//     if(query(i,x,y) == mx) ans(x,y), continue;
//     if(query(i,x,z) == mx) ans(x,z), continue;
//     ans(y,z);
//   }
// }