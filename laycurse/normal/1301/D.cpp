#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
int N;
int M;
int K;
int ress;
int step[3000];
char dir[3000];
void doit(int s, char d){
  if(s==0){
    return;
  }
  arrInsert(ress, ress, step,min_L(s, K), dir, d);
  K -= s;
  if(K <= 0){
    int i;
    wt_L("YES");
    wt_L('\n');
    wt_L(ress);
    wt_L('\n');
    for(i=(0);i<(ress);i++){
      wt_L(step[i]);
      wt_L(' ');
      wt_L(dir[i]);
      wt_L('\n');
    }
    exit(0);
  }
}
int main(){
  int FmcKpFmN, e98WHCEY;
  rd(N);
  rd(M);
  rd(K);
  if(K > 4*N*M-2*N-2*M){
    wt_L("NO");
    wt_L('\n');
    return 0;
  }
  doit(M-1, 'R');
  for(e98WHCEY=(0);e98WHCEY<(M-1);e98WHCEY++){
    doit(N-1, 'D');
    doit(N-1, 'U');
    doit(1, 'L');
  }
  doit(N-1, 'D');
  for(FmcKpFmN=(0);FmcKpFmN<(N-1);FmcKpFmN++){
    doit(M-1, 'R');
    doit(M-1, 'L');
    doit(1, 'U');
  }
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// int N, M, K;
// 
// int ress, step[3000]; char dir[3000];
// 
// void doit(int s, char d){
//   if(s==0) return;
//   arrInsert(ress, ress, step, min(s,K), dir, d);
//   K -= s;
//   if(K <= 0){
//     wt("YES");
//     wt(ress);
//     rep(i,ress) wt(step[i], dir[i]);
//     exit(0);
//   }
// }
// 
// {
//   rd(N,M,K);
//   if(K > 4*N*M-2*N-2*M) wt("NO"), return 0;
// 
//   doit(M-1, 'R');
//   rep(M-1){
//     doit(N-1, 'D');
//     doit(N-1, 'U');
//     doit(1, 'L');
//   }
//   doit(N-1, 'D');
//   rep(N-1){
//     doit(M-1, 'R');
//     doit(M-1, 'L');
//     doit(1, 'U');
//   }
// }