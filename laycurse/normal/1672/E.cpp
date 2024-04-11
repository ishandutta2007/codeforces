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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N = 2;
int mode = 0;
int L[10000] = {9, 7, 9, 9};
long long query(long long w){
  if(mode==1){
    int i;
    int res = 1;
    int cur = -1;
    for(i=(0);i<(N);i++){
      if(L[i] > w){
        return 1073709056;
      }
      if(cur + 1 + L[i] > w){
        cur = -1;
        res++;
      }
      cur += L[i] + 1;
    }
    return res;
  }
  long long r;
  wt_L("?");
  wt_L(' ');
  wt_L(w);
  wt_L('\n');
  rd(r);
  if(r==0){
    return 1073709056;
  }
  return r;
}
int main(){
  int i;
  int k;
  int s;
  long long res;
  rd(N);
  int WKqLrJHZ;
  int QAAnbtfa;
  int om7Ebh6q;
  WKqLrJHZ = 2*N-1;
  QAAnbtfa = 2001*N;
  while(WKqLrJHZ < QAAnbtfa){
    if((WKqLrJHZ + QAAnbtfa)%2==0){
      om7Ebh6q = (WKqLrJHZ + QAAnbtfa) / 2;
    }
    else{
      om7Ebh6q = (WKqLrJHZ + QAAnbtfa - 1) / 2;
    }
    if(query(om7Ebh6q) == 1){
      QAAnbtfa = om7Ebh6q;
    }
    else{
      WKqLrJHZ = om7Ebh6q + 1;
    }
  }
  res = s =QAAnbtfa;
  s -= N-1;
  for(i=(2);i<(N+1);i++){
    k =(divup_L((s+(N-i)),i));
    chmin(res, query(k) * k);
  }
  wt_L("!");
  wt_L(' ');
  wt_L(res);
  wt_L('\n');
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
// cLay version 20220312-1 [+beta]

// --- original code ---
// //interactive
// int N = 2;
// 
// int mode = 0;
// int L[10000] = {9, 7, 9, 9};
// 
// ll query(ll w){
//   if(mode==1){
//     int res = 1, cur = -1;
//     rep(i,N){
//       if(L[i] > w) return int_inf;
//       if(cur + 1 + L[i] > w) cur = -1, res++;
//       cur += L[i] + 1;
//     }
//     return res;
//   }
//   ll r;
//   wt("?", w);
//   rd(r);
//   if(r==0) return int_inf;
//   return r;
// }
// 
// {
//   int i, k, s; ll res;
//   rd(N);
// 
//   res = s = bsearch_min[int,x,2*N-1,2001*N](query(x) == 1);
//   s -= N-1;
//   rep(i,2,N+1){
//     k = (s+(N-i)) /+ i;
//     res <?= query(k) * k;
//   }
//   wt("!",res);
//     // ll res2;
//     // res2 = ll_inf;
//     // rep(i,1,1e6) res2 <?= query(i) * i;
//     // wt("!",res2);
// 
//     // wt(res,res2);
//     // assert(res == res2);
// }