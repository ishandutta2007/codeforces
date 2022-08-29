#pragma GCC optimize ("Ofast")
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
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
}
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
int A;
int dame;
int k;
int s[2];
int x[2][100000];
int y[2][100000];
int main(){
  int i;
  rd(N);
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      k = (i + j) % 2;
      arrInsert(s[k], s[k], x[k], i+1, y[k], j+1);
    }
  }
  while(s[0] && s[1]){
    rd(A);A += (-1);
    for(k=(0);k<(3);k++){
      if(k != A){
        break;
      }
    }
    s[k]--;
    wt_L(k+1);
    wt_L(' ');
    wt_L(x[k][s[k]]);
    wt_L(' ');
    wt_L(y[k][s[k]]);
    wt_L('\n');
  }
  if(s[0] == 0){
    dame = 0;
  }
  if(s[1] == 0){
    dame = 1;
  }
  while(s[0] || s[1]){
    rd(A);A += (-1);
    for(k=(0);k<(3);k++){
      if(k != dame && k != A){
        break;
      }
    }
    for(i=(0);i<(2);i++){
      if(s[i]){
        s[i]--;
        wt_L(k+1);
        wt_L(' ');
        wt_L(x[i][s[i]]);
        wt_L(' ');
        wt_L(y[i][s[i]]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210404-1

// --- original code ---
// //interactive
// int N, A, dame, k;
// int s[2], x[2][1d5], y[2][1d5];
// {
//   rd(N);
//   rep(i,N) rep(j,N){
//     k = (i + j) % 2;
//     arrInsert(s[k], s[k], x[k], i+1, y[k], j+1);
//   }
// 
//   while(s[0] && s[1]){
//     rd(A--);
//     rep(k,3) if(k != A) break;
//     s[k]--;
//     wt(k+1, x[k][s[k]], y[k][s[k]]);
//   }
//   if(s[0] == 0) dame = 0;
//   if(s[1] == 0) dame = 1;
//   while(s[0] || s[1]){
//     rd(A--);
//     rep(k,3) if(k != dame && k != A) break;
//     rep(i,2) if(s[i]) s[i]--, wt(k+1, x[i][s[i]], y[i][s[i]]);
//   }
// }